#include "inverted_search.h"
void display_database( Wlist *head[] )
{
printf("index\t\t8words\t\tfilecount\t\tfilenames and wordcount\n");
printf("------------------------------------------------------------------------------------------------\n");
    for(int i =0;i<27;i++)
    {


        if(head[i] != NULL)
        {

         print_word_count(head[i]);

        }
    }




}
int print_word_count(Wlist *head)
{
 //traverse through the nodes
 
  int  i = tolower(head->word[0]%97);
  if(!( i>=0  && i<=25))
  {
    i = 26;
  }
   while(head != NULL)
   {
    printf("[%d]\t\t[%s]\t\t[%d]\t\t",i,head->word, head->file_count);
     Ltable *temp = head->Tlink;
    while(temp !=NULL)
    {
        printf("[%s]\t[%d] ",temp->file_name,temp->word_count);
        temp = temp->table_link;
    }
    printf("\n");
    head = head->link;

   }
   return SUCCESS;
}