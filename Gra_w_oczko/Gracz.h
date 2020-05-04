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

	//ETAP 1 - AGREGACJA (Gracz mo¿e posiadaæ 0..10 Kart)
	Karta* kKartyGracza[MaxLiczbaKart]; //Czasem ¿ycia Kart zarz¹dza Kasyno, nie Gracz
	//ETAP 2 - ASOCJACJA - GRACZ MA ŒWIADOMOŒÆ O KASYNIE KTÓRE GO STWORZY£O
	Kasyno* ksKasyno;

	//ETAP 1 - ILOŒÆ KART, ILOŒÆ PUNKTÓW
	int iIloscKart;
	int iIloscPunktow;
	//ETAP 2 - INFORMACJA O PASIE
	bool bPas;
	//ETAP 2 - NAZWA GRACZA
	char nazwaGracza[20];

public:
	//Konstruktor domyœlny/przeci¹¿ony

	//_ksKasyno - Kasyno do którego ma nale¿eæ gracz;
	//_nazwa - nazwa gracza;
	Gracz(Kasyno* _ksKasyno = nullptr, string _nazwa = "Domyslny Gracz");

	//Metody

	//ETAP 1 - POBRANIE KARTY Z KASYNA
	//Dopisuje Kartê _karta do listy kart gracza 
	void wezKarte(Karta* _karta);

	//Wywo³uje odpowiedni¹ metodê w klasie Kasyna, powoduj¹c zwrócenie Karty
	//Zwraca: wskaŸnik na Kartê któr¹ poda³o Kasyno
	Karta* pobierzKarteOdKasyna();

	//ETAP 1 - WYŒWIETLANIE KART
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
	Karta** GetKarty() { return kKartyGracza; }
	char* GetNazwa() { return nazwaGracza; };
	//ETAP 2 - GETTER INFORMACJI O PASIE
	bool GetPass() { return bPas; }

	//Settery

	void SetKasyno(Kasyno* _ksKasyno) { ksKasyno = _ksKasyno; }
};

