#include <iostream>
#include"String.h"
using namespace std;


int main() {
	String s1("Some text"), s2("Line of text"), s3(5, 'a'), s4;
	cout << "S1: ";
	s1.Print();
	cout << "S2: ";
	s2.Print();
	cout << "S1 + S2: ";
	s4 = s1 + s2;
	s4.Print();
	cout << "S1 * S2: ";
	s4 = s1 * s2;
	s4.Print();
	cout << "S1 > S2 ? " << boolalpha << (s1 > s2) << endl;
	cout << "S1 < S2 ? " << boolalpha << (s1 < s2) << endl;
	cout << "S1 == S2 ? " << boolalpha << (s1 == s2) << endl;
	cout << "S1 != S2 ? " << boolalpha << (s1 != s2) << endl;
	return 0;
}