#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef struct point
{
    int lig,lib;
    char color,col;
} pt;

void tsumego3(pt tab_entree[100])
{
tab_entree[0].lig=6; tab_entree[0].lib=4; tab_entree[0].color='n'; tab_entree[0].col='H';
tab_entree[1].lig=7; tab_entree[1].lib=4; tab_entree[1].color='b'; tab_entree[1].col='F';
tab_entree[2].lig=6; tab_entree[2].lib=4; tab_entree[2].color='n'; tab_entree[2].col='I';
tab_entree[3].lig=7; tab_entree[3].lib=4; tab_entree[3].color='b'; tab_entree[3].col='I';
tab_entree[4].lig=7; tab_entree[4].lib=3; tab_entree[4].color='n'; tab_entree[4].col='J';
tab_entree[5].lig=8; tab_entree[5].lib=4; tab_entree[5].color='b'; tab_entree[5].col='I';
tab_entree[6].lig=8; tab_entree[6].lib=4; tab_entree[6].color='n'; tab_entree[6].col='H';
tab_entree[7].lig=9; tab_entree[7].lib=4; tab_entree[7].color='b'; tab_entree[7].col='H';
tab_entree[8].lig=8; tab_entree[8].lib=4; tab_entree[8].color='n'; tab_entree[8].col='F';
tab_entree[9].lig=8; tab_entree[9].lib=4; tab_entree[9].color='n'; tab_entree[9].col='G';
tab_entree[10].lig=9; tab_entree[10].lib=4; tab_entree[10].color='b'; tab_entree[10].col='G';
tab_entree[11].lig=9; tab_entree[11].lib=4; tab_entree[11].color='n'; tab_entree[11].col='F';
tab_entree[12].lig=9; tab_entree[12].lib=3; tab_entree[12].color='b'; tab_entree[12].col='J';
tab_entree[13].lig=8; tab_entree[13].lib=4; tab_entree[13].color='n'; tab_entree[13].col='E';
}
