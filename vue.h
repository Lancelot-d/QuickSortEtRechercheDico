#pragma once
#include <string>

using namespace std;

const int MAX_ARRAY_SIZE = 1000000;

void afficherTableau(int tab[], int taile);
void afficherMessage(string message);
int afficherMessageInput(string message);
int recupererLongueurTableau(string message);
int * afficherTableau(string message, int tailleChaine);
int afficherMenu();