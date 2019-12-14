#define _CRT_SECURE_NO_WARNINGS
#include "stdlib.h"
#include "stdio.h"
#include "math.h"
#include "locale.h"
#include "string.h"
#include "windows.h"
#define STRSIZE 20

short AskYesNo();

struct Hotel {
	char Name[STRSIZE];
	char City[STRSIZE];
	unsigned short RoomNumber;
	unsigned short Stars;
};

int main(int agrc, char* agrv[]) {
	int status;
	char FileName[STRSIZE];
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	if (agrc == 3) {
		if (strcmp(agrv[1], "--file")) {
			status = 3;
			strcpy(FileName, agrv[2]);
			printf("Програма приняла аргументи");
		}
	}
	if (agrc == 2) {
		if (strcmp(agrv[1], "--manual")) {
			status = 2;
			printf("Програма приняла аргументи");
		}
	}
	if (agrc == 1) {
		printf("Введіть 1 для запису в файл 0 для використання\n");
		status = AskYesNo();
	}
	return 0;
}

short AskYesNo() {
	char ch;
	int res;
	do {
		scanf("%c", &ch);
		if (ch == '1') {
			res = 1;
			return 1;
		}
		else if(ch == '0') {
			res = 1;
			return 0;
		}
		else {
			res = 0;
			scanf("%*[^\n]");
			printf("Не вірний ввід, повторіть спробу\n");
		}
	} while (res != 1);
}
	
