#pragma once
#include <algorithm>
#include "Plane.h"
#include "Passenger.h"
#include "Transport.h"
#include "Mail.h"
#include "Agricultural.h"
#include "Log.h"

using namespace std;

class AirCompany // ���� ���������
{
private:
	Passenger* companyPassFleet = new Passenger[0];			// ����� ������������� �����.
	Transport* companyTransFleet = new Transport[0];		// ����� ������������� �����.
	Mail* companyMailFleet = new Mail[0];					// ����� ��������� �����.
	Agricultural* companyAgricFleet = new Agricultural[0];	// ����� ��������������������� �����.

	int passFleetCounter{};		// ˳������� ������������� �����.
	int transFleetCounter{};	// ˳������� ������������� �����.
	int mailFleetCounter{};		// ˳������� ��������� �����.
	int agricFleetCounter{};	// ˳������� ��������������������� �����.

public:
	// ������������.
	AirCompany();
	explicit AirCompany(Passenger&);
	explicit AirCompany(Transport&);
	explicit AirCompany(Mail&);
	explicit AirCompany(Agricultural&);

	// ����������
	~AirCompany();

	// ������� �����.
	void setCompanyPassFleet(Passenger* ptr) { companyPassFleet = ptr; }
	void setCompanyTransFleet(Transport* ptr) { companyTransFleet = ptr; }
	void setCompanyMailFleet(Mail* ptr) { companyMailFleet = ptr; }
	void setCompanyAgricFleet(Agricultural* ptr) { companyAgricFleet = ptr; }

	// ������� �����.
	Passenger* getCompanyPassFleet() { return companyPassFleet; }
	Transport* getCompanyTransFleet() { return companyTransFleet; }
	Mail* getCompanyMailFleet() { return companyMailFleet; }
	Agricultural* getCompanyAgricFleet() { return companyAgricFleet; }

	// ������� ��������� �����.
	void setPassFleetCounter(int value) { passFleetCounter = value; };
	void setTransFleetCounter(int value) { transFleetCounter = value; };
	void setMailFleetCounter(int value) { mailFleetCounter = value; };
	void setAgricFleetCounter(int value) { agricFleetCounter = value; };

	// ������� ��������� �����.
	int getPassFleetCounter() { return passFleetCounter; }
	int getTransFleetCounter() { return transFleetCounter; }
	int getMailFleetCounter() { return mailFleetCounter; }
	int getAgricFleetCounter() { return  agricFleetCounter; }

	void flightRangeSort(); // ���������� ����� �� �������� �������.

	// ���������� ��������� ������� �� ���������������� ��� ����� ������.
	void totalFleetCarryingCapacityCalculation();

	void fuelConsumptionSearch(); // ����� ����� �� ��������� ������ ��������.

	// ����������, ������������.
	string encrypt(const string&);
	string decrypt(const string&);

	// �����, ���������� �����.
	void writeFile(int);
	void readFile();

	void show(AirCompany&); // ³���������� �������� �� �������� ����� ������.
};

ostream& operator <<(ostream&, AirCompany&); // �������������� ��������� ���������.

// ������� ������������ � �����.
string toString(int);
string toString(char*);

// ����� � ��������.
void quit();

