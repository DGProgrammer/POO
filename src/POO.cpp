// POO.cpp : Defines the entry point for the application.
//

#include <iostream>
#include "Vector.h"

using namespace std;



int main()
{
	Vector<int> v(9);
	
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}

	for (int i = 0; i < 10; i++) {
		cout << v[i] << endl;
	}
	
	//v.remove(&v[3]);
	v.remove(1);
	v.push_back(10);
	v.printVector();
	
	return 0;
}
