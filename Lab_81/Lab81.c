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
	printf("�������� ����������� ����� � ����� �����, ������ �����:\n");
	scanf_s("%d", &i);
	if (i < 1 || i>12) {
		printf("�������, ������ ����� �� 1 �� 12\n");
		while (i < 1 || i>12) {
			scanf("%[123456789,10,12]", &i);
		}
	}
	puts(month(i, mon));
	printf("\n");
	printf("��� ����������� ������ 1\n");
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
		strcpy(mon, "ѳ����");
		break;
	case 2:
		strcpy(mon, "�����");
		break;
	case 3:
		strcpy(mon, "��������");
		break;
	case 4:
		strcpy(mon, "������");
		break;
	case 5:
		strcpy(mon, "�������");
		break;
	case 6:
		strcpy(mon, "�������");
		break;
	case 7:
		strcpy(mon, "������");
		break;
	case 8:
		strcpy(mon, "�������");
		break;
	case 9:
		strcpy(mon, "��������");
		break;
	case 10:
		strcpy(mon, "�������");
		break;
	case 11:
		strcpy(mon, "��������");
		break;
	case 12:
		strcpy(mon, "�������");
		break;
	}
	return mon;
}