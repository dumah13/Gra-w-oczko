#include "Gracz.h"
#include "DodatkoweFunkcje.h"
#include "Kasyno.h"
#include <stdio.h>

using namespace std;

Gracz::Gracz(Kasyno* _ksKasyno, string _nazwa):
	ksKasyno(_ksKasyno),
	nazwaGracza {},
	iIloscKart(0),
	iIloscPunktow(0),
	bPas(false),
	kKartyGracza {}
{
	for (int i = 0; i < _nazwa.length(); i++)
	{
		if (i == 19) {
			nazwaGracza[19] = '\0';
			break;
		}
		nazwaGracza[i] = _nazwa[i];
	}
}

void Gracz::wezKarte(Karta* _karta)
{
	if (_karta == nullptr) {
		return;
	}
	if (iIloscKart < MaxLiczbaKart) {
		kKartyGracza[iIloscKart++] = _karta;
		iIloscPunktow += _karta->getWartosc();
	}
	else {
		cout << "\nPrzekroczono maksymalna liczbe kart.\n";
	}
}

Karta* Gracz::pobierzKarteOdKasyna() {
	return ksKasyno->dajKarte();
}

void Gracz::wyswietlKarty(ostream& os)
{
	for (int i = 0; i < iIloscKart; ++i) {
		os << *kKartyGracza[i] << " ";
	}
	for (int i = 0; i < (MaxLiczbaKart - iIloscKart) * 3; ++i) {
		os << " ";
	}
}

int Gracz::wykonajAkcje() {	
	int wybor;
	Karta* pobranaKarta;

	if (iIloscPunktow < 21 && iIloscKart < MaxLiczbaKart)
	{
		cout << "Wpisz 1 aby wziac karte.\nWpisz 2 aby spasowac.\nWpisz 3 aby zakonczyc gre.\n";
		wybor = wczytajWartosc<int>(cin, 1, 3);
	}
	else {
		cout << "Automatyczny pas - przekroczyles 20 punktow lub osiagnales maksymalna ilosc kart.\n";
		wybor = 4;
	}

	switch (wybor) {
	case 1:
		pobranaKarta = pobierzKarteOdKasyna();
		wezKarte(pobranaKarta);
		if (!pobranaKarta) break;
		cout << "Pobrano karte " << *pobranaKarta << endl << "Nowa liczba punktow: " << iIloscPunktow << endl;
		break;
	case 2:
		spasuj();
		break;
	case 3:
		break;
	case 4:
		spasuj();
		break;
	default:
		cout << "\nBlad zwiazany z wykonywaniem tury gracza.\n";
	}

	return wybor;
}

void Gracz::spasuj() {
	bPas = true;
}

