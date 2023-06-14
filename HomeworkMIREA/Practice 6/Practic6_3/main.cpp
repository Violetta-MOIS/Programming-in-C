#include "ocean.h"
#include "sea.h"
#include "gulf.h"


int main()
{
	using namespace std;
	Ocean ocean1 = Ocean("Pacific", 4280, 165250000, "I dont care");
	cout << ocean1;

	Ocean ocean2 = Ocean();
	cout << "(NAME, DEPTH, AREA, LOCATION): ";
	cin >> ocean2;

	cout << ocean2;

	Sea sea1 = Sea(ocean2, "Laptev", 578, 700000);
	cout << sea1;

	cout << endl;
	Gulf bay1 = Gulf(ocean1, "Kamchatka", 2000, rand());
	cout << bay1;
	std::cout << "The name is " << bay1.get_name() << " and the depth is " << bay1.get_depth();
	Sea sea2 = Sea("Caspian", 211, 371000, "Eastern Europe");
	cout << sea2;
}