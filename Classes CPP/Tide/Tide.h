#ifndef Tide_h
#define Tide_h

#include <Arduino.h>
#include <Time.h>
#include <Wire.h>

class Tide {
	
	public:

	Tide(bool status_tide,bool status_oxygen,bool status_mixer,Time timeon_tide,Time timeoff_tide,int pin_tide,int pin_oxygen,int pin_mixer);
	Tide();
	bool get_status_tide();
	bool get_status_oxygen();
	bool get_status_mixer();
	//Time get_timeon_oxygen();
	//Time get_timeon_mixer;
	Time get_timeon_tide();
	//Time get_timeoff_oxygen();
	//Time get_timeoff_mixer();
	Time get_timeoff_tide();
	int get_pin_tide();
	int get_pin_oxygen();
	int get_pin_mixer();
	void set_status_tide(bool status);
	void set_status_oxygen(bool status);
	void set_status_mixer(bool status);
	//void set_timeon_oxygen(Time t);
	//void set_timeon_mixer(Time t);
	void set_timeon_tide(Time t);
	//void set_timeoff_oxygen(Time t);
	//void set_timeoff_mixer(Time t);
	void set_timeoff_tide(Time t);
	void set_pin_tide(int pin);
	void set_pin_oxygen(int pin);
	void set_pin_mixer(int pin);
	void setup_oxygen();
	void setup_mixer();
	void setup_tide();
	//void switch_on_oxygen(Time t);
	//void switch_off_oxygen(Time t);
	//void switch_on_mixer(Time t);
	//void switch_off_mixer(Time t);
	void switch_on_tide(Time t);
	void switch_off_tide(Time t);
	~Tide();
	
	private:
	
	bool m_status_tide;
	bool m_status_oxygen;
	bool m_status_mixer;
	Time m_timeon_oxygen;
	//Time m_timeon_mixer;
	//Time m_timeon_tide
	Time m_timeoff_oxygen;
	//Time m_timeoff_mixer;
	//Time m_timeoff_tide;
	int m_pin_tide;
	int m_pin_oxygen;
	int m_pin_mixer;
	
};

#endif