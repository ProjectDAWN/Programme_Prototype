#ifndef Led_h
#define Led_h

#include <Arduino.h>
#include <Time.h>
#include <Wire.h>

class Led {
	public:
	
	bool get_status();
	Time get_timeon();
	Time get_timeoff();
	int get_pin();
	void set_status(bool status);
	void set_timeon(Time timeon);
	void set_timeoff(Time timeoff);
	void set_pin(int pin);
	void setup_led();
	void switch_on(Time t);
	void switch_off(Time t);
	float average_to_pH();
	
	
	private:
	
	bool m_status;
	Time m_timeon;
	Time m_timeoff;
	int m_pin;
	
};

#endif