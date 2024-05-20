// Librairies nécessaires
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Appel des fichiers contenant les fonctions
#include "column.h"
#include "cdataframe.h"
#include "list.h"
#include "sort.h"

#define ASC 0
#define DESC 1




int main() {

    int running = 1;

    CDATAFRAME* ptr_CDataframe = NULL;

    int init_CDataframe = 0;

    int full = 0;



    while (running == 1) {

        menu();


        if (init_CDataframe == 0) {
            init_CData();
        }
        if (full == 0) {
            full_CData();
        }

        int categorie;
        printf("_______________________________________________\n\n");
        printf("Choisissez parmi les categories ci-dessus (entrez le numero de la categorie choisie 1-5) : ");
        scanf(" %d", &categorie);


        char fonction;

        switch (categorie) {


            case 1 : {

                while (categorie == 1) {

                    for (int i = 0; i < 3; i++)
                        printf("\n");
                    printf("1. Alimentation\n\n");
                    printf("\t 'a' - Creation du ptr_CDataframe vide\n");
                    printf("\t 'b' - Remplissage du CDataframe a partir de saisies utilisateurs\n");
                    printf("\t 'c' - Remplissage en dur du CDataframe\n");
                    printf("\nChoisissez une fonctionnalite a, b ou c (pour revenir au menu tapez 0) :");
                    scanf(" %c", &fonction);

                    switch (fonction) {

                        case 'a':

                            if (init_CDataframe == 0) {

                                ENUM_TYPE INIT[10];
                                ptr_CDataframe = create_cdataframe(INIT, 0);

                                print_answer("CDataframe creer...");

                                init_CDataframe = 1;

                                full = 0;

                            } else{

                                ptr_CDataframe = NULL;

                                ENUM_TYPE INIT[10];
                                ptr_CDataframe = create_cdataframe(INIT, 0);

                                print_answer("Nouveau CDataframe...");

                                full = 0;
                            }

                            break;

                        case 'b':

                            if (init_CDataframe == 1) {

                                print_answer("REMPLISSAGE...");

                                fill_CDataframe(ptr_CDataframe);

                                full = 1;
                            }
                            else {
                                init_CData();
                            }
                            break;


                        case 'c':
                            if (init_CDataframe == 1) {

                                print_answer("REMPLISSAGE...");

                                fill_CDataframe_auto(ptr_CDataframe);

                                full = 1;
                            } else{
                                init_CData();
                            }
                            break;

                        case '0':
                            categorie = 0;
                            break;

                    }

                }
                break;
            }


            case 2: {
                if (init_CDataframe == 1 && full == 1) {
                    while (categorie == 2) {

                        for (int i = 0; i < 3; i++)
                            printf("\n");
                        printf("2. Affichage\n\n");
                        printf("\t 'a' - Afficher tout le ptr_CDataframe\n");
                        printf("\t 'b' - Afficher une partie des lignes du ptr_CDataframe selon une limite fournie par un utilisateur\n");
                        printf("\t 'c' - Afficher une partie des colonnes du ptr_CDataframe selon une limite fournie par un utilisateur\n");
                        printf("\nChoisissez une fonctionnalite a, b ou c (pour revenir au menu tapez 0) :");
                        scanf(" %c", &fonction);

                        switch (fonction) {

                            case 'a':


                                print_answer("Affichage...");
                                print_CData_chaine(ptr_CDataframe);

                                break;

                            case 'b':

                                printf("\n\n\n");
                                print_CData_selected_lines(ptr_CDataframe);

                                break;


                            case 'c':


                                print_CData_selected_column(ptr_CDataframe);

                                break;

                            case '0':
                                categorie = 0;
                                break;

                        }

                    }
                }
                break;
            }


            case 3 : {
                if (init_CDataframe == 1) {
                    while (categorie == 3) {

                        for (int i = 0; i < 3; i++)
                            printf("\n");
                        printf("3. Operations usuelles\n\n");
                        printf("\t 'a' - Ajouter une ligne de valeurs au ptr_CDataframe\n");
                        printf("\t 'b' - Supprimer une ligne de valeurs du ptr_CDataframe\n");
                        printf("\t 'c' - Ajouter une colonne au ptr_CDataframe\n");
                        printf("\t 'd' - Supprimer une colonne du ptr_CDataframe\n");
                        printf("\t 'e' - Renommer le titre d une colonne du ptr_CDataframe\n");
                        printf("\t 'f' - Acceder/remplacer la valeur se trouvant dans une cellule du ptr_CDataframe en utilisant son numero de ligne et de colonne\n");
                        printf("\t 'g' - Afficher les noms des colonnes\n ");
                        printf("\nChoisissez une fonctionnalite a, b ou c (pour revenir au menu tapez 0) :");
                        scanf(" %c", &fonction);

                        switch (fonction) {

                            case 'a':
                                if (full == 1) {
                                    printf("\n\n\n");
                                    add_lines(ptr_CDataframe);
                                }
                                else {
                                    full_CData();
                                }
                                break;

                            case 'b':
                                if(full == 1) {
                                    printf("\n\n\nNOM COLONNE :");
                                    char name[100];
                                    scanf(" %s", name);
                                    printf("\n");

                                    COLUMN* column = acces_column_by_name(ptr_CDataframe, name);

                                    if (column != NULL) {
                                        delete_line(column);
                                    }

                                }
                                else{
                                    full_CData();
                                }
                                break;


                            case 'c':

                                printf("\n\n\nPOSITION DE LA COLONNE (DEBUT[0], POSTION[x],  FIN[-1]) : ");
                                int pos;
                                scanf(" %d", &pos);
                                printf("\n");

                                if (pos > get_cdataframe_cols_size(ptr_CDataframe)) {
                                    print_answer("Position erronee...");
                                }
                                else {

                                    LNODE *new_lnode = create_lnode();

                                    insert_lnode(ptr_CDataframe, new_lnode, pos);

                                    printf("NOM DE LA COLONNE [%d]: ", new_lnode->NUMBER_COLONNE);
                                    char title[100] = "";
                                    char *ptr_title = malloc(strlen(title) + 1);
                                    enum enum_type type;


                                    scanf(" %s", title);
                                    strcpy(ptr_title, title);
                                    printf("\n\n\nTYPE DE LA COLONNE %s (NULLVAL[1] , UINT[2], INT[3], CHAR[4], FLOAT[5], DOUBLE[6], STRING[7], STRUCTURE[8]) : ",
                                           ptr_title);
                                    scanf(" %u", &type);
                                    printf("\n\n\n");

                                    new_lnode->COLUMN = create_column(type, ptr_title);

                                    full = 1;
                                }
                                break;


                            case 'd':

                                if (full == 1) {
                                    printf("\n\n\nNUMERO COLONNE:");
                                    int number;
                                    scanf(" %d", &number);
                                    printf("\n");

                                    if (number < get_cdataframe_cols_size(ptr_CDataframe)) {
                                        delete_lnode(ptr_CDataframe, number);
                                        print_answer("Suppression...");
                                    } else{
                                        print_answer("Colonne intouvable...");
                                    }

                                }
                                else{
                                    full_CData();
                                }
                                break;

                            case 'e':
                                if (full == 1) {
                                    printf("\n\n\nNOM COLONNE :");
                                    char named[100];
                                    scanf(" %s", named);
                                    printf("\n");
                                    COLUMN *column = acces_column_by_name(ptr_CDataframe, named);
                                    if (column != NULL) {
                                        rename_columns_name(column);
                                    }
                                }
                                else {
                                    full_CData();
                                }

                                break;


                            case 'f':

                                if (full == 1) {
                                    printf("\n\n\nNOM COLONNE :");
                                    char namee[100];
                                    scanf(" %s", namee);
                                    printf("\n");

                                    COLUMN *col = acces_column_by_name(ptr_CDataframe, namee);

                                    if (col != NULL) {

                                        int line_number;
                                        printf("NUMERO LIGNE : ");
                                        scanf(" %d", &line_number);
                                        printf("\n");

                                        printf("La valeur a la ligne %d de la colonne %s est %d\n", line_number,
                                               col->CHAINE,
                                               *((int *) col->DONNEES[line_number]));

                                        printf("\n\nCHANGER VALEUR (OUI[1]/ NON[0]) : ");
                                        int answer;
                                        scanf(" %d", &answer);
                                        printf("\n");

                                        if (answer == 1) {
                                            col->DONNEES[line_number] = type_choice(col);
                                        }
                                    }

                                }
                                else{
                                    full_CData();
                                }
                                break;


                            case 'g':
                                if (full == 1) {
                                    LNODE *tmp = ptr_CDataframe->head;

                                    printf("\n\n\n");
                                    while (tmp->SUCC != NULL) {
                                        printf("%s - ", tmp->COLUMN->CHAINE);
                                        tmp = tmp->SUCC;
                                    }
                                    printf("%s\n", tmp->COLUMN->CHAINE);
                                } else{
                                    full_CData();
                                }
                                break;

                            case '0':
                                categorie = 0;
                                break;


                        }
                    }
                }
                break;
            }


            case 4: {
                if (init_CDataframe == 1 && full == 1) {
                    while (categorie == 4) {

                        for (int i = 0; i < 3; i++)
                            printf("\n");
                        printf("4. Analyse et statistiques\n\n");
                        printf("\t 'a' - Afficher le nombre de lignes\n");
                        printf("\t 'b' - Afficher le nombre de colonnes\n");
                        printf("\t 'c' - Nombre de cellules contenant une valeur egale a x (x donne en parametre)\n");
                        printf("\t 'd' - Nombre de cellules contenant une valeur superieure a x (x donne en parametre)\n");
                        printf("\t 'e' - Nombre de cellules contenant une valeur inferieure a x(x donne en parametre)\n");
                        printf("\nChoisissez une fonctionnalite a, b ou c (pour revenir au menu tapez 0) :");
                        scanf(" %c", &fonction);

                        switch (fonction) {

                            case 'a':

                                printf("\n\n\n");
                                print_CData_number_lines(ptr_CDataframe);

                                break;

                            case 'b':

                                printf("\n\n\nLe nombre de colonne du CDataframe est : %d",
                                       get_cdataframe_cols_size(ptr_CDataframe));

                                break;


                            case 'c':

                                LNODE *tmp = ptr_CDataframe->head;

                                printf("\n\n\nVALEUR A CHERCHER :");
                                void *value = type_choice(tmp->COLUMN);;
                                printf("\n");


                                ENUM_TYPE type = INT;

                                int occ = 0;

                                while (tmp != NULL) {
                                    if (tmp->COLUMN->COLUMN_TYPE == type) {
                                        occ += occurence(tmp->COLUMN, *((int *) value));
                                        tmp = tmp->SUCC;
                                    }
                                }
                                printf("Le nombre d'occurence de %d est : %d", *((int *) value), occ);


                                break;

                            case 'd':

                                LNODE *tmp1 = ptr_CDataframe->head;

                                printf("\n\n\nVALEUR A CHERCHER :");
                                void *value2 = type_choice(tmp1->COLUMN);;
                                printf("\n");

                                ENUM_TYPE type1 = INT;

                                int sup = 0;

                                while (tmp1 != NULL) {
                                    if (tmp1->COLUMN->COLUMN_TYPE == type1) {
                                        sup += sup_x(tmp1->COLUMN, *((int *) value2));
                                        tmp1 = tmp1->SUCC;
                                    }
                                }
                                printf("Le nombre d'occurence de %d est : %d", *((int *) value2), sup);

                                break;

                            case 'e':


                                LNODE *tmp3 = ptr_CDataframe->head;

                                printf("\n\n\nVALEUR A CHERCHER :");
                                void *value3 = type_choice(tmp3->COLUMN);;
                                printf("\n");

                                ENUM_TYPE type3 = INT;

                                int inf = 0;

                                while (tmp3 != NULL) {
                                    if (tmp3->COLUMN->COLUMN_TYPE == type3) {
                                        inf += inf_x(tmp3->COLUMN, *((int *) value3));
                                        tmp3 = tmp3->SUCC;
                                    }
                                }
                                printf("Le nombre d'occurence de %d est : %d", *((int *) value3), inf);

                                break;


                            case '0':
                                categorie = 0;
                                break;

                        }

                    }
                }
                break;
            }



            case 5 : {
                if (init_CDataframe == 1) {
                    while (categorie == 5) {

                        for (int i = 0; i < 3; i++)
                            printf("\n");
                        printf("5.Manupulation de ptr_CDataframe\n\n");
                        printf("\t 'a' - Trier une colonne\n");
                        printf("\t 'b' - Regarder le statut d'index d'une colonne\n");
                        printf("\t 'c' - Effacer l'index d'une colonne\n");
                        printf("\t 'd' - Importer un ptr_CDataframe d'un fichier .csv\n");
                        printf("\t 'e' - Sauvegarder un ptr_CDataframe dans un fichier .csv\n");
                        printf("\nChoisissez une fonctionnalite a, b, ... (pour revenir au menu tapez 0) :");
                        scanf(" %c", &fonction);

                        switch (fonction) {

                            case 'a':
                                if (full == 1) {
                                    char column_name[100];
                                    printf("\n\n\nNOM COLONNE :");
                                    scanf(" %s", column_name);
                                    printf("\n");

                                    COLUMN *new_column = acces_column_by_name(ptr_CDataframe, column_name);

                                    if (new_column != NULL) {

                                        printf("\n\n\nTYPE DE TRI (ASC[0] ou DES[1]) :");

                                        int sort_dir;
                                        scanf(" %d", &sort_dir);
                                        printf("\n");
                                        printf("slure");
                                        sort(new_column, sort_dir);
                                        printf("miam");
                                        print_col_by_index(new_column);
                                    }
                                } else{
                                    full_CData();
                                }
                                break;

                            case 'b':
                                if (full == 1) {
                                    char name_column[100];
                                    printf("\n\n\nNOM COLONNE :");
                                    scanf(" %s", name_column);

                                    COLUMN* column = acces_column_by_name(ptr_CDataframe, name_column);
                                    if (column != NULL) {
                                        int index = check_index(column);

                                        printf("Indice de la colonne : %d", index);
                                    }
                                }
                                else {
                                    full_CData();
                                }
                                break;


                            case 'c':
                                if (full == 1) {
                                    char column[100];
                                    printf("\n\n\nNOM COLONNE :");
                                    scanf(" %s", column);

                                    COLUMN* new = acces_column_by_name(ptr_CDataframe, column);

                                    if (new != NULL) {
                                        erase_index(new);

                                        print_answer("Indice de la colonne efface...");
                                    }
                                } else{
                                    full_CData();
                                }
                                break;

                            case 'd':
                                if (full != 1) {
                                    printf("\n\n\n\n");

                                    printf("NOM DU FICHIER :");
                                    char file_name[100];
                                    scanf(" %s", file_name);
                                    printf("\n\n\n\n");


                                    printf("NOMBRE DE COLONNE :");
                                    int column_number;
                                    scanf(" %d", &column_number);
                                    printf("\n\n\n\n");

                                    ENUM_TYPE type[100];
                                    for (int i = 0; i < column_number; i++) {
                                        printf("TYPE DE LA COLONNE [%d] (NULLVAL[1] , UINT[2], INT[3], CHAR[4], FLOAT[5], DOUBLE[6], STRING[7], STRUCTURE[8]) : ",
                                               i);
                                        scanf(" %d", &type[i]);
                                        printf("\n");
                                    }

                                    ptr_CDataframe = load_from_csv(file_name, type, column_number);

                                    if (ptr_CDataframe != NULL) {
                                        print_answer("CDataframe cree...");
                                        full = 1;
                                    }


                                }
                                else {
                                    print_answer("CDataframe deja rempli, veuillez en creer un nouveau...");
                                }

                                break;

                            case 'e':
                                if (full == 1) {
                                    printf("\n\n\nNOM DU FICHIER :");
                                    char file_name[100];
                                    scanf(" %s", file_name);
                                    printf("\n\n\n\n");

                                    save_into_csv(ptr_CDataframe, file_name);

                                    print_answer("CDataframe sauvegarde dans le fichier...");
                                } else{
                                    full_CData();
                                }
                                break;


                            case '0':
                                categorie = 0;
                                break;

                        }

                    }
                }
                break;
            }

            case 0 :
                printf("\n\n\n");
                printf("======================\n");
                printf("|| Fin de programme ||\n");
                printf("======================\n");
                running = 0;
        }
    }

    delete_cdataframe(ptr_CDataframe);

    return 0;
}

