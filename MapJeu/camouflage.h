#pragma once
#include "map.hpp"
#include "vecteur.hpp"
#include "piece.h"
#include<iostream>


class camouflage {
private:
	map<char> _mapJeu;
	map<string> _solutionJeu;
	vecteur<piece*> _pieces;
	bool _solutionner;

public:
	void init();
	void initMap();
	void initPiece();
	void initSolution();

	bool isMatch(int noPiece, int ligne, int col);
	void placerPiece(int noPiece, int i, int j);
	void retirerPiece(int noPiece, int ligne, int col);
	bool resoudre(int noPiece = 0);
	void afficherLaSolution();
	void game();
};