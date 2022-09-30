/****************************************************************************************
* Auteur	 : Claudio Henrique Soares da Cruz		 									*
* Nom		 : main.cpp																	*
* Date		 : 07 octobre 2022														*
* Description: Map du jeu Camouflage au pôle 													*
****************************************************************************************/

#include<iostream>
#include "map.hpp"
#include "camouflage.h"

void main() {

	
	camouflage game;

	game.initMap();
	/*
	cout << "Voulez-vous relancer le jeux ? (o / n) : ";
	cin >> finJeux;
	*/
	system("pause > 0");
}