#pragma once
#include "Jednostka.h"
#include "Gracz.h"
class Przeciwnik : public Jednostka
{
private:
	float dmg;
	Jednostka& wrog;
	int liczba_strzalow;	
public:	
	Przeciwnik(float _hp, int _numer, int _x, int _y, Gra& _gierka, float _dmg, Jednostka& _wrog, int _kierunek = 1, char _ikona = 'P');
	virtual void Akcja();
	void RuszSie(int kierunek_x, int kierunek_y);
	bool DetekcjaGracza();
	virtual void OddajStrzal(int kierunek);
};