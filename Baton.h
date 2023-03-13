#pragma once
#include <string>
#include "Sort.h"
#include "utilitaires.h"
#include "Magicien.h"

class Baton
{
private:
	/**
	* Variable membre du nom du bâton.
	*/
	std::string m_nom;
	/**
	* Variable membre du sort d'attaque du baton.
	*/
	Sort* m_sortAttaque{ nullptr };
	/**
	* Variable membre du sort de défense du baton.
	*/
	Sort* m_sortDefense{ nullptr };
public:
	/*Constructeur de base.
	*/
	Baton();
	/**
	* Surcharge du constructeur.
	* @param choixAtt la liste des sorts d'attaque à choisir.
	* @param choixDef la liste des sorts de défense à choisir.
	*/
	Baton(Sort* choixAtt, Sort* choixDef);
	/**
	* Destructeur.
	*/
	~Baton();
	/**
	* Permet d'utiliser le sort d'attaque.
	* @param[in] ennemi l'ennemi de l'utilisateur
	*/
	void UtiliserAttaque(Magicien* ennemi);
	/**
	* Permet d'utiliser le sort de défense.
	* @param[in] utilisateur l'utilisateur
	*/
	void UtiliserDefense(Magicien* utilisateur);
	/**
	* Permet d'avoir le nom du baton.
	* @returns le nom du baton.
	*/
	std::string GetNom();
};

