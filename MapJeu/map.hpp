/****************************************************************************************
* Auteur	 : Claudio Henrique Soares da Cruz		 									*
* Nom		 : map.hpp																	*
* Date		 : 07 octobre 2022															*
* Description: Génère un map générique dynamyque à 2 dimensions	et avec un nom de map.	*									
****************************************************************************************/

#pragma once
#include<assert.h>
#include<iostream>
#include<iomanip> 
#include<fstream>
#include <sstream>

using namespace std;

template <class TYPE>
class map
{
private:
	char* _name;														//pointeur sur le nom de la map
	TYPE** _map;														//La map dynamique en ligne et colonne
	int _nbLine,														//nombre de ligne pour la matrice
		_nbCol;															//nombre de colonne pour la matrice
public:
	map();
	map(const char* name, int line = 0, int col = 0);
	~map();
	map<TYPE>(const map<TYPE>& map);
	void clear();														//clear la map et le nom
	void clearMap();													//clear la map et remet les dimensions à 0
	void clearName();													//clear le nom

	//getteurs / setteurs
	int nbLine()const;													//retourne le nb de ligne
	int nbCol()const;													//retourne le nb de colonne

	void resize(int nbLine, int nbCol);									//resize la matrice avec les nouv. dims
	TYPE& at(int posI, int posJ)const;									//retourne une référence à l’élément
																		////à la position i,j pour accéder ou modifier
	const char* getName()const;											//retourne le nom de la map
	void setName(const char* name);										//modifie le nom de la map
	void print(ostream& sortie)const;									//print la matrice (sans le nom)
	void writeFile(ostream& sortie) const;								//enregistre la matrice dans un fichier
	void read(istream& entree);											//lit la matrice de la map ds le flux

	const map<TYPE>& operator=(const map<TYPE>& map);					//operateur d'affectations
	TYPE*& operator[](int indline) const;								//operateur []
};
template<class TYPE>												
bool readFile(map<TYPE>& mapLue, const char* nomFichier);				//operateur pour lire un fichier

template<class TYPE>													
bool readSolution(map<TYPE>& mapLue, const char* nomFichier);			//lire le fichier solution

template <class TYPE> 
ostream& operator<<(ostream& sortie, const map<TYPE>& m);				//operateur de sortie

template <class TYPE> 
istream& operator>>(istream& entree, map<TYPE>& m);						//operateur d'entree

/// <summary>
/// constructeur sans paramétres
/// </summary>
/// <typeparam name="TYPE"></typeparam>
template<class TYPE>
inline map<TYPE>::map()
{
	_name = nullptr;
	_map = nullptr;
	_nbLine = 0,
	_nbCol = 0;
}

/// <summary>
/// constructeur avec paramétres
/// </summary>
/// <typeparam name="TYPE"></typeparam>
/// <param name="name"></param>
/// <param name="nbLine"></param>
/// <param name="nbCol"></param>
template<class TYPE>
inline map<TYPE>::map(const char* name, int nbLine, int nbCol)
{
	assert(nbLine >= 0 && nbCol >= 0);

	if (nbLine > 0 && nbCol > 0) {
		_nbLine = nbLine;
		_nbCol = nbCol;

		_map = new TYPE * [_nbLine];			//génère un vecteur de pointeur de dimension "nbLine"

		for (int i = 0; i < _nbLine; i++)		//génère "nbLine" vecteurs de pointeur de dimension "nbCol"
		{
			*(_map + i) = new TYPE[_nbCol];
		}
	}
	else {										//si "nbLine" = 0 et "nbCol" = 0, génère un map sans paramétre 
		_nbCol = _nbLine = 0;
		_map = nullptr;
	}
	setName(name);
}

/// <summary>
/// destructeur
/// </summary>
/// <typeparam name="TYPE"></typeparam>
template<class TYPE>
map<TYPE>::~map()
{
	clear();
}

/// <summary>
/// Constructeur de copie
/// </summary>
/// <typeparam name="TYPE"></typeparam>
/// <param name="mapCopie"></param>
template<class TYPE>
map<TYPE>::map<TYPE>(const map<TYPE>& mapCopie)
{
	assert(mapCopie._nbLine >= 0 && mapCopie._nbCol >= 0);

	if (mapCopie._nbLine > 0 && mapCopie._nbCol > 0) {
		_nbLine = mapCopie._nbLine;
		_nbCol = mapCopie._nbCol;

		_map = new TYPE * [_nbLine];
		for (int i = 0; i < _nbLine; i++)
		{
			*(_map + i) = new TYPE[_nbCol];
		}

		for (int i = 0; i < _nbLine; i++)
		{
			for (int j = 0; j < _nbCol; j++)
			{
				*(*(_map + i) + j) = *(*(mapCopie._map + i) + j);
			}
		}
	}
	else {								//si "nbLine" = 0 et "nbCol" = 0, génère un map sans paramétre 
		_nbCol = _nbLine = 0;
		_map = nullptr;
	}
	setName(mapCopie._name);
}


/// <summary>
/// clear la map et le nom
/// </summary>
/// <typeparam name="TYPE"></typeparam>
template<class TYPE>
void map<TYPE>::clear()
{
	clearMap();
	clearName();
}

/// <summary>
/// clear la map et remet les dimensions à 0
/// </summary>
/// <typeparam name="TYPE"></typeparam>
template<class TYPE>
void map<TYPE>::clearMap()
{
	for (int i = 0; i < _nbLine; i++)	//on delete les lignes du map avant de detruire le map
	{
		delete[] * (_map + i);
	}
	delete[]_map; //on delete le map

	_map = nullptr; //on met le map a null
	_nbLine = 0,
		_nbCol = 0;
}

/// <summary>
/// clear le nom
/// </summary>
/// <typeparam name="TYPE"></typeparam>
template<class TYPE>
void map<TYPE>::clearName()
{
	delete[]_name;
	_name = nullptr;
}

/// <summary>
/// retourne le nb de ligne
/// </summary>
/// <typeparam name="TYPE"></typeparam>
/// <returns></returns>
template<class TYPE>
int map<TYPE>::nbLine() const
{
	return _nbLine;
}

/// <summary>
/// retourne le nb de colonne
/// </summary>
/// <typeparam name="TYPE"></typeparam>
/// <returns></returns>
template<class TYPE>
int map<TYPE>::nbCol() const
{
	return _nbCol;
}

/// <summary>
/// resize la matrice avec les nouv. dims
/// </summary>
/// <typeparam name="TYPE"></typeparam>
/// <param name="nbLine"></param>
/// <param name="nbCol"></param>
template<class TYPE>
void map<TYPE>::resize(int nbLine, int nbCol)
{
	assert(nbLine >= 0 && nbCol >= 0);

	TYPE** newmap = nullptr;

	if (nbLine > 0 && nbCol > 0) {
		newmap = new TYPE * [nbLine];						//création d'une nouvelle map
		for (int i = 0; i < nbLine; i++)
		{
			*(newmap + i) = new TYPE[nbCol];
		}
		for (int i = 0; i < nbLine && i < _nbLine; i++)
		{
			for (int j = 0; j < nbCol && i < _nbCol; j++)
			{
				*(*(newmap + i) + j) = *(*(_map + i) + j);	//fait une copie de chaque élément de _map
			}
		}
	}
	else
		nbLine = nbCol = 0;

	clearMap();
	_map = newmap;
	_nbLine = nbLine;
	_nbCol = nbCol;
}

/// <summary>
/// retourne une référence à l’élément
/// </summary>
/// <typeparam name="TYPE"></typeparam>
/// <param name="posI"></param>
/// <param name="posJ"></param>
/// <returns></returns>
template<class TYPE>
TYPE& map<TYPE>::at(int posI, int posJ) const
{
	assert(posI >= 0 && posI < _nbLine);
	assert(posJ >= 0 && posJ < _nbCol);

	return *(*(_map + posI) + posJ);
}

/// <summary>
/// retourne le nom de la map
/// </summary>
/// <typeparam name="TYPE"></typeparam>
/// <returns></returns>
template<class TYPE>
const char* map<TYPE>::getName() const
{
	if (_name == nullptr) {
		return "\0";
	}
	return _name;
}

/// <summary>
/// modifie le nom de la map
/// </summary>
/// <typeparam name="TYPE"></typeparam>
/// <param name="name"></param>
template<class TYPE>
void map<TYPE>::setName(const char* name)
{
	clearName();

	int len = strlen(name);
	if (len != 0)
	{
		_name = new char[len + 1];
		strcpy_s(_name, len + 1, name);
	}
}

/// <summary>
/// operateur d'affichage
/// </summary>
/// <typeparam name="TYPE"></typeparam>
/// <param name="sortie"></param>
template<class TYPE>
void map<TYPE>::print(ostream& sortie) const
{
	assert(_map != nullptr);

	for (int i = 0; i < _nbLine; i++)
	{
		for (int j = 0; j < _nbCol; j++)
		{
			sortie << std::setw(4) << *(*(_map + i) + j) << " ";
		}
		sortie << endl;
	}
}

/// <summary>
/// enregistrement de la solution dans le fichier 
/// </summary>
/// <typeparam name="TYPE"></typeparam>
/// <param name="sortie"></param>
template<class TYPE>
void map<TYPE>::writeFile(ostream& sortie) const
{
	assert(_map != nullptr);

	sortie << _nbLine << "," << _nbCol << endl;

	for (int i = 0; i < _nbLine; i++)
	{
		for (int j = 0; j < _nbCol; j++)
		{
			if (j < (_nbCol - 1))
				sortie << *(*(_map + i) + j) << ",";
			else
				sortie << *(*(_map + i) + j);
		}
		//sortie << ",";
		sortie << endl;
	}
}

/// <summary>
/// operateur de sortie
/// </summary>
/// <typeparam name="TYPE"></typeparam>
/// <param name="sortie"></param>
/// <param name="m"></param>
/// <returns></returns>
template<class TYPE>
ostream& operator<<(ostream& sortie, const map<TYPE>& m)
{
	m.print(sortie);
	return sortie;
}

/// <summary>
/// operateur pour lire un fichier
/// </summary>
/// <typeparam name="TYPE"></typeparam>
/// <param name="entree"></param>
template<class TYPE>
void map<TYPE>::read(istream& entree)
{
	assert(_map != nullptr);
	for (int i = 0; i < _nbLine; i++)
	{
		for (int j = 0; j < _nbCol; j++)
		{
			entree >> *(*(_map + i) + j); // equivalent à this[i][j];
		}

	}
}

/// <summary>
/// operateur de afectation
/// </summary>
/// <typeparam name="TYPE"></typeparam>
/// <param name="mapCopie"></param>
/// <returns></returns>
template<class TYPE>
const map<TYPE>& map<TYPE>::operator=(const map<TYPE>& mapCopie)
{
	assert(mapCopie._nbLine >= 0 && mapCopie._nbCol >= 0);

	if (this == &mapCopie)
		return *this;

	if (mapCopie._nbLine > 0 && mapCopie._nbCol > 0) {
		_nbLine = mapCopie._nbLine;
		_nbCol = mapCopie._nbCol;

		_map = new TYPE * [_nbLine];
		for (int i = 0; i < _nbLine; i++)
		{
			*(_map + i) = new TYPE[_nbCol];
		}
		for (int i = 0; i < _nbLine; i++)
		{
			for (int j = 0; j < _nbCol; j++)
			{
				*(*(_map + i) + j) = *(*(mapCopie._map + i) + j);
			}
		}
	}
	else {
		_nbCol = _nbLine = 0;
		_map = nullptr;
	}
	setName(mapCopie._name);

	return *this;
}

/// <summary>
/// operateur []
/// </summary>
/// <typeparam name="TYPE"></typeparam>
/// <param name="indLine"></param>
/// <returns></returns>
template<class TYPE>
TYPE*& map<TYPE>::operator[](int indLine) const
{
	assert(indLine >= 0 && indLine < _nbLine);
	// // O: insérer une instruction return ici
	return *(_map + indLine);
}

/// <summary>
/// operator d'entree de données
/// </summary>
/// <typeparam name="TYPE"></typeparam>
/// <param name="entree"></param>
/// <param name="m"></param>
/// <returns></returns>
template<class TYPE>
istream& operator>>(istream& entree, map<TYPE>& m)
{
	m.read(entree);
	return entree;
}


/// <summary>
/// fonction d’ouverture du fichier contenant la matrice
/// </summary>
/// <typeparam name="TYPE"></typeparam>
/// <param name="mapLue"></param>
/// <param name="nomFichier"></param>
/// <returns></returns>
template<class TYPE>
bool readFile(map<TYPE>& mapLue, const char* nomFichier) {
	
	ifstream fichier(nomFichier); //ouverture du ficher
	int nbLine, nbCol;
	if (fichier.is_open())
	{
		mapLue.setName(nomFichier);
		fichier >> nbLine >> nbCol;
		mapLue.resize(nbLine, nbCol);
		cout << endl << "Contenu initiale de la grille de jeu ./MapJeu/" << nomFichier << " :" << endl << endl;
		fichier >> mapLue; //lecture de la matrice
		mapLue.print(cout);
		fichier.close();
		return true;
	}
	else
		cout << "Le Fichier : ./MapJeu/" << nomFichier << " n'existe pas. Veuillez recomencer." << endl;
	return false;
}

/// <summary>
/// lire le fichier solution
/// </summary>
/// <typeparam name="TYPE"></typeparam>
/// <param name="mapLue"></param>
/// <param name="nomFichier"></param>
/// <returns></returns>
template<class TYPE>
bool readSolution(map<TYPE>& mapLue, const char* nomFichier)
{
	ifstream fichier(nomFichier); //ouverture du ficher
	int nbLine, nbCol;
	char delimiter;
	string ligne;

	if (fichier.is_open())
	{
		mapLue.setName(nomFichier);
		fichier >> nbLine >> delimiter >> nbCol;
		mapLue.resize(nbLine, nbCol);
		cout << endl << "Contenu initiale de la grille de jeu ./MapJeu/" << nomFichier << " :" << endl << endl;
		delimiter = 13;
		while (getline(fichier, ligne, delimiter))
		{
			fichier >> ligne;
			//cout << ligne << endl;
		}
		//fichier >> mapLue; //lecture de la matrice
		mapLue.print(cout);
		fichier.close();
		return true;
	}
	else
		cout << "Le Fichier : ./MapJeu/" << nomFichier << " n'existe pas. Veuillez recomencer." << endl;
	return false;
}
