#include "Karta.h"
#include <string>
#pragma once

//Szkieletowa deklaracja klasy Kasyno w celu implementacji asocjacji
class Kasyno;

class Gracz
{
	//Statyczna sta³a - maksymalna iloœæ kart na rêce
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
	//Konstruktor domyœlny/przeci¹¿ony

	//_ksKasyno - Kasyno do którego ma nale¿eæ gracz;
	//_nazwa - nazwa gracza;
	Gracz(Kasyno* _ksKasyno = nullptr, string _nazwa = "Domyslny Gracz");

	//Metody

	//Dopisuje Kartê _karta do listy kart gracza 
	void wezKarte(Karta* _karta);
	//Wywo³uje odpowiedni¹ metodê w klasie Kasyna, powoduj¹c zwrócenie Karty
	Karta* pobierzKarteOdKasyna();
	//Wyœwietla karty na rêce gracza 
	//_os - strumieñ do którego maj¹ zostaæ wypisane
	void wyswietlKarty(ostream& _os = cout);
	//Wirtualna metoda w której u¿ytkownik wybiera akcjê do wykonania
	//Zwraca: numer akcji któr¹ wykona³ gracz
	virtual int wykonajAkcje();
	//Ustawia atrybut bPas na true
	void spasuj();

	//Gettery dla atrybutow prywatnych

	int GetIloscKart() { return iIloscKart; }
	int GetIloscPunktow() { return iIloscPunktow; }
	char* GetNazwa() { return nazwaGracza; };
	bool GetPass() { return bPas; }
};

