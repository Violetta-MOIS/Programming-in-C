#pragma once
#include <iostream>

class Class {
private:
	int a;
	float b;
public:
	Class(int A, float B);
	void Out();
	Class operator=(Class& T);
};