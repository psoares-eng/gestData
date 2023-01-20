#ifndef __GESTDATA_H__
#define __GEST_DATA_H__


#define DIR_DATA "data"
#define DATA_FILE_PERSON "person.dat"
#define DATA_FILE_COUNTRY "country.dat"

// Dimensao das strings de uso generico
#define MAX_STRING             1024
#define MAX_LINE               2048

// Opcoes dos menus
// Main menu
#define OP_PERSONS   'p'
#define OP_COUNTRIES 'n'

#define OP_IMPORT    'c'
#define OP_DUMP      'd'
#define OP_ZAP       'z'

#define OP_RESET     'r'

#define OP_EXIT      'x'

// Menu pessoas
#define OP_INSERT   'i'
#define OP_UPDATE   'm'
#define OP_REMOVE   'r'
#define OP_UNDELETE 'u'

// VALIDAR
#define OP_LIST      'l'
#define OP_LIST_ALL  't'
//#define OP_SAVE      'g'
#define OP_CLEANLIST 'e'

#define OP_SORT         '1'
#define OP_SEARCH_SEQ   '2'
#define OP_SEARCH_BIN   '3'


void reset(FILE *fp);
FILE *open_data_file(const char*path, const char*filename);
int check_command_line(int argc, char **argv);
void manage_countries();

#endif
