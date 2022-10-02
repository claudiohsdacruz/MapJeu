


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


public:
	void init();
	void initMap();
	void initPiece();
};