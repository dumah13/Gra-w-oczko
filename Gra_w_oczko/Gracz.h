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

	//ETAP 1 - AGREGACJA (Gracz mo�e posiada� 0..10 Kart)
	Karta* kKartyGracza[MaxLiczbaKart]; //Czasem �ycia Kart zarz�dza Kasyno, nie Gracz
	//ETAP 2 - ASOCJACJA - GRACZ MA �WIADOMO�� O KASYNIE KT�RE GO STWORZY�O
	Kasyno* ksKasyno;

	//ETAP 1 - ILO�� KART, ILO�� PUNKT�W
	int iIloscKart;
	int iIloscPunktow;
	//ETAP 2 - INFORMACJA O PASIE
	bool bPas;
	//ETAP 2 - NAZWA GRACZA
	char nazwaGracza[20];

public:
	//Konstruktor domy�lny/przeci��ony

	//_ksKasyno - Kasyno do kt�rego ma nale�e� gracz;
	//_nazwa - nazwa gracza;
	Gracz(Kasyno* _ksKasyno = nullptr, string _nazwa = "Domyslny Gracz");

	//Metody

	//ETAP 1 - POBRANIE KARTY Z KASYNA
	//Dopisuje Kart� _karta do listy kart gracza 
	void wezKarte(Karta* _karta);

	//Wywo�uje odpowiedni� metod� w klasie Kasyna, powoduj�c zwr�cenie Karty
	//Zwraca: wska�nik na Kart� kt�r� poda�o Kasyno
	Karta* pobierzKarteOdKasyna();

	//ETAP 1 - WY�WIETLANIE KART
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
	Karta** GetKarty() { return kKartyGracza; }
	char* GetNazwa() { return nazwaGracza; };
	//ETAP 2 - GETTER INFORMACJI O PASIE
	bool GetPass() { return bPas; }

	//Settery

	void SetKasyno(Kasyno* _ksKasyno) { ksKasyno = _ksKasyno; }
};

