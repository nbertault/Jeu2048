/* 
 * File:   Plateau.h
 * Author: nbertault
 *
 * Created on 31 janvier 2024, 08:54
 */

#ifndef PLATEAU_H
#define PLATEAU_H
#include <cstring>
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <future>
#include "jeu2048.h"
#include "joueur.h"



class Plateau
{
public:

    Plateau();
    
    void Afficher();
    bool JouerCoup();
    int RechercherJoueur(const string &_pseudo);
    void TrierTableauJoueurs();

private:
    
    int nbCoups;
    int score;
    Jeu2048 leJeu;
    Joueur tabJoueurs;

};

#endif /* PLATEAU_H */

