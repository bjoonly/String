#include<iostream>
using namespace std;

class String {
	char* str;
	int length;

public:
	String();
	String(int count, char symb);
	String(const char* str);

	String(const String& other);

	~String();

	void Print() const;

	String operator+(const String& st2)const;
	void operator+=(const char& symbol);
	void operator+=(const char* str);
	void operator+=(const String& str);
	String& operator=(const String& other);
	String operator*(const String& str)const;
	bool operator>(const String& str)const;
	bool operator<(const String& str)const;
	bool operator==(const String& str)const;
	bool operator!=(const String& str)const;
};