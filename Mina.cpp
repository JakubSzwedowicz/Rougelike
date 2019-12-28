#include <iostream>
#include "Mina.h"

void Mina::Akcja()
{
	int kierunek = rand() % 4;
	kierunek++;
	Ruch(kierunek);
}

Mina::Mina(int _dmg, int _numer, int _x, int _y, int _kierunek, Gra& _gierka, float _hp, char _ikona) : Jednostka(_hp, _numer, _x, _y, _gierka, _ikona, _kierunek), dmg(_dmg)
{

};