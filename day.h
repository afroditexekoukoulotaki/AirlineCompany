#ifndef DAY_H
#define DAY_H
#include <iostream>
#include <string>
using namespace std;

class Day
{
    private:
		int day;
		static string days[]; // one array for all objects
              
	public:
		// class constructor
		Day();
		Day(int day);
		string getDay();
		int getDayInt();
		void setDay(int);
		// class destructor
		~Day();
};

#endif // DAY_H
