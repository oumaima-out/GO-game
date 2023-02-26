#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

typedef struct point
{
    int lig,lib;
    char color,col;
} pt;

void nombre_liberte(pt point,pt tab_entree[100],int *pr_liber1,int tour)

{
    int l=point.lib;
    for(int j=0; j<=tour; j++)
    {
        if (point.lig!=-1)
        {
            if(tab_entree[j].color==point.color)
            {
                if (tab_entree[j].lig==point.lig)
                {
                    if (tab_entree[j].col==(point.col+1)) l=l-1;
                    if (tab_entree[j].col==(point.col-1)) l=l-1;
                }

                if (tab_entree[j].col==point.col)
                {
                    if (tab_entree[j].lig==(point.lig+1)) l=l-1;
                    if (tab_entree[j].lig==(point.lig-1))  l=l-1;
                }
            }
        }
    }

    *pr_liber1=l;
}






















void machine_moy(pt tab_entree[100],int tour,int *ligne,int *colonne,pt tab_capture[100],int *pr_tail_cap)
{
    int libe1=0;
    int *pr_liber1=&libe1;
    int libt=4;
    char colorr;
    if (tour%2==0) colorr='n';
    else colorr='b';
    for(int u=0; u<tour; u++)
    {
        if (tab_entree[u].color!=colorr)
        {
            nombre_liberte(tab_entree[u],tab_entree,pr_liber1,tour-1);
            if((*pr_liber1<libt || *pr_liber1==4) && (*pr_liber1>0))
            {
                libt=*pr_liber1;
                joueur_machine_medium(tab_entree,u,ligne,colonne,tab_capture,pr_tail_cap,tour);
            }

        }
    }
}
