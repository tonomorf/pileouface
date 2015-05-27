/****************************************************************************************************************
 *                     SIMULATEUR DE PILE OU FACE                                                               *
 * Auteur       : Fromonot Camille                                                                              *
 * Mail         : Fromonot.camille@gmail.com                                                                    *
 * Date         : 24/05/2015                                                                                    *
 * Fichier      : Programme                                                                                     *
 * Description  : Simulateur de pile ou face,on peut jouer (y); simuler n lancer de pieces (s); ou quitter(n).  *
 *                Le simulateur donne le nombres de pile le nombres de face et le rapport pile/face.            *
 *                Quand on quitte, le programme vous donne ces meme donnees, seulement pour le jeu.             *
 ****************************************************************************************************************/

#include <iostream> // Bibliotheque entrees sortie
#include <time.h>   // Bibliotheque du temps
#include <stdlib.h> // Bibliotheque pour random()
#include <string.h> // Bibliotheque pour variable string
using namespace std;
string resultat;    // Definition variable globale pour interaction avec la console
float pf();         // Definition fonction tirage pile ou face
float spf();        // Definition fonction simulation
float p;            // Definition variable pile
float nf;           // Definition variable nombres de faces
float np;           // Definition variable nombre de piles
float k;            // Definition variable rapport pile/face

float spf()         // Attribution fonction simulation
{
    int i;  // Definition variable globale compteur boucle for
    int a;  // Definition variable nombres lancers

    // Attribution des variables compteur for; nlancers; nombre pile; nombre face
    a=0;
    i=0;
    np=0;
    nf=0;

    //Choisir le nombre de simulation
    cout<<"nombre de simulations  ";
    while( !(cin >> a) )
    {
    string tmp;
    cin.clear();
    cin >> tmp;
    cout << "incorrect , ce n'est pas nombre! " << endl;
        }

    for (i=0;i<a;i++)  // Debut de boucle for:une simulation 'c'est un lancer de piece
    {
        pf();

        if(p==1)      // Si le lancer est pile nombre de pile = nombre de pile +1
        {
            np++;
        }

        else          // Sinon nombre de faces= nombre de faces +1
        {
            nf++;
        }
    }

    k=np/nf;          // Attribution de la variable k rapport pile/face.

    // Affichage des resultats de la simulation
    cout<<"nombres de piles  "<<np<<endl
        <<"nombres de faces  "<<nf<<endl
        <<"rapport pile/face  "<<k<<endl;

}

float pf()           // Attribution fonction tirage pile ou face
{
    int var;         // Declaration variable locale var
    var=rand()%2;    // Attribution variable locale var
    p=0;             // Attribution variable globale pile

    if(var==0)
    {
        if (resultat!="s" && resultat!="n")     // Si var = 0 et qu'on choisi le mode tirage,
        {
            cout<<"PILE"<<endl;                 // affichage PILE et
        }
        p++;                                    // p=1
    }

    else
    {
        if (resultat!="s"&& resultat!="n")      // Sinon en mode tirage,
        {
            cout<<"FACE"<<endl;                 // affichage face
        }

    }
}


int main()                                     // Debut fonction principale
{
    srand(time(NULL));                         // Definition graine rand()
    resultat="pass";                           // Attribution variable globale interaction console

    // Boucle principale : repeter tout tant que resultat = y ou s
    do
    {   np=0;                                  // Attribution nombres pile et nombres face en debut de boucle principale
        nf=0;

        // Deuxieme boucle : Si resultat = n , on casse la boucle;
        // Si resultat= y , on apelle la fonction tirage pile ou face
        do
        {
            // 3em boucle: Si on ecrit autre chose que y,n,s, repetition de la boucle
            do
            {
                cout<<"Play?(y/n/s)";
                cin>>resultat;
            } while (resultat!="y" && resultat!="n" && resultat!="s");

            if(resultat=="n")
            {
                break;
            }

            pf();                             // Appel de la fonction tirage pile ou face (2em boucle)

            if(p==1)                          // Si il ya un pile, nombre de pile = nombre de pile +1
            {
                np++;
            }
            else                              // Sinon, nombre de face = nombre de face +1
            {
                nf++;
            }
        } while(resultat=="y");

        // Quand on quitte, affichage des valeurs nombre piles, nombre face , et rapport pile/face
        if (resultat=="n")
        {
            k=np/nf;
            cout<<"nombres de piles  "<<np<<endl
                <<"nombres de faces  "<<nf<<endl
                <<"rapport pile/face  "<<k<<endl;}

        // si resultat = s , appel de la fonction simulation
        if(resultat=="s")
        {
        spf();
        }
    } while(resultat=="y"||resultat=="s");
}
