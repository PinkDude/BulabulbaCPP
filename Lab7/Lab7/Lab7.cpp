// Lab7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	FILE *file;

	fopen_s(&file, "test.txt", "r");

	char buf[8];

	fgets(buf, 8, file);

	int size = atoi(buf);

	char **mas = new char*[size-1];

	int n = 50;

	for (int i = 0; i < size - 1; i++) {
		mas[i] = (char *) malloc(n * sizeof(char));
		fgets(mas[i], n, file);
		cout << mas[i];
	}

	fclose(file);

	char word[2048];

	cin >> word;
	int len = strlen(word);
	char *p;

	for (int i = 0; i < size - 1; i++) {
		while ((p = strstr(mas[i], word)) != NULL)
		{
			strcpy_s(p, strlen(p), p + len);
		}
	}

	cout << "\n\n";

	for (int i = 0; i < size - 1; i++) {
		cout << mas[i];
	}
}
