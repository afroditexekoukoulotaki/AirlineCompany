#ifndef ROUTE_H
#define ROUTE_H
#include <iostream>
#include <string>
#include <list>
#include <stdlib.h>
#include <fstream>
#include <sstream> 
#include "time.h"
#include "day.h"

using namespace std;


class Route
{
    private:
		int routeID;
		string start;
		string destination;
		float price;
		Time startTime;
		Time destinationTime;
		Day routeDay;
	public:
		// class constructor
		Route();
		Route(int, string, string, float, Time, Time, Day);
		Route(string);
		
		//void load(list<Route>&);
		string toString();
		void Display();
		//void addRoute();
		
		void setRouteID(int);
		int getRouteID();
		void setStart(string);
		string getStart();
		void setDestination(string);
		string getDestination();
		void setPrice(float);
		float getPrice();
		void setStartTime(Time);
		void setDestinationTime(Time);
		Time getStartTime();
		Time getDestinationTime();
		void setRouteDay(Day);
		Day getRouteDay();
		// class destructor
		~Route();
};

#endif // ROUTE_H
