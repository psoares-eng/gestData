#include <stdio.h>
#include "includes/list_persons.h"

// Inicializa uma lista de pessoas
void list_persons_inic(LIST_PERSONS *list) {
  list->count=0;
}

// Verifica se a lista de pessoas esta cheia
int list_persons_isFull(LIST_PERSONS *list) {
    // VALIDAR // TODO // Verifica se a lista de pessoas esta cheia
    return (list->count==MAX_PERSONS);
}

// Verifica se a lista de pessoas esta vazia
int list_persons_isEmpty(LIST_PERSONS *list) {
  // VALIDAR // TODO // Verifica se a lista de pessoas esta vazia
  return (list->count==0);
}

// Adiciona uma nova pessoa a lista, caso ainda exista espaco disponivel.
// Caso contrario mostra um erro.
void list_persons_add(LIST_PERSONS *list, PERSON *record) {
    // VALIDAR // TODO // Adiciona uma nova pessoa a lista, caso ainda exista espaco disponivel.

    list->person[list->count].id = record->id;
    //printf( "\n ID %d\n", list->count );
    //wait("//// TODO list_persons_add //// Prima <ENTER> para continuar...\n");
    strcpy( list->person[list->count].first_name, record->first_name );
    strcpy( list->person[list->count].last_name, record->last_name );

        // VALIDAR // junta o nome com o apelido
        /*char full_name[MAX_FULLNAME_SIZE+1];
        sprintf(full_name, "%s %s", record->first_name, record->last_name);
        strcpy(list->person[list->count].full_name, full_name);*/

    strcpy(list->person[list->count].address, record->address);
    strcpy(list->person[list->count].email, record->email);

        // TODO /PS/ usar campo timedate >> ver #include <time.h>
        //struct tm date;
        //memset(&date, 0, sizeof(struct tm));
        //strptime( campo[5], "%Y-%m-%d", &date );

        //strcpy( list->person[list->count].birth_date, record->birth_date );

    strcpy( list->person[list->count].gender, record->gender );
        //strcpy( list->person[list->count].zip, record->zip );
    strcpy( list->person[list->count].country_code, record->country_code );
    strcpy (list->person[list->count].dep, record->dep );
    list->person[list->count].is_active = record->is_active;


    list->count++;
}

// Devolve a posicao onde se encontra o id
// no array de pessoas ou REC_NOT_FOUND, caso nao exista.
int list_persons_getIndex(LIST_PERSONS *list, int id) {

    // VALIDAR // TODO // Devolve a posicao onde se encontra o id
    for (int i = 0; i < list->count; i++) {
        if( list->person[i].id == id ) {
            return i;
        }
    }
    return REC_NOT_FOUND;
}

// Carrega a lista de pessoas a partir do ficheiro fp que se assume aberto e
// posicionado algures
void list_persons_loadFromFile(FILE *fp, LIST_PERSONS *list) {

  // TODO // Carrega a lista de pessoas a partir do ficheiro
}
