#include "Magicien.h"

Magicien::Magicien() {
	int vie[2]{ 50,100 };
	m_vie = vie;
	int mana[2]{ 50,50 };
	m_mana = mana;
	int bouclier[2]{ 0,50 };
	m_vie = bouclier;
}

Magicien::Magicien(Sort* choixAtt, Sort* choixDef)
{
	int vie[2]{ 50,100 };
	m_vie = vie;
	int mana[2]{ 50,50 };
	m_mana = mana;
	int bouclier[2]{ 0,50 };
	m_bouclier = bouclier;

	Baton baton{ choixAtt,choixDef };
	m_baton = &baton;
	choixAtt = nullptr;
	choixDef = nullptr;
	delete choixAtt;
	delete choixDef;
}

Magicien::~Magicien()
{
	delete[] m_vie;
	delete[] m_mana;
	delete[] m_bouclier;
}

void Magicien::Attaquer(Magicien* ennemi)
{
	if (IsMana()) {
		m_baton->UtiliserAttaque(ennemi);
		m_mana[0] -= 10;
	}
	ennemi = nullptr;
	delete ennemi;
}

void Magicien::Defendre()
{
	if (IsMana()) {
		m_baton->UtiliserDefense(this);
		m_mana[0] -= 10;
	}
}

void Magicien::Recharger(Sort* choixAtt, Sort* choixDef)
{
	Baton nouvBaton{choixAtt,choixDef};
	m_baton = &nouvBaton;
	m_mana[0] = m_mana[1];
	choixAtt = nullptr;
	choixDef = nullptr;
	delete choixAtt;
	delete choixDef;
}

int Magicien::GetVie()
{
	return m_vie[0];
}

int Magicien::GetMana()
{
	return m_mana[0];
}

int Magicien::GetBouclier()
{
	return m_bouclier[0];
}

int Magicien::GetVieMax()
{
	return m_vie[1];
}

int Magicien::GetManaMax()
{
	return m_mana[1];
}

int Magicien::GetBouclierMax()
{
	return m_bouclier[1];
}

std::string Magicien::GetBatonNom()
{
	return m_baton->GetNom();
}

void Magicien::SetBouclier(int bouclier)
{
	if (bouclier >= 0) {
		m_bouclier[0] = bouclier;
	}
}

void Magicien::SetVie(int vie)
{
	if (vie >= 0) {
		m_vie[0] = vie;
	}
}

bool Magicien::IsVivant()
{
	return m_vie[0] <= 0 ? false:true;
}

bool Magicien::IsMana()
{
	return m_mana[0] < 10 ? false : true;
}

bool Magicien::IsBouclier()
{
	return m_bouclier[0] <= 0 ? false:true;
}
