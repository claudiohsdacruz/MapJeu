/****************************************************************************************
* Auteur	 : Claudio Henrique Soares da Cruz et Maimouna Sarah Diakit�				*
* Nom		 : piece.h																	*
* Date		 : 07 octobre 2022															*
* Description: Pi�ces utilis�e pour jouer au jeu camouflage au p�le						*
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