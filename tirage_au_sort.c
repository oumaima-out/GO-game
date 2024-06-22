#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

void tirage_au_sort() /*Determiner le joueur qui commencera la partie*/
{
    char Nom1[50],Nom2[50]; /*tab du nom deux joueurs*/
    printf("\tEntrer vos noms:\n\n");
    scanf("%s%s",Nom1,Nom2);
    srand(time(NULL)); /*initialiser le tirage*/
    if (rand()%2==0)
    {
        printf("\tLe joueur 1 est: %s",Nom1);
        printf("\n\tLe joueur 2 est: %s \n",Nom2);
    }
    else
    {
        printf("\tLe joueur 1 est: %s",Nom2);
        printf("\n\tLe joueur 2 est: %s \n\n\n\n",Nom1);
    }
}
