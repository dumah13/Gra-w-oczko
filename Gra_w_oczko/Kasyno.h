#include "Gracz.h"
#include "Bot.h"
#include "Karta.h"

#pragma once


class Kasyno
{
public:
	//Statyczne sta³e, parametry gry u¿ywane potem w grze i podczas inicjalizacji
	const static int LiczbaKolorow = 4;
	const static int LiczbaFigur = 13;
	const static int LiczbaKart = 52;
	const static int MaxLiczbaBotow = 3;
	const static int MaxLiczbaLudzkichGraczy = 3;
	const static int MaxLiczbaGraczy = MaxLiczbaBotow + MaxLiczbaLudzkichGraczy;
	const static int LiczbaKartNaStart = 2;

private:
	int iNrBota;
	int iNrGracza;

	Gracz* gGracze[MaxLiczbaGraczy];
	Karta kKarty[LiczbaKart];
	int iWydaneKarty;
	int iLiczbaGraczyLudzkich;
	int iLiczbaBotow;
	int iLiczbaGraczy;
public:

	//Konstruktor domyœlny/przeci¹¿ony
	Kasyno(bool _bNazwijGraczy = true, int _iLiczbaGraczyLudzkich = 1, int _iLiczbaBotow = 1);

	//Metody


	void tasuj(int _iLiczbaPrzetasowan = 100);
	Karta* dajKarte();
	void wypiszKarty();
	
	void rozpocznijRozgrywke();
	void wyswietlRekeGracza(int _iGracz, ostream& _os = cout);
	bool czyWszyscySpasowali();
	void zakonczGre();
	void zapiszGre(string _nazwaPliku = "rozgrywki.txt");
	bool wykonajTure();
	void wypiszPodsumowanie(ostream& _os = cout);
	void nowaGra(bool _bNazwij = true,  int _iLiczbaGraczyLudzkich = 1, int _iLiczbaBotow = 1);
	

	//Gettery

	int GetWydaneKarty() { return iWydaneKarty; }

	//Operatory

	//Destruktor
	~Kasyno();

private:
	//Metody prywatne

	string nazwijGracza();
	string nazwijBota();
	void sprawdzLiczbeGraczy(int _iLiczbaBotow, int _iLiczbaGraczy);
	bool* sprawdzWygrane();
	void inicjalizujGraczy(bool _bNazwij);
	void zamienKarty(Karta& _kKarta1, Karta& _kKarta2);
};
