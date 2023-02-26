#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef struct point
{
    int lig,lib;
    char color,col;
} pt;

int coup_interdit(pt tab_entree[100],pt tab_capture[100],int *pr_tail_cap,int tour,int l,int c)
{

    if ((tab_capture[*pr_tail_cap-1].lig==l)&&(tab_capture[*pr_tail_cap-1].col==c)&&(tab_capture[*pr_tail_cap-1].color==tab_entree[tour].color)) return 1;
      /*cas de capture atarie*/

 else return 0;


}
