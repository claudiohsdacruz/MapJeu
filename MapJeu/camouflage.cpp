#include "camouflage.h"

void camouflage::init()
{
	//initMap();
	initPiece();
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
	_pieces[0] = new piece3Cases('U', ' ', 'P', 'O', '\0'); //instance de la pièce U
	_pieces[1] = new piece3Cases('V', 'P', ' ', 'O', '\0'); //instance de la pièce V
	_pieces[2] = new piece3Cases('W', ' ', 'O', 'P', '\0'); //instance de la pièce W
	_pieces[3] = new piece3Cases('X', 'P', 'P', '\0', '\0');//instance de la pièce X
	_pieces[4] = new piece3Cases('Y', 'P', 'O', '\0', '\0');//instance de la pièce Y
	_pieces[5] = new piece3Cases('Z', ' ', '\0', 'O', ' '); //instance de la pièce Z

	for (int i = 0; i < 6; i++)
		for (int r = 0; r < 4; r++)
		{
			_pieces[i]->afficher(cout);
			_pieces[i]->rotation();
			cout << endl;
		}
}

void camouflage::initSolution()
{

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			_solutionJeu[i][j] = "  ";
		}
	}
}

bool camouflage::isMatch(int noPiece, int i, int j) const
{

}

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
}