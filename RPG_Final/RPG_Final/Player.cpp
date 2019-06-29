#include "Player.h"
#include "Enemies.h"
#include "Inventory.h"
#include <iostream>
using std::cout;

double Player::L(int x)const {
	if (x == 0)
		return 100;
	return ((108 * x*x) - (60 * x) + 152);
}

double Player::P(int x)const {
	return pow(10, (log10(L(x)) - 2.5));
}

int Player::R(int x)const {
	return int(int(L(x) / P(x))*P(x));
}

int Player::E(int x)const {
	return int(R(x - 1) - R(x - 2));
}

Player::Player(char* namee) {
	name = new char[100];
	strcpy(name, namee);
	health = 100;
	maxHealth = 100;
	experience = 0;
	level = 1;
	attack = 0;
	defense = 0;
	nextLevelExp = E(2);
	equip = new Inventory[5];
	backpack = new Inventory[10];
	Inventory a("Health Potion");
	Inventory b("Health Potion");
	Inventory c("Short Sword", 'W', 0, 0, 0, 5, 0, 'S', 0);
	backpack[0] = c;
	backpack[1] = b;
	backpack[2] = a;
}

Player::~Player() {
	delete[]equip;
	delete[]backpack;
}

Player::Player(const Player & copy){
	name = new char[100];
	strcpy(name, copy.name);
	health = copy.health;
	maxHealth = copy.maxHealth;
	experience = copy.experience;
	level = copy.level;
	attack = copy.attack;
	defense = copy.defense;
	nextLevelExp = copy.nextLevelExp;
	equip = new Inventory[5];
	backpack = new Inventory[10];
	int i = 0;
	for (i = 0; i < 5; i++)
		equip[i] = copy.equip[i];
	for (i = 0; i < 10; i++)
		backpack[i] = copy.backpack[i];
}
/*
void Player::Display()const{
	cout << "What shall you do?\n		I - View Inventory\n		P - Proceed to next area.\n		U - Use item at slot #\n		D - Drop item at slot #\n		Q - Quit\n" << name << "\n----------------\n" << "Health: " << health << " / " << maxHealth << "\nLevel : " << level << "\nExperience : " << experience;
}
*/

bool Player::isAlive()const {
	if (health <= 0)
		return 0;
	return 1;
}

void Player::dropItem(int id) {
	id--;
	backpack[id] = Inventory("Empty");
}

void Player::equipItem(int id) {
	id--;
	Inventory& item = backpack[id];
	if (!strcmp(item.getname(), "Health Potion")) {
		if ((maxHealth - health) <= 25)
			health = maxHealth;
		else
			health += 25;
		item = Inventory("Empty");
	}
	else if (!strcmp(item.getname(), "Empty"))
		cout << "You cannot use an empty item. Please try again.\n";
	else if (item.getType() == 'H') {
		Inventory temp = equip[0];
		changeMaxHealth(item.getHealth());
		changeMaxHealth(-temp.getHealth());
		equip[0] = item;
		item = temp;
	}
	else if (item.getType() == 'B') {
		Inventory temp = equip[1];
		changeMaxHealth(item.getHealth());
		changeMaxHealth(-temp.getHealth());
		equip[1] = item;
		item = temp;
	}
	else if (item.getType() == 'F') {
		Inventory temp = equip[2];
		changeMaxHealth(item.getHealth());
		changeMaxHealth(-temp.getHealth());
		equip[2] = item;
		item = temp;
	}
	else if (item.getType() == 'W') {
		Inventory temp = equip[3];
		equip[3] = item;
		item = temp;
	}
	else if (item.getType() == 'T') {
		Inventory temp = equip[4];
		equip[4] = item;
		item = temp;
	}
}

bool Player::takeItem(Inventory item){
	int i = 0;
	int flag = 0;
	for (i = 0; i < 10; i++) {
		if (strcmp(backpack[i].getname(), "Empty"))
			continue;
		else {
			backpack[i] = item;
			flag = 1;
			break;
		}
	}
	if (!flag) {
		cout << "You do not have empty space in your inventory.";
		return 0;
	}
	return 1;
}


void Player::gainExp(int exp) {
	if (level == 25)
		experience = 0;
	else {
		if (exp + experience > nextLevelExp) {
			experience += exp - nextLevelExp;
			level++;
			nextLevelExp = E(level+1);
			maxHealth += 2;
			health = maxHealth;
			if (!(level % 5)) {
				attack += 2;
				defense += 1;
			}
		}
		else {
			experience += exp;
		}
	}
}

void Player::Display()const {
	cout << "=========================\n" << "Currently Equipped\n" << "=========================\n";
	cout << "\nHeadgear\n" << "---------------------------------\n";
	equip[0].Display();
	cout << "\nBody\n" << "---------------------------------\n";
	equip[1].Display();
	cout << "\nFootgear\n" << "---------------------------------\n";
	equip[2].Display();
	cout << "\nWeapon\n" << "---------------------------------\n";
	equip[3].Display();
	cout << "\nTalisman\n" << "---------------------------------\n";
	equip[4].Display();

	cout<<"\n\n=========================\n" << "Inventory\n" << "=========================\n";
	cout << "\nSlot #1\n" << "---------------------------------\n";
	backpack[0].Display();
	cout << "\nSlot #2\n" << "---------------------------------\n";
	backpack[1].Display();
	cout << "\nSlot #3\n" << "---------------------------------\n";
	backpack[2].Display();
	cout << "\nSlot #4\n" << "---------------------------------\n";
	backpack[3].Display();
	cout << "\nSlot #5\n" << "---------------------------------\n";
	backpack[4].Display();
	cout << "\nSlot #6\n" << "---------------------------------\n";
	backpack[5].Display();
	cout << "\nSlot #7\n" << "---------------------------------\n";
	backpack[6].Display();
	cout << "\nSlot #8\n" << "---------------------------------\n";
	backpack[7].Display();
	cout << "\nSlot #9\n" << "---------------------------------\n";
	backpack[8].Display();
	cout << "\nSlot #10\n" << "---------------------------------\n";
	backpack[9].Display();
}

char * Player::weaponName() const{
	return equip[3].getname();
}

Inventory Player::itemNameId(int id) const
{
	return equip[id];
}





int Player::getHealth()const {
	return health;
}
int Player::getMaxHealth()const {
	return maxHealth;
}
int Player::getExperience()const {
	return experience;
}
int Player::getLevel()const {
	return level;
}
int Player::getAttack()const {
	return attack;
}
int Player::getDefense()const {
	return defense;
}
int Player::getNextLevelExp()const {
	return nextLevelExp;
}



float Player::takeDamage(Enemy mob){
	RNG rngesus;
	float damagePhysical = 0;
	float damageMagical = 0;
	float damagePhysicalFinal = 0;
	float damageMagicalFinal = 0;
	char attack0 = 0;
	char attack1 = 0;
	int locationRoll = rngesus.pick(1, 100);
	int pick;
	if (between(locationRoll, 1, 25)) {
		pick = 0;
	}
	else if (between(locationRoll, 26, 85)) {
		pick = 1;
	}
	else if (between(locationRoll, 86, 100)) {
		pick = 2;
	}

	if (sizeof(mob.getattack()) / sizeof(mob.getattack()[0]) != 1) {
		damageMagical = (float)mob.getattack()[1];
		attack1 = 'M';
	}

	if (mob.getattacktype()[0] == 'M') {
		damageMagical = (float)mob.getattack()[0];
		attack0 = 'M';
	}
	else {
		damagePhysical = (float)mob.getattack()[0];
		attack0 = mob.getattacktype()[0];
	}

	if (equip[pick].getDefenseType() == 'L') {
		if ((attack0 == 'P') || (attack0 == 'S')) {
			damagePhysical *= (float)1.2;
		}
	}

	if (equip[pick].getDefenseType() == 'H') {
		if (attack0 == 'C') {
			damagePhysical *= (float)1.35;
		}
	}

	if (damageMagical != 0) {
		damageMagical = (float)fmax(1,damageMagical-(equip[pick].getMagicResistance()*defense));
	}

	if (equip[pick].getSpecial() == 'A') {
		damagePhysical = (float)mob.getattack()[0];
	}

	if (damagePhysical != 0) {
		damagePhysical = (float)fmax(1, damagePhysical-(equip[pick].getDefense() + defense));
	}

	damageMagicalFinal = damageMagical;
	damagePhysicalFinal = damagePhysical;

	if ((equip[pick].getSpecial() == 'E') && (rngesus.chance(15))) {
		if (equip[pick].getType() == 'T')
			damageMagicalFinal = 0;
		else
			damagePhysicalFinal=0;
	}
	int takenDamage = (int)(damageMagicalFinal + damagePhysicalFinal);
	health -= takenDamage;
	if (pick == 0) {
		if (mob.getattacktype()[0] == 'S')
			cout << mob.getname() << " attacks your Head with a Slashing attack for " << takenDamage << " damage!\n";
		if (mob.getattacktype()[0] == 'P')
			cout << mob.getname() << " attacks your Head with a Piercing attack for " << takenDamage << " damage!\n";
		if (mob.getattacktype()[0] == 'C')
			cout << mob.getname() << " attacks your Head with a Crushing attack for " << takenDamage << " damage!\n";
		if (mob.getattacktype()[0] == 'M')
			cout << mob.getname() << " attacks your Head with a Magic attack for " << takenDamage << " damage!\n";
	}
	if (pick == 1) {
		if (mob.getattacktype()[0] == 'S')
			cout << mob.getname() << " attacks your Body with a Slashing attack for " << takenDamage << " damage!\n";
		if (mob.getattacktype()[0] == 'P')
			cout << mob.getname() << " attacks your Body with a Piercing attack for " << takenDamage << " damage!\n";
		if (mob.getattacktype()[0] == 'C')
			cout << mob.getname() << " attacks your Body with a Crushing attack for " << takenDamage << " damage!\n";
		if (mob.getattacktype()[0] == 'M')
			cout << mob.getname() << " attacks your Body with a Magic attack for " << takenDamage << " damage!\n";
	}
	if (pick == 2) {
		if (mob.getattacktype()[0] == 'S')
			cout << mob.getname() << " attacks your Foot with a Slashing attack for " << takenDamage << " damage!\n";
		if (mob.getattacktype()[0] == 'P')
			cout << mob.getname() << " attacks your Foot with a Piercing attack for " << takenDamage << " damage!\n";
		if (mob.getattacktype()[0] == 'C')
			cout << mob.getname() << " attacks your Foot with a Crushing attack for " << takenDamage << " damage!\n";
		if (mob.getattacktype()[0] == 'M')
			cout << mob.getname() << " attacks your Foot with a Magic attack for " << takenDamage << " damage!\n";
	}
		
	return (damageMagicalFinal + damagePhysicalFinal);
}

void Player::Heal(int hup){
	health = (int)round(fmin(maxHealth, health+hup));
}

void Player::changeMaxHealth(int hp)
{
	if (health + hp > 0) {
		maxHealth += hp;
		health += hp;
	}
	else {
		maxHealth += hp;
		health = 1;
	}
}
