#include <iostream>
#include <string>
#include "Plane.h"
#include "AirCompany.h"

using namespace std;

// ��������� ����� � ���� ������.
void Plane::setPlane(string fleetType, int planeNumber) {

	fleet = fleetType; // ������ ����� �������� �����.

	number = planeNumber;
	id = fleet.substr(0, 4) + "-" + toString(number); // ���������� �������������� �����.

	cout << "Plane model: "; // ������.
	cin >> model;

	cout << "Plane capacity, (m3): "; // ̳������.
	string capacity_cin;
	cin >> capacity_cin;
	capacity = stoi(capacity_cin);

	cout << "Plane carryingCapacity, (kg): "; // ����������������.
	string carryingCapacity_cin;
	cin >> carryingCapacity_cin;
	carryingCapacity = stoi(carryingCapacity_cin);

	cout << "Plane flightRange, (km): "; // �������� �������.
	string flightRange_cin;
	cin >> flightRange_cin;
	flightRange = stoi(flightRange_cin);

	cout << "Plane fuelConsumption, (kg): "; // ������� ��������.
	string fuelConsumption_cin;
	cin >> fuelConsumption_cin;
	fuelConsumption = stoi(fuelConsumption_cin);

}

void Plane::setPlaneFromFile(string fleet_f, string id_f, string model_f, int capacity_f,
	int carryingCapacity_f, int flightRange_f, int fuelConsumption_f) {

	fleet = fleet_f; // ���� �������� �����.
	id = id_f; // ������������� �����.
	model = model_f; // ������ �����.
	capacity = capacity_f; // ̳������, �.���.
	carryingCapacity = carryingCapacity_f; // ����������������, ��.
	flightRange = flightRange_f; // �������� �������, ��.
	fuelConsumption = fuelConsumption_f; // ������� ��������, ��.
	number = 0;
}
