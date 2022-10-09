/****************************************************************************************
* Auteur	 : Claudio Henrique Soares da Cruz et Maimouna Sarah Diakité				*
* Nom		 : piece.cpp																*
* Date		 : 07 octobre 2022															*
* Description: Les pièces sont representées par um map de char à deux dimension. Chaque *
*			   element de la pièce est identifier pour un char different: les espaces	*
*			   vides (' '), l'ours (O), le poisson (P) ou sans valeur ('\0'). Pour ce	*
*			   jeu on a deux pièces à deux case et quatre pièces à trois cases			*
****************************************************************************************/

#pragma once

//structure pour la case
struct casePiece {
	char valeur;																		//valeur de la case
	bool active;																		//État de la case
};

//Classe parent
class piece {

protected:
	char _nom;																			//Nom de la pièce
	casePiece _piece[2][2];																//cases de la pièce

public:
	//Getters
	char getNom()const;																	//Récupère le nom
	bool siValide(int ligne, int col)const;												//Récupère le valeur booléenne de la case
	char getValeur(int ligne, int col)const;											//Récupère la valeur de la case
		
	//Setters
	void setNom(char nom);																//Change le nom de la pièce
	void setValeur(int ligne, int col, char valeur);									//Change la valeur d'une case

	//Méthodes
	void init(char nom, char valeur1, char valeur2, char valeur3, char valeur4);		//Permet d'initialiser une pièce
	void afficher(std::ostream& sortie) const;											//Permet d'afficher la pièce

	virtual void rotation() {};															
};
std::ostream& operator<<(std::ostream& sortie, const piece& p);							//Permet d'afficher la pièce

//Classes enfant
class piece2Cases : public piece {

public:
	piece2Cases();																		//Initialise la pièce à '\0'
	piece2Cases(char nom, char valeur1, char valeur2, char valeur3, char valeur4);		//Initailise la pièce en fonction des valeurs donnée
	~piece2Cases();																		//Réinitialise(détruit) les pièces

	virtual void rotation();															//Fait tourner la pièce
};

class piece3Cases : public piece {

public:
	piece3Cases();																		//Initialise la pièce à '\0'
	piece3Cases(char nom, char valeur1, char valeur2, char valeur3, char valeur4);		//Initailise la pièce en fonction des valeurs donnée
	~piece3Cases();																		//Réinitialise(détruit) les pièces

	virtual void rotation();															//Fait tourner la pièce
};