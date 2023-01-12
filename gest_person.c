#include <stdio.h>
#include <stdlib.h>

#include "includes/person.h"
#include "includes/list_persons.h"
#include "includes/gestdata.h"
#include "includes/gest_person.h"


static const char* menu_person[] = {
  "I - Inserir Pessoa",
  "A - Alterar Pessoa",
  "R - Remover Pessoa",
  "U - Recuperar pessoa (Undelete)",
  "",
  "M - Importar Pessoas",
  "L - Listar pessoas",
  "",
  "1 - Ordenar lista de pessoas",
  "2 - Pesquisar pessoa (pesquisa sequencial)",
  "3 - Pesquisar pessoa (pesquisa binaria)",
  "",
  "X - Sair",
  NULL
};



// Ecra de gestao de pessoas
void manage_persons(FILE *fp, LIST_PERSONS* list_persons){
  char opcao;

  while ((opcao = get_menu_option(menu_person))!=OP_EXIT)
    switch(opcao)
    {
      case OP_INSERT:      insert_person(fp, list_persons); break;
      case OP_UPDATE:      update_person(fp, list_persons); break;
      case OP_REMOVE:      remove_person(fp, list_persons); break;

      //case OP_IMPORTP:     import_persons(fp, list_persons); break;
      case OP_IMPORTP:     import_persons(list_persons); break;

      case OP_LIST:        wait("Listagens (Pessoas)"); break;

      case OP_EXIT:        wait("Opcao SAIR"); break;
    }

}

// https://stackoverflow.com/questions/33704362/spilitting-a-string-into-array-of-strings?noredirect=1&lq=1
// Divide uma string em várias por um separador
// Recolhe sub-strings em array
void tokenize(char* string, char *delimiter, char *arr[], int* count) {
    char *token;
    token = strtok (string, delimiter);
    int i = 0;
    while (token != NULL) {
        arr[i++] = token;
        token = strtok (NULL, delimiter);
    }
    *count = i;
}

// Read one contry in file.
// Return boolean
int read_person_from_txt_file(FILE*fp, PERSON *person) {
  //int n_fields = fscanf(fp, "%s %s %[^\n]s", person->f1, person->f2, person->f3);

    int id;
    char first_name[MAX_NAME_SIZE+1];
    char last_name[MAX_NAME_SIZE+1];
    //char full_name[MAX_NAME_SIZE+1];
    char address[MAX_ADDRESS_SIZE+1];
    char email[MAX_EMAIL_SIZE+1];
    //char birth_date[MAX_ADDRESS_SIZE+1];
    char gender[MAX_GENDER_SIZE+1];
    //char zip[MAX_ADDRESS_SIZE+1];
    char country_code[MAX_COUNTRY_CODE_SIZE+1];
    char dep[MAX_DEP_SIZE+1];

    int is_active;

    char string[500];
    //int n_fields = fscanf(fp, "%s", string);
    int n_fields = fgets(string, 500, fp);

    char *arr[100] = { NULL };
    int count = 0;
    tokenize(string, "\t", arr, &count);

    for ( int i = 0; i < count; i++ ) {
        if ( arr[i] != NULL ) {
            printf( "arr[%d] = %s\n", i, arr[i] );
        }
    }

  //int n_fields = fscanf(fp, "%[^\n]s", person->id);//
  //426	Constantin	Gowdridge	2, Old Gate Point	cgowdridge0@chicagotribune.com	1994-02-02	Male	28400	CN	Finance	1
  /*int n_fields = fscanf(fp, "%d %s %s %s %s %s %s %s %s %[^\n]d", id, first_name, last_name, address, email, gender, country_code, dep, is_active);

  char info[MAX_STRING];
  sprintf(info, "| %s | %s | %s | %s | %s | %s | Prima <ENTER>...\n", aux1, aux2, aux3, aux4, aux5, aux6);
  wait(info);*/
  return 0;//(n_fields == 3); // Sucesso se foram lidos 3 campos
}

// IMPORTAR
//void import_persons(FILE *fp, LIST_PERSONS *list_persons) {
void import_persons() {
  LIST_PERSONS list_persons;
  list_persons.count = 0;   // Nao ha pessoas na lista
  char aux[MAX_STRING];

  wait("Importar o ficheiro csv com as pessoas. Prima <ENTER>...\n");
  // Importar os dados do ficheiro para a lista de countries
  FILE *fp;         // Ficheiro para importar os dados.
  //sprintf(aux, "%s/%s", "datasets", "all-persons.csv");
  sprintf(aux, "%s/%s", "datasets", "persons.csv");



  if ((fp=fopen(aux, "rt"))==NULL)
  {
    wait("Problemas na abertura do ficheiro de pessoas.");
    return;
  }

  while (read_person_from_txt_file(fp, &list_persons.person[list_persons.count])) // Enquanto conseguir ler um registo
  {
    printf("Ler registo de ficheiro de texto #%d\n", ++list_persons.count);
  }
  char info[MAX_STRING];
  sprintf(info, "%d. Prima <ENTER>...\n", list_persons.count);
  wait(info);

  fclose(fp);

}

// INSERIR Processa um novo registo de pessoa
void insert_person(FILE *fp, LIST_PERSONS *list_persons) {

  // TODO /PS/ INSERIR Processa um novo registo de pessoa
}

// UPDATE Processa um novo registo de pessoa
void update_person(FILE *fp, LIST_PERSONS *list_persons) {

  int id = read_integer("Indique o Id a alterar: ", 100, 999);

  int index = list_persons_getIndex(list_persons, id);
  if (index==REC_NOT_FOUND)
  {
    wait("Nao existe um registo de pessoa com o indicado.");
    return;
  }

  // TODO // UPDATE Processa um novo registo de pessoa
}

// REMOVE Processa um novo registo de pessoa
void remove_person(FILE *fp, LIST_PERSONS *list_persons) {
  // TODO // REMOVE Processa um novo registo de pessoa
}

//
// Grava um registo de pessoa no ficheiro.
// O processamento difere caso a operacao seja uma insercao ou alteracao
// Devolve um valor boolean indicando se a operacao foi realizada com uscesso
//
int save_person(FILE *fp, LIST_PERSONS *list_persons, PERSON *p, char operation) {
  // Ver se a pessoa ji existe e obter o indice da sua posicao
  int index = list_persons_getIndex(list_persons, p->id);

  // TODO // Grava um registo de pessoa no ficheiro.

  return 1;
}

