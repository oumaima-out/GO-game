#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef struct point /*le type des élts de tableau des points entrés*/
{
    int lig,lib;
    char color,col;
} pt;

void test_KO(pt tab_capture[100],int *pr_tail_cap,pt tab_entree[100],int tour,int *pr_test)
{
    if ((tab_capture[*pr_tail_cap-1].lig==tab_capture[*pr_tail_cap-2].lig) && ( (tab_capture[*pr_tail_cap-1].col==(tab_capture[*pr_tail_cap-2].col)+1) || (tab_capture[*pr_tail_cap-1].col==(tab_capture[*pr_tail_cap-2].col)-1)) && (tab_capture[*pr_tail_cap-1].color!=tab_capture[*pr_tail_cap-2].color))
    {
        if (tab_entree[tour-1].lig==-1)
        {
            if ((tab_entree[tour-1].col==tab_capture[*pr_tail_cap-1].col) || (tab_entree[tour-1].col==tab_capture[*pr_tail_cap-2].col)) goto tst;
        }
        if (((tab_entree[tour-1].lig!=tab_capture[*pr_tail_cap-1].lig) || (tab_entree[tour-1].col!=tab_capture[*pr_tail_cap-1].col)) && ((tab_entree[tour-1].lig!=tab_capture[*pr_tail_cap-2].lig) || (tab_entree[tour-1].col!=tab_capture[*pr_tail_cap-2].col) ))
        {
            tab_capture[*pr_tail_cap-2].lig=0;
            *pr_test=0;
        }
        else
        {
tst:
            tab_entree[tour-1]=tab_capture[*pr_tail_cap-1];
            tab_entree[tour].lig=-1;
            *pr_tail_cap=*pr_tail_cap-1;
            *pr_test=1;

        }
    }


    if (( (tab_capture[*pr_tail_cap-1].lig==(tab_capture[*pr_tail_cap-2].lig)+1) || (tab_capture[*pr_tail_cap-1].lig==(tab_capture[*pr_tail_cap-2].lig)-1)) && (tab_capture[*pr_tail_cap-1].col==tab_capture[*pr_tail_cap-2].col) && (tab_capture[*pr_tail_cap-1].color!=tab_capture[*pr_tail_cap-2].color))
    {
        if (tab_entree[tour-1].lig==-1)
            {
                if ((tab_entree[tour-1].col==tab_capture[*pr_tail_cap-1].col) || (tab_entree[tour-1].col==tab_capture[*pr_tail_cap-2].col)) goto tst;
            }
        if (((tab_entree[tour-1].lig!=tab_capture[*pr_tail_cap-1].lig) || (tab_entree[tour-1].col!=tab_capture[*pr_tail_cap-1].col)) && ((tab_entree[tour-1].lig!=tab_capture[*pr_tail_cap-2].lig) || (tab_entree[tour-1].col!=tab_capture[*pr_tail_cap-2].col) ))
        {
            tab_capture[*pr_tail_cap-2].lig=0;
            *pr_test=0;
        }
        else
        {
            tab_entree[tour-1]=tab_capture[*pr_tail_cap-1];
            tab_entree[tour].lig=-1;
            *pr_tail_cap=*pr_tail_cap-1;
            *pr_test=1;
        }
    }

}
