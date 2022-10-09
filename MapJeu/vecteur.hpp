/****************************************************************************************
* Auteur	 : Maimouna Sarah Diakité													*
* Nom		 : camouflage.h																*
* Date		 : 07 octobre 2022															*
* Description: Template d'un vecteur dynamique qui peut stocker tout type de données.	*
****************************************************************************************/

#pragma once
#include <assert.h>
#include <iostream>

using namespace std;

template <class TYPE> //Le mot TYPE sera utilisé pour
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
	void push_back(const TYPE& element);

	//Getter/setter
	int size()const;
	void resize(int newDim);

	TYPE& at(int pos)const;
	TYPE& operator[](int pos)const;

	template <class TYPE>
	friend void swap(vecteur<TYPE>& v1, vecteur<TYPE>& v2);
	void reverse();
	void reverseRecursive(int pos = 0);

	//Opérateurs
	
	const vecteur<TYPE>& operator=(const vecteur<TYPE>& v);
	bool operator==(const vecteur<TYPE>& v)const;
	vecteur<TYPE> operator+(const vecteur<TYPE>& v)const;
	const vecteur<TYPE>& operator+=(const vecteur<TYPE>& v);

};

template <class TYPE>
std::ostream& operator<<(std::ostream& sortie, const vecteur<TYPE>& v);

/// <summary>
/// Construit un vecteur vide
/// </summary>
/// <typeparam name="TYPE"></typeparam>

template <class TYPE>
vecteur<TYPE>::vecteur()
{
	_tab = nullptr;
	_dim = 0;

}

/// <summary>
/// Construit un vecteur de taille dynamique
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
///Permer d'effacer un vecteur
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
/// Permet d'afficher le contenu d'un vecteur
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
/// Permet d'afficher le contenu d'un vecteur
/// Elle réutilise la méthode print(...)
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
/// Permet d'ajouter des éléments à un vecteur
/// </summary>
/// <typeparam name="TYPE"></typeparam>
/// <param name="element"></param>

template <class TYPE>
void vecteur<TYPE>::push_back(const TYPE& element)
{							
	TYPE* _newTab = new TYPE[_dim + 1];										//Création de tableau temporaire avec un taille plus grande de 1
		
	for (int i = 0; i < _dim; i++)											//Affectation du contenu de l'ancien tableau au nouveau
	{
		*(_newTab + i) = *(_tab + i);
	}

	*(_newTab + _dim) = element;											//Ajout du nouvel élément au nouveau tableau

	delete[]_tab;													

	_tab = _newTab;															
	_dim++;																	

}

/// <summary>
/// Permet de récuperer la taille du vecteur
/// </summary>
/// <typeparam name="TYPE"></typeparam>
/// <returns></returns>

template <class TYPE>
int vecteur<TYPE>::size()const
{
	return _dim;
}

/// <summary>
/// Permet de change la taille d'un vecteur
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

	for (int i = 0; i < _dim && i < newDim; i++)	//copie les éléments pour le plus petit
	{												//des 2 tableaux
		*(newTab + i) = *(_tab + i);
	}

	delete[]_tab;
	_tab = newTab;
	_dim = newDim;
}

/// <summary>
/// Permet d'accéder à un élément du vecteur
/// </summary>
/// <typeparam name="TYPE"></typeparam>
/// <param name="pos">Positision de l'élément auquel on veut accéder</param>
/// <returns></returns>

template <class TYPE>
TYPE& vecteur<TYPE>::at(int pos)const
{
	assert(pos >= 0 && pos < _dim);

	return *(_tab + pos);
}

/// <summary>
/// Permet d'accéder à un élément du vecteur
/// </summary>
/// <typeparam name="TYPE"></typeparam>
/// <param name="pos">position de l'élément auquel onj veut accéder</param>
/// <returns></returns>

template <class TYPE>
TYPE& vecteur<TYPE>::operator[](int pos)const
{
	return at(pos);
}

/// <summary>
/// Permet d'affecter la valeur d'un vecteur à un autre
/// </summary>
/// <typeparam name="TYPE"></typeparam>
/// <param name="v">Vecteur que l'on veut affecter à un autre vecteur</param>
/// <returns></returns>

template <class TYPE>
const vecteur<TYPE>& vecteur<TYPE>::operator=(const vecteur<TYPE>& v)
{
	if (this == &v)		//affecte le vecteur à lui-même v=v;
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
/// permet de comparer deux vecteur (Vérifier si ils sont égaux)
/// </summary>
/// <typeparam name="TYPE"></typeparam>
/// <param name="v"></param>
/// <returns></returns>

template <class TYPE>
bool vecteur<TYPE>::operator==(const vecteur<TYPE>& v)const
{
	if (_dim != v._dim) 
	{
		return false;
	}

	for (int i = 0; i < _dim ; i++)
	{
		if (*(_tab + i) != *(v._tab + i))
		{
			return false;
		}
	}
	return true;

}

/// <summary>
/// Permet de concatener deux vecteurs
/// </summary>
/// <typeparam name="TYPE"></typeparam>
/// <param name="v"></param>
/// <returns></returns>

template <class TYPE>
vecteur<TYPE> vecteur<TYPE>::operator+(const vecteur<TYPE>& v)const
{
	int j = 0;
	vecteur<TYPE> newVecteur(v._dim + _dim);

	for (int i = 0; i < _dim; i++)							//Copie les éléments du premier vecteur
	{
		*(newVecteur._tab + i) = *(_tab + i);
	}

	for (int i = _dim; i < newVecteur._dim; i++)			//Copie les éléments du deuxième vecteur à la suite des autres
	{
		*(newVecteur._tab + i) = *(v._tab + j);
		j++;
	}

	return newVecteur;
}

/// <summary>
/// Permet de concatener deux vecteurs et d'affecter 
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
/// Permet d'échanger le contenu et l'adresse de deux vecteurs
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
/// Permet d'inverser l'ordre des éléments d'un vecteur
/// de façon itérative (ex:le dernier élément devient le premier)
/// </summary>
/// <typeparam name="TYPE"></typeparam>

template <class TYPE>
void vecteur<TYPE>::reverse()
{
	int j = _dim - 1;					//borne supérieur pour le swap

	for (int i = 0; i < _dim / 2; i++)	//pour la moitier du tableau
	{
		swap(*(_tab + i), *(_tab + j));
		j--;
	}
}

/// <summary>
/// Permet d'inverser l'ordre des éléments d'un vecteur
/// de façon récursive (ex:le dernier élément devient le premier)
/// </summary>
/// <typeparam name="TYPE"></typeparam>

template <class TYPE>
void vecteur<TYPE>::reverseRecursive(int pos)
{
	assert(pos >= 0 && pos <= _dim);
	if (pos == _dim / 2)
	{
		return;
	}

	swap(*(_tab + pos), *(_tab + _dim - pos - 1));

	reverseRecursive(pos + 1);
}