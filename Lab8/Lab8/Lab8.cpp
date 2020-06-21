// Lab8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <string.h>
#define MaxLength 9

using namespace std;

struct Element {
	char id[MaxLength];
	struct Element *sled;
};

void IncludeElement(Element **p, char t_id[]) {
	Element *pt, *k, *j;
	pt = (struct Element *)malloc(sizeof(Element));
	strcpy_s(pt->id, t_id);

	if (*p == NULL || strcmp(pt->id, (*p)->id) < 0) {
		pt->sled = *p;
		*p = pt;
	}
	else {
		k = *p;
		j = NULL;
		while (k != NULL && strcmp(pt->id, k->id) >= 0) {
			j = k;
			k = k->sled;
		}
		j->sled = pt;
		pt->sled = k;
	}
}

void PrintElements(Element *p) {
	Element *i;
	cout << "\nResults:\n";
	for (i = p; i != NULL; i = i->sled) {
		cout << i->id << "\n";
	}
}

void AllIdentWithLetter(int n, Element *p) {
	char let;
	cout << "Input letter\n";
	cin >> let;

	int count = 0;

	Element *j = p;
	for (int i = 0; i < n; i++, j = j->sled) {
		if (j->id[0] == let) {
			count++;
		}
	}

	cout << "Count == " << count << endl;
}

void After(int n, Element *p) {
	char *ident = new char[MaxLength];
	for (int o = 0; o < MaxLength; o++) {
		ident[o] = NULL;
	}
	cout << "Input identificator\n>>";
	cin >> ident;

	bool yes = false;
	for (Element *i = p; i != NULL; i = i->sled) {
		if (!yes) {
			if (strcmp(i->id, ident) == 0) {
				yes = true;
			}
			continue;
		}
		else {
			cout << i->id << endl;
		}
	}
}

void Before(int n, Element *p) {
	char *ident = new char[MaxLength];
	for (int o = 0; o < MaxLength; o++) {
		ident[o] = NULL;
	}
	cout << "Input identificator\n>>";
	cin >> ident;

	for (Element *j = p; j != NULL; j = j->sled) {
		if (strcmp(j->id, ident) == 0)
			break;
		cout << j->id << endl;
	}
}

int main()
{
	Element *p = NULL;
	int n, i;
	char t_id[MaxLength];

	cout << "Input identificator count\nn = ";
	cin >> n;

	cout << "Input identificators: \n";

	for (int i = 0; i < n; i++) {
		cin >> t_id;
		IncludeElement(&p, t_id);
	}

	PrintElements(p);


	int otv;
	bool exit = false;
	while (true) {
		cout << "\nSelect action:\n1) All identificators with letter\n2) After identificator\n3) Before identificator\n" << 
			"0) Exit\n";
		cin >> otv;
		cout << "\n";
		switch (otv)
		{
		case 1:
			AllIdentWithLetter(n, p);
			break;
		case 2:
			After(n, p);
			break;
		case 3:
			Before(n, p);
			break;
		case 0:
			exit = true;
			break;
		default:
			cout << "Plz input again...\n";
			break;
		}

		if (exit)
			break;
	}
}
