#include "camouflage.h"

void camouflage::init()
{
	initMap();
	initPiece();
	initSolution();
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
	_pieces[5] = new piece3Cases('Z', ' ', '\0', 'O', ' ');//instanxe de la pi�ce Z

	//for (int i = 0; i < 6; i++)
	//	for (int r = 0; r < 4; r++)
	//	{
	//		_pieces[i]->afficher(cout);
	//		_pieces[i]->rotation();
	//		cout << endl;
	//	}
}


/// <summary>
/// place la pi�ce dans la solution � l�index line et col re�u
/// </summary>
/// <param name="noPiece"></param>
/// <param name="ligne"></param>
/// <param name="col"></param>
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

/// <summary>
/// Initialise la map de la solution
/// </summary>
void camouflage::initSolution()
{
	_solutionJeu.resize(4, 4);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			_solutionJeu[i][j] = "  ";
		}
	}
}

/// <summary>
/// V�rifie si la pi�ece est compatible avec la map � une certaine position
/// </summary>
/// <param name="noPiece"></param>
/// <param name="ligne"></param>
/// <param name="col"></param>
/// <returns></returns>
bool camouflage::isMatch(int noPiece, int ligne, int col)
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (_pieces[noPiece]->siValide(i,j))
			{
				if (ligne + i >= 4)
				{
					return false;
				}

				if (col + j >= 4)
				{
					return false;
				}

				if (_solutionJeu[i + ligne][j + col] != "  ")
				{
					return false;
				}

				if (_pieces[noPiece]->getValeur(i, j) == 'P' && _mapJeu[i + ligne][j + col] != 'E')
				{
					return false;
				}
				else if (_pieces[noPiece]->getValeur(i, j) == 'O' && _mapJeu[i + ligne][j + col] != 'B')
				{
					return false;
				}
				else if (_pieces[noPiece]->getValeur(i, j) == 'P' && _mapJeu[i + ligne][j + col] == 'I')
				{
					return false;
				}
				else if (_pieces[noPiece]->getValeur(i, j) == 'O' && _mapJeu[i + ligne][j + col] == 'I')
				{
					return false;
				}

			}
		}
	}
	
	return true;
}

/// <summary>
/// Retire la pi�ce de la solution
/// </summary>
/// <param name="noPiece"></param>
/// <param name="ligne"></param>
/// <param name="col"></param>
void camouflage::retirerPiece(int noPiece, int ligne, int col)
{
	_solutionJeu[ligne][col] = "  ";
}

bool camouflage::resoudre(int noPiece)
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