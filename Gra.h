#pragma once
#include "Jednostka.h"
#include "Gracz.h"
#include "Plansza.h"

struct opcje
{
	float hp_gracza, szybkosc_przeciwnikow, hp_wrogow;
	int pociski_gracza, dmg_przeciwnikow, dmg_gracza;
};

class Jednostka;
class Gra
{
private:
	std::vector<Jednostka*> wszyscy;
	int liczba_obiektow;
	Plansza *mapa;
	bool koniec;
	opcje ustawienia;
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
	void OdswierzObraz(std::vector<std::string>& stare_pole);
	void Graj();
	Plansza& ZwrocPlansze() { return *mapa; };
	template<typename T>
	bool WystrzelPocisk(Jednostka& obiekt, T _dmg, int kierunek);
	template <typename T>
	void StworzObiekt(int opcja, int nowy_x, int nowy_y, int kierunek =0, T _dmg = 0);
};