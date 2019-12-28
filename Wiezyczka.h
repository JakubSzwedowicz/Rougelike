#pragma once

#include "Jednostka.h"

class Wiezyczka : public Jednostka
{
private:
	int dmg;
public:
	Wiezyczka(int _numer, int _x, int _y, Gra& _gierka, int _dmg, float _hp = 1, int _kierunek = 0, char _ikona = 'P');
	virtual void OddajStrzal(int _kierunek);
	virtual void Akcja();
};