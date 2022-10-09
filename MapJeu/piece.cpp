/****************************************************************************************
* Auteur	 : Claudio Henrique Soares da Cruz et Maimouna Sarah Diakit�				*
* Nom		 : piece.cpp																*
* Date		 : 07 octobre 2022															*
* Description: Les pi�ces sont represent�es par um map de char de deux dimension. Chaque*
*			   pi�ce  *
*			   peut avoir des espaces vides, represent� par un ours (O), par un poisson *
*			   (P), ou sans valeur 
****************************************************************************************/

#include <iostream>
#include <cassert>
#include "Piece.h"
using namespace std;

//M�thodes de la classe Piece

/// <summary>
/// Permet de r�cup�rer le nom de la pi�ce
/// </summary>
/// <returns></returns>
char piece::getNom()const
{
	return _nom;
}

/// <summary>
///	Permet de r�cup�rer le valeur bool�enne de la case
/// </summary>
/// <param name="ligne"></param>
/// <param name="col"></param>
/// <returns></returns>
bool piece::siValide(int ligne, int col)const
{
	assert(ligne >= 0 && ligne < 2);
	assert(col >= 0 && col < 2);

	return _piece[ligne][col].active;
}

/// <summary>
/// Permet de r�cup�rer la valeur de la case
/// </summary>
/// <param name="ligne"></param>
/// <param name="col"></param>
/// <returns></returns>
char piece::getValeur(int ligne, int col)const
{
	assert(ligne >= 0 && ligne < 2);
	assert(col >= 0 && col < 2);

	return _piece[ligne][col].valeur;
}

/// <summary>
/// Permet de changer le nom de la pi�ce
/// </summary>
/// <param name="nom"></param>
void piece::setNom(char nom)
{
	_nom = nom;
}

/// <summary>
/// Permet de changer la valeur d'une case
/// </summary>
/// <param name="ligne"></param>
/// <param name="col"></param>
/// <param name="valeur"></param>
void piece::setValeur(int ligne, int col, char valeur)
{
	assert(ligne >= 0 && ligne < 2);
	assert(col >= 0 && col < 2);
	assert(valeur == 'O' || valeur == 'P' || valeur == ' ' || valeur == '\0');

	_piece[ligne][col].valeur = valeur;
	_piece[ligne][col].active = (valeur != '\0') ? true : false;
}

/// <summary>
/// Permet d'initialiser une pi�ce
/// </summary>
/// <param name="nom"></param>
/// <param name="valeur1"></param>
/// <param name="valeur2"></param>
/// <param name="valeur3"></param>
/// <param name="valeur4"></param>
void piece::init(char nom, char valeur1, char valeur2, char valeur3, char valeur4)
{
	assert(valeur1 == 'O' || valeur1 == 'P' || valeur1 == ' ' || valeur1 == '\0');
	assert(valeur2 == 'O' || valeur2 == 'P' || valeur2 == ' ' || valeur2 == '\0');
	assert(valeur3 == 'O' || valeur3 == 'P' || valeur3 == ' ' || valeur3 == '\0');
	assert(valeur4 == 'O' || valeur4 == 'P' || valeur4 == ' ' || valeur4 == '\0');

	_nom = nom;
	setValeur(0, 0, valeur1);
	setValeur(0, 1, valeur2);
	setValeur(1, 0, valeur3);
	setValeur(1, 1, valeur4);
}

/// <summary>
/// Permet d'afficher la pi�ce
/// </summary>
/// <param name="sortie"></param>
void piece::afficher(ostream& sortie)const
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (_piece[i][j].active)
			{
				sortie << _nom << _piece[i][j].valeur << " ";
			}
		}
		cout << endl;
	}
}

/// <summary>
/// Permet d'afficher la pi�ce
/// </summary>
/// <param name="sortie"></param>
/// <param name="p"></param>
/// <returns></returns>
ostream& operator<<(ostream& sortie, const piece& p)
{
	p.afficher(sortie);
	return sortie;
}

//M�thodes de la classe Piece2Cases

/// <summary>
/// Initialise la pi�ce � '\0'
/// </summary>
piece2Cases::piece2Cases()
{
	init('\0', '\0', '\0', '\0', '\0');
}

/// <summary>
/// Initailise la pi�ce en fonction des valeurs donn�e
/// </summary>
/// <param name="nom">Nom de la pi�ce</param>
/// <param name="valeur1">Valeur de la premi�re case</param>
/// <param name="valeur2">Valeur de la deuxi�me case</param>
/// <param name="valeur3">Valeur de la troisi�me case</param>
/// <param name="valeur4">Valeur de la quatri�me case</param>
piece2Cases::piece2Cases(char nom, char valeur1, char valeur2, char valeur3, char valeur4)
{
	init(nom, valeur1, valeur2, valeur3, valeur4);
}

/// <summary>
/// R�initialise(d�truit) les pi�ces
/// </summary>
piece2Cases::~piece2Cases()
{
	init('\0', '\0', '\0', '\0', '\0');
}

/// <summary>
/// Fait tourner la pi�ce
/// </summary>
void piece2Cases::rotation()
{
	if (_piece[0][1].active)				//horizontal
		swap(_piece[0][1], _piece[1][0]);
	else {									//vertical
		casePiece temp = _piece[0][1];
		_piece[0][1] = _piece[0][0];
		_piece[0][0] = _piece[1][0];
		_piece[1][0] = temp;
	}
}

//M�thodes de la classe Piece3Cases

/// <summary>
/// Initialise la pi�ce � '\0'
/// </summary>
piece3Cases::piece3Cases()
{
	init('\0', '\0', '\0', '\0', '\0');
}

/// <summary>
/// Initailise la pi�ce en fonction des valeurs donn�e
/// </summary>
/// <param name="nom">Nom de la pi�ce</param>
/// <param name="valeur1">Valeur de la premi�re case</param>
/// <param name="valeur2">Valeur de la deuxi�me case</param>
/// <param name="valeur3">Valeur de la troisi�me case</param>
/// <param name="valeur4">Valeur de la quatri�me case</param>
piece3Cases::piece3Cases(char nom, char valeur1, char valeur2, char valeur3, char valeur4)
{
	init(nom, valeur1, valeur2, valeur3, valeur4);
}

/// <summary>
/// R�initialise(d�truit) les pi�ces
/// </summary>
piece3Cases::~piece3Cases()
{
	init('\0', '\0', '\0', '\0', '\0');
}

/// <summary>
/// Fait tourner la pi�ce
/// </summary>
void piece3Cases::rotation()
{
	casePiece temp = _piece[0][0];
	_piece[0][0] = _piece[1][0];
	_piece[1][0] = _piece[1][1];
	_piece[1][1] = _piece[0][1];
	_piece[0][1] = temp;
}
