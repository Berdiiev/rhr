#pragma once
#include <algorithm>
#include "Plane.h"
#include "Passenger.h"
#include "Transport.h"
#include "Mail.h"
#include "Agricultural.h"
#include "Log.h"

using namespace std;

class AirCompany // Клас авіакомпанії
{
private:
	Passenger* companyPassFleet = new Passenger[0];			// Масив пасажирського флоту.
	Transport* companyTransFleet = new Transport[0];		// Масив транспортного флоту.
	Mail* companyMailFleet = new Mail[0];					// Масив поштового флоту.
	Agricultural* companyAgricFleet = new Agricultural[0];	// Масив сільськогосподарського флоту.

	int passFleetCounter{};		// Лічильник пасажирського флоту.
	int transFleetCounter{};	// Лічильник транспортного флоту.
	int mailFleetCounter{};		// Лічильник поштового флоту.
	int agricFleetCounter{};	// Лічильник сільськогосподарського флоту.

public:
	// Конструктори.
	AirCompany();
	explicit AirCompany(Passenger&);
	explicit AirCompany(Transport&);
	explicit AirCompany(Mail&);
	explicit AirCompany(Agricultural&);

	// Деструктор
	~AirCompany();

	// Сеттери флотів.
	void setCompanyPassFleet(Passenger* ptr) { companyPassFleet = ptr; }
	void setCompanyTransFleet(Transport* ptr) { companyTransFleet = ptr; }
	void setCompanyMailFleet(Mail* ptr) { companyMailFleet = ptr; }
	void setCompanyAgricFleet(Agricultural* ptr) { companyAgricFleet = ptr; }

	// Геттери флотів.
	Passenger* getCompanyPassFleet() { return companyPassFleet; }
	Transport* getCompanyTransFleet() { return companyTransFleet; }
	Mail* getCompanyMailFleet() { return companyMailFleet; }
	Agricultural* getCompanyAgricFleet() { return companyAgricFleet; }

	// Сеттери лічильників флотів.
	void setPassFleetCounter(int value) { passFleetCounter = value; };
	void setTransFleetCounter(int value) { transFleetCounter = value; };
	void setMailFleetCounter(int value) { mailFleetCounter = value; };
	void setAgricFleetCounter(int value) { agricFleetCounter = value; };

	// Геттери лічильників флотів.
	int getPassFleetCounter() { return passFleetCounter; }
	int getTransFleetCounter() { return transFleetCounter; }
	int getMailFleetCounter() { return mailFleetCounter; }
	int getAgricFleetCounter() { return  agricFleetCounter; }

	void flightRangeSort(); // Сортування літаків по дальності польоту.

	// Розрахунок загальних місткості та вантажопідйомності усіх літаків компанії.
	void totalFleetCarryingCapacityCalculation();

	void fuelConsumptionSearch(); // Пошук літака за діапазоном витрат пального.

	// Шифрування, дешифрування.
	string encrypt(const string&);
	string decrypt(const string&);

	// Запис, зчитування файлів.
	void writeFile(int);
	void readFile();

	void show(AirCompany&); // Відображення ієрархії та наявності літаків компанії.
};

ostream& operator <<(ostream&, AirCompany&); // Перевантаження оператора виведення.

// Функція перетворення у рядок.
string toString(int);
string toString(char*);

// Вихід з програми.
void quit();

