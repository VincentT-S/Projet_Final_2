//Vincent Tran-Sy, remise avant 28
//
#include <iostream>
#include <limits>
#include <ctype.h>
using namespace std;
int main()
{
//Déclarer les variables et des constantes et initialiser
    int i, j, CHOIX_STOCK, CHOIX_CODE, CODE_CHOISI, STOCK_AJOUTE, STOCK_VIEUX; //7 rangés?
    bool CHOIX_NONEXISTANT = true;
    const float TPQ = 0.09975, TPS = 0.05;
    string DIMENSION[4]    = {"Small","Medium","Big","Extra"};//se rapeller d'ajouter " ml" apres
    float       INFO[3][4] ={
                             {     50,     100,  250,    500},//CODE
                             {  15.99,   24.99,49.99,  89.99},//PRIX UNITAIRE
                             {      0,       0,    0,      0} //STOCK ACTUEL
                            };


//Inviter, lire et enregistrer les entrées
    //Inviter, lire et enregistrer le CHOIX 4.x
    do{
        cout<<"Choisissez :"<<endl<<
          "    1- POUR INVENTAIRE DE STOCK"<<endl<<
          "    2- POUR RENFOUEMENT DE STOCK"<<endl<<
          "    3- POUR MENU PRINCIPAL"<<endl;
        cin>>CHOIX_STOCK;

        if (CHOIX_STOCK!=1&&CHOIX_STOCK!=2&&CHOIX_STOCK!=3){//verification du chiffre
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            cout<<"Erreur ! Vous avez tape un mauvais nombre. Essayez a nouveau !"<<endl;
        } else {
            CHOIX_NONEXISTANT = false;
        }
    } while (CHOIX_NONEXISTANT);
    CHOIX_NONEXISTANT=true;//reset boolean

    if (CHOIX_STOCK==1||CHOIX_STOCK==2){
        do{
            cout<<"Entrer le CODE du produit (50, 100, 250 ou 500) pour afficher son INVENTAIRE DE STOCK:"<<endl;
            cin>>CHOIX_CODE;
            cout<<endl;
            if (CHOIX_CODE!=50&&CHOIX_CODE!=100&&CHOIX_CODE!=250&&CHOIX_CODE!=500){
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                cout<<"Le CODE de produit entre n'est pas valide."<<endl;
            } else {
            CHOIX_NONEXISTANT = false;
            }
        } while (CHOIX_NONEXISTANT);
        CHOIX_NONEXISTANT=true;//reset boolean

        //Changer le code en colonne de tableau correspondant
        switch (CHOIX_CODE) {
            case 50:CODE_CHOISI=0;
            break;
            case 100:CODE_CHOISI=1;
            break;
            case 250:CODE_CHOISI=2;
            break;
            case 500:CODE_CHOISI=3;
            break;
        }
        cout<<"CODE        : "<<INFO[0][CODE_CHOISI]<<endl;
        cout<<"DIMENSION   : "<<DIMENSION[CODE_CHOISI]<<endl;
        cout<<"STOCK ACTUEL: "<<INFO[2][CODE_CHOISI]<<endl<<endl;

        //Demande pour la quant. de stock ajoute si l'option 2 est choisi.
        if(CHOIX_STOCK==2){
            do{
                cout<<"Combien de produits voulez-vous ajouter au stock?"<<endl;
                cin>>STOCK_AJOUTE;
                if (STOCK_AJOUTE<0||!cin){
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                    cout<<"S.V.P. entrez un nombre positif"<<endl<<endl;
                } else {
                CHOIX_NONEXISTANT = false;
                }
            }while (CHOIX_NONEXISTANT);
            CHOIX_NONEXISTANT=true;//reset boolean
            //Ajout de la quant au stock
            STOCK_VIEUX = INFO[2][CODE_CHOISI];
            INFO[2][CODE_CHOISI] = STOCK_VIEUX+STOCK_AJOUTE;
            cout<<"Le nouveau stock a ete ajoute"<<endl;
            cout<<"STOCK ACTUEL: "<<INFO[2][CODE_CHOISI];
        }
    }


//Afficher la sortie
/*
CODE 		 : 50
DIMENSION 	 : Small ml
PRIX UNITAIRE: 15.99
TPS 		 : 0.8$CA (5%)
TPQ 		 : 1.6$CAc (9.975%)
TOTAL 		 : 18.38$CA
STOCK ACTUEL : 0 items
*/

}
