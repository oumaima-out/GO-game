#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

typedef struct point
{
    int lig,lib;
    char color,col;
} pt;

void joueur_machine(int tour,char tab_col_gri[100],pt tab_entree[100],float *ptg1,float *ptg2,int *pr_tail_cap,pt tab_capture[100],int cas11) /*jouer à tour de role entre les 2 joueurs*/
{
    int l,i,y;
    char c;
    first:
    y=0;
    int *ligne=&l;
    char *colonne=&c;
    if(cas11==1 || (cas11==2 && tour==0)){
    srand(time(NULL)); /*initialiser le tirage*/
    l=(rand()%10)+1;
    c=tab_col_gri[rand()%10];}
    if(cas11==2 && tour!=0) {
        machine_moy(tab_entree,tour,ligne,colonne,tab_capture,pr_tail_cap);
        l=*ligne;
        c=*colonne;
    }

    for (i=0; i<=tour ;i++) if ((tab_entree[i].lig==l)&&(tab_entree[i].col==c)) y=1;
    if (y==0){
        tab_entree[tour].lig=l;
        tab_entree[tour].col=c;
        if (tour%2==0) tab_entree[tour].color='n';
        else tab_entree[tour].color='b';
        tab_entree[tour].lib=lib_point(l,c);
        capture(tour,tab_entree,ptg1,ptg2,tab_capture,pr_tail_cap);
        int test=0,*pr_test;
        pr_test=&test;
        if (coup_interdit(tab_entree,tab_capture,pr_tail_cap ,tour,l,c)==1)  goto first ;
        test_KO(tab_capture,pr_tail_cap,tab_entree,tour,pr_test);
        if (*pr_test==1) goto first;
        capture_chaine(tour,tab_entree);
        afficher_grille_dynamique(tab_entree,tour,tab_col_gri);
        printf("%d",*pr_tail_cap);
    }
    if (y==1) {
            goto first;}
}
