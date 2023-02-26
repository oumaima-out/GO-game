#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
void Color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}

void color(int x)
{if(x==1)
    {Color(0,0);
    printf(" ");
    Color(0,14);}
if(x==2)
    {Color(15,15);
    printf(" ");
    Color(0,14);}

}
