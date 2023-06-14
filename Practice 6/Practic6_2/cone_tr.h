#pragma once
#include "cone.h"
class Cone_tr: public Cone{
protected:
	double rad_2;
public: 
	Cone_tr();
	Cone_tr(double r, double h, double r_2);
	Cone_tr(double x1, double y1, double z1, double r, double h, double r_2);
	Cone_tr(Cone& cone, double r_2);
	void set_cone_rad2(double r_2);
	double get_cone_rad_2();
	double area_cone();
	double volume_cone();
	bool operator < (Cone_tr& cone);
	bool operator > (Cone_tr& cone);
	bool operator == (Cone_tr& cone);
	friend std::ostream& operator << (std::ostream& stream, Cone_tr cone);
};