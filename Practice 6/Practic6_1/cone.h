#include <iostream>
#include <cmath>
const double pi = 3.14;
class Cone {
private:
	double x, y, z, rad, heig;
public:
	Cone();
	Cone(double rad, double heig);
	Cone(double x, double y, double z, double rad, double heig);
	void set_cone_cord(double x1, double y1, double z1);
	void set_cone_rad(double r);
	void set_cone_heig(double h);
	double get_cone_rad();
	double get_cone_heig();
	double area_cone();
	double volume_cone();
	friend std::ostream& operator << (std::ostream& stream, Cone cone);
};
std::ostream& operator << (std::ostream& stream, Cone cone);