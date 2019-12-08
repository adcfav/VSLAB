#define _CRT_SECURE_NO_WARNINGS
#include "stdlib.h"
#include "stdio.h"
#include "math.h"
#include "locale.h"
#include "string.h"
#include "windows.h"
#define STRLEN 1001

int main() {
	char Str[STRLEN];
	int YesNo = 0;
	setlocale(LC_CTYPE, "ukr");
	printf("Програма виводу слова за його номером\n");
	do{
		int NumStr = 0;
		int InpNum = 0;
		for (int i = 0; i < STRLEN - 1; i++) {
			Str[i] = ' ';
		}
		printf("Ведiть рядок слiв(До 1000 символiв):\n");
		gets(Str);
		OemToChar(Str, Str);

		for (int i = 0; i <= STRLEN - 1; i++) {
			if (Str[i] != ' ') {
				NumStr++;
				while (Str[i] != ' ') {
					i++;
				}
			}
		}
		--NumStr;
		printf("Ведiть номер слова: \n(Cлiв в рядку %d) \n", NumStr);
		scanf("%d", &InpNum);

		if (InpNum>NumStr|| InpNum <= 0) {
			printf("Помилка!!!\n");
			main();
		}

		NumStr = 0;
		
		for (int i = 0; i <= STRLEN - 1; i++) {
			if (Str[i] != ' ') {
				NumStr++;
				if (NumStr == InpNum) {
					while (Str[i] != ' ') {
					printf("%c", Str[i]);
					i++;
					}
				}

				while (Str[i] != ' ') {
					i++;
				}
			}
		}
		
		printf("\n");
		printf("Введiть 1 для повтору\n");
		scanf("%d", &YesNo);
	} while (YesNo == 1);

	return 0;
}
