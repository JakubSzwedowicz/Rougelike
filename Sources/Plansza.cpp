#include <iostream>
#include "Plansza.h"

Plansza::Plansza(int _x, int _y, std::vector<std::string> _pola)
{
	rozmiar_x = _x;
	rozmiar_y = _y;
	pola.resize(rozmiar_x);
	pola = _pola;
}
int Plansza::ZwrocRozmiar_X()
{
	return rozmiar_x;
}
int Plansza::ZwrocRozmiar_Y()
{
	return rozmiar_y;
}
char Plansza::ZwrocPole(int _x, int _y)
{
	if(_x > -1 && _y > -1)
		return pola[_x][_y];
}
void Plansza::ZmienPole(char obiekt, int _x, int _y)
{
	pola[_x][_y] = obiekt;
}

void Plansza::NowaPozycja(int _x, int _y, int nowe_x, int nowe_y)
{
	// kierunek: 1 gora, 2, prawo, 3 lewo, 4 dol
	ZmienPole(ZwrocPole(_x, _y), nowe_x, nowe_y);
	ZmienPole(' ', _x, _y);
}
void Plansza::Wyswietl()
{
	for (int i = 0; i < pola.size(); i++)
	{
		std::cout << pola[i] << std::endl;
	}
}
std::vector<std::string> Plansza::ZwrocCalaPlansze()
{
	return pola;
}