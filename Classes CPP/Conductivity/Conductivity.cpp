#include <Arduino.h>
#include <Time.h>
#include <Wire.h>
#include <OneWire.h>
#include "Conductivity.h"

Conductivity::Conductivity(byte pin_conductivity,byte pin_temperature,unsigned int analog_interval,unsigned int print_interval,unsigned int temperature_interval,unsigned int values_list[20],byte index,double analog_total,double analog_average,double voltage_average,unsigned long last_analog,unsigned long last_print,unsigned long last_temperature,double current_conductivity,double temperature,double voltage_coefficient,Time timeon) {
	m_pin_conductivity=pin_conductivity;
	m_pin_temperature=pin_temperature;
	m_analog_interval=analog_interval;
	m_print_interval=print_interval;
	m_temperature_interval=temperature_interval;
	m_values_list=values_list;
	m_index=index;
	m_analog_total=analog_total;
	m_analog_average=analog_average;
	m_voltage_average=voltage_average;
	m_last_analog=last_analog;
	m_last_print=last_print;
	m_last_temperature=last_temperature;
	m_current_conductivity=current_conductivity;
	m_temperature=temperature;
	m_voltage_coefficient=voltage_coefficient;
	m_timeon=timeon;
}

Conductivity::Conductivity() {
	byte pin_conductivity=A1;
	byte pin_temperature=2;
	unsigned int analog_interval=25;
	unsigned int print_interval=700;
	unsigned int temperature_interval=850;
	unsigned int values_list[20];
	byte index=0;
	double analog_total=0;
	double analog_average=0;
	double voltage_average=0;
	unsigned long last_analog=0;
	unsigned long last_print=0;
	unsigned long last_temperature=0;
	double current_conductivity=0;
	double temperature=0;
	double voltage_coefficient=0;
	Time timeon=Time(0,0);
	Conductivity(pin_conductivity,pin_temperature,analog_interval,print_interval,temperature_interval,values_list,index,analog_total,analog_average,voltage_average,last_analog,last_print,last_temperature,current_conductivity,temperature,voltage_coefficient,timeon)
}

bool Conductivity::get_StartConvert() {
	return m_StartConvert;
}

bool Conductivity::get_ReadTemperature() {
	return m_ReadTemperature;
}

byte Conductivity::get_NumberReading() {
	return m_NumberReading;
}

byte Conductivity::get_pin_conductivity() {
	return m_pin_conductivity;
}

byte Conductivity::get_pin_temperature() {
	return m_pin_temperature;
}

unsigned int Conductivity::get_analog_interval() {
	return m_analog_interval;
}

unsigned int Conductivity::get_print_interval() {
	return m_print_interval;
}

unsigned int Conductivity::get_temperature_interval() {
	return m_temperature_interval;
}

unsigned int Conductivity::get_values_list() {
	return m_values_list;
}

byte Conductivity::get_index() {
	return m_index;
}

double Conductivity::get_analog_total() {
	return m_analog_total;
}

double Conductivity::get_analog_average() {
	return m_analog_average;
}

double Conductivity::get_voltage_average() {
	return m_voltage_average;
}

unsigned long Conductivity::get_last_analog() {
	return m_last_analog;
}

unsigned long Conductivity::get_last_print() {
	return m_last_print;
}

unsigned long Conductivity::get_last_temperature() {
	return m_last_temperature;
}

double Conductivity::get_current_conductivity() {
	return m_current_conductivity;
}

double Conductivity::get_temperature() {
	return m_temperature;
}

double Conductivity::get_temperature_coefficient() {
	return m_temperature_coefficient;
}

double Conductivity::get_voltage_coefficient() {
	return m_voltage_coefficient;
}

Time Conductivity::get_timeon() {
	return m_timeon;
}

void Conductivity::set_pin_conductivity(byte pin_conductivity) {
	m_pin_conductivity=pin_conductivity;
}

void Conductivity::set_pin_temperature(byte pin_temperature) {
	m_pin_temperature=pin_temperature;
}

void Conductivity::set_analog_interval(unsigned int analog_interval) {
	m_analog_interval=analog_interval;
}

void Conductivity::set_print_interval(unsigned int print_interval) {
	m_print_interval=print_interval;
}

void Conductivity::set_temperature_interval(unsigned int temperature_interval) {
	m_temperature_interval=temperature_interval;
}

void Conductivity::set_values_list(unsigned int values_list[20]) {
	m_values_list=values_list;
}

void Conductivity::set_index(byte index) {
	m_index=index;
}

void Conductivity::set_analog_total(double analog_total) {
	m_analog_total=analog_total;
}

void Conductivity::set_analog_average(double analog_average) {
	m_analog_average=analog_average;
}

void Conductivity::set_voltage_average(double voltage_average) {
	m_voltage_average=voltage_average;
}

void Conductivity::set_last_analog(unsigned long last_analog) {
	m_last_analog=last_analog;
}

void Conductivity::set_last_print(unsigned long last_print) {
	m_last_print=last_print;
}

void Conductivity::set_last_temperature(unsigned long last_temperature) {
	m_last_temperature=last_temperature;
}

void Conductivity::set_current_conductivity(double current_conductivity) {
	m_current_conductivity=current_conductivity;
}

void Conductivity::set_temperature(double temperature) {
	m_temperature=temperature;
}

void Conductivity::set_temperature_coefficient(double temperature_coefficient) {
	m_temperature_coefficient=temperature_coefficient;
}

void Conductivity::set_voltage_coefficient(double voltage_coefficient) {
	m_voltage_coefficient=voltage_coefficient;
}

void Conductivity::set_timeon(Time timeon) {
	m_timeon=timeon;
}

void Conductivity::setup_conductivity() {
	for (byte m_reading = 0; m_reading<m_NumberReading;m_reading++) {
		m_values_list[m_reading]=0;
		temp(m_StartConvert);
		m_last_analog=millis();
		m_last_print=millis();
		m_last_temperature=millis();
	}
}

float Conductivity::temp(bool boolean) {
	static byte m_data[12];
    static byte m_addr[8];
	if(!boolean){
		if ( !ds.search(addr)) {
			Serial.println("Pas de capteur, on relance la recherche");
            ds.reset_search();
            return 0;
        }      
		if (OneWire::crc8( addr, 7) != addr[7]) {
			Serial.println("CRC n'est pas valide");
			return 0;
		}        
		if ( addr[0] != 0x10 && addr[0] != 0x28) {
			Serial.print("Appareil non reconnu");
			return 0;
		}      
		ds.reset();
		ds.select(addr);
		ds.write(0x44,1); 
	}
	else{  
		byte present = ds.reset();
        ds.select(addr);    
		ds.write(0xBE);            
		for (int i = 0; i < 9; i++) {
			data[i] = ds.read();
		}         
		ds.reset_search();           
		byte MSB = data[1];
		byte LSB = data[0];        
		float m_temp_read = ((MSB << 8) | LSB); 
		m_temperature = tempRead / 16;
    }
          return m_temperature;  
}

void Conductivity::analog() {
	if (millis()-m_last_analog>=m_analog_interval) {
		m_last_analog=millis();
		m_analog_total-=m_values_list[m_index];
		m_values_list[m_index]=analogRead(m_pin_conductivity);
		m_analog_total+=m_values_list[m_index];
		m_index+=1;
		if (m_index>=m_NumberReading) {
			m_index=0;
			m_analog_average=m_analog_total/m_NumberReading;
		}
	}
}
		
void Conductivity::temperature() {
	if (millis()-m_last_temperature>=m_temperature_interval) {
		m_last_temperature=millis();
		m_temperature=temp(m_ReadTemperature);
		temp(m_StartConvert);
	}
}

void Conductivity::print() {
	if (millis()-m_last_print>=m_print_interval) {
		m_last_print=millis();
		m_voltage_average=m_analog_average*(5000.0/1024.0);
		Serial.print("Valeur analogique:");
		Serial.print(m_analog_average);
		Serial.print("		Voltage");
		Serial.print(m_voltage_average);
		Serial.print("mV		");
		Serial.print("Temperature:");
		Serial.print(m_temperature);
		Serial.print("°C	Conductivité:");
		
		m_temperature_coefficient=1.0+0.0185*(m_temperature-25.0);
		m_voltage_coefficient=m_voltage_average/m_temperature_coefficient;
		if(m_voltage_coefficient<150) {
			Serial.println("Pas de solution");
		}
		else if (m_voltage_coefficient>3300) {
			Serial.println("Hors du spectre");
		}
		else {
			if (m_voltage_coefficient<=448) {
				m_current_conductivity=6.84*m_voltage_coefficient-64.32;
			}
			else if (m_voltage_coefficient<=1457) {
				m_current_conductivity=6.98*m_voltage_coefficient-127;
			}
			else {
				m_current_conductivity=5.3*m_voltage_coefficient+2278;
			}
			m_current_conductivity/=1000;
			Serial.print(m_current_conductivity,2);
			Serial.println("ms/cm");
		}
	}
}

void Conductivity::conductivity(Time time) {
	if (time.isequal(m_timeon)) {
		analog();
		temperature();
		print();
	}
}
		
Conductivity::~Conductivity() {
}