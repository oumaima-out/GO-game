/*G12*/
/*derniere version*/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef struct point /*le type des élts de tableau des points entrés, tab_col_gri, tab_cap*/
{
    int lig,lib; /*lig:ligne, lib:liberté*/
    char color,col; /*col:colonne*/
} pt;

int main()
{
    system("color E0"); /*la couleur de l'arrière plan de la console*/
    int  N=0,B=0,tour; /* N: Les points gagnés noirs, B Les points gagnés blances*/
    float *ptg1=&N, *ptg2=&B; /*les pointeurs de N et B*/
    int *pr_tour=&tour; /*pointeur sur le nbre de tour joué*/
    int cas,cas1,cas11,cas111,num_tsum;/*cas: choix 1er menu, cas1: choix entre humain ou machine, cas11: choix entre from scratch ou tsumego, cas111:choix enre tsumego facile,moy,diff*/
    char tab_col_gri[10]= {'A','B','C','D','E','F','G','H','I','J'}; /*tableau des colones de la grille*/
    pt tab_entree[100]; /*le tableau de type pt, contient les pts entrés par le joueur*/
    pt tab_capture[100]; /*tab des pts capturés*/
    int tail_cap=0; /*taille de tab_cap*/
    int *pr_tail_cap=&tail_cap;
    float terrN=0,terrB=0;
    float *pr_terrN=&terrN, *pr_terrB=&terrB;
    int a,*pr_a;
    pr_a=&a;
    int handicap;
    int point_handicap;
debut:
    printf("\n\n\t\t\t\t\t\t\t\t\t*Bievenue avec nous dans le monde de jeu de Go*\n\n\t Choisissez : \n\n\t\t1. Jouer\n\n\t\t2. Regles de jeu\n\n\t\t3. Quitter\n\n");
    scanf("%d",&cas);
    switch(cas)
    {
    case 1:
        printf("\n\n\t Choisissez : \n\n\t\t1. Joueur-Joueur\n\n\t\t2. Joueur-Machine\n\n");
        scanf("%d",&cas1);
        switch(cas1)
        {
        case 1:

            printf("Est ce que l'un de vous a besoin de poser des pierres handicap? si oui saisir un nombre impair des pierres sinon 0  \n");
            scanf("%d",&handicap);
            if(handicap!=0)
            {    int l;
                 char c;
                afficher_grille(tab_col_gri);
                for(int h=0;h<handicap;h++)
                { printf("\nchoisir l'intersection numero %d \n",h);
                  scanf("%d%c",&l,&c);
                  tab_entree[h].lig=l; tab_entree[h].lib=lib_point(l,c); tab_entree[h].color='n'; tab_entree[0].col=c;
                  tour=h;
                  afficher_grille_dynamique(tab_entree,tour,tab_col_gri);
                }
                tour+=1;
                goto boucle;
            }
            tirage_au_sort(); /*Determiner le joueur qui commencera la partie*/
             printf("Est ce que vous voulez qu'on ajoute 6,5 points au deuxieme joueur ? si oui saisir 1 sinon 0  \n");
             scanf("%d",&point_handicap);
             if(point_handicap==1) terrB=6,5;

            afficher_grille(tab_col_gri); /*afficher la grille vide*/
            tour=0;
            int r;
            boucle:
            while (tour<=99)
            {
                joueur_joueur(tour,tab_col_gri,tab_entree,ptg1,ptg2,pr_tail_cap,tab_capture,pr_terrN,pr_terrB); /*jouer à tour de role entre les 2 joueurs*/
                tour=tour+1;
            }
            territoire(tab_entree,tab_col_gri,tour,pr_terrN,pr_terrB);
            joueur_gagnant(tab_entree,tour,pr_terrN,pr_terrB);
        case 2:
            printf("\n\n\t Choisissez : \n\n\t\t1. Jouer from scratch facile\n\n\t\t2. Jouer from scratch moyen\n\n\t\t3.Jouer avec un tsumego\n\n");
            scanf("%d",&cas11);
            int M=0;
            switch(cas11)
            {
            case 1:
                a=0;
                pt tab_entree[100]; /*tab des points entres par les joueurs*/
                tirage_sort_machine(pr_a); /*Determiner le joueur qui commencera la partie*/
                if (*pr_a==1) goto machine;
                else
                {
                    afficher_grille(tab_col_gri); /*afficher la grille vide*/
machine:
                    tour=0;
                    while (tour<=99)
                    {
                        if(a==0)
                        {
                            if (tour%2==0) joueur_humain(tour,tab_col_gri,tab_entree,ptg1,ptg2,pr_tail_cap,tab_capture,pr_terrN,pr_terrB,cas11);
                            else
                            {
                                printf("Tapez 1 pour que la machine joue son tour:");
                                scanf("%d",&M);
                                joueur_machine(tour,tab_col_gri,tab_entree,ptg1,ptg2,pr_tail_cap,tab_capture,cas11);}
                        }
                        else
                        {
                            if (tour%2==0) joueur_machine(tour,tab_col_gri,tab_entree,ptg1,ptg2,pr_tail_cap,tab_capture,cas11);
                            else
                            {
                                joueur_humain(tour,tab_col_gri,tab_entree,ptg1,ptg2,pr_tail_cap,tab_capture,pr_terrN,pr_terrB,cas11);
                                printf("Tapez 1 pour que la machine joue son tour:");
                                scanf("%d",&M);}
                        }
                        tour=tour+1;}
                    territoire(tab_entree,tab_col_gri,tour,pr_terrN,pr_terrB);
                    joueur_gagnant(tab_entree,tour,pr_terrN,pr_terrB);}
            case 2:
                a=0;
                tirage_sort_machine(pr_a); /*Determiner le joueur qui commencera la partie*/
                if (*pr_a==1) goto machine2;
                else
                {
                    afficher_grille(tab_col_gri); /*afficher la grille vide*/
machine2:
                    tour=0;
                    while (tour<=99)
                    {
                        if(a==0)
                        {
                            if (tour%2==0) joueur_humain(tour,tab_col_gri,tab_entree,ptg1,ptg2,pr_tail_cap,tab_capture,pr_terrN,pr_terrB,cas11);
                            else
                            {
                                printf("Tapez 1 pour que la machine joue son tour:");
                                scanf("%d",&M);
                                joueur_machine(tour,tab_col_gri,tab_entree,ptg1,ptg2,pr_tail_cap,tab_capture,cas11);
                            }
                        }
                        else
                        {
                            if (tour%2==0) joueur_machine(tour,tab_col_gri,tab_entree,ptg1,ptg2,pr_tail_cap,tab_capture,cas11);
                            else
                            {
                                joueur_humain(tour,tab_col_gri,tab_entree,ptg1,ptg2,pr_tail_cap,tab_capture,pr_terrN,pr_terrB,cas11);
                                printf("Tapez 1 pour que la machine joue son tour:");
                                scanf("%d",&M);
                            }
                        }
                        tour=tour+1;

                    }
                    territoire(tab_entree,tab_col_gri,tour,pr_terrN,pr_terrB);
                    joueur_gagnant(tab_entree,tour,pr_terrN,pr_terrB);
                }
            case 3:
                printf("\n\n\t Choisissez : \n\n\t\t1. tsumego 1 \n\n\t\t2. tsumego 2\n\n\t\t3.tsumego 3\n\n");
                scanf("%d",&num_tsum);
                switch(num_tsum)
                {
                case 1:
                    tsumego1(tab_entree);
                    afficher_grille_dynamique(tab_entree,16,tab_col_gri);
                    a=0;
                    tirage_sort_machine(pr_a); /*Determiner le joueur qui commencera la partie*/
                    if (*pr_a==1)
                    {
                        tab_entree[17].lig=9;
                        tab_entree[17].col='G';
                        tab_entree[17].color='n';
                        tab_entree[17].lib=4;
                        afficher_grille_dynamique(tab_entree,17,tab_col_gri);
                        printf("\n\n\t\t*****FIN DU TSUMEGO:*****\n\n\n");
                        printf("  LE JOUEUR GAGNANT EST : LE NOIR");}
                    else
                    {joueur_humain(17,tab_col_gri,tab_entree,ptg1,ptg2,pr_tail_cap,tab_capture,pr_terrN,pr_terrB,cas11);
                        if(tab_entree[17].lig==9 && tab_entree[17].col=='G')
                        {
                            printf("\n\n\t\t*****FIN DU TSUMEGO:*****\n\n\n");
                            printf("  LE JOUEUR GAGNANT EST : LE BLANC");
                        }
                        else
                        {
                            tab_entree[18].lig=9;
                            tab_entree[18].col='G';
                            tab_entree[18].color='n';
                            tab_entree[18].lib=4;
                            capture(18,tab_entree,ptg1,ptg2,tab_capture,pr_tail_cap);
                            afficher_grille_dynamique(tab_entree,18,tab_col_gri);
                            printf("\n\n\t\t*****FIN DU TSUMEGO:*****\n\n\n");
                            printf("  LE JOUEUR GAGNANT EST : LE NOIR");
                        }
                    }
                    exit(0);

                case 2:
                    tsumego2(tab_entree);
                    afficher_grille_dynamique(tab_entree,15,tab_col_gri);
                    a=0;
                    tirage_sort_machine(pr_a); /*Determiner le joueur qui commencera la partie*/
                    if (*pr_a==1)
                    {
                        tab_entree[16].lig=9;
                        tab_entree[16].col='F';
                        tab_entree[16].color='n';
                        tab_entree[16].lib=4;
                        afficher_grille_dynamique(tab_entree,16,tab_col_gri);
                        printf("\n\n\t\t*****FIN DU TSUMEGO:*****\n\n\n");
                        printf("  LE JOUEUR GAGNANT EST : LE NOIR");
                    }
                    else
                    {
                        joueur_humain(16,tab_col_gri,tab_entree,ptg1,ptg2,pr_tail_cap,tab_capture,pr_terrN,pr_terrB,cas11);
                        if(tab_entree[16].lig==9 && tab_entree[16].col=='F')
                        {
                            printf("\n\n\t\t*****FIN DU TSUMEGO:*****\n\n\n");
                            printf("  LE JOUEUR GAGNANT EST : LE BLANC");
                        }
                        else
                        {
                            tab_entree[17].lig=9;
                            tab_entree[17].col='F';
                            tab_entree[17].color='n';
                            tab_entree[17].lib=4;
                            capture(17,tab_entree,ptg1,ptg2,tab_capture,pr_tail_cap);
                            afficher_grille_dynamique(tab_entree,17,tab_col_gri);
                            printf("\n\n\t\t*****FIN DU TSUMEGO:*****\n\n\n");
                            printf("  LE JOUEUR GAGNANT EST : LE NOIR");
                        }
                    }
                    return 0;



                case 3:
                    tsumego3(tab_entree);
                    afficher_grille_dynamique(tab_entree,13,tab_col_gri);
                    a=0;
                    tirage_sort_machine(pr_a); /*Determiner le joueur qui commencera la partie*/
                    if (*pr_a==1)
                    {
                        tab_entree[14].lig=10;
                        tab_entree[14].col='I';
                        tab_entree[14].color='n';
                        tab_entree[14].lib=3;
                        afficher_grille_dynamique(tab_entree,14,tab_col_gri);
                        printf("\n\n\t\t*****FIN DU TSUMEGO:*****\n\n\n");
                        printf("  LE JOUEUR GAGNANT EST : LE NOIR");
                    }
                    else
                    {
                        joueur_humain(14,tab_col_gri,tab_entree,ptg1,ptg2,pr_tail_cap,tab_capture,pr_terrN,pr_terrB,cas11);
                        if(tab_entree[14].lig==10 && tab_entree[14].col=='I')
                        {
                            printf("\n\n\t\t*****FIN DU TSUMEGO:*****\n\n\n");
                            printf("  LE JOUEUR GAGNANT EST : LE BLANC");
                        }
                        else
                        {
                            tab_entree[15].lig=9;
                            tab_entree[15].col='I';
                            tab_entree[15].color='n';
                            tab_entree[15].lib=3;
                            capture(15,tab_entree,ptg1,ptg2,tab_capture,pr_tail_cap);
                            afficher_grille_dynamique(tab_entree,15,tab_col_gri);
                            printf("\n\n\t\t*****FIN DU TSUMEGO:*****\n\n\n");
                            printf("  LE JOUEUR GAGNANT EST : LE NOIR");
                        }
                    }
                    return 0;
                }
            }

        }
    case 2:
        printf("\t\t\t\t\t*Les regles du jeu Go*\n\n");
        printf("   1.Capture:\n\n");
        printf(" Lorsqu'un joueur supprime la derniere liberte d'une chaine adverse,il la capture en retirant du goban les pierres\n de cette chaine.\n");
        printf(" De plus, en posant une pierre, un joueur ne doit pas construire une chaine sans liberte, sauf si par ce coup il capture une chaine adverse.");
        printf("\n\n\n   2.Vie et mort:\n\n");
        printf(" De la regle de capture decoule la notion de vie et de mort : des pierres mortes sont des pierres que l'on est sur de \n");
        printf(" sans y perdre par ailleurs, tandis que des pierres vivantes sont des pierres que l'on ne peut plus esperer capturer.");
        printf("\n\n\n   3.Repetition:\n\n");
        printf(" Un joueur, en posant une pierre, ne doit pas redonner au goban un etat identique à l'un de ceux qu'il lui avait deja\n donne.\n\n\n");
        printf("\tVoulez vous jouer?\n\tSi oui tapez 1, sinon tapez 0: ");
        int h;
        scanf("%d",&h);
        if (h==1) goto debut;
        else return 0;

    case 3:
        return 0;
    }
    return 0;

}

