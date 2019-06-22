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
	Przeciwnik(Jednostka& _wrog, int _numer, int _x, int _y, int _kierunek, Gra& _gierka, float _hp, float _dmg, char _ikona = 'P');
	virtual void Akcja();
	void RuszSie(int kierunek_x, int kierunek_y);
	bool DetekcjaGracza();
	virtual void OddajStrzal(int kierunek);
};