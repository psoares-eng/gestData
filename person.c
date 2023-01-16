#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

#include "includes/person.h"
#include "includes/gestdata.h"

// Ler o registo de uma pessoa a partir do ecra
// operation = 'I' (new record) 'U' (update record)

void read_person(PERSON *p, char operation) {

   if (operation==OP_INSERT) // nunca se altera um id
     p->id = read_integer("Id         : ", 100, 999);

   // TODO // Ler o registo de uma pessoa a partir do ecra

   p->is_active = 1;  // Por defeito o registo fica ativo (true)
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
    // "Activo ID  Primeiro Nome\t\tApelido\t\tNome Completo\t\tMorada\t\tEmail\t\tNascimento\t\tGenero\t\tCódigo Postal\t\tPaís\t\tDepartmento\n\n"
    //printf("%d %d  %s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n",
    printf("%d %d  %s\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n",
           p->is_active, p->id, p->first_name, p->last_name,
           /*p->full_name, */p->address, /*p->email, */p->birth_date,
           p->gender, p->zip, p->country_code, p->dep);
}
