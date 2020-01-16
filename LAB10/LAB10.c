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
	setlocale(LC_ALL, "Ukr");
	Write(NULL,Sort(Input()));
	if (agrc == 3) {
		if (!strcmp(agrv[1], "-rf")) {
			printf("Програма приняла аргументи\n");
			Read(agrv[2]);
		}
		else if (!strcmp(agrv[1], "-wf")) {
			printf("Програма приняла аргументи\n");
			Write(agrv[2],Input());
		}
	}
	if (agrc == 2) {
		if (!strcmp(agrv[1], "-rf")) {
			printf("Програма приняла аргументи\n");
			Read(NULL);
		}
		else if (!strcmp(agrv[1], "-wf")) {
			printf("Програма приняла аргументи\n");
			Write(NULL, Input());
		}
	}
	printf("Програма введення інформації про готелі та сортування за зірками\n");

	printf("Бажаєте стоворити чи зчитати файл(1 - створити, 0 - зчитати, q - вийти з програми)");
	if (Ask(TRUE)) {
		Write(NULL,Input());
	}
	else {
		Read(NULL);
	}
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
				exit(-1);
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
	FILE* Fp;
	char Ch;

	if (Name == NULL) {
		Name = (char*)malloc(STRSIZE * sizeof(char));

		if (!Name) {
			printf("Помилка при виділенні памяті\n");
			printf("Спробувати знову?(1 - так, 0 - вихід)\n");
			if (Ask(FALSE)) {
				system("cls");
				main(1, 0);
			}
			else {
				return 0;
			}
		}

		printf("\nВведіть імя нового файлу\n");
		scanf("%*[^\n]");
		scanf("%20s", Name);
		scanf("%*[^\n]");

		if ((Fp = fopen(Name, "w+")) == NULL) {
			printf("Помилка створення файлу.\n");
			printf("Спробувати знову?(1 - так, 0 - вихід)\n");
			if (Ask(FALSE)) {
				system("cls");
				free(Name);
				free(Adress);
				main(1, 0);
			}
			else {
				return 0;
			}
		}
		free(Name);
	}
	else {
		if ((Fp = fopen(Name, "at")) == NULL) {
			printf("Помилка !!!\n");
			printf("Спробувати знову?(1 - так, 0 - вихід)\n");
			if (Ask(FALSE)) {
				system("cls");
				free(Adress);
				main(1, 0);
			}
			else {
				return 0;
			}
		}
	}
	int i = 0;
	int j = 0;
	while (*(Adress + i) != '\0') {
		if (*(Adress + i) == '$') {
			fputc(',', Fp);
			j++;
			if (j == 4) {
				fputc('\n', Fp);
				j = 0;
			}
		}
		else {
			fputc(*(Adress + i), Fp);
		}
		i++;
	}
	fclose(Fp);
	free(Adress);

	printf("Виконано, спробувати ще? 1-так 0-вихід\n");
	if (Ask(FALSE)) {
		system("cls");
		main(1, 0);
	}
	else {
		return 0;
	}
}

char* Input() {
	struct Hotel Buffer;
	char* Adress;
	int Row;

	printf("\nСкільки бажаєте ввести готелів(за замовчуванням 3)\n");

	if (!scanf("%d", &Row) || Row <= 0) {
		fflush(stdin);
		scanf("%*[^\n]");
		printf("Встановленно значення 3\n");
		Row = 3;
	}
	else {
		printf("Встановленно значення %d\n", Row);
	}

	Adress = (char*)malloc(sizeof(char) * STRUCTSIZE * Row + 4 * Row);

	if (!Adress) {
		printf("Брак памяті");
		system("pause");
		exit(-1);
	}

	
	*(Adress) = '\0';

	// Заповнення масиву
	for (int i = 0; i < Row; i++) {
		for (int j = 0; j < 4; j++) {
			switch (j) {
			case 0:
				printf("Введіть імя готелю                  ");
				scanf("%20s", Buffer.Name);
				scanf("%*[^\n]");
				break;
			case 1:
				printf("Введіть адресу                      ");
				scanf("%20s", Buffer.City);
				scanf("%*[^\n]");
				break;
			case 2:
				printf("Введіть кількість кімнат            ");
				scanf("%5s", Buffer.Rooms);
				scanf("%*[^\n]");
				for (int i = 0; i < 5; i++) {
					if (*(Buffer.Rooms + i) == '\0') {
						break;
					}
					if (!(strchr("1234567890", *(Buffer.Rooms + i)))) {
						printf("Програма приняла недопустимий символ, спробуйте ще\n");
						j--;
						break;
					}
				}
				break;
			case 3:
				printf("Введіть кількість зірок             ");
				scanf("%5s", Buffer.Stars);
				scanf("%*[^\n]");
				for (int i = 0; i < 5; i++) {
					if(*(Buffer.Stars + i) == '\0'){
						break;
					}
					if (*(Buffer.Stars + i) != '*'){
						printf("Програма приняла недопустимий символ, спробуйте ще\n");
						j--;
						break;
					}
				}
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

int Read(char* Name) {
	FILE* fp;
	char* Ch;
	if (Name == NULL) {
		Name = (char*)malloc(STRSIZE * sizeof(char));

		if (!Name) {
			printf("Помилка при виділенні памяті\n");
			printf("Спробувати ще? 1-так 0-вихід\n");
			if (Ask(FALSE)) {
				system("cls");
				main(1, 0);
			}
			else {
				return 0;
			}
		}

		printf("\nВведіть імя існуючого файлу\n");

		fgets(Name, STRSIZE, stdin);
		*(Name + strlen(Name) - 1) = '\0';
		fflush(stdin);
	}

	if ((fp = fopen(Name, "r")) == NULL) {
		printf("Помилка при відкритті файлу.\n");
		printf("Спробувати знову?(1 - так, 0 - вихід)\n");
		if (Ask(FALSE)) {
			system("cls");
			free(Name);
			main(1, 0);
		}
		else {
			return 0;
		}
	}
	else {
		printf("Назва: Адреса: Кімнати: Зірки:\n");
		while ((Ch = getc(fp)) != EOF) {
			putchar(Ch);
		}
	}
	fclose(fp);
	printf("Спробувати знову?(1 - так, 0 - вихід)\n");
	if (Ask(FALSE)) {
		system("cls");
		free(Name);
		main(1, 0);
	}
	else {
		return 0;
	}
}

