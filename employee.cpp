#include "employee.h"


int Employee::numberOfE;

// class constructor
Employee::Employee() {}
// class destructor
Employee::~Employee() {}

Employee::Employee(string fn, string ln, string ads, string nb):
             firstName(fn), lastName(ln), address(ads), number(nb) {}
             
void Employee::setNumberOfE(int n){
	this->numberOfE = n;
}

int Employee::getNumberOfE(){
	return this->numberOfE;
}
                         
void Employee::setFirstName(string fn){ firstName = fn; }

string Employee::getFirstName() { return firstName; }

void Employee::setLastName(string ln) { lastName = ln; }

string Employee::getLastName() { return lastName; }

void Employee::setAddress(string ads) { address = ads; }

string Employee::getAddress() { return address; }

void Employee::setNumber(string nb) { number = nb; }

string Employee::getNumber() { return number; }

void Employee::setID(int id) { ID = id; }

int Employee::getID() { return ID; }

void Employee::Display() { // to do----- ID????
//	string str;
	string str = "Name: " + this->firstName + " " + this->lastName + "\nAddress: " + this->address + "\nPhone number: " + 
	this->number + "\nID: ";
	cout << str;
}

string Employee::toString() {
	return "";
}

