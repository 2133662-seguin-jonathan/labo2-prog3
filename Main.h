#pragma once
#include <string>
#include "Baton.h"
#include "Sort.h"
#include "utilitaires.h"
#include "Magicien.h"

/**
*  Donne le string du tour à afficher.
* Le string compose les infos de l'ennemi et du joueur.
* @param ptrJoueur pointeur du joueur
* @param ptrEnnemi pointeur de l'ennemi
* @returns le string du message de tour.
*/
std::string AffichageTour(Magicien* ptrJoueur, Magicien* ptrEnnemi);

/**
* Exécute le tour de l'ennemi.
* L'action est déterminé aléatoirement selon les conditions 
* que peut faire un magicien.
* @param ptrEnnemi pointeur de l'ennemi.
* @param ptrJoueur pointeur du joueur.
* @param  choixAtt la liste des sorts d'attaque à choisir.
* @param choixDef la liste des sorts de défense à choisir.
*/
void TourEnnemi(Magicien* ptrEnnemi, Magicien* ptrJoueur, Sort* choixAtt, Sort* choixDef);