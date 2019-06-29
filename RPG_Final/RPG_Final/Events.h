#pragma once

#include"Enemies.h"
#include"Names.h"
#include"RNG.h"
#include "Inventory.h"

using std::strcpy;

class Events {
protected:
	char* description;
	char* monsterdescription;
	int status;
	Enemy themonster;
	Inventory theitem;
public:
	Events(int eventnumber, int finalNumber, int PL) {
		RNG rngesus;

		description = new char[100];
		monsterdescription = new char[100];

		strcpy(description, "You ");
		strcat(description, Area_Travel_Type[rngesus.pick(0, 6)]);
		strcat(description, " a ");
		strcat(description, Area_Descriptor[rngesus.pick(0, 15)]);
		strcat(description, " ");
		strcat(description, Area_Setting[rngesus.pick(0, 10)]);
		strcat(description, "!");

		if ((eventnumber == finalNumber) && (PL >= 15))
		{
			int* A = new int[2];
			A[0] = 20;
			A[1] = 25;
			float* D = new float[2];
			D[0] = 5;
			D[1] = 2.5;
			char* Atype = new char[2];
			Atype[0] = 'P';
			Atype[1] = 'M';
			char* Dtype = new char[2];
			Dtype[0] = 'H';
			Dtype[1] = 'U';
			Enemy M("Dark Lord", 500, A, Atype, D, Dtype, 100, 0, 5000, 15);

			themonster = M;
			delete[] A;
			delete[] D;
			delete[] Atype;
			delete[] Dtype;
			
			strcpy(monsterdescription, M.getname());
			strcat(monsterdescription, " ");
			strcat(monsterdescription, Enemy_Appearance_Descriptor[rngesus.pick(0, 7)]);
			strcat(monsterdescription, "!");

			status = 1;
		}

		else if (rngesus.chance(40))
		{
			status = 1;

			if ((eventnumber - finalNumber <= 15) && (PL >= 12))
			{
				int pick = rngesus.pick(0, 415);
				if (pick > 385)
				{
					int* A = new int[2];
					A[0] = 16;
					A[1] = 12;
					float* D = new float[1];
					D[0] = 3;
					char* Atype = new char[2];
					Atype[0] = 'C';
					Atype[1] = 'M';
					char* Dtype = new char[1];
					Dtype[0] = 'H';
					Enemy M("Black Knight", 250, A, Atype, D, Dtype, 90, 30, 2000, 12);

					themonster = M;
					delete[] A;
					delete[] D;
					delete[] Atype;
					delete[] Dtype;
					
				}

				else if (pick > 365)
				{
					int* A = new int[1];
					A[0] = 16;
					float* D = new float[2];
					D[0] = 1;
					D[1] = 5;
					char* Atype = new char[1];
					Atype[0] = 'M';
					char* Dtype = new char[2];
					Dtype[0] = 'L';
					Dtype[1] = 'U';
					Enemy M("Necromancer", 100, A, Atype, D, Dtype, 60, 20, 600, 10);

					themonster = M;
					delete[] A;
					delete[] D;
					delete[] Atype;
					delete[] Dtype;

				}

				else if (pick > 340)
				{
					int *A = new int[1];
					A[0] = 12;
					float* D = new float[1];
					D[0] = 1;
					char *Atype = new char[1], *Dtype = new char[1];
					Atype[0] = 'C';
					Dtype[0] = 'M';
					Enemy M("Giant", 125, A, Atype, D, Dtype, 50, 25, 500, 10);

					themonster = M;
				}

				else if (pick > 320)
				{
					int A[2] = { 16, 10 };
					float D[2] = { 5, 1 };
					char Atype[2] = { 'P','M' }, Dtype[2] = { 'H','U' };
					Enemy M("Dragon", 100, A, Atype, D, Dtype, 60, 20, 550, 10);

					themonster = M;
				}

				else if (pick > 290)
				{
					int *A = new int[1];
					A[0] = 6;
					float D[2] = { 1,3 };
					char *Atype = new char[1], Dtype[2] = { 'M','U' };
					Atype[0] = 'C';
					Enemy M("Golem", 60, A, Atype, D, Dtype, 30, 30, 125, 6);

					themonster = M;
				}

				else if (pick > 245)
				{
					int* A = new int[1];
					A[0] = 6;
					float *D = new float[1];
					D[0] = 2;
					char* Atype = new char[1], * Dtype = new char[1];
					Atype[0] = 'S';
					Dtype[0] = 'H';
					Enemy M("Skeleton", 35, A, Atype, D, Dtype, 25, 45, 100, 6);

					themonster = M;
				}

				else if (pick > 185)
				{
					int* A = new int[1];
					A[0] = 4;
					float* D = new float[1];
					D[0] = 1;
					char* Atype = new char[1], * Dtype = new char[1];
					Atype[0] = 'P';
					Dtype[0] = 'L';
					Enemy M("Spider", 20, A, Atype, D, Dtype, 20, 60, 55, 4);

					themonster = M;
				}

				else if (pick > 135)
				{
					int* A = new int[1];
					A[0] = 8;
					float* D = new float[1];
					D[0] = 0;
					char* Atype = new char[1], * Dtype = new char[1];
					Atype[0] = 'S';
					Dtype[0] = 'L';
					Enemy M("Troll", 35, A, Atype, D, Dtype, 20, 50, 85, 3);

					themonster = M;
				}

				else if (pick > 75)
				{
					int* A = new int[1];
					A[0] = 5;
					float* D = new float[1];
					D[0] = 1;
					char* Atype = new char[1], * Dtype = new char[1];
					Atype[0] = 'S';
					Dtype[0] = 'L';
					Enemy M("Orc", 25, A, Atype, D, Dtype, 15, 60, 60, 1);

					themonster = M;
				}

				else
				{
					int* A = new int[1];
					A[0] = 3;
					float* D = new float[1];
					D[0] = 0;
					char* Atype = new char[1], * Dtype = new char[1];
					Atype[0] = 'S';
					Dtype[0] = 'L';
					Enemy M("Goblin", 15, A, Atype, D, Dtype, 10, 75, 30, 1);

					themonster = M;
				}
			}

			else if (PL >= 12)
			{
				int pick = rngesus.pick(0, 400);
				if (pick > 385)
				{
					int A[2] = { 16, 12 };
					float D[1] = { 3 };
					char Atype[2] = { 'C','M' }, Dtype[1] = { 'H' };
					Enemy M("Black Knight", 250, A, Atype, D, Dtype, 90, 15, 2000, 12);

					themonster = M;
				}

				else if (pick > 365)
				{
					int A[1] = { 16 };
					float D[2] = { 1,5 };
					char Atype[1] = { 'M' }, Dtype[2] = { 'L','U' };
					Enemy M("Necromancer", 100, A, Atype, D, Dtype, 60, 20, 600, 10);

					themonster = M;
				}

				else if (pick > 340)
				{
					int A[1] = { 12 };
					float D[1] = { 1 };
					char Atype[1] = { 'C' }, Dtype[1] = { 'M' };
					Enemy M("Giant", 125, A, Atype, D, Dtype, 50, 25, 500, 10);

					themonster = M;
				}

				else if (pick > 320)
				{
					int A[2] = { 16, 10 };
					float D[2] = { 5, 1 };
					char Atype[2] = { 'P','M' }, Dtype[2] = { 'H','U' };
					Enemy M("Dragon", 100, A, Atype, D, Dtype, 60, 20, 550, 10);

					themonster = M;
				}

				else if (pick > 290)
				{
					int A[1] = { 6 };
					float D[2] = { 1,3 };
					char Atype[1] = { 'C' }, Dtype[2] = { 'M','U' };
					Enemy M("Golem", 60, A, Atype, D, Dtype, 30, 30, 125, 6);

					themonster = M;
				}

				else if (pick > 245)
				{
					int A[1] = { 6 };
					float D[1] = { 2 };
					char Atype[1] = { 'S' }, Dtype[1] = { 'H' };
					Enemy M("Skeleton", 35, A, Atype, D, Dtype, 25, 45, 100, 6);

					themonster = M;
				}

				else if (pick > 185)
				{
					int A[1] = { 4 };
					float D[1] = { 1 };
					char Atype[1] = { 'P' }, Dtype[1] = { 'L' };
					Enemy M("Spider", 20, A, Atype, D, Dtype, 20, 60, 55, 4);

					themonster = M;
				}

				else if (pick > 135)
				{
					int A[1] = { 8 };
					float D[1] = { 0 };
					char Atype[1] = { 'S' }, Dtype[1] = { 'L' };
					Enemy M("Troll", 35, A, Atype, D, Dtype, 20, 50, 85, 3);

					themonster = M;
				}

				else if (pick > 75)
				{
					int A[1] = { 5 };
					float D[1] = { 1 };
					char Atype[1] = { 'S' }, Dtype[1] = { 'L' };
					Enemy M("Orc", 25, A, Atype, D, Dtype, 15, 60, 60, 1);

					themonster = M;
				}

				else
				{
					int A[1] = { 3 };
					float D[1] = { 0 };
					char Atype[1] = { 'S' }, Dtype[1] = { 'L' };
					Enemy M("Goblin", 15, A, Atype, D, Dtype, 10, 75, 30, 1);

					themonster = M;
				}
			}

			else if (PL >= 10)
			{
				int pick= rngesus.pick(0, 385);

				if (pick > 365)
					{
					int A[1] = { 16 };
					float D[2] = { 1,5 };
					char Atype[1] = { 'M' }, Dtype[2] = { 'L','U' };
					Enemy M("Necromancer", 100, A, Atype, D, Dtype, 60, 20, 600, 10);

					themonster = M;
					}

				else if (pick > 340)
					{
					int A[1] = { 12 };
					float D[1] = { 1 };
					char Atype[1] = { 'C' }, Dtype[1] = { 'M' };
					Enemy M("Giant", 125, A, Atype, D, Dtype, 50, 25, 500, 10);

					themonster = M;
					}

				else if (pick > 320)
					{
					int A[2] = { 16, 10 };
					float D[2] = { 5, 1 };
					char Atype[2] = { 'P','M' }, Dtype[2] = { 'H','U' };
					Enemy M("Dragon", 100, A, Atype, D, Dtype, 60, 20, 550, 10);

					themonster = M;
					}

				else if (pick > 290)
					{
					int A[1] = { 6 };
					float D[2] = { 1,3 };
					char Atype[1] = { 'C' }, Dtype[2] = { 'M','U' };
					Enemy M("Golem", 60, A, Atype, D, Dtype, 30, 30, 125, 6);

					themonster = M;
					}

				else if (pick > 245)
					{
					int A[1] = { 6 };
					float D[1] = { 2 };
					char Atype[1] = { 'S' }, Dtype[1] = { 'H' };
					Enemy M("Skeleton", 35, A, Atype, D, Dtype, 25, 45, 100, 6);

					themonster = M;
					}

				else if (pick > 185)
					{
					int A[1] = { 4 };
					float D[1] = { 1 };
					char Atype[1] = { 'P' }, Dtype[1] = { 'L' };
					Enemy M("Spider", 20, A, Atype, D, Dtype, 20, 60, 55, 4);

					themonster = M;
					}

				else if (pick > 135)
					{
					int A[1] = { 8 };
					float D[1] = { 0 };
					char Atype[1] = { 'S' }, Dtype[1] = { 'L' };
					Enemy M("Troll", 35, A, Atype, D, Dtype, 20, 50, 85, 3);

					themonster = M;
					}

				else if (pick > 75)
					{
					int A[1] = { 5 };
					float D[1] = { 1 };
					char Atype[1] = { 'S' }, Dtype[1] = { 'L' };
					Enemy M("Orc", 25, A, Atype, D, Dtype, 15, 60, 60, 1);

					themonster = M;
					}

				else
					{
					int A[1] = { 3 };
					float D[1] = { 0 };
					char Atype[1] = { 'S' }, Dtype[1] = { 'L' };
					Enemy M("Goblin", 15, A, Atype, D, Dtype, 10, 75, 30, 1);

					themonster = M;
					}
			}

			else if (PL >= 6)
			{
				int pick = rngesus.pick(0, 320);

				 if (pick > 290)
					{
					 int A[1] = { 6 };
					 float D[2] = { 1,3 };
					 char Atype[1] = { 'C' }, Dtype[2] = { 'M','U' };
					 Enemy M("Golem", 60, A, Atype, D, Dtype, 30, 30, 125, 6);

					 themonster = M;
					}

				else if (pick > 245)
					{
					 int A[1] = { 6 };
					 float D[1] = { 2 };
					 char Atype[1] = { 'S' }, Dtype[1] = { 'H' };
					 Enemy M("Skeleton", 35, A, Atype, D, Dtype, 25, 45, 100, 6);

					 themonster = M;
					}

				else if (pick > 185)
					{
					 int A[1] = { 4 };
					 float D[1] = { 1 };
					 char Atype[1] = { 'P' }, Dtype[1] = { 'L' };
					 Enemy M("Spider", 20, A, Atype, D, Dtype, 20, 60, 55, 4);

					 themonster = M;
					}

				else if (pick > 135)
					{
					 int A[1] = { 8 };
					 float D[1] = { 0 };
					 char Atype[1] = { 'S' }, Dtype[1] = { 'L' };
					 Enemy M("Troll", 35, A, Atype, D, Dtype, 20, 50, 85, 3);

					 themonster = M;
					}

				else if (pick > 75)
					{
					 int A[1] = { 5 };
					 float D[1] = { 1 };
					 char Atype[1] = { 'S' }, Dtype[1] = { 'L' };
					 Enemy M("Orc", 25, A, Atype, D, Dtype, 15, 60, 60, 1);

					 themonster = M;
					}

				else
					{
					 int A[1] = { 3 };
					 float D[1] = { 0 };
					 char Atype[1] = { 'S' }, Dtype[1] = { 'L' };
					 Enemy M("Goblin", 15, A, Atype, D, Dtype, 10, 75, 30, 1);

					 themonster = M;
					}

			}

			else if (PL >= 4)
			{
				int pick = rngesus.pick(0, 245);

				if (pick > 185)
				{
					int A[1] = { 4 };
					float D[1] = { 1 };
					char Atype[1] = { 'P' }, Dtype[1] = { 'L' };
					Enemy M("Spider", 20, A, Atype, D, Dtype, 20, 60, 55, 4);

					themonster = M;
				}

				else if (pick > 135)
				{
					int A[1] = { 8 };
					float D[1] = { 0 };
					char Atype[1] = { 'S' }, Dtype[1] = { 'L' };
					Enemy M("Troll", 35, A, Atype, D, Dtype, 20, 50, 85, 3);

					themonster = M;
				}

				else if (pick > 75)
				{
					int A[1] = { 5 };
					float D[1] = { 1 };
					char Atype[1] = { 'S' }, Dtype[1] = { 'L' };
					Enemy M("Orc", 25, A, Atype, D, Dtype, 15, 60, 60, 1);

					themonster = M;
				}

				else
				{
					int A[1] = { 3 };
					float D[1] = { 0 };
					char Atype[1] = { 'S' }, Dtype[1] = { 'L' };
					Enemy M("Goblin", 15, A, Atype, D, Dtype, 10, 75, 30, 1);

					themonster = M;
				}
			}

			else if (PL >= 3)
			{
				int pick = rngesus.pick(0, 185);

				if (pick > 135)
				{
					int A[1] = { 8 };
					float D[1] = { 0 };
					char Atype[1] = { 'S' }, Dtype[1] = { 'L' };
					Enemy M("Troll", 35, A, Atype, D, Dtype, 20, 50, 85, 3);

					themonster = M;
				}

				else if (pick > 75)
				{
					int A[1] = { 5 };
					float D[1] = { 1 };
					char Atype[1] = { 'S' }, Dtype[1] = { 'L' };
					Enemy M("Orc", 25, A, Atype, D, Dtype, 15, 60, 60, 1);

					themonster = M;
				}

				else
				{
					int* A = new int[1];
					A[0] = 3;
					float* D = new float[1];
					D[0] = 0;
					char* Atype = new char[1], * Dtype = new char[1];
					Atype[0] = 'S';
					Dtype[0] = 'L';
					Enemy M("Goblin", 15, A, Atype, D, Dtype, 10, 75, 30, 1);

					themonster = M;
				}
			}

			else
			{
				int pick = rngesus.pick(0, 135);

				if (pick > 75)
					{
					int A[1] = { 5 };
					float D[1] = { 1 };
					char Atype[1] = { 'S' }, Dtype[1] = { 'L' };
					Enemy M("Orc", 25, A, Atype, D, Dtype, 15, 60, 60, 1);

					themonster = M;
					}

				else
					{
					int* A = new int[1];
					A[0] =3;
					float* D = new float[1];
					D[0] = 0;
					char* Atype = new char[1], * Dtype = new char[1];
					Atype[0] = 'S';
					Dtype[0] = 'L';
					Enemy M("Goblin", 15, A, Atype, D, Dtype, 10, 75, 30, 1);

					themonster = M;
					}

			}

			strcpy(monsterdescription, themonster.getname());
			strcat(monsterdescription, " ");
			strcat(monsterdescription, Enemy_Appearance_Descriptor[rngesus.pick(0, 7)]);
			strcat(monsterdescription, "!");

		}

		else if (rngesus.chance(25))
		{
			Inventory Retitem(PL);


			strcpy(monsterdescription, "\0");
			theitem = Retitem;
			status = 2;
		}

		else
		{
			strcpy(monsterdescription, "\0");
			status = 0;
		}
		
	}

	const void Display() {
		cout << description << "\n";
		if (status == 1)
		{
			cout << monsterdescription << "\n";
		}
	}

	~Events() {
		delete[] description;
		delete[] monsterdescription;
	}


	int getStatus() {
		return status;
	}
	Enemy getEnemy() {
		return themonster;
	}
	Inventory getInventory() {
		return theitem;
	}
	
	char* getDescription() {
		return description;
	}
	char* getMonsterDescription() {
		return monsterdescription;
	}

};



/*monsterdescription = new char[100];
themonster = M;
strcat(monsterdescription, M.getname());
strcat(monsterdescription, " ");
strcat(monsterdescription, Enemy_Appearance_Descriptor[rngesus.pick(0, 7)]);
strcat(monsterdescription, "!");*/

/*	int A[2] = { 20, 25 };
			float D[2] = { 5,2.5 };
			char Atype[2] = { 'P','M' }, Dtype[2] = { 'H','U' };
			Enemy DarkLord("Dark Lord", 500, A, Atype, D, Dtype, 100, 0, 5000, 15);*/