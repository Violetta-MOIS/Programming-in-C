#include "gulf.h"
Gulf::Gulf() {
	name = "none";
	depth = 0;
	area = 0;
	loc = "none";
}
Gulf::Gulf(std::string Name, double Depth, double Area, std::string Loc) {
	name = Name;
	depth = Depth;
	area = Area;
	loc = Loc;
}
Gulf::Gulf(Ocean& ocean, std::string Name, double Depth, double Area) {
	name = Name;
	depth = Depth;
	area = Area;
	OCEAN = &ocean;
	loc = Ocean::loc;
}
Gulf::Gulf(Sea& sea, std::string Name, double Depth, double Area) {
	name = Name;
	depth = Depth;
	area = Area;
	SEA = &sea;
	loc = Sea::loc;
}
std::string Gulf::get_name() {
	return name;
}
double Gulf::get_depth() {
	return depth;
}
double Gulf::get_area() {
	return area;
}
std::string Gulf::get_loc() {
	return loc;
}
std::ostream& operator << (std::ostream& stream, Gulf gulf) {
	stream << gulf.area << " " << gulf.depth << " " << gulf.name << " " << gulf.loc << std::endl;
	return stream;
}
std::istream& operator >> (std::istream& stream, Gulf &gulf) {
	stream >> gulf.name >> gulf.depth >> gulf.area >> gulf.loc;
	return stream;
}