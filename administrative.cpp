#include "administrative.h"

Administrative::Administrative(){
	this->ID = ++numberOfE;
}

Administrative::Administrative(string fn, string ln, string ads, string nb, string kl, unsigned int ye)
              : Employee(fn, ln, ads, nb), knowledgeLevel(kl), yearsExperience(ye) {}

Administrative::Administrative(string str){
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
	this->knowledgeLevel = elements.front();
	elements.pop_front();
	this->yearsExperience = stoi(elements.front());
	elements.pop_front();
}

string Administrative::toString(){
	string str = "2\n" + this->firstName + "|" + this->lastName + "|" + this->address + "|" + this->number + "|" + to_string(this->ID) + 
					"|" + this->knowledgeLevel + "|" + to_string(this->yearsExperience) + "\n";
	return str;
}

// class destructor
Administrative::~Administrative(){}

void Administrative::setKnowledgeLevel(string kl) { knowledgeLevel = kl; }

string Administrative::getKnowledgeLevel() { return knowledgeLevel; }

void Administrative::setYearsExperience(unsigned int ye) { yearsExperience = ye; }

unsigned int Administrative::getYearsExperience() { return yearsExperience; }


void Administrative::Display() // to check
{
	Employee::Display();
     cout << "Administrative:\n: " << endl;
     
}

