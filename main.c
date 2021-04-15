#include"list.h"
#include<locale.h>

int main(int argc, char* argv[]) {
	if (argc < 2)
		return 1;
	char* fn = argv[1];

	setlocale(LC_ALL, "Russian");

	Air* head = NULL;

	FILE* mf;
	char name[100];
	char country[100];
	char city[100];
	char heightS[100];
	int height = 0;
	char empty[100] = " ";
	mf = fopen(fn, "r");
	if (mf == NULL){
		printf("error");
		 return 1;
			}

	while (1)
	{
		fgets(name, 100, mf);
		fgets(country, 100, mf);
		fgets(city, 100, mf);
		fgets(heightS, 100, mf);
		height = atoi(heightS);

		printf("%s %s %s %d", name, country, city, height);
		if (name == "" || country == "" || city == "" || height == 0)  {
			if (feof(mf) != 0)
			{
				printf("\nЧтение файла закончено\n");
				break;
			}
			else
			{
				printf("\nОшибка в чтении файла\n");
				break;
			}
		}
		strtok(name, "\n");
		strtok(country, "\n");
		strtok(city, "\n");
		head = pushFront(head, name, country, city, height);
		strcpy(name, "");
		strcpy(country, "");
		strcpy(city, "");
		strcpy(heightS, "");
		height = -1;


	}
	printf("Закрытие файла : ");
	fclose(mf);
/*
	void print_menu() {
    	printf("Выберите действие.\n");
    	printf("1. Новая авиабаза\n");
    	printf("2. Список\n");
    	printf("3.Отредактировать информацию\n");
    	printf("4.Поиск по названию\n");
    	printf("5.Поиск по стране\n");
    	printf("6.Поиск по городу\n");
    	printf("7.Поиск по высоте\n");
	printf("8.Поиск по ID\n");
	printf("9.Выход\n");
	}
*/
	int choose = -1;
	while (choose != 9) {
		printf("1.Новая авиабаза\n 2.Список\n 3.Отредактировать информацию\n 4.Поиск по названию\n 5.Поиск по стране\n 6.Поиск по городу\n 7.Поиск по высоте\n 8.Поиск по ID\n 9.Выход\n");
		scanf("%d", &choose);
		if (choose == 1) {
			char name[100], country[100], city[100];
			int height;
			printf("Название:");
			scanf("%s", name);
			printf("Страна:");
			scanf("%s", country);
			printf("Город:");
			scanf("%s", city);
			printf("Высота:");
			scanf("%d", &height);
			head = pushFront(head, name, country, city, height);
			printFile(head, fn);
		}
		if (choose == 2) {
			print(head);
		}
		if (choose == 3) {
			int index;
			char editname[100];
			char value[255];
			int ivalue;
			scanf("%d", &index);
			printf("Введите строку редактирования: Название, страну, город, высота ");
			scanf("%s", editname);

			printf("Введите значение: ");
			if(editname == "height"){
			scanf("%d", &ivalue);
			edit1(head, index, editname, ivalue);
			}
			else{
			scanf("%s", value);
			edit(head, index, editname, value);
			}
			printFile(head, fn);
		}
		if (choose == 4) {
			char name[100];
			scanf("%s", name);
			Air* result = findByName(head, name);
			if(result!=NULL)
			printf("Название: %s\n Страна: %s\n Город: %s\n Высота: %d\n", result->name, result->country, result->city, result->height);
		}
		if (choose == 5) {
			char country[100];
			scanf("%s", country);
			Air* result = findByCountry(head, country);
			if (result != NULL)
			printf("Название: %s\n Страна: %s\n Город: %s\n Высота: %d\n", result->name, result->country, result->city, result->height);
		}
		if (choose == 6) {
			char city[100];
			scanf("%s", city);
			Air* result = findByCity(head, city);
			if (result != NULL)
			printf("Название: %s\n Страна: %s\n Город: %s\n Высота: %d\n", result->name, result->country, result->city, result->height);

		}
		if (choose == 7) {
			int height;
			scanf("%d", &height);
			Air* result = findByHeight(head, height);
			if (result != NULL)
				printf("Название: %s\n Страна: %s\n Город: %s\n Высота: %d\n", result->name, result->country, result->city, result->height);

		}
		if (choose == 8) {
			int id;
			printf("ID Аэродрома:");
			scanf("%d", &id);

			del(head, id);
			printFile(head, fn);
		}
}
	freeList(head);
	return 0;
}
