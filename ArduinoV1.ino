#include <Wire.h>
#define SLAVE_ADDRESS 0x12

//initialisation pins capteurs/actionneurs
int pinled1=6;
int pinled2=5;
int pinPompeMaree=2;
int pinOxygen=3;
int pinAgitateur=4;

boolean allumageLed1=false;
boolean allumageLed2=false;
boolean allumagePompeMaree=false;
boolean allumageOxygen=false;
boolean allumageAgitateur=false;

//valeurs pousse
int heureAllumageLed=5;
int heureEteindreLed=23;
int heureMaree=20;

//initialisation capteur pH
#define SensorPin 0     // pin de l'interface pH
unsigned long int valeurmoyenne;     //stock la valeurretournée
float b;
int buf[10],temp;
int heureph=20;

//fin

// initialisation heure
int dataReceived=2;

//Initialisation EC

//#include <OneWire.h>
//#define StartConvert 0
//#define ReadTemperature 1
//const byte numReadings = 20;     //the number of sample times
//byte ECsensorPin = A1;  //EC Meter analog output,pin on analog 1
//byte DS18B20_Pin = 2; //DS18B20 signal, pin on digital 2
//unsigned int AnalogSampleInterval=25,printInterval=700,tempSampleInterval=850;  //analog sample interval;serial print interval;temperature sample interval
//unsigned int readings[numReadings];      // the readings from the analog input
//byte index = 0;                  // the index of the current reading
//unsigned long AnalogValueTotal = 0;                  // the running total
//unsigned int AnalogAverage = 0,averageVoltage=0;                // the average
//unsigned long AnalogSampleTime,printTime,tempSampleTime;
//float temperature,ECcurrent; 
//int heureEC=20; 

////Temperature chip i/o
//OneWire ds(DS18B20_Pin);  // on digital pin 2

void setup() {
    Serial.begin(9600);
    // Connection série raspberry
    Wire.begin(SLAVE_ADDRESS);
    Wire.onReceive(receiveData);
        
    // fin
    
    //setup pin capteurs
    pinMode(pinled1,OUTPUT);
    pinMode(pinled2,OUTPUT);
    pinMode(pinPompeMaree,OUTPUT);
    pinMode(pinOxygen,OUTPUT);
    pinMode(pinAgitateur,OUTPUT);
    digitalWrite(pinled1,HIGH);
    digitalWrite(pinled2,HIGH);
    digitalWrite(pinPompeMaree,HIGH);
    digitalWrite(pinOxygen,HIGH);
    digitalWrite(pinAgitateur,HIGH);
    
      
    //fin
    
//    //setup EC
//    
//    for (byte thisReading = 0; thisReading < numReadings; thisReading++)
//    readings[thisReading] = 0;
//    TempProcess(StartConvert);  
//    AnalogSampleTime=millis();
//    printTime=millis();
//    tempSampleTime=millis();

    
    
    Serial.println("Debut du programme !");
    
}

void loop() {
  
    
   
  // Toute les minutes, la variable dataReceived s'actualise avec l'heure de la raspberry
  
  // Boucle led 1
  if (dataReceived>=heureAllumageLed && !allumageLed1 && dataReceived<heureEteindreLed){
    digitalWrite(pinled1,LOW);
    allumageLed1=true;
    Serial.println("Premiere Led allumee !");
  }
  else if (dataReceived>=heureEteindreLed && allumageLed1){
    digitalWrite(pinled1,HIGH);
    allumageLed1=false;
    Serial.println("Premiere Led eteinte !");
  }
  
  // Boucle led 2
  
   if (dataReceived>=heureAllumageLed && !allumageLed2 && dataReceived<heureEteindreLed){
    digitalWrite(pinled2,LOW);
    allumageLed2=true;
    Serial.println("Deuxieme Led allumee !");
  }
  else if (dataReceived>=heureEteindreLed && allumageLed2){
    digitalWrite(pinled2,HIGH);
    allumageLed2=false;
    Serial.println("Deuxieme Led eteinte !");
  }
  
       //boucle capteur pH
    
     if (dataReceived==heureph){
       for(int i=0;i<10;i++) {  //on recupère 10 valeurs pour affiner la mesure 
         buf[i]=analogRead(SensorPin);
         delay(10);
       }
       for(int i=0;i<9;i++) {  //trier les valeurs
         for(int j=i+1;j<10;j++) {
           if(buf[i]>buf[j]) {
             temp=buf[i];
             buf[i]=buf[j];
             buf[j]=temp;
           }
        }  
     }   
     valeurmoyenne=0;
     for(int i=2;i<8;i++) {
       valeurmoyenne+=buf[i];
     }
     float valeurpH=(float)valeurmoyenne*5.0/1024/6; // on convertit la donnée analogique en milivolt
     valeurpH=3.5*valeurpH;   // on convertit la valeu(mV) en une valeur pH
     Serial.print("    pH:");
     Serial.println(valeurpH,2);
     heureph=heureph+1;
     heureph=heureph%24; 
}
     
   // fin boucle pH
   
//   //Boucle EC
//   if (dataReceived==heureEC){
//   
//   if(millis()-AnalogSampleTime>=AnalogSampleInterval)  
//  {
//    AnalogSampleTime=millis();
//     // subtract the last reading:
//    AnalogValueTotal = AnalogValueTotal - readings[index];
//    // read from the sensor:
//    readings[index] = analogRead(ECsensorPin);
//    // add the reading to the total:
//    AnalogValueTotal = AnalogValueTotal + readings[index];
//    // advance to the next position in the array:
//    index = index + 1;
//    // if we're at the end of the array...
//    if (index >= numReadings)
//    // ...wrap around to the beginning:
//    index = 0;
//    // calculate the average:
//    AnalogAverage = AnalogValueTotal / numReadings;
//  }
//   if(millis()-tempSampleTime>=tempSampleInterval) 
//  {
//    tempSampleTime=millis();
//    temperature = TempProcess(ReadTemperature);// read the current temperature from the  DS18B20
//    TempProcess(StartConvert);                   //after the reading,start the convert for next reading
//  }
//   /*
//   Every once in a while,print the information on the serial monitor.
//  */
//  if(millis()-printTime>=printInterval)
//  {
//    printTime=millis();
//    averageVoltage=AnalogAverage*(float)5000/1024;
//    Serial.print("Analog value:");
//    Serial.print(AnalogAverage);   //analog average,from 0 to 1023
//    Serial.print("    Voltage:");
//    Serial.print(averageVoltage);  //millivolt average,from 0mv to 4995mV
//    Serial.print("mV    ");
//    Serial.print("temp:");
//    Serial.print(temperature);    //current temperature
//    Serial.print("^C     EC:");
//    
//    float TempCoefficient=1.0+0.0185*(temperature-25.0);    //temperature compensation formula: fFinalResult(25^C) = fFinalResult(current)/(1.0+0.0185*(fTP-25.0));
//    float CoefficientVolatge=(float)averageVoltage/TempCoefficient;   
//    if(CoefficientVolatge<150)Serial.println("No solution!");   //25^C 1413us/cm<-->about 216mv  if the voltage(compensate)<150,that is <1ms/cm,out of the range
//    else if(CoefficientVolatge>3300)Serial.println("Out of the range!");  //>20ms/cm,out of the range
//    else
//    { 
//      if(CoefficientVolatge<=448)ECcurrent=6.84*CoefficientVolatge-64.32;   //1ms/cm<EC<=3ms/cm
//      else if(CoefficientVolatge<=1457)ECcurrent=6.98*CoefficientVolatge-127;  //3ms/cm<EC<=10ms/cm
//      else ECcurrent=5.3*CoefficientVolatge+2278;                           //10ms/cm<EC<20ms/cm
//      ECcurrent/=1000;    //convert us/cm to ms/cm
//      Serial.print(ECcurrent,2);  //two decimal
//      Serial.println("ms/cm");
//      
//    }
//  }
// }
   //fin boucle EC
   
  // Boucle marée
 
   if (dataReceived==heureMaree){
     digitalWrite(pinOxygen,LOW);
     digitalWrite(pinAgitateur,LOW);
     Serial.println("Debut de l oxygenation et de l agitation !");
     delay(900000);
     digitalWrite(pinPompeMaree,LOW);
     Serial.println("Debut de la maree !");
     delay(1800000);
     digitalWrite(pinOxygen,HIGH);
     digitalWrite(pinAgitateur,HIGH);
     digitalWrite(pinPompeMaree,HIGH);
     heureMaree=heureMaree+2;
     heureMaree=heureMaree%24;
     Serial.println("Fin de la maree !");
   }

}
void receiveData(int byteCount){
    while(Wire.available()) {
        dataReceived = Wire.read();
        
        
    }
}
void sendData(){
    int envoi = dataReceived;
    Wire.write(envoi);
}
//
//float TempProcess(bool ch)
//{
//  //returns the temperature from one DS18B20 in DEG Celsius
//  static byte data[12];
//  static byte addr[8];
//  static float TemperatureSum;
//  if(!ch){
//          if ( !ds.search(addr)) {
//              Serial.println("no more sensors on chain, reset search!");
//              ds.reset_search();
//              return 0;
//          }      
//          if ( OneWire::crc8( addr, 7) != addr[7]) {
//              Serial.println("CRC is not valid!");
//              return 0;
//          }        
//          if ( addr[0] != 0x10 && addr[0] != 0x28) {
//              Serial.print("Device is not recognized!");
//              return 0;
//          }      
//          ds.reset();
//          ds.select(addr);
//          ds.write(0x44,1); 
//  }
//  else{  
//          byte present = ds.reset();
//          ds.select(addr);    
//          ds.write(0xBE); // Read Scratchpad            
//          for (int i = 0; i < 9; i++) { // we need 9 bytes
//            data[i] = ds.read();
//          }         
//          ds.reset_search();           
//          byte MSB = data[1];
//          byte LSB = data[0];        
//          float tempRead = ((MSB << 8) | LSB); 
//          TemperatureSum = tempRead / 16;
//    }
//          return TemperatureSum;  
//}
