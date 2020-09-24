#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <sstream>
#include <iterator>
#include <ctime>
#include "date.h"
#include "executionroute.h"
#include "pilot.h"
#include "company.h"
#include "customer.h"
using namespace std;


int main()
{
	Company Comp;
    Comp.load();
	Comp.myInterface();
	Comp.save();
	
	cout << endl;
    system("pause");
    return 0;
}
