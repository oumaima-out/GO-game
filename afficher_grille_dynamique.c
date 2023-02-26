#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef struct point
{
    int lig,lib;
    char color,col;
} pt;
void afficher_grille_dynamique(pt tab_entree[100],int tour,char tab_col_gri[100])
{
    int i,j,k,t,m,s;

    for (i=0;i<=9;i++) printf("\t%c",tab_col_gri[i]);
    printf("\n\n");

    for (i=1;i<=10;i++){
        if (i==10) printf("    10  ");
        else printf("    %d   ",i);
        for (j=1;j<=10;j++){
            s=0;
            t=0;
            if (j==10){
                while (s==0 && t<=tour){
                    if ((i==tab_entree[t].lig) && (tab_entree[t].col==tab_col_gri[j-1])) {
                    if (tab_entree[t].color=='n') color(1);
                    else color(2);
                    s=s+1;
                    }
                    t=t+1;
                    }
                    if (s==0) printf("-");
            }
            else{
            while (s==0 && t<=tour){
                if ((i==tab_entree[t].lig) && (tab_entree[t].col==tab_col_gri[j-1])) {
                if (tab_entree[t].color=='n') color(1);
                else color(2);
                printf("-------");
                s=s+1;
                }
                t=t+1;
            }
            if (s==0) printf("--------");}
        }
        printf("\n");
        if (i!=10){
        for (k=0;k<=9;k++) printf("\t|");
        printf("\n");
        for (k=0;k<=9;k++) printf("\t|");
        printf("\n");
        }
    }
    }
