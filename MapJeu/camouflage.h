/****************************************************************************************
* Auteur	 : Claudio Henrique Soares da Cruz	et Maimouna Sarah Diakit�				*
* Nom		 : camouflage.cpp															*
* Date		 : 07 octobre 2022															*
* Description: Le jeu camouflage au p�le consiste en placez les pi�ces sur le tableau	*
			   de sorte que tous les ours polaires reviennent sur leur banquise et les	*
			   poissons dans l�eau. Ce jeu comporte 6 pi�ces de puzzle transparentes et	*
			   48 formidables d�fis dedifficult� croissante.							*
****************************************************************************************/

#pragma once
#include "map.hpp"
#include "vecteur.hpp"
#include "piece.h"
#include<iostream>


class camouflage {
private:
	map<char> _mapJeu;										//Map du jeu
	map<string> _solutionJeu;								//Map qui contient la solution trouv�e pour la map donn�e
	vecteur<piece*> _pieces;								//Vecteur qui contient les pi�ces � placer dans la map
	bool _solutionner;										//Pour v�rifier si la solution � �t� trouv�e
	string _nomMap;											//Nom de la map du jeu entr�e par le joueur

public:
	void init();											//Initialise la map, les pi�ces, et la solution
	void initMap();											//Initialise la map
	void initPiece();										//Initialise la pi�ce
	void initSolution();									//Initialise la map de la solution
	
	void putPiece(int noPiece, int i, int j);				//Place la pi�ce dans la solution � l�index line et col re�u
	bool isMatch(int noPiece, int ligne, int col);			//V�rifie si la pi�ece est compatible avec la map � une certaine position
	void removePiece(int noPiece, int ligne, int col);		//Retire la pi�ce de la solution
	bool resolve(int noPiece = 0);							//Trouve la solution pour une map
	void printSolution();									//Fonctionnement du jeu entier
	void play();											//Afficher la solution trouv�e
};