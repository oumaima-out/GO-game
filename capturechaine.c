
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
typedef struct point
{
    int lig,lib;
    char color,col;
} pt;

void ajouter(pt tab[100],pt point,int position)
{
    tab[position].lig=point.lig;
    tab[position].col=point.col;
    tab[position].lib=point.lib;
    tab[position].color=point.color;
}

void capture_chaine(int tour,pt tab_entree[100],int *pr_coup,pt tab_capture[100],int *pr_tail_cap)
{
    for(int i=0; i<=tour ; i++)
    {
premier:
        if (i<=tour)
        {
            if (tab_entree[i].lig!=-1)
            {

                pt tab_adj[100];
                int nbre_adj=0;
                int *pr_nbre_adj=&nbre_adj;
                pt liste_noeuds[100], liste_traite[100];
                int liber=tab_entree[i].lib;
                int *pr_liber=&liber;
                int tailN=1,tailT=0;
                int parcours=0;
                ajouter(liste_noeuds,tab_entree[i],0);
                while(parcours<tailN)
                {
                    int ex=0;
                    for (int j=0; j<tailT; j++)
                    {
                        if ((liste_traite[j].lig==liste_noeuds[parcours].lig) && (liste_traite[j].col==liste_noeuds[parcours].col) && (liste_traite[j].color==liste_noeuds[parcours].color)) ex=1;
                    }
                    if (ex==0)
                    {
                        adjacent(liste_noeuds[parcours],tour,tab_entree,tab_adj,pr_nbre_adj,pr_liber);


                        if (*pr_liber!=0)
                        {
                            i=i+1;
                            goto premier;
                        }
                        ajouter(liste_traite,liste_noeuds[parcours],tailT);
                        tailT+=1;
                        for (int j=0; j<*pr_nbre_adj; j++)
                        {
                            ajouter(liste_noeuds,tab_adj[j],tailN);
                            tailN+=1;
                        }
                    }
                    parcours+=1;
                }
                /*coup interdit*/
                for (int m=0; m<tailT; m++)
                {
                    if ((tab_entree[tour].lig==liste_traite[m].lig) && (tab_entree[tour].col==liste_traite[m].col)
                        && (tab_entree[tour].color==liste_traite[m].color)) *pr_coup=1;
                }


                if (*pr_coup==0)
                {
                    for (int k=0 ; k<=tour ; k++)
                    {
                        for (int j=0; j<tailT; j++)
                        {
                            if ((tab_entree[k].lig==liste_traite[j].lig) && (tab_entree[k].col==liste_traite[j].col) &&
                                (tab_entree[k].color==liste_traite[j].color) && (tab_entree[k].lib==liste_traite[j].lib)) tab_entree[k].lig=-1;

                        }
                    }
                }

            }

        }


    }

}



