#define _CRT_SECURE_NO_WARNINGS
#include "stdlib.h"
#include "stdio.h"
#include "math.h"
#include "locale.h"
#include "string.h"
#include "windows.h"
#define STRLEN 81

int main() {
	char Str[STRLEN][STRLEN];
	int YesNo = 0;
	int count = 0;
	int check = 0;
	setlocale(LC_CTYPE, "ukr");
	printf("�������� ������ ����� �� ���� �������\n");
	//do {
		for (int i = 0; i <= STRLEN - 1; i++) {
			for (int j = 0; j <= STRLEN - 1; j++) {
				Str[i][j] = ' ';
			}
		}
		printf("���i�� ����� ��i�(�� 100 ��i� �� 100 ����):\n");
		for (int i = 0; i <= STRLEN - 1; i++) {
			for (int j = 0; j <= STRLEN - 1;j++) {
				scanf("%c", &Str[i][j]);
				if (Str[i][j] == ' ') {
					break;
				}
				if (Str[i][j] == '\n') {
					YesNo = -1;
					break;
				}
			}
			if (YesNo == -1) {
				break;
			}
		}
		printf("����i�� ����� �������� ����� :\n");
		scanf("%d", &count);
		count--;
		if (count < 0 || count >= STRLEN) {
			printf("�������!!!\n");
			main();
		}
		
		for (int j = 0; j <= STRLEN - 1; j++) {
			printf("%c", Str[count][j]);
		}
		
	//	printf("\n");
	//	printf("����i�� 1 ��� �������\n");
	//	scanf("%d", &YesNo);
	//} while (YesNo == 1);
		getch();
		return 0;
}
