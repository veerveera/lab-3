#include "list.h"


void print(Air* head) {
	Air* tmp = head;
	while (tmp != NULL) {
		printf("Название: %s\n Страна: %s\n Город: %s\n Высота: %d\n", tmp->name, tmp->country, tmp->city, tmp->height);
		tmp = tmp->next;
	}
}
void printFile(Air* head, char* file) {
	FILE* fp;

	fp = fopen(file, "w+");
	if (fp == NULL) return;
	Air* tmp = head;
	while (tmp != NULL) {
		fprintf(fp, "%s\n%s\n%s\n%d\n", tmp->name, tmp->country, tmp->city, tmp->height);
		tmp = tmp->next;
	}

	fclose(fp);
}
Air* pushFront(Air* head, char* name, char* country, char* city, int height) {
	Air* tmp = (Air*)malloc(sizeof(Air));

	strcpy(tmp->name, name);
	strcpy(tmp->country, country);
	strcpy(tmp->city, city);
	tmp->height = height;

	tmp->next = head;
	tmp->prev = NULL;

	if (head) {
		head->prev = tmp;
	}
	return tmp;
}

void insert(Air* head, int index, char* name, char* country, char* city, int height) {
	Air* elemBefore = find(head, index);
	if (!elemBefore)
		return;

	Air* tmp = (Air*)malloc(sizeof(Air));
	strcpy(tmp->name, name);
	strcpy(tmp->country, country);
	strcpy(tmp->city, city);
	tmp->height = height;

	tmp->next = elemBefore->next;
	tmp->prev = elemBefore;

	if (elemBefore->next) {
		elemBefore->next->prev = tmp;
	}
	elemBefore->next = tmp;
}

void freeList(Air* head) {
	Air* tmp = head;
	while (tmp != NULL) {
		Air* p = tmp;
		tmp = tmp->next;
		free(p);
	}
}

void del(Air* head, int index) {
	Air* finded = find(head, index);
	if (!finded)
		return;

	if (finded->prev) {
		finded->prev->next = finded->next;
	}
	if (finded->next) {
		finded->next->prev = finded->prev;
	}
	free(finded);
}

Air* find(Air* head, int index) {
	Air* finded = NULL, * tmp = head;
	int i = 0;
	while (tmp != NULL) {
		if (i == index) {
			finded = tmp;
			break;
		}
		i++;
		tmp = tmp->next;
	}
	return finded;
}

Air* findByName(Air* head, char* value) {
	Air* finded = NULL,* tmp = head;
	while (tmp != NULL) {
		if (strcmp(tmp->name, value) == 0) {
			finded = tmp;
			break;
		}
		tmp = tmp->next;
	}
	return finded;
}
Air* findByCountry(Air* head, char* value) {
	Air* finded = NULL, * tmp = head;
	while (tmp != NULL) {
		if (strcmp(tmp->country, value) == 0) {
			finded = tmp;
			break;
		}
		tmp = tmp->next;
	}
	return finded;
}
Air* findByCity(Air* head, char* value) {
	Air* finded = NULL, * tmp = head;
	while (tmp != NULL) {
		if (strcmp(tmp->city, value) == 0) {
			finded = tmp;
			break;
		}
		tmp = tmp->next;
	}
	return finded;
}
Air* findByHeight(Air* head, int value) {
	Air* finded = NULL, * tmp = head;
	while (tmp != NULL) {

		if (tmp->height==value) {
			finded = tmp;
			break;
		}
		tmp = tmp->next;
	}
	return finded;
}


void edit(Air* head, int index, char* info, char* newvalue) {
	Air* finded = find(head, index);
	if (!finded)
		return;

	if (strcmp("Город", info) == 0)
		strcpy(finded->city, newvalue);
	else if (strcmp("Страна", info) == 0)
		strcpy(finded->country, newvalue);
	else if (strcmp("Название", info) == 0)
		strcpy(finded->name, newvalue);
}
void edit1(Air* head, int index, char* info, int newvalue) {
	Air* finded = find(head, index);
	if (!finded)
		return;

	if (strcmp("Высота", info) == 0)
		finded->height=newvalue;
}

int size(Air* head) {
	Air* tmp = head;
	int size = 0;
	while (tmp != NULL) {
		size++;
		tmp = tmp->next;
	}
}
