/***************************************************************************************************************************************************
*Author		:Akshat
*Date		:Tue 1/9 /2026 14:48:05 IST
*File		:main.c
*Title		:Driver function
*Description	:This function acts like the driver function for the project inverted search
****************************************************************************************************************************************************/
#include "inverted_search.h"

int main(int argc, char *argv[])
{
    system("clear");
    
    if(argc<=1)
    {
        printf("Enter the valid no. of arguments \n");
        printf("./slist.exe file1.txt file2.txt ......\n");
        return 0;
    }
   Flist * f_head = NULL;

   file_validation_n_file_list(&f_head,argv);
   if( f_head == NULL)
   {
    printf("no file added to the linked list\n");
    printf("hence the process get terminated\n");
    return 1;
   }

   Wlist *head[27] = {NULL};
 

   int choice;
while(1)
{


   printf("Enter your choice\n1. create database\n2. Display database\n3. Search database\n4. update database\n5. save database\n6. Exit\n");
   scanf("%d",&choice);


   switch(choice)
   {


    case 1: create_database(f_head, head);
            break;

  
    case 2 : display_database(head);
             break;

    case 3 : printf("enter the word\n");
               char str[50];
               scanf("%s",str);
               int i ;
               i = tolower(str[0]%97);
               if(! (i >=0 &&  i<=25 ))
               {
                i = 26;
               }
               search(head[i], str,i);
               break;
           

    case 4 :update_database(head,&f_head);
              break;


    case 5 : save_database(head);
             break;
    


    case 6: printf("exit\n");
             return 0;


    default :
          printf("invalid input\n");
            return -1;

   }

              

}
}