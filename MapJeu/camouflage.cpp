#include "camouflage.h"

//initialise la map, les 6 pi�ces et les autres propri�t�s
void camouflage::init()
{
	//initMap();
	initPiece();
	//initSolution();
}

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

void camouflage::initPiece()
{
	_pieces.resize(6);
	_pieces[0] = new piece3Cases('U', ' ', 'P', 'O', '\0'); //instance de la pi�ce U
	_pieces[1] = new piece3Cases('V', 'P', ' ', 'O', '\0'); //instance de la pi�ce V
	_pieces[2] = new piece3Cases('W', ' ', 'O', 'P', '\0'); //instance de la pi�ce W
	_pieces[3] = new piece2Cases('X', 'P', 'P', '\0', '\0');//instance de la pi�ce X
	_pieces[4] = new piece2Cases('Y', 'P', 'O', '\0', '\0');//instance de la pi�ce Y
	_pieces[5] = new piece3Cases('Z', ' ', '\0', 'O', ' '); //instance de la pi�ce Z

	for (int i = 0; i < 6; i++)
		for (int r = 0; r < 4; r++)
		{
			_pieces[i]->afficher(cout);
			_pieces[i]->rotation();
			cout << endl;
		}
}


//place la pi�ce dans la solution � l�index line et col re�u
void camouflage::placerPiece(int noPiece, int ligne, int col)
{
	piece piecePlace = *(_pieces[noPiece]);
	
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
		{	
			if (piecePlace.siValide(i, j)) {
				string casePiece;
				casePiece += piecePlace.getNom();
				casePiece += piecePlace.getValeur(i, j);
				cout << casePiece << endl;

				_solutionJeu[i + ligne][j + col] = casePiece;
			}
		}

}

//retire la pi�ce dans la solution � l�index line et col re�u (remet des espaces)
void camouflage::retirerPiece(int noPiece, int i, int j)
{
	piece pieceRetire = *(_pieces[noPiece]);

}

/*
bool camouflage::resoudre(int noPiece = 0)
{
	if (noPiece == 6) return true;
	
	for (int r = 0; r < 4; r++)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++) 
			{
				if (isMatch(noPiece, i, j))
					placerPiece(noPiece, i, j);
				if (resoudre(noPiece + 1))
					retirerPiece(noPiece, i, j);
			}
		}
		_pieces[noPiece]->rotation();
	}
	return false;
}*/