#include "Personnage.h"
#include "functions.h"


using namespace std;

//CONFIG

//Methodes
void Personnage::init(string newNom, int newLvl, int newPdv, int newXpValue, int newAtk) {
    
    nom = newNom;
    lvl=DEFAULT_LVL;
    pdv = DEFAULT_PDV;
    pdvMax = pdv;
    pda = DEFAULT_PDA;
    xp = 0;
    xpValue = 5;
    atk = 3;
    dead = 0;
}

//getter
string Personnage::getName() {
    return nom;
}
int Personnage::getLife(){
	return pdv;
}
int Personnage::getAtk() {
	return atk;
}
int Personnage::getLvl() {
	return lvl;
}
int Personnage::getXp() {
	return xp;
}

//setter    -> Servent à changer les valeurs au cours du main
void Personnage::setLife(int amount) { //Permet de changer la vie
	if(pdv>=0) {
		pdv = amount;
	}
	else {
		pdv = 0;
	}
	refreshDead();
}

//tester
bool Personnage::isAlive() {
	return !dead;
}

//printer
void Personnage::printLife() {
	cout << getName() << "(" << getLife() << " pdv)" << endl;
	//printWithSeparators(nom + "(" + to_string(pdv) + " pdv)"); //Ne fait pas très joli
}
void Personnage::printLvlUp() {
	printWithSeparators(color(COLOR_GREEN) + getName() + color(COLOR_WHITE) + " est maintenant niveau " + to_string(lvl) + " !\nSon attaque est maintenant de " + to_string(getAtk()) + ".");
}
void Personnage::printIsDead() {
	printWithSeparators(getName() + " est mort !");
}
void Personnage::printIsAlive() {
	printWithSeparators(getName() + " est toujours en vie !");
}
void Personnage::printAtk(Personnage *cible) {
    cout << getName() << "[lvl " << getLvl() << "]("<< getLife() << "pdv) attaque " << cible->getName() << "[lvl " << cible->getLvl() <<"]("<< cible->getLife()<<"pdv) ! -> (-"<< getAtk() << "pdv)"; 
    cout << endl << endl;
    usleep(800000);
}
void Personnage::printGotXp(int amount) {
	cout << getName() << " a gagné " << to_string(amount) << " points d'xp.";
	int remaining = getNeededXp() - getXp();
	if(remaining > 0) {
		cout << " (reste " << to_string(remaining) << " pour passer au niveau suivant..)";
	}
	cout << endl;
}


//ACTIONS DE COMBAT
void Personnage::attack(Personnage *cible) {
	printAtk(cible);
	cible->takeDmg(atk);
	//cout << cible->getName() << " perd " << atk << " pdv !" <<endl;
	if(cible->getLife() <= 0) {
		cible->aleatGiveXpTo(this);
	}
	else {

	}
}
void Personnage::takeDmg(int dmg) {
    pdv = pdv-dmg; //on retire les dommages subits
    refreshDead();
}
void Personnage::heal() {
	pdv = pdvMax; //on restaure les pdv
}



//ACTIONS SUR L'XP
void Personnage::aleatGiveXpTo(Personnage *cible) {
	int aleatXp = xpValue * (getLvl()/cible->getLvl() +1) *2; //Nombre généré en fonction du lvl des 2 perso
	cible->addXp(aleatXp); //On donne l'xp à la cible
}
void Personnage::addXp(int amount) {
	xp += amount;
	refreshXp();
	printGotXp(amount);
}
int Personnage::getNeededXp() {
	return ((lvl+1)*5)*180/100; //Calcul de l'xp nécéssaire pour up (provisoire)
}
void Personnage::levelUp() {
	heal();
	xp -= getNeededXp(); //On retire l'xp nécéssaire pour up
	++lvl; //on up
	atk += 1 + 0.1*(lvl);
	pdv+=2;
	printLvlUp(); //et on l'affiche
}



//refresher
void Personnage::refreshDead() {
	if(pdv <= 0) { //Si la vie est négative
		dead=1; //Alors le perso est mort
		printIsDead(); //et donc on le signale
	}
}
void Personnage::refreshXp() {
	while(xp >= getNeededXp()) { //Tant que xp> xp nécéssaire pour up -> 
 		levelUp();
	}
}