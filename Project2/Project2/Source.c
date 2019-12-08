#define _CRT_SECURE_NO_WARNINGS
#include "stdlib.h"
#include "stdio.h"
#include "math.h"
#include "locale.h"
#include "string.h"
#include "windows.h"
#define STRLEN 1001

int main() {
	int YesNo = 0;
	char Str[STRLEN];

	setlocale(LC_CTYPE, "ukr");
	printf("Програма виводу слова за його номером\n");
	printf("Ведiть рядок слiв(До 1000 символiв),\n");
	printf("Пiсля введення введiть номер бажаного слова:\n");
		int NumStr = 0;
		int InpNum = 0;
		
		for (int i = 0; i <= STRLEN - 1; i++) {
			Str[i] = ' ';
		}

		fgets(Str, STRLEN - 1, stdin);
		OemToChar(Str, Str);

		for (int i = 0; i <= STRLEN - 1; i++) {
			if (Str[i] != ' ') {
				NumStr++;
				while (Str[i] != ' '||i == STRLEN-1) {
					i++;
				}
				while (Str[i] == ' ' || i == STRLEN - 1) {
					i++;
				}
			}
		}
		if (Str[0] > 0 || Str[0] < 0) {
			scanf("%d", &InpNum);
		}
		if (InpNum > NumStr || InpNum <= 0) {
			printf("Помилка!!! , в масивi немає слова пiд таким номером\n");
			system("cls");
			main();
		}

		NumStr = 0;

		for (int i = 0; i <= STRLEN - 1; i++) {
			if (Str[i] != ' ') {
				NumStr++;
				if (NumStr == InpNum) {
					while (Str[i] != ' '|| i == STRLEN-1 ) {
						printf("%c", Str[i]);
						i++;
					}
				}

				while (Str[i] != ' ' || i == STRLEN - 1) {
					i++;
				}
				
			}
		}

	
		printf("\n");
		printf("Введiть 1 для повтору\n");
		scanf("%d", &YesNo);
		system("cls");
		if (YesNo == 1) {
			main();
		}
		else { return 0; }
}
