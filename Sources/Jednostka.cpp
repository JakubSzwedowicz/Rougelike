#include <iostream>
#include "Jednostka.h"
#include "Gra.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

Jednostka::Jednostka(float _hp, int _numer, int _x, int _y, Gra& _gierka, char _ikona, int _kierunek) : hp(_hp), numer(_numer), x(_x), y(_y), gierka(_gierka), ikona(_ikona), kierunek(_kierunek)
{

};
Jednostka::~Jednostka()
{
};
float Jednostka::DajHp()
{
	return hp;
}

char Jednostka::DajIkona()
{
	return ikona;
}
void Jednostka::AktualizujPozycje(int _x, int _y)
{
	x = _x;
	y = _y;
}
void Jednostka::Ruch(int _kierunek)
{		
	if (gierka.PrzesunObjekt(*this, _kierunek))
	{
		kierunek = _kierunek;
	}
}
void Jednostka::Dzialanie(unsigned char znak)
{
	// kierunek: 1 gora, 2, prawo, 3 lewo, 4 dol
	switch (znak)
	{
	case KEY_UP:
		Ruch(1);
		break;
	case KEY_RIGHT:
		Ruch(2);
		break;
	case KEY_LEFT:
		Ruch(3);
		break;
	case KEY_DOWN:
		Ruch(4);
		break;	
	case 's':
		OddajStrzal();
		break;
	case 'q':
		gierka.ZakonczNatychmiast();
		break;
	}
}
int Jednostka::DajNumer()
{
	return numer;
}
void Jednostka::UstawNumer(int _numer)
{
	numer = _numer;
}
void Jednostka::operator-=(float dmg)
{	
	hp -= dmg;
	if (hp <= 0)
		gierka.UsunObiekt(*this);
};
int Jednostka::ZwrocX()
{
	return x;
}
int Jednostka::ZwrocY()
{
	return y;
}
int Jednostka::ZwrocKierunek()
{
	return kierunek;
}
