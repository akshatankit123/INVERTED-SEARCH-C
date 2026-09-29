#include "inverted_search.h"
 void save_database( Wlist *head[])
{
   char fname[50]; 
   printf("enter the file name\n");
   scanf("%s",fname);
   FILE *fptr = fopen(fname,"w");
   if(fptr == NULL)
   {
    printf("file opening failed\n");
    return ;
   }
   fprintf(fptr,"index\t\twords\t\tfilecount\t\tfilenames and wordcount\n");
fprintf(fptr,"------------------------------------------------------------------------------------------------\n");
     
   for(int i=0;i<27;i++)
   {
    write_databasefile(head[i],fptr,i);
   }
   fclose(fptr);

}
void write_databasefile(Wlist*head,FILE *fptr, int i)
{
    Wlist *temp = head;


    while(temp != NULL)
    {
        fprintf(fptr, "[%d]\t\t[%s]\t\t[%d]\t\t", i, temp->word, temp->file_count);

        Ltable *t = temp->Tlink;

        while(t != NULL)
        {
            fprintf(fptr,"[%s]\t\t[%d]", t->file_name, t->word_count);
            t = t->table_link;
        }

        fprintf(fptr, " \n");

        temp = temp->link;
    }


}