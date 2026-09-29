#include "inverted_search.h"
char *fname ;
void create_database(Flist *f_head, Wlist **head)
{
    while(f_head)
    {
        read_datafile(f_head,head,f_head->file_name);
        f_head= f_head->link;

    }
}

void read_datafile(Flist *file, Wlist *head[], char *filename)
{
    fname = filename;
   
  FILE *fptr = fopen(filename,"r");
   char word[WORD_SIZE];
    while(fscanf(fptr, "%s",word)!= EOF)
    {
         int flag =1;
          int index = tolower(word[0]) % 97;
          if(!(index >= 0 && index <= 26 ))
          {
            index = 26;
         }
        
         if(head[index] != NULL)
         {
           Wlist *temp = head[index];

           while(temp != NULL)
           {
              if( strcmp(temp->word, word)== 0)
              {  
                 update_word_count(&temp,filename);
                 flag =0;

                 break;
              }
             temp = temp->link;

           }
         }
          
             if(flag == 1)
             {
          insert_at_last(&head[index],word);
             }
    }
}

int insert_at_last(Wlist **head, data_t* data)
{
    Wlist *new = malloc(sizeof(Wlist));


    if(new == NULL)
    {
        return FAILURE;
    }
    new->file_count =1;
    strcpy(new->word,data);
    new-> Tlink = NULL;
    new->link = NULL;
 
    //create function to create  itable node;
    update_link_table(&new);


     if (*head == NULL)
     {
           *head = new;
           return SUCCESS;
           
     }


     Wlist *temp = *head;

     while(temp->link != NULL)
     {
         temp = temp->link;
     }
     temp->link = new;
     return SUCCESS;
}
int update_word_count(Wlist **head, char *file_name)
{
Ltable *temp= (*head)->Tlink;
Ltable *p;

while(temp !=NULL)
{
    p = temp;
     
    if(strcmp(temp->file_name,file_name)==0)
    {
        temp->word_count++;
        return SUCCESS;
    }

    

    temp = temp->table_link;
}

Ltable *new = malloc(sizeof(Ltable));

if(new == NULL)
{
    return FAILURE;
}

new->word_count=1;
strcpy(new->file_name,file_name);
new->table_link =NULL;
p->table_link = new;
(*head)->file_count++;
return SUCCESS;
 
}

