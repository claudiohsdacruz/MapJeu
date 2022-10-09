/****************************************************************************************
* Auteur	 : Claudio Henrique Soares da Cruz et Maimouna Sarah Diakité				*
* Nom		 : piece.cpp																*
* Date		 : 07 octobre 2022															*
* Description: Les pièces sont representées par um map de char de deux dimension. Chaque*
*			   pièce  *
*			   peut avoir des espaces vides, representé par un ours (O), par un poisson *
*			   (P), ou sans valeur 
****************************************************************************************/

#include <iostream>
#include <cassert>
#include "Piece.h"
using namespace std;

//Méthodes de la classe Piece

/// <summary>
/// Permet de récupérer le nom de la pièce
/// </summary>
/// <returns></returns>
char piece::getNom()const
{
	return _nom;
}

/// <summary>
///	Permet de récupérer le valeur booléenne de la case
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
/// Permet de récupérer la valeur de la case
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
/// Permet de changer le nom de la pièce
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
/// Permet d'initialiser une pièce
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
/// Permet d'afficher la pièce
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
/// Permet d'afficher la pièce
/// </summary>
/// <param name="sortie"></param>
/// <param name="p"></param>
/// <returns></returns>
ostream& operator<<(ostream& sortie, const piece& p)
{
	p.afficher(sortie);
	return sortie;
}

//Méthodes de la classe Piece2Cases

/// <summary>
/// Initialise la pièce à '\0'
/// </summary>
piece2Cases::piece2Cases()
{
	init('\0', '\0', '\0', '\0', '\0');
}

/// <summary>
/// Initailise la pièce en fonction des valeurs donnée
/// </summary>
/// <param name="nom">Nom de la pièce</param>
/// <param name="valeur1">Valeur de la première case</param>
/// <param name="valeur2">Valeur de la deuxième case</param>
/// <param name="valeur3">Valeur de la troisième case</param>
/// <param name="valeur4">Valeur de la quatrième case</param>
piece2Cases::piece2Cases(char nom, char valeur1, char valeur2, char valeur3, char valeur4)
{
	init(nom, valeur1, valeur2, valeur3, valeur4);
}

/// <summary>
/// Réinitialise(détruit) les pièces
/// </summary>
piece2Cases::~piece2Cases()
{
	init('\0', '\0', '\0', '\0', '\0');
}

/// <summary>
/// Fait tourner la pièce
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

//Méthodes de la classe Piece3Cases

/// <summary>
/// Initialise la pièce à '\0'
/// </summary>
piece3Cases::piece3Cases()
{
	init('\0', '\0', '\0', '\0', '\0');
}

/// <summary>
/// Initailise la pièce en fonction des valeurs donnée
/// </summary>
/// <param name="nom">Nom de la pièce</param>
/// <param name="valeur1">Valeur de la première case</param>
/// <param name="valeur2">Valeur de la deuxième case</param>
/// <param name="valeur3">Valeur de la troisième case</param>
/// <param name="valeur4">Valeur de la quatrième case</param>
piece3Cases::piece3Cases(char nom, char valeur1, char valeur2, char valeur3, char valeur4)
{
	init(nom, valeur1, valeur2, valeur3, valeur4);
}

/// <summary>
/// Réinitialise(détruit) les pièces
/// </summary>
piece3Cases::~piece3Cases()
{
	init('\0', '\0', '\0', '\0', '\0');
}

/// <summary>
/// Fait tourner la pièce
/// </summary>
void piece3Cases::rotation()
{
	casePiece temp = _piece[0][0];
	_piece[0][0] = _piece[1][0];
	_piece[1][0] = _piece[1][1];
	_piece[1][1] = _piece[0][1];
	_piece[0][1] = temp;
}
