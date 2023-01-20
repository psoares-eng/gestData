#include <stdio.h>
#include <locale.h>

#include "includes/utils.h"
#include "includes/gestdata.h"
#include "includes/gest_person.h"
#include "includes/menus.h"

static const char *menu_main[] = {
                      "P - Gestao de pessoas",
                      "N - Gestao de paises",
                      "",
                      "C - Importar dados - .CSV",
                      "",
                      "D - \"Dump\"   - Reescrever todos os dados",
                      "Z - \"Zap\"    - Compactar dados (remover apagados)",
                      "",
                      "R - \"Reset\"  - ATENCAO: Apagar todos os dados!!!",
                      "",
                      "X - Sair",
                      NULL
};

//
FILE *open_data_file(const char *folder, const char*filename) {
  FILE *fp;
  char fullpath[MAX_STRING];
  char erro[MAX_STRING+MAX_STRING];
  sprintf(fullpath, "%s/%s", folder, filename); // Criar o caminho completo do ficheiro

  if (!file_exists(fullpath)) // Ficheiro de dados nao existe. Vamos criar!!!
  {
    if ((fp=fopen(fullpath,"wb"))==NULL) {
        sprintf(erro, "Impossivel criar o ficheiro [%s]\n", fullpath);
        wait(erro);
        return NULL;
     }
    else
       return fp;
  }


  // Tentar abrir o ficheiro (que ja existe)
  if ((fp=fopen(fullpath,"r+b"))==NULL) {
        sprintf(erro, "Impossivel abrir o ficheiro [%s]\n", fullpath);
        wait(erro);
        return NULL;
     }
  return fp;
}

int main() {
  int opcao;
  FILE *fp_data;
  LIST_PERSONS list_persons;
  list_persons_inic(&list_persons); // Nao ha pessoas na lista

  setlocale(LC_ALL,"");

  if ((fp_data = open_data_file(DIR_DATA, DATA_FILE_PERSON))==NULL)      // Abrir o ficheiro de dados
    return 1;

  while ((opcao = get_menu_option(menu_main))!=OP_EXIT)
  {
    switch(opcao)
    {

      // TODO // MENU (1 NIVEL)
      // VALIDAR
      case OP_PERSONS:    manage_persons(fp_data, &list_persons); break;
      case OP_COUNTRIES:  manage_countries(); break;

      case OP_IMPORT:     import_persons(&list_persons); break;

      case OP_DUMP:       save_persons(fp_data, &list_persons); break;
      //case OP_ZAP:    manage_persons(fp_data, &list_persons); break;

      case OP_RESET:      reset_file(fp_data); break;

      case OP_EXIT:       wait("Opcao SAIR"); break;
    }
  }


  fclose(fp_data);
  return 0;
}
