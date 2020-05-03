#pragma once
#include "Gracz.h"


enum TypyBota {
	zachowawczy = 13,
	normalny = 17,
	ryzykujacy = 21
};

class Bot : public Gracz
{
	//Ilosc punktow jaka musi miec na rece bot przed spasowaniem
	TypyBota tbOdwaga;
public:
	Bot(Kasyno* _ksKasyno, string _nazwa, TypyBota _tbTyp = normalny) : Gracz(_ksKasyno, _nazwa), tbOdwaga(_tbTyp) {};

	virtual int wykonajAkcje();
};

