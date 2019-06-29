#pragma once
#include "Actors.h"
#include "Inventory.h"
#include "Enemies.h"
#include "RNG.h"

class Player : public Actor {
private:
	int health;
	int maxHealth;
	int experience;
	int level;
	int attack;
	int defense;
	int nextLevelExp;
	Inventory* equip;
	Inventory* backpack;
public:
	Player(char* namee);
	~Player();
	Player(const Player &copy);
	double L(int x)const;
	double P(int x)const;
	int R(int x)const;
	int E(int x)const;
	bool isAlive()const;
	void dropItem(int id);
	void equipItem(int id);
	bool takeItem(Inventory item);
	void gainExp(int exp);
	void Display()const;
	char* weaponName()const;
	Inventory itemNameId(int id)const;
	int getHealth()const;
	int getMaxHealth()const;
	int getExperience()const;
	int getLevel()const;
	int getAttack()const;
	int getDefense()const;
	int getNextLevelExp()const;
	float takeDamage(Enemy mob);
	void Heal(int hup);
	void changeMaxHealth(int hp);

};
