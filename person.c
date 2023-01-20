#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

#include "includes/person.h"
#include "includes/gestdata.h"

// Ler o registo de uma pessoa a partir do ecra
// operation = 'I' (new record) 'U' (update record)

void read_person(PERSON *p, char opcao) {
    // VALIDAR // TODO // Ler o registo de uma pessoa a partir do ecra
    if (opcao==OP_INSERT) {// nunca se altera um id
        p->id = read_integer("Id               : ", 100, 999);
        read_string("Primeiro Nome (*): ", p->first_name, 1, MAX_NAME_SIZE);
        read_string("Apelido       (*): ", p->last_name, 1, MAX_NAME_SIZE);
        //read_string("Nome             : ", p->last_name, 1, MAX_FULLNAME_SIZE);
        read_string("Morada           : ", p->address, 0, MAX_ADDRESS_SIZE);
        read_string("Email            : ", p->email, 0, MAX_EMAIL_SIZE);
        //read_string("Nasc. aaaa-mm-dd : ", p->email, 0, MAX_BIRTH_DATE);
        read_string("Género           : ", p->gender, 0, MAX_GENDER_SIZE);
        //read_string("Código Postal    : ", p->gender, 0, MAX_ZIP);
        read_string("CP          (XX) : ", p->country_code, 0, MAX_COUNTRY_CODE_SIZE);
        read_string("Departamento     : ", p->dep, 0, MAX_NAME_SIZE);
        p->is_active = 1;  // Por defeito o registo fica ativo (true)
    }

    if (opcao==OP_UPDATE) {// nunca se altera um id
        //p->id = read_integer("Id               : ", 100, 999);
        read_string("Primeiro Nome (*): ", p->first_name, 1, MAX_NAME_SIZE);
        read_string("Apelido       (*): ", p->last_name, 1, MAX_NAME_SIZE);
        //read_string("Nome             : ", p->last_name, 1, MAX_FULLNAME_SIZE);
        read_string("Morada           : ", p->address, 0, MAX_ADDRESS_SIZE);
        read_string("Email            : ", p->email, 0, MAX_EMAIL_SIZE);
        //read_string("Nasc. aaaa-mm-dd : ", p->email, 0, MAX_BIRTH_DATE);
        read_string("Género           : ", p->gender, 0, MAX_GENDER_SIZE);
        //read_string("Código Postal    : ", p->gender, 0, MAX_ZIP);
        read_string("CP          (XX) : ", p->country_code, 0, MAX_COUNTRY_CODE_SIZE);
        read_string("Departamento     : ", p->dep, 0, MAX_NAME_SIZE);
        p->is_active = 1;  // Por defeito o registo fica ativo (true)
    }

    if (opcao==OP_SEARCH_SEQ) {// nunca se altera um id
        read_string("Primeiro Nome (*): ", p->first_name, 1, MAX_NAME_SIZE);
    }

    if (opcao==OP_SEARCH_BIN) {// nunca se altera um id
        read_string("Primeiro Nome (*): ", p->first_name, 1, MAX_NAME_SIZE);
    }
}

// Exibe Vertical pessoa o registo de uma pessoa a partir do ecra
void show_person_vertical(PERSON *p){
    // VALIDAR // TODO // Exibe Vertical pessoa o registo de uma pessoa a partir do ecra
    printf("        ID     : %d\n", p->id);
    printf("        Name   : %s\n", p->first_name);
    printf("        L  Name: %s\n", p->last_name);
    printf("        F  Name: %s\n", p->full_name);
    printf("        Address: %s\n", p->address);
    printf("        Email  : %s\n", p->email);
    printf("        Birth  : %s\n", p->birth_date);
    printf("        Gender : %s\n", p->gender);
    printf("        ZIP    : %s\n", p->zip);
    printf("        Country: %s\n", p->country_code);
    printf("        Depart.: %s\n", p->dep);
    printf("        Active : %d\n", p->is_active);
}

// Exibe Horizontal pessoa o registo de uma pessoa a partir do ecra
void show_person_horizontal(PERSON *p){
    // VALIDAR // TODO // Exibe Horizontal pessoa o registo de uma pessoa a partir do ecra
    //printf("%1d %3d %10s %10s %20s %20s %20s %9s %6s %6s %2s %10s\n",
    //string_from_date(p->birth_date, date);
    printf("   %1d %3d %15s %20s %25s %10s %6s %6s %15s\n",
           p->is_active, p->id, p->first_name, p->last_name,
           /*p->full_name,  */p->address, /*p->email, */p->birth_date,
           p->gender, p->zip, /*p->country_code, */p->dep);
}
