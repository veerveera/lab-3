#include <string>
#include <iostream>
#include <fstream>

class Air {
private:
	std::string name;
	std::string country;
	std::string city;
	int height;
public:

	Air* next;
	Air* prev;


	Air() {
		next = NULL;
		prev = NULL;

	}
	Air(std::string name, std::string country, std::string city, int height) : name(name), country(country), city(city), height(height) {
		next = NULL;
		prev = NULL;

	}
	friend std::ostream& operator<< (std::ostream& out, const Air& air)
	{
		out << "Name Airbase:" <<air.name<< '\n';
		out << "Country:" << air.country << '\n';
		out << "City:" << air.city << '\n';
		out << "Height: " << air.height << '\n';
		return out;
	}

	friend std::istream& operator>> (std::istream& is, Air& air)
	{
		is >> air.name >> air.country >> air.city >> air.height;
		return is;
	}

	void SetName(std::string n) {
		this->name = n;
	}
	std::string GetName() {
		return this->name;
	}
	void SetCountry(std::string c) {
		this->country = c;
	}
	std::string GetCountry() {
		return this->country;
	}
	void SetCity(std::string c) {
		this->city = c;
	}
	std::string GetCity() {
		return this->city;
	}
	void SetHeight(int h) {
		this->height = h;
	}
	int GetHeight() {
		return this->height;
	}
};

class Menu {
private:
	Air* begin;
	Air* end;
	size_t size;
	Air* find(int index);
public:
	Menu() {
		begin = NULL;
		end = NULL;
		size = 0;
	}
	Menu(Air air) {
		Air* tmp = new Air(air);
		end = tmp;
		begin = tmp;
		size = 1;
	}



	Air* findAirByName(std::string name);
	Air* findAirByCountry(std::string country);
	Air* findAirByCity(std::string city);
	Air* findAirByHeight(int height);


	void print();
	void printFile(std::string name);
	void pushFront(std::string name, std::string country, std::string city, int height);
	void del(int index);
	void edit(int index, std::string info, std::string value);

	void freeList();
};
