#include "Kasyno.h"
#include "DodatkoweFunkcje.h"
#include <random>
#include <fstream>

Kasyno::Kasyno(bool _bNazwijGraczy, int _iLiczbaGraczyLudzkich, int _iLiczbaBotow):
	gGracze{},
	kKarty{},
	iWydaneKarty(0),
	iNrBota(1),
	iNrGracza(1)
{
	sprawdzLiczbeGraczy(_iLiczbaBotow, _iLiczbaGraczyLudzkich);

	inicjalizujGraczy(_bNazwijGraczy);

	for (int i = 0; i < LiczbaKolorow; ++i) {
		for (int j = 0; j < LiczbaFigur; ++j) {
			int indeks = i * LiczbaFigur + j;
			kKarty[indeks].setKolor(i);
			kKarty[indeks].setWartosc(j);
		}
	}
}

Kasyno::Kasyno(const Kasyno& _ksKasyno) :
	gGracze{},
	iLiczbaBotow(_ksKasyno.iLiczbaBotow),
	iLiczbaGraczy(_ksKasyno.iLiczbaGraczy),
	iLiczbaGraczyLudzkich(_ksKasyno.iLiczbaGraczyLudzkich),
	iNrBota(_ksKasyno.iNrBota),
	iNrGracza(_ksKasyno.iNrGracza),
	iWydaneKarty(_ksKasyno.iWydaneKarty)
{


	for (int i = 0; i < Kasyno::LiczbaKart; i++)
	{
		kKarty[i] = _ksKasyno.kKarty[i];
	}

	for (int i = 0; i < _ksKasyno.iLiczbaGraczy; i++)
	{
		Gracz* gracz = typeid(*_ksKasyno.gGracze[i]) == typeid(Bot) ? new Bot((*dynamic_cast<Bot*>(_ksKasyno.gGracze[i]))) : new Gracz(*_ksKasyno.gGracze[i]);

		for (int j = 0; j < _ksKasyno.gGracze[i]->GetIloscKart(); j++)
		{
			int offset = _ksKasyno.gGracze[i]->GetKarty()[j] - _ksKasyno.kKarty;
			gracz->GetKarty()[j] = &kKarty[offset];
		}
		gGracze[i] = gracz;
	}


}

void Kasyno::tasuj(int _iLiczbaPrzetasowan)
{
	for (int i = 0; i < _iLiczbaPrzetasowan; ++i) {
		int indeksKarty1 = losowaPrzedzial(0, LiczbaKart-1);
		int indeksKarty2;

		//zabezpieczenie przed prób¹ zamiany karty z sam¹ sob¹
		while ((indeksKarty2 = losowaPrzedzial(0, LiczbaKart-1)) == indeksKarty1);

		zamienKarty(kKarty[indeksKarty1], kKarty[indeksKarty2]);
	}
}

Karta* Kasyno::dajKarte()
{
	if (iWydaneKarty == LiczbaKart) {
		std::cout << "\nBrak kart w talii.\n";
		return nullptr;
	}
	return &kKarty[iWydaneKarty++];
}

void Kasyno::wypiszKarty() {
	for (int i = 0; i < LiczbaKart; ++i) {
		std::cout << kKarty[i] << " ";
	}
}

void Kasyno::rozpocznijRozgrywke()
{
	tasuj();
	for (int i = 0; i < (iLiczbaGraczy); i++)
	{
		for (int j = 0; j < LiczbaKartNaStart; j++)
		{
			gGracze[i]->wezKarte(dajKarte());
		}
	}
	system("cls");
}

void Kasyno::wyswietlRekeGracza(int _iGracz, ostream& _os) {
	_os.setf(std::ios::left);
	_os.width(20);

	_os << gGracze[_iGracz]->GetNazwa() << " ";
	gGracze[_iGracz]->wyswietlKarty(_os);
	_os << gGracze[_iGracz]->GetIloscPunktow();

	_os.unsetf(std::ios::left);
}

bool Kasyno::czyWszyscySpasowali() {
	for (int i = 0; i < (iLiczbaGraczy); i++)
	{
		if (!gGracze[i]->GetPass()) {
			return false;
		}
	}

	return true;
}

void Kasyno::zakonczGre() {
	system("cls");
	cout << "Koniec gry. Wyniki: " << endl;
	wypiszPodsumowanie(cout);
	zapiszGre();
}

void Kasyno::zapiszGre(string _nazwaPliku) {
	std::ofstream plik;
	plik.open(_nazwaPliku, std::ifstream::app);
	plik.fill('#');
	plik.width(55);
	plik << "" << endl;
	plik.fill(' ');
	wypiszPodsumowanie(plik);

	plik << endl;

	plik.close();
}

bool Kasyno::wykonajTure() {
	for (int i = 0; i < (iLiczbaGraczy); i++)
	{
		if (!gGracze[i]->GetPass())
		{
			cout << "Tura gracza: " << gGracze[i]->GetNazwa() << endl;
			string temp = "";

			if (i < iLiczbaGraczyLudzkich) {
				wyswietlRekeGracza(i);
				cout << endl << endl;
			}

			int wybor = gGracze[i]->wykonajAkcje();

			if (wybor == 1 || wybor == 4 || i >= iLiczbaGraczyLudzkich)
			{
				cout << "Wpisz dowolny znak aby kontynuwac, lub end zeby zakonczyc gre.\n";
				temp = wczytajWartosc<string>(cin);
			}

			if (wybor == 3 || temp == "end") {
				cout << "Czy chcesz wyswietlic tablice wynikow i zapisac gre?\n1 - tak\n2 - nie\n3 - anuluj wyjscie\n";
				int nrOpcji = wczytajWartosc<int>(cin, 1, 3);

				switch (nrOpcji)
				{
				case 1:
					zakonczGre();
				case 2:
					return false;
				case 3:		
					if (temp != "end") {
						i--;
					}
				default:
					break;
				}
			}

			system("cls");
		}
	}

	if (czyWszyscySpasowali()) {
		zakonczGre();
		return false;
	}

	return true;
}

void Kasyno::wypiszPodsumowanie(ostream& _os) {
	bool* wygrane = sprawdzWygrane();

	for (int i = 0; i < (iLiczbaGraczy); i++) {
		wyswietlRekeGracza(i, _os);
		if (wygrane[i]) {
			_os.width(15);
			_os << "ZWYCIEZCA!" << endl;;
		}
		else {
			_os << endl;
		}
	}

	delete[] wygrane;
}

void Kasyno::nowaGra(bool _bNazwij, int _iLiczbaGraczy, int _iLiczbaBotow) {
	for (int i = 0; i < (iLiczbaGraczy); i++)
	{
		delete gGracze[i];
	}

	iWydaneKarty = 0;
	iNrBota = 1;
	iNrGracza = 1;

	sprawdzLiczbeGraczy(_iLiczbaBotow, _iLiczbaGraczy);

	inicjalizujGraczy(_bNazwij);

	system("cls");
	rozpocznijRozgrywke();
}

//OPERAToRY

Kasyno& Kasyno::operator=(Kasyno _ksKasyno) {
	swap(*this, _ksKasyno);
	return *this;
}

//Destruktor
Kasyno::~Kasyno() {
	for (int i = 0; i < (iLiczbaGraczy); i++)
	{
		delete gGracze[i];
	}
}


//METODY PRYWATNE


string Kasyno::nazwijGracza() {
	string nazwa = "Anonim";
	nazwa += iNrGracza++ + 48;
	return nazwa;
}

string Kasyno::nazwijBota() {
	string nazwa = "Bot";
	nazwa += iNrBota++ + 48;
	return nazwa;
}

void Kasyno::sprawdzLiczbeGraczy(int _iLiczbaBotow, int _iLiczbaGraczyLudzkich) {
	iLiczbaGraczyLudzkich = _iLiczbaGraczyLudzkich < 1 ? 1 : _iLiczbaGraczyLudzkich > MaxLiczbaLudzkichGraczy ? MaxLiczbaLudzkichGraczy : _iLiczbaGraczyLudzkich;
	iLiczbaBotow = _iLiczbaBotow < 1 ? 1 : _iLiczbaBotow > MaxLiczbaBotow ? MaxLiczbaBotow : _iLiczbaBotow;

	iLiczbaGraczy = iLiczbaGraczyLudzkich + iLiczbaBotow;
}

bool* Kasyno::sprawdzWygrane() {
	bool* wygrane = new bool[iLiczbaGraczy];

	for (int i = 0; i < (iLiczbaGraczy); i++) {
		int punkty = gGracze[i]->GetIloscPunktow();


		if (punkty == MaxLiczbaPunktowDoWygrania) {
			wygrane[i] = true;
			for (int j = 0; j < i; j++) {

				if (gGracze[j]->GetIloscPunktow() != MaxLiczbaPunktowDoWygrania)
				{
					wygrane[j] = false;
				}
			}
		}
		else if (punkty < MaxLiczbaPunktowDoWygrania) {
			wygrane[i] = true;
			for (int j = 0; j < i; j++) {
				if (wygrane[j]) {
					if (gGracze[j]->GetIloscPunktow() < gGracze[i]->GetIloscPunktow()) {
						wygrane[j] = false;
					}
					else if (gGracze[j]->GetIloscPunktow() != gGracze[i]->GetIloscPunktow()) {
						wygrane[i] = false;
					}
				}
			}
		}
		else {
			wygrane[i] = false;
		}
	}

	return wygrane;
}


void Kasyno::inicjalizujGraczy(bool _bNazwij) {
	for (int i = 0; i < (iLiczbaGraczyLudzkich); i++)
	{
		string nazwa;

		if (_bNazwij)
		{
			cout << "Podaj nazwe gracza. (1 s³owo!)" << endl;
			nazwa = wczytajWartosc<string>(cin);
		}
		else {
			nazwa = nazwijGracza();
		}

		gGracze[i] = new Gracz(this, nazwa);

	}

	for (int i = iLiczbaGraczyLudzkich; i < (iLiczbaGraczy); i++) {
		int indeks = losowaPrzedzial<int>(1,3);
		TypyBota typ;

		switch (indeks) {
		case 1:
			typ = zachowawczy;
			break;
		case 2:
			typ = normalny;
			break;
		case 3:
			typ = ryzykujacy;
			break;
		default:
			typ = normalny;
		}

		gGracze[i] = new Bot(this, nazwijBota(), typ);
	}
}

void Kasyno::zamienKarty(Karta& _kKarta1, Karta& _kKarta2)
{
	Karta tempKarta = _kKarta1;

	_kKarta1 = _kKarta2;
	_kKarta2 = tempKarta;
}

