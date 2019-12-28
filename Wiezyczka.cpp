#include "Wiezyczka.h"
#include "Gra.h"
#include "Jednostka.h"

Wiezyczka::Wiezyczka(int _numer, int _x, int _y, Gra& _gierka, int _dmg, float _hp, int _kierunek, char _ikona) : Jednostka(_hp, _numer, _x, _y, _gierka, _ikona, _kierunek), dmg(_dmg)
{

}
void Wiezyczka::OddajStrzal(int _kierunek)
{		
	gierka.WystrzelPocisk<int>(*this, dmg, _kierunek);
}
void Wiezyczka::Akcja()
{
	int los = rand() % 2;
	if (los == 0)
		for (int i = 1; i < 5; i++)
			OddajStrzal(i);
}