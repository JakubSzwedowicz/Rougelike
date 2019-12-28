#pragma once
#include "Jednostka.h"

class Mina : public Jednostka
{
private:
	int dmg;
public:
	Mina(int _dmg, int _numer, int _x, int _y, int _kierunek, Gra& _gierka, float _hp = 1, char _ikona = 'M');
	virtual void Akcja();
	virtual float DajDmg() { return dmg; };
};