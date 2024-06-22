#pragma once
#include <string>

using namespace std;

class Plane // Клас визначення літака для включення до флоту компанії.
{
private:
	string fleet = "";			// 1 Призначення (пасажирський, транспортний, поштовий, сільськогосподарський).
	string id = "";				// 2 Ідентифікатор літака.
	string model = "";			// 3 Модель.
	int capacity{};				// 4 Місткість.
	int carryingCapacity{};		// 5 Вантажопідйомність.
	int flightRange{};			// 6 Дальність польоту.
	int fuelConsumption{};		// 7 Споживання пального.

	int number{};				//   Номер літака (не відображається, застосований для генерації id.).

public:

	Plane() {}
	~Plane() {}

	void setPlane(string, int); // Сетер для додавання нового літака до флоту компанії.
	void setPlaneFromFile(string, string, string, int, int, int, int); // Сеттер для зчитування даних з файла та ініціалізації масивів флотів.

	// Гетери.
	int getPlaneNumber() { return number; }		// Номер.
	string getPlaneId() { return id; }			// Ідентифікатор. 
	string getPlaneModel() { return model; }	// Модель.
	string getPlaneFleet() { return fleet; }	// Флот приписки.
	int getPlaneCapacity() { return capacity; }	// Місткість.
	int getPlaneFlightRange() { return flightRange; }	// Дальність польоту.
	int getPlaneCarryingCapacity() { return carryingCapacity; }	// Вантажопідйомність.
	int getPlaneFuelConsumption() { return fuelConsumption; }	// Витарти пального (за рейс).
};
