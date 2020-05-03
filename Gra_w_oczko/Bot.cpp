#include "Bot.h"
#include "DodatkoweFunkcje.h"


int Bot::wykonajAkcje() {
	int wybor = 0;
	if (GetIloscPunktow() < tbOdwaga && GetIloscKart() < Gracz::MaxLiczbaKart) {
		wezKarte(pobierzKarteOdKasyna());
		cout << "Bot pobral karte.\n";
		wybor = 1;
	}
	else {
		spasuj();
		cout << "Bot spasowal.\n";
		wybor = 2;
	}
	
	return wybor;
}