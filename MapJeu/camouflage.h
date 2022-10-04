


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
	bool _solution;

public:
	void init();
	void initMap();
	void initPiece();
	void initSolution();

	bool isMatch(int noPiece, int i, int j) const;
	//void placerPiece(int noPiece, int i, int j);
	//void retirerPiece(int noPiece, int i, int j);
	bool resoudre(int noPiece, int i, int j);
};