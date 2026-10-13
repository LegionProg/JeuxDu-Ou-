#include <iostream>
#include <conio.h>


int Generator(int max)
{
	return rand() % (max + 1);
}



int ChekWin(int tab[], int symbole, int n2)
{
	for (int i = 0; i < n2; i++)
	{
		int index = i * n2;

		if (tab[index] == tab[index + 1] && tab[index] == tab[index + 2] && tab[index] != 0 && tab[0 * n2 + 1] == tab[index + 2]) // verticale
			return symbole;
		if (tab[i] == tab[i + n2] && tab[i] == tab[i + n2 + n2] && tab[i] == tab[i+n2+n2+n2] && tab[i]!=0) // horisontal
			return symbole;
		if (tab[i] == tab[i + n2 + 1] && tab[i] == tab[i + n2 + 1 + n2 + 1] && tab[i]== tab[i + n2 + 1 + n2 + 1+n2+1] && tab[i] != 0) // diagonal gauche droite
			return symbole;
		if (tab[i + n2-1] == tab[i + n2-1 + n2-1 - 1] && tab[i] == tab[i + n2-1 + n2-1 - 1 + n2-1 - 1] && tab[i] == symbole) // diagonal droite gauche
			return symbole;

	}
	for (int i = 0; i < n2 * n2; i++)
	{
		if (tab[i] == 0)
			return 5;
	}
	return 1;
}






void PrintCell(int tab[], int n2, int posX, int posY)
{
	int a = n2 - 1;
	int b = 0;
	int tailleTab = n2 * n2;
	for (int i = 0; i < posX; i++)
	{
		std::cout << "         ";
	}
	std::cout << "    |"<< std::endl;

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
			if (posY == b)
			{
				std::cout << " <- ";
			}
			b++;
			a = a + n2;
			std::cout << std::endl;
		}
		
	}
}



int Choice(int min, int max, int tab[])
{
	int choice = 0;
	int posX = 0;
	int posY = 0;
	while (true)
	{
		system("cls");
		PrintCell(tab, max, posX, posY);

		choice = _getch();

		//std::cout << choice << std::endl; // debug 

		if (choice == 75) // fleche gauche
		{
			if (posX == min)
				std::cout << " Vous ne pouvez pas allez a gauche" << std::endl;
			else
				posX--;
		}
		else if (choice == 77) //77 fleche droite
		{
			if (posX == max-1)
				std::cout << " vous ne pouvez pas allez plus a droite " << std::endl;
			else
				posX++;
		}
		else if (choice == 80) // 80 fleche bas
		{
			if (posY == max-1)
				std::cout << " vous ne pouvez pas allez plus a bas " << std::endl;
			else
				posY++;
		}
		else if (choice == 72) // 72 fleche haute
		{
			if (posY == min)
				std::cout << " vous ne pouvez pas allez plus a haut " << std::endl;
			else
				posY--;
		}
		else if (choice == 13)// 13 = entrée 
		{
			posX = posX + (3 * (posY));
			return posX;
		}

	}
	return choice;
}

void Morpions_Cours()
{
	int numberPlayer = 1;
	int end = 0;
	int testeIf = 1;
	int choice = 0;
	bool noIdeaIA = false;
	int symbole;
	// tableau
	const int n = 20;
	for (int i = 0; i < n; i++)
	{
		
		int n2 = 3 + i;// pour

		const int sizeTab = n * n;
		int tab[sizeTab]; // {0}
	

		for (int i = 0; i < sizeTab; i++)
		{
			tab[i] = 0;
		}

		while (true)
		{

			int a = 2;

			
			std::cout << "Choisit une case" << std::endl;

			std::cout << std::endl;


			while (true)
			{

				choice = Choice(0, n2,tab);
				tab[choice] - 1;


				if (tab[choice] == 0)
				{
					tab[choice] = -1;
					break;
				}
				std::cout << "La case et deja prise" << std::endl;
			}

			// condition de victoire joueur
			end = ChekWin(tab, -1, n2);
			if (end == -1)
			{
				break;
			}
			else if (end == 1)
				break;


			//IA // inteligente (comme les premier IA pour les echeque
			noIdeaIA = true;
			symbole = -2;
			for (int i = 0; i <= 2; i++)
			{
				if (noIdeaIA)
				{
					for (int i = 0; i < n2; i++)// Chercher si uncoup lui permet de Win
					{
						if (tab[i] == symbole && tab[i + 1] == symbole && tab[i + 2] == 0) // si troue a droite
						{
							tab[i + 2] = -2;
							noIdeaIA = false;
							//std::cout << "IA vertical manque i+2" << symbole << std::endl;
							break;
						}

						else if (tab[i + 1] == symbole && tab[i + 2] == symbole && tab[i] == 0) // si troue a gauche
						{
							tab[i] = -2; // faire un autre for pour lui
							noIdeaIA = false;
							//std::cout << "IA vertical manque i" << symbole << std::endl; // probleme
							break;
						}
						else if (tab[i] == symbole && tab[i + 2] == symbole && tab[i + 1] == 0) // si troue au milieux
						{
							tab[i + 1] = -2;
							noIdeaIA = false;
							//std::cout << "IA vertical manque i+1" << std::endl;
							break;
						}

						// haut bas
						else if (tab[i] == symbole && tab[i + n] == symbole && tab[i + n + n] == 0)
						{
							tab[i + n + n] = -2;
							noIdeaIA = false;
							//std::cout << "IA horizontal manque i+n+n" << std::endl;
							break;
						}
						else if (tab[i] == symbole && tab[i + n + n] == symbole && tab[i + n] == 0)
						{
							tab[i + n] = -2;
							noIdeaIA = false;
							//std::cout << "IA horizontal manque i+n" << std::endl;
							break;
						}
						else if (tab[i + n] == symbole && tab[i + n + n] == symbole && tab[i] == 0)
						{
							tab[i] = -2;
							noIdeaIA = false;
							//std::cout << "IA horizontal manque i " << std::endl;
							break;
						}
					}
				}
				symbole = -1;// contrer adversaire 
			}

			if (noIdeaIA) // si l'ia na pas d'idée de quoi jouer alors il choisit rand 
			{
				while (true)
				{
					choice = Generator(n2 * n2);
					if (tab[choice] == 0)
					{
						tab[choice] = -2;
						break;
					}
				}
			}



			// teste si victoire bot
			end = ChekWin(tab, -2, n2);


			if (end == -2)
			{
				break;
			}
		}
		if (end == -1)
		{
			std::cout << "Joueur a gagner" << std::endl;
			PrintCell(tab, n2,0,0);
			break;
		}
		if (end == -2)
		{
			std::cout << "Machine a gagner" << std::endl;
			PrintCell(tab, n2,0,0);
			break;
		}
		std::cout << "agrandire le tableau car egaliter" << std::endl;
	}
	
}

/**/


int main()
{
	Morpions_Cours();
	return 0;
}