#ifndef COMPANY_H
#define COMPANY_H
#include <list>
#include <string>
#include <iostream>
#include <iterator>
#include <ctime>
#include "pilot.h"
#include "flightattendant.h"
#include "administrative.h"
#include "route.h"
#include "customer.h"
#include "employee.h"
#include "ticket.h"
#include "executionroute.h"
#include "User.h"
#include "Administrator.h"
#include "Session.h"
#include "date.h"
using namespace std;

class Company
{
	
    private:
        list<Route> routeList;
		list<Customer> customerList;
		list<Administrator> administratorList;
		list<Ticket> ticketList;
		list<Employee*> employeeList; // insted of . we put  ->
		list<ExecutionRoute> routeExecutionList;
		
		void loadRoutes(); // from file to list
		void loadCustomers();
		void loadAdministrators();
		void loadTickets();
		void loadRouteExecutions();
		void loadEmployees();
		
		void saveRoutes(); // from list to file
		void saveCustomers();
		void saveAdministrators();
		void saveTickets();
		void saveRouteExecutions();
		void saveEmployees();
		string inuser;
		string inpass;
		
		Route foundRoute(int routeID);
    public:
    	Session mySession;
		Company();
		
		void ticketing();
		void cancelTicket();
		
		bool checkIfExexecuted(Date);
		void removeRouteExecution();
		void addRouteExecution();
		void addRoute();
		void addRoute(Route);
		void removeRoute();
		void myInterface();
		int validate();
		
		void load();
		void save();
		
		// class destructor
		~Company();
};

#endif // COMPANY_H
