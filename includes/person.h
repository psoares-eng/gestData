#ifndef __PERSON_H__
#define __PERSON_H__

#include "utils.h"

#define MAX_NAME_SIZE           50
    #define MAX_FULLNAME_SIZE      100
#define MAX_ADDRESS_SIZE       100
#define MAX_EMAIL_SIZE          50
    #define MAX_BIRTH_DATE          10

#define MAX_GENDER_SIZE         10
    #define MAX_ZIP                 10
#define MAX_COUNTRY_CODE_SIZE    2
#define MAX_DEP_SIZE            50


// define STRUCT PERSON
typedef struct
{
    // TODO /PS/ finish define STRUCT PERSON

    int id;
    char first_name[MAX_NAME_SIZE+1];
    char last_name[MAX_NAME_SIZE+1];
    //char full_name[MAX_NAME_SIZE+1];
    char address[MAX_ADDRESS_SIZE+1];
    char email[MAX_EMAIL_SIZE+1];
    //char birth_date[MAX_BIRTH_DATE+1];
    char gender[MAX_GENDER_SIZE+1];
    //char zip[MAX_ZIP+1];
    char country_code[MAX_COUNTRY_CODE_SIZE+1];
    char dep[MAX_DEP_SIZE+1];

    int is_active;
} PERSON;


void read_person(PERSON *p, char operation);
void show_person_vertical(PERSON *p);
void show_person_horizontal(PERSON *p);

#endif // __PERSON_H__
