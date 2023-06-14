#include "cone.h"
int main() {
	Cone cone_1 = Cone();
	cone_1.set_cone_cord(5.5, 6, 7.3);
	cone_1.set_cone_heig(10);
	cone_1.set_cone_rad(3);

	Cone cone_2(5, 7.5);
	Cone cone_3(1, 1, 1, 5, 7.5);
	std::cout << cone_1 << std::endl;
	std::cout << cone_2 << std::endl;
	std::cout << cone_1.volume_cone()<< " " << cone_1.area_cone() << std::endl;
	std::cout << cone_2.volume_cone() << " " << cone_2.area_cone() << std::endl;
	return 0;
}