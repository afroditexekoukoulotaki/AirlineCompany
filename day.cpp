#include "day.h" // class's header file


Day::Day(): day(0){}

Day::Day(int day): day(day){
	
    if (day<1 || day>7) {
        cout << "    Enter valid Day (1-7): ";
        cin >> this->day;
        Day(this->day);
    }
}

string Day::days[] = {"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};

string Day::getDay(){
    return days[this->day - 1]; // works without scope
}

int Day::getDayInt(){
	return this->day;
}

void Day::setDay(int d){
	this->day = d;
}

// class destructor
Day::~Day(){}
