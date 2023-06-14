#include "cone_tr.h"
const double pi = 3.14;
Cone_tr::Cone_tr() {
	x = y = z = rad = rad_2 = heig = 0;
}
Cone_tr::Cone_tr(double r, double h, double r_2) {
	x = y = z = 0;
	rad = r;
	heig = h;
	rad_2 = r_2;
}
Cone_tr::Cone_tr(double x1, double y1, double z1, double r, double h, double r_2) {
	x = x1;
	y = y1;
	z = z1;
	rad = r;
	heig = h;
	rad_2 = r_2;
}
Cone_tr::Cone_tr(Cone& cone, double r_2):Cone(cone) {
	rad_2 = r_2;
}
void Cone_tr::set_cone_rad2(double r_2) {
	rad_2 = r_2;
}
double Cone_tr::get_cone_rad_2() {
	return rad_2;
}
double Cone_tr::area_cone() {
	double M = sqrt(pow(rad - rad_2, 2) + heig * heig);
	return pi * (rad * rad + (rad + rad_2) * M + rad_2 * rad_2);
}
double Cone_tr::volume_cone() {
	double M = sqrt(pow(rad - rad_2, 2) + heig * heig);
	return (pi * heig * ((rad * rad) + (rad * rad_2) + (rad_2 * rad_2))) / 3;
}
std::ostream& operator << (std::ostream& stream, Cone_tr cone) {
	stream << "coard:" << cone.x << "," << cone.y << "," << cone.z << "," << " height: " << cone.heig << " radius: " << cone.rad << " radius_2: " << cone.rad_2;
	return stream;
}
bool Cone_tr::operator < (Cone_tr& cone) {
	return volume_cone() < cone.volume_cone();
}
bool Cone_tr::operator > (Cone_tr& cone) {
	return volume_cone() > cone.volume_cone();
}
bool Cone_tr::operator == (Cone_tr& cone) {
	return volume_cone() == cone.volume_cone();
}