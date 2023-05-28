#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void afficher_grille(char tab_col_gri[10]) /*afficher la grille vide*/
{
    int i,j,k; /*ces var pour le parcours*/
    for (i=0;i<=9;i++) printf("\t%c",tab_col_gri[i]);
    printf("\n\n");

    for (i=1;i<=9;i++){
        printf("    %d   ",i);
        for (j=1;j<=9;j++)
            printf("--------");
        printf("\n");
        for (k=0;k<=9;k++) printf("\t|    ");
        printf("\n");
        for (k=0;k<=9;k++) printf("\t|    ");
        printf("\n");
    }
    printf("    10  ");
    for (j=1;j<=9;j++) printf("--------");
}
