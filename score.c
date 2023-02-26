#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef struct point
{
    int lig,lib;
    char color,col;
} pt;

void joueur_gagnant(pt tab_entree[100],int tour,float *pr_terrN,float *pr_terrB)
{
    for (int i=0; i<=tour ;i++){
        if ((tab_entree[i].lig==-1) && (tab_entree[i].color=='n')) *pr_terrN-=1;
        if ((tab_entree[i].lig==-1) && (tab_entree[i].color=='b')) *pr_terrB-=1;
    }
    printf("\n\n\t\t*****FIN DE LA PARTIE:*****\n\n\n");
    if (*pr_terrN>*pr_terrB)
    printf("  LE JOUEUR GAGNANT EST : LE NOIR");
    else   {if (*pr_terrN==*pr_terrB) printf("  PARTIE NULL");
        else printf("  LE JOUEUR GAGNANT EST : LE BLANC");}
}
