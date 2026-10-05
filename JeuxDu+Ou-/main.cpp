#include <iostream>


using namespace std;

int main()
{
	srand(time(NULL)); // retenir
	int mystery_number = rand() % 101; // retenir
	int number;
	cout << "bienvenue au jeux du nombre plus ou moins " << endl;
	int i=0;
	bool help;

	while (true)
	{
		cout << "choisit un nombre" << endl ;
		cin >> number;
		if (number == mystery_number)
		{
			cout << "GG ta win" << endl;
			cout << "tu a fait " << i << "essai" << endl;
			break;
		}
		else if (number < mystery_number-10)
		{
			cout << "c'est beaucoup plus !!" << endl << endl;
		}
		else if (number < mystery_number)
		{
			cout << "C'est un peu plus !!" << endl << endl;
		}
		else if (number > mystery_number + 10)
		{
			cout << "c'est beaucoup moins!!"<< endl << endl;
		}
		else if (number > mystery_number)
		{
			cout << "C'est un peu moins !!"<< endl << endl;
		}
		if (i >= 10)
		{
			cout << "Perdu au bout de ten d essais " << i << endl;
		}
			i++;
	}
	


	return 0;
}