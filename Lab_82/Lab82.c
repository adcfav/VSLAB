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

int check(char str1[MAXSIZE]);

int main(int agrc, char* agrv[]) {
	int yes_no = 0;
	int count = 0;
	char str1[MAXSIZE];
	char EnLowCh[] = "qwertyuiopasdfghjklzxcvbnm";
	setlocale(LC_CTYPE, "ukr");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	printf("Програма перевірки слова на паліндромність\n");
	printf("Введіть слово\n");
	scanf("%s", &str1);
	for (int i = 0; i < MAXSIZE; i++){
		if (str1[i] == '\0') {
			break;
		}
		if (strchr(EnLowCh, str1[i])) {
			count++;
		}
	}

	if (count != strlen(str1)) {
		printf("Повторіть введення програма прияла недопустимий символ!!!\n");
		main(1, 0);
	}

	if (check(str1) == 1) {
		printf("YES");
	}
	else {
		printf("NO");
	}
	printf("\n");
	printf("Для продовження введіть 1\n");
	scanf_s("%d", &yes_no);
	if (yes_no == 1) {
		system("cls");
		main(1, 0);
	}
	return 0;
}

int check(char str1[MAXSIZE]) {
	char str2[MAXSIZE];
	int count = 0;
	int len = strlen(str1);
	for (int i = 0; i < len; i++) {
		if (str1[i] != '\0') {
			str2[abs(i - len + 1)] = str1[i];
		}
	}
	str2[len] = '\0';
	for (int i = 0; i < len; i++) {
		if (str2[i] == str1[i]) {
 			count++;
		}
	}
	if (count == len) {
		return 1;
	}
	else {
		return 0;
	}
}