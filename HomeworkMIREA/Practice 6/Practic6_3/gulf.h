#pragma once
#include "ocean.h"
#include "sea.h"
class Gulf : public Sea, public Ocean {
private:
	std::string name;
	double depth;
	double area;
	Ocean *OCEAN;
	Sea* SEA;
protected:
	std::string loc;
public:
	Gulf();
	Gulf(std::string Name, double Depth, double Area, std::string Loc);
	Gulf(Ocean &ocean, std::string Name, double Depth, double Area);
	Gulf(Sea& sea, std::string Name, double Depth, double Area);
	std::string get_name();
	double get_depth();
	double get_area();
	std::string get_loc();
	friend std::ostream& operator << (std::ostream& stream, Gulf gulf);
	friend std::istream& operator >> (std::istream& stream, Gulf& gulf);
};