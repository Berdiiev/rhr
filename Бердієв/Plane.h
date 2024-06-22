#pragma once
#include <string>

using namespace std;

class Plane // ���� ���������� ����� ��� ��������� �� ����� ������.
{
private:
	string fleet = "";			// 1 ����������� (������������, ������������, ��������, ��������������������).
	string id = "";				// 2 ������������� �����.
	string model = "";			// 3 ������.
	int capacity{};				// 4 ̳������.
	int carryingCapacity{};		// 5 ����������������.
	int flightRange{};			// 6 �������� �������.
	int fuelConsumption{};		// 7 ���������� ��������.

	int number{};				//   ����� ����� (�� ������������, ������������ ��� ��������� id.).

public:

	Plane() {}
	~Plane() {}

	void setPlane(string, int); // ����� ��� ��������� ������ ����� �� ����� ������.
	void setPlaneFromFile(string, string, string, int, int, int, int); // ������ ��� ���������� ����� � ����� �� ����������� ������ �����.

	// ������.
	int getPlaneNumber() { return number; }		// �����.
	string getPlaneId() { return id; }			// �������������. 
	string getPlaneModel() { return model; }	// ������.
	string getPlaneFleet() { return fleet; }	// ���� ��������.
	int getPlaneCapacity() { return capacity; }	// ̳������.
	int getPlaneFlightRange() { return flightRange; }	// �������� �������.
	int getPlaneCarryingCapacity() { return carryingCapacity; }	// ����������������.
	int getPlaneFuelConsumption() { return fuelConsumption; }	// ������� �������� (�� ����).
};
