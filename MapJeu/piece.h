
/**/


#pragma once



struct casePiece {
	char valeur;
	bool active;
};

//Classe parent
class piece {

protected:
	char _nom;							//
	casePiece _piece[2][2];				//

public:
	//Getters
	char getNom()const;
	bool siValide(int ligne, int col)const;
	char getValeur(int ligne, int col)const;


	//Setters
	void setNom(char nom);
	void setValeur(int ligne, int col, char valeur);

	//Méthodes
	void init(char nom, char valeur1, char valeur2, char valeur3, char valeur4);
	void afficher(std::ostream& sortie) const;

	virtual void rotation() {};
};
std::ostream& operator<<(std::ostream& sortie, const piece& p);

//Classes enfant
class piece2Cases : public piece {

public:
	piece2Cases();
	piece2Cases(char nom, char valeur1, char valeur2, char valeur3, char valeur4);
	~piece2Cases();

	virtual void rotation();
};

class piece3Cases : public piece {

public:
	piece3Cases();
	piece3Cases(char nom, char valeur1, char valeur2, char valeur3, char valeur4);
	~piece3Cases();

	virtual void rotation();
};