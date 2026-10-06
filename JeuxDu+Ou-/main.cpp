#include <iostream>


using namespace std;

int main()
{
	srand(time(NULL)); // retenir
	int help;
	int dificulty;
	int mystery_number = 0;
	int modulo;
	int number;
	int i = 0;
	int old_Number;

	cout << "Voulez vous activer l'indication de proximite ? \n Oui = 1 \n Non = 0" << endl;
	while (true)
	{
		cin >> help;
		if (help == 0)
		{
			cout << "indicateur de promiximiter activer" << endl;
			break;
		}
		else if (help == 1)
		{
			cout << "indicateur de promiximiter desactiver" << endl;
			break;
		}
		else
		{
			cout << "recommancer saisit invalide" << endl;
			help = 3;
		}
	}
	cout << "Choisiser la dificulter \n Facile = 1\n Normal = 2\n Difficile = 3" << endl;

	while (true)
	{
		cin >> dificulty;
		if (dificulty == 3)
		{
			cout << "vous avez choisis Difficile bonne chance a vous :-)" << endl;
			modulo = 501; // retenir
			break;
		}
		else  if (dificulty == 2)
		{
			cout << "vous avez choisis Normal :-|" << endl;
			modulo = 101; // retenir
			break;
		}
		else if (dificulty == 1)
		{
			cout << "vous avez choisis Facile il faut bien commencer :-/" << endl;
			modulo = 21; // retenir
			break;
		}
		else
		{
			cout << "recommancer saisit invalide" << endl;
		}
	}
	mystery_number = rand() % modulo;

	cout << "bienvenue au jeux du nombre plus ou moins " << endl;

	while (true)
	{
		cout << " Debug -> " << mystery_number << endl << endl;
		cout << "choisit un nombre entre 0 et "  << modulo << endl;
		cin >> number;
		if (number > 0 && number <= modulo)
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
		{
			cout << "recommancer saisit invalide" << endl;
		}
	}



	return 0;
}