#pragma once
#include "ocean.h"
class Sea: public Ocean {
private:
	std::string name;
	double depth;
	double area;
	Ocean *OCEAN;
public:
	Sea();
	Sea(std::string Name, double Depth, double Area, std::string Loc);
	Sea(Ocean& ocean, std::string Name, double Depth, double Area);
	friend std::ostream& operator << (std::ostream& stream, Sea sea);
	friend std::istream& operator >> (std::istream& stream, Sea& sea);
};