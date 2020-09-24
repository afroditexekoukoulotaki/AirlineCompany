#include "route.h" // class's header file

// class constructor
Route::Route() {}

Route::Route(int id, string st, string dn, float pr, Time stime, Time dt, Day d):
routeID(id), start(st), destination(dn), price(pr), startTime(stime), destinationTime(dt), routeDay(d) {}

Route::Route(string strRoute){
        istringstream issin(strRoute);
		list<string> elements;
		string el;
		int i = 0;

		while (getline(issin, el, '|')) {
			elements.push_back(el);
			i++;
		}
		istringstream buffer;
		
		buffer.str(elements.front()); // Returns a reference to the first element in the list container.
		buffer >> this->routeID; // string to integer
		elements.pop_front(); // Delete first element
		buffer.clear();
		this->start = elements.front(); // 2
		elements.pop_front();
		this->destination = elements.front(); // 3
		elements.pop_front();
		buffer.str(elements.front()); // 4
		buffer >> this->price;
		elements.pop_front();
		buffer.clear();
		this->startTime.setTime(elements.front()); // 03:45  5
		elements.pop_front();
		this->destinationTime.setTime(elements.front()); //6
		elements.pop_front();
		buffer.str(elements.front()); // string to int  6
		int x;
		buffer >>  x;
		routeDay.setDay(x);
		buffer.clear();
		
}

void Route::Display(){
	string str;
	str = "    " + to_string(this->routeID) + " | " + this->start + " | " + this->destination + " | " + to_string(this->price) + " | " + 
		this->startTime.getTime() + " | " + this->destinationTime.getTime() + " | " + this->routeDay.getDay() + "\n";
	cout << str;
}

string Route::toString(){
	string pr = to_string(this->price);
	pr.erase(pr.find_last_not_of('0')+1, string::npos);
	string str = to_string(this->routeID) + "|" + this->start + "|" + this->destination + "|" + pr + "|" + 
				this->startTime.getTime() + "|" + this->destinationTime.getTime() + "|" + to_string(this->routeDay.getDayInt()) + "\n";
	return str;
}


void Route::setRouteID(int id) { routeID = id; }

int Route::getRouteID() {return routeID; }

void Route::setStart(string st) { start = st; }

string Route::getStart() { return start; }

void Route::setDestination(string dn) { destination = dn; }

string Route::getDestination() { return destination; }

void Route::setPrice(float p)
{
    this->price = p;
}
float Route::getPrice()
{
    return this->price;
}
void Route::setStartTime(Time st)
{
    this->startTime = st;
}
void Route::setDestinationTime(Time dt)
{
    this->destinationTime = dt;
}
Time Route::getStartTime() //
{
    return this->startTime; //.getTime();
}
Time Route::getDestinationTime()
{
    return this->destinationTime;
}
void Route::setRouteDay(Day d)
{
    this->routeDay = d;
}
Day Route::getRouteDay()
{
    return this->routeDay;
}
// class destructor
Route::~Route() {}
