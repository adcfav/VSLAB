#define _CRT_SECURE_NO_WARNINGS															//��� �������� � ���������� ���������
#include "stdlib.h"
#include "stdio.h"
#include "math.h"
#include "locale.h"
#include "string.h"
#include "windows.h"
#define STRINGLEN 1000																	//���������� ������������� ������ ������

int main() {
	int Yes_No;
	char Str1[STRINGLEN];																//���������� ������ �������� ������
	setlocale(LC_CTYPE, "ukr");															//���� ������, ��� ���� ����������������� �������� ���������
	
	do {

		printf("����i�� �����:\n");
		memset(Str1, 0, sizeof Str1);													//�������� ������

		gets(Str1);																		//���������� ������

		OemToChar(Str1, Str1);	
		Str1[0] -= 32;																				//������������ ����� � ��������

		for (int i = 0; i < STRINGLEN - 1; i++) {
			if (Str1[i] == '.') {														//�������� �� �������� ������
				for (i += 1; i < STRINGLEN - 1; i++) {

					if ((Str1[i] != ' ') && (Str1[i] != '\0') && (Str1[i] != '.')) {	//�������� �������� ������ �� ��������
						Str1[i] -= 32;													//���� ����������� �������� ������
						break;															//������� ��������� ���������� 䳿

					}
				}
			}
		}
		int length = strlen(Str1);														//��������� ����� �����, �� � �������� �����
		
		for (int i = 0; i < length; i++) {
			printf("%c", Str1[i]);														//��������� ������
		}
		
		printf("\n����, ����i�� '1', ���� ������ ���������� ������������� ���������, �� ");
		printf("����-���� i���� ������ ��� �������: \n");
		scanf("%d", &Yes_No);
	} while (Yes_No == 1);																//�������� �� ����������� ������ � ��������� �� ����� �� ��
	return 0;
}
