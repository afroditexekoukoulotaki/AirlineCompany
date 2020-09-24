#include "flightattendant.h" // class's header file

// class constructor
FlightAttendant::FlightAttendant() {
	this->ID = ++numberOfE;
}

FlightAttendant::FlightAttendant(string fn, string ln, string ads, string nb, unsigned int ye)
            	:Employee(fn, ln, ads, nb), yearsExperience(ye) {}
              
FlightAttendant::FlightAttendant(string str){
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
	this->yearsExperience = stoi(elements.front());
	elements.pop_front();
}

string FlightAttendant::toString(){
	string str = "1\n" + this->firstName + "|" + this->lastName + "|" + this->address + "|" + this->number + "|" + to_string(this->ID) + 
					"|" + to_string(this->yearsExperience) + "\n";
	return str;
}
              
void FlightAttendant::setYearsExperience(unsigned int ye) { yearsExperience = ye; }

unsigned int FlightAttendant::getYearsExperience() { return yearsExperience; }

// class destructor
FlightAttendant::~FlightAttendant() {}

void FlightAttendant::Display() {
	Employee::Display();
	cout << "FlightAttendant:" << endl;
}

