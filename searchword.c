#include "inverted_search.h"
void search (Wlist *head, char *word,int i)
{
    int flag =0;
    Wlist * temp = head;

    while(temp != NULL)
    {
       if(strcmp(temp->word, word)==0)
       {
        printf("word found at \n");
        printf("index\t\twords\t\tfilecount\t\tfilenames and wordcount\n");
printf("------------------------------------------------------------------------------------------------\n");
        printf("[%d]\t\t[%s]\t\t[%d]\t\t",i,temp->word, temp->file_count);
     Ltable *p = temp->Tlink;
    while(p !=NULL)
    {
        printf("[%s]\t[%d] ",p->file_name,p->word_count);
        p = p->table_link;
    }
    printf("\n");
    flag =1;
       }

       temp = temp->link;
    }


  if(flag ==0)
    printf("word not found\n");


}

