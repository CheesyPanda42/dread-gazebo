#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

int DieRoller (int num_sides);

int main()
{
	int numMelee, numRanged;
	int attackRolls[20];
	int dmgRoll[20];
	int AC;
	int i;
	int roll;
	int meleeDmg, rangedDmg, totalDmg;
	float percent;

	srand(time(NULL));

	meleeDmg = rangedDmg = totalDmg = 0;

	cout <<"Peasant is defined as a level 1 commoner with a 10 in all abilities" << endl;
	cout << "Number of melee peasants (quarterstaff): ";
	cin >> numMelee;
	cout << "Number of ranged peasants(sling): ";
	cin >> numRanged;
	cout << "AC of enemy: ";
	cin >> AC;

	AC--;

	for (i=0; i < 20; i++)
	{
		attackRolls[i] = 0;
		dmgRoll[i] = 0;
	}
	
	for (i = 0; i < numMelee; i++)
	{
		roll = rand()%20;
		attackRolls[roll]++;
	}

	
	for (i = 0; i < attackRolls[19]; i++)
	{
		dmgRoll[19]+= (rand() %4 +1) *2;
	}
	i = min(AC,20);
	while (i < 19)
	{
		if (attackRolls[i] > 0) dmgRoll[i] += (rand() %4 +1);
		i++;
	}

	dmgRoll[0] = 0;

	for (i = 0; i < 20; i++)
	{
		meleeDmg += dmgRoll[i];
	}

	cout << "Melee Results: " << endl;
	for (i = 0; i < 20; i++)
	{
		cout << i+1 << ": " << attackRolls[i] << "  " << dmgRoll[i] << " damage" << endl;
	}


	cout << "Melee damage: " << meleeDmg << endl << endl;


	for (i=0; i < 20; i++)
	{
		attackRolls[i] = 0;
		dmgRoll[i] = 0;
	}
	
	for (i = 0; i < numRanged; i++)
	{
		roll = rand()%20;
		attackRolls[roll]++;
	}

	
	for (i = 0; i < attackRolls[19]; i++)
	{
		dmgRoll[19]+= (rand() %4 +1) *2;
	}
	i = min(AC,20);
	while (i < 19)
	{
		if (attackRolls[i] > 0) dmgRoll[i] += (rand() %4 +1);
		i++;
	}

	dmgRoll[0] = 0;

	for (i = 0; i < 20; i++)
	{
		rangedDmg += dmgRoll[i];
	}

	cout << "Ranged Results: " << endl;
	for (i = 0; i < 20; i++)
	{
		cout << i+1 << ": " << attackRolls[i] << "  " << dmgRoll[i] << " damage" << endl;
	}


	cout << "Ranged damage: " << rangedDmg << endl;
	cout << "Total damage: " << meleeDmg + rangedDmg << endl;
	
	char c;
	cout << "Press any character then enter to exit. ";
	cin >> c;
	return 0;
}
