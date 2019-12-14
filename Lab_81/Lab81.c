#define _CRT_SECURE_NO_WARNINGS
#include "stdlib.h"
#include "stdio.h"
#include "math.h"
#include "locale.h"
#include "string.h"
#include "windows.h"
#include <Windows.h>
#include <conio.h>
#define MAXSIZE 11

char* month(int i,char mon[MAXSIZE]);

int main(int agrc, char* agrv[]) {
	int i , yes_no = 0;
	char mon[MAXSIZE];
	setlocale(LC_CTYPE, "ukr");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	printf("Програма переведення числа в назву місяця, введіть число:\n");
	scanf_s("%d", &i);
	if (i < 1 || i>12) {
		printf("Помилка, введіть число від 1 до 12\n");
		while (i < 1 || i>12) {
			scanf("%[123456789,10,12]", &i);
		}
	}
	puts(month(i, mon));
	printf("\n");
	printf("Для продовження введіть 1\n");
	scanf_s("%d", &yes_no);
	if (yes_no == 1) {
		system("cls");
		main(1, 0);
	}
	return 0;
}

char* month(int i,char mon[MAXSIZE]) {
	switch (i) {
	case 1:
		strcpy(mon, "Січень");
		break;
	case 2:
		strcpy(mon, "Лютий");
		break;
	case 3:
		strcpy(mon, "Березень");
		break;
	case 4:
		strcpy(mon, "Квітень");
		break;
	case 5:
		strcpy(mon, "Травень");
		break;
	case 6:
		strcpy(mon, "Червень");
		break;
	case 7:
		strcpy(mon, "Липень");
		break;
	case 8:
		strcpy(mon, "Серпень");
		break;
	case 9:
		strcpy(mon, "Вересень");
		break;
	case 10:
		strcpy(mon, "Жовтень");
		break;
	case 11:
		strcpy(mon, "Листопад");
		break;
	case 12:
		strcpy(mon, "Грудень");
		break;
	}
	return mon;
}