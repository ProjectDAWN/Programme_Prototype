#ifndef Ph_h
#define Ph_h

#include <Arduino.h>
#include <Time.h>
#include <Wire.h>
#include <Utils.h>

class Ph {
	
	public:
	
	bool get_status();
	Time get_timeon();
	int get_pin();
	unsigned int long get_Ph_average();
	int get_Ph_list();
	float get_Ph_final;
	void set_status(bool status);
	void set_timeon(Time time);
	void set_pin(int pin);
	void set_Ph_average(unsigned long int Ph_average);
	void set_Ph_list(int Ph_list[10]);
	void set_Ph_final(float Ph_final);
	float get_Ph(Time time);
	void fill_Ph_list();
	void fill_average_Ph();
	
	
	private:
	
	bool m_status;
	Time m_timeon;
	int m_pin;
	unsigned long int m_Ph_average;
	int m_Ph_list[10];
	float m_Ph_final;
	
};

#endif