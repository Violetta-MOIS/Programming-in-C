#include "cone.h"
const double pi = 3.14;
Cone::Cone() {
	x = y = z = rad = heig = 0;
}
Cone::Cone(double r, double h) {
	x = y = z = 0;
	rad = r;
	heig = h;
}
Cone::Cone(double x1, double y1, double z1, double r, double h) {
	x = x1;
	y = y1;
	z = z1;
	rad = r;
	heig = h;
}
void Cone::set_cone_cord(double x1, double y1, double z1) {
	x = x1;
	y = y1;
	z = z1;
}
void Cone::set_cone_rad(double r) {
	rad = r;
}
void Cone::set_cone_heig(double h) {
	heig = h;
}
double Cone::get_cone_rad() {
	return rad;
}
double Cone::get_cone_heig() {
	return rad;
}
double Cone::area_cone() {
	return (pi * (sqrt(heig * heig + rad * rad) + rad) * rad);
}
double Cone::volume_cone() {
	return rad * rad * pi * heig / 3;
}
std::ostream& operator << (std::ostream& stream, Cone cone) {
	stream << "coard:" << cone.x << "," << cone.y << "," << cone.z << "," << " height: " << cone.heig << " radius: " << cone.rad;
	return stream;
}