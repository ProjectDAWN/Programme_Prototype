#include <Arduino.h>
#include <Time.h>
#include <Wire.h>
#include "Tide.h"

Tide::Tide(bool status_tide,bool status_oxygen,bool status_mixer,Time timeon_tide,Time timeoff_tide,int pin_tide,int pin_oxygen,int pin_mixer) {
		m_status_tide=status_tide;
		m_status_oxygen=status_oxygen;
		m_status_mixer=status_mixer;
		m_timeon_tide=timeon_tide;
		//m_timeon_oxygen=timeon_oxygen;
		//m_timeon_mixer=timeon_mixer;
		m_timeoff_tide=timeoff_tide;
		//m_timeoff_oxygen=timeoff_oxygen;
		//m_timeoff_mixer=timeoff_mixer;
		m_pin_tide=pin_tide;
		m_pin_oxygen=pin_oxygen;
		m_pin_mixer=pin_mixer;
}

Tide::Tide() {
	bool status_tide=false;
	bool status_oxygen=false;
	bool status_mixer=false;
	Time timeon_tide=new Time(0,0);
	Time timeoff_tide=new Time(0,30);
	int pin_tide=2;
	int pin_oxygen=3;
	int pin_mixer=4;
	Tide(status_tide,status_oxygen,status_mixer,timeon_tide,timeoff_tide,pin_tide,pin_oxygen,pin_mixer);
}
	

bool Tide::get_status_tide() {
	return m_status_tide;
}

bool Tide::get_status_oxygen() {
	return m_status_oxygen;
}

bool Tide::get_status_mixer() {
	return m_status_mixer;
}

Time Tide::get_timeon_tide() {
	return m_timeon_tide;
}

/* Time ::Tide::get_timeon_oxygen() {
	return m_timeon_oxygen;
}

Time Tide::get_timeon_mixer() {
	return m_timeon_mixer; 
} */

Time Tide::get_timeoff_tide() {
	return m_timeoff_tide;
}

/* Time Tide::get_timeoff_oxygen() {
	return m_timeoff_oxygen;
}

Time Tide::get_timeoff_mixer() {
	return m_timeoff_mixer; 
} */

int Tide::get_pin_tide() {
	return m_pin_tide;
}

int Tide::get_pin_oxygen() {
	return m_pin_oxygen;
}

int Tide::get_pin_mixer() {
	return m_pin_mixer;
}

void Tide::set_status_tide(bool status_tide) {
	m_status_tide=status_tide;
}

void Tide::set_status_oxygen(bool status_oxygen) {
	bool m_status_oxygen=status_oxygen;
}

void Tide::set_status_mixer(bool status_mixer) {
	bool m_status_mixer=status_mixer;
}

void Tide::set_timeon_tide(Time timeon_tide) {
	Time m_timeon_tide=timeon_tide;
}

/* void Tide::set_timeon_oxygen(Time timeon_oxygen) {
	Time m_timeon_oxygen=timeon_oxygen;
}

void Tide::set_timeon_mixer(Time timeon_mixer) {
	Time m_timeon_mixer=timeon_mixer; */
}

void Tide::set_timeoff_tide(Time timeoff_tide) {
	Time m_timeoff_tide=timeoff_tide;
}

/* void Tide::set_timeoff_oxygen(Time timeoff_oxygen) {
	Time m_timeoff_oxygen=timeoff_oxygen;
}

void Tide::set_timeoff_mixer(Time timeoff_mixer) {
	Time m_timeoff_mixer=timeoff_mixer; 
} */

void Tide::set_pin_tide(int pin_tide) {
	int m_pin_tide=pin_tide;
}

void Tide::set_pin_oxygen(int pin_oxygen) {
	int m_pin_oxygen=pin_oxygen;
}

void Tide::set_pin_mixer(int pin_mixer) {
	int m_pin_mixer=pin_mixer;
}

void Tide::setup_tide() {
	pinMode(m_pin_tide,OUTPUT);
	digitalWrite(m_pin_tide,HIGH);
}

void Tide::setup_oxygen() {
	pinMode(m_pin_oxygen,OUTPUT);
	digitalWrite(m_pin_oxygen,LOW);
}

void Tide::setup_mixer() {
	pinMode(m_pin_tide,OUTPUT);
	digitalWrite(m_pin_tide,LOW);
}

void Tide::switch_on_tide(Time t) {
	if (!m_status_tide && t.isequal(m_timeon_tide) ) {
		digitalWrite(m_pin_tide,LOW);
		set_status_tide(!m_status_tide);
	}
}

/* void Tide::switch_on_oxygen(Time t) {
	if (!m_status_oxygen && t.isequal(m_timeon_oxygen)) {
		digitalWrite(m_pin_oxygen,LOW);
		set_status_oxygen(!m_status_oxygen);
	}
}

void Tide::switch_on_mixer(Time t) {
	if (!m_status_mixer && t.isequal(m_timeon_mixer)) {
		digitalWrite(m_pin_mixer,LOW);
		set_status_oxygen(!m_status_mixer);
	}
} */

void Tide::switch_off_tide(Time t) {
	if (m_status_tide && t.isequal(m_timeoff_tide)) {
		digitalWrite(m_pin_tide,HIGH);
		set_status_tide(!m_status_tide);
	}
}

/* void Tide::switch_off_oxygen(Time t) {
	if (m_status_oxygen && t.isequal(m_timeoff_oxygen)) {
		digitalWrite(m_pin_oxygen,HIGH);
		set_status_oxygen(!m_status_oxygen);
	}
}

void Tide::switch_off_mixer(Time t) {
	if (m_status_mixer && t.isequal(m_timeoff_mixer)) {
		digitalWrite(m_pin_mixer,HIGH);
		set_status_mixer(!m_status_mixer);
	}
} */

Tide::~Tide() {
}
