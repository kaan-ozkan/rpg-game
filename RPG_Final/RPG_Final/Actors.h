#pragma once

#include<string.h>
#include<iostream>

class Actor {
protected:
	char* name;
public:
	bool between(int x, int a, int b) {
		if (x <= b && x >= a)
			return 1;
		return 0;
	}
	Actor() {
		name = new char[100];
	}
	Actor(const char* actname) {
		name = new char[100];
		strcpy(name, actname);
	}
	Actor(const Actor &A) {
		name = new char[100];

		strcpy(name, A.name);
	}
	Actor& operator = (const Actor& A) {
		strcpy(name, A.name);

		return *this;
	}
	void setname(const char* actname) {
		strcpy(name, actname);
	}
	char* getname() {
		return name;
	}
	~Actor() {
		delete[] name;
	}
	virtual void Display()const = 0;
};

