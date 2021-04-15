#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Air {
	char name[100];
	char country[100];
	char city[100];
	int height;
	struct Air* next;
	struct Air* prev;
} Air;

void print(Air* head);
void printFile(Air* head, char* file);
Air* pushFront(Air* head, char* name, char* country, char* city, int height);
void insert(Air* head, int index, char* name, char* country, char* city, int height);
void del(Air* head, int index);
void edit(Air* head, int index, char* info, char* newvalue);
void edit1(Air* head, int index, char* info, int newvalue);



Air* find(Air* head, int index);
Air* findByName(Air* head, char* value);
Air* findByCountry(Air* head, char* value);
Air* findByCity(Air* head, char* value);
Air* findByHeight(Air* head, int value);

int size(Air* head);
void freeList(Air* head);
