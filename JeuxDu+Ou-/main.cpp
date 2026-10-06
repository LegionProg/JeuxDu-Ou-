#include <iostream>


using namespace std;

int AskInt(int min, int max)
{
	int dificulty;
	while (true)
	{
		std::cin >> dificulty;
		if (dificulty >= min && dificulty <= max)
			break;

		std::cout << "Erreur saisie" << endl;
	}
	return dificulty;
}


void Play()
{
	srand(time(NULL)); // retenir


	int mystery_number = 0;
	int max_Mystery_Number;
	int number;
	int i = 0;
	int old_Number;

	cout << "Ativer l'indication ? \n Oui = 0\n Non =1" << endl;
	int help = AskInt(0, 1);
	cout << "Choisiser la dificulter \n Facile = 1\n Normal = 2\n Difficile = 3" << endl;
	int difficulty = AskInt(1, 3);


	if (difficulty == 3)
	{
		cout << "vous avez choisis Difficile bonne chance a vous :-)" << endl;
		max_Mystery_Number = 500; // retenir
	}
	else  if (difficulty == 2)
	{
		cout << "vous avez choisis Normal :-|" << endl;
		max_Mystery_Number = 100; // retenir
	}
	else if (difficulty == 1)
	{
		cout << "vous avez choisis Facile il faut bien commencer :-/" << endl;
		max_Mystery_Number = 20; // retenir
	}
	mystery_number = rand() % max_Mystery_Number;

	cout << "bienvenue au jeux du nombre plus ou moins " << endl;
	while (true)
	{
		//cout << " Debug -> " << mystery_number << endl << endl;
		cout << "choisit un nombre entre 0 et " << max_Mystery_Number - 1 << endl;
		number = AskInt(0, max_Mystery_Number);
		if (number > 0 && number <= max_Mystery_Number)
		{
			/*if (i == 0)
			{*/
			if (number == mystery_number)
			{
				cout << "--------->|<---------" << endl;
				cout << "GG ta win" << endl;
				cout << "tu a fait " << i << "essai" << endl;
				break;
			}
			else if (number < mystery_number - 10 && help == true)
			{

				cout << "--->>>>>>>|---------" << endl;
				//cout << "c'est beaucoup plus !!" << endl << endl;
			}
			else if (number < mystery_number - 5 && help == true)
			{

				cout << "------>>>>|---------" << endl;
				//cout << "c'est beaucoup plus !!" << endl << endl;
			}
			else if (number < mystery_number)
			{

				cout << "-------->>|----------" << endl;
				//cout << "C'est un peu plus !!" << endl << endl;

			}
			else if (number > mystery_number + 10 && help == true)
			{

				cout << "----------|<<<<<<<---" << endl;
				//cout << "c'est beaucoup moins!!" << endl << endl;
			}
			else if (number > mystery_number + 5 && help == true)
			{
				cout << "----------|<<<<------" << endl;
				//cout << "c'est beaucoup moins!!" << endl << endl;
			}
			else if (number > mystery_number)
			{
				cout << "----------|<<--------" << endl;
				//cout << "C'est un peu moins !!" << endl << endl;
			}
			if (i >= 10)
			{
				cout << "Perdu au bout de ten d essais " << i << endl;
				break;
			}
			old_Number = number;
			//}
			/*
			else // revenir plus tard
			{
				if (number == mystery_number)
				{
					cout << "GG ta win" << endl;
					cout << "tu a fait " << i << "essai" << endl;
					break;
				}
				else if ((old_Number < mystery_number && old_Number > number) || (old_Number > mystery_number && old_Number < number))
					cout << " -> Froid !" << endl;
				else if ((old_Number < mystery_number && old_Number < number) || (old_Number > mystery_number && old_Number > number))
					cout << " -> Chaud !" << endl;

				if (i >= 10)
				{
					cout << "Perdu au bout de tens d'essais " << i << endl;
					break;
				}
				old_Number = number;
			}*/
			i++;
		}
		else
			cout << "recommancer saisit invalide" << endl;
	}
}

int main()
{
	Play();



	return 0;
}


/*
while (true)
	{
		cout << " Debug -> " << mystery_number << endl << endl;
		cout << "choisit un nombre entre 0 et " << modulo - 1 << endl;
		number = AskInt(0, max)
			if (number > 0 && number <= modulo)
			{
				//if (i == 0)
				//{
if (number == mystery_number)
{
	cout << "--------->|<---------" << endl;
	cout << "GG ta win" << endl;
	cout << "tu a fait " << i << "essai" << endl;
	break;
}
else if (number < mystery_number - 10 && help == true)
{
	cout << "--->>>>>>>|---------" << endl;
	//cout << "c'est beaucoup plus !!" << endl << endl;
}
else if (number < mystery_number - 5 && help == true)
{
	cout << "------>>>>|---------" << endl;
	//cout << "c'est beaucoup plus !!" << endl << endl;
}
else if (number < mystery_number)
{
	cout << "-------->>|----------" << endl;
	//cout << "C'est un peu plus !!" << endl << endl;

}
else if (number > mystery_number + 10 && help == true)
{
	cout << "----------|<<<<<<<---" << endl;
	//cout << "c'est beaucoup moins!!" << endl << endl;
}
else if (number > mystery_number + 5 && help == true)
{
	cout << "----------|<<<<------" << endl;
	//cout << "c'est beaucoup moins!!" << endl << endl;
}
else if (number > mystery_number)
{
	cout << "----------|<<--------" << endl;
	//cout << "C'est un peu moins !!" << endl << endl;
}
if (i >= 10)
{
	cout << "Perdu au bout de ten d essais " << i << endl;
	break;
}
old_Number = number;
//}
/*
else // revenir plus tard
{
	if (number == mystery_number)
	{
		cout << "GG ta win" << endl;
		cout << "tu a fait " << i << "essai" << endl;
		break;
	}
	else if ((old_Number < mystery_number && old_Number > number) || (old_Number > mystery_number && old_Number < number))
		cout << " -> Froid !" << endl;
	else if ((old_Number < mystery_number && old_Number < number) || (old_Number > mystery_number && old_Number > number))
		cout << " -> Chaud !" << endl;

	if (i >= 10)
	{
		cout << "Perdu au bout de tens d'essais " << i << endl;
		break;
	}
	old_Number = number;
}
i++;
			}
			else
				cout << "recommancer saisit invalide" << endl;
	}
	bool rePlay = false;
	cout << "voulez vous rejouez ? Oui = 1 Non = 0" << endl;
	cin >> rePlay;
	if (rePlay == false)
		break; */