#include "String.h"


String::String() : length(0), str(nullptr) {}

String::String(int count, char symb) : length(count) {
	str = new char[length + 1]{};
	for (int i = 0; i < length; i++)
		str[i] = symb;
}
String::String(const char* str){
	length = strlen(str);
	this->str = new char[length + 1];
	strcpy_s(this->str, length + 1, str);
}

String::String(const String& other){
	length = other.length;
	str = nullptr;
	if (other.str != nullptr) {
		str = new char[length + 1];
		strcpy_s(str, length + 1, other.str);
	}
}

String::~String(){
	delete[] str;
}

void String::Print() const{
	if (str != nullptr)
		cout << str << endl;
}

String String::operator+(const String& st2) const{
	String res(*this);
	res += st2;
	return res;	
}


void String::operator+=(const char& symbol){
	++length;
	char* newStr = new char[length + 1]{};
	if (str!= nullptr)
	strcpy_s(newStr, length, str);
	newStr[length - 1] = symbol;
	delete[]str;
	str = newStr;
}

void String::operator+=(const char* str){
	length = length + strlen(str);
	char* newStr = new char[length + 1]{};

	if (this->str != nullptr)
		strcpy_s(newStr, length + 1, this->str);

	strcat_s(newStr, length + 1, str);

	delete[]this->str;
	this->str = newStr;
}

void String::operator+=(const String& str){
	if (str.str == nullptr)
		return;

	length = length + str.length;
	char* newStr = new char[length + 1]{};
	if (this->str != nullptr)
		strcpy_s(newStr, length + 1, this->str);

		strcat_s(newStr, length + 1, str.str);

	delete[]this->str;
	this->str = newStr;

}

String& String::operator=(const String& other){
	if (this == &other)
		return *this;

	delete[]str;
	length = other.length;
	str = nullptr;
	if (other.str != nullptr) {
		str = new char[length + 1];
		strcpy_s(str, length + 1, other.str);
	}
	return *this;
}

String String::operator*(const String& str)const{
	String res;
	bool repeat = false;
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < str.length; j++) {
			if (this->str[i] == str.str[j]) {
				for (int k = 0; k < res.length; k++) {
					if (res.str[k] == this->str[i]) {
					repeat = true;
					break;
					}
				}
				if (repeat == false) 
					res += this->str[i];
				else
					repeat = false;
				break;
			}
		}
	}
	return res;
}

bool String::operator>(const String& str)const{
	return  (strcmp(this->str, str.str) > 0);
}

bool String::operator<(const String& str)const{
	return (strcmp(this->str, str.str) < 0);
}

bool String::operator==(const String& str)const{
	return (strcmp(this->str, str.str) == 0);
}

bool String::operator!=(const String& str)const{
	return strcmp(this->str, str.str) != 0;
}
