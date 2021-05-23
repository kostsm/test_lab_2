#include <stdio.h>
#include <string.h>
#include "_text.h"

void rn(text txt){


    std::list<std::string>::iterator current = txt->cursor->line;
    std::list<std::string>::iterator last = txt->lines->end();
    last--;

    if (current != last){

    current++;

    txt->lines->erase(current);
    }
}
