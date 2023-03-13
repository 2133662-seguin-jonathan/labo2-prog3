#pragma once
#include <string>
#include "Baton.h"
#include "utilitaires.h"
#include "Sort.h"

class Magicien
{
private:
	/**
	* Variable membre de la vie du magicien.
	* l'index 0 est la vie actuel et l'index 1 est la vie max.
	*/
	int* m_vie{ nullptr };

	/**
	* Variable membre du mana du magicien.
	* l'index 0 est le mana actuel et l'index 1 est le mana maximal.
	*/
	int* m_mana{ nullptr };

	/**
	* Variable membre du bouclier du magicien.
	* l'index 0 est la vie du bouclier actuel et
	* l'index 1 est la vie du bouclier max.
	*/
	int* m_bouclier{ nullptr };

	/**
	* Variable membre qui est le baton actuel du magicien.
	* le baton est un pointeur.
	*/
	Baton* m_baton{ nullptr };

public:
	/**
	* Constructeur de base du magicien.
	*/
	Magicien();
	/**
	* Surcharge du constructeur de base.
	* @param choixAtt la liste des sorts d'attaque à choisir.
	* @param choixDef la liste des sorts de défense à choisir.
	*/
	Magicien(Sort* choixAtt, Sort* choixDef);
	/**
	* Destructeur de la classe magicien.
	*/
	~Magicien();
	/**
	* Permet de lancer une attaque à l'ennemi.
	* @param ennemi pointeur de l'ennemi à attaquer.
	*/
	void Attaquer(Magicien* ennemi);
	/**
	* Permet de lancer une défense sur lui même.
	* La méthode à besoin du pointeur l'objet en lui même pour le donner
	* au bâton et ainsi faire fonctionner le sort de défense.
	*/
	void Defendre();
	/**
	* Permet de changer de bâton et recharger son mana au max.
	* @param choixAtt la liste des sorts d'attaque à choisir.
	* @param choixDef la liste des sorts de défense à choisir.
	*/
	void Recharger(Sort* choixAtt, Sort* choixDef);
	/**
	* Permet d'avoir la vie actuelle.
	* @returns la valeur actuelle de la vie.
	*/
	int GetVie();
	/**
	* Permet d'avoir le mana actuel.
	* @returns la valeur actuelle du mana.
	*/
	int GetMana();
	/**
	* Permet d'avoir le bouclier actuel.
	* @returns la valeur actuelle deu bouclier.
	*/
	int GetBouclier();
	/**
	* Permet d'avoir la vie max.
	* @returns la valeur max de la vie.
	*/
	int GetVieMax();
	/**
	* Permet d'avoir le mana max.
	* @returns la valeur max du mana.
	*/
	int GetManaMax();
	/**
	* Permet d'avoir le bouclier max.
	* @returns la valeur max du bouclier.
	*/
	int GetBouclierMax();
	/**
	* Permet d'avoir le nom du baton actuel.
	* @returns le nom du baton actuel.
	*/
	std::string GetBatonNom();
	/**
	* Permet de changer la vie actuelle.
	* @param vie valeur de la vie à changer.
	*/
	void SetVie(int vie);
	/**
	* Permet de changer le bouclier actuel.
	* @param bouclier valeur de la bouclier à changer.
	*/
	void SetBouclier(int bouclier);
	/**
	* Indique si le magicien est vivant.
	* @returns vrai s'il est vivant, sinon faux
	*/
	bool IsVivant();
	/**
	* Indique si le mana est suppérieur à 0.
	* @returns vrai si la condition est respectée, sinon faux
	*/
	bool IsMana();
	/**
	* Indique si le bouclier est suppérieur à 0.
	* @returns vrai si la condition est respectée, sinon faux
	*/
	bool IsBouclier();
};

