#pragma once
#include "Jednostka.h"

class Obiekt : public Jednostka
{
private:
public:
	Obiekt(int _x, int _y, Gra& _gierka, int _numer, int _kierunek = 0, float _hp = 100, char _ikona = 'O') : Jednostka(_hp, _numer, _x, _y, _gierka, _ikona, _kierunek)
	{};
	virtual void Akcja() {};
};