#pragma once
#include "Gracz.h"

//ETAP 3 - TYP ODWAGI BOTA
//Enumerator typów bota (liczby punktów jakie musi osi¹gn¹æ bot aby spasowaæ)
enum TypyBota {
	zachowawczy = 13,
	normalny = 17,
	ryzykujacy = 21
};

//ETAP 3 - KLASA BOTA DZIEDZICZ¥CA PO GRACZU
class Bot : public Gracz
{

	//ETAP 3 - ATRYBUT ODWAGA
	//Ilosc punktow jaka musi miec na rece bot przed spasowaniem
	TypyBota tbOdwaga;
public:
	//Kontruktor domyœlny/Przeci¹¿ony
	Bot(Kasyno* _ksKasyno = nullptr, string _nazwa = "Bot", TypyBota _tbTyp = normalny) : Gracz(_ksKasyno, _nazwa), tbOdwaga(_tbTyp) {};

	//ETAP 3 - METODA WIRTUALNA PODEJMUJ¥CA DECYZJÊ DLA BOTA
	//Wirtualna metoda w której bot podejmuje decyzjê jak¹ akcjê wykonaæ
	//Zwraca: int numer wykonanej akcji.
	virtual int wykonajAkcje();

	//ETAP 4 - jedna metoda wirtualna w zupe³noœci wystarcza, poniewa¿ ka¿da funkcjonalnoœæ poza procesem podejmowania decyzji jest taka sama
	//dla bota jak i dla gracza ludzkiego.
};

