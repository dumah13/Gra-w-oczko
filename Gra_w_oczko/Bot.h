#pragma once
#include "Gracz.h"

//ETAP 3 - TYP ODWAGI BOTA
//Enumerator typ�w bota (liczby punkt�w jakie musi osi�gn�� bot aby spasowa�)
enum TypyBota {
	zachowawczy = 13,
	normalny = 17,
	ryzykujacy = 21
};

//ETAP 3 - KLASA BOTA DZIEDZICZ�CA PO GRACZU
class Bot : public Gracz
{

	//ETAP 3 - ATRYBUT ODWAGA
	//Ilosc punktow jaka musi miec na rece bot przed spasowaniem
	TypyBota tbOdwaga;
public:
	//Kontruktor domy�lny/Przeci��ony
	Bot(Kasyno* _ksKasyno = nullptr, string _nazwa = "Bot", TypyBota _tbTyp = normalny) : Gracz(_ksKasyno, _nazwa), tbOdwaga(_tbTyp) {};

	//ETAP 3 - METODA WIRTUALNA PODEJMUJ�CA DECYZJ� DLA BOTA
	//Wirtualna metoda w kt�rej bot podejmuje decyzj� jak� akcj� wykona�
	//Zwraca: int numer wykonanej akcji.
	virtual int wykonajAkcje();

	//ETAP 4 - jedna metoda wirtualna w zupe�no�ci wystarcza, poniewa� ka�da funkcjonalno�� poza procesem podejmowania decyzji jest taka sama
	//dla bota jak i dla gracza ludzkiego.
};

