#include<conio.h>
#include<iostream>
#include<iomanip>
#include<cstdlib>
#include <string>
#include <cstdlib>
#include "vue.h"


using namespace std;

const int MENU_AUTO = 1;
const int MENU_MANUEL = 2;
const int MENU_QUITTER = 3;

void echange(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int * remplirTableau(int tailleTableau)
{
	static int tab[MAX_ARRAY_SIZE];
	string temp;
	afficherMessage("Voici les nombres dans votre tableau :");
	for (int i = 0; i < tailleTableau; i++)
	{
		tab[i] = rand() % tailleTableau;
		afficherMessage("numéros " + to_string(i + 1) + " : " + to_string(tab[i]));
	}
	cout << endl;
	return tab;
}

int echangePivot(int tab[], int pivBas, int pivHaut)
{
	int pivot = tab[pivHaut];
	int i = (pivBas - 1);

	for (int j = pivBas; j <= pivHaut - 1; j++)
	{
		if (tab[j] < pivot)
		{
			i++;
			echange(&tab[i], &tab[j]);
		}
	}
	echange(&tab[i + 1], &tab[pivHaut]);
	return (i + 1);
}

void triQuickSort(int tab[], int valBas, int valHaute)
{
	if (valBas < valHaute)
	{
		int valPiv = echangePivot(tab, valBas, valHaute);
		triQuickSort(tab, valBas, valPiv - 1);
		triQuickSort(tab, valPiv + 1, valHaute);
	}
}

int RechercheDico(int tab[], int min, int max, int ElemRecherche)
{
	if (min > max)
		return -1;
	int millieu = (min + max) / 2;
	if (ElemRecherche == tab[millieu])
		return millieu;
	else if (ElemRecherche < tab[millieu])
		return RechercheDico(tab, min, millieu - 1, ElemRecherche);
	else
		return RechercheDico(tab, millieu + 1, max, ElemRecherche);
}

int main()
{
	clock_t debut, fin;
	int choix = 0,tailleChaine, nombreAChercher,*tab,positionDansTableau;

	while (choix != MENU_QUITTER) {
		choix = afficherMenu();
		switch (choix)
		{
			case MENU_AUTO:
				tailleChaine = recupererLongueurTableau("Entrer la taille de votre tableau : (max = " + to_string(MAX_ARRAY_SIZE) + ")");
				tab = remplirTableau(tailleChaine);
				break;
			case MENU_MANUEL:
				tailleChaine = recupererLongueurTableau("Entrer la taille de votre tableau : (max =" + to_string(MAX_ARRAY_SIZE) + ")");
				tab = afficherTableau("Entrer les nombres qui le compose : ", tailleChaine);
				break;
			case MENU_QUITTER:
				return 0;
			default:
				tab = remplirTableau(0);
		}

		// QuickSort
		debut = clock();
		triQuickSort(tab, 0, tailleChaine - 1);
		fin = clock();
		afficherMessage("Chaine trie quickSort : ");
		afficherTableau(tab, tailleChaine);
		afficherMessage("Temps d'execution du quickSort = " + to_string(double(fin - debut)/double(CLOCKS_PER_SEC))+ "\n");


		//Recherche dichotomique
		nombreAChercher = afficherMessageInput("Quel chiffre voulez-vous rechercher ?");
		afficherMessage("Position dans le tableau : ");
		debut = clock();
		positionDansTableau = RechercheDico(tab, 0, tailleChaine - 1, nombreAChercher);
		fin = clock();
		if (positionDansTableau == -1)
			afficherMessage("	Nombre non trouvé");
		else
		{
			afficherMessage("	"+ to_string(positionDansTableau));
		}
		afficherMessage("Temps d'execution de la recherche dichotomique = " + to_string(double(fin - debut) / double(CLOCKS_PER_SEC)) + "\n");

		
		afficherMessage("\n\nAppuyer sur une touche pour continuer");
		_getch();
		system("CLS");
	}
}