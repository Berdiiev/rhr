#include <iostream>
#include <fstream>
#include <ctime>
#include "AirCompany.h"
#include "Log.h"

using namespace std;

Log::~Log() {}
Log::Log(string logstring) {
	logFile(logstring);
}

void Log::logFile(string logstring) {

	// Генерація часового маркера.
	time_t const timeNow = time(nullptr);
	char buffer[26];
	ctime_s(buffer, sizeof(buffer), &timeNow);

	// Запис у лог-файл.
	ofstream logFile("logAirCompany.txt", ios::app);
	if (logFile.is_open()) {

		logFile << logstring << ": " << buffer;

		logFile.close();
	}
}
