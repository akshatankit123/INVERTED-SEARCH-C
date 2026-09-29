#include "inverted_search.h"

void file_validation_n_file_list(Flist **f_head, char *argv[] )
{
   int i =1;
   int empty;

   while(argv[i]!= NULL)
   {
	 empty = isFileEmpty(argv[i]);
	 if(empty == FILE_NOTAVAILABLE)
	 {
		printf("file : %s is not available\n",argv[i]);
		printf("Hence  we are not adding to the linked list\n");
		i++;
		continue;
	 }
	 else if(empty == FILE_EMPTY)
	 {
		printf("file : %s having no content\n",argv[i]);
		printf("Hence  we are not adding to the linked list\n");
		i++;
		continue;
	 }
	 else if(empty == FAILURE)
	 {
       printf("failed to cheak the file\n");
	   i++;
	   continue;
	 }
	 else
	 {
      int ret_val =   to_create_list_of_files(f_head,argv[i]);
	  if(ret_val == SUCCESS)
	  {
		printf("Successfully inserted the file %s int the linked list\n",argv[i]);
	  }
	 else if(ret_val == REPEATATION)
	  {
		printf("insertion failed due %s file is repeated\n",argv[i]);
	  }
	  else
	  {
       printf("failure\n");
	  }
	  i++;
      continue;
	 }
   }
}	

int isFileEmpty(char *Filename)
{
  FILE *fptr = fopen(Filename, "r");
   if(fptr == NULL)
   {
	if(errno ==ENOENT)
	{
		return FILE_NOTAVAILABLE;
	
   }
   else
   {
	return FAILURE;
   }
}
   fseek(fptr,0,SEEK_END);
   if(ftell(fptr) == 0)
   {
	fclose(fptr);
	return FILE_EMPTY;
   }
   fclose(fptr);
   return SUCCESS;
}

int to_create_list_of_files(Flist **f_head, char *name)
   {
		Flist *temp = *f_head;
   

		while(temp != NULL)
		{
           if(strcmp(temp->file_name,name) == 0)
		   {
			 return REPEATATION;
		   }

		   temp = temp->link;


		}
	   Flist *new = malloc(sizeof(Flist));

	   if(new == NULL)
	   {
           return FAILURE;
	   }
	     
		 new->link = NULL;
		 new->word_count =0;

		 strcpy(new->file_name,name);



        if(*f_head == NULL)
		{
			*f_head = new;
			return SUCCESS;
		}
		 
	
       temp = *f_head;
		while(temp->link != NULL)
		{
			temp = temp->link;
		}
		temp->link = new;
		return SUCCESS;
   }



