#include "Baton.h"

Baton::Baton()
{
	Sort attaque{"Flaque",true,0};
	m_sortAttaque = &attaque;
	Sort defense{ "Trempette",true,0 };
	m_sortAttaque = &defense;

	m_nom = m_sortAttaque->GetNom() + " de " + m_sortDefense->GetNom();
}

Baton::Baton(Sort* choixAtt, Sort* choixDef)
{
	m_sortAttaque = &choixAtt[RngInt(0, 1)];
	m_sortDefense = &choixDef[RngInt(0, 1)];

	m_nom = m_sortAttaque->GetNom() + " de " + m_sortDefense->GetNom();

	choixAtt = nullptr;
	choixDef = nullptr;
	delete choixAtt;
	delete choixDef;
}

Baton::~Baton()
{
	m_sortAttaque = nullptr;
	m_sortDefense = nullptr;
	delete m_sortAttaque;
	delete m_sortDefense;
}

void Baton::UtiliserAttaque(Magicien* ennemi)
{
	m_sortAttaque->Attaque(ennemi);

	ennemi = nullptr;
	delete ennemi;
}

void Baton::UtiliserDefense(Magicien* utilisateur)
{
	m_sortDefense->Defense(utilisateur);

	utilisateur = nullptr;
	delete utilisateur;
}

std::string Baton::GetNom()
{
	return m_nom;
}
