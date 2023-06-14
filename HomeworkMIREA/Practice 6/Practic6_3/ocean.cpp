#include "ocean.h"
Ocean::Ocean() {
	name = "none";
	depth = 0;
	area = 0;
	loc = "none";
}
Ocean::Ocean(std::string Name, double Depth, double Area, std::string Loc) {
	name = Name;
	depth = Depth;
	area = Area;
	loc = Loc;
}
std::string Ocean::get_name() {
	return name;
}
double Ocean::get_depth() {
	return depth;
}
double Ocean::get_area() {
	return area;
}
std::string Ocean::get_loc() {
	return loc;
}
std::ostream& operator << (std::ostream& stream, Ocean ocean) {
	stream << ocean.area << " " << ocean.depth << " " << ocean.name << " " << ocean.loc << std::endl;
	return stream;
}
std::istream& operator >> (std::istream& stream, Ocean& ocean) {
	stream >> ocean.name >> ocean.depth >> ocean.area >> ocean.loc;
	return stream;
}