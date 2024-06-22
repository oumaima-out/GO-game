#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

typedef struct point
{
    int lig,lib;
    char color,col;
} pt;


void adjacent(pt poin,int tour,pt tab_entree[100],pt tab_adj[100],int *pr_nbre_adj,int *pr_liber)
{
    int l=poin.lib;

    int k=0;
    for(int j=0; j<=tour; j++)
    {
        if (poin.lig!=-1)
        {
            if(tab_entree[j].color==poin.color)
            {
                if (tab_entree[j].lig==poin.lig)
                {
                    if (tab_entree[j].col==(poin.col+1))
                    {
                        ajouter(tab_adj,tab_entree[j],k);
                        (k++);
                        l=l-1;
                    }

                    if (tab_entree[j].col==(poin.col-1))
                    {
                        ajouter(tab_adj,tab_entree[j],k);
                        (k++);
                        l=l-1;
                    }
                }

                if (tab_entree[j].col==poin.col)
                {
                    if (tab_entree[j].lig==(poin.lig+1))
                    {
                        ajouter(tab_adj,tab_entree[j],k);
                        (k++);
                        l=l-1;
                    }

                    if (tab_entree[j].lig==(poin.lig-1))

                    {
                        ajouter(tab_adj,tab_entree[j],k);
                        (k++);
                        l=l-1;
                    }
                }
            }
            if(tab_entree[j].color!=poin.color)
            {
                if (tab_entree[j].lig==poin.lig)
                {
                    if (tab_entree[j].col==(poin.col+1))
                       {
                           l=l-1;
                       }
                    if (tab_entree[j].col==(poin.col-1))
                        {l=l-1;
                        }
                }

                if (tab_entree[j].col==poin.col)
                {
                    if (tab_entree[j].lig==(poin.lig+1))
                    {
                        l=l-1;
                    }

                    if (tab_entree[j].lig==(poin.lig-1))

                    {
                        l=l-1;
                    }
                }
            }
        }
    }
    *pr_nbre_adj=k;
    *pr_liber=l;
}
