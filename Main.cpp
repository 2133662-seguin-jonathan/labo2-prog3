#include <iostream>
#include "Main.h"

int main()
{
	//Création des sorts
	Sort guerison{"Guerison",false,20};
	Sort protection{ "Protection",false,10 };
	Sort incinerateur{ "Incinerateur",true,20 };
	Sort foudre{ "Foudre",true,10 };

	//Tableaux des différents type de sort
	Sort choixAtt[2]{ incinerateur,foudre };
	Sort choixDef[2]{ guerison,protection };

	//Création des Magiciens
	Magicien joueur{ choixAtt,choixDef };
	Magicien ennemi{ choixAtt,choixDef };

	bool finPartie{ false };
	bool tourJoueur{ true };
   
	while (!finPartie)
	{
		if (!joueur.IsVivant() || !ennemi.IsVivant()) {
			finPartie = true;
			if (joueur.IsVivant())
			{
				std::cout << "Joueur gagnant!";
			}
			else 
			{
				std::cout << "Ennemi gagnant!";
			}
		}
		else 
		{
			int rng = RngInt(0, 1); // Si 0, l'ennemi attaque en premier
			if (rng == 0) {
				std::cout << "Ennemi en premier\n\n";

				TourEnnemi(&ennemi,&joueur,choixAtt,choixDef);

				if (!joueur.IsVivant()) {
					finPartie = true;
					std::cout << "Ennemi gagnant!";
				}
				else 
				{
					std::cout << AffichageTour(&joueur, &ennemi);

					int choixJoueur{ 0 };
					std::cout << "Action: \n";

					if (joueur.IsMana()) {
						std::cout << " 1: Attaque\n";
						std::cout << " 2: Defense\n";
					}
					std::cout << " 3: Recharge\n";
					std::cout << " 4: Quitter\n";

					std::cin >> choixJoueur;

					if (choixJoueur == 1 && joueur.IsMana())
					{
						joueur.Attaquer(&ennemi);
					}
					else if (choixJoueur == 2 && joueur.IsMana())
					{
						joueur.Defendre();
					}
					else if (choixJoueur == 3)
					{
						joueur.Recharger(choixAtt, choixDef);
					}
					else if (choixJoueur == 4)
					{
						finPartie = true;
					}
				}

				
			}
			else {
				std::cout << "Joueur en premier\n\n";

				std::cout << AffichageTour(&joueur, &ennemi);

				int choixJoueur{ 0 };
				std::cout << "Action: \n";

				if (joueur.IsMana()) {
					std::cout << " 1: Attaque\n";
					std::cout << " 2: Defense\n";
				}
				std::cout << " 3: Recharge\n";
				std::cout << " 4: Quitter\n";

				std::cin >> choixJoueur;

				if (choixJoueur == 1 && joueur.IsMana())
				{
					joueur.Attaquer(&ennemi);
				}
				else if (choixJoueur == 2 && joueur.IsMana())
				{
					joueur.Defendre();
				}
				else if (choixJoueur == 3)
				{
					joueur.Recharger(choixAtt, choixDef);
				}
				else if (choixJoueur == 4)
				{
					finPartie = true;
				}
				if (!ennemi.IsVivant()) {
					finPartie = true;
					std::cout << "Joueur gagnant!";
				}
				else
				{
					TourEnnemi(&ennemi, &joueur, choixAtt, choixDef);
				}

			}
		}
		
		
	}
}

std::string AffichageTour(Magicien* ptrJoueur, Magicien* ptrEnnemi)
{
	std::string infoEnnemi{ "Info Ennemi:\n" };
	infoEnnemi += " Vie: " + std::to_string(ptrEnnemi->GetVie()) + " / " + 
		std::to_string(ptrEnnemi->GetVieMax()) + "\n";
	infoEnnemi += " Mana: " + std::to_string(ptrEnnemi->GetMana()) + " / " +
		std::to_string(ptrEnnemi->GetManaMax()) + "\n";
	infoEnnemi += " Bouclier: " + std::to_string(ptrEnnemi->GetBouclier()) + " / " +
		std::to_string(ptrEnnemi->GetBouclierMax()) + "\n";
	infoEnnemi += " Baton : " + ptrEnnemi->GetBatonNom() + "\n\n";

	std::string infoJoueur{ "Info Joueur:\n" };
	infoJoueur += " Vie: " + std::to_string(ptrJoueur->GetVie()) + " / " +
		std::to_string(ptrJoueur->GetVieMax()) + "\n";
	infoJoueur += " Mana: " + std::to_string(ptrJoueur->GetMana()) + " / " +
		std::to_string(ptrJoueur->GetManaMax()) + "\n";
	infoJoueur += " Bouclier: " + std::to_string(ptrJoueur->GetBouclier()) + " / " +
		std::to_string(ptrJoueur->GetBouclierMax()) + "\n";
	infoJoueur += " Baton : " + ptrJoueur->GetBatonNom() + "\n\n";

	ptrJoueur = nullptr;
	ptrEnnemi = nullptr;
	delete ptrEnnemi;
	delete ptrJoueur;

	return infoEnnemi + infoJoueur;
}

void TourEnnemi(Magicien* ptrEnnemi, Magicien* ptrJoueur, Sort* choixAtt, Sort* choixDef)
{
	if (ptrEnnemi->IsMana()) 
	{
		int choixEnnemi{ RngInt(1,3) };
		if (choixEnnemi == 1 && ptrEnnemi->IsMana())
		{
			ptrEnnemi->Attaquer(ptrJoueur);
		}
		else if (choixEnnemi == 2 && ptrEnnemi->IsMana())
		{
			ptrEnnemi->Defendre();
		}
		else if (choixEnnemi == 3)
		{
			ptrEnnemi->Recharger(choixAtt, choixDef);
		}
	}
	else
	{
		ptrEnnemi->Recharger(choixAtt, choixDef);
	}
	
	ptrJoueur = nullptr;
	ptrEnnemi = nullptr;
	delete ptrEnnemi;
	delete ptrJoueur;
}
