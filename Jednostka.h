#pragma once
//#include "Gra.h"

class Gra;
class Jednostka
{
protected: 
	float hp;
	char ikona;
	int x;
	int y;
	int kierunek;
	int numer;
	Gra& gierka;
public:
	Jednostka(int _numer, int _x, int _y, int _kierunek, Gra& _gierka, float _hp, char _ikona);
	virtual ~Jednostka();
	float DajHp();
	char DajIkona();
	virtual void Ruch(int kierunek);
	void AktualizujPozycje(int _x, int _y);
	virtual void Dzialanie(unsigned char znak);
	virtual void Dzialanie() {};
	virtual int DajLiczbeStrzalow() { return 0; };
	virtual float DajDmg() { return 0; };
	int DajNumer();
	void UstawNumer(int _numer);
	virtual void OddajStrzal() {};
	virtual void Akcja() {};
	void operator-=(float dmg);
	int ZwrocX();
	int ZwrocY();	
	int ZwrocKierunek();
};