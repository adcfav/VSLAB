#define _CRT_SECURE_NO_WARNINGS
#include "stdlib.h"
#include "stdio.h"
#include "math.h"
#include "locale.h"
#include "string.h"
#include "windows.h"
#define STRLEN 256

int main() {
	char Str[STRLEN];
	char CheckStr[STRLEN];
	int count = 0;
	int check = 0;
	setlocale(LC_CTYPE, "ukr");
	for (int i = 0; i <= STRLEN - 1; i++) {
		Str[i] = ' ';
		CheckStr[i] = ' ';
	}
	printf("Введiть рядок(до 256 символiв):\n");
	gets(Str);
	OemToChar(Str, Str);
	printf("Введiть шукане слово(до 256 символiв):\n");
	gets(CheckStr);
	OemToChar(CheckStr, CheckStr);
	count = strlen(CheckStr) - 1;
	for (int i = 0; i <= STRLEN - 1; i++) {
		if (Str[i] != ' ') {
			for (int j = 0; j <= count;) {
				if (CheckStr[j] == Str[i]) {
					j++;
					i++;
				}
				if(CheckStr[j] == Str[i]&&count == j){
					printf("Введене слово є в рядку!!\n");
					check = 1;
					break;
				}
				else {
					printf("Введене слово не є в рядку!!\n");
					break; 
				}
			}
		}
		if (check == 1) {
			break;
		}
	}

	getch();
	return 0;
}
