#ifndef FLIGHTATTENDANT_H
#define FLIGHTATTENDANT_H
#include <iostream>
#include <list>
#include <sstream>
#include "employee.h"
using namespace std;

class FlightAttendant : public Employee {
	
    private:
        unsigned int yearsExperience;
        
	public:
		
		FlightAttendant();
		FlightAttendant(string fn, string ln, string ads, string nb, unsigned int);
		FlightAttendant(string); // tested
		
		void setYearsExperience(unsigned int);
		unsigned int getYearsExperience();
		
		void Display();
        
        virtual string toString();
        
		// class destructor
		~FlightAttendant();
};

#endif // FLIGHTATTENDANT_H
