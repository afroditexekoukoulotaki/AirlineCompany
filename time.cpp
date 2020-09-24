#include "time.h" // class's header file


// class constructor
Time::Time(unsigned int hour, unsigned int minutes) : hour(hour), minutes(minutes) {}

Time::Time(){}

void Time::setHour(unsigned int hr) { hour = hr; }
     
void Time::setMinutes(unsigned int mn) { minutes = mn; }

unsigned int Time::getHour() {return hour; }

unsigned int Time::getMinutes() {return minutes; }

string Time::getTime() { // gets object Time and returns string like 03:45
	char pin[2];
	string str, h, m;
	
	str = itoa(this->hour, pin, 10); // int to string. return A pointer to the resulting null-terminated string, same as parameter str.
    if(this->hour < 10)
		h = '0' + str;
	else
		h = str;
		
	str = itoa(this->minutes, pin, 10);
	if(this->minutes < 10)
		m = '0' + str;
	else
		m = str;
	str = h + ':' + m;
	
	return str;
}

 //string to Time
void Time::setTime(string s){
	while (s.length() != 5 || s.at(2) != ':' || stoi(s.substr(0,2)) < 0 || stoi(s.substr(0,2)) > 23 || stoi(s.substr(3,2)) < 0 || stoi(s.substr(3,2)) > 59){
		cout << "    Enter valid time (--:--): ";
		cin >> s;
	}
	this->hour = stoi(s.substr(0,2));
	this->minutes = stoi(s.substr(3,2));
}

// class destructor
Time::~Time(){}
