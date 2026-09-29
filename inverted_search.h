
#ifndef INVERTED_SEARCH_H
#define INVERTED_SEARCH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include <errno.h>

#define FAILURE   -30
#define SUCCESS    40
#define FNAME_SIZE 300
#define WORD_SIZE 50
#define FILE_EMPTY -30
#define FILE_NOTAVAILABLE -10
#define REPEATATION -20
#define FILE_VALID -5

typedef char data_t;
typedef struct file_node
{
	data_t file_name[ FNAME_SIZE];
	int word_count;
	struct file_node *link;

}Flist;

typedef struct linkTable_node
{
	int word_count;
	data_t file_name[ FNAME_SIZE ];
	struct linkTable_node *table_link;
}Ltable;
typedef struct word_node
{
	int file_count;
	data_t word[ WORD_SIZE ];
	struct word_node *link;
	  Ltable *Tlink;
}Wlist;

void file_validation_n_file_list(Flist **f_head, char *argv[] );
int isFileEmpty(char *filename);
int to_create_list_of_files(Flist **f_head, char *name);

int print_list(Wlist *head);
void create_database(Flist *f_head, Wlist *head[]);
void read_datafile(Flist *file, Wlist *head[], char *filename);
int insert_at_last(Wlist **head,data_t *data);
int update_link_table(Wlist **head);
int update_word_count(Wlist **head, char *file_name);
int print_word_count(Wlist *head);
void search( Wlist *head, char *word,int i);
void display_database( Wlist *head[] );
void save_database( Wlist *head[]);
void write_databasefile(Wlist *head, FILE* databasefile,int i);
void update_database( Wlist *head[], Flist **f_head);
void insert_new_word_to_database(Wlist *head[], char *file_name, char *word);
char **extract_words_from_file(const char *file_name);

#endif
