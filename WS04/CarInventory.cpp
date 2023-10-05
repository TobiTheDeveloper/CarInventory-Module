#define _CRT_SECURE_NO_WARNINGS
#include "CarInventory.h"
#include <cstring>
#include <iostream>
using namespace std;


namespace sdds {

	CarInventory::CarInventory() {
		this->resetInfo();
	}

	void CarInventory::resetInfo() {
		this->m_type = nullptr;
		this->m_brand = nullptr;
		this->m_model = nullptr;
		this->m_year = 0;
		this->m_code = 0;
		this->m_price = 0;
	}

	CarInventory::CarInventory(const char* type, const char* brand, const char* model, int year, int code, double price) {
		if (type != nullptr && brand != nullptr && model != nullptr && year >= 1990 && (code > 99 || code < 1000) && price > 0) {
			this->resetInfo();
			this->setInfo(type, brand, model, year, code, price);
		}
		else {
			this->resetInfo();
		}

	}

	CarInventory:: ~CarInventory() {
		delete[] m_type;
		delete[] m_brand;
		delete[] m_model;

		m_type = nullptr;
		m_brand = nullptr;
		m_model = nullptr;

	}

	CarInventory& CarInventory::setInfo(const char* type, const char* brand, const char* model, int year, int code, double price) {
		delete[] this->m_type;
		delete[] this->m_brand;
		delete[] this->m_model;

		this->m_type = new char[strlen(type) + 1];
		this->m_brand = new char[strlen(brand) + 1];
		this->m_model = new char[strlen(model) + 1];

		strcpy(this->m_type, type);
		strcpy(this->m_brand, brand);
		strcpy(this->m_model, model);
		this->m_year = year;
		this->m_code = code;
		this->m_price = price;

		return *this;
	}

	void CarInventory::printInfo() const {
		printf("| %-11s| %-17s| %-17s| %-5d|  %-4d|%10.2lf |\n", this->m_type, this->m_brand, this->m_model, this->m_year, this->m_code, this->m_price);
	}

	bool CarInventory::isValid() const {
		bool isvalid = 0;

		if (this->m_type != nullptr && this->m_brand != nullptr && this->m_model != nullptr && this->m_year >= 1990 && (this->m_code > 99 || this->m_code < 1000) && this->m_price > 0) {
			isvalid = 1;
		}
		return isvalid;
	}

	bool CarInventory::isSimilarTo(const CarInventory& car) const {
		bool isSimilar = 0;
		if (this->isValid())
		{
			if (!strcmp(this->m_type, car.m_type) && !strcmp(this->m_model, car.m_model) && !strcmp(this->m_brand, car.m_brand) && this->m_year == car.m_year)
			{
				isSimilar = 1;
			}
		}

		return isSimilar;
	}

	bool find_similar(CarInventory car[], const int num_cars) {
		bool isSimilar = 0;
		int i, j;

		for (i = 0; i < num_cars; i++) {
			for (j = i + 1; j < num_cars; j++)
			{
				if (car[i].isSimilarTo(car[j]))
				{
					isSimilar = 1;
				}
			}
		}
		return isSimilar;
	}

}