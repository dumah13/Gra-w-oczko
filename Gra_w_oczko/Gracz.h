#include "Karta.h"
#include <string>
#pragma once

//Szkieletowa deklaracja klasy Kasyno w celu implementacji asocjacji
class Kasyno;

class Gracz
{
	//Statyczna sta�a - maksymalna ilo�� kart na r�ce
public:
	const static int MaxLiczbaKart = 10;

private:
	//Zmienne prywatne
	Karta* kKartyGracza[MaxLiczbaKart];
	Kasyno* ksKasyno;
	int iIloscKart;
	int iIloscPunktow;
	bool bPas;
	char nazwaGracza[20];

public:
	//Konstruktor domy�lny/przeci��ony

	//_ksKasyno - Kasyno do kt�rego ma nale�e� gracz;
	//_nazwa - nazwa gracza;
	Gracz(Kasyno* _ksKasyno = nullptr, string _nazwa = "Domyslny Gracz");

	//Metody

	//Dopisuje Kart� _karta do listy kart gracza 
	void wezKarte(Karta* _karta);
	//Wywo�uje odpowiedni� metod� w klasie Kasyna, powoduj�c zwr�cenie Karty
	Karta* pobierzKarteOdKasyna();
	//Wy�wietla karty na r�ce gracza 
	//_os - strumie� do kt�rego maj� zosta� wypisane
	void wyswietlKarty(ostream& _os = cout);
	//Wirtualna metoda w kt�rej u�ytkownik wybiera akcj� do wykonania
	//Zwraca: numer akcji kt�r� wykona� gracz
	virtual int wykonajAkcje();
	//Ustawia atrybut bPas na true
	void spasuj();

	//Gettery dla atrybutow prywatnych

	int GetIloscKart() { return iIloscKart; }
	int GetIloscPunktow() { return iIloscPunktow; }
	char* GetNazwa() { return nazwaGracza; };
	bool GetPass() { return bPas; }
};

