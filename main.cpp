#include <iostream>
#include <string>
#include "Personnage.h"
#include "functions.h"


//CONFIG


using namespace std;


int main()
{
    //CONFIGURATION DE L'INTERFACE

    cout << color(COLOR_WHITE) << color(BACKGROUND_BLACK);



    string nom;
    int choix;
    Personnage joueur; //init(nom, lvl, pdv, xpValue, atk);

    cout << "Bonjour\nNom du personnage : ";
    cin >> nom;
    joueur.init(nom, 1, 13, 5, 3);
    cout << "Felicitation, le personnage " << joueur.getName() << " a été créé !\n";

    while(joueur.getLife() > 0) {
        Personnage nmy;
        nmy.init("Ver de terre", 1, 5, 4, 2);
        nmy.setLife(5);
        choix = 0;
        cout << "Un " + nmy.getName() + " apparaît !\n";
        while(nmy.getLife() > 0 && joueur.getLife() > 0) {
            choix = 0;
            cout << "Que faire ?\n1 : Attaquer\n2 : Fuir\nChoix : ";
            cin >> choix;
            clearConsole();
            switch(choix) {
                case 1:
                joueur.attack(&nmy);
                if(nmy.isAlive()) { 
                    nmy.attack(&joueur);
                }
                break;
                case 2:
                cout << "Impossible pour le moment...";
                break;
            }
        }
    }
    if (joueur.getLife() < 0) {
        cout << "You died.\nNAME : " << joueur.getName() << "\nLVL : " << joueur.getLvl() << "\n\n";
        cout << "Thanks for playing." << endl;
    }
    return 0;
}