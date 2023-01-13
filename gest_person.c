#include <stdio.h>
#include <stdlib.h>

// VALIDAR
#include <string.h>
#include <stdlib.h>
#include <time.h>

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

      // VALIDAR // Menu importar dados pessoas csv
      // Menus: a > m
      case OP_IMPORTP:     import_persons(list_persons); break;
      //case OP_IMPORTP:     import_persons(fp, list_persons); break;

      //case OP_LIST:        wait("Listagens (Pessoas)"); break;
      case OP_LIST:        show_persons(list_persons); break;

      case OP_EXIT:        wait("Opcao SAIR"); break;
    }
}

// VALIDAR // Read one person in file
// Return boolean
// REF read_country_from_txt_file()
int read_person_from_txt_file(FILE *fp, PERSON *person) {
    char string[500]; // VALIDAR valor
    int n_fields = fgets(string, 500, fp);
    char *campo[100] = { NULL }; // VALIDAR valor
    int count = 0;

    if( n_fields!=0 ){ // VALIDAR // Verificar se n_fields não null
        //printf("\nFIELDS #%d\n", (n_fields));

        strreplace(string, "\t\t", "\tNULL\t"); // substitui NULL por "NULL"
        tokenize(string, "\t", campo, &count);

        person->id = atoi(campo[0]); // VALIDAR uso de atoi
        strcpy( person->first_name, campo[1] );
        strcpy( person->last_name, campo[2] );
            // VALIDAR // junta o nome com o apelido
            char full_name[MAX_FULLNAME_SIZE];
            sprintf(full_name, "%s %s", campo[1], campo[2]);
            strcpy(person->full_name, full_name);
        strcpy(person->address, campo[3]);
        strcpy(person->email, campo[4]);
            // TODO /PS/ usar campo timedate >> ver #include <time.h>
            //struct tm date;
            //memset(&date, 0, sizeof(struct tm));
            //strptime( campo[5], "%Y-%m-%d", &date );
            strcpy( person->birth_date, campo[5] );
        strcpy( person->gender, campo[6] );
          strcpy( person->zip, campo[7] );
        strcpy( person->country_code, campo[8] );
        strcpy (person->dep, campo[9] );
        person->is_active = atoi(campo[10]);
    }
    return (count == 11);// Sucesso se foram lidos 11 campos
}

// VALIDAR // IMPORTAR
int import_persons(LIST_PERSONS* list_persons) {
    //LIST_PERSONS list_persons;
    //list_persons.count = 0;   // Nao ha pessoas na lista

    // Importar os dados do ficheiro para a lista de countries
    FILE *fp;         // Ficheiro para importar os dados.

    char info[MAX_STRING];
    char filepath[MAX_STRING];
    //sprintf(filepath, "%s/%s", "datasets", "all-persons.csv");
    // Remover cabecalhos do ficheiro e campos para simplificar a importacao
    sprintf(filepath, "%s/%s", "datasets", "persons.csv");
    sprintf(info, "\nImportar o ficheiro \"%s\" com as pessoas. Prima <ENTER>...\n", filepath);
    wait(info);

    if ((fp=fopen(filepath, "rt"))==NULL)
    {
        wait("Problemas na abertura do ficheiro de pessoas.");
        return 1;
    }

    //int pid = 0;
    while (read_person_from_txt_file(fp, &list_persons->person[list_persons->count])) // Enquanto conseguir ler um registo
    {
        /*
        // REMOVER
        pid = list_persons->count;
        printf("\nLer registo de ficheiro de texto #%d\n", pid+1);
        printf("(%d)\n", list_persons->person[pid].id);
        printf("        Name   : %s\n", list_persons->person[pid].first_name);
        printf("        L  Name: %s\n", list_persons->person[pid].last_name);
        printf("        F  Name: %s\n", list_persons->person[pid].full_name);
        printf("        Address: %s\n", list_persons->person[pid].address);
        printf("        Email  : %s\n", list_persons->person[pid].email);
        printf("        Birth  : %s\n", list_persons->person[pid].birth_date);
        printf("        Gender : %s\n", list_persons->person[pid].gender);
        printf("        ZIP    : %s\n", list_persons->person[pid].zip);
        printf("        Country: %s\n", list_persons->person[pid].country_code);
        printf("        Depart.: %s\n", list_persons->person[pid].dep);
        printf("        Active : %d\n", list_persons->person[pid].is_active);
        */
        ++list_persons->count;
    }

    // VALIDAR // REMOVER // PAUSAR PARA VERIFICACAO DOS DADOS APENAS
    //sprintf(info, "\nTotal de registos csv = %d.\n", pid);
    printf("\nTotal de registos csv = %d.\n", list_persons->count);
    wait("Prima <ENTER> para continuar...\n");

    fclose(fp);
    return(0);
}

// VALIDAR // Listar Pessoas
// Exibir resultados de melhor forma
int show_persons(LIST_PERSONS *list_persons) {
    for (int i = 0; i < list_persons->count; i++) {
        printf("(%d)\n", list_persons->person[i].id);
        printf("        Name   : %s\n", list_persons->person[i].first_name);
        printf("        L  Name: %s\n", list_persons->person[i].last_name);
        printf("        F  Name: %s\n", list_persons->person[i].full_name);
        printf("        Address: %s\n", list_persons->person[i].address);
        printf("        Email  : %s\n", list_persons->person[i].email);
        printf("        Birth  : %s\n", list_persons->person[i].birth_date);
        printf("        Gender : %s\n", list_persons->person[i].gender);
        printf("        ZIP    : %s\n", list_persons->person[i].zip);
        printf("        Country: %s\n", list_persons->person[i].country_code);
        printf("        Depart.: %s\n", list_persons->person[i].dep);
        printf("        Active : %d\n", list_persons->person[i].is_active);
    }
    printf("\nExistem %d pessoas em memoria\n", list_persons->count);
    wait("Prima <ENTER>...\n");
    return(0);
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

