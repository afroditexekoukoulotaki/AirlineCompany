#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H
#include <string>
#include <list>
#include <sstream>
#include "User.h"
using namespace std;

class Administrator : public User
{
	public:
		Administrator();
		Administrator(string);
		string toString();
		void setNumberOfA(int);
		int getNumberOfA();
	protected:
	private:
	//	int ID;
//		static int numberOfA;
};

#endif
