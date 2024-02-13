/* 
 * File:   Plateau.cpp
 * Author: nbertault
 * 
 * Created on 31 janvier 2024, 08:54
 */

#include "plateau.h"

Plateau::Plateau()
{
    score = 0;
    nbCoups = 0;
}

void Plateau::Afficher()
{
    int laGrille[TAILLE][TAILLE];
    int indice;

    system("clear");
    leJeu.ObtenirGrille(laGrille);
    cout << "| Score : " << score << " | Nombre de coups : " << nbCoups << " |" << endl;
    cout << endl;
    for (int ligne = 0; ligne < 4; ligne++)
    {
        cout << " +";
        for (indice = 0; indice < 4; indice++)
        {
            cout << setw(7) << setfill('-') << '+';

        }
        cout << endl << " |";
        for (indice = 0; indice < 4; indice++)
        {
            if (laGrille[ligne][indice] != 0)
                cout << setfill(' ') << setw(6) << laGrille[ligne][indice] << '|'; // affichage d'une ligne de la grille
            else
            {
                cout << setfill(' ') << setw(7) << '|'; // affichage d'une ligne de la grille
            }
        }
        cout << endl;
    }
    cout << " +";
    for (indice = 0; indice < 4; indice++)// affichage de la dernière ligne du tableau
        cout << setw(7) << setfill('-') << '+';

    cout << endl << endl << "F pour sortir du jeu" << endl;
    cout << "Votre déplacement : H(↑), B(↓), G(←), D(→) : " << endl; // affichage du texte sous le tableau
}

bool Plateau::JouerCoup()
{
    bool retour = false;
    char touche;
    cin >> touche;
    bool calcul;
    touche = toupper(touche);
    ETATS_DU_JEU partie;

    if (strchr("BHGD", touche) != nullptr)
    {
        nbCoups++;

        leJeu.Deplacer(touche);
        calcul = leJeu.Calculer(touche);
        leJeu.Deplacer(touche);
        partie = leJeu.RechercherFinDePartie();
        switch (partie)
        {
        case EN_COURS:
            leJeu.PlacerNouvelleTuille();
            score = leJeu.CalculerScore();
            Afficher();
            break;
        case GAGNE:
            cout << "Bien Joué vous avez gagné" << endl;
            retour = true;
            break;
        case PERDU:
            cout << "Dommage vous avez perdu. Retentez votre chance" << endl;
            retour = true;
            break;
        }
    }
    if (touche == 'F')
        retour = true;
    return retour;
}

int RechercherJoueur(const string &_pseudo)
{
    int i = 0;

    while (_tab[i] != _pseudo && i < _nb)
        i++;

    if (i == _nb)
    {
        i = -1;
    }

    return i;
}

void TrierTableauJoueurs()
{
    int borne = _nb;
    bool tri = false;
    while (tri == false)
    {
        tri = true;
        for (int i = 0; i < borne-1; i++)
        {
            if (_tab[i] < _tab[i+1])
            {
                Joueur compteur = _tab[i];
                _tab[i] = _tab[i + 1];
                _tab[i + 1] = compteur;
                tri = false;
            }
        }
        borne--;
    }
}