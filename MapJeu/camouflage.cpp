#include "camouflage.h"

void camouflage::initMap()
{
	string nomMap, nomFichier, solution;

	do
	{
		cout << endl << "Entrez le nom de la grille du jeu: ";
		cin >> nomMap;
		nomFichier = "map" + nomMap + ".txt";
	} while (!readFile(_mapJeu, nomFichier.c_str()));


}
