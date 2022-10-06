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
	string _nomMap;

public:
	void init();
	void initMap();
	void initPiece();
	void initSolution();

	bool isMatch(int noPiece, int ligne, int col);
	void putPiece(int noPiece, int i, int j);
	void removePiece(int noPiece, int ligne, int col);
	bool resolve(int noPiece = 0);
	void printSolution();
	void play();
};