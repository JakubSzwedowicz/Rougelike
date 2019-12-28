#include <iostream>
#include "Gracz.h"
#include "Gra.h"
#include <ctime>
#include <conio.h>
Gracz::Gracz(int _dmg, int _liczba_strzalow, int _numer, int _x, int _y, int _kierunek, Gra& _gierka, float _hp, char _ikona) : Jednostka(_hp, _numer, _x, _y, _gierka, _ikona, _kierunek)
{
	dmg = _dmg;
	liczba_strzalow = _liczba_strzalow;
	hp = _hp;
}

void Gracz::OddajStrzal()
{
	if (liczba_strzalow > 0)
	{
		if (gierka.WystrzelPocisk<int>(*this, dmg, kierunek))
			liczba_strzalow--;
	}
		
}
int Gracz::DajLiczbeStrzalow()
{
	return liczba_strzalow;
}
void Gracz::Akcja()
{
	clock_t czas = clock() + 250 * CLOCKS_PER_SEC / 1000;
	while (!_kbhit() && clock() < czas);
	if (_kbhit())
	{
		char znak = _getch();
		Dzialanie(znak);
	}
}