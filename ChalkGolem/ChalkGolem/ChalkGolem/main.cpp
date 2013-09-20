#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main ()
{
	int num=0;
	int AC =0;
	int rolls[20];
	int rolls_BAB[28];
	int i = 0;
	int dice;
	float percent;
	int dmg = 0;
	
	srand(time(NULL));
	cout << "Number of Chalk Golems: ";
	cin >> num;
	cout << "\nAC of Enemy: ";
	cin >> AC;

	for (i = 0; i < 20; i++)
	{
		rolls [i] = 0;
	}
	for (i = 0; i < 28; i++)
	{
		rolls_BAB [i] = 0;
	}
	
	cout << "\n\nNo BAB" << endl;
	for (i = 0; i < num; i++)
	{
		//if (i % 100000000 == 0) cout << i << " rolls" << endl;
		rolls[rand()%20] ++;
	}
	
	for (i = 0; i < 20; i ++)
	{
		percent = ((float)rolls[i] / (float)num)*100;
		cout << i+1 << ": " << rolls[i] << "   " << percent << "%   ";
		if (i == 0) 
		{
			cout << "0 dmg" << endl;
		}
		else if (i == 19) 
		{
			cout << 2 * rolls[i] << " dmg potential" << endl;
		}
			
		else 
		{
			cout << rolls [i] << " dmg potential" << endl;
		}
	}

	for (i = 0; i < 20; i ++)
	{
		if (i+1 < AC && i+1 != 20) dmg += rolls[i];
		if (i+1 == 20) dmg += rolls[i]*2;
	}
	cout << "This creature took " << dmg << " dmg. " << endl;

	dmg = 0;
	cout << "\nFine BAB (+8) " << endl;
	cout << "Note: A roll of 28 is a natural 20" << endl;

	cout << "No BAB" << endl;
	for (i = 0; i < num; i++)
	{
		//if (i % 100000 == 0) cout << i << " rolls" << endl;
		dice = rand()%20;
		if (dice != 0)
		{
			dice +=8;
		}
		rolls_BAB[dice] ++;
	}

		for (i = 0; i < 28; i ++)
	{
		percent = ((float)rolls_BAB[i] / (float)num)*100;
		cout << i+1 << ": " << rolls_BAB[i] << "   " << percent << "%   ";
		if (i == 0) 
		{
			cout << "0 dmg" << endl;
		}
		else if (i == 27) 
		{
			cout << 2 * rolls_BAB[i] << " dmg potential" << endl;
		}
			
		else 
		{
			cout << rolls_BAB [i] << " dmg potential" << endl;
		}
	}

	for (i = 0; i < 28; i ++)
	{
		if (i+1 < AC && i+1 != 28) dmg += rolls_BAB[i];
		if (i+1 == 28) dmg += rolls_BAB[i]*2;
	}
	cout << "This creature took " << dmg << " dmg. " << endl;

	char c;
	cout << "Press any character then enter to exit. ";
	cin >> c;
	return 0;

}