#include "Pocisk.h"
#include <iostream>


template class Pocisk<int>;
template class Pocisk<float>;

template<typename T>
Pocisk<T>::Pocisk(T _dmg, int _numer, int _x, int _y, int _kierunek, Gra& _gierka, float _hp, char _ikona) : Jednostka(_numer, _x, _y, _kierunek, _gierka, _hp, _ikona)
{
	dmg = _dmg;
}

template<typename T>
void Pocisk<T>::Akcja()
{
	Ruch(kierunek);
}