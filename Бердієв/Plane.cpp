#include <iostream>
#include <string>
#include "Plane.h"
#include "AirCompany.h"

using namespace std;

// Реєстрація літака у флот компанії.
void Plane::setPlane(string fleetType, int planeNumber) {

	fleet = fleetType; // Назава флоту приписки літака.

	number = planeNumber;
	id = fleet.substr(0, 4) + "-" + toString(number); // Формування ідентифікатора літака.

	cout << "Plane model: "; // Модель.
	cin >> model;

	cout << "Plane capacity, (m3): "; // Місткість.
	string capacity_cin;
	cin >> capacity_cin;
	capacity = stoi(capacity_cin);

	cout << "Plane carryingCapacity, (kg): "; // Вантажопідйомність.
	string carryingCapacity_cin;
	cin >> carryingCapacity_cin;
	carryingCapacity = stoi(carryingCapacity_cin);

	cout << "Plane flightRange, (km): "; // Дальність польоту.
	string flightRange_cin;
	cin >> flightRange_cin;
	flightRange = stoi(flightRange_cin);

	cout << "Plane fuelConsumption, (kg): "; // Витрати пального.
	string fuelConsumption_cin;
	cin >> fuelConsumption_cin;
	fuelConsumption = stoi(fuelConsumption_cin);

}

void Plane::setPlaneFromFile(string fleet_f, string id_f, string model_f, int capacity_f,
	int carryingCapacity_f, int flightRange_f, int fuelConsumption_f) {

	fleet = fleet_f; // Флот приписки літака.
	id = id_f; // Ідентифікатор літака.
	model = model_f; // Модель літака.
	capacity = capacity_f; // Місткість, м.куб.
	carryingCapacity = carryingCapacity_f; // Вантажопідйомність, кг.
	flightRange = flightRange_f; // Дальність польоту, км.
	fuelConsumption = fuelConsumption_f; // Витрати пального, кг.
	number = 0;
}
