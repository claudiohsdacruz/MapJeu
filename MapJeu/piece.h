/****************************************************************************************
* Auteur	 : Claudio Henrique Soares da Cruz et Maimouna Sarah Diakit�				*
* Nom		 : piece.cpp																*
* Date		 : 07 octobre 2022															*
* Description: Les pi�ces sont represent�es par um map de char � deux dimension. Chaque *
*			   element de la pi�ce est identifier pour un char different: les espaces	*
*			   vides (' '), l'ours (O), le poisson (P) ou sans valeur ('\0'). Pour ce	*
*			   jeu on a deux pi�ces � deux case et quatre pi�ces � trois cases			*
****************************************************************************************/

#pragma once

//structure pour la case
struct casePiece {
	char valeur;																		//valeur de la case
	bool active;																		//�tat de la case
};

//Classe parent
class piece {

protected:
	char _nom;																			//Nom de la pi�ce
	casePiece _piece[2][2];																//cases de la pi�ce

public:
	//Getters
	char getNom()const;																	//R�cup�re le nom
	bool siValide(int ligne, int col)const;												//R�cup�re le valeur bool�enne de la case
	char getValeur(int ligne, int col)const;											//R�cup�re la valeur de la case
		
	//Setters
	void setNom(char nom);																//Change le nom de la pi�ce
	void setValeur(int ligne, int col, char valeur);									//Change la valeur d'une case

	//M�thodes
	void init(char nom, char valeur1, char valeur2, char valeur3, char valeur4);		//Permet d'initialiser une pi�ce
	void afficher(std::ostream& sortie) const;											//Permet d'afficher la pi�ce

	virtual void rotation() {};															
};
std::ostream& operator<<(std::ostream& sortie, const piece& p);							//Permet d'afficher la pi�ce

//Classes enfant
class piece2Cases : public piece {

public:
	piece2Cases();																		//Initialise la pi�ce � '\0'
	piece2Cases(char nom, char valeur1, char valeur2, char valeur3, char valeur4);		//Initailise la pi�ce en fonction des valeurs donn�e
	~piece2Cases();																		//R�initialise(d�truit) les pi�ces

	virtual void rotation();															//Fait tourner la pi�ce
};

class piece3Cases : public piece {

public:
	piece3Cases();																		//Initialise la pi�ce � '\0'
	piece3Cases(char nom, char valeur1, char valeur2, char valeur3, char valeur4);		//Initailise la pi�ce en fonction des valeurs donn�e
	~piece3Cases();																		//R�initialise(d�truit) les pi�ces

	virtual void rotation();															//Fait tourner la pi�ce
};