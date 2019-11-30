#define _CRT_SECURE_NO_WARNINGS
#include "stdlib.h"
#include "stdio.h"
#include "math.h"
#include "locale.h"
#include "string.h"
#include "windows.h"
#define STRLEN 1001

int main() {
	setlocale(LC_CTYPE, "ukr");
	char LowCh[] = "qwertyuiopasdfghjklzxcvbnmйцукенгшщзхїфівапролджєячсмитьбю";
	char Str[STRLEN];
	printf("Програма переводу у верхнiй регiстр букву пiсля крапки\n");
	printf("Ведiть рядок слiв(До 1000 символiв):\n");
	fgets(Str, STRLEN, stdin);

	for (int i = 0; i <= STRLEN - 1; i++) {
		if (Str[i] == '.') {
			for (i = i + 1; i < STRLEN - 1; i++) {
				if (strchr(LowCh, Str[i])) {
					Str[i] -= 32;
					break;
				}
			}
		}
	}

	puts(Str);
	system("pause");

	return 0;
}
