#ifndef __GEST_PERSON__
#define __GEST_PERSON__


#include "person.h"
#include "list_persons.h"

void manage_persons(FILE *fp, LIST_PERSONS* list_persons);

void insert_person(FILE *fp, LIST_PERSONS *list_persons, char opcao);
void update_person(FILE *fp, LIST_PERSONS *list_persons, char opcao);
void remove_person(FILE *fp, LIST_PERSONS *list_persons);
void undelete_person(FILE *fp, LIST_PERSONS *list_persons);

// VALIDAR
int import_persons(LIST_PERSONS* list_persons);
int show_persons(LIST_PERSONS *list_persons, char opcao);
int save_persons(FILE* fp, LIST_PERSONS* list_persons);
int save_person(FILE *fp, LIST_PERSONS *list_persons, PERSON *p, char operation);
int clean_list(LIST_PERSONS* list_persons);

int reset_file(FILE *fp);

int sort_persons(LIST_PERSONS* list_persons);
int search_person_sequencial(LIST_PERSONS* list_persons, char opcao);
int search_person_binary(LIST_PERSONS* list_persons, char opcao);

int comp_person_by_fname(const void*ptr1, const void* ptr2);

#endif // __GEST_PERSON__

