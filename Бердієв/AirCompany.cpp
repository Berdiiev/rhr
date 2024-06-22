#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include "Plane.h"
#include "Passenger.h"
#include "Transport.h"
#include "Mail.h"
#include "Agricultural.h"
#include "Log.h"
#include "AirCompany.h"

using namespace std;

AirCompany::AirCompany() {
	readFile(); // Зчитування файла, ініціалізація масивів флотів.
	Log log_1("All files are read"); // Логування події.
	Log log_2("Air companyi's initialized");
}

// Перевантаження конструктора для додавання нових літаків.
AirCompany::AirCompany(Passenger& newPassPlane) {
	readFile();
	Log log_1("File PassFleet.acmp is read");
	auto* tempFleet = new Passenger[++passFleetCounter];
	for (int i = 0; i < (passFleetCounter - 1); i++) tempFleet[i] = companyPassFleet[i];
	companyPassFleet = tempFleet;
	newPassPlane.setPlane("Passenger", passFleetCounter);
	tempFleet[passFleetCounter - 1] = newPassPlane;
	tempFleet = nullptr;
	writeFile(1);
	Log log_2("File PassFleet.acmp is saved");
}

AirCompany::AirCompany(Transport& newTransPlane) {
	readFile();
	Log log_1("File TransFleet.acmp is read");
	auto* tempFleet = new Transport[++transFleetCounter];
	for (int i = 0; i < (transFleetCounter - 1); i++) tempFleet[i] = companyTransFleet[i];
	companyTransFleet = tempFleet;
	newTransPlane.setPlane("Transport", transFleetCounter);
	tempFleet[transFleetCounter - 1] = newTransPlane;
	tempFleet = nullptr;
	writeFile(2);
	Log log_2("File TransFleet.acmp is saved");
}

AirCompany::AirCompany(Mail& newMailPlane) {
	readFile();
	Log log_1("File MailFleet.acmp is read");
	auto* tempFleet = new Mail[++mailFleetCounter];
	for (int i = 0; i < (mailFleetCounter - 1); i++) tempFleet[i] = companyMailFleet[i];
	companyMailFleet = tempFleet;
	newMailPlane.setPlane("Mail", mailFleetCounter);
	tempFleet[mailFleetCounter - 1] = newMailPlane;
	tempFleet = nullptr;
	writeFile(3);
	Log log_2("File MailFleet.acmp is saved");
}

AirCompany::AirCompany(Agricultural& newAgricPlane) {
	readFile();
	Log log_1("File AgricFleet.acmp is read");
	auto* tempFleet = new Agricultural[++agricFleetCounter];
	for (int i = 0; i < (agricFleetCounter - 1); i++) tempFleet[i] = companyAgricFleet[i];
	companyAgricFleet = tempFleet;
	newAgricPlane.setPlane("Agricultural", agricFleetCounter);
	tempFleet[agricFleetCounter - 1] = newAgricPlane;
	tempFleet = nullptr;
	writeFile(4);
	Log log_2("File AgricFleet.acmp is saved");
}

// Деструктор.
AirCompany::~AirCompany() {

	delete[]companyPassFleet;
	companyPassFleet = nullptr;

	delete[]companyTransFleet;
	companyTransFleet = nullptr;

	delete[]companyMailFleet;
	companyMailFleet = nullptr;

	delete[]companyAgricFleet;
	companyAgricFleet = nullptr;

}

// Шифрування.
string AirCompany::encrypt(const string& wrString)
{
	string encrypted = wrString;
	for (int i = 0; i < wrString.length(); i += 3)
		encrypted[i] += 18;
	reverse(encrypted.begin(), encrypted.end());
	return encrypted;
}

// Дешифрування.
string AirCompany::decrypt(const string& rdString)
{
	string decrypted = rdString;
	reverse(decrypted.begin(), decrypted.end());
	for (int i = 0; i < rdString.length(); i += 3)
		decrypted[i] -= 18;
	return decrypted;
}

// Запис даних до файлів флотів.
void AirCompany::writeFile(int fleetCode) {

	string wrString = "";
	string encryptedString = "";

	switch (fleetCode) {

	case 1: { // Пасажирський флот.

		ofstream wrFile("PassFleet.acmp", ios::out);
		if (wrFile.is_open()) {
			wrString = toString(getPassFleetCounter()) + ":";
			wrFile << encrypt(wrString) << endl;
			for (int i = 0; i < getPassFleetCounter(); i++) {
				wrString = "";
				wrString +=
					getCompanyPassFleet()[i].getPlaneFleet() + ","
					+ getCompanyPassFleet()[i].getPlaneId() + ","
					+ getCompanyPassFleet()[i].getPlaneModel() + ","
					+ toString(getCompanyPassFleet()[i].getPlaneCapacity()) + ","
					+ toString(getCompanyPassFleet()[i].getPlaneCarryingCapacity()) + ","
					+ toString(getCompanyPassFleet()[i].getPlaneFlightRange()) + ","
					+ toString(getCompanyPassFleet()[i].getPlaneFuelConsumption()) + ";";
				wrFile << encrypt(wrString) << endl;
			}
		}
		wrFile.close();
	} break;

	case 2: { // Транспортний флот.

		ofstream wrFile("TransFleet.acmp", ios::out);
		if (wrFile.is_open()) {
			wrString = toString(getTransFleetCounter()) + ":";
			wrFile << encrypt(wrString) << endl;
			for (int i = 0; i < getTransFleetCounter(); i++) {
				wrString = "";
				wrString +=
					getCompanyTransFleet()[i].getPlaneFleet() + ","
					+ getCompanyTransFleet()[i].getPlaneId() + ","
					+ getCompanyTransFleet()[i].getPlaneModel() + ","
					+ toString(getCompanyTransFleet()[i].getPlaneCapacity()) + ","
					+ toString(getCompanyTransFleet()[i].getPlaneCarryingCapacity()) + ","
					+ toString(getCompanyTransFleet()[i].getPlaneFlightRange()) + ","
					+ toString(getCompanyTransFleet()[i].getPlaneFuelConsumption()) + ";";
				wrFile << encrypt(wrString) << endl;
			}
		}
		wrFile.close();
	} break;

	case 3: { // Поштовий флот.

		ofstream wrFile("MailFleet.acmp", ios::out);
		if (wrFile.is_open()) {
			wrString = toString(getMailFleetCounter()) + ":";
			wrFile << encrypt(wrString) << endl;
			for (int i = 0; i < getMailFleetCounter(); i++) {
				wrString = "";
				wrString +=
					getCompanyMailFleet()[i].getPlaneFleet() + ","
					+ getCompanyMailFleet()[i].getPlaneId() + ","
					+ getCompanyMailFleet()[i].getPlaneModel() + ","
					+ toString(getCompanyMailFleet()[i].getPlaneCapacity()) + ","
					+ toString(getCompanyMailFleet()[i].getPlaneCarryingCapacity()) + ","
					+ toString(getCompanyMailFleet()[i].getPlaneFlightRange()) + ","
					+ toString(getCompanyMailFleet()[i].getPlaneFuelConsumption()) + ";";
				wrFile << encrypt(wrString) << endl;
			}
		}
		wrFile.close();
	} break;

	case 4: { // Сільськогосподарський флот.
		ofstream wrFile("AgricFleet.acmp", ios::out);
		if (wrFile.is_open()) {
			wrString = toString(getAgricFleetCounter()) + ":";
			wrFile << encrypt(wrString) << endl;
			for (int i = 0; i < getAgricFleetCounter(); i++) {
				wrString = "";
				wrString +=
					getCompanyAgricFleet()[i].getPlaneFleet() + ","
					+ getCompanyAgricFleet()[i].getPlaneId() + ","
					+ getCompanyAgricFleet()[i].getPlaneModel() + ","
					+ toString(getCompanyAgricFleet()[i].getPlaneCapacity()) + ","
					+ toString(getCompanyAgricFleet()[i].getPlaneCarryingCapacity()) + ","
					+ toString(getCompanyAgricFleet()[i].getPlaneFlightRange()) + ","
					+ toString(getCompanyAgricFleet()[i].getPlaneFuelConsumption()) + ";";
				wrFile << encrypt(wrString) << endl;
			}
		}
		wrFile.close();
	}
	}
}

// Зчитування файлів флотів.
void AirCompany::readFile() {

	string enString = "";
	string rdString = "";
	string dcString = "";
	int p{};

	// Пасажирський флот.
	ifstream rdFile_1("PassFleet.acmp", ios::in);

	if (rdFile_1.is_open()) {

		getline(rdFile_1, enString);
		rdString = decrypt(enString);

		do {
			if (rdString[p] != ':') dcString += rdString[p];
			p++;
		} while (rdString[p] != ':');
		p = 0;

		setPassFleetCounter(stoi(dcString));

		Passenger* tmpPassFleet = new Passenger[getPassFleetCounter()];
		setCompanyPassFleet(tmpPassFleet);
		tmpPassFleet = nullptr;

		for (int i = 0; i < getPassFleetCounter(); i++) {

			getline(rdFile_1, enString);
			rdString = decrypt(enString);

			// 1 Флот.
			string fleet_f = "";
			do {
				if (rdString[p] != ',') fleet_f += rdString[p];
				p++;
			} while (rdString[p] != ',');

			// 2 Ідентифікатор літака.
			string id_f = "";
			do {
				if (rdString[p] != ',') id_f += rdString[p];
				p++;
			} while (rdString[p] != ',');

			// 3 Модель літака.
			string model_f = "";
			do {
				if (rdString[p] != ',') model_f += rdString[p];
				p++;
			} while (rdString[p] != ',');

			// 4 Місткість.
			string capacity_f_str = "";
			do {
				if (rdString[p] != ',') capacity_f_str += rdString[p];
				p++;
			} while (rdString[p] != ',');

			// 5 Вантажопідйомність.
			string carryingCapacity_f_str = "";
			do {
				if (rdString[p] != ',') carryingCapacity_f_str += rdString[p];
				p++;
			} while (rdString[p] != ',');

			//6 Дальність польоту.
			string flightRange_f_str = "";
			do {
				if (rdString[p] != ',') flightRange_f_str += rdString[p];
				p++;
			} while (rdString[p] != ',');

			// 7 Витрати пального кг.
			string fuelConsumption_f_str = "";
			do {
				if ((rdString[p] != ';') && (rdString[p] != ',')) fuelConsumption_f_str += rdString[p];
				p++;
			} while (rdString[p] != ';');
			p = 0;

			getCompanyPassFleet()[i].setPlaneFromFile(
				fleet_f,
				id_f,
				model_f,
				stoi(capacity_f_str),
				stoi(carryingCapacity_f_str),
				stoi(flightRange_f_str),
				stoi(fuelConsumption_f_str));
		}
		rdFile_1.close();
	}

	// Транспортний флот.
	enString = "";
	rdString = "";
	dcString = "";
	p = 0;
	ifstream rdFile_2("TransFleet.acmp", ios::in);

	if (rdFile_2.is_open()) {

		getline(rdFile_2, enString);
		rdString = decrypt(enString);

		do {
			if (rdString[p] != ':') dcString += rdString[p];
			p++;
		} while (rdString[p] != ':');
		p = 0;

		setTransFleetCounter(stoi(dcString));

		Transport* tmpTransFleet = new Transport[getTransFleetCounter()];
		setCompanyTransFleet(tmpTransFleet);
		tmpTransFleet = nullptr;

		for (int i = 0; i < getTransFleetCounter(); i++) {

			getline(rdFile_2, enString);
			rdString = decrypt(enString);

			// 1
			string fleet_f = "";
			do {
				if (rdString[p] != ',') fleet_f += rdString[p];
				p++;
			} while (rdString[p] != ',');

			// 2
			string id_f = "";
			do {
				if (rdString[p] != ',') id_f += rdString[p];
				p++;
			} while (rdString[p] != ',');

			// 3
			string model_f = "";
			do {
				if (rdString[p] != ',') model_f += rdString[p];
				p++;
			} while (rdString[p] != ',');

			// 4
			string capacity_f_str = "";
			do {
				if (rdString[p] != ',') capacity_f_str += rdString[p];
				p++;
			} while (rdString[p] != ',');

			// 5
			string carryingCapacity_f_str = "";
			do {
				if (rdString[p] != ',') carryingCapacity_f_str += rdString[p];
				p++;
			} while (rdString[p] != ',');

			//6
			string flightRange_f_str = "";
			do {
				if (rdString[p] != ',') flightRange_f_str += rdString[p];
				p++;
			} while (rdString[p] != ',');

			// 7
			string fuelConsumption_f_str = "";
			do {
				if ((rdString[p] != ';') && (rdString[p] != ',')) fuelConsumption_f_str += rdString[p];
				p++;
			} while (rdString[p] != ';');
			p = 0;

			getCompanyTransFleet()[i].setPlaneFromFile(
				fleet_f,
				id_f,
				model_f,
				stoi(capacity_f_str),
				stoi(carryingCapacity_f_str),
				stoi(flightRange_f_str),
				stoi(fuelConsumption_f_str));
		}
		rdFile_2.close();
	}

	// Поштовий флот.
	enString = "";
	rdString = "";
	dcString = "";
	p = 0;
	ifstream rdFile_3("MailFleet.acmp", ios::in);

	if (rdFile_3.is_open()) {

		getline(rdFile_3, enString);
		rdString = decrypt(enString);

		do {
			if (rdString[p] != ':') dcString += rdString[p];
			p++;
		} while (rdString[p] != ':');
		p = 0;

		setMailFleetCounter(stoi(dcString));

		Mail* tmpMailFleet = new Mail[getMailFleetCounter()];
		setCompanyMailFleet(tmpMailFleet);
		tmpMailFleet = nullptr;

		for (int i = 0; i < getMailFleetCounter(); i++) {

			getline(rdFile_3, enString);
			rdString = decrypt(enString);

			// 1
			string fleet_f = "";
			do {
				if (rdString[p] != ',') fleet_f += rdString[p];
				p++;
			} while (rdString[p] != ',');

			// 2
			string id_f = "";
			do {
				if (rdString[p] != ',') id_f += rdString[p];
				p++;
			} while (rdString[p] != ',');

			// 3
			string model_f = "";
			do {
				if (rdString[p] != ',') model_f += rdString[p];
				p++;
			} while (rdString[p] != ',');

			// 4
			string capacity_f_str = "";
			do {
				if (rdString[p] != ',') capacity_f_str += rdString[p];
				p++;
			} while (rdString[p] != ',');

			// 5
			string carryingCapacity_f_str = "";
			do {
				if (rdString[p] != ',') carryingCapacity_f_str += rdString[p];
				p++;
			} while (rdString[p] != ',');

			//6
			string flightRange_f_str = "";
			do {
				if (rdString[p] != ',') flightRange_f_str += rdString[p];
				p++;
			} while (rdString[p] != ',');

			// 7
			string fuelConsumption_f_str = "";
			do {
				if ((rdString[p] != ';') && (rdString[p] != ',')) fuelConsumption_f_str += rdString[p];
				p++;
			} while (rdString[p] != ';');
			p = 0;

			getCompanyMailFleet()[i].setPlaneFromFile(
				fleet_f,
				id_f,
				model_f,
				stoi(capacity_f_str),
				stoi(carryingCapacity_f_str),
				stoi(flightRange_f_str),
				stoi(fuelConsumption_f_str));
		}
		rdFile_3.close();
	}

	// Сільськогосподарський флот.
	enString = "";
	rdString = "";
	dcString = "";
	p = 0;
	ifstream rdFile_4("AgricFleet.acmp", ios::in);

	if (rdFile_4.is_open()) {

		getline(rdFile_4, enString);
		rdString = decrypt(enString);

		do {
			if (rdString[p] != ':') dcString += rdString[p];
			p++;
		} while (rdString[p] != ':');
		p = 0;

		setAgricFleetCounter(stoi(dcString));

		Agricultural* tmpAgricFleet = new Agricultural[getAgricFleetCounter()];
		setCompanyAgricFleet(tmpAgricFleet);
		tmpAgricFleet = nullptr;

		for (int i = 0; i < getAgricFleetCounter(); i++) {

			getline(rdFile_4, enString);
			rdString = decrypt(enString);

			// 1
			string fleet_f = "";
			do {
				if (rdString[p] != ',') fleet_f += rdString[p];
				p++;
			} while (rdString[p] != ',');

			// 2
			string id_f = "";
			do {
				if (rdString[p] != ',') id_f += rdString[p];
				p++;
			} while (rdString[p] != ',');

			// 3
			string model_f = "";
			do {
				if (rdString[p] != ',') model_f += rdString[p];
				p++;
			} while (rdString[p] != ',');

			// 4
			string capacity_f_str = "";
			do {
				if (rdString[p] != ',') capacity_f_str += rdString[p];
				p++;
			} while (rdString[p] != ',');

			// 5
			string carryingCapacity_f_str = "";
			do {
				if (rdString[p] != ',') carryingCapacity_f_str += rdString[p];
				p++;
			} while (rdString[p] != ',');

			//6
			string flightRange_f_str = "";
			do {
				if (rdString[p] != ',') flightRange_f_str += rdString[p];
				p++;
			} while (rdString[p] != ',');

			// 7
			string fuelConsumption_f_str = "";
			do {
				if ((rdString[p] != ';') && (rdString[p] != ',')) fuelConsumption_f_str += rdString[p];
				p++;
			} while (rdString[p] != ';');
			p = 0;

			getCompanyAgricFleet()[i].setPlaneFromFile(
				fleet_f,
				id_f,
				model_f,
				stoi(capacity_f_str),
				stoi(carryingCapacity_f_str),
				stoi(flightRange_f_str),
				stoi(fuelConsumption_f_str));
		}
		rdFile_4.close();
	}
}

// Визначення загальних місткості та вантажопідйомності усіх наявних літаків.
void AirCompany::totalFleetCarryingCapacityCalculation() {

	// Сумарна місткість.
	int totalFleetCapacity{};

	// Пасажирський флот.
	for (int i = 0; i < getPassFleetCounter(); i++) {
		totalFleetCapacity += getCompanyPassFleet()[i].getPlaneCapacity();
	}

	// Транспортний флот.
	for (int i = 0; i < getTransFleetCounter(); i++) {
		totalFleetCapacity += getCompanyTransFleet()[i].getPlaneCapacity();
	}

	// Поштовий флот.
	for (int i = 0; i < getMailFleetCounter(); i++) {
		totalFleetCapacity += getCompanyMailFleet()[i].getPlaneCapacity();
	}

	// Сільськогосподарський флот.
	for (int i = 0; i < getAgricFleetCounter(); i++) {
		totalFleetCapacity += getCompanyAgricFleet()[i].getPlaneCapacity();
	}

	cout << endl << endl << "Air company fleet total capacity, (m3): " << totalFleetCapacity;

	// Сумарна вантажопідйомність.
	int totalFleetCarryingCapacity{};

	// Пасажирський флот.
	for (int i = 0; i < getPassFleetCounter(); i++) {
		totalFleetCarryingCapacity += getCompanyPassFleet()[i].getPlaneCarryingCapacity();
	}

	// Транспортний флот.
	for (int i = 0; i < getTransFleetCounter(); i++) {
		totalFleetCarryingCapacity += getCompanyTransFleet()[i].getPlaneCarryingCapacity();
	}

	// Поштовий флот.
	for (int i = 0; i < getMailFleetCounter(); i++) {
		totalFleetCarryingCapacity += getCompanyMailFleet()[i].getPlaneCarryingCapacity();
	}

	// Сільськогосподарський флот.
	for (int i = 0; i < getAgricFleetCounter(); i++) {
		totalFleetCarryingCapacity += getCompanyAgricFleet()[i].getPlaneCarryingCapacity();
	}

	cout << endl << endl << "Air company fleet total carrying capacity, (kg): " << totalFleetCarryingCapacity;

	Log log_1("Fleets carrying capacity calculated");
	Log log_2("Show result: Calculate fleet carrying capacity");
}

// Сортування літаків по дальності польоту.
void AirCompany::flightRangeSort() {

	// Загальний лічильник флоту компанії.
	int totalFleetCounter =
		getPassFleetCounter()
		+ getTransFleetCounter()
		+ getMailFleetCounter()
		+ getAgricFleetCounter();

	// Загальний масив флоту компанії для сортування.
	Plane* companyFlightRange = new Plane[totalFleetCounter];

	int a{};

	// Об'єднання усіх літаків в один масив.

	for (int i = 0; i < getPassFleetCounter(); i++) {
		companyFlightRange[a] = getCompanyPassFleet()[i];
		a++;
	}

	for (int i = 0; i < getTransFleetCounter(); i++) {
		companyFlightRange[a] = getCompanyTransFleet()[i];
		a++;
	}

	for (int i = 0; i < getMailFleetCounter(); i++) {
		companyFlightRange[a] = getCompanyMailFleet()[i];
		a++;
	}

	for (int i = 0; i < getAgricFleetCounter(); i++) {
		companyFlightRange[a] = getCompanyAgricFleet()[i];
		a++;
	}

	// Сортування за дальністю польоту в порядку збільшення.
	for (int i = 0; i < totalFleetCounter; i++) {
		for (int j = 0; j < (totalFleetCounter - 1); j++) {
			if (companyFlightRange[j].getPlaneFlightRange() > companyFlightRange[j + 1].getPlaneFlightRange()) {
				Plane b = companyFlightRange[j]; // создали дополнительную переменную
				companyFlightRange[j] = companyFlightRange[j + 1]; // меняем местами
				companyFlightRange[j + 1] = b; // значения элементов
			}
		}
	}

	// Відображення результатів сортування.
	cout << endl << "Fleet: " << "Id: " << "Model: " << "Capacity, (m3): " << "Carrying capacity, (kg): "
		<< "Flight range,(km): " << "Fuel consumption, (kg):" << endl;

	cout << endl << "Flight Range" << endl;

	for (int i = 0; i < totalFleetCounter; i++) {
		cout << companyFlightRange[i].getPlaneFleet() << ", "
			<< companyFlightRange[i].getPlaneId() << ", "
			<< companyFlightRange[i].getPlaneModel() << ", "
			<< companyFlightRange[i].getPlaneCapacity() << ", "
			<< companyFlightRange[i].getPlaneCarryingCapacity() << ", "
			<< companyFlightRange[i].getPlaneFlightRange() << ", "
			<< companyFlightRange[i].getPlaneFuelConsumption();

		cout << endl;
	}
	Log log_1("Flight range sort");
	Log log_2("Show result: Flight range sort");
}

// Пошук літака за діапазоном споживання пального (за рейс).
void AirCompany::fuelConsumptionSearch() {

	// Загальний лічильник флоту компанії.
	int totalFleetCounter =
		getPassFleetCounter()
		+ getTransFleetCounter()
		+ getMailFleetCounter()
		+ getAgricFleetCounter();

	// Загальний масив флоту компанії.
	Plane* companyFlightRange = new Plane[totalFleetCounter];

	int a{};

	for (int i = 0; i < getPassFleetCounter(); i++) {
		companyFlightRange[a] = getCompanyPassFleet()[i];
		a++;
	}

	for (int i = 0; i < getTransFleetCounter(); i++) {
		companyFlightRange[a] = getCompanyTransFleet()[i];
		a++;
	}

	for (int i = 0; i < getMailFleetCounter(); i++) {
		companyFlightRange[a] = getCompanyMailFleet()[i];
		a++;
	}

	for (int i = 0; i < getAgricFleetCounter(); i++) {
		companyFlightRange[a] = getCompanyAgricFleet()[i];
		a++;
	}

	// Визначення діапазону витрат пального.
	int min{}, max{};
	cout << endl << endl << "Enter min (400) fuel consumption, (kg):";
	cin >> min;
	cout << endl << "Enter max (300000) fuel consumption, (kg):";
	cin >> max;

	// Відображення результатів пошуку літака за диапазоном витрат пального.
	cout << endl << "Fleet: " << "Id: " << "Model: " << "Capacity, (m3): " << "Carrying capacity, (kg): "
		<< "Flight range,(km): " << "Fuel consumption, (kg):" << endl << endl;

	for (int i = 0; i < totalFleetCounter; i++) {

		if ((companyFlightRange[i].getPlaneFuelConsumption() >= min) &&
			(companyFlightRange[i].getPlaneFuelConsumption() <= max)) {

			cout << companyFlightRange[i].getPlaneFleet() << ", "
				<< companyFlightRange[i].getPlaneId() << ", "
				<< companyFlightRange[i].getPlaneModel() << ", "
				<< companyFlightRange[i].getPlaneCapacity() << ", "
				<< companyFlightRange[i].getPlaneCarryingCapacity() << ", "
				<< companyFlightRange[i].getPlaneFlightRange() << ", "
				<< companyFlightRange[i].getPlaneFuelConsumption();
			cout << endl;
		}
	}
	Log log_1("Fuel consumption search");
	Log log_2("Show result: Fuel consumption search");
}


// Відображення.
void AirCompany::show(AirCompany& planesList) {

	cout << endl << "Fleet: " << "Id: " << "Model: " << "Capacity, (m3): " << "Carrying capacity, (kg): "
		<< "Flight range,(km): " << "Fuel consumption, (kg):" << endl;

	cout << planesList;
	Log log_1("Show: Air company fleet");
}


// Глобальні функції.
// Перевантаження оператора виведення.
ostream& operator <<(ostream& out, AirCompany& planesList) {

	out << endl << "Passenger Fleet" << endl;
	for (int i = 0; i < planesList.getPassFleetCounter(); i++) {
		out << planesList.getCompanyPassFleet()[i].getPlaneFleet() << ", "
			<< planesList.getCompanyPassFleet()[i].getPlaneId() << ", "
			<< planesList.getCompanyPassFleet()[i].getPlaneModel() << ", "
			<< planesList.getCompanyPassFleet()[i].getPlaneCapacity() << ", "
			<< planesList.getCompanyPassFleet()[i].getPlaneCarryingCapacity() << ", "
			<< planesList.getCompanyPassFleet()[i].getPlaneFlightRange() << ", "
			<< planesList.getCompanyPassFleet()[i].getPlaneFuelConsumption();

		out << endl;
	}

	out << endl << endl << "Transport Fleet" << endl;
	for (int i = 0; i < planesList.getTransFleetCounter(); i++) {
		out << planesList.getCompanyTransFleet()[i].getPlaneFleet() << ", "
			<< planesList.getCompanyTransFleet()[i].getPlaneId() << ", "
			<< planesList.getCompanyTransFleet()[i].getPlaneModel() << ", "
			<< planesList.getCompanyTransFleet()[i].getPlaneCapacity() << ", "
			<< planesList.getCompanyTransFleet()[i].getPlaneCarryingCapacity() << ", "
			<< planesList.getCompanyTransFleet()[i].getPlaneFlightRange() << ", "
			<< planesList.getCompanyTransFleet()[i].getPlaneFuelConsumption();

		out << endl;
	}

	out << endl << endl << "Mail Fleet" << endl;
	for (int i = 0; i < planesList.getMailFleetCounter(); i++) {
		out << planesList.getCompanyMailFleet()[i].getPlaneFleet() << ", "
			<< planesList.getCompanyMailFleet()[i].getPlaneId() << ", "
			<< planesList.getCompanyMailFleet()[i].getPlaneModel() << ", "
			<< planesList.getCompanyMailFleet()[i].getPlaneCapacity() << ", "
			<< planesList.getCompanyMailFleet()[i].getPlaneCarryingCapacity() << ", "
			<< planesList.getCompanyMailFleet()[i].getPlaneFlightRange() << ", "
			<< planesList.getCompanyMailFleet()[i].getPlaneFuelConsumption();

		out << endl;
	}

	out << endl << endl << "Agricultural Fleet" << endl;
	for (int i = 0; i < planesList.getAgricFleetCounter(); i++) {
		out << planesList.getCompanyAgricFleet()[i].getPlaneFleet() << ", "
			<< planesList.getCompanyAgricFleet()[i].getPlaneId() << ", "
			<< planesList.getCompanyAgricFleet()[i].getPlaneModel() << ", "
			<< planesList.getCompanyAgricFleet()[i].getPlaneCapacity() << ", "
			<< planesList.getCompanyAgricFleet()[i].getPlaneCarryingCapacity() << ", "
			<< planesList.getCompanyAgricFleet()[i].getPlaneFlightRange() << ", "
			<< planesList.getCompanyAgricFleet()[i].getPlaneFuelConsumption();

		out << endl;
	}

	return out;
}

// Перетворення цілого на рядок.
string toString(int number) {
	string number_string = to_string(number);
	return number_string;
}

// Перетворення символьного масиву на рядок.
string toString(char* char_word) {
	string char_string(char_word);
	return char_string;
}

// Вихід з програми.
void quit() {
	Log log_1("Quit: Program's shutted down");
	exit(777); // Код успішного виходу 777.
}
