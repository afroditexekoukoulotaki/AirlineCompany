#ifndef ADMINISTRATIVE_H
#define ADMINISTRATIVE_H
#include <string>
#include <iostream>
#include <sstream>
#include <list>
#include "employee.h"

using namespace std;

class Administrative : public Employee {
    private:
		string knowledgeLevel;
		unsigned int yearsExperience;
	public:
		
		Administrative();
		Administrative(string fn, string ln, string ads, string nb, string kl, unsigned int ye);
		Administrative(string);
		
		// class destructor
		~Administrative();
		void setKnowledgeLevel(string);
		string getKnowledgeLevel();
		void setYearsExperience(unsigned int);
		unsigned int getYearsExperience();
		void Display();
        virtual string toString();
};

#endif // ADMINISTRATIVE_H
