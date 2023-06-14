#pragma once
#include <string>
#include <iostream>
class Ocean {
private:
	std::string name;
	double depth;
	double area;
protected:
	std::string loc;
public:
	Ocean();
	Ocean(std::string Name, double Depth, double Area, std::string Loc);
	std::string get_name();
	double get_depth();
	double get_area();
	std::string get_loc();
	friend std::ostream &operator << (std::ostream &stream, Ocean ocean);
	friend std::istream &operator >> (std::istream& stream, Ocean &ocean);
};