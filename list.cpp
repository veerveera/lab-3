#include "list.h"


Air* Menu::find(int index) {
	Air* finded = NULL, * tmp = begin;
	int i = 0;
	while (tmp != NULL) {
		if (i == index) {
			finded = tmp;
			break;
		}
		tmp = tmp->next;
		i++;
	}
	return finded;
}

Air* Menu::findAirByName(std::string name) {
	Air* finded = NULL, * tmp = begin;
	while (tmp != NULL) {
		if (tmp->GetName() == name) {
			finded = tmp;
			break;
		}
		tmp = tmp->next;
	}
	return finded;
}

Air* Menu::findAirByCountry(std::string country) {
	Air* finded = NULL, * tmp = begin;
	while (tmp != NULL) {
		if (tmp->GetCountry() == country) {
			finded = tmp;
			break;
		}
		tmp = tmp->next;
	}
	return finded;
}

Air* Menu::findAirByCity(std::string city) {
	Air* finded = NULL, * tmp = begin;
	while (tmp != NULL) {
		if (tmp->GetCity() == city) {
			finded = tmp;
			break;
		}
		tmp = tmp->next;
	}
	return finded;
}

Air* Menu::findAirByHeight(int height) {
	Air* finded = NULL, * tmp = begin;
	while (tmp != NULL) {
		if (tmp->GetHeight() == height) {
			finded = tmp;
			break;
		}
		tmp = tmp->next;
	}
	return finded;
}

void Menu::edit(int index, std::string info, std::string value) {
	Air* finded = find(index);
	if (!finded) {
		std::cout << "There is no such index" << index << '\n';
		return;
	}
	if (info == "Name") {
		finded->SetName(value);
	}
	else if (info == "Country") {
		finded->SetCountry(value);
	}
	else if (info == "City") {
		finded->SetCity(value);
	}
	else if (info == "Height") {
		finded->SetHeight(stoi(value));
	}
	else {
		std::cout << "Does not find" << info << '\n';
		return;
	}
}

void Menu::pushFront(std::string name, std::string country, std::string city, int height) {

	Air* tmp = new Air(name, country, city, height);
	tmp->next = NULL;
	tmp->prev = end;

	if (end) {
		end->next = tmp;
		end = tmp;
	}
	else {
		end = tmp;
		begin = tmp;
	}
}

void Menu::print() {
	Air* tmp = begin;
	int i = 1;
	while (tmp != NULL) {
		std::cout << "Airbase" << i << '\n';
		std::cout << *tmp;
		tmp = tmp->next;
		i++;
	}
}

void Menu::printFile(std::string fileName) {
	std::ofstream out(fileName);
	if (out.is_open())
	{
		Air* tmp = begin;
		while (tmp != NULL) {
			out << tmp->GetName() << '\n' << tmp->GetCountry() << '\n' << tmp->GetCity() << '\n' << tmp->GetHeight() << '\n';
			tmp = tmp->next;
		}
	}
	else {
		std::cout << "Can't open file " << fileName << '\n';
	}
	out.close();
}

void Menu::del(int index) {

	Air* finded = find(index);
	if (!finded)
		return;

	if (index == 0) {
		begin = finded->next;
		finded->next->prev = NULL;
	}
	else {
		if (finded->prev) {
			finded->prev->next = finded->next;
		}
		if (finded->next) {
			finded->next->prev = finded->prev;
		}
	}
	delete finded;

}

void Menu::freeList() {
	Air* tmp = begin;
	while (tmp != NULL) {
		Air* p = tmp;
		tmp = tmp->next;
		delete p;
	}
	size = 0;
}
