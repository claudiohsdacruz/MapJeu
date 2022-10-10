/****************************************************************************************
* Auteur	 : Claudio Henrique Soares da Cruz	et Maimouna Sarah Diakit�				*
* Nom		 : camouflage.cpp															*
* Date		 : 07 octobre 2022															*
* Description: Le jeu camouflage au p�le consiste en placez les pi�ces sur le tableau	*
			   de sorte que tous les ours polaires reviennent sur leur banquise et les	*
			   poissons dans l�eau. Ce jeu comporte 6 pi�ces de puzzle transparentes et	*
			   48 formidables d�fis dedifficult� croissante.							*
****************************************************************************************/

#include <fstream>
#include "camouflage.h"

/// <summary>
/// Initialise la map, les pi�ces, et la solution
/// </summary>
void camouflage::init()
{
	initMap();
	initPiece();
	initSolution();
}

/// <summary>
/// Initialise la map
/// </summary>
void camouflage::initMap()
{
	string nomFichier, solution;

	do
	{
		cout << endl << "Entrez le nom de la grille du jeu: ";
		cin >> _nomMap;
		nomFichier = "map" + _nomMap + ".txt";
	} while (!readFile(_mapJeu, nomFichier.c_str()));


}

/// <summary>
/// Initialise la pi�ce
/// </summary>
void camouflage::initPiece()
{
	_pieces.resize(6);
	_pieces[0] = new piece3Cases('U', ' ', 'P', 'O', '\0'); //instance de la pi�ce U
	_pieces[1] = new piece3Cases('V', 'P', ' ', 'O', '\0'); //instance de la pi�ce V
	_pieces[2] = new piece3Cases('W', ' ', 'O', 'P', '\0'); //instance de la pi�ce W
	_pieces[3] = new piece2Cases('X', 'P', 'P', '\0', '\0');//instance de la pi�ce X
	_pieces[4] = new piece2Cases('Y', 'P', 'O', '\0', '\0');//instance de la pi�ce Y
	_pieces[5] = new piece3Cases('Z', ' ', '\0', 'O', ' ');//instanxe de la pi�ce Z
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
/// place la pi�ce dans la solution � l�index line et col re�u
/// </summary>
/// <param name="noPiece"></param>
/// <param name="ligne"></param>
/// <param name="col"></param>
void camouflage::putPiece(int noPiece, int ligne, int col)
{
	assert(noPiece >= 0 && noPiece <= 6);
	assert(ligne >= 0 && ligne <= _solutionJeu.nbLine());
	assert(col >= 0 && col <= _solutionJeu.nbCol());

	piece piecePlace = *(_pieces[noPiece]);
	string casePiece;

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (piecePlace.siValide(i, j)) 
			{
				casePiece = piecePlace.getNom();
				casePiece += piecePlace.getValeur(i, j);
				_solutionJeu[i + ligne][j + col] = casePiece;
			}
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
	assert(noPiece >= 0 && noPiece <= 6);
	assert(ligne >= 0 && ligne <= _solutionJeu.nbLine());
	assert(col >= 0 && col <= _solutionJeu.nbCol());

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

				//Si position sur solutionJeu est egal � vide
				if (_solutionJeu[i + ligne][j + col] != "  ")
				{
					return false;
				}

				//Si piece est 'P' et position sur la map n'est pas 'E'
				if (_pieces[noPiece]->getValeur(i, j) == 'P' && _mapJeu[i + ligne][j + col] != 'E')
				{
					return false;
				}

				//Si piece est 'O' et position sur la map n'est pas 'B'
				if (_pieces[noPiece]->getValeur(i, j) == 'O' && _mapJeu[i + ligne][j + col] != 'B')
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
void camouflage::removePiece(int noPiece, int ligne, int col)
{
	assert(noPiece >= 0 && noPiece <= 6);
	assert(ligne >= 0 && ligne <= _solutionJeu.nbLine() );
	assert(col >= 0 && col <= _solutionJeu.nbCol());

	piece piecePlace = *(_pieces[noPiece]);
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (piecePlace.siValide(i, j)) 
			{
				_solutionJeu[i + ligne][j + col] = "  ";
			}
		}
	}
		
}

/// <summary>
/// Trouve la solution pour une map
/// </summary>
/// <param name="noPiece"></param>
/// <returns></returns>
bool camouflage::resolve(int noPiece)
{
	assert(noPiece >= 0 && noPiece <= 6);

	if (noPiece == 6)
	{
		return true;
	}		
	
	for (int r = 0; r < 4; r++)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++) 
			{
				//Si la pi�ce match avec la map du jeu il place la pi�ce sinon il retire la pi�ce
				if (isMatch(noPiece, i, j)) 
				{
					putPiece(noPiece, i, j);

					if (resolve(noPiece + 1))
					{
						return true;
					}
					else
					{
						removePiece(noPiece, i, j);
					
					}
				}	
			}
		}
		_pieces[noPiece]->rotation();
	}
	
	return false;
	
}

/// <summary>
/// Fonctionnement du jeu entier
/// </summary>
void camouflage::play()
{
	init();
	_solutionner = resolve();
	printSolution();
}

/// <summary>
/// Afficher la solution trouv�e
/// </summary>
void camouflage::printSolution()
{
	string nomFichier = "solution" + _nomMap + ".txt";

	ofstream fichier(nomFichier);
	
	if (_solutionner)
	{
		_solutionJeu.writeFile(fichier);
		readSolution(_solutionJeu, nomFichier.c_str());
	}
	else
	{
		cout << endl << "Il n'y a pas de solution pour cette map" << endl;
	}	
}