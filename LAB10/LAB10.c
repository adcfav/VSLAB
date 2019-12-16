#define _CRT_SECURE_NO_WARNINGS
#include "stdlib.h"
#include "stdio.h"
#include "math.h"
#include "locale.h"
#include "string.h"
#include "windows.h"
#define STRSIZE 21
#define SIZE 6
#define STRUCTSIZE 54
#define TRUE 1
#define FALSE 0

int Ask(int);
int Write(char*,char*);
int Read(char*);
char* Sort(char*);
char* Input();

struct Hotel {
	char Name[STRSIZE];
	char City[STRSIZE];
	char Rooms[SIZE];
	char Stars[SIZE];
};

int main(int agrc, char* agrv[])
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	Input();
	return 0;
}

int Ask(int Quit) {
	char Ch;
	int Status = FALSE;
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
				return FALSE;
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

int Write(char* Name,char* Adress) {

}

char* Input() {
	struct Hotel Buffer;
	char* Adress;
	int Row;

	printf("Скільки бажаєте ввести готелів(за замовчуванням 3)\n");

	if (!scanf("%d", &Row) || Row <= 0) {
		fflush(stdin);
		scanf("%*[^\n]");
		printf("Встановленно значення 3\n");
		Row = 3;
	}
	else {
		printf("Встановленно значення %d\n", Row);
	}

	Adress = (char*)malloc(sizeof(char) * STRUCTSIZE * Row + 4*Row);

	if (!Adress) {
		printf("Брак памяті");
		exit(-1);
	}

	*(Adress) = '\0';

	// Заповнення масиву
	for (int i = 0; i < Row; i++) {
		for (int j = 0; j < 4; j++) {
			switch (j) {
			case 0:
				printf("Введіть імя готелю %d         ", i + 1);
				scanf("%20s", Buffer.Name);
				scanf("%*[^\n]");
				break;
			case 1:
				printf("Введіть адресу               ");
				scanf("%20s", Buffer.City);
				scanf("%*[^\n]");
				break;
			case 2:
				printf("Введіть кількість кімнат     ");
				scanf("%5s", Buffer.Rooms);
				scanf("%*[^\n]");
				break;
			case 3:
				printf("Введіть кількість зірок      ");
				scanf("%5s", Buffer.Stars);
				scanf("%*[^\n]");
				break;
			}
		}

		for (int j = 0; j < 4; j++) {
			switch (j) {
			case 0:
				strcat(Adress, Buffer.Name);
    			
				break;
			case 1:
				strcat(Adress, Buffer.City);
				
				break;
			case 2:
				strcat(Adress, Buffer.Rooms);
				
				break;
			case 3:
				strcat(Adress, Buffer.Stars);
				
				break;
			}
			strcat(Adress, "$");
		}
	}
	return Adress;
}