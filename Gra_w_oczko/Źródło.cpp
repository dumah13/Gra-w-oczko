#include "Kasyno.h"
#include <time.h>
#include <iostream>
#include "DodatkoweFunkcje.h"
#include <vld.h>

using namespace std;
int main() {

	//Inicjalizacja programu
	srand((unsigned int)time(0));
	bool kontynuuj = true;

	int liczbaGraczy;
	int liczbaBotow;
	
	Kasyno kasyno1(false);

	//Brute force testy operatora przypisania, konstruktora kopiujacego i destruktora
	/*Kasyno kasyno2(false);

	kasyno1.rozpocznijRozgrywke();
	int i = 0;

	while (i++ < 100000) {
		
		Kasyno kasyno3(kasyno1);
		kasyno1 = kasyno2;
		kasyno2 = kasyno3;
	}
	*/

	//Petla programu
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

			//Testy przypisania
			//kasyno2 = kasyno1;
		}

		while (kasyno1.wykonajTure());
		cout << "Czy chcesz zagrac ponownie?\n1 - tak\n2 - nie\n";
		kontynuuj = wczytajWartosc<int>(cin, 1, 2) == 1 ? true : false;

		system("cls");

	} while (kontynuuj);
}