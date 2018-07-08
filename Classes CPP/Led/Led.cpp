
Led::Led(bool status,Time timeon,Time timeoff,int pin) {
	m_status=status;
	m_timeon=timeon;
	m_timeoff=timeoff;
	m_pin=pin;
}

Led::Led(int pin) {
	bool status = false;
	Time timeon = Time(5,0);
	Time timeoff = Time(23,0);
	Led(status,timeon,timeoff,pin);
}

bool Led::get_status() {
	return m_status;
}

Time Led::get_timeon() {
	return m_timeon;
}

Time Led::get_timeoff() {
	return m_timeoff;
}

int Led::get_pin() {
	return m_pin;
}

void Led::set_status(bool status) {
	m_status=status;
}

void Led::set_timeon(Time timeon) {
	m_timeon=timeon;
}

void Led::set_timeoff(Time timeoff) {
	m_timeoff=timeoff;
}

void Led::set_pin(int pin) {
	m_pin=pin;
}

void Led::setup_led() {
	pinMode(m_pin,OUTPUT);
	digitalWrite(m_pin,HIGH);
}

void Led::switch_on(Time t) {
	if(t.is_sup_equal(m_timeon) && t.is_inf(m_timeoff) && !m_status) {
		digitalWrite(m_pin,LOW);
		set_status(!m_status);
	}
}

void Led::switch_off(Time t) {
	if(t.is_sup_equal(m_timeoff) && m_status) {
		digitalWrite(m_pin,HIGH);
		set_status(!m_status);
	}
}

Led::~Led() {
}

