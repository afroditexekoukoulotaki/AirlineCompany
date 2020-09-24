#ifndef PILOT_H
#define PILOT_H
#include <list>
#include <iostream>
#include <sstream>
#include "employee.h"
using namespace std;


class Pilot : public Employee
{
    private:
        unsigned int flightHours;
	public:
		
		Pilot();
		Pilot(string fn, string ln, string ads, string nb, unsigned int fh);
		Pilot(string); // tested
		// class destructor
		~Pilot();
		
		void setFlightHours(unsigned int);
		unsigned int getFlightHours();
		
		virtual void Display();
		string toString();
};

#endif // PILOT_H
