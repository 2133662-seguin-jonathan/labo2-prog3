#pragma once
#include <string>
#include "Magicien.h"

class Sort
{
private:
	/**
	* Variable membre du nom du sort.
	*/
	std::string m_nom;
	/**
	* Variable membre qui indique si le sort est offensif.
	* Les effets du sort varient selon si cette varibale est 
	* vraie ou fausse.
	*/
	bool m_isAttaque{ false };
	/**
	* Variable membre de la puissance du sort.
	* Les effets du sort varient selon si cette
	* variable est positive ou n�gative.
	*/
	int m_puissance{ 0 };
public:
	/**
	* Constructeur de base de la classe Sort.
	*/
	Sort();
	/**
	* Surcharge du constructeur de base.
	* @param nom le nom du sort.
	* @param isAttaque bool�en indicant si c'est un sort d'attaque.
	* @param puissance la puissance du sort.
	*/
	Sort(std::string nom, bool isAttaque, int puissance);
	/**
	* Lance une action d'attaque.
	* @param ennemi pointeur de l'ennemi actuel de l'utilisateur.
	* Si la puissance est n�gative les dommage ignore le bouclier,
	* sinon cela prends de l'utillisation du bouclier.
	*/
	void Attaque(Magicien* ennemi);
	/**
	* Lance une action d�fensive.
	* @param utilisateur pointeur de l'utilisateur.
	* Si la puissance est n�gative cela augmente le bouclier jusqu'� sa capacit� max,
	* sinon cela augmente la vie j'usqu'� sa capacit� max.
	*/
	void Defense(Magicien* utilisateur);
	/**
	* Valide si c'est un sort d'attaque.
	* @returns vrai si c'est un sort d'attaque, sinon faux si c'est un sort de d�fense.
	*/
	bool IsAttaque();
	/**
	* Permet d'avoir le nom du sort.
	* @returns le nom du sort.
	*/
	std::string GetNom();
};

