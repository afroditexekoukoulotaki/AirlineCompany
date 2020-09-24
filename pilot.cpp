#include "pilot.h"



Pilot::Pilot() {
	this->ID = ++numberOfE;
}

Pilot::Pilot(string fn, string ln, string ads, string nb, unsigned int fh):
        Employee(fn, ln, ads, nb), flightHours(fh) {
		this->ID = ++numberOfE;
		}
              
Pilot::Pilot(string str){
	istringstream issin(str);
	list<string> elements;
	string el;
	int i = 0;

	while (getline(issin, el, '|')) {
		elements.push_back(el);
		i++;
	}
	this->firstName = elements.front();
	elements.pop_front(); // Delete first element
	this->lastName = elements.front();
	elements.pop_front();
	this->address = elements.front();
	elements.pop_front();
	this->number = elements.front();
	elements.pop_front();
	this->ID = stoi(elements.front());
	elements.pop_front();
	this->flightHours = stoi(elements.front());
	elements.pop_front();
}

string Pilot::toString(){
	string str = "0\n" + this->firstName + "|" + this->lastName + "|" + this->address + "|" + this->number + "|" + to_string(this->ID) + 
					"|" + to_string(this->flightHours) + "\n";
	return str;
}

void Pilot::setFlightHours(unsigned int fh) { flightHours = fh; }

unsigned int Pilot::getFlightHours() { return flightHours; }

void Pilot::Display() // to check
{
    cout << "Pilot:\n " << endl;
	Employee::Display();
     
}
// class destructor
Pilot::~Pilot() {}
