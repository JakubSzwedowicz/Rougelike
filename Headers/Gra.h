#pragma once
#include "Jednostka.h"
#include "Gracz.h"
#include "Plansza.h"
#include "Opcje.h"



//class Jednostka;
class Gra
{
private:
	std::vector<Jednostka*> wszyscy;
	int liczba_obiektow, czlowiek;
	Plansza *mapa;
	bool koniec;
	Opcje ustawienia;
public:
	Gra();
	void Menu();
	void ZmienUstawienia(int decyzja);
	void Posprzataj();
	void WczytajMape();
	void SynchronizujObiektyZPlansza();
	void ZakonczNatychmiast();
	bool PrzesunObjekt(Jednostka& obiekt, int _kierunek);
	int CzyWidacGracza(Jednostka& obiekt);
	void DetekcjaKolizji(Jednostka& _obiekt, int _nowy_x, int _nowy_y, int kierunek);
	int ZwrocObiektZPozycji(int x, int y);
	void UsunObiekt(Jednostka& obiekt);
	void PoprawNumery(int nowy_numer);
	void OdswierzObraz(std::vector<std::string>& stare_pole, float& _hp, int& _pociski);
	void Graj();
	Plansza& ZwrocPlansze() { return *mapa; };
	template<typename T>
	bool WystrzelPocisk(Jednostka& obiekt, T _dmg, int kierunek);
	template <typename T>
	void StworzObiekt(int opcja, int nowy_x, int nowy_y, int kierunek =0, T _dmg = 0);
};