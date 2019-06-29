#pragma once
#include "Actors.h"

class Inventory: public Actor{
private:
	char type;
	int health;
	float defense;
	float magicresistance;
	int damage;
	char special;
	char damageType;
	char defenseType;
public:
	Inventory(int level);
	Inventory();
	Inventory(const char* namee);
	Inventory(const char* namee,char t, int h, float d, float mr, int dam, char sp,char damT,char defT);
	~Inventory() = default;
	Inventory(const Inventory &);
	Inventory& operator=(const Inventory &);
	int getHealth()const;
	float getDefense()const;
	float getMagicResistance()const;
	int getDamage()const;
	char getType()const;
	char getSpecial()const;
	char getDamageType()const;
	char getDefenseType()const;
	void Display()const;
};
