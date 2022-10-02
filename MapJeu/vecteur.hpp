/*Auteur	: Maimouna Sarah Diakit�
* Date		: 09/09/2022
* Programme	: vecteur.hpp
* But		: Template d'un vecteur dynamique qui peut stocker tout type de donn�es
*/

#pragma once
#include <assert.h>
#include <iostream>

using namespace std;

template <class TYPE> //Le mot TYPE sera utilis� pour
class vecteur {
private:
	TYPE* _tab; //tableau du contenu du vecteur
	int _dim;	//taille du vecteur

public:
	//Constructeurs 
	vecteur();
	vecteur(int dim);

	//Destructeur
	~vecteur();
	void clear();

	//Constructeur de copie
	vecteur(const vecteur& v);

	void print(std::ostream& sortie)const;
	void push_back(int element);

	//Getter
	int size()const;

	//setter
	void resize(int newDim);

	//Methodes
	TYPE& at(int pos);
	template <class TYPE>
	friend void swap(vecteur<TYPE>& v1, vecteur<TYPE>& v2);
	void reverse();
	void reverseRecursive(int pos = 0);

	//Op�rateurs
	TYPE& operator[](int pos);
	const vecteur<TYPE>& operator=(const vecteur<TYPE>& v);
	bool operator==(const vecteur<TYPE>& v)const;
	vecteur<TYPE> operator+(const vecteur<TYPE>& v);
	const vecteur<TYPE>& operator+=(const vecteur<TYPE>& v);

};

template <class TYPE>
std::ostream& operator<<(std::ostream& sortie, const vecteur<TYPE>& v);

/// <summary>
/// Constructeur sans param�tre
/// </summary>
/// <typeparam name="TYPE"></typeparam>

template <class TYPE>
vecteur<TYPE>::vecteur()
{
	_tab = nullptr;
	_dim = 0;

}

/// <summary>
/// Constructeur avec param�tre
/// </summary>
/// <typeparam name="TYPE"></typeparam>
/// <param name="dim"></param>

template <class TYPE>
vecteur<TYPE>::vecteur(int dim)
{
	assert(dim >= 0);
	if (dim > 0)
	{
		_tab = new TYPE[dim];
	}
	else
	{
		_tab = nullptr;
	}

	_dim = dim;
}

/// <summary>
/// Destructeur
/// </summary>
/// <typeparam name="TYPE"></typeparam>

template <class TYPE>
vecteur<TYPE>::~vecteur()
{
	clear();
}

/// <summary>
/// Constructeur de copie
/// </summary>
/// <typeparam name="TYPE"></typeparam>
/// <param name="v"></param>

template <class TYPE>
vecteur<TYPE>::vecteur(const vecteur<TYPE>& v)
{
	if (v._dim == 0)
	{
		_tab = nullptr;
	}
	else
	{
		_tab = new TYPE[v._dim];
		for (int i = 0; i < v._dim; i++)
		{
			*(_tab + i) = *(v._tab + i);
		}
	}
	_dim = v._dim;
}

/// <summary>
/// M�thode qui permet d'afficher le contenu d'un vecteur
/// </summary>
/// <typeparam name="TYPE"></typeparam>
/// <param name="sortie"></param>

template <class TYPE>
void vecteur<TYPE>::print(ostream& sortie)const
{
	for (int i = 0; i < _dim; i++)
	{
		sortie << *(_tab + i) << " ";
	}
}

/// <summary>
/// Op�rateur qui permet d'afficher le contenu d'un vecteur
/// Elle r�utilise la m�thode print(...)
/// </summary>
/// <typeparam name="TYPE"></typeparam>
/// <param name="sortie"></param>
/// <param name="v"></param>
/// <returns></returns>

template <class TYPE>
ostream& operator<<(ostream& sortie, const vecteur<TYPE>& v)
{
	v.print(sortie);
	return sortie;
}

/// <summary>
/// M�thode qui permet d'ajouter des �l�ments � un vecteur
/// </summary>
/// <typeparam name="TYPE"></typeparam>
/// <param name="element"></param>

template <class TYPE>
void vecteur<TYPE>::push_back(int element)
{
	//Cr�ation de tableau temporaire avec un taille plus grande de 1
	TYPE* _newTab = new TYPE[_dim + 1];

	//Affectation du contenu de l'ancien tableau au nouveau
	for (int i = 0; i < _dim; i++)
	{
		*(_newTab + i) = *(_tab + i);
	}
	//Ajout du nouvel �l�ment au nouveau tableau
	*(_newTab + _dim) = element;

	//Suppression de l'ancien tableau
	delete[]_tab;

	//Affectation de l'adresse du nouveau tableau � l'ancien (ancien tableau = nouveau tableau)
	_tab = _newTab;
	//augmentation de la taille de l'ancien tableau
	_dim++;

}

/// <summary>
/// M�thode qui permet de r�cuperer la taille du vecteur
/// </summary>
/// <typeparam name="TYPE"></typeparam>
/// <returns></returns>

template <class TYPE>
int vecteur<TYPE>::size()const
{
	return _dim;
}

/// <summary>
/// M�thode pour changer la taille d'un vecteur
/// </summary>
/// <typeparam name="TYPE"></typeparam>
/// <param name="newDim"></param>

template <class TYPE>
void vecteur<TYPE>::resize(int newDim)
{
	assert(newDim >= 0);

	if (newDim == 0)
	{
		clear();
		return;
	}
	TYPE* newTab = new TYPE[newDim];

	for (int i = 0; i < _dim && i < newDim; i++)	//copie les �l�ments pour le plus petit
	{												//des 2 tableaux
		*(newTab + i) = *(_tab + i);
	}

	delete[]_tab;
	_tab = newTab;
	_dim = newDim;
}

/// <summary>
/// Methoe pour �ffacer un vecteur
/// </summary>
/// <typeparam name="TYPE"></typeparam>

template <class TYPE>
void vecteur<TYPE>::clear()
{
	delete[]_tab;
	_tab = nullptr;
	_dim = 0;
}

/// <summary>
/// M�thode pour acc�der � un �l�ment du vecteur
/// </summary>
/// <typeparam name="TYPE"></typeparam>
/// <param name="pos">Positision de l'�l�ment auquel on veut acc�der</param>
/// <returns></returns>

template <class TYPE>
TYPE& vecteur<TYPE>::at(int pos)
{
	assert(pos >= 0 && pos < _dim);

	return *(_tab + pos);
}

/// <summary>
/// op�rateur qui permet d'acc�der � un �l�ment du vecteur
/// </summary>
/// <typeparam name="TYPE"></typeparam>
/// <param name="pos">position de l'�l�ment auquel onj veut acc�der</param>
/// <returns></returns>

template <class TYPE>
TYPE& vecteur<TYPE>::operator[](int pos)
{
	return at(pos);
}

/// <summary>
/// Operateur qui permet d'affecter la valeur d'un vecteur � un autre
/// </summary>
/// <typeparam name="TYPE"></typeparam>
/// <param name="v">Vecteur que l'on veut affecter � un autre vecteur</param>
/// <returns></returns>

template <class TYPE>
const vecteur<TYPE>& vecteur<TYPE>::operator=(const vecteur<TYPE>& v)
{
	if (this == &v)		//affecte le vecteur � lui-m�me v=v;
		return *this;

	clear();
	if (v._dim > 0) {
		_dim = v._dim;
		_tab = new TYPE[v._dim];
		for (int i = 0; i < v._dim; i++)
		{
			*(_tab + i) = *(v._tab + i);
		}
	}
	return *this;
}

/// <summary>
/// Operateur qui permet de comparer deux vecteur (V�rifier si ils sont �gaux)
/// </summary>
/// <typeparam name="TYPE"></typeparam>
/// <param name="v"></param>
/// <returns></returns>

template <class TYPE>
bool vecteur<TYPE>::operator==(const vecteur<TYPE>& v)const
{
	if (_dim == 0 && v._dim == 0) //si les deux vecteurs sont vides (taille = 0 <=> vecteur vide)
	{
		return true;
	}

	for (int i = 0; i < _dim && i < v._dim; i++)
	{
		if (*_tab == *v._tab)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

}

/// <summary>
/// operateur qui permet de concatener deux vecteurs
/// </summary>
/// <typeparam name="TYPE"></typeparam>
/// <param name="v"></param>
/// <returns></returns>

template <class TYPE>
vecteur<TYPE> vecteur<TYPE>::operator+(const vecteur<TYPE>& v)
{
	int j = 0;
	vecteur<TYPE> newVecteur;
	newVecteur._dim = v._dim + _dim;
	newVecteur._tab = new TYPE[newVecteur._dim];

	for (int i = 0; i < _dim; i++)
	{
		*(newVecteur._tab + i) = *(_tab + i);
	}

	for (int i = _dim; i < newVecteur._dim; i++)
	{
		*(newVecteur._tab + i) = *(v._tab + j);
		j++;
	}

	return newVecteur;
}

/// <summary>
/// Operateur qui permet de concatener deux vecteurs et d'affecter 
/// la concatenation au vecteur implicite
/// </summary>
/// <typeparam name="TYPE"></typeparam>
/// <param name="v"></param>
/// <returns></returns>

template <class TYPE>
const vecteur<TYPE>& vecteur<TYPE>::operator+=(const vecteur<TYPE>& v)
{
	int ancienneDim = this->_dim;

	resize(ancienneDim + v._dim);

	for (int i = 0; i < _dim - ancienneDim; i++)
	{
		*(_tab + i + ancienneDim) = *(v._tab + i);
	}

	return *this;
}

/// <summary>
/// M�thode qui permet d'�changer le contenu et l'adresse de deux vecteurs
/// </summary>
/// <typeparam name="TYPE"></typeparam>
/// <param name="v1"></param>
/// <param name="v2"></param>

template <class TYPE>
void swap(vecteur<TYPE>& v1, vecteur<TYPE>& v2)
{
	TYPE* tempTab;
	int dim;

	tempTab = v1._tab;
	dim = v1._dim;

	v1._tab = v2._tab;
	v1._dim = v2._dim;

	v2._tab = tempTab;
	v2._dim = dim;
}

/// <summary>
/// M�thode qui permet d'inverser l'ordre des �l�ments d'un vecteur
/// de fa�on it�rative (ex:le dernier �l�ment devient le premier)
/// </summary>
/// <typeparam name="TYPE"></typeparam>

template <class TYPE>
void vecteur<TYPE>::reverse()
{
	int j = _dim - 1;					//borne sup�rieur pour le swap

	for (int i = 0; i < _dim / 2; i++)	//pour la moitier du tableau
	{
		swap(*(_tab + i), *(_tab + j));
		j--;
	}
}

/// <summary>
/// M�thode qui permet d'inverser l'ordre des �l�ments d'un vecteur
/// de fa�on r�cursive (ex:le dernier �l�ment devient le premier)
/// </summary>
/// <typeparam name="TYPE"></typeparam>

template <class TYPE>
void vecteur<TYPE>::reverseRecursive(int pos)
{

	if (pos == _dim / 2)
	{
		return;
	}

	swap(*(_tab + pos), *(_tab + _dim - pos - 1));

	reverseRecursive(pos + 1);
}