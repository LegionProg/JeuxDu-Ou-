#include <iostream>

int Choice(int min, int max)
{
	int choice;
	while (true)
	{
		std::cin >> choice;
		if (choice >= min && choice <= max)
			break;
		std::cout << "Vous avez mal saisie recommencer et cette fois si correctement !!!" << std::endl;
	}


	return choice;
}
int Generator(int max)
{

	return rand() % (max + 1);
}

int ChekWin(int tab, int symbole, int n)
{
	for (int i = 0; i < n; i++)
	{
		int index = i * 3; 
		/*if (tab[index] != symbole)
		{
			break;
		}*/
		if (tab[index] == tab[index + 1] && tab[index] == tab[index + 2])
			return symbole;
	}
}


















void PrintCell(int tab[], int n, int tailleTab)
{
	int a = n - 1;
	for (int i = 0; i < tailleTab; i++)
	{
		std::cout << " [ ";
		if (tab[i] == 0)
			std::cout << "   ";
		else if (tab[i] == -1)
			std::cout << " X ";

		else if (tab[i] == -2)
			std::cout << " O ";

		std::cout << " ] ";
		if (i == a)
		{
			a = a + n;
			std::cout << std::endl;
		}
	}

}

void Morpions_Cours()
{
	int numberPlayer = 1;
	int end = 0;
	int testeIf = 1;
	int choice = 0;
	bool noIdeaIA = false;

	// tableau
	const int n = 4;
	const int sizeTab = n * n;
	int tab[sizeTab]; // {0}
	int tabChoice[2]{ 0 };

	for (int i = 0; i < sizeTab; i++)
	{
		tab[i] = 0;
	}

	while (true)
	{
		int a = 2;

		/*for (int i = 0; i < 9; i++)
		{
			std::cout << " [ " << ((((tab[i] == -1) ? 'X' : tab[i] ) || ((tab[i] == -2) ? 'O' : tab[i])) ||((tab[i] == 0) ? ' ' : tab[i])) << " ] ";
			if (i == a)
			{
				a = a + 3;
				std::cout << std::endl;
			}
		}*/

		system("cls");
		PrintCell(tab, n, sizeTab);

		std::cout << "Choisit une case" << std::endl;

		std::cout << std::endl;


		while (true)
		{
			std::cout << "Joueur 1 a vous de jouer choisiser Y" << std::endl;
			tabChoice[0] = Choice(1, n) - 1; // Y
			std::cout << "Joueur 1 a vous de jouer choisiser X" << std::endl;
			tabChoice[1] = Choice(1, n) - 1; // X

			for (int a = 0; a < n; a++)
			{
				for (int i = 0; i < n; i++)
				{
					if (tabChoice[0] == a)
						if (tabChoice[1] == i)
						{
							choice = i + (a * n); // problème
							break;
						}
				}
			}


			if (tab[choice] == 0)
			{
				tab[choice] = -1;
				break;
			}
			std::cout << "La case et deja prise" << std::endl;
		}


		// condition de victoire joueur
		ChekWin(tab[sizeTab], -1, n);


		/*for (int i = 0; i <= n * 2; i = i + n)
		{
			if (tab[i] == -1 && tab[i + 1] == -1 && tab[i + 2] == -1)
			{
				std::cout << "Bien joueur 1 Gagner !" << std::endl;
				PrintCell(tab, n, tailleTab);
				end = 1;
				break;
			}
		}
		for (int i = 0; i <= n; i++)
		{
			if (tab[i] == -1 && tab[i + n] == -1 && tab[i + n+n] == -1)
			{
				std::cout << "Bien joueur 1 Gagner !" << std::endl;
				PrintCell(tab, n, tailleTab);
				end = 1;
				break;
			}
		}
		if ((tab[0] == -1 && tab[4] == -1 && tab[8] == -1) || (tab[6] == -1 && tab[4] == -1 && tab[2] == -1))
		{
			std::cout << "Bien joueur 1 Gagner !" << std::endl;
			PrintCell(tab, n, tailleTab);
			end = 1;
			break;
			else {
			for (int i = 0; i < 9; i++) // probleme avec matche null
			{
				if (tab[i] == 0)
				{
					testeIf = 1;
					break;
				}
				else
					testeIf = 0;
			}
			if (testeIf == 0)
				std::cout << "Egaliter !" << std::endl;

		}
		if (end == 1)
			break;

		}*/
		



		
		system("cls");
		PrintCell(tab, n, sizeTab);

		// IA / Bot / Joueur 2

		//JOueur 2
		/*if (numberPlayer == 2)
		{
			std::cout << "Joueur 2 a vous de jouer " << std::endl;
			while (true)
			{
				int choice = Choice(1, n) - 1;
				if (tab[choice] == 0)
				{
					tab[choice] = -2;
					break;
				}
				std::cout << "La case et deja prise" << std::endl;
			}
		}*/

		// Bot // Rand
		if (false)
		{
			while (true)
			{
				choice = Generator(8);
				if (tab[choice] == 0)
				{
					tab[choice] = -2;
					break;
				}
			}
		}

		//IA // inteligent (comme les premier IA pour les echeque
		noIdeaIA = true;
		for (int i = 0; i < n; i++)// Chercher si uncoup lui permet de Win
		{
			if (tab[i] == -2 && tab[i + 1] == -2 && tab[i + 2] == 0) // si troue a droite
			{
				tab[i + 2] = -2;
				noIdeaIA = false;
				break;
			}
			else if (tab[i + 1] == -2 && tab[i + 2] == -2 && tab[i] == 0) // si troue a gauche
			{
				tab[i] = -2;
				noIdeaIA = false;
				break;
			}
			else if (tab[i] == -2 && tab[i + 2] == -2 && tab[i + 1] == 0) // si troue au milieux
			{
				tab[i + 1] = -2;
				noIdeaIA = false;
				break;
			}

			// haut bas
			else if (tab[i] == -2 && tab[i + n] == -2 && tab[i + n + n] == 0)
			{
				tab[i + n + n] = -2;
				noIdeaIA = false;
				break;
			}
			else if (tab[i] == -2 && tab[i + n + n] == -2 && tab[i + n] == 0)
			{
				tab[i + n] = -2;
				noIdeaIA = false;
				break;
			}
			else if (tab[i+n] == -2 && tab[i + n + n] == -2 && tab[i] == 0)
			{
				tab[i] = -2;
				noIdeaIA = false;
				break;
			}

		}

		if (noIdeaIA) // si l'ia na pas d'idée de quoi jouer alors il choisit rand
		{
			while (true)
			{
				choice = Generator(sizeTab - 1);
				if (tab[choice] == 0)
				{
					tab[choice] = -2;
					break;
				}
			}
		}



		// victoire bot
		end = ChekWin(tab[sizeTab], -2, n);
		/*for (int i = 0; i <= n+n; i = i + n)
		{
			if (tab[i] == -2 && tab[i + 1] == -2 && tab[i + 2] == -2)
			{
				std::cout << "Machine Gagne !" << std::endl;
				end = 1;
				break;
			}
		}
		for (int i = 0; i <= n; i++)
		{
			if (tab[i] == -2 && tab[i + n] == -2 && tab[i + n+n] == -2)
			{
				std::cout << "Machine Gagne !" << std::endl;
				end = 1;
				break;
			}
			if ((tab[i] == -2 && tab[i + n + 1] == -2 && tab[i + n + 1 + n + 1] == -1) || (tab[i] == -2 && tab[i+n-1] == -2 && tab[i + n - 1+n-1] == -2))
			{
				std::cout << "Machine Gagne !" << std::endl;
				end = 1;
				break;
			}
		}*/
	

		if (end == -1)
		{
			std::cout << "Joueur a gagner" << std::endl;
			break;
		}
		else if (end == -2)
		{
			std::cout << "Machine a gagner" << std::endl;
			break;
		}

	}
}/**/


int main()
{
	Morpions_Cours();
	return 0;
}