#pragma once
#include "Jednostka.h"
//#include "Gra.h"

class Gra;
class Gracz : public Jednostka
{
private:
	int dmg;
	int liczba_strzalow;
public:
	Gracz(int _dmg, int _liczba_strzalow, int _numer, int _x, int _y, int _kierunek, Gra &_gierka, float _hp, char _ikona = 'G');
	void OddajStrzal();
	int DajLiczbeStrzalow();
	void Akcja();
	
};