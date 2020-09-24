#ifndef DATE_H
#define DATE_H
#include <string>
//#include <stdlib.h>
#include <iostream>
using namespace std;

class Date
{
      private:
              unsigned int day;
              unsigned int month;
              unsigned int year;
	  public:
    		
    		Date();
    		Date(unsigned int, unsigned int, unsigned int);
    		Date(string);
    		
    		void setDate(string);
    		string getDate();
    		
    		void setDay(unsigned int);
    		void setMonth(unsigned int);
    		void setYear(unsigned int);
    		unsigned int getDay();
    		unsigned int getMonth();
    		unsigned int getYear();
    		
    		// class destructor
    		~Date();
};

#endif // DATE_H
