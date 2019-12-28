#pragma once
#include <Windows.h>
#include <iostream>
#include "dirent.h" 
#undef max

#include <time.h>
#include <chrono>
#include <thread>
#include <mutex>

	// x - kolumna, y - wiersz
	void ustaw_pozycje_kursora(int x, int y)
	{
		static const HANDLE kursor = GetStdHandle(STD_OUTPUT_HANDLE);
		std::cout.flush();
		COORD pozycja = { (SHORT)x, (SHORT)y };
		SetConsoleCursorPosition(kursor, pozycja);
	}
	int kontrola_bledow(int a, int b)
	{
		int poprawka, flaga = 1;
		while (flaga)
		{
			std::cin >> poprawka;
			if (poprawka <= b && poprawka >= a && std::cin.fail() == false) //std::cin zwraca 0 przy z³ym formacie [ std::cin.failbit() ]
				flaga--;
			else
			{
				std::cout << "Wprowadzono bledna odpowiedz! \n";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
		}
		return poprawka;
	};
	void skanuj_folder()
	{
		DIR* folder;
		int i = 1;
		struct dirent* plik;
		if ((folder = opendir("przykladowe mapy")) != NULL)
		{
			while ((plik = readdir(folder)) != NULL)
			{
				if (plik->d_name[0] != '.')
				{
					printf("Plik %d: %s \n", i, plik->d_name);
					i++;
				}
			}
			closedir(folder);
		}
		else
		{
			perror("");
			throw ("Nie udalo sie otworzyc folderu! \n");
		}
	};
	
	/*void RuchyInnych(Gra &gierka, std::vector<Jednostka*>& _wszyscy, int& _liczba_obiektow, bool& koniec, bool& flaga1)
	{
		while (!koniec)
		{
			while (flaga1)
			{				
				std::this_thread::sleep_for(std::chrono::milliseconds(500));
				//std::vector<std::string> stare_pole(gierka.ZwrocPlansze().ZwrocCalaPlansze());
				for (int i = 0; i < _liczba_obiektow; i++)
				{
					if (_wszyscy[i]->DajIkona() == 'G') continue;
					_wszyscy[i]->Akcja();
				}
				//gierka.OdswierzObraz(stare_pole);
				flaga1 = false;
			}
		}
	}*/
	void cls(int x, int y)
	{
		static const HANDLE kursor = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_SCREEN_BUFFER_INFO informacje;
		COORD pozycja = {x, y};
		std::cout.flush();
		if (!GetConsoleScreenBufferInfo(kursor, &informacje))
			abort();		
		DWORD dlugosc = (informacje.dwSize.X - x) * (informacje.dwSize.Y - y);
		DWORD temp;
		FillConsoleOutputCharacter(kursor, ' ', dlugosc, pozycja, &temp);
	}


/*void RuchyInnych(Jednostka** _wszyscy, int _liczba_obiektow, bool koniec) // Problem le¿y w tym, ¿e w¹tek dzia³a szybciej ni¿ odœwierzanie planszy std::mutex?
{
	
	while (!koniec)
	{			
		while (_liczba_obiektow != 0)
		{	
			
			std::this_thread::sleep_for(std::chrono::milliseconds(250));
			for (int j = 0; j < _liczba_obiektow; j++)
			{
				_wszyscy[j]->Akcja();
			}
		}

		
	}
}*/

/*void RuchyInnych(std::vector<Jednostka*> &_wszyscy, int &_liczba_obiektow, bool &koniec, bool &watek_dziala, bool &flaga_watku)
{	
	while (!koniec)
	{
		//std::this_thread::sleep_for(std::chrono::milliseconds(500));
		while (watek_dziala)
		{			
			for (int i = 0; i < _liczba_obiektow; i++)
			{
				if (_wszyscy[i]->DajIkona() == 'G') continue;
				_wszyscy[i]->Akcja();
			}
			watek_dziala = false;
			flaga_watku = false;
		}
	}
	
}*/



