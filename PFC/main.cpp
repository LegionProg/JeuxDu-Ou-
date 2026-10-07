#include <iostream>

using namespace std;

int Choice(int min, int max)
{
	int choice;

	while (true)
	{
		cin >> choice;
		if (choice >= min && choice <= max)
			break;
		cout << "saisit incorecte recomancer" << endl;
	}


	return choice;
}

int Random(int max)
{
	srand(time(NULL)); // retenir
	int randomNumber = rand() % max;
	return randomNumber;
}

void Print_Choice(int choice)
{
	if (choice == 0)
	{
		cout << "Pierre" << endl;
	}
	else if (choice == 1)
	{
		cout << "Feuille" << endl;
	}
	else if (choice == 2)
	{
		cout << "Ciseau" << endl;
	}

}



void PrintResult(int choice, int botChoice)
{

}
void Play()
{
	int choice;
	int botChoice;
	cout << ">Bienvenu dans le jeux du pierre feuille ciseau" << endl;

	int score[3]{ 0 };

	// proto

	int tableIA[3]{ 0 };
	int randomIA;

	while (true)
	{

		cout << "Choisiser" << endl
			<< "Pierre = 0" << endl
			<< "Feuille = 1" << endl
			<< "Ciseau = 2" << endl;

		choice = Choice(0, 2);
		cout << "Humain joue -> ";
		Print_Choice(choice);

		tableIA[choice] = tableIA[choice] + 1;

		randomIA = Random(100);
		if (randomIA <= 70)
		{
			cout << endl << "IA" << endl;
			if (tableIA[0] > tableIA[1] && tableIA[0] > tableIA[2])
				botChoice = 1;
			else if (tableIA[1] > tableIA[2])
				botChoice = 2;
			else
				botChoice = 0;
		}
		else
		{
			botChoice = Random(3);
			cout << endl << "RN" << endl;
		}
		
		cout << "Machine joue -> ";
		Print_Choice(botChoice);


		// proto fonctionelle  ->
		if (choice == botChoice)
		{
			cout << endl << "egaliter" << endl;
			score[2] = score[2] + 1;
		}
		else if (choice == 0) // caillou
		{
			if (botChoice == 1) // feuille
			{
				cout << endl << "perdu " << endl;
				score[1] = score[1] + 1;
			}
			else
			{
				cout << endl << "Victoir " << endl;
				score[0] = score[0] + 1;

			}
		}
		else if (choice - 1 == botChoice)
		{
			cout << endl << "Victoire " << endl;
			score[0] = score[0] + 1;
		}
		else if (choice == botChoice + 1)
		{
			cout << endl << "perdu " << endl;
			score[1] = score[1] + 1;
		}
		
		// <- proto




		/*
		if (choice == botChoice)
		{
			cout << endl << "egaliter" << endl;
			score[2] = score[2] + 1;
		}

		if (choice == 0)
		{
			if (botChoice == 1)
			{
				cout << endl << "Perdu" << endl;
				score[1] = score[1] + 1;
			}
			else if (botChoice == 2)
			{
				cout << endl << "Victoir" << endl;
				score[0] = score[0] + 1;
			}
		}
		else if (choice == 1)
		{
			if (botChoice == 0)
			{
				cout << endl << "Victoir" << endl;
				score[0] = score[0] + 1;
			}
			else if (botChoice == 2)
			{
				cout << endl << "Perdu" << endl;
				score[1] == score[1] + 1;
			}
		}
		else if (choice == 2)
		{
			if (botChoice == 0)
			{
				cout << endl << "Perdu" << endl;
				score[1] = score[1] + 1;
			}
			else if (botChoice == 1)
			{
				cout << endl << "Victoir" << endl;
				score[0] = score[0] + 1;
			}
		}
		*/

		cout << endl << "Voici les score Humain -> " << score[0]
			<< " score Machine -> " << score[1]
			<< " manche nul -> " << score[2] << endl;

		if (score[0] == 4)
		{
			cout << "tu a gagner cette fois si " << endl;
			break;
		}
		else if (score[1] == 4)
		{
			cout << "tu a perdu " << endl;
			break;
		}
	}
	/*
	for (int i = 0; i < 2; i++)
	{
		tableIA[i] = tableIA[i] = 0;
		score[i] = score[i] = 0;
	}*/
}

int main()
{
	Play();


	return 0;
}


