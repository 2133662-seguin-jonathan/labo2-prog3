#pragma once
#include <cstdlib>
#include <ctime>

/**
* @public
* @brief Permet de g�n�rer un nombre al�atoire en entier.
* @param[in] int valeur minimale
* @param[in] int valeur maximale
* @returns le nombre al�atoire entre le min et max en param�tres
*/
int RngInt(int min, int max)
{
	std:srand(time(NULL));

	int rng = std::rand() % (max - min + 1) + min;

	return rng;
}