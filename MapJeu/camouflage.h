/****************************************************************************************
* Auteur	 : Claudio Henrique Soares da Cruz et Maimouna Sarah Diakité				*
* Nom		 : camouflage.h																*
* Date		 : 07 octobre 2022															*
* Description: Classe du jeu camouflage au pôle											*
****************************************************************************************/

#pragma once
#include "map.hpp"
#include "vecteur.hpp"
#include "piece.h"
#include<iostream>


class camouflage {
private:
	map<char> _mapJeu;										//Map du jeu
	map<string> _solutionJeu;								//Map qui contient la solution trouvée pour la map donnée
	vecteur<piece*> _pieces;								//Vecteur qui contient les pièces à placer dans la map
	bool _solutionner;										//Pour vérifier si la solution à été trouvée
	string _nomMap;											//Nom de la map du jeu entrée par le joueur

public:
	void init();											//Initialise la map, les pièces, et la solution
	void initMap();											//Initialise la map
	void initPiece();										//Initialise la pièce
	void initSolution();									//Initialise la map de la solution
	
	void putPiece(int noPiece, int i, int j);				//Place la pièce dans la solution à l’index line et col reçu
	bool isMatch(int noPiece, int ligne, int col);			//Vérifie si la pièece est compatible avec la map à une certaine position
	void removePiece(int noPiece, int ligne, int col);		//Retire la pièce de la solution
	bool resolve(int noPiece = 0);							//Trouve la solution pour une map
	void printSolution();									//Fonctionnement du jeu entier
	void play();											//Afficher la solution trouvée
};