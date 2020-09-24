#ifndef EXECUTIONROUTE_H
#define EXECUTIONROUTE_H
#include <string>
#include <iostream>
#include <list>
#include <sstream>
#include <iterator>
#include "date.h"
#include "customer.h"

using namespace std;

class ExecutionRoute
{
    private:
		int pilotsID[2];
		int flightAttendantsID[4];
		int routeID;
		Date exDate;
		bool executed;
		unsigned int maxPersons;
		
		static int numberOfER;
		int id;
	public:
		
		list<int> customersID;
		
		ExecutionRoute();
		ExecutionRoute(int pIDs[], int fIDs[], int, Date, bool executed = false , unsigned int maxPersons = 2);
		ExecutionRoute(string);
		
		string toString();
		//functions for customers add/remove/get etc.
		bool addCustomer(int id);
		bool removeCustomer(int id);
		bool available();
		
		void setDate(string);
		void setPilotID(int, int);
		void setFlightAttendantID(int, int);
		void setRouteID(int);
		void setMaxPersons(unsigned int);
		void setID(int);
		void setNumberOfER(int n);
		void setExecuted(bool);
		
		string getDate();
		int getPilotID(int); // 0-1
		int getFlightAttendantID(int); // 0-3
		int getRouteID();
		unsigned int getMaxPersons();
		int getID();
		int getNumberOfER();
		bool getExecuted();
		
		// class destructor
		~ExecutionRoute();
		
		void Display() {
		};
};

#endif // EXECUTIONROUTE_H
