#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "includes/utils.h"

// VALIDAR
#include <stdbool.h>


static int days_of_month[] = {0,31,28,31,30,31,30,31,31,30,31,30,31}; // posicao igual ao n. do mes

// Limpa o ecra
void cls() {

#ifdef  _WIN32
  system("cls");
#else // linux
  system("clear");
#endif
}


// Mostra uma string e aguarda que o utilizador prima ENTER para a aplicacao continuar
// 'E mostrada a string enviada 'a  funcao ou a string por defeito, caso se envie NULL
void wait(const char*caption) {
  char *alt = "\nPrima <ENTER> para continuar . . .";

  if (caption==NULL || caption[0]=='\0')
    caption = alt;

  do {
    fflush(stdin);
    printf("%s", caption);
  }
  while (getchar()!='\n');
}

// Verifica se um ficheiro existe
int file_exists(const char*filename) {
  FILE *fp = fopen(filename, "rb");
  int exist_file = (fp!=NULL);
  if (fp!=NULL) fclose(fp);
  return exist_file;
}

// Le um inteiro entre dois valores (limites incluidos)
int read_integer(const char*prompt, int min, int max){
  int value;
  do {
    fflush(stdin);
    printf("%s", prompt);
    scanf("%d", &value);
  }
  while(value<min || value>max);
  return value;
}

// Le uma string com um tamanho minimo e maximo
char* read_string(const char*prompt, char*s, int min_len, int max_len){
    // TODO // Le uma string com dimensao minima
    do {
        fflush(stdin);
        printf("%s", prompt);
        scanf("%s", s);
        //wait("//// TODO read_person //// Prima <ENTER> para continuar...\n");
    }
    while(strlen(s)<min_len || strlen(s)>max_len);
    return NULL;
}

// Verifica se um ano é bissexto
int isLeapYear(int year)
{
        if(year%4==0)
        if(year%100!=0)
            return 1;
        else
            if(year%400==0)
                return 1;
            else
                return 0;
    else
        return 0;
  // TODO // Verifica se um ano é bissexto // DA // VALIDAR
  // DA // VALIDAR
  // https://www.mathsisfun.com/leap-years.html
}

// Verifica se uma data é valida
int isDate(DATE date) {
  // TODO // Verifica se uma data é valida
  bool year_valid = (date.year >= 1900 && date.year <= 2100);
  bool leap = isLeapYear(date.year);
  bool month_valid = (date.month >= 1 && date.month <= 12);
  bool day_valid = (date.day >= 1 && (date.day <= days_of_month[date.month] || (leap && date.day == 29) ) );

  if ( year_valid && month_valid && day_valid )
    return 1;
  else
    return 0;
}

// Adiciona um dia 'a data enviada por parametro
void date_addOneDay(DATE *date)
{
  // TODO // Adiciona um dia 'a data enviada por parametro
  date->day = date->day + 1;
}

// Adiciona n_dias 'a data enviada por parametro
void date_add(DATE *date, int n_days)
{
  // TODO // Adiciona n_dias 'a data enviada por parametro
  date->day = date->day + n_days;
}


// Le e retorna uma data no formato yyyy-mm-dd. Caso a data seja invalida mostra um
// erro e volta a pedir, até que uma data valida seja introduzida.
DATE read_date(const char* prompt) {
  DATE date;
  // TODO // Le e retorna uma data no formato yyyy-mm-dd

  return date;
}

// Solicita a confirmacao de um pedido
int confirm(const char*prompt) {
  char answer;
  do {
    printf("%s (s/n)? : ", prompt);
    fflush(stdin);
    scanf(" %c", &answer);
    answer = tolower(answer);
  }
  while (answer!=ANSWER_YES && answer!=ANSWER_NO);

  return answer==ANSWER_YES;
}

// VALIDAR // Divide uma string em várias por um separador
// Recolhe sub-strings em array
//https://codebrowser.dev/glibc/glibc/string/strsep.c.html
// REQUIRES strsep()
int tokenize(char* str, char *delim, char *flds[]) {
  int i = 0;
  char* token;
  while( (token = strsep( &str, delim) ) != NULL ) {
    if( strlen(token) == 0 ) {
      token = "-----";
    }
    flds[i++] = token;
  }
  return i;
}

// Le e retorna uma data no formato yyyy-mm-dd. Caso a data seja invalida mostra um
// erro e volta a pedir, até que uma data valida seja introduzida.
void date_from_string(char *string, DATE *date) {
    //DATE date;
    sscanf(string, "%04d-%02d-%02d", &date->year, &date->month, &date->day);
    //strcpy(&date->str, string);
}

// https://stackoverflow.com/questions/33704362/spilitting-a-string-into-array-of-strings?noredirect=1&lq=1
// https://www.tutorialspoint.com/what-is-strtok-r-function-in-c-language
/*void tokenize(char* string, char *delimiter, char *arr[], int* count) {
    char *token;
    token = strtok(string, delimiter);
    int i = 0;
    while (token != NULL) {
        arr[i++] = token;
        token = strtok(NULL, delimiter);
    }
    *count = i;
}*/
