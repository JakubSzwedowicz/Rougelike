#pragma once
#include "Jednostka.h"


class Gra;
template<typename T>
class Pocisk : public Jednostka
{
private:
	T dmg;
public:
	Pocisk(T _dmg, int _numer, int _x, int _y, int _kierunek, Gra& _gierka, float _hp = 1, char _ikona = '*');
	virtual void Akcja();
	virtual float DajDmg() { return dmg; };
};