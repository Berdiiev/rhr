#include <iostream>
#include <string>
#include <algorithm>
#include <conio.h>
#include "Plane.h"
#include "Passenger.h"
#include "Transport.h"
#include "Mail.h"
#include "Agricultural.h"
#include "AirCompany.h"
#include "Log.h"

using namespace std;

int main()
{
	while (true) {

		// Головне меню.

		int operationCode{};

		cout << endl << endl;
		cout << "\t1. Show all Air fleet." << endl;
		cout << "\t2. Add plane to fleet." << endl;
		cout << "\t3. Total capacity and carrying capacity calculation." << endl;
		cout << "\t4. Flight range sorting." << endl;
		cout << "\t5. Fuel consumption searching." << endl;
		cout << "\t6. Quit." << endl << endl;
		cout << "\tEnter the operation code: ";
		cin >> operationCode;

		switch (operationCode) {

		case 1: { // Показати весь наявний флот авіакомпанії.
			AirCompany airManager;
			airManager.show(airManager);
		} break;

		case 2: { // Додати літак у флот авіакомпанії.
			int fleetCategory{};

			cout << endl << "Add plane to the company fleet:" << endl;
			cout << "\t1. Passenger fleet." << endl;
			cout << "\t2. Transport fleet." << endl;
			cout << "\t3. Mail fleet." << endl;
			cout << "\t4. Agricultural fleet." << endl << endl;
			cout << "\tEnter fleet categjry to add plane: ";
			cin >> fleetCategory;

			switch (fleetCategory) {

			case 1: { // Пасажирські літаки.
				cout << endl << endl << "Passenger fleet is selected" << endl;
				Passenger newPassPlane;
				AirCompany companyPassFleet(newPassPlane);
				Log log_1("Passenger plane's added");
			} break;

			case 2: { // Транспортні літаки.
				cout << endl << endl << "Transport fleet is selected" << endl;
				Transport newTransPlane;
				AirCompany companyTransFleet(newTransPlane);
				Log log_1("Transport plane's added");
			} break;

			case 3: { // Поштові літаки.
				cout << endl << endl << "Mail fleet is selected" << endl;
				Mail newMailPlane;
				AirCompany companyMailFleet(newMailPlane);
				Log log_1("Mail plane's added");
			} break;

			case 4: { // Літаки сільськогосподарського призначення.
				cout << endl << endl << "Agricultural fleet is selected" << endl;
				Agricultural newAgricPlane;
				AirCompany companyAgricFleet(newAgricPlane);
				Log log_1("Agricultural plane's added");
			} break;
			}
		} break;

		case 3: { // Розрахунко загальної місткості та вантажопідйомності флоту.

			AirCompany airCompanyManager_1;
			airCompanyManager_1.totalFleetCarryingCapacityCalculation();
		} break;

		case 4: { // Сортування літаків за дальністю польту.
			AirCompany airCompanyManager_2;
			airCompanyManager_2.flightRangeSort();

		} break;

		case 5: { // Пошук літака у заданих межах витрати палива.
			AirCompany airCompanyManager_3;
			airCompanyManager_3.fuelConsumptionSearch();

		} break;

		case 6: { // Вихід з програми.
			quit();
		}
		}
	}
	return 0;
}

