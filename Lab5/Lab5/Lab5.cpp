// Lab5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>

void func(int **mass, int str, int stol, void f(int **, int, int))
{
	for (int i = 0; i < stol; i ++) {
			f(mass, str, i);
	}
}

void func1(int **mass, int str, int stol) {
	int minIndex = 0, min = mass[0][stol];

	for (int j = 1; j < str; j++) {
		if (mass[j][stol] < min) 
		{
			min = mass[j][stol];
			minIndex = j;
		}
	}

	for (int j = minIndex + 1; j < str; j++) {
		mass[j][stol] = 0;
	}
}

void func2(int **mass, int str, int stol) {
	int sum = 0;
	for (int j = 0; j < str; j++) {
		if (mass[j][stol] > 0)
			sum += mass[j][stol];
	}
	std::cout << "Summ of positive elements =" << sum << "\n\n";
}

int main()
{
	int a1, b1;
	std::cout << "Please input size of first mass\n";
	while (true)
	{
		std::cout << "a = ";
		std::cin >> a1;
		if (a1 > 0)
			break;
	}
	while (true)
	{
		std::cout << "b = ";
		std::cin >> b1;
		if (b1 > 0)
			break;
	}

	int **mass1 = new int*[a1];
	for (int i = 0; i < a1; i++)
	{
		mass1[i] = new int[b1];
	}

	for (int i = 0; i < a1; i++) {
		for (int j = 0; j < b1; j++) {
			std::cout << "Input [" << i << "][" << j << "]: ";
			std::cin >> mass1[i][j];
		}
	}

	int a2, b2;
	std::cout << "Please input size of second mass\n";
	while (true)
	{
		std::cout << "a = ";
		std::cin >> a2;
		if (a2 > 0)
			break;
	}
	while (true)
	{
		std::cout << "b = ";
		std::cin >> b2;
		if (b2 > 0)
			break;
	}

	int **mass2 = new int*[a2];
	for (int i = 0; i < a2; i++)
	{
		mass2[i] = new int[b2];
	}

	for (int i = 0; i < a2; i++) {
		for (int j = 0; j < b2; j++) {
			std::cout << "Input [" << i << "][" << j << "]: ";
			std::cin >> mass2[i][j];
		}
	}

	std::cout << "\nYour first mass:\n";

	for (int i = 0; i < a1; i++) {
		for (int j = 0; j < b1; j++) {
			std::cout << mass1[i][j] << "\t";
		}
		std::cout << "\n";
	}

	std::cout << "Your second mass:\n";

	for (int i = 0; i < a2; i++) {
		for (int j = 0; j < b2; j++) {
			std::cout << mass2[i][j] << "\t";
		}
		std::cout << "\n";
	}

	std::cout << "\n";

	func(mass1, a1, b1, func1);
	func(mass2, a2, b2, func2);

	std::cout << "\nYour first mass:\n";

	for (int i = 0; i < a1; i++) {
		for (int j = 0; j < b1; j++) {
			std::cout << mass1[i][j] << "\t";
		}
		std::cout << "\n";
	}

	std::cout << "Your second mass:\n";

	for (int i = 0; i < a2; i++) {
		for (int j = 0; j < b2; j++) {
			std::cout << mass2[i][j] << "\t";
		}
		std::cout << "\n";
	}
}


