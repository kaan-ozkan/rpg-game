#include "Inventory.h"
#include "RNG.h"
#include "Names.h"
using std::cout;

Inventory::Inventory(int level) {
	name = new char[100];
	RNG rngesus;
	damageType = 0;
	defenseType = 0;
	int typeInt=rngesus.pick(1, 100);
	if (between(typeInt,1,15))type = 'H'; if (between(typeInt, 16, 25))type = 'B'; if (between(typeInt, 26, 40))type = 'F'; if (between(typeInt, 41, 60))type = 'W'; if (between(typeInt, 61, 70))type = 'T'; if (between(typeInt, 71, 100))type = 'P';
	int rolledstat;

	if (type == 'H'||type=='B'||type=='F') {
		if (rngesus.chance(65)) {
			rolledstat = rngesus.pick(0, 1);
			if (rolledstat)
				health = rngesus.pick(1, 2 * level);
			else
				defense = rngesus.pick_float(1, 1 + level / (float)3.0);
		}
		else {
			health = rngesus.pick(1, 2 * level);
			defense = rngesus.pick_float(1, 1 + level / (float)3.0);
		}
	}
	if (type == 'W') {
		damage = rngesus.pick(6, 1 + 3 * level);
	}
	if (type == 'T') {
		if (rngesus.chance(65)) {
			rolledstat = rngesus.pick(0, 2);
			if (rolledstat)
				magicresistance = rngesus.pick_float(1,1+level/ (float)3.0);
			else if (rolledstat==1)
				magicresistance = rngesus.pick_float(0, level / (float)4.0);
			else
				damage = rngesus.pick(6, 1 + 3 * level);
		}
		else {
			int rolledstat2;
			rolledstat = rngesus.pick(0, 2);
			if (rolledstat)
				magicresistance = rngesus.pick_float(1, 1 + level / (float)3.0);
			else if (rolledstat == 1)
				magicresistance = rngesus.pick_float(0, level / (float)4.0);
			else
				damage = rngesus.pick(6, 1 + 3 * level);

			while ((rolledstat2 = rngesus.pick(0, 2)) == rolledstat);
			if (rolledstat2)
				magicresistance = rngesus.pick_float(1, 1 + level / (float)3.0);
			else if (rolledstat2 == 1)
				magicresistance = rngesus.pick_float(0, level / (float)4.0);
			else
				damage = rngesus.pick(6, 1 + 3 * level);
			
		}
	}

	int specialChance = rngesus.pick(0,9);
	if (specialChance == 4) {
		if (type == 'H' || type == 'B' || type == 'F') {
			do { specialChance = rngesus.pick(1, 100); } while (between(specialChance,1,15)||between(specialChance,31,61)||between(specialChance,86,100));
			if (between(specialChance, 16, 30))
				special = 'E';
			else if (between(specialChance, 61, 85))
				special = 'A';
		}
		if (type == 'T') {
			do { specialChance = rngesus.pick(1, 100); } while (between(specialChance, 61, 100));
			if (between(specialChance, 1, 15))
				special = 'C';
			if (between(specialChance, 16, 30))
				special = 'E';
			if (between(specialChance, 31, 60))
				special = 'D';
		}
		if (type == 'W') {
			do { specialChance = rngesus.pick(1, 100); } while (!(between(specialChance, 1, 15) || between(specialChance, 31, 61) || between(specialChance, 86, 100)));
			if (between(specialChance, 1, 15))
				special = 'C';
			if (between(specialChance, 31, 60))
				special = 'D';
			if (between(specialChance, 86, 100))
				special = 'L';
		}
	}
	int itemId;
	if (type == 'W') {
		itemId = rngesus.pick(0, 14);
		strcpy(name, Item_Names[itemId]);
		if (damage) {
			if (itemId == (0) || itemId == (1) || itemId == (5) || itemId == (6) || itemId == (7) || itemId == (8) || itemId == (13))
				damageType = 'S';
			if (itemId == (2) || itemId == (3) || itemId == (4) || itemId == (14))
				damageType = 'P';
			if (itemId == (9) || itemId == (10))
				damageType = 'C';
			if (itemId == (11) || itemId == (12))
				damageType = 'M';
		}
		
	}
	if (type == 'H') {
		itemId = rngesus.pick(15, 20);
		strcpy(name, Item_Names[itemId]);
		if (defense) {
			if (itemId == (16) || itemId == (18) || itemId == (19) || itemId == (20))
				defenseType = 'L';
			if (itemId == (17))
				defenseType = 'M';
			if (itemId == (15))
				defenseType = 'H';
		}
		

	}
	if (type == 'B') {
		itemId = rngesus.pick(21, 26);
		strcpy(name, Item_Names[itemId]);
		if (defense) {
			if (itemId == (21))
				defenseType = 'L';
			if (itemId == (22))
				defenseType = 'M';
			if (itemId == (23) || itemId == (24) || itemId == (25) || itemId == (26))
				defenseType = 'H';
		}
		
	}
	if (type == 'F') {
		itemId = rngesus.pick(27, 31);
		strcpy(name, Item_Names[itemId]);
		if (defense) {
			if (itemId == (27) || itemId == (30))
				defenseType = 'L';
			if (itemId == (31))
				defenseType = 'M';
			if (itemId == (28) || itemId == (29))
				defenseType = 'H';
		}
		
	}
	if (type == 'T') {
		itemId = rngesus.pick(32, 36);
		strcpy(name, Item_Names[itemId]);
		if (defense)
			defenseType = 'L';
		if (damage)
			damageType = 'M';
	}
	if (type == 'P') {
		strcpy(name, Item_Names[37]);
	}


}

Inventory::Inventory(const char* namee) {
	name = new char[100];
	if (!strcmp(namee, "Health Potion")) {
		type = 'P';
	}
	strcpy(name, namee);
	health = 0;
	defense = 0;
	magicresistance = 0;
	damage = 0;
	special = 0;
	damageType = 0;
	defenseType = 0;
}

Inventory::Inventory() {
	name = new char[100];
	strcpy(name, "Empty");
	type = 0;
	health = 0;
	defense = 0;
	magicresistance = 0;
	damage = 0;
	special = 0;
	damageType = 0;
	defenseType = 0;
}

Inventory::Inventory(const char* namee,char t,int h,float d,float mr,int dam,char sp,char damt, char defT) {
	name = new char[100];
	strcpy(name, namee);
	type = t;
	health = h;
	defense = d;
	magicresistance = mr;
	damage = dam;
	special = sp;
	damageType = damt;
	defenseType = defT;
}

int Inventory::getHealth()const {
	return health;
}
float Inventory::getDefense()const {
	return defense;
}
float Inventory::getMagicResistance()const {
	return magicresistance;
}
int Inventory::getDamage()const {
	return damage;
}
char Inventory::getType()const {
	return type;
}
char Inventory::getSpecial()const {
	return special;
}
char Inventory::getDamageType()const {
	return damageType;
}
char Inventory::getDefenseType()const {
	return defenseType;
}

void Inventory::Display()const {
	if (!strcmp(name, "Empty")) {
		cout << "Empty\n\n";
	}
	else {
		cout << name << "\n--------------\n";
		if (health)
			cout << "Health: " << health << "\n";
		if (damage)
			cout << "Damage: " << damage << "(" << damageType << ")\n";
		if (defense)
			cout << "Defense: " << defense << "(" << defenseType << ")\n";
		if (magicresistance)
			cout << "Magic Resistance: " << magicresistance << "\n";
		if (special) {
			char *specialName = new char[50];
			if (special == 'C')
				strcpy(specialName, "Critical Strike");
			if (special == 'E')
				strcpy(specialName, "Evasion");
			if (special == 'D')
				strcpy(specialName, "Ignore Defense");
			if (special == 'A')
				strcpy(specialName, "Imbued Armor");
			if (special == 'L')
				strcpy(specialName, "Life Leech");

			cout << "Special Type: " << specialName << "\n";
			delete[] specialName;
		}
	}
}

Inventory::Inventory(const Inventory &copy) {
	health = copy.health;
	defense = copy.defense;
	magicresistance = copy.magicresistance;
	damageType = copy.damageType;
	defenseType = copy.defenseType;
	damage = copy.damage;
	type = copy.type;
	special = copy.special;
	name = new char[100];
	strcpy(name, copy.name);
}

Inventory& Inventory::operator=(const Inventory &copy) {
	health = copy.health;
	defense = copy.defense;
	magicresistance = copy.magicresistance;
	damageType = copy.damageType;
	defenseType = copy.defenseType;
	damage = copy.damage;
	type = copy.type;
	special = copy.special;
	name = new char[100];
	strcpy(name, copy.name);
	return *this;
}

