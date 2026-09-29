#include "inverted_search.h"
extern char *fname;
int update_link_table(Wlist **head)
{
    Ltable *new = malloc(sizeof(Ltable));

    if(new == NULL)
    {
        return FAILURE;
    }

    new->word_count =1;
    strcpy(new->file_name,fname);
    new->table_link = NULL;

   (*head)->Tlink = new;
   return SUCCESS;
}

