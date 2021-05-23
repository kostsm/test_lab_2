#include <stdio.h>
#include <string.h>
#include "_text.h"

void mpweb(text txt)
{
    if (txt->lines==NULL)
    return;

    int first_word_length=0;
    int i, spaces;

    i=0;

    std::list<std::string>::iterator current=txt->cursor->line;

    while ((*current)[i]==' ')
        i++;

    spaces=i;

    while ((*current)[i]!=' '){
    first_word_length++;
    i++;
    }

    if (txt->cursor->position>(first_word_length+spaces)){

    i=txt->cursor->position;

    while ((*current)[i-1]!=' ')
       i--;

    while (((*current)[i-1]==' ')&&((*current)[i+1]!=' '))
    i--;
    txt->cursor->position=i;

    }

    return;
}
