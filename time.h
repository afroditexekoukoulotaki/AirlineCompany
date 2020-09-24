#ifndef TIME_H
#define TIME_H
#include <string>
#include <stdlib.h>
#include <iostream>
using namespace std;

class Time
{
    private:
        unsigned int hour;
        unsigned int minutes;
	public:
		
		Time(unsigned int hour, unsigned int minutes);
		Time();
		
		void setTime(string); //string to Time
		
		void setHour(unsigned int);
		void setMinutes(unsigned int);
		unsigned int getHour();
		unsigned int getMinutes();
		string getTime(); // gets object Time and returns string like 03:45
		
		// class destructor
		~Time();
};

#endif // TIME_H
