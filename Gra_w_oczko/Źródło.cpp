#include "Kasyno.h"
#include <time.h>
#include <iostream>
#include "DodatkoweFunkcje.h"
//#include <vld.h>

using namespace std;
int main() {
	srand((unsigned int)time(0));
	bool kontynuuj = true;

	int liczbaGraczy;
	int liczbaBotow;
	
	Kasyno kasyno1(false);
	do
	{
		if (kontynuuj)
 {
			cout << "Podaj liczbe graczy\n";
			liczbaGraczy = wczytajWartosc<int>(cin, 1, Kasyno::MaxLiczbaLudzkichGraczy);

			cout << "Podaj liczbe botow\n";
			liczbaBotow = wczytajWartosc<int>(cin, 1, Kasyno::MaxLiczbaBotow);

			cout << "Czy chcesz nazwac graczy?\n1 - tak\n2 - nie" << endl;
			bool nazwij = wczytajWartosc<int>(cin, 1, 2) == 1 ? true : false;
			system("cls");

			kasyno1.nowaGra(nazwij, liczbaGraczy, liczbaBotow);
		}

		while (kasyno1.wykonajTure());
		cout << "Czy chcesz zagrac ponownie?\n1 - tak\n2 - nie\n";
		kontynuuj = wczytajWartosc<int>(cin, 1, 2) == 1 ? true : false;

		system("cls");

	} while (kontynuuj);
}