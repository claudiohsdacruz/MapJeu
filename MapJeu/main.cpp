/****************************************************************************************
* Auteur	 : Claudio Henrique Soares da Cruz et Maimouna Sarah Diakité				*
* Nom		 : main.cpp																	*
* Date		 : 07 octobre 2022															*
* Description: Initialize et applique le contrôle général du jeu camouflage au pôle.	*
****************************************************************************************/

#include <iostream>
#include "map.hpp"
#include "camouflage.h"
#include "piece.h"

void main() {

	//initialize le jeu
	camouflage game;
	char reponse;

	//fait le contrôle du derroulement du jeu
	do
	{
		game.play();

		do
		{
			cout << endl << "Voulez-vous relancer le jeux ? (o / n) : ";
			cin >> reponse;

			if (tolower(reponse) == 'n')
			{
				cout << endl << "Merci d'avoir joue! Aurevoir!" << endl;
			}
			else
			{
				system("cls");
			}

		} while (tolower(reponse) != 'n' && tolower(reponse) != 'o');

	} while (tolower(reponse) != 'n');
	
	system("pause > 0");
}