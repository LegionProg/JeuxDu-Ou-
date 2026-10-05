#include <iostream>


using namespace std;

int main()
{
	srand(time(NULL)); // retenir
	int mystery_number = rand() % 101; // retenire
	int number;
	cout << "bienvenue au jeux du nombre plus ou moins " << endl;


	while (true)
	{
		cout << mystery_number;
		cout << "choisit un nombre" << endl ;
		cin >> number;
		if (number == mystery_number)
		{
			cout << "GG ta win" << endl;
			break;
		}
		else if (number < mystery_number)
		{
			cout << "trop petit !!" << endl << endl;
		}
		else
		{
			cout << "trop grand !!" << endl << endl;
		}
	}
	


	return 0;
}