#ifndef Conductivity_h
#define Conductivity_h

#include <Arduino.h>
#include <Time.h>
#include <Wire.h>
#include <OneWire.h>


class Conductivity {
	
	public:
	
	bool get_StartConvert();
	bool get_ReadTemperature();
	byte get_NumberReading();
	byte get_pin_conductivity();
	byte get_pin_temperature();
	unsigned int get_analog_interval();
	unsigned int get_print_interval();
	unsigned int get_temperature_interval();
	unsigned int get_values_list();
	byte get_index();
	double get_analog_total();
	double get_analog_average();
	double get_voltage_average();
	unsigned long get_last_analog();
	unsigned long get_last_print();
	unsigned long get_last_temperature();
	double get_current_conductivity();
	double get_temperature();
	double get_temperature_coefficient();
	double get_voltage_coefficient();
	Time get_timeon();
	void set_pin_conductivity(byte pin_conductivity);
	void set_pin_temperature(byte pin_temperature);
	void set_analog_interval(unsigned int analog_interval);
	void set_print_interval(unsigned int print_interval);
	void set_temperature_interval(unsigned int temperature_interval);
	void set_values_list(unsigned int values_list[20]);
	void set_index(byte index);
	void set_analog_total(double analog_total);
	void set_analog_average(double analog_average);
	void set_voltage_average(double voltage_average);
	void set_last_analog(unsigned long last_analog);
	void set_last_print(unsigned long last_print);
	void set_last_temperature(unsigned long last_temperature);
	void set_current_conductivity(double current_conductivity);
	void set_temperature(double temperature);
	void set_temperature_coefficient(double temperature_coefficient);
	void set_voltage_coefficient(double voltage_coefficient);
	void set_timeon(Time timeon);
	void setup_conductivity();
	float temp(bool boolean);
	void analog();
	void temperature();
	void print();
	void conductivity(Time time);
	
	private:
	
	const bool m_StartConvert=false;
	const bool m_ReadTemperature=true;
	const int m_NumberReading=20;
	byte m_pin_conductivity;
	byte m_pin_temperature;
	unsigned int m_analog_interval;
	unsigned int m_print_interval;
	unsigned int m_temperature_interval;
	unsigned int m_values_list[m_NumberReading];
	byte m_index;
	double m_analog_total;
	double m_analog_average;
	double m_voltage_average;
	unsigned long m_last_analog;
	unsigned long m_last_print;
	unsigned long m_last_temperature;
	double m_current_conductivity;
	double m_temperature;
	double m_temperature_coefficient;
	double m_voltage_coefficient;
	Time m_timeon;
	
	
};

#endif