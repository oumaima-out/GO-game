#include <stdio.h>
#include <stdlib.h>

int lib_point(int l,char c) /*determiner les deg de lib d'un pt*/
{
    int lib=4;
    if ((l==1)||(l==10))
    {
        lib=3;
        if ((c=='A')||(c=='J')) lib=2;
    }
    else if((c=='A')||(c=='J')) lib=3;
    return lib;
}

