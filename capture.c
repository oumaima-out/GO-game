#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef struct point
{
    int lig,lib;
    char color,col;
} pt;

/*cette proc test chaque pt du tab_entree avec les autres pts si c'est un pt à capturer, elle ajoute ds tab_cap*/
void capture(int tour,pt tab_entree[100],int *ptg1,int *ptg2,pt tab_capture[100],int *pr_tail_cap)
{
    for (int i=0; i<=tour; i++)
    {
        int l,j;
        if (tab_entree[i].lig==-1) continue;
        l=lib_point(tab_entree[i].lig,tab_entree[i].col);

            for(j=0; j<=tour; j++)
            {
                if(tab_entree[j].color!=tab_entree[i].color)
                {
                    if (tab_entree[j].lig==tab_entree[i].lig)
                    {
                        if (tab_entree[j].col==(tab_entree[i].col+1)) l-=1;
                        if (tab_entree[j].col==(tab_entree[i].col-1)) l-=1;
                        }
                    if (tab_entree[j].col==tab_entree[i].col)
                    {
                        if((tab_entree[j].lig+1)==tab_entree[i].lig) l-=1;
                        if ((tab_entree[j].lig-1)==tab_entree[i].lig) l-=1;
                    }
                }
            }
            if(l==0)
            {
                ajouter(tab_capture,tab_entree[i],*pr_tail_cap);
                *pr_tail_cap=*pr_tail_cap+1;
                tab_entree[i].lig=-1 ;

            }

    }
}


