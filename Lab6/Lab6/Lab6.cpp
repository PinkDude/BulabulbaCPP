// Lab6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <time.h>

int rekCount = 0;

int rek(int i) {
	rekCount++;
	if (i > 1) {
		return rek(i / 2) + rek(i / 3);
	}
	return 1;
}

void rekur(int n) {
	unsigned int start, end;
	start = clock();

	int res = rek(n);

	end = clock();

	std::cout << "The above code block was executed in " << (double)(end - start) / (double)1000 << " second(s)\n";
	std::cout << "Rekursion count = " << rekCount << "\n\n";
	rekCount = 0;
}

void iter(int n) {
	n++;
	clock_t start, end;
	start = clock();

	int *a = new int[n];
	a[0] = 1;

	for (int i = 1; i <= n; i++) {
		if (i / 2 > 1 && i / 3 > 1) {
			a[i] = a[i / 2] + a[i / 3];
		}
		else {
			a[i] = 1;
		}
	}

	end = clock();

	std::cout << "The above code block was executed in " << (double)(end - start) / (double)1000 << " second(s)\n";

	/*for (int i = 0; i < n; i++) {
		std::cout << i << ") " << a[i] << "\n";
	}*/
}

int GetN() {
	int n;
	while (true) {
		std::cout << "Input 'n'. (n > 1)\nn = ";
		std::cin >> n;
		if (n > 1)
			break;
	}
	std::cout << "\n";
	return n;
}

int main()
{
	int choose, n = GetN();
	bool exit = false;
	while (true) {
		std::cout << "Select func:\n1)Rekursion\n2)Iteration\n3)Change 'n'\n0)Exit\n";
		std::cin >> choose;
		std::cout << "\n";
		switch (choose)
		{
		case 1:
			rekur(n);
			break;
		case 2:
			iter(n);
			break;
		case 3:
			n = GetN();
			break;
		case 0:
			exit = true;
			break;
		default:;
			std::cout << "\nTakogo net! Ale!\n\n";
			break;
		}

		if (exit)
			break;
	}
}
