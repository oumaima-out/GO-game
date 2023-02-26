#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

void tirage_sort_machine(int *pr_a) /*Determiner le joueur qui commencera la partie*/
{
    char Nom1[50]; /*tab du nom deux joueurs*/
    printf("\tEntrer votre nom:\n\n");
    scanf("%s",Nom1);
    srand(time(NULL)); /*initialiser le tirage*/
    if (rand()%2==0)
    {
        printf("\tLe joueur 1 est: %s",Nom1);
        printf("\n\tLe joueur 2 est: la machine\n");
    }
    else
    {
        *pr_a=1;
        printf("\tLe joueur 1 est: la machine");
        printf("\n\tLe joueur 2 est: %s \n\n\n\n",Nom1);
    }
}
