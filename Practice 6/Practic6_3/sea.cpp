#include "sea.h"
Sea::Sea() {
	name = "none";
	depth = 0;
	area = 0;
	loc = "none";
}
Sea::Sea(std::string Name, double Depth, double Area, std::string Loc) {
	name = Name;
	depth = Depth;
	area = Area;
	loc = Loc;
}
Sea::Sea(Ocean& ocean, std::string Name, double Depth, double Area) :Ocean(ocean) {
	name = Name;
	depth = Depth;
	area = Area;
	OCEAN = &ocean;
	loc = Ocean::loc;
}
std::ostream& operator << (std::ostream& stream, Sea sea) {
	stream << sea.area << " " << sea.depth << " " << sea.name << " " << sea.loc << std::endl;
	return stream;
}
std::istream& operator >> (std::istream& stream, Sea& sea) {
	stream >> sea.name >> sea.depth >> sea.area >> sea.loc;
	return stream;
}