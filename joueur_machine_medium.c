#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

typedef struct point
{
    int lig,lib;
    char color,col;
} pt;

void joueur_machine_medium(pt tab_entree[100],int pos,int *ligne, char *colonne,pt tab_capture[100],int *pr_tail_cap,int tour)
{
    int ld=0;
    int lg=0;
    int cd=0;
    int cg=0;
    for (int j=0;j<tour;j++){

                if (tab_entree[j].lig==tab_entree[pos].lig)
                {
                    if (tab_entree[j].col==(tab_entree[pos].col+1)) ld=1;
                    if (tab_entree[j].col==(tab_entree[pos].col-1)) lg=1;
                }

                if (tab_entree[j].col==tab_entree[pos].col)
                {
                    if (tab_entree[j].lig==(tab_entree[pos].lig+1))
                    {
                        cd=1;
                    }

                if (tab_entree[j].lig==(tab_entree[pos].lig-1))

                    {
                        cg=1;
                    }
                }

    }
    if (tab_entree[pos].col=='A') lg=1;
    if (tab_entree[pos].col=='J') ld=1;
    if (tab_entree[pos].lig==1) cg=1;
    if (tab_entree[pos].lig==10) cd=1;


    if (ld==0 && coup_interdit(tab_entree,tab_capture,pr_tail_cap ,tour,tab_entree[pos].lig,tab_entree[pos].col+1)!=1 ) {
        *ligne=tab_entree[tour-1].lig ;
        *colonne=tab_entree[pos].col+1;
    }
    else {if (lg==0 && coup_interdit(tab_entree,tab_capture,pr_tail_cap ,tour,tab_entree[pos].lig,tab_entree[pos].col-1)!=1) {
        *ligne=tab_entree[pos].lig ;
        *colonne=tab_entree[pos].col-1;
    }
    else {if (cd==0 && coup_interdit(tab_entree,tab_capture,pr_tail_cap ,tour,tab_entree[pos].lig+1,tab_entree[pos].col)!=1) {
        *ligne=tab_entree[pos].lig+1 ;
        *colonne=tab_entree[pos].col;
    }
    else {if (cg==0 && coup_interdit(tab_entree,tab_capture,pr_tail_cap ,tour,tab_entree[pos].lig-1,tab_entree[pos].col)!=1) {
        *ligne=tab_entree[pos].lig-1 ;
        *colonne=tab_entree[pos].col;
    }
    }
}

}
}
