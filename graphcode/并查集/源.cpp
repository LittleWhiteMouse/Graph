#include<iostream>
#include "DisjointSet.h"
using namespace std;
int main(int argc,char ** argv) {
	DisjointSet obj(5);
	obj.merge(0, 2);
	obj.merge(4, 2);
	obj.merge(3, 1);

	if (obj.find(4) == obj.find(0))
		cout << "4 0 in the same set" << endl;
	else
		cout << "4 0 in the different sets" << endl;
	
	if (obj.find(1) == obj.find(0))
		cout << "1 0 in the same set" << endl;
	else
		cout << "1 0 in the different sets" << endl;



}