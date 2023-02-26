#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
typedef struct point
{
    int lig,lib;
    char color,col;
} pt;
void joueur_humain(int tour,char tab_col_gri[100],pt tab_entree[100],float *ptg1,float *ptg2,int *pr_tail_cap,pt tab_capture[100],int *pr_terrN,int *pr_terrB,int cas11) /*jouer à tour de role entre les 2 joueurs*/
{
    int l,i,w,y;
    char c;
    first:
    y=0;
    w=0;
    printf("\n\nCHOISISEZ UNE CASE: (exemple: 1 B)");
    scanf("%d %c",&l,&c);
    if (c=='X' && l==1)
        {
        territoire(tab_entree,tab_col_gri,tour,pr_terrN,pr_terrB);
        joueur_gagnant(tab_entree,tour,pr_terrN,pr_terrB);
        exit(0);}
    for (i=0; i<=tour ;i++) if ((tab_entree[i].lig==l)&&(tab_entree[i].col==c)) y=1;
    for (i=0;i<=9;i++) if (tab_col_gri[i]==c) w+=1;
    if (w==1 && l<=10 && y==0){
        tab_entree[tour].lig=l;
        tab_entree[tour].col=c;
         if (cas11==3) tab_entree[tour].color='b';
        else{
        if (tour%2==0) tab_entree[tour].color='n';
        else tab_entree[tour].color='b';}
        tab_entree[tour].lib=lib_point(l,c);
        capture(tour,tab_entree,ptg1,ptg2,tab_capture,pr_tail_cap);
        int test=0,*pr_test;
        pr_test=&test;
        test_KO(tab_capture,pr_tail_cap,tab_entree,tour,pr_test);
        if (*pr_test==1) goto first;
        capture_chaine(tour,tab_entree);
        afficher_grille_dynamique(tab_entree,tour,tab_col_gri);
        printf("%d",*pr_tail_cap);
    }
    if (y==1) {
            printf("cette case est occupee\n");
            goto first;}
    if (w!=1) {
            printf("Vous devez entrer un caractere qui represente une colonne de la grille\n");
            goto first;}
    if (l>10) {
            printf("Vous devez entrer un nombre qui represente une ligne de la grille\n");
            goto first;}
}
