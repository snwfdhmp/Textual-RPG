#ifndef DEF_PERSONNAGE
#define DEF_PERSONNAGE

#include <string>
#include <iostream>
#include <unistd.h>
//#include "Monster.h"
using namespace std;

//CONFIG
#define DEFAULT_LVL             1
#define DEFAULT_PDV             13
#define DEFAULT_PDA             10

//string separator = "========================\n";

class Personnage
{
public:
    //Methodes
    void init(string newNom, int newLvl, int newPdv, int newXpValue, int newAtk);

    //getter
    string getName();
    int getLife();
    int getAtk();
    int getLvl();
    int getXp();

    //setter
    void setLife(int newLife);

    //tester
    bool isAlive();

    //printer
    void printLife();
    void printLvlUp();
    void printIsDead();
    void printIsAlive();
    void printAtk(Personnage *cible);
    void printGotXp(int amount);

    //ACTIONS DE COMBAT
    void attack(Personnage *cible);
    void takeDmg(int dmg);
    void heal();

    //RAFFRAICHISSEURS
    void refreshDead();
    void refreshXp();


    //ACTIONS SUR L'XP
    void aleatGiveXpTo(Personnage *cible);
    void addXp(int amount);
    int getNeededXp();
    void levelUp();

private:
    //Variables
    string nom;
    int lvl, pdv, pdvMax, pda, level, atk, xp, dead, xpValue;
};
#endif