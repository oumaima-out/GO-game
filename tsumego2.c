#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef struct point
{
    int lig,lib;
    char color,col;
} pt;

void tsumego2(pt tab_entree[100])
{
tab_entree[0].lig=8; tab_entree[0].lib=4; tab_entree[0].color='n'; tab_entree[0].col='I';
tab_entree[1].lig=10; tab_entree[1].lib=3; tab_entree[1].color='b'; tab_entree[1].col='G';
tab_entree[2].lig=9; tab_entree[2].lib=4; tab_entree[2].color='n'; tab_entree[2].col='H';
tab_entree[3].lig=9; tab_entree[3].lib=4; tab_entree[3].color='b'; tab_entree[3].col='G';
tab_entree[4].lig=8; tab_entree[4].lib=4; tab_entree[4].color='n'; tab_entree[4].col='G';
tab_entree[5].lig=8; tab_entree[5].lib=4; tab_entree[5].color='b'; tab_entree[5].col='F';
tab_entree[6].lig=7; tab_entree[6].lib=4; tab_entree[6].color='n'; tab_entree[6].col='F';
tab_entree[7].lig=8; tab_entree[7].lib=4; tab_entree[7].color='b'; tab_entree[7].col='E';
tab_entree[8].lig=7; tab_entree[8].lib=4; tab_entree[8].color='n'; tab_entree[8].col='E';
tab_entree[9].lig=8; tab_entree[9].lib=4; tab_entree[9].color='b'; tab_entree[9].col='D';
tab_entree[10].lig=7; tab_entree[10].lib=4; tab_entree[10].color='n'; tab_entree[10].col='D';
tab_entree[11].lig=9; tab_entree[11].lib=3; tab_entree[11].color='b'; tab_entree[11].col='D';
tab_entree[12].lig=9; tab_entree[12].lib=4; tab_entree[12].color='n'; tab_entree[12].col='C';
 tab_entree[13].lig=10; tab_entree[13].lib=3; tab_entree[13].color='b'; tab_entree[13].col='E';
tab_entree[14].lig=8; tab_entree[14].lib=4; tab_entree[14].color='n'; tab_entree[14].col='C';
 tab_entree[15].lig=7; tab_entree[15].lib=4; tab_entree[15].color='n'; tab_entree[15].col='C';
}
