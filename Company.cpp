#include "company.h"

Company::Company(){}

void Company::myInterface(){
	
	string str, str2, dstr; Date d1;
    int action = 6, i, i2; char ch;int routeID;
    list<int> intlist; bool flag = false, b1, b2;
    //string inuser, inpas;
    cout << "\n      :: AIRLINE INFORMATION SYSTEM ::" << endl << endl;
    while(action == 6){
	    cout << "    username :" ;
	    cin >> this->inuser;
	    cout << "    password :" ;
	    cin >> this->inpass; cout << endl;
	    action = 1;
	    
	    if(validate() == 1){
	        cout << "    : CUSTOMER MODE :" << endl << endl;
	        cout << "    1. Print route catalogue" << endl;
	        cout << "    2. Buy ticket (if available)" << endl;
	        cout << "    3. Print purchased tickets" << endl;
	        cout << "    4. Cancel purchased ticket (before route execution)" << endl; // Give ticket id to delete
	        cout << "    5. Buy ticket for connected fly" << endl;
	        cout << "    6. Sign out" << endl;
	        cout << "    7. Save and Exit" << endl;
	        while(action > 0 && action < 8 && action != 6){
		        cout << "\n    Enter the option: ";
		        
		        cin >> action;
		        while( !(action > 0 && action < 8) ){
		        	cout << "    Enter invalid option: ";
		        	cin >> action;
				}
		        switch (action) {
		        	case 1:
		        		cout << "\n    Route catalogue:" << endl;
		        		cout << "    ----------------------------------------------------------------------\n";
		        		cout << "    ID | Start | Destination | Price | Start Time | Destination Time | Day " << endl;
		        		cout << "    ----------------------------------------------------------------------\n";
		        		for(list<Route>::iterator it = routeList.begin(); it != routeList.end(); ++it){
							(*it).Display();
						}
		        		break;
		        	case 2: // check if ex exist, ticketing()
		        		this->ticketing();
		        		break;
		        	case 3:
		        		for(list<Ticket>::iterator it = ticketList.begin(); it != ticketList.end(); ++it){
		        			if( mySession.getConnectedUser()->getID() == (*it).getCustomerID()){
		        				intlist.push_back((*it).getExecutionID());
		        			}
						}
						cout << "\n    My purchased tickets:\n";
						if(intlist.empty()) {
							cout << "    Not purchased tickets found!\n";
						}
						else {
							for(list<ExecutionRoute>::iterator it = routeExecutionList.begin(); it != routeExecutionList.end(); ++it){
								if( (*it).getID() == intlist.front() ){
									cout << "    ------------------------------------------------------------------\n";
									foundRoute((*it).getRouteID()).Display();
									cout << "    Execution Date: " << (*it).getDate() << endl;
									intlist.pop_front();
								}
							}
						}
		        		break;
		        	case 4:
		        		this->cancelTicket();
		        		break;
		        	case 5:
		        		cout << "    Give the 1st route ID: ";
						cin >> i;
						cout << "    Give the 2st route ID: ";
						cin >> i2;
						cout << "    Give the date (--/--/----): ";
						cin >> dstr;
						d1.setDate(dstr);
						for(list<Route>::iterator it = routeList.begin(); it != routeList.end(); ++it){
							if( (*it).getRouteID() == i)
								str = (*it).getDestination();
							if( (*it).getRouteID() == i2)
								str2 = (*it).getStart();
						}
						if(str == str2){
							// first I check if there are tickets available
							for(list<ExecutionRoute>::iterator it = routeExecutionList.begin(); it != routeExecutionList.end(); ++it){
								if( i == (*it).getRouteID() && d1.getDate() == (*it).getDate() && (*it).getExecuted() == false ){
									b1 = (*it).available();
								}
								if( i2 == (*it).getRouteID() && d1.getDate() == (*it).getDate() && (*it).getExecuted() == false ){
									b2 = (*it).available();
								}
							}
							if( b1 == b2 == true){
								for(list<ExecutionRoute>::iterator it = routeExecutionList.begin(); it != routeExecutionList.end(); ++it){
									if( i == (*it).getRouteID() && d1.getDate() == (*it).getDate() && (*it).getExecuted() == false ){
										if ( (*it).addCustomer( mySession.getConnectedUser()->getID() ) )
											ticketList.push_back( Ticket(mySession.getConnectedUser()->getID(), (*it).getID()) );
										flag = true;
									}
									else if( i == (*it).getRouteID() && d1.getDate() == (*it).getDate() && (*it).getExecuted() == true){
										cout << "    Route execution 1 has been executed";
										flag = true;
									}
									if( i2 == (*it).getRouteID() && d1.getDate() == (*it).getDate() && (*it).getExecuted() == false ){
										if ( (*it).addCustomer( mySession.getConnectedUser()->getID() ) )
											ticketList.push_back( Ticket(mySession.getConnectedUser()->getID(), (*it).getID()) );
										flag = true;
									}
									else if( i2 == (*it).getRouteID() && d1.getDate() == (*it).getDate() && (*it).getExecuted() == true){
										cout << "    Route execution 2 has been executed";
										flag = true;
									}	
								}
								if( flag == false ){
									cout << "    Route execution not found: ";
								}
							}
						}
						else
							cout << "    Route executions are not both available";
		        		break;
		        	case 6:
		        		mySession.setConnectedUser(NULL);
		        		cout << "    You signed out\n";
		        		break;
		        	case 7:
		        		this->save();
		        		exit(0);
		        		break;
	      		
				}
				
			}
		}
    
    else if(validate() == 2){
    	int id;
    	bool flag = false;
        cout << "    : ADMINISTRATOR MODE :" << endl << endl;
        cout << "    1. Create new user" << endl;
        cout << "    2. Print route catalogue" << endl;
        cout << "    3. Add / Remove route" << endl;
        cout << "    4. Add / Remove route execution" << endl;
        cout << "    5. Print customer base" << endl;
        cout << "    6. Print tickets by customer" << endl;
        cout << "    7. Sign out" << endl; // program does not terminate
        cout << "    8. Save and Exit" << endl;
        while(action > 0 && action < 9 && action != 6){
		    cout << "\n    Enter the option: ";
		    cin >> action;
		    while( !(action > 0 && action < 9) ){
		    	cout << "    Enter invalid option: ";
		    	cin >> action;
			}
		    switch (action) {
		    	case 1:
		    		cout << "    Create new Customer or Administrator? (c/a): ";
		    		cin >> ch;
		    		while(ch != 'a' && ch != 'c'){
		        		cout << "    (c/a): ";
		        		cin >> ch;
					}
					if(ch == 'c'){
						Customer c;
						cout << "    First and Last name: ";
						cin >> str;
						c.setName(str);
						cout << "    Address: ";
						cin >> str;
						c.setAddress(str);
						cout << "    Phone number: ";
						cin >> str;
						c.setNumber(str);
						cout << "    Username: ";
						cin >> str;
						c.setUsername(str);
						cout << "    Password: ";
						cin >> str;
						c.setPassword(str);
						customerList.push_back(c);
						cout << "    Customer recorded\n";
					}
					else {
						Administrator a;
						cout << "    Username: ";
						cin >> str;
						a.setUsername(str);
						cout << "    Password: ";
						cin >> str;
						a.setPassword(str);
						administratorList.push_back(a);
						cout << "    Administrator recorded\n";
					}
		    		break;
		    	case 2:
		    		cout << "\n    Route catalogue:" << endl;
		    		cout << "    ----------------------------------------------------------------------\n";
		    		cout << "    ID | Start | Destination | Price | Start Time | Destination Time | Day " << endl;
		    		cout << "    ----------------------------------------------------------------------\n";
		    		for(list<Route>::iterator it = routeList.begin(); it != routeList.end(); ++it){
						(*it).Display();
					}
		    		break;
		    	case 3:
		    		cout << "    Add (a) or Remove (r) ?: ";
		    		cin >> ch;
		    		while(ch != 'a' && ch != 'r'){
		        		cout << "    Add (a) or Remove (r) ?: ";
		        		cin >> ch;	
					}
					if(ch == 'a'){
						addRoute();
					}
					else{
						removeRoute();
					}
		    		break;
		    	case 4:
		            cout << "    Add (a) or Remove (r) ?: ";
		            cin >> ch;
		    		while(ch != 'a' && ch != 'r'){
		        		cout << "    Add (a) or Remove (r) ?: ";
		        		cin >> ch;	
					}
					if(ch == 'a'){
						this->addRouteExecution();
					}
					else{
						this->removeRouteExecution();
					}
		            break;
		    	case 5:
		    		cout << "    Customer base:" << endl;
		    		cout << "    ----------------------------------\n";
		    		cout << "    ID | Name | Phone Number | Address " << endl;
		    		cout << "    ----------------------------------\n";
		    		for(list<Customer>::iterator it = customerList.begin(); it != customerList.end(); ++it){
						(*it).Display();
					}
		    		break;
		    	case 6: // to check
		    		cout << "    Give the customer ID to display his/her tickets: "; // y/n
		    		cin >> id;
		    		cout << "    His/Her tickets:\n";
		    		cout << "    --------------------------------------------\n";
		    		cout << "    Ticket ID | Customer ID | Route Execution ID" << endl;
		    		cout << "    --------------------------------------------\n";
		    		for(list<Ticket>::iterator it = ticketList.begin(); it != ticketList.end(); ++it){
		    			if( (*it).getCustomerID() == id ){
		    				(*it).Display();
		    				flag = true;
						}
					}
					if(flag == false){
						cout << "    Given customer hasn't bought tickets\n"; // doesn't own purchased tickets
					}
		    		break;
		    	case 7:
		    		mySession.setConnectedUser(NULL);
		    		cout << "    You signed out\n";
		    		action = 6;
		    		break;
		    	case 8:
		    		this->save();
		    		exit(0);
		    		break;
			}
		}
    }
    else{
    	cout << "    Wrong username or password. Please try again.\n";
    	action = 6;
	}
    cout << endl;
	}
}

int Company::validate()
{
	for(list<Customer>::iterator it = customerList.begin(); it != customerList.end(); ++it){
		if((*it).getUsername() == this->inuser && (*it).getPassword() == this->inpass){
			mySession.setConnectedUser(&(*it));
			return 1;
		}
	}
	for(list<Administrator>::iterator it = administratorList.begin(); it != administratorList.end(); ++it){
		if( (*it).getUsername() == this->inuser && (*it).getPassword() == this->inpass){
			mySession.setConnectedUser(&(*it));
			return 2;
		}
	}
	return 0;
}

void Company::ticketing(){
	int i; string str; Date d;
	bool flag = false;
	cout << "    Give the route ID: ";
	cin >> i;
	cout << "    Give the date (--/--/----): ";
	cin >> str;
	d.setDate(str);
	for(list<ExecutionRoute>::iterator it = routeExecutionList.begin(); it != routeExecutionList.end(); ++it){
		if( i == (*it).getRouteID() && d.getDate() == (*it).getDate() && (*it).getExecuted() == false ){
			if ( (*it).addCustomer( mySession.getConnectedUser()->getID() ) )
				ticketList.push_back( Ticket(mySession.getConnectedUser()->getID(), (*it).getID()) );
			flag = true;
		}
		else if( i == (*it).getRouteID() && d.getDate() == (*it).getDate() && (*it).getExecuted() == true){
			cout << "    Route execution has been executed";
			flag = true;
		}
	}
	if( flag == false ){
		cout << "    Route execution not found: ";
	}
}

void Company::cancelTicket(){
	int i; string str; Date d;
	cout << "    Give the route ID: ";
	cin >> i;
	cout << "    Give the date (--/--/----): ";
	cin >> str;
	d.setDate(str);
	for(list<ExecutionRoute>::iterator it = routeExecutionList.begin(); it != routeExecutionList.end(); ++it){
		if( i == (*it).getRouteID() && d.getDate() == (*it).getDate() /*&& (*it).getExecuted() == false*/ ){
			if ( (*it).removeCustomer( mySession.getConnectedUser()->getID() ) ){
				for(list<Ticket>::iterator it = ticketList.begin(); it != ticketList.end(); ++it){
					if( mySession.getConnectedUser()->getID() == (*it).getCustomerID()){
						it = ticketList.erase(it);
					}
				}
			}
		}
	}
}

void Company::addRouteExecution(){
	char action = 'y';
	string str;
	int i;
	ExecutionRoute er;
	while(action == 'y' || action == 'Y'){
		//er.setID(er.getNumberOfER() + 1);
		cout << "    Pilot 1 ID: ";
		cin >> i;
		er.setPilotID(0,i);
		cout << "    Pilot 2 ID: ";
		cin >> i;
		er.setPilotID(1,i);
		cout << "    Flight Attendant 1 ID: ";
		cin >> i;
		er.setFlightAttendantID(0,i);
		cout << "    Flight Attendant 2 ID: ";
		cin >> i;
		er.setFlightAttendantID(1,i);
		cout << "    Flight Attendant 3 ID: ";
		cin >> i;
		er.setFlightAttendantID(2,i);
		cout << "    Flight Attendant 4 ID: ";
		cin >> i;
		er.setFlightAttendantID(3,i);
		cout << "    Route ID: ";
		cin >> i;
		er.setRouteID(i);
		cout << "    Date: ";
		cin >> str;
		er.setDate(str);
		er.setExecuted(checkIfExexecuted(Date(er.getDate())));
		cout << "    Max Persons: ";
		cin >> i;
		er.setMaxPersons(i);
		routeExecutionList.push_back(er);
		cout << "\n    Route Execution has been recorded. Do you want to add another? (y/n): ";
		cin >> action;
		while( !(action == 'y' || action == 'Y' || action == 'n' || action ==  'N')){
			cout << "\n    y/n: ";
			cin >> action;
		}
	}
}

void Company::addRoute(){ // to chech enters \n
	char action = 'y';
	float p;
	int i;
	string str;
	Route r;
	while(action == 'y' || action == 'Y'){
		cout << "    ID: ";
		cin >> i;
		r.setRouteID(i);
		cout << "    Start: ";
		cin >> str;
		r.setStart(str);
		cout << "    Destination: ";
		cin >> str;
		r.setDestination(str);
		cout << "    Price: ";
		cin >> p;
		r.setPrice(p);
		cout << "    Start time (--:--): ";
		cin >> str;
		Time t; t.setTime(str);
		r.setStartTime(t);
		cout << "    Destination time: ";
		cin >> str;
		t.setTime(str);
		r.setDestinationTime(t);
		cout << "    Day (1-7): ";
		cin >> i;
		Day d(i);
		r.setRouteDay(d);
		routeList.push_back(r);
		cout << "\n    Route has been recorded. Do you want to add another Route? (y/n): ";
		cin >> action;
		while( !(action == 'y' || action == 'Y' || action == 'n' || action ==  'N')){
			cout << "\n    y/n: ";
			cin >> action;
		}
	}
}

void Company::addRoute(Route r){
	this->routeList.push_back(r);
}

void Company::removeRoute(){
	int id;
	list<Route>::iterator it;
	char action = 'y';
	while(action == 'y' || action == 'Y'){
		cout << "\n    Give the Route ID you want to delete: ";
		cin >> id;
		bool flag = false;
		for(it = routeList.begin(); it != routeList.end(); ++it){
			if((*it).getRouteID() == id){
				it = routeList.erase(it);
				cout << "\n    Route has been deleted.";
				flag = true;
			}
		}
		if(flag == false){
			cout << "\n    Route does not exist to be deleted.";
		}
		cout << "\n    Do you want to delete another Route? (y/n): ";
		cin >> action;
		while( !(action == 'y' || action == 'Y' || action == 'n' || action ==  'N')){
			cout << "\n    y/n: ";
			cin >> action;
		}
	}
}

void Company::removeRouteExecution(){
	int id;
	list<ExecutionRoute>::iterator it;
	char action = 'y';
	while(action == 'y' || action == 'Y'){
		cout << "\n    Give the Route Execution ID you want to delete: ";
		cin >> id;
		bool flag = false;
		for(it = routeExecutionList.begin(); it != routeExecutionList.end(); ++it){
			if((*it).getID() == id){
				it = routeExecutionList.erase(it);
				cout << "\n    Route Execution has been deleted.";
				flag = true;
				break;
			}
		}
		if(flag == false){
			cout << "\n    Route Execution does not exist to be deleted.";
		}
		cout << "\n    Do you want to delete another Route Execution? (y/n): ";
		cin >> action;
		while( !(action == 'y' || action == 'Y' || action == 'n' || action ==  'N')){
			cout << "\n    y/n: ";
			cin >> action;
		}
	}
}

void Company::loadRoutes() {
	ifstream infile;
	infile.open("routes.txt");

	string strRoute;
	
	while (infile.good()) {
		getline(infile, strRoute);
		if (strRoute.length() > 1) {
			this->routeList.push_back(Route(strRoute));
		}
	}
	infile.close();
}

void Company::loadCustomers(){
	ifstream infile;
	infile.open("customers.txt");
	string str;
	getline(infile, str);
	Customer().setNumberOfU(stoi(str)); // <---------------------------
	while (infile.good()) {
		getline(infile, str);
		if (str.length() > 1) {
			this->customerList.push_back(Customer(str));
		}
	}
	infile.close();
}

void Company::loadAdministrators(){
	ifstream infile;
	infile.open("Administrators.txt");
	string str;
	getline(infile, str);
	Administrator().setNumberOfU(stoi(str)); // <---------------------------
	while (infile.good()) {
		getline(infile, str);
		if (str.length() > 1) {
			this->administratorList.push_back(Administrator(str));
		}
	}
	infile.close();
}

void Company::loadTickets(){
	ifstream infile;
	infile.open("tickets.txt");
	string str;
	getline(infile, str);
	Ticket().setNumberOfT(stoi(str)); // <---------------------------
	while (infile.good()) {
		getline(infile, str);
		if (str.length() > 1) {
			this->ticketList.push_back(Ticket(str));
		}
	}
	infile.close();
}

void Company::loadRouteExecutions(){
	ifstream infile;
	infile.open("routeExecutions.txt");
	string str;
	getline(infile, str);
	ExecutionRoute().setNumberOfER(stoi(str)); // <---------------------------
	while (infile.good()) {
		getline(infile, str);
		if (str.length() > 1) {
			this->routeExecutionList.push_back(ExecutionRoute(str));
		}
	}
	for(list<ExecutionRoute>::iterator it = routeExecutionList.begin(); it != routeExecutionList.end(); ++it){
		(*it).setExecuted(this->checkIfExexecuted(Date((*it).getDate())));
	}
	infile.close();
}

void Company::loadEmployees() {
	ifstream infile;
	infile.open("employees.txt");

	int ctype;
	string type;
	string strEmployee;
	
	getline(infile, strEmployee);
	Pilot().setNumberOfE(stoi(strEmployee)); // <---------------------------
	while (infile.good()) {
		getline(infile, type);
		//cout << type << endl;
		getline(infile, strEmployee);
		//cout << strEmployee;
		if (strEmployee.length() > 1) {
			ctype = stoi(type);
			switch(ctype) {
				case 0: // pilot
					this->employeeList.push_back(new Pilot(strEmployee)); // with new, pointer to object, without object
					break;
				case 1: // flightAttendant
					this->employeeList.push_back(new FlightAttendant(strEmployee));
					break;
				case 2: // administrative
					this->employeeList.push_back(new Administrative(strEmployee));
					break;
				default:
					break;
			}
		}
	}

	infile.close();
	
//	for (std::list<Employee*>::iterator it = this->employeeList.begin(); it != this->employeeList.end(); it++) {
//		(*it)->Display();
//	}
}

void Company::saveRoutes(){
	ofstream outfile;
	outfile.open("routes.txt", std::ofstream::out | std::ofstream::trunc);
	string str;
	for(list<Route>::iterator it = routeList.begin(); it != routeList.end(); ++it){
		str = str + (*it).toString();
	}
	outfile <<  str;
	outfile.close();
}

void Company::saveCustomers(){
	ofstream outfile;
	outfile.open("customers.txt", std::ofstream::out | std::ofstream::trunc);
	string str;
	str = to_string(customerList.front().getNumberOfU()) + "\n"; // <-----------------------
	for(list<Customer>::iterator it = customerList.begin(); it != customerList.end(); ++it){
		str = str + (*it).toString();
	}
	outfile <<  str;
	outfile.close();
}

void Company::saveAdministrators(){
	ofstream outfile;
	outfile.open("administrators.txt", std::ofstream::out | std::ofstream::trunc);
	string str;
	str = to_string(administratorList.front().getNumberOfU()) + "\n"; // <-----------------------
	for(list<Administrator>::iterator it = administratorList.begin(); it != administratorList.end(); ++it){
		str = str + (*it).toString();
	}
	outfile <<  str;
	outfile.close();
}

void Company::saveTickets(){
	ofstream outfile;
	outfile.open("tickets.txt", std::ofstream::out | std::ofstream::trunc);
	string str;
	str = to_string(ticketList.front().getNumberOfT()) + "\n"; // <-----------------------
	for(list<Ticket>::iterator it = ticketList.begin(); it != ticketList.end(); ++it){
		str = str + (*it).toString();
	}
	outfile <<  str;
	outfile.close();
}

void Company::saveRouteExecutions(){
	ofstream outfile;
	outfile.open("routeExecutions.txt", std::ofstream::out | std::ofstream::trunc);
	string str;
	str = to_string(routeExecutionList.front().getNumberOfER()) + "\n"; // <-----------------------
	for(list<ExecutionRoute>::iterator it = routeExecutionList.begin(); it != routeExecutionList.end(); ++it){
		str = str + (*it).toString();
	}
	outfile <<  str;
	outfile.close();
}

void Company::saveEmployees(){
	ofstream outfile;
	outfile.open("employees.txt", std::ofstream::out | std::ofstream::trunc);
	string str;
	str = to_string(employeeList.front()->getNumberOfE()) + "\n"; // <-----------------------
	for(list<Employee*>::iterator it = employeeList.begin(); it != employeeList.end(); ++it){
		str = str + (*it)->toString();
	}
	outfile << str << endl;
	outfile.close();
}

void Company::load() {
	this->loadRoutes();
	this->loadCustomers();
	this->loadAdministrators();
	this->loadTickets();
//	this->loadEmployees();
	this->loadRouteExecutions();
	// more
}

void Company::save(){
	this->saveRoutes();
	this->saveCustomers();
	this->saveAdministrators();
	this->saveTickets();
//	this->saveEmployees();
	this->saveRouteExecutions();
}

bool Company::checkIfExexecuted(Date date){
	Date currDate;
	
	time_t now = time(0);
	tm *ltm = localtime(&now);
	
	currDate.setYear(1900 + ltm->tm_year);
	currDate.setMonth(1 + ltm->tm_mon);
	currDate.setDay(ltm->tm_mday);
	
	if(date.getYear() > currDate.getYear()){
		return 0; // not executed
	}
	if(date.getYear() < currDate.getYear()){
		return 1; // executed
	}
	if(date.getYear() == currDate.getYear()){
		if(date.getMonth() > currDate.getMonth()){
			return 0; // not executed
		}
		if(date.getMonth() < currDate.getMonth()){
			return 1; // executed
		}
		if(date.getMonth() == currDate.getMonth()){
			if(date.getDay() > currDate.getDay()){
				return 0; // not executed
			}
			if(date.getDay() < currDate.getDay()){
				return 1; // executed
			}
			if(date.getDay() == currDate.getDay()){
				return 1; // executed
			}
		}
	}
}

Route Company::foundRoute(int routeID) {
	for(list<Route>::iterator it = routeList.begin(); it != routeList.end(); ++it){
		if ((*it).getRouteID() == routeID){
			return *it;
		}
	}
}

Company::~Company(){}
