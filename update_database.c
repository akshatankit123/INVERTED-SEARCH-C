#include "inverted_search.h"
 void update_database(Wlist **head, Flist **f_head)
{
    char file_name[FNAME_SIZE];
    printf("enter the new file name to update the data base\n");
    scanf("%s",file_name);
   int  empty = isFileEmpty(file_name);
	 if(empty == FILE_NOTAVAILABLE)
	 {
		printf("file : %s is not available\n",file_name);
		printf("Hence  we are not adding to the linked list\n");
		
	 }
	 else if(empty == FILE_EMPTY)
	 {
		printf("file : %s having no content\n",file_name);
		printf("Hence  we are not adding to the linked list\n");
	
	 }
	 else if(empty == FAILURE)
	 {
       printf("failed to cheak the file\n");
	  
	 }
	 else
	 {
      int ret_val =   to_create_list_of_files(f_head,file_name);
	  if(ret_val == SUCCESS)
	  {
		
	   
		printf("Successfully inserted the file %s int the linked list\n",file_name);
		Flist *temp = *f_head;
      while(temp->link != NULL)
	  {
		temp = temp->link;
	  }
	  create_database(temp,head);
	  }
	 else if(ret_val == REPEATATION)
	  {
		printf("insertion failed due %s file is repeated\n",file_name);
	  }
	  else
	  {
       printf("failure\n");
	  }

	
	 }
   }
