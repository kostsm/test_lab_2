#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include "common.h"
#include "text/text.h"

static void show_line(int index, std::string contents, int cursor, void *data);


void showunderscores(text txt)
{
    /* Применяем функцию show_line к каждой строке текста */
    process_forward(txt, show_line, NULL);
}


static void show_line(int index, std::string contents, int cursor, void *data)
{
    /* Декларируем неиспользуемые параметры */
    UNUSED(index);
    UNUSED(cursor);
    UNUSED(data);

    /*Выделяем память под копию текущей строки */
    char *contents_copy = (char *) malloc((MAXLINE + 1) * sizeof(char));

    /*Копируем текующую строку */
    strcpy(contents_copy, contents.c_str());

   int i=0;
    while (contents_copy[i]!='\0') {
        if (contents_copy[i]==' ')
            contents_copy[i]='_';
        i++;
    }

    /* Выводим копию строки на экран */
    printf("%s\n", contents_copy);
}
