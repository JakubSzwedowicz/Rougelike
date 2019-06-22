#include <iostream>
#include "Mina.h"

void Mina::Akcja()
{
	int kierunek = rand() % 4;
	kierunek++;
	Ruch(kierunek);
}