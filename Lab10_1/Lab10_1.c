#define _CRT_SECURE_NO_WARNINGS
#include "stdlib.h"
#include "stdio.h"
#include "math.h"
#include "locale.h"
#include "string.h"
#include "windows.h"
#define STRSIZE 10
#define TRUE 1
#define FALSE 0

int Ask(int);
int Write(char*);
int Read(char*);

struct Hotel {
	char Name[STRSIZE];
	char City[STRSIZE];
	char RoomNumber[5];
	char Stars[5];
};

int main(int agrc, char* agrv[]) {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	if (agrc == 3) {
		if (!strcmp(agrv[1], "-rf")) {
			printf("Програма приняла аргументи");
			Read(agrv[2]);
		}
		else if (!strcmp(agrv[1], "-wf")) {
			printf("Програма приняла аргументи");
			Write(agrv[2]);
		}
	}
	if (agrc == 2) {
		if (!strcmp(agrv[1], "-rf")) {
			printf("Програма приняла аргументи");
			Read(NULL);
		}
		else if (!strcmp(agrv[1], "-wf")) {
			printf("Програма приняла аргументи");
			Write(NULL);
		}
	}
	printf("Програма введення інформації про готелі (ширина поля для міста та назви 9,для кількості кімнат та зірок 4)\n");
	printf("Бажаєте стоворити чи зчитати файл(1 - створити, 0 - зчитати, q - вийти з програми)");
	if (Ask(TRUE)) {
		Write(NULL);
	}
	else {
		Read(NULL);
	}
	return 0;
}

int Ask(int Quit) {
	char Ch;
	int Status = FALSE;
	int Row;
	do {
		Ch = getch();
		switch (Ch) {
		case '1':
			Status = TRUE;
			return TRUE;
			break;
		case '0':
			Status = TRUE;
			return FALSE;
			break;
		case 'q':
			if (Quit == TRUE) {
				return -1;
			}
			else {
				printf("\nНе вірний ввід, спробуйте ще\n");
				Status = FALSE;
			}
			break;
		default:
			printf("\nНе вірний ввід, спробуйте ще\n");
			Status = FALSE;
			break;
		}
	} while (Status != TRUE);
}

int Write( char* Name) {
	FILE* fp;
	struct Hotel HotelBuff;
	char* Buffer = NULL;
	int Row;
	int StrucS = sizeof(struct Hotel) ;
	int StrS = sizeof(HotelBuff.Name) ;
	int ChS = sizeof(HotelBuff.Stars) ;

	if (Name == NULL) {

		Name = (char*)malloc(STRSIZE * sizeof(char));

		if (!Name) {														
			printf("Помилка при виділенні памяті\n");
			printf("Спробувати ще? 1-так 0-вихід\n");
			if (Ask(FALSE)) {
				Write(NULL);
			}
			else {
				return 0;
			}
		}

		printf("\nВведіть імя нового файлу\n");

		fgets(Name, STRSIZE, stdin);
		*(Name + strlen(Name) - 1) = '\0';
		fflush(stdin);
		
		if ((fp = fopen(Name, "w")) == NULL) {
			printf("Помилка при відкритті файлу.\n");
			printf("Спробувати ще? 1-так 0-вихід\n");
			if (Ask(FALSE)) {
				Write(NULL);
			}
			else {
				return 0;
			}
		}
	}
	else {
		if ((fp = fopen(Name, "w+")) == NULL) {
			printf("Помилка при відкритті файлу.\n");
			printf("Створити? 1-так 0-вихід\n");
			if (Ask(FALSE)) {
				Write(NULL);
			}
			else {
				return 0;
			}
		}
	}

	printf("Скільки бажаєте ввести готелів(за замовчуванням 3)\n");
	fflush(stdin);

	if (!scanf("%d", &Row)||Row <= 0) {
		fflush(stdin);
		scanf("%*[^\n]");
		printf("Встановленно значення 3\n");
		Row = 3;
	}
	else {
		printf("Встановленно значення %d\n", Row);
	}

	Buffer = (char*)malloc(Row * StrucS);	

	if (!Buffer) {														
		printf("Брак пам'яті. \n");
		system("pause");
		fclose(fp);
		exit(FALSE);
	}

	memset(&HotelBuff, ' ', StrucS);

	for (int i = 0; i < Row; i++) {
		for (int j = 0; j < 4; j++) {
			switch (j) {
			case 0:
				printf("Введіть імя готелю %d         ", i + 1);
				scanf("%9s", HotelBuff.Name);
				*(HotelBuff.Name + strlen(HotelBuff.Name)) = '$';
				scanf("%*[^\n]");
				break;
			case 1:
				printf("Введіть адресу               ");
				scanf("%9s", HotelBuff.City);
				*(HotelBuff.City + strlen(HotelBuff.City)) = '$';
				scanf("%*[^\n]");
				break;
			case 2:
				printf("Введіть кількість кімнат     ");
				scanf("%4s", HotelBuff.RoomNumber);
				*(HotelBuff.RoomNumber + strlen(HotelBuff.RoomNumber)) = '$';
				scanf("%*[^\n]");
				break;
			case 3:
				printf("Введіть кількість зірок      ");
				scanf("%4s", HotelBuff.Stars);
				*(HotelBuff.Stars + strlen(HotelBuff.Stars)) = '$';
				scanf("%*[^\n]");
				break;
			}	
		}
		printf("\n");
		strcpy(Buffer + StrucS * i, HotelBuff.Name);
		strcpy(Buffer + StrucS * i + StrS, HotelBuff.City);
		strcpy(Buffer + StrucS * i + StrS * 2, HotelBuff.RoomNumber);
		strcpy(Buffer + StrucS * i + StrS * 2 + ChS, HotelBuff.Stars);
		*(Buffer + StrucS * Row - 1) = '\n';
		memset(&HotelBuff, ' ', StrucS);
		puts(Buffer);
	}

	printf("Бажаэте продовжити чи записати данні в файл?(1 - записати та продовжити, 0 - записати та вийти, q - вийти з програми)\n");

	if (Ask(TRUE)) {
		for (int i = 0; i < Row; i++) {	
			for (int j = 0; j < StrucS - 1; j++) {
				if (*(Buffer + i * StrucS + j) == '$') {
					fprintf(fp, ",");
				}
				else {
					fputc(*(Buffer + i * StrucS + j), fp);
				}
			}
			fprintf(fp, "\n");
		}
		fclose(fp);
		free(Buffer);
		free(Name);
		main(1, 0);
	}
	else {
		for (int i = 0; i < Row; i++) {
			for (int j = 0; j < StrucS; j++) {
				if (*(Buffer + i * StrucS + j) == '$') {
					fprintf(fp, ",");
				}
				else {
					fputc(*(Buffer + i * StrucS + j), fp);
				}
			}
			fprintf(fp, "\n");
		}
		fclose(fp);
		free(Buffer);
		free(Name);
		main(1, 0);
	}
}

int Read(char* Name) {
	FILE* fp = NULL;
	char* Ch;
	if (Name == NULL) {

		Name = (char*)malloc(STRSIZE * sizeof(char));

		if (!Name) {
			printf("Помилка при виділенні памяті\n");
			printf("Спробувати ще? 1-так 0-вихід\n");
			if (Ask(FALSE)) {
				Read(NULL);
			}
			else {
				exit(FALSE);
			}
		}

		printf("\nВведіть імя існуючого файлу\n");

		fgets(Name, STRSIZE, stdin);
		*(Name + strlen(Name) - 1) = '\0';
		fflush(stdin);
	}
	if ((fp = fopen(Name, "r")) == NULL) {
		printf("Помилка при відкритті файлу.\n");
		printf("Створити файл? 1-так 0-вихід\n");
		if (Ask(FALSE)) {
			Write(NULL);
		}
		else {
			exit(FALSE);
		}
	}
	else {
		printf("Готель:Адреса:Кімнати:Зірки:\n");
		while ((Ch = getc(fp)) != EOF) {
		putchar(Ch);  
		}
	}
	fclose(fp);
	printf("Спробувати знову?(1 - так, 0 - створити файл та записати данні, q - вихід)\n");
	if (Ask(TRUE)) {
		Read(NULL);
	}
	else {
		Write(NULL);
	}
}
