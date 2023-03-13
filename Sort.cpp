#include "Sort.h"

Sort::Sort() : m_nom{ "Trempette" }, m_isAttaque{ false }, m_puissance{ 0 } {}

Sort::Sort(std::string nom, bool isAttaque, int puissance) : m_nom{ nom }, m_isAttaque{ isAttaque }, m_puissance{ puissance } {}

void Sort::Attaque(Magicien* ennemi)
{
	if (m_isAttaque) {
		if (m_puissance < 0) {
			int vieReduite{ ennemi->GetVie() + m_puissance };
			if (vieReduite < 0) {
				ennemi->SetVie(0);
			}
			else {
				ennemi->SetVie(vieReduite);
			}
		}
		else if (m_puissance > 0) {
			int bouclierReduit{ ennemi->GetBouclier() - m_puissance };
			if (bouclierReduit < 0) {
				int vieReduite{ ennemi->GetVie() + bouclierReduit };
				if (vieReduite < 0) {
					ennemi->SetVie(0);
				}
				else {
					ennemi->SetVie(vieReduite);
				}
				ennemi->SetBouclier(0);
			}
			else if (bouclierReduit == 0) {
				ennemi->SetBouclier(0);
			}
			else if (bouclierReduit > 0) {
				ennemi->SetBouclier(bouclierReduit);
			}
		}
	}

	ennemi = nullptr;
	delete ennemi;
}

void Sort::Defense(Magicien* utilisateur)
{
	if (!m_isAttaque) {
		if (m_puissance < 0) {
			int bouclierAugmentation{ utilisateur->GetBouclier() + m_puissance };
			if (bouclierAugmentation > utilisateur->GetBouclierMax()) {
				utilisateur->SetBouclier(utilisateur->GetBouclierMax());
			}
			else {
				utilisateur->SetBouclier(bouclierAugmentation);
			}
		}
		else if (m_puissance > 0) {
			int vieAugmentation{ utilisateur->GetVie() + m_puissance };
			if (vieAugmentation > utilisateur->GetVieMax()) {
				utilisateur->SetVie(utilisateur->GetVieMax());
			}
			else {
				utilisateur->SetVie(vieAugmentation);
			}
		}
	}
	
	utilisateur = nullptr;
	delete utilisateur;
}

bool Sort::IsAttaque()
{
	return m_isAttaque;
}

std::string Sort::GetNom()
{
	return m_nom;
}

