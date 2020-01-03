#pragma once
#include <iostream>
#include <vector>
#include <string>


class Plansza
{
	private:
		std::vector<std::string> pola;
		int rozmiar_x, rozmiar_y;
	public:
		Plansza(int _x, int _y, std::vector<std::string> _pola);
		int ZwrocRozmiar_X();
		int ZwrocRozmiar_Y();
		char ZwrocPole(int _x, int _y);
		void ZmienPole(char obiekt, int _x, int _y);
		void PrzesunObjekt(int _x, int _y, int kierunek);
		void NowaPozycja(int _x, int _y, int nowe_x, int nowe_y);
		void Wyswietl();
		std::vector<std::string> ZwrocCalaPlansze();

};