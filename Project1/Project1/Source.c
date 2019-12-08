#define _CRT_SECURE_NO_WARNINGS															//для сумісності с класичними функціями
#include "stdlib.h"
#include "stdio.h"
#include "math.h"
#include "locale.h"
#include "string.h"
#include "windows.h"
#define STRINGLEN 1000																	//визначення максимального розміру масиву

int main() {
	int Yes_No;
	char Str1[STRINGLEN];																//оголошення масиву заданого розміру
	setlocale(LC_CTYPE, "ukr");															//задає локаль, яка буде використовуватися поточною програмою
	
	do {

		printf("Введiть текст:\n");
		memset(Str1, 0, sizeof Str1);													//очищення масиву

		gets(Str1);																		//зчитування тексту

		OemToChar(Str1, Str1);	
		Str1[0] -= 32;																				//перетворення рядків в кирилицю

		for (int i = 0; i < STRINGLEN - 1; i++) {
			if (Str1[i] == '.') {														//перевірка на наявність крапки
				for (i += 1; i < STRINGLEN - 1; i++) {

					if ((Str1[i] != ' ') && (Str1[i] != '\0') && (Str1[i] != '.')) {	//перевірка елемента масиву на значення
						Str1[i] -= 32;													//зміна символьного елемента масиву
						break;															//зупинка виконання попередньої дії

					}
				}
			}
		}
		int length = strlen(Str1);														//присвоєння змінній числа, що є довжиною рядка
		
		for (int i = 0; i < length; i++) {
			printf("%c", Str1[i]);														//виведення масиву
		}
		
		printf("\nОтже, введiть '1', якщо хочете продовжити користуватися програмою, та ");
		printf("будь-який iнший символ для зупинки: \n");
		scanf("%d", &Yes_No);
	} while (Yes_No == 1);																//перевірка на продовження роботи з програмою чи вихід із неї
	return 0;
}
