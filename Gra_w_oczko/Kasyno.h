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
	const static int MaxLiczbaPunktowDoWygrania = 21;

private:
	//Zmienne prywatne

	int iNrBota;
	int iNrGracza;

	//Tablica graczy jest statyczna dla wygody w gruncie rzeczy, obiekty graczy i tak s¹ dynamiczne
	//ETAP 1 - KOMPOZYCJA (1..3 Gracz i 1..3 Bot)
	Gracz* gGracze[MaxLiczbaGraczy]; //czas ¿ycia zarz¹dzany przez Kasyno
	//ETAP 1 - KOMPOZYCJA (52)
	Karta kKarty[LiczbaKart]; //Czas ¿ycia zarz¹dzany przez Kasyno
	int iWydaneKarty;
	int iLiczbaGraczyLudzkich;
	int iLiczbaBotow;
	int iLiczbaGraczy;

public:
	//Dla wprawy spróbowa³em zrobiæ tak, ¿eby ta klasa spe³nia³a zasadê trzech (wielk¹ trójkê)

	//KONSTRUKTORY

	//ETAP 4 - WSPÓLNA TABLICY GRACZY LUDZKICH I BOTÓW
	//ETAP 3 - FUNKCJONALNOŒÆ TWORZENIA DYNAMICZNYCH OBIEKTÓW KLASY BOT
	//ETAP 1 - PRZYGOTOWANIE 52 KART
	//Konstruktor domyœlny/przeci¹¿ony
	Kasyno(bool _bNazwijGraczy = true, int _iLiczbaGraczyLudzkich = 1, int _iLiczbaBotow = 1);
	//Konstruktor kopiuj¹cy - REGU£A TRZECH
	Kasyno(const Kasyno& _ksKasyno);

	//METODY

	//ETAP 1 - TASOWANIE
	//Zamienia miejscami dwie Karty w talii _iLiczbaPrzetasowan razy.
	void tasuj(int _iLiczbaPrzetasowan = 200);

	//ETAP 1 - WYDAWANIE UNIKALNYCH KART
	//Przekazuje wskaznik do nastepnej niewykorzystanej Karty w talii
	//Zwraca: wskaŸnik na Kartê z tablicy kKarty
	Karta* dajKarte();

	//Wypisuje do cout wszystkie karty w talii
	void wypiszKarty();


	//ETAP 1 - GRAJ
	//Metoda graj() z instrukcji - tasuje talie i daje ka¿demu graczowi po 2 karty
	void rozpocznijRozgrywke();

	//Wyœwietla Karty posiadane przez _iGracza z tablicy gGracze w strumieniu wyjœciowym _os
	void wyswietlRekeGracza(int _iGracz, ostream& _os = cout);

	//ETAP 2 - OKREŒLENIE CZY WSZYSCY SPASOWALI
	//Sprawdza czy wszyscy obecnie graj¹cy gracze spasowali
	//Zwraca: true je¿eli wszyscy spasowali, w innym przypadku false
	bool czyWszyscySpasowali();

	//Metoda koñcz¹ca rozgrywkê i wyœwietlaj¹ca wyniki.
	void zakonczGre();

	//ETAP 2 - ZAPISYWANIE STANU PO ROZGRYWCE W PLIKU TEKSTOWYM  
	//Metoda zapisuj¹ca stan gry do pliku _nazwaPliku - 
	//UWAGA, ¯EBY ODCZYTAÆ PLIK PRAWID£OWO NALE¯Y ZMIENIÆ CZCIONKÊ W NOTATNIKU NA 'TERMINAL'
	void zapiszGre(string _nazwaPliku = "rozgrywki.txt");

	//ETAP 2 - SPRAWDZANIE CZY GRACZ POBRA£ KARTÊ CZY SPASOWA£
	//G³ówna metoda logiki gry - w œrodku wszyscy Gracze s¹ proszeni o wykonanie akcji, po czym sprawdzane jest czy rozgrywka zosta³a zakoñczona i podsumowanie jej
	//Zwraca: true jeœli grê mo¿na kontynuwoaæ, false jeœli gra siê zakoñczy³a;
	bool wykonajTure();

	//Metoda wypisuj¹ca do _os podsumowanie rozgrywki
	void wypiszPodsumowanie(ostream& _os = cout);

	//ETAP 3 - FUNKCJONALNOŒÆ TWORZENIA DYNAMICZNYCH OBIEKTÓW KLASY BOT
	//ETAP 2 - KASYNO WYDAJE AUTOMATYCZNIE TYLKO 2 PIERWSZE KARTY, ROZPOCZÊCIE NOWEJ GRY
	//Metoda czyszcz¹ca tablicê Graczy i rozpoczynaj¹ca now¹ rozgrywkê, jeœli _bNazwij to u¿ytkownik zostanie poproszony o nazwanie Graczy
	void nowaGra(bool _bNazwij = true,  int _iLiczbaGraczyLudzkich = 1, int _iLiczbaBotow = 1);
	
	//GETTERY


	int GetWydaneKarty() { return iWydaneKarty; }

	//OPERATORY

	//Operator przypisania - REGU£A TRZECH
	Kasyno& operator=(Kasyno _ksKasyno);

	//Destruktor - REGU£A TRZECH
	~Kasyno();

private:
	//Metody prywatne


	//Metoda zwracaj¹ca kolejn¹ domyœln¹ nazwê gracza
	string nazwijGracza();

	//ETAP 3 - METOD¥ NADAJ¥CA BOTOM IDENTYFIKATOR
	//Metoda zwracaj¹ca kolejn¹ domyœln¹ nazwê bota
	string nazwijBota();

	//Metoda sprawdzaj¹ca czy podane liczby Graczy i Botów mieszcz¹ siê w odpowiednich zakresach i modyfikuje je jeœli nie
	void sprawdzLiczbeGraczy(int _iLiczbaBotow, int _iLiczbaGraczy);

	//ETAP 2 - OKREŒLENIE KTÓRY GRACZ WYGRA£
	//Metoda sprawdzaj¹ca którzy gracze wygrali
	//Zwraca: tablicê booli rzutowan¹ na tablicê graczy - jeœli wygrane[i] == true to oznacza ¿e gGracze[i] wygra³
	bool* sprawdzWygrane();

	//Metoda inicjalizuj¹ca Graczy i Boty
	void inicjalizujGraczy(bool _bNazwij);

	//Metoda zmieniaj¹ca miejscami dwie karty
	void zamienKarty(Karta& _kKarta1, Karta& _kKarta2);

	//Redefincja funkcji swap w celu zastosowania przypisania idiomowego
	friend void swap(Kasyno& _KsKasyno1, Kasyno& _KsKasyno2) {
		using std::swap;

		swap(_KsKasyno1.iLiczbaBotow, _KsKasyno2.iLiczbaBotow);
		swap(_KsKasyno1.iLiczbaGraczy, _KsKasyno2.iLiczbaGraczy);
		swap(_KsKasyno1.iLiczbaGraczyLudzkich, _KsKasyno2.iLiczbaGraczyLudzkich);
		swap(_KsKasyno1.iWydaneKarty, _KsKasyno2.iWydaneKarty);
		swap(_KsKasyno1.iNrBota, _KsKasyno2.iNrBota);
		swap(_KsKasyno1.iNrGracza, _KsKasyno2.iNrGracza);
		swap(_KsKasyno1.gGracze, _KsKasyno2.gGracze);
		swap(_KsKasyno1.kKarty, _KsKasyno2.kKarty);

		for (int i = 0; i < _KsKasyno1.iLiczbaGraczy; i++){
			_KsKasyno1.gGracze[i]->SetKasyno(&_KsKasyno1);

			for (int j = 0; j < _KsKasyno1.gGracze[i]->GetIloscKart(); j++)
			{
				int offset = _KsKasyno1.gGracze[i]->GetKarty()[j] - _KsKasyno2.kKarty;
				_KsKasyno1.gGracze[i]->GetKarty()[j] = &_KsKasyno1.kKarty[offset];
			}
		}

		for (int i = 0; i < _KsKasyno2.iLiczbaGraczy; i++) {
			_KsKasyno2.gGracze[i]->SetKasyno(&_KsKasyno2);

			for (int j = 0; j < _KsKasyno2.gGracze[i]->GetIloscKart(); j++)
			{
				int offset = _KsKasyno2.gGracze[i]->GetKarty()[j] - _KsKasyno1.kKarty;
				_KsKasyno2.gGracze[i]->GetKarty()[j] = &_KsKasyno2.kKarty[offset];
			}
		}

	}
};
