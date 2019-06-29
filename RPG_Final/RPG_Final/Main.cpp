#include <iostream>
#include "Inventory.h"
#include "Player.h"
#include "Events.h"
using std::cout;
using std::cin;

int main() {
	cout<<"Welcome to Dark Dungeons!\nThis game was made by Mehmet Kaan Ozkan and Mehmet Efe Zorlutuna\nHow many events will this adventure have ? ";
	int n;
	char name[100];
	do {
		cin >> n;
		std::cin.sync();
		std::cin.get();
		if (n < 1) {
			cout << "Please enter a number of events greater than zero.\n";
			cout<<"\nHow many events will this adventure have ? ";
		}
	} while (n < 1);
	
	cout << "What shall be the name of your hero ? ";
	cin.getline(name, 100);
	Player player(name);
	cout << "Arise " << player.getname() << "! Your adventure now begins...";
	int e;
	cout <<"\n======================================\n\n";

	for (e = 1; e <= n; e++) {
		cout << "\nTurn " << e << "\n";
		Events currentEvent(e, n, player.getLevel());
		int status = currentEvent.getStatus();
		char menu = 0;
		int slot;
		RNG rngesus;
		if (status == 0) {
			cout <<"\n"<< currentEvent.getDescription();
			while ((menu != 'P') && (menu != 'p')) {
				cout << "\n\nWhat shall you do?\n		I - View Inventory\n		P - Proceed to next area.\n		U - Use item at slot #\n		D - Drop item at slot #\n		Q - Quit\n" << name << "\n----------------\n" << "Health: " << player.getHealth() << " / " << player.getMaxHealth() << "\nLevel : " << player.getLevel() << "\nExperience : " << player.getExperience() << "\n\n> ";
				cin >> menu;
				if (menu == 'I' || menu == 'i') {
					player.Display();
				}
				else if (menu == 'U' || menu == 'u') {
					cin >> slot;
					std::cin.sync();
					std::cin.get();
					player.equipItem(slot);
				}
				else if (menu == 'D' || menu == 'd') {
					cin >> slot;
					std::cin.sync();
					std::cin.get();
					player.dropItem(slot);
				}
				else if (menu == 'Q' || menu == 'q') {
					cout << "\nThank you for playing, " << player.getname() << ".\n";
					system("PAUSE");
					return 0;
				}
				else if (menu == 'P' || menu == 'p') {
					break;
				}
				else {
					cout << "\nInvalid input, try again.\n";
				}
			}
		}
		if (status == 1) {
			cout << "\n"<< currentEvent.getDescription()<<"\n";
			Enemy enemy = currentEvent.getEnemy();
			cout << currentEvent.getMonsterDescription();
			while ((menu != 'Q') && (menu != 'q')) {
				cout << "\n\nWhat shall you do?\n		I - View Inventory\n		A - Attack the "<<enemy.getname()<<" with "<<player.weaponName()<<"\n		U - Use item at slot #\n		D - Drop item at slot #\n		Q - Quit\n" << name << "\n----------------\n" << "Health: " << player.getHealth() << " / " << player.getMaxHealth() << "\nLevel : " << player.getLevel() << "\nExperience : " << player.getExperience() << "\n\n> ";
				cin >> menu;
				if (menu == 'I' || menu == 'i') {
					player.Display();
				}
				else if (menu == 'A' || menu == 'a') {
					int attack = player.getAttack();
					if (player.itemNameId(3).getDamageType() == 'M')
						attack += player.itemNameId(3).getDamage() + player.itemNameId(4).getDamage();
					else
						attack += player.itemNameId(3).getDamage();
					int enemyDamage = enemy.damage((float)attack, player.itemNameId(3).getDamageType(), player.itemNameId(3).getSpecial(), player.itemNameId(4).getSpecial());
					cout << "\nYou've dealt "<<enemyDamage<<" damage!\n";
					if (player.itemNameId(3).getSpecial() == 'L')
						player.Heal(enemyDamage);
					if (!enemy.isAlive()) {
						cout << "You have killed the " << enemy.getname() << "!\n";
						player.gainExp(enemy.getExp());
						if (rngesus.chance(enemy.getdrop())) {
							status = 3;
							cout << "The "<<enemy.getname()<<" has dropped an item!\n";
							break;
						}
						status = -1;
						break;
					}

					player.takeDamage(enemy);
					
					if (!player.isAlive()) {
						cout << "You have died! Game over. Thanks for playing.\n";
						system("PAUSE");
						return 1;
					}
					
				}
				else if (menu == 'U' || menu == 'u') {
					cin >> slot;
					std::cin.sync();
					std::cin.get();
					player.equipItem(slot);
				}
				else if (menu == 'D' || menu == 'd') {
					cin >> slot;
					std::cin.sync();
					std::cin.get();
					player.dropItem(slot);
				}
				else if (menu == 'Q' || menu == 'q') {
					cout << "\nThank you for playing, " << player.getname() << ".\n";
					system("PAUSE");
					return 0;
				}
				else {
					cout << "\nInvalid input, try again.\n";
				}
			}
		}
		if ((status == 2)||status==3) {
			Inventory item(player.getLevel());
			if (status ==2) {
				cout << "\n" << currentEvent.getDescription();
				item = currentEvent.getInventory();
			}	
				
			cout << "\nYou have found a " << item.getname() << "!\n";
			while ((menu != 'P') && (menu != 'p')) {
				cout << "\n\nWhat shall you do?\n		I - View Inventory\n		P - Proceed to next area.\n		T- Take " << item.getname() << "\n		E- Examine " << item.getname() << "\n		U - Use item at slot #\n		D - Drop item at slot #\n		Q - Quit\n" << name << "\n----------------\n" << "Health: " << player.getHealth() << " / " << player.getMaxHealth() << "\nLevel : " << player.getLevel() << "\nExperience : " << player.getExperience() << "\n\n> ";
				cin >> menu;
				if (menu == 'I' || menu == 'i') {
					player.Display();
				}
				else if (menu == 'U' || menu == 'u') {
					cin >> slot;
					std::cin.sync();
					std::cin.get();
					player.equipItem(slot);
				}
				else if (menu == 'T' || menu == 't') {
					if (player.takeItem(item))
						status = -1;
					break;
				}
				else if (menu == 'E' || menu == 'e') {
					item.Display();
				}
				else if (menu == 'D' || menu == 'd') {
					cin >> slot;
					std::cin.sync();
					std::cin.get();
					player.dropItem(slot);
				}
				else if (menu == 'Q' || menu == 'q') {
					cout << "\nThank you for playing, " << player.getname() << ".\n";
					system("PAUSE");
					return 0;
				}
				else if ((menu == 'P') || (menu == 'p')) {
					break;
				}
				else {
					cout << "\nInvalid input, try again.\n";
				}
			}
		}
		if (status == -1) {
			while ((menu != 'P') && (menu != 'p')) {
				cout << "\n\nWhat shall you do?\n		I - View Inventory\n		P - Proceed to next area.\n		U - Use item at slot #\n		D - Drop item at slot #\n		Q - Quit\n" << name << "\n----------------\n" << "Health: " << player.getHealth() << " / " << player.getMaxHealth() << "\nLevel : " << player.getLevel() << "\nExperience : " << player.getExperience() << "\n\n> ";
				cin >> menu;
				if (menu == 'I' || menu == 'i') {
					player.Display();
				}
				else if (menu == 'U' || menu == 'u') {
					cin >> slot;
					std::cin.sync();
					std::cin.get();
					player.equipItem(slot);
				}
				else if (menu == 'D' || menu == 'd') {
					cin >> slot;
					std::cin.sync();
					std::cin.get();
					player.dropItem(slot);
				}
				else if (menu == 'Q' || menu == 'q') {
					cout << "\nThank you for playing, " << player.getname() << ".\n";
					system("PAUSE");
					return 0;
				}
				else if (menu == 'P' || menu == 'p') {
					break;
				}
				else {
					cout << "\nInvalid input, try again.\n";
				}
			}
		}
	}
	
	system("PAUSE");
	
}