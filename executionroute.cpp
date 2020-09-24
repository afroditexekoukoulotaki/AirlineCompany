#include "executionroute.h" // class's header file

int ExecutionRoute::numberOfER;

// class constructor
ExecutionRoute::ExecutionRoute(){
	this->id = ++numberOfER;
	this->executed = false;
}
    		
ExecutionRoute::ExecutionRoute(int pIDs[], int fIDs[], int routeID, Date exDate, bool executed, unsigned int maxPersons) 
               :   id(++numberOfER),
                   routeID(routeID),
                   exDate(exDate),
                   executed(executed),
                   maxPersons(maxPersons)
               {
                   this->pilotsID[0] = pIDs[0];
                   this->pilotsID[1] = pIDs[1];
                   for (int i=0;i<4;i++)
                       this->flightAttendantsID[i] = fIDs[i];
}

ExecutionRoute::ExecutionRoute(string str){
	istringstream issin(str);
	list<string> elements;
	string el;
	int i = 0;

	while (getline(issin, el, '|')) {
		elements.push_back(el);
		i++;
	}
	this->id = stoi(elements.front()); elements.pop_front();
	this->pilotsID[0] = stoi(elements.front()); elements.pop_front();
	this->pilotsID[1] = stoi(elements.front()); elements.pop_front();
	for (int i=0;i<4;i++){
        this->flightAttendantsID[i] = stoi(elements.front());
		elements.pop_front();
	}
	this->routeID = stoi(elements.front()); elements.pop_front();
	this->exDate = Date(elements.front()); elements.pop_front();
	this->executed = stoi(elements.front()); elements.pop_front();
	this->maxPersons = stoi(elements.front()); elements.pop_front();
	
	while (!elements.empty()) {
		this->customersID.push_back(stoi(elements.front()));
		elements.pop_front();
	}
}

string ExecutionRoute::toString(){
	string str = to_string(this->id) + "|";
	str +=  to_string(this->pilotsID[0]) + "|" + to_string(this->pilotsID[1]) + "|" + to_string(this->flightAttendantsID[0]) 
				+ "|" + to_string(this->flightAttendantsID[1]) + "|" + to_string(this->flightAttendantsID[2]) 
				+ "|" + to_string(this->flightAttendantsID[3]) + "|" + 	to_string(this->routeID) + "|" + this->exDate.getDate() 
				+ "|" + to_string(this->executed) + "|" + to_string(this->maxPersons);
	for (list<int>::iterator it = customersID.begin(); it != customersID.end(); ++it){
		str += "|" + to_string(*it);
	}
	str = str + "\n";
	return str;
}

bool ExecutionRoute::addCustomer(int id) {
	int count = 0;
     // check megethos listas dld posa tickets exoun dwthei kai na pros8etei mono an einai katw apo to maxPersons
    for (list<int>::iterator it = customersID.begin(); it != customersID.end(); ++it){
    	count++;
        if ( *it == id ){
            cout << "\n    Customer already exist to list";
            return false;
        }
	}
    if( count < this->maxPersons){
        this->customersID.push_back(id);
        cout << "\n    Customer recorded.\n  Current customers: " << count+1 << " Max: " << this->maxPersons << endl;
        return true;
    }
    else {
        cout << "\n    Customer list is full" << endl;
        return false;
    }
}
bool ExecutionRoute::removeCustomer(int id){
    bool flag = false;
    for (list<int>::iterator it = customersID.begin(); it != customersID.end(); ++it){
        if( (*it) == id && this->executed == false ){
			it = customersID.erase(it);
			cout << "    Customer deleted from list" << endl;
			flag = true;
			return true;
		}
		if( (*it) == id && this->executed == true ){
			cout << "    Cannot delete customer from list. Route execution has been completed" << endl;
			flag = true;
			return false;
		}
    }
    if ( flag == false ) { 
    	cout << "    Cannot delete customer from list. Customer not found" << endl;
    	return false;
    }
    cout << "    Ticket not found" << endl;
    return false;
}

bool ExecutionRoute::available(){
	int count = 0;
	for (list<int>::iterator it = customersID.begin(); it != customersID.end(); ++it){
    	count++;
	}
    if( count < this->maxPersons){
        return true;
    }
    else
    	return false;
}

void ExecutionRoute::setDate(string s){
	this->exDate = Date(s);
}

string ExecutionRoute::getDate(){
	string s = this->exDate.getDate();
	return s;
}

int ExecutionRoute::getID(){
    return this->id;
}

void ExecutionRoute::setMaxPersons(unsigned int mp){
    this->maxPersons = mp;
}
unsigned int ExecutionRoute::getMaxPersons(){
    return this->maxPersons;
}

void ExecutionRoute::setPilotID(int i, int ID)
{
    this->pilotsID[i] = ID; 
}

void ExecutionRoute::setFlightAttendantID(int i, int ID)
{
    this->flightAttendantsID[i] = ID;
}

void ExecutionRoute::setRouteID(int ID)
{
    this->routeID = ID;
}

void ExecutionRoute::setID(int i){
	this->id = i;
}

void ExecutionRoute::setNumberOfER(int n)
{
    this->numberOfER = n;
}

void ExecutionRoute::setExecuted(bool b){
	this->executed = b;
}

int ExecutionRoute::getFlightAttendantID(int i)
{
    return this->flightAttendantsID[i];
}

int ExecutionRoute::getPilotID(int i)
{
    return this->pilotsID[i];
}

int ExecutionRoute::getRouteID()
{
    return this->routeID;
}

int ExecutionRoute::getNumberOfER(){
	return this->numberOfER;
}

bool ExecutionRoute::getExecuted(){
	return this->executed;
}

// class destructor
ExecutionRoute::~ExecutionRoute(){}

