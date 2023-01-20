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
  "M - Modificar Pessoa",
  "R - Remover Pessoa",
  "U - Recuperar Pessoa (Undelete)",
  "",
  "L - Listar Pessoas          (novo)",
  "T - Listar Pessoas (Todas)  (novo)",
//  "G - Guardar Pessoas         (novo)",
  "E - Limpar lista de Pessoas (novo)",
  "",
  "1 - Ordenar lista de Pessoas",
  "2 - Pesquisar Pessoa (nome - pesquisa sequencial - C qsort)",
  "3 - Pesquisar Pessoa (nome - pesquisa binaria - C bsearch)",
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
      case OP_INSERT:      insert_person(fp, list_persons, opcao); break;
      case OP_UPDATE:      update_person(fp, list_persons, opcao); break;
      case OP_REMOVE:      remove_person(fp, list_persons); break;
      case OP_UNDELETE:    undelete_person(fp, list_persons); break;

      // VALIDAR // Menu importar dados pessoas csv
      case OP_LIST:        show_persons(list_persons, opcao); break;
      case OP_LIST_ALL:    show_persons(list_persons, opcao); break;
      //case OP_SAVE:        save_persons(fp, list_persons); break;
      case OP_CLEANLIST:   clean_list(list_persons); break;

      case OP_SORT:        sort_persons(list_persons); break;
      case OP_SEARCH_SEQ:  search_person_sequencial(list_persons, opcao); break;
      case OP_SEARCH_BIN:  search_person_binary(list_persons, opcao); break;

      case OP_EXIT:        wait("Opcao SAIR"); break;
    }
}

// VALIDAR // INSERIR Processa um novo registo de pessoa
void insert_person(FILE *fp, LIST_PERSONS *list_persons, char opcao) {
    // TODO /PS/ INSERIR Processa um novo registo de pessoa
    PERSON new_person;
    read_person(&new_person, opcao);
    show_person_horizontal(&new_person);

    //printf( "\n ID %d\n", list_persons->count );
    //wait("//// TODO insert_person //// Prima <ENTER> para continuar...\n");

    list_persons_add(list_persons, &new_person);

    //save_persons(fp, list_persons);
}

// UPDATE Actualiza registo de pessoa
void update_person(FILE *fp, LIST_PERSONS *list_persons, char opcao) {

    int id = read_integer("Indique o Id a alterar: ", 100, 999);

    int index = list_persons_getIndex(list_persons, id);
    if (index==REC_NOT_FOUND) {
        wait("Nao existe um registo de pessoa com o indicado.");
        return;
    }

    // VALIDAR // TODO // UPDATE Processa um novo registo de pessoa
    show_person_horizontal(&list_persons->person[index]);
    read_person(&list_persons->person[index], opcao);

    show_person_horizontal(&list_persons->person[index]);
    //wait("//// TODO update_person //// Prima <ENTER> para continuar...\n");
    //save_persons(fp, list_persons);
}

// VALIDAR // REMOVE registo de pessoa
void remove_person(FILE *fp, LIST_PERSONS *list_persons) {
    // VALIDAR // TODO // REMOVE Processa um novo registo de pessoa

    int id = read_integer("Indique o Id a remover: ", 100, 999);

    printf("\nAtenção esta operação irá apagar o registo\n");
    int do_remove = confirm("Tem a certeza?");

    if ( do_remove == 1 ) {
        int index = list_persons_getIndex(list_persons, id);
        if (index==REC_NOT_FOUND) {
            wait("Nao existe um registo de pessoa com o ID indicado.");
            return;
        }
        list_persons->person[index].is_active = 0;
        show_person_horizontal(&list_persons->person[index]);
        //wait("//// TODO remove_person //// Prima <ENTER> para continuar...\n");
        //save_persons(fp, list_persons);
    }
}

// RECUPERA registo de pessoa
void undelete_person(FILE *fp, LIST_PERSONS *list_persons) {

    int id = read_integer("Indique o Id a recuperar: ", 100, 999);

    int index = list_persons_getIndex(list_persons, id);
    if (index==REC_NOT_FOUND) {
        wait("Nao existe um registo de pessoa com o ID indicado.");
        return;
    }

    // VALIDAR // TODO // RECUPERA registo de pessoa
    list_persons->person[index].is_active = 1;
    show_person_horizontal(&list_persons->person[index]);

    //wait("//// TODO undelete_person //// Prima <ENTER> para continuar...\n");
    //save_persons(fp, list_persons);
}

// Grava um registo de pessoa no ficheiro.
// O processamento difere caso a operacao seja uma insercao ou alteracao
// Devolve um valor boolean indicando se a operacao foi realizada com uscesso
int save_person(FILE *fp, LIST_PERSONS *list_persons, PERSON *p, char operation) {
  // Ver se a pessoa ji existe e obter o indice da sua posicao
  int index = list_persons_getIndex(list_persons, p->id);

  // TODO // Grava um registo de pessoa no ficheiro.
  wait("//// TODO save_person //// Prima <ENTER> para continuar...\n");

  return 1;
}

// VALIDAR // Read one person in file
// Return boolean
// REF read_country_from_txt_file()
int read_person_from_txt_file(FILE *fp, PERSON *person) {
    char line[MAX_LINE];
    char *n_fields = fgets(line, MAX_LINE, fp);
    char *campo[MAX_ADDRESS_SIZE] = { NULL };

    // Saltar linhas comentário ou vazias
    while ((line[0] == '#') || (line[0] == ' ') || (line[0] == '\n') || (line[0] == 'i') ) {
        //printf("\nline %c\n", line[0] );
        //wait("Prima <ENTER> para continuar...\n");
        n_fields = fgets(line, MAX_LINE, fp);
    }

    int count = 0;
    if( n_fields != NULL ) { // VALIDAR // Verificar se n_fields não null
        count = tokenize(line, "\t", campo);//, &count);

        // MELHORAR // CODIGO REPETIDO

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
            //date_from_string(campo[5], person->birth_date);

        strcpy( person->gender, campo[6] );
          strcpy( person->zip, campo[7] );
        strcpy( person->country_code, campo[8] );
        strcpy (person->dep, campo[9] );
        person->is_active = atoi(campo[10]);
    }
    return (count == 11);// Sucesso se foram lidos 11 campos
}

// VALIDAR // Importar CSV
int import_persons(LIST_PERSONS* list_persons) {
    //LIST_PERSONS list_persons;
    //list_persons.count = 0;   // Nao ha pessoas na lista

    // Importar os dados do ficheiro para a lista de countries
    FILE* fp_csv;         // Ficheiro para importar os dados.

    char filepath[MAX_STRING];

    cls();
    sprintf( filepath, "%s/%s", "datasets", "all-persons.csv" );
    printf( "\nImportar o ficheiro \"%s\" com os registos\n", filepath );
    //wait("Prima <ENTER> para continuar...\n");

    if ( ( fp_csv = fopen( filepath, "rt" ) ) == NULL ) //freopen(fp);
    {
        wait("Problemas na abertura do ficheiro de pessoas.");
        return 1;
    }

    while ( read_person_from_txt_file( fp_csv, &list_persons->person[list_persons->count] ) ) // Enquanto conseguir ler um registo
    {
        ++list_persons->count;
    }

    // VALIDAR // REMOVER // PAUSAR PARA VERIFICACAO DOS DADOS APENAS
    printf("\nTotal de registos csv = %d.\n", list_persons->count);
    wait("Prima <ENTER> para continuar...\n");

    fclose( fp_csv );
    return(0);
}

// VALIDAR // Listar Pessoas
// Exibir resultados de melhor forma
int show_persons(LIST_PERSONS *list_persons, char opcao) {
    cls();
    printf("LISTA DE PESSOAS\n");
    printf("\nExistem %d pessoas em memoria\n\n", list_persons->count);
    printf("   A ID  Nome            APELIDO              Morada                     Nasc.     Genero CP     Departmento    \n\n");
    for (int i = 0; i < list_persons->count; i++) {
        if (opcao==OP_LIST && list_persons->person[i].is_active == 1) {
            show_person_horizontal(&list_persons->person[i]);
        }
        if (opcao==OP_LIST_ALL) {
            show_person_horizontal(&list_persons->person[i]);
        }
    }
    printf("\n\n");
    wait("Prima <ENTER>...\n");
    return 0;
}

// VALIDAR // Guardar Ficheiro
int save_persons(FILE* fp, LIST_PERSONS* list_persons) {
    int n_recs = fwrite(list_persons->person, sizeof(PERSON), (long) list_persons->count, fp);

    if (n_recs!=list_persons->count)
    {
        wait("Problemas na gravacao dos registos no ficheiro binario. Prima <ENTER>...");
        return 1;
    }
    else
    {
        fflush(fp); // just in case
        fclose(fp);
        printf("\nTotal de registos gravados com sucesso = %d.\n", n_recs);
        wait("Prima <ENTER> para continuar...\n");
    }
    return 0;
}

// VALIDAR // Limpar a lista de registos em memoria
int clean_list(LIST_PERSONS* list_persons) {
    puts("\n\nLimpar a lista de registos em memoria\n");
    list_persons->count=0; // Lista vazia
    wait("Prima <ENTER> para continuar...\n");
    return 0;
}

// VALIDAR // Apaga todos os dados
int reset_file(FILE *fp) {

    printf("\nAtenção esta operação irá apagar todos os dados\n");
    int do_reset = confirm("Tem a certeza?");

    //printf("%d\n", do_reset);
    //wait("Prima <ENTER> para continuar...\n");
    if ( do_reset == 1 ) {
        char fullpath[MAX_STRING];
        char erro[MAX_STRING+MAX_STRING];
        sprintf(fullpath, "%s/%s", DIR_DATA, DATA_FILE_PERSON); // Criar o caminho completo do ficheiro

        fp = fopen(fullpath, "wb");
        wait("Prima <ENTER> para continuar...\n");
    }
    return 0;
}

// VALIDAR // Ordenar Lista
int sort_persons(LIST_PERSONS* list_persons) {
    printf("\n\nOrdenar lista de pessoas pelo Nome\n");

    /*
    Não poderão usar a função qsort da biblioteca standard da linguagem C. No entanto poderão ver como esta função
    pode ser usada para ordenar um array (gestão de países).
    */
    qsort(list_persons->person, (long) list_persons->count, sizeof(PERSON), comp_person_by_fname);
    wait("Prima <ENTER> para continuar...\n");
    return 0;
}

int search_person_sequencial(LIST_PERSONS* list_persons, char opcao) {
    printf("\n\nProcura Sequencial em lista ordenada por nome de pessoa\n");
    PERSON pessoa = {0, "", "", "", "", "", "", "", "", "", 1};

    read_person(&pessoa, opcao);

    for (int i = 0; i < list_persons->count; i++) {
        if( !strcmp(list_persons->person[i].first_name, pessoa.first_name) && list_persons->person[i].is_active == 1 ) {
            show_person_horizontal(&list_persons->person[i]);
            wait("Prima <ENTER> para continuar...\n");
            return i;
        }
    }
    printf("NAO FOI ENCONTRADA com o nome %s\n\n", pessoa.first_name);
    wait("Prima <ENTER> para continuar...\n");
    return 0;
}

// VALIDAR // Procura Binaria em lista ordenada por nome de pessoa
int search_person_binary(LIST_PERSONS* list_persons, char opcao) {
    sort_persons(list_persons);

    printf("\n\nProcura Binaria em lista ordenada por nome de pessoa\n");
    PERSON pessoa = {0, "", "", "", "", "", "", "", "", "", 1};

    read_person(&pessoa, opcao);
    /*
    Não poderão usar a função bsearch da biblioteca standard da linguagem C. No entanto poderão ver como esta
    função pode ser usada para fazer a pesquisa de um país num array previamente ordenado (gestão de países).
    */
    PERSON *ptr = bsearch(&pessoa, list_persons->person, (long) list_persons->count, sizeof(PERSON), comp_person_by_fname);

    if (ptr!=NULL) {
        printf("Encontrada a pessoa %s\n\n", pessoa.first_name);
        show_person_horizontal(ptr);
    } else {
        printf("NAO FOI ENCONTRADA com o nome %s\n\n", pessoa.first_name);
    }
    wait("Prima <ENTER> para continuar...\n");
    return 0;
}

// VALIDAR // Comparar Nomes
int comp_person_by_fname(const void*ptr1, const void* ptr2) {
  PERSON *p1 = (PERSON *) ptr1;
  PERSON *p2 = (PERSON *) ptr2;

  // comparar primeiro nome
  return strcmp(p1->first_name, p2->first_name);
}
