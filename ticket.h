#ifndef TICKET_H
#define TICKET_H
#include <string>
#include <iostream>
#include <list>
#include <sstream>
#include "date.h"

using namespace std;

class Ticket
{
    private:
		int ticketID;
		int customerID;
		int executionID;
		static int numberOfT;
	public:
		// class constructor
		Ticket();
		Ticket(int, int);
		Ticket(string);
		
		string toString();
		void Display();
		
		void setTicketID(int);
		void setCustomerID(int);
		void setExecutionID(int);
		void setNumberOfT(int);
		//void setRouteID(int);
		int getTicketID();
		int getCustomerID();
		int getExecutionID();
		int getNumberOfT();
		//int getRouteID();
		
		// class destructor
		~Ticket();
};

#endif // TICKET_H
