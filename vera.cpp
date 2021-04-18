#include <iostream>
#include "list.h"
//#include<locale.h>
//#include<windows.h>
using namespace std;

int main(int argc, char* argv[]) {
	//setlocale(LC_ALL, "Russian");
	//SetConsoleCP(1251);
	//SetConsoleOutputCP(1251);
string filename(argv[1]);
if (argc < 2){
	std::cout <<" Specify a file name" ;
	return 1;
}
int variant = -1;
Menu menu;


std::ifstream in(filename);
std::string names,countrys, citys, heighti;
	if (in.is_open())
	{
		while (1)
		{
			if (std::getline(in, names) && std::getline(in, countrys) && std::getline(in, citys) && std::getline(in, heighti)) {
				menu.pushFront(names, countrys, citys, stoi(heighti));
			}
			else {
				break;
			}
		}
		in.close();
	}
	else {
		std::cout << "Can't open file " << filename << '\n';
		return 1;
	}

	while (variant != 9) {
		std::cout << "Menu \n";
		std::cout << "1.Add the airbase \n";
		std::cout << "2.View airbase \n";
		std::cout << "3.Find Airbase by name \n";
		std::cout << "4.Find Airbase by country \n";
		std::cout << "5.Find Airbase by city \n";
		std::cout << "6.Find Airbase by height \n";
		std::cout << "7.Delete airbase \n";
		std::cout << "8.Edit the airbase \n";
		std::cout << "9.Exit \n";
		std::cin >> variant;

		switch (variant) {
		case 1: {
			string name, country, city;
			int height;
			cout << "enter Name:";
			cin >> name;
			cout << "Enter Country:";
			cin >> country;
			cout << "Enter City:";
			cin >> city;
			cout << "Enter Height:";
			cin >> height;

			menu.pushFront(name, country, city, height);
			menu.printFile(filename);
		}

			  break;
		case 2:
			menu.print();
			break;
		case 3: {
			string name;
			cin >> name;
			Air* a = menu.findAirByName(name);
			cout << *a << endl;
		}
			 break;
		case 4: {
			string country;
			cin >> country;
			Air* a = menu.findAirByCountry(country);
			cout << *a << endl;
		}
			  break;
		case 5: {
			string city;
			cin >> city;
			Air* a = menu.findAirByCity(city);
			cout << *a << endl;
		}
			  break;

		case 6: {
			int height;
			cin >> height;
			Air* a = menu.findAirByHeight(height);
			cout << *a << endl;
		}
			  break;
		case 7: {
			int index;
			cout << "Enter index:" << '\n';
			cin >> index;
			menu.del(index);
			menu.printFile(filename);
		}
			  break;
		case 8: {
			int index;
			string editname;
			string value;
			cout << "Enter index:" << '\n';
			cin >> index;
			cout << "Enter what you want to change:Name, Cointry, City, Height:";
			cin >> editname;
			cout << "Enter value:";
			cin >> value;
			menu.edit(index, editname, value);
			menu.printFile(filename);
		}
		case 9:
		default:
			break;
		}
	}
}

