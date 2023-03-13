#pragma once
#include <cstdlib>
#include <ctime>

/**
* @public
* @brief Permet de générer un nombre aléatoire en entier.
* @param[in] int valeur minimale
* @param[in] int valeur maximale
* @returns le nombre aléatoire entre le min et max en paramètres
*/
int RngInt(int min, int max)
{
	std:srand(time(NULL));

	int rng = std::rand() % (max - min + 1) + min;

	return rng;
}