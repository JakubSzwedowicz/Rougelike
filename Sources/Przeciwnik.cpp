#include "Przeciwnik.h"
#include "Jednostka.h"
#include <cstdlib>
#include "Gra.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

Przeciwnik::Przeciwnik(float _hp, int _numer, int _x, int _y, Gra& _gierka, float _dmg, Jednostka& _wrog, int _kierunek, char _ikona) : Jednostka(_hp, _numer, _x, _y, _gierka, _ikona, _kierunek), wrog(_wrog)
{	
	dmg = _dmg;
	liczba_strzalow = 5;
}
void Przeciwnik::Akcja()
{
	// kierunek: 1 gora, 2, prawo, 3 lewo, 4 dol
	int kierunek_x = wrog.ZwrocX() - x;
	int kierunek_y = wrog.ZwrocY() - y;
	if (kierunek_x == 0 || kierunek_y == 0)
	{
		kierunek = gierka.CzyWidacGracza(*this);
		if (kierunek == 0)
			RuszSie(kierunek_x, kierunek_y);
		else
			OddajStrzal(kierunek);
	}
	else
		RuszSie(kierunek_x, kierunek_y);		
}
void Przeciwnik::RuszSie(int kierunek_x, int kierunek_y)
{
	int los = rand() % 10;
	switch (los)
	{
	case 0:
		if (kierunek_x > 0)
			Dzialanie(KEY_DOWN);
		else
			Dzialanie(KEY_UP);
		break;
	case 1:
		if (kierunek_y > 0)
			Dzialanie(KEY_RIGHT);
		else
			Dzialanie(KEY_LEFT);
		break;
	default:
		los = rand() % 4;
		switch (los)
		{
		case 0:
			Dzialanie(KEY_DOWN);
			break;
		case 1:
			Dzialanie(KEY_UP);
			break;
		case 2:
			Dzialanie(KEY_RIGHT);
			break;
		case 3:
			Dzialanie(KEY_LEFT);
			break;
		}
	}
}
void Przeciwnik::OddajStrzal(int _kierunek)
{
	if (liczba_strzalow > 0)
	{
		if (gierka.WystrzelPocisk<float>(*this, dmg, _kierunek))
			liczba_strzalow--;
	}

}
