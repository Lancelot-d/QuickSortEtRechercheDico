#include<conio.h>
#include<iostream>
#include<iomanip>
#include<cstdlib>
#include "vue.h"
#include <string>

using namespace std;

void afficherTableau(int tab[], int taile)
{
	int i;
	for (i = 0; i < taile; i++)
	{ 
		if (i % 10 == 0)
			cout << endl;
		cout << tab[i] << " ";
	}
	cout << endl << endl;
}

void afficherMessage(string message)
{
	cout << message << "\n";
}
int recupererLongueurTableau(string message)
{
	bool estValide = false;
	int input = NULL;

	while (estValide == false)
	{
		afficherMessage(message);
		cin >> input;
		if (input <= MAX_ARRAY_SIZE && input >= 0)
		{
			afficherMessage("");
			estValide = true;
			return input;
		}
	}
	return 1;
}
int afficherMessageInput(string message)
{
	int input = NULL;

	afficherMessage(message);
	cin >> input;
	afficherMessage("");
	return input;
}

int *afficherTableau(string message, int tailleChaine)
{
	static int tab[MAX_ARRAY_SIZE];
	string temp;
	afficherMessage(message);
	for (int i = 0; i < tailleChaine; i++)
	{
		temp = "numéros " + to_string(i+1) + " : ";
		tab[i] = afficherMessageInput(temp);
	}
	return tab;
}

int afficherMenu() {
	int choix;
	cout << endl << endl <<
		"Que voulez-vous faire?" << endl << endl <<
		"1 Remplissage automatique" << endl <<
		"2 Remplissage manuel" << endl <<
		"3 Quitter" << endl << endl<<
		"Votre choix : ";
	cin >> choix;
	cout << endl;
	return choix;
}
