
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef struct point
{
    int lig,lib;
    char color,col;
} pt;

void territoire(pt tab_entree[100],char tab_col_gri[10],int tour,int *pr_terrN, int *pr_terrB)
{
    char clr;
    *pr_terrN=0;
    *pr_terrB=0;
    for(int i=1;i<=10;i++)
    {
        int s=0;
        for(int j=0;j<=9;j++)
        {
            if(j==9) {

               /* if (clr=='n')  {  *pr_scoreN+=s;   }
                else  {  *pr_scoreB+=s;    }*/


            int ex=0;
            for(int k=0;k<=tour;k++)
            {

                if((tab_entree[k].lig==i)&&(tab_entree[k].col==tab_col_gri[j]))
                {
                    ex=1;
                    goto second1;
                }

            }
            second1:
            if(ex==0)
             {
                 s+=1;
                 if (clr=='n')  {  *pr_terrN+=s;   }
                else  {  *pr_terrB+=s;   }
            }
            if(ex==1){
                if (clr=='n')  {  *pr_terrN+=s; }
                else  {  *pr_terrB+=s;}
            }
            }


            else{
            int ex=0;
            for(int k=0;k<=tour;k++)
            {

                if((tab_entree[k].lig==i)&&(tab_entree[k].col==tab_col_gri[j]))
                {
                    ex=1;
                    clr=tab_entree[k].color;
                    goto second;
                }

            }
            second:
            if(ex==0) s+=1;
            if(ex==1){
                if (clr=='n')  {  *pr_terrN+=s;    s=0;}
                else  {  *pr_terrB+=s;    s=0;}
            }
            }

        }
    }
}










