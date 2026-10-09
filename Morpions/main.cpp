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


void Morpion()
{
	std::cout << "Bien venue au morpions" << std::endl;
	int end = 0;
	const int max_Table = 9;
	char table[max_Table]{ ' ', ' ',' ',' ', ' ',' ', ' ', ' ',' ' };
	int choice;
	while (true)
	{
		int a = 2;
		for (int i = 0; i <= 8; i++)
		{
			std::cout << table[i];
			if (i != a && i != 9)
				std::cout << " | ";
			if (i == a)
			{
				std::cout << std::endl;
				a = a + 3;
			}

		}

		while (true) // joueur qui joue
		{
			choice = Choice(1, 9) - 1;
			if (table[choice] == ' ')
			{
				table[choice] = 'x';
				break;
			}
			std::cout << "la place et deja occuper" << std::endl;
		}



		// condition de victoire joueur
		for (int i = 0; i <= 6; i = i + 3)
		{
			if (table[i] == 'x' && table[i + 1] == 'x' && table[i + 2] == 'x')
			{
				std::cout << "Bien jouer Gagner !" << std::endl;
				end = 1;
				break;
			}
		}
		for (int i = 0; i <= 3; i++)
		{
			if (table[i] == 'x' && table[i + 3] == 'x' && table[i + 6] == 'x')
			{
				std::cout << "Bien jouer Gagner !" << std::endl;
				end = 1;
				break;
			}
		}
		if ((table[0] == 'x' && table[4] == 'x' && table[8] == 'x') || (table[6] == 'x' && table[4] == 'x' && table[2] == 'x'))
		{
			std::cout << "Bien jouer Gagner !" << std::endl;
			end = 1;
		}

		while (true) // bot stupide (random)
		{
			choice = Generator(max_Table);
			if (table[choice] == ' ')
			{
				table[choice] = 'o';
				break;
			}

		}
		for (int i = 0; i == 8; i++)
		{
			if (table[i] == ' ' && table[i + 1] == ' ' && table[i + 2] == ' ')
			{
				std::cout << " Egaliter " << std::endl;
				end = 1;
				break;
			}
		}

		for (int i = 0; i == 6; i = i + 3) // vertical
		{
			if (table[i] == 'o' && table[i + 1] == 'o' && table[i + 2] == 'o')
			{
				std::cout << "Perdu !" << std::endl;
				end = 1;
				break;
			}

		}
		for (int i = 0; i == 3; i++) // horizontal
		{
			if (table[i] == 'o' && table[i + 3] == 'o' && table[i + 6] == 'o')
			{
				std::cout << "Perdu !" << std::endl;
				end = 1;
				break;
			}
		}
		if ((table[0] == 'o' && table[4] == 'o' && table[8] == 'o') || (table[6] == 'o' && table[4] == 'o' && table[2] == 'o'))
		{
			std::cout << "Perdu !" << std::endl;
			end = 1;
		}
		if (end != 0)
		{
			std::cout << "La parti et finis la relancer ? " << std::endl
				<< "Oui = 0" << std::endl
				<< "Non = 1" << std::endl;
			end = Choice(0, 1);
			if (end == 1)
				break;
		}
	}
}






















void PrintCell(int tab[])
{
	int a = 2;

	for (int i = 0; i < 9; i++)
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
			a = a + 3;
			std::cout << std::endl;
		}
	}

}

void Morpions_Cours()
{
	int end = 0;
	int testeIf = 0;
	int tab[9]; // {0}
	for (int i = 0; i < 9; i++)
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



		std::cout << "Choisit une case" << std::endl;

		std::cout << std::endl;

		std::cout << "Joueur 1 a vous de jouer " << std::endl;
		while (true)
		{
			int choice = Choice(1, 9) - 1;
			if (tab[choice] == 0)
			{
				tab[choice] = -1;
				break;
			}
			std::cout << "La case et deja prise" << std::endl;
		}


		// condition de victoire joueur
		for (int i = 0; i < 9; i++)
		{
			if (tab[i] == 0)
			{
				testeIf = 1;
				break;
			}
			else if(tab)
			{
				testeIf = 0;
				end = 1;
				std::cout << "Match nul" << std::endl;
				break;
			}
		}
			
		if(testeIf == 1)
		{
			for (int i = 0; i <= 6; i = i + 3)
			{
				if (tab[i] == -1 && tab[i + 1] == -1 && tab[i + 2] == -1)
				{
					std::cout << "Bien joueur 1 Gagner !" << std::endl;
					PrintCell(tab);
					end = 1;
					break;
				}
			}
			for (int i = 0; i <= 3; i++)
			{
				if (tab[i] == -1 && tab[i + 3] == -1 && tab[i + 6] == -1)
				{
					std::cout << "Bien joueur 1 Gagner !" << std::endl;
					PrintCell(tab);
					end = 1;
					break;
				}
			}
			if ((tab[0] == -1 && tab[4] == -1 && tab[8] == -1) || (tab[6] == -1 && tab[4] == -1 && tab[2] == -1))
			{
				std::cout << "Bien joueur 1 Gagner !" << std::endl;
				PrintCell(tab);
				end = 1;
				break;
			}
		}
		

		if (end == 1)
			break;

		system("cls");
		PrintCell(tab);

		std::cout << "Joueur 2 a vous de jouer " << std::endl;
		while (true)
		{
			int choice = Choice(1, 9) - 1;
			if (tab[choice] == 0)
			{
				tab[choice] = -2;
				break;
			}
			std::cout << "La case et deja prise" << std::endl;
		}





		for (int i = 0; i <= 6; i = i + 3)
		{
			if (tab[i] == -2 && tab[i + 1] == -2 && tab[i + 2] == -2)
			{
				std::cout << "Bien joueur 2 Gagner !" << std::endl;
				end = 1;
				break;
			}
		}
		for (int i = 0; i <= 3; i++)
		{
			if (tab[i] == -2 && tab[i + 3] == -2 && tab[i + 6] == -2)
			{
				std::cout << "Bien joueur 2 Gagner !" << std::endl;
				end = 1;
				break;
			}
		}
		if ((tab[0] == -2 && tab[4] == -2 && tab[8] == -1) || (tab[6] == -2 && tab[4] == -2 && tab[2] == -2))
		{
			std::cout << "Bien joueur 2 Gagner !" << std::endl;
			end = 1;
			break;
		}
		PrintCell(tab);
		if (end == 1)
			break;

		/*
		// ne marche pas
		switch (choice == 1)
		{
		case 1:
		{
			tab[0] = -1;
			break;
		}
		case 2:
		{
			tab[1] = -1;
			break;
		}
		case 3:
		{
			tab[2] = -1;
			break;
		}
		case 4:
		{
			tab[3] = -1;
			break;
		}
		case 5:
		{
			tab[4] = -1;
			break;
		}
		case 6:
		{
			tab[5] = -1;
			break;
		}
		case 7:
		{
			tab[6] = -1;
			break;
		}
		case 8:
		{
			tab[7] = -1;
			break;
		}
		case 9:
		{
			tab[8] = -1;
			break;
		}

		}
		*/
	}
}


int main()
{
	Morpions_Cours();
	return 0;
}