#include <Arduino.h>
#include <Time.h>
#include <Wire.h>
#include "Ph.h"
#include <Utils.h>

Ph::Ph(bool status,Time timeon,int pin,unsigned long int Ph_average,int Ph_list[10]) {
	m_status=status;
	m_timeon=timeon;
	m_pin=pin;
	m_Ph_average=Ph_average;
	m_Ph_list=Ph_list;
}

Ph::Ph() {
	bool status = false;
	Time timeon = Time(0,0);
	int pin=0;
	unsigned long int Ph_average = 0;
	int Ph_list[10];

bool Ph::get_status() {
	return m_status;
}

Time Ph::get_timeon() {
	return m_timeon;
}

int Ph::get_pin() {
	return m_pin;
}

unsigned long int Ph::get_Ph_average() {
	return m_Ph_average;
}

int Ph::get_Ph_list() {
	return m_Ph_list;
}

float Ph::get_Ph_final() {
	return m_Ph_final;
}

void Ph::set_status(bool status) {
	m_status = status ;
}

void Ph::set_timeon(Time time) {
	m_timeon=time;
}

void Ph::set_pin(int pin) {
	m_pin = pin;
}

void Ph::set_Ph_average(unsigned long int Ph_average) {
	m_Ph_average=Ph_average;
}

void Ph::set_Ph_list(int Ph_list[10]) {
	m_Ph_list=Ph_list;
}

void Ph::set_Ph_final(float Ph_final) {
	m_Ph_final=Ph_final;
}

float Ph::get_Ph() {
	fill_Ph_list();
	fusion_sort(m_Ph_list,0,9);
	fill_average_Ph();
	return(m_Ph_final);
}

void Ph::fill_Ph_list() {
	for(int i=0;i<10;i++)   {
		m_Ph_list[i]=analogRead(SensorPin);
		delay(10);
  }
}

void Ph::fill_average_Ph() {
	for(int i=2;i<8;i++)
  {
    m_Ph_average+=m_Ph_list[i];
  }
  m_Ph_final=(float)m_Ph_average*((5.0*3.5)/(6*1024));
}

Ph::~Ph() {
}

