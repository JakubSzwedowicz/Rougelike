#include <iostream>
#include "Jednostka.h"
#include "Gra.h"
#include "Gracz.h"
#include "Plansza.h"
#include "Przeciwnik.h"
#include "Obiekt.h"
#include "Pocisk.h"
#include "Mina.h"
#include "Wiezyczka.h"
#include "GlobalneFunkcje.h"
#include <conio.h>
#include <fstream>
#include <time.h>



/*#include <thread>
#include <boost/ref.hpp>
#include <functional>
#include <chrono>
#include <future>
#include <mutex>*/


template bool Gra::WystrzelPocisk<int>(Jednostka& obiekt, int _dmg, int kierunek);
template bool Gra::WystrzelPocisk<float>(Jednostka& obiekt, float _dmg, int kierunek);

Gra::Gra()
{
	mapa = nullptr;
	koniec = false;
	czlowiek = 0;
	liczba_obiektow = 0;
	ustawienia.hp_gracza = 50;
	ustawienia.hp_wrogow = 1;
	ustawienia.dmg_gracza = 1;
	ustawienia.dmg_przeciwnikow = 1;
	ustawienia.pociski_gracza = 100;
	ustawienia.szybkosc_przeciwnikow = 4;
}
void Gra::Menu()
{
	int decyzja;
	bool flaga1 = true;
	while (flaga1)
	{
		try
		{
			system("cls");
			std::cout << "Menu: \n 1. Zacznij gre. \n 2. Wczytaj mape \n 3. Ustawienia \n 4. Zakoncz gre \n";
			decyzja = kontrola_bledow(1, 4);
			switch (decyzja)
			{
			case 1:
				Graj();
				Posprzataj();
				break;
			case 2:
				if (mapa != nullptr)
					Posprzataj();
				WczytajMape();
				break;
			case 3:	
				if (mapa != nullptr)
					throw "Juz wczytano mape! \n";
				std::cout << "1. Latwy \n 2. sredni \n 3. trudny \n 4. Uzytkownika \n";
				decyzja = kontrola_bledow(1, 4);
				ZmienUstawienia(decyzja);
				break;
			case 4:
				flaga1 = false;
				break;
			}
		}
		catch (const char *tekst)
		{
			std::cout << tekst << std::endl;
			system("pause");
		}
		catch (...)
		{
			std::cout << "Wystapil nieznany blad! \n";
			system("pause");
		}
	}	
}
void Gra::ZmienUstawienia(int decyzja)
{	
	switch (decyzja)
	{
	case 1:
		ustawienia.hp_gracza = 50;
		ustawienia.hp_wrogow = 1;
		ustawienia.dmg_gracza = 1;
		ustawienia.dmg_przeciwnikow = 1;
		ustawienia.pociski_gracza = 100;
		ustawienia.szybkosc_przeciwnikow = 4;
		break;
	case 2:
		ustawienia.hp_gracza = 25;
		ustawienia.hp_wrogow = 2;
		ustawienia.dmg_gracza = 1;
		ustawienia.dmg_przeciwnikow = 2;
		ustawienia.pociski_gracza = 50;
		ustawienia.szybkosc_przeciwnikow = 2;
		break;
	case 3:
		ustawienia.hp_gracza = 10;
		ustawienia.hp_wrogow = 3;
		ustawienia.dmg_gracza = 1;
		ustawienia.dmg_przeciwnikow = 3;
		ustawienia.pociski_gracza = 20;
		ustawienia.szybkosc_przeciwnikow = 1;
		break;
	case 4:
		int liczba;
		std::cout << "Podaj hp_gracza \n";
		liczba = kontrola_bledow(1, 100000);
		ustawienia.hp_gracza = liczba;
		std::cout << "Podaj hp_wrogow \n";
		liczba = kontrola_bledow(1, 100000);
		ustawienia.hp_wrogow = liczba;
		std::cout << "Podaj dmg_gracza \n";		
		liczba = kontrola_bledow(1, 100000);
		ustawienia.dmg_gracza = liczba;
		std::cout << "Podaj liczbe pociskow gracza \n";
		liczba = kontrola_bledow(1, 100000);
		ustawienia.pociski_gracza = liczba;
		std::cout << "Podaj szybkosc gry (im mniej tym szybciej) \n";
		liczba = kontrola_bledow(1, 100000);
		ustawienia.szybkosc_przeciwnikow = liczba;
		break;
	}	
}
void Gra::Posprzataj()
{
	for (int i = 0; i < wszyscy.size(); i++)	
		delete wszyscy[i];
	delete mapa;
	mapa = nullptr;
	koniec = false;
	wszyscy.clear();
	liczba_obiektow = 0;
}
void Gra::WczytajMape()
{
	std::ifstream plik;
	char nazwa_pliku[50];
	skanuj_folder();
	std::cout << "Ktory plik chcesz wczytac? \n";
	std::cin >> nazwa_pliku;
	std::string sciezka("Maps\\");
	sciezka.append(nazwa_pliku);	
	plik.open(sciezka, std::ifstream::in);
	if (plik.is_open())
	{
		int x, y, i = 0;
		std::vector<std::string> mapa_z_pliku;
		plik >> x;
		plik >> y;		
		plik.get();
		mapa_z_pliku.resize(x);
		while (!plik.eof())
		{
			std::getline(plik, mapa_z_pliku[i]);
			i++;
		}
		mapa = new Plansza(x, y, mapa_z_pliku);
		SynchronizujObiektyZPlansza();
		plik.close();
	}
	else throw "Nie udalo siê otworzyc pliku! \n";
}
void Gra::SynchronizujObiektyZPlansza()
{	
	for(int i = 0; i < mapa->ZwrocRozmiar_X(); i++)
		for (int j = 0; j < mapa->ZwrocRozmiar_Y(); j++)
		{
			char znak = mapa->ZwrocPole(i, j);
			switch (znak)
			{
			case 'G':
				StworzObiekt(1, i, j, 1, 1);
				break;
			case 'P':
				StworzObiekt(3, i, j, 1, float(0.5)); // Dlaczego domaga siê floata? Wygl¹da na to, ¿e template nie akceptuje double, czy to ze wzglêdu na deklaracjê w cpp bez double?
				break;
			case 'M':
				StworzObiekt(5, i, j, 1, 2);
				break;
			case 'O':
				StworzObiekt<int>(4, i, j);
				break;
			case 'W':
				StworzObiekt<int>(6, i, j);
				break;
			}
		}
}
void Gra::ZakonczNatychmiast()
{
	koniec = true;
}
bool Gra::PrzesunObjekt(Jednostka& obiekt, int _kierunek)
{
	// kierunek: 1 gora, 2 prawo, 3 lewo, 4 dol
	int nowy_x, nowy_y;
	char pole;
		switch (_kierunek)
		{
		case 1:
			nowy_x = obiekt.ZwrocX() - 1;
			nowy_y = obiekt.ZwrocY();
			break;
		case 2:
			nowy_x = obiekt.ZwrocX();
			nowy_y = obiekt.ZwrocY() + 1;
			break;
		case 3:
			nowy_x = obiekt.ZwrocX();
			nowy_y = obiekt.ZwrocY() - 1;
			break;
		case 4:
			nowy_x = obiekt.ZwrocX() + 1;
			nowy_y = obiekt.ZwrocY();
			break;
		}
		pole = mapa->ZwrocPole(nowy_x, nowy_y);
		if (pole == ' ')
		{
			mapa->NowaPozycja(obiekt.ZwrocX(), obiekt.ZwrocY(), nowy_x, nowy_y);
			obiekt.AktualizujPozycje(nowy_x, nowy_y);
			return true;
		}
		else if (pole == 'K')
		{
			koniec = true;
			return true;
		}
		else
		{
			DetekcjaKolizji(obiekt, nowy_x, nowy_y, _kierunek);
			return false;
		}
};
int Gra::CzyWidacGracza(Jednostka& obiekt)
{	
	char znak;
	for (int i = 1; (znak = mapa->ZwrocPole(obiekt.ZwrocX() - i, obiekt.ZwrocY())) != '#' && znak != 'O' && znak != 'P' && znak != 'M' && znak != 'W'; i++)
		if (znak == 'G')
			return 1;
	for (int i = 1; (znak = mapa->ZwrocPole(obiekt.ZwrocX() + i, obiekt.ZwrocY())) != '#' && znak != 'O' && znak != 'P' && znak != 'M' && znak != 'W'; i++)
		if (znak == 'G')
			return 4;
	for (int i = 1; (znak = mapa->ZwrocPole(obiekt.ZwrocX(), obiekt.ZwrocY() + i)) != '#' && znak != 'O' && znak != 'P' && znak != 'M' && znak != 'W'; i++)
		if (znak == 'G')
			return 2;
	for (int i = 1; (znak = mapa->ZwrocPole(obiekt.ZwrocX(), obiekt.ZwrocY() - i)) != '#' && znak != 'O' && znak != 'P' && znak != 'M' && znak != 'W'; i++)
		if (znak == 'G')
			return 3;
	return 0;	
}
void Gra::DetekcjaKolizji(Jednostka& obiekt, int _nowy_x, int _nowy_y, int _kierunek)
{
	char nieznany = mapa->ZwrocPole(_nowy_x, _nowy_y);
	switch (nieznany)
	{
	case'G':
		if (obiekt.DajIkona() == '*' || obiekt.DajIkona() == 'M')
		{
			*(wszyscy[ZwrocObiektZPozycji(_nowy_x, _nowy_y)]) -= obiekt.DajDmg();
			UsunObiekt(obiekt);			
		}		
		break;
	case '#':
		if (obiekt.DajIkona() == '*')
		{
			UsunObiekt(obiekt);			
		}
		break;
	case '*':
		if (obiekt.DajIkona() == '*')
		{
			UsunObiekt(obiekt);
			UsunObiekt(*(wszyscy[ZwrocObiektZPozycji(_nowy_x, _nowy_y)]));
		}
		else if (obiekt.DajIkona() == 'G')
		{
			obiekt -= wszyscy[ZwrocObiektZPozycji(_nowy_x, _nowy_y)]->DajDmg();
			UsunObiekt(*(wszyscy[ZwrocObiektZPozycji(_nowy_x, _nowy_y)]));
		}
		break;
	case 'P':
		if (obiekt.DajIkona() == '*')
		{
			*(wszyscy[ZwrocObiektZPozycji(_nowy_x, _nowy_y)]) -= obiekt.DajDmg();
			UsunObiekt(obiekt);			
		}
		break;
	case 'O':
		if (obiekt.DajIkona() == 'G')
		{
			PrzesunObjekt(*(wszyscy.at(ZwrocObiektZPozycji(_nowy_x, _nowy_y))), _kierunek);
		}
		else if (obiekt.DajIkona() == '*')
			UsunObiekt(obiekt);
		break;
	case 'M':
		if (obiekt.DajIkona() == '*')
		{
			UsunObiekt(*(wszyscy.at(ZwrocObiektZPozycji(_nowy_x, _nowy_y))));
			UsunObiekt(obiekt);
		}
		else if (obiekt.DajIkona() == 'G')
		{
			*(wszyscy[ZwrocObiektZPozycji(_nowy_x, _nowy_y)]) -= obiekt.DajDmg();
			UsunObiekt(obiekt);
		}
		break;
	case 'W':
		if (obiekt.DajIkona() == '*')
		{
			*(wszyscy[ZwrocObiektZPozycji(_nowy_x, _nowy_y)]) -= obiekt.DajDmg();
			UsunObiekt(obiekt);
		}
	}
}
int Gra::ZwrocObiektZPozycji(int x, int y)
{
	for (int i = 0; i < liczba_obiektow; i++)
	{
		if (wszyscy[i]->ZwrocX() == x)
			if (wszyscy[i]->ZwrocY() == y)
				return i;
	}
}
void Gra::UsunObiekt(Jednostka& obiekt)
{	
	if (obiekt.DajIkona() == 'G')
		koniec = true;
	mapa->ZmienPole(' ', obiekt.ZwrocX(), obiekt.ZwrocY());	
	liczba_obiektow--;
	wszyscy.erase(wszyscy.begin() + obiekt.DajNumer());	
	PoprawNumery(obiekt.DajNumer());
	delete& obiekt;	
	wszyscy.shrink_to_fit();
}
void Gra::PoprawNumery(int nowy_numer)
{
	for (int i = nowy_numer; i < liczba_obiektow; i++)
		wszyscy[i]->UstawNumer(i);
}
void Gra::OdswierzObraz(std::vector<std::string>& stare_pole, float& _hp, int& _pociski)
{
	//std::mutex mapa_mutex;
	//std::lock_guard<std::mutex> guard(mapa_mutex);
	//mapa_mutex.lock(); // Tutaj powinny znaleŸæ siê blokady dostêpu do mapy ¿eby w¹tek nie edytowa³ mapy w trakcie odœwie¿ania obrazu
	ustaw_pozycje_kursora(0, 0);
	for (int x = 0; x != mapa->ZwrocRozmiar_X(); ++x)
	{
		for (int y = 0; y != mapa->ZwrocRozmiar_Y(); ++y)
		{
			if (mapa->ZwrocPole(x, y) == stare_pole[x][y]) {
				continue;
			}
			ustaw_pozycje_kursora(y, x);
			std::cout << mapa->ZwrocPole(x, y);
		}
	}
	if (_hp != wszyscy[czlowiek]->DajHp() || _pociski != wszyscy[czlowiek]->DajLiczbeStrzalow())
	{
		cls(0, mapa->ZwrocRozmiar_X() + 2);
		ustaw_pozycje_kursora(0, mapa->ZwrocRozmiar_X() + 2);		
		std::cout << "Panel Gracza: \n";
		std::cout << "Hp: " << wszyscy[czlowiek]->DajHp() << std::endl;
		std::cout << "pociski: " << wszyscy[czlowiek]->DajLiczbeStrzalow() << std::endl;
		_hp = wszyscy[czlowiek]->DajHp();
		_pociski = wszyscy[czlowiek]->DajLiczbeStrzalow();
	}
	std::cout.flush();
	//mapa_mutex.unlock();
	
}

void Gra::Graj()
{
	if (mapa == nullptr)
		throw "Najpierw wczytaj mape! \n";	
	unsigned char znak;
	float hp = 0;
	int pociski = 0;
	clock_t tura_botow = clock() + 250 * ustawienia.szybkosc_przeciwnikow * CLOCKS_PER_SEC/1000;
	clock_t tura_pociskow = clock() + 125 * ustawienia.szybkosc_przeciwnikow * CLOCKS_PER_SEC / 1000;	
	bool odswierz_ekran = true;
	system("cls");
	mapa->Wyswietl();	
	while (!koniec)
	{
		std::vector<std::string> stare_pole(mapa->ZwrocCalaPlansze());
		if (_kbhit())
			{
				znak = _getch();
				wszyscy[czlowiek]->Dzialanie(znak);
				odswierz_ekran = true;
			}
		if (tura_pociskow < clock())
		{
			for (int i = 0; i < liczba_obiektow; i++)
			{
				if (wszyscy[i]->DajIkona() != '*')
					continue;
				else
					wszyscy[i]->Akcja();				
			}
			odswierz_ekran = true;
			tura_pociskow = clock() + 125 * ustawienia.szybkosc_przeciwnikow * CLOCKS_PER_SEC / 1000;
		}
		if (tura_botow < clock())
		{
			for (int i = 0; i < liczba_obiektow; i++)
				if (wszyscy[i]->DajIkona() == '*' || wszyscy[i]->DajIkona() == 'G')
					continue;
				else
					wszyscy[i]->Akcja();
			odswierz_ekran = true;
			tura_botow = clock() + 250 * ustawienia.szybkosc_przeciwnikow * CLOCKS_PER_SEC / 1000;
		}
		if (odswierz_ekran)
		{
			OdswierzObraz(stare_pole, hp, pociski);
			odswierz_ekran = false;
		}
	}
	std::cout << "Koniec gry! \n";
	system("pause");
}
template<typename T>
bool Gra::WystrzelPocisk(Jednostka& obiekt, T _dmg, int kierunek)
{
	int nowy_x, nowy_y;
	switch (kierunek)
	{
	case 1:
		nowy_x = obiekt.ZwrocX() - 1;
		nowy_y = obiekt.ZwrocY();
		break;
	case 2:
		nowy_x = obiekt.ZwrocX();
		nowy_y = obiekt.ZwrocY() + 1;
		break;
	case 3:
		nowy_x = obiekt.ZwrocX();
		nowy_y = obiekt.ZwrocY() - 1;
		break;
	case 4:
		nowy_x = obiekt.ZwrocX() + 1;
		nowy_y = obiekt.ZwrocY();
		break;
	}
	if (mapa->ZwrocPole(nowy_x, nowy_y) == ' ')
	{
		StworzObiekt(2, nowy_x, nowy_y, kierunek, _dmg);
		return true;		
	}
	return false;
}
template<typename T>//https://stackoverflow.com/questions/48097444/why-do-i-get-error-c2768-with-using-template-type-where-i-need-the-type-as-point
void Gra::StworzObiekt(int opcja, int nowy_x, int nowy_y, int kierunek, T _dmg) 
{
	int i = 0;
	switch (opcja) // 1 - gracz, 2 - pocisk, 3 - przeciwnik, 4 - obiekt, 5 - mina, 6 - wie¿yczka
	{
	case 1:
		czlowiek = liczba_obiektow;
		wszyscy.push_back(new Gracz(_dmg * ustawienia.dmg_gracza, ustawienia.pociski_gracza, liczba_obiektow, nowy_x, nowy_y, kierunek, *this, ustawienia.hp_gracza));
		//mapa->ZmienPole(wszyscy[liczba_obiektow]->DajIkona(), nowy_x, nowy_y);
		liczba_obiektow++;
		break;
	case 2:
		wszyscy.push_back(new Pocisk<T>(_dmg, liczba_obiektow, nowy_x, nowy_y, kierunek, *this));
		mapa->ZmienPole(wszyscy[liczba_obiektow]->DajIkona(), nowy_x, nowy_y);
		liczba_obiektow++;
		break;
	case 3:				
		while (wszyscy[i]->DajIkona() != 'G') i++;
		wszyscy.push_back(new Przeciwnik(ustawienia.hp_wrogow, liczba_obiektow, nowy_x, nowy_y, *this, _dmg * ustawienia.dmg_przeciwnikow, *(wszyscy.at(i))));
		//mapa->ZmienPole(wszyscy[liczba_obiektow]->DajIkona(), nowy_x, nowy_y);
		liczba_obiektow++;
		break;
	case 4:
		wszyscy.push_back(new Obiekt(nowy_x, nowy_y, *this, liczba_obiektow));
		//mapa->ZmienPole(wszyscy[liczba_obiektow]->DajIkona(), nowy_x, nowy_y);
		liczba_obiektow++;
		break;
	case 5:
		wszyscy.push_back(new Mina(1 * ustawienia.dmg_przeciwnikow, liczba_obiektow, nowy_x, nowy_y, kierunek, *this));
		liczba_obiektow++;
		break;
	case 6:
		wszyscy.push_back(new Wiezyczka(liczba_obiektow, nowy_x, nowy_y, *this, 1 * ustawienia.dmg_przeciwnikow));
		liczba_obiektow++;
		break;
	}
}

