#include "ticket.h" // class's header file

int Ticket::numberOfT;

Ticket::Ticket() {
	this->ticketID = ++numberOfT;
}

Ticket::Ticket(int cid, int exid) : ticketID(++numberOfT), customerID(cid), executionID(exid) {}

Ticket::Ticket(string str){
	istringstream issin(str);
	list<string> elements;
	string el;
	int i = 0;

	while (getline(issin, el, '|')) {
		elements.push_back(el);
		i++;
	}
	this->ticketID = stoi(elements.front()); elements.pop_front();
	this->customerID = stoi(elements.front()); elements.pop_front();
	this->executionID = stoi(elements.front()); elements.pop_front();
}

void Ticket::Display(){
	string str = "    " + to_string(this->ticketID) + " | " + to_string(this->customerID) + " | " + to_string(this->executionID) + "\n";
	cout << str;
}

string Ticket::toString(){
	string str;
	str = to_string(this->ticketID) + "|" + to_string(this->customerID) + "|" + to_string(this->executionID) + "\n";
	return str;
}

void Ticket::setTicketID(int tid)
{
     this->ticketID = tid;
}

void Ticket::setCustomerID(int cid)
{
     this->customerID = cid;
}
void Ticket::setNumberOfT(int n){
	this->numberOfT = n;
}

int Ticket::getTicketID()
{
    return this->ticketID;
}

int Ticket::getCustomerID()
{
    return this->customerID;
}
void Ticket::setExecutionID(int eid){
     this->executionID = eid;
}
int Ticket::getExecutionID(){
    return this->executionID;
}
int Ticket::getNumberOfT(){
    return this->numberOfT;
}

Ticket::~Ticket()
{
	// insert your code here
}
