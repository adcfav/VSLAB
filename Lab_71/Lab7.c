#define _CRT_SECURE_NO_WARNINGS
#include "stdlib.h"
#include "stdio.h"
#include "math.h"
#include "locale.h"
#include "string.h"
#include "windows.h"
#include <Windows.h>
#include <conio.h>
#define MAXSIZE 50


int main(int agrc, char* agrv[]) {
	int* adress;
	int row, col, buffer = 0;
	int yes_no = 0;
	setlocale(LC_CTYPE, "ukr");
	SetConsoleCP(1251);													// ������������ ��������� ������
	SetConsoleOutputCP(1251);
	printf("������ ������ �������� ������ (�������� 50*50)\n");
	do {																// �������� ��������	
		printf("������ ������� ��������:\n");
		scanf("%d", &col);
		if (col <= 0 || col > MAXSIZE) {
			printf("������!!! ��������� ��\n");
		}
	} while (col <= 0 || col > MAXSIZE);
	do {																// �������� �����
		printf("������ ������� �����:\n");
		scanf("%d", &row);
		if (row <= 0 || row > MAXSIZE) {
			printf("������!!! ��������� ��\n");
		}
	} while (row <= 0 || row > MAXSIZE);


	adress = (int*)malloc(row * col * sizeof(int));							// �������� ���'��

	if (!adress) {														// �������� �� �������� ���'��
		printf("���� ���'��. \n");
		system("pause");
		system("cls");
		main(1, 0);
	}

	for (int i = 0; i < row; i++) {										// ���������� ������
		for (int j = 0; j < col; j++) {
			printf("�������[%d][%d] = ", i + 1, j + 1);
			scanf("%d", (adress + i * col + j));
			int k = (i * col + j) - 1;
			while (k >= 0) {
				if (*(adress + i * col + j) == *(adress + k)) {
					printf("� ����� ��� � ���� ����� !!! \n");
					j--;
					break;
				}
				k--;
			}
		}
	}

	printf("�������� �����:\n");

	for (int i = 0; i < row; i++) {										// ��������� ������ ��� ����������
		for (int j = 0; j < col; j++){
			printf("%10d", *(adress + i * col + j));
		}
		printf("\n");
	}

	for (int i = 0; i < row; i++) {										// ���������� ������
		for (int j = 0; j < col; j++) {
			int k = 0;
			while (k < col - 1) {
				if (*(adress + i * col + k) > * (adress + i * col + k + 1)) {
					buffer = *(adress + i * col + k + 1);
					*(adress + i * col + k + 1) = *(adress + i * col + k);
					*(adress + i * col + k) = buffer;
				}
				k++;
			}
		}
	}

	printf("���������� �����:\n");

	for (int i = 0; i < row; i++) {										// ��������� ����������� 
		for (int j = 0; j < col; j++)
		{
			printf("%10d ", *(adress + i * col + j));
		}
		printf("\n");
	}

	free(adress);														// ���������� ������� ���'��

	printf("��� ������� �������� 1\n");								// ������������ ��������
	scanf("%d", &yes_no);
	if (yes_no == 1) {
		system("cls");
		main(1, 0);
	}

	return 0;
}
