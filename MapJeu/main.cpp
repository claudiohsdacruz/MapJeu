/****************************************************************************************
* Auteur	 : Claudio Henrique Soares da Cruz		 									*
* Nom		 : main.cpp																	*
* Date		 : 07 octobre 2022														*
* Description: Map du jeu Camouflage au pôle 													*
****************************************************************************************/

#include <iostream>
#include "map.hpp"
#include "camouflage.h"
#include "piece.h"

void main() {

	
	camouflage game;
	
	game.init();
	game.resoudre();
	game.afficherLaSolution();
	
	/*
	cout << "3 Cases" << endl << endl;
	for (int r = 0; r < 4; r++) { //pour les 4 rotations
		for (int i = 0; i < piece.size(); i++)//pour chaque pièce
		{
			piece[r]->afficher(cout);
			cout << endl;
			piece[i]->rotation();
		}
		cout << endl;
	}
	
	
	*/

	/*
	cout << "Voulez-vous relancer le jeux ? (o / n) : ";
	cin >> finJeux;
	*/
	system("pause > 0");
}