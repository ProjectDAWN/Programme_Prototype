#include <Arduino.h>
#include "Time.h"

Time::Time(int hour,int minute) {
	int m_hour = hour;
	int m_minute = minute;
}

int Time::get_hour() {
	return m_hour;
}

int Time::get_minute() {
	return m_minute;
}

void Time::set_hour(int hour) {
	m_hour=hour;
}

void Time::set_minute(int minute) {
	m_minute=minute;
}

bool Time::is_equal(int hour,int minute) {
	return m_hour==hour && m_minute==minute;
}

bool Time::is_inf_equal(int hour,int minute) {
	return m_hour<=hour && m_minute<=minute;
}

bool Time::is_sup_equal(int hour,int minute) {
	return !(is_inf_equal(hour,minute)) || is_equal(hour,minute);
}

bool Time::is_inf(int hour,int minute) {
	return m_hour<=hour && m_minute<minute;
}


bool Time::is_sup(int hour,int minute) {
	return !(is_inf(hour,minute) || is_equal(hour,minute));
}

void Time::add_hour(int hour) {
	m_hour=(m_hour + hour)%24;
}

void Time::add_minute(int minute) {
	add_hour(minute/60);
	m_minute=(m_minute+minute)%60;
}

Time::~Time() {
}