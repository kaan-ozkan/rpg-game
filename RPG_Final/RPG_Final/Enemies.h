#pragma once
#include"Actors.h"
#include "RNG.h"
using std::cout;

class Enemy : public Actor {
protected:
	int health;
	int* attack;
	char* attacktype;
	float* defense;
	char* defensetype;
	int drop;
	int Aweight;
	int Exp;
	int MPL;
public:
	Enemy() {
		name = new char[100];
		attack = new int[2];
		attack[0] = 0;
		attack[1] = 0;
		attacktype = new char[2];
		attacktype[0] = 'N';
		attacktype[1] = 'N';
		defense = new float[2];
		defense[0] = 0;
		defense[1] = 0;
		defensetype = new char[2];
		defensetype[0] = 'N';
		defensetype[1] = 'N';
	}
	Enemy(const char* name, int HP, int* A, char* Atype, float* D, char* Dtype, int drp, int W, int E, int M) : Actor(name) {
		health = HP;

		if ((strcmp(name, "Dragon") == 0)|| (strcmp(name, "Black Knight") == 0)|| (strcmp(name, "Dark Lord") == 0))
		{
			attack = new int[2];
			attacktype = new char[2];

			attack[0] = A[0];
			attacktype[0] = Atype[0];

			attack[1] = A[1];
			attacktype[1] = Atype[1];
		}
		else
		{
			attack = new int[1];
			attacktype = new char[1];

			*attack = A[0];
			*attacktype = Atype[0];
		}

		if ((strcmp(name, "Dragon") == 0)|| (strcmp(name, "Golem") == 0)|| (strcmp(name, "Dark Lord") == 0)|| (strcmp(name, "Necromancer") == 0))
		{
			defense = new float[2];
			defensetype = new char[2];

			defense[0] = D[0];
			defensetype[0] = Dtype[0];

			defense[1] = D[1];
			defensetype[1] = Dtype[1];
		}
		else
		{
			defense = new float[1];
			defensetype = new char[1];

			*defense = D[0];
			*defensetype = Dtype[0];
		}

		drop = drp;
		Aweight = W;
		Exp = E;
		MPL = M;
		
	}

	Enemy& operator = (const Enemy& copy) {
		strcpy(name,copy.name);

		health = copy.health;

		if ((strcmp(copy.name, "Dragon") == 0) || (strcmp(copy.name, "Black Knight") == 0) || (strcmp(copy.name, "Dark Lord") == 0))
		{
			attack[0] = copy.attack[0];
			attack[1] = copy.attack[1];

			attacktype[0] = copy.attacktype[0];
			attacktype[1] = copy.attacktype[1];
		}
		else
		{
			attack[0] = copy.attack[0];

			attacktype[0] = copy.attacktype[0];
		}

		if ((strcmp(name, "Dragon") == 0) || (strcmp(name, "Golem") == 0) || (strcmp(name, "Dark Lord") == 0) || (strcmp(name, "Necromancer") == 0))
		{
			defense[0] = copy.defense[0];
			defensetype[0] = copy.defensetype[0];

			defense[1] = copy.defense[1];
			defensetype[1] = copy.defensetype[1];
		}
		else
		{
			defense[0] = copy.defense[0];
			defensetype[0] = copy.defensetype[0];
		}

		drop = copy.drop;
		Aweight = copy.Aweight;
		Exp = copy.Exp;
		MPL = copy.MPL;

		return *this;
	}

	Enemy(const Enemy &E) {
		name = new char[100];

		strcpy(name, E.name);
		health = E.health;

		if ((strcmp(name, "Dragon") == 0) || (strcmp(name, "Black Knight") == 0) || (strcmp(name, "Dark Lord") == 0))
		{
			attack = new int[2];
			attacktype = new char[2];

			attack[0] = E.attack[0];
			attacktype[0] = E.attacktype[0];

			attack[1] = E.attack[1];
			attacktype[1] = E.attacktype[1];
		}
		else
		{
			attack = new int[1];
			attacktype = new char[1];

			*attack = E.attack[0];
			*attacktype = E.attacktype[0];
		}

		if ((strcmp(name, "Dragon") == 0) || (strcmp(name, "Golem") == 0) || (strcmp(name, "Dark Lord") == 0) || (strcmp(name, "Necromancer") == 0))
		{
			defense = new float[2];
			defensetype = new char[2];

			defense[0] = E.defense[0];
			defensetype[0] = E.defensetype[0];

			defense[1] = E.defense[1];
			defensetype[1] = E.defensetype[1];
		}
		else
		{
			defense = new float[1];
			defensetype = new char[1];

			*defense = E.defense[0];
			*defensetype = E.defensetype[0];
		}

		drop = E.drop;
		Aweight = E.Aweight;
		Exp = E.Exp;
		MPL = E.MPL;
	}

	~Enemy() {
		delete[] attack;
		delete[] attacktype;
		delete[] defense;
		delete[] defensetype;
	}

	int gethealth()const {
		return health;
	}
	int* getattack()const {
		return attack;
	}
	char* getattacktype()const {
		return attacktype;
	}
	float* getdefense()const {
		return defense;
	}
	char* getdefensetype()const {
		return defensetype;
	}
	int getdrop()const {
		return drop;
	}
	int getAweight()const {
		return Aweight;
	}
	int getExp()const {
		return Exp;
	}
	int getMPL()const {
		return MPL;
	}

	void sethealth(const int HP) {
		health = HP;
	}
	void setattack(const int* atk) {
		if ((strcmp(name, "Dragon") == 0) || (strcmp(name, "Black Knight") == 0) || (strcmp(name, "Dark Lord") == 0))
		{
			attack[0] = atk[0];
			attack[1] = atk[1];
		}
		else
		{
			attack[0] = atk[0];
		}
	}
	void setattacktype(const char* atktype) {
		if ((strcmp(name, "Dragon") == 0) || (strcmp(name, "Black Knight") == 0) || (strcmp(name, "Dark Lord") == 0))
		{
			attacktype[0] = atktype[0];
			attacktype[1] = atktype[1];
		}
		else
		{
			attacktype[0] = atktype[0];
		}
	}
	void setdefense(const float* def) {
		if ((strcmp(name, "Dragon") == 0) || (strcmp(name, "Golem") == 0) || (strcmp(name, "Dark Lord") == 0) || (strcmp(name, "Necromancer") == 0))
		{
			defense[0] = def[0];
			defense[1] = def[1];
		}
		else
		{
			defense[0] = def[0];
		}

	}
	void setdefensetype(const char* deftype) {
		if ((strcmp(name, "Dragon") == 0) || (strcmp(name, "Golem") == 0) || (strcmp(name, "Dark Lord") == 0) || (strcmp(name, "Necromancer") == 0))
		{
			defensetype[0] = deftype[0];
			defensetype[1] = deftype[1];
		}
		else
		{
			defensetype[0] = deftype[0];
		}
	}
	void setdrop(const int newd) {
		drop = newd;
	}
	void setAweight(const int newweight) {
		Aweight = newweight;
	}
	void setExp(const int newExp) {
		Exp = newExp;
	}
	void setMPL(const int newMPL) {
		MPL = newMPL;
	}

	void Display() const{
		cout << "Name: " << name << "\n";
		cout << "Health: " << health << "\n";
		if ((strcmp(name, "Dragon") == 0) || (strcmp(name, "Black Knight") == 0) || (strcmp(name, "Dark Lord") == 0))
		{
			cout << "Attack (1): " << attack[0] << " " << attacktype[0] << "\n";
			cout << "Attack (2): " << attack[1] << " " << attacktype[1] << "\n";
		}
		else
		{
			cout << "Attack: " << attack[0] << " " << attacktype[0] << "\n";
		}

		if ((strcmp(name, "Dragon") == 0) || (strcmp(name, "Golem") == 0) || (strcmp(name, "Dark Lord") == 0) || (strcmp(name, "Necromancer") == 0))
		{
			cout << "Deffense (1): " << defense[0] << " " << defensetype[0] << "\n";
			cout << "Deffense (2): " << defense[1] << " " << defensetype[1] << "\n";
		}
		else
		{
			cout << "Deffense: " << defense[0] << " " << defensetype[0] << "\n";
		}
		cout << "Drop: " << drop << "\n";
		cout << "Appear Weight: " << Aweight << "\n";
		cout << "Experience: " << Exp << "\n";
		cout << "MPL " << MPL << "\n";
	}
	
	bool isAlive() {
		if (health <= 0)
		{
			return 0;
		}

		else
		{
			return 1;
		}
	}
	
	int damage(float A, char Atype, char Special, char TSpecial)
	{
		RNG rngesus;
		int damage=0;

		if (((Special == 'C') || (TSpecial == 'C')) && rngesus.chance(25))
			A *= 2;
		if (((Special == 'D') || (TSpecial == 'D')) && rngesus.chance(25));
		else if ((strcmp(name, "Dragon") == 0) || (strcmp(name, "Dark Lord") == 0) || (strcmp(name, "Necromancer") == 0) || (strcmp(name, "Golem") == 0))
		{
			if (Atype == 'M') {
				A = (float)fmax(1, A - (defense[0] * defense[1]));
			}
			else if (Atype == 'S' && defensetype[0] == 'L') {
				A = (float)1.2*A;
				A = (float)fmax(1,A - defense[0]);
			}
			else if (Atype == 'P' && defensetype[0] == 'L') {
				A = (float)1.2*A;
				A = (float)fmax(1, A - defense[0]);
			}
			else if (Atype == 'C'&& defensetype[0] == 'H') {
				A = (float)1.35*A;
				A = (float)fmax(1, A - defense[0]);
			}
		}

		else
		{
			if (Atype == 'S' && defensetype[0] == 'L') {
				A = (float)1.2*A;
				A = (float)fmax(1, A - defense[0]);
			}
			else if (Atype == 'P' && defensetype[0] == 'L') {
				A = (float)1.2*A;
				A = (float)fmax(1, A - defense[0]);
			}
			else if (Atype == 'C'&& defensetype[0] == 'H') {
				A = (float)1.35*A;
				A = (float)fmax(1, A - defense[0]);
			}
		}
		damage = (int)A;
		health = health - damage;
		return damage;
	}
};