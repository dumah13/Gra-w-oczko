#pragma once
#include <iostream>

class Karta {
private:
	char kolor;
	char figura;
	int wartosc;
public:
	Karta(int _kolor = 0, int _wartosc = 0);
	void setKolor(int _kolor);
	void setWartosc(int _wartosc);
	char getKolor() const { return kolor; }
	char getFigura() const { return figura; }
	int getWartosc() const { return wartosc; }
	void wypisz() const { std::cout << figura << kolor; }
};

using namespace std;
//ETAP 2 - PRZECIĄŻONY OPERATOR << DO WYPISYWANIA KARTY BEZPOŚREDNIO DO STRUMIENIA
ostream& operator<<(ostream& _os, const Karta& _Karta);