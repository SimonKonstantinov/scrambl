#include <conio.h>
#include <string.h>
#include "stdio.h"
#include <iostream>
#include <locale>

using namespace std;

int *vvod(int &len);
void print(int *);
void autosinh_scr(int m, int n, int *mas, int len);
void additiv(int m, int n, int *mas, int len);
void autosinh_descr(int m, int n, int *mas, int len);
int *init_reg(int len, bool b);

int main()
{
	int m = 0, n = 0, len = 0;
	setlocale(LC_ALL, "Russian");
	cout << "Please, writer your sequence. Foe example 1111111100000000" << endl;

	int *mas = vvod(len);
	cout << "M:";
	cin >> m;
	cout << "N:";
	cin >> n;
	int variable;
	do {
		cout << "1) Auto scrambler \n2) Aditiv scrambler\n3) Auto descreambler \n4) Aditiv descrambler\n";
		cin >> variable;
	} while (variable != 1 && variable != 2 && variable != 3 && variable != 4);
	switch (variable) {
	case 1:
		autosinh_scr(m, n, mas, len);
		break;
	case 2:
		additiv(m, n, mas, len);
		break;
	case 3:
		autosinh_descr(m, n, mas, len);
		break;
	case 4:
		additiv(m, n, mas, len);
		break;
	}

	_getch();
	return 0;
}


int *vvod(int &len) {
	char *str = new char[100];
	cin >> str;
	len = strlen(str);
	int *mas = new int[len];
	for (int j = 0; j<len; j++) {
		mas[j] = str[j] - '0';
	}
	return mas;
}

void print(int *reg) {
	for (int j = 0; j <= sizeof(reg); j++) {
		printf("%i ", reg[j]);
	}
	printf("\n");
}

void autosinh_scr(int m, int n, int *mas, int len) {
	int q;
	int *reg = init_reg(m, true);
	for (int i = 0; i<len; i++) {
		q = (reg[m - 1] ^ reg[n - 1]) ^ mas[i];
		for (int j = 4; j>0; j--) {
			reg[j] = reg[j - 1];
		}
		reg[0] = q;
		printf("%i\t", q);
		print(reg);
	}
}

void additiv(int m, int n, int *mas, int len) {
	int q;
	int *reg = init_reg(m, false);
	for (int i = 0; i<len; i++) {
		q = (reg[m - 1] ^ reg[n - 1]);
		for (int j = 4; j>0; j--) {
			reg[j] = reg[j - 1];
		}
		reg[0] = q;
		q = q ^ mas[i];
		printf("%i\t", q);
		print(reg);
	}
}

int *init_reg(int len, bool b) {
	int *reg = new int[len];
	int m = len;
	if (b) {
		for (int i = 0; i<len; i++) {
			reg[i] = 0;
		}
	}
	else {
		do {
			cout << "Заполните " << m << " элементов:" << endl;
			reg = vvod(len);
			if (len != m) cout << "Error!" << endl;
		} while (len != m);
	}
	return reg;
}

void autosinh_descr(int m, int n, int *mas, int len) {
	int q; 
	int *reg = init_reg(m, true);
	for (int i = 0; i<len; i++) {
		q = (reg[m - 1] ^ reg[n - 1]) ^ mas[i];
		for (int j = 4; j>0; j--) {
			reg[j] = reg[j - 1];
		}
		reg[0] = mas[i];
		printf("%i\t", q);
	}
}