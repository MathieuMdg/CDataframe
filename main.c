#include <stdio.h>
#include "column.h"
#include "fonctions.h"
#include <stdlib.h>
#include <string.h>
#include "CDataframe.h"
#define ASC 0
#define DESC 1

int main() {

    int running = 1;

    CDATAFRAME* ptr_CDataframe = NULL;

    int init_CDataframe = 0;

    int full = 0;



    while (running == 1) {

        menu();


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
                    printf("\t 'b' - Remplissage du ptr_CDataframe a partir de saisies utilisateurs\n");
                    printf("\t 'c' - Remplissage en dur du ptr_CDataframe (utilise un ptr_CDataframe prerempli pour le reste des fonctionnalites)\n");
                    printf("\nChoisissez une fonctionnalite a, b ou c (pour revenir au menu tapez 0) :");
                    scanf(" %c", &fonction);

                    switch (fonction) {

                        case 'a':

                            ENUM_TYPE INIT[10];
                            ptr_CDataframe = create_cdataframe(INIT,0);

                            print_answer("CDataframe creer...");

                            break;

                        case 'b':

                            print_answer("REMPLISSAGE...");

                            fill_CDataframe(ptr_CDataframe);

                            break;


                        case 'c':

                            print_answer("REMPLISSAGE...");

                            fill_CDataframe_auto(ptr_CDataframe);

                            break;

                        case '0':
                            categorie = 0;
                            break;

                    }

                }
                break;
            }


            case 2: {

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
                break;
            }


            case 3 : {

                while (categorie == 3) {

                    for (int i = 0; i < 3; i++)
                        printf("\n");
                    printf("3. Operations usuelles\n\n");
                    printf("\t 'a' - Ajouter une ligne de valeurs au ptr_CDataframe\n");
                    printf("\t 'b' - Supprimer une ligne de valeurs du ptr_CDataframe\n");
                    printf("\t 'c' - Ajouter une colonne au ptr_CDataframe\n");
                    printf("\t 'd' - Supprimer une colonne du ptr_CDataframe\n");
                    printf("\t 'e' - Renommer le titre d une colonne du ptr_CDataframe\n");
                    printf("\t 'f' - Verifier l existence d une valeur (recherche) dans le ptr_CDataframe\n");
                    printf("\t 'g' - Acceder/remplacer la valeur se trouvant dans une cellule du ptr_CDataframe en utilisant son numero de ligne et de colonne\n");
                    printf("\t 'h' - Afficher les noms des colonnes\n ");
                    printf("\nChoisissez une fonctionnalite a, b ou c (pour revenir au menu tapez 0) :");
                    scanf(" %c", &fonction);

                    switch (fonction) {

                        case 'a':

                            add_lines(ptr_CDataframe);

                            break;

                        case 'b':

                            printf("\n\n\nNOM COLONNE :");
                            char name[100];
                            scanf(" %s", name);
                            printf("\n");

                            delete_line(acces_column_by_name(ptr_CDataframe, name));

                            break;


                        case 'c':

                            printf("\n\n\nPOSITION DE LA COLONNE (DEBUT[0], POSTION[x],  FIN[-1]) : ");
                            int pos;
                            scanf(" %d", &pos);
                            printf("\n");

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

                            break;


                        case 'd':


                            printf("\n\n\nNUMERO COLONNE:");
                            int number;
                            scanf(" %d", &number);
                            printf("\n");

                            delete_lnode(ptr_CDataframe, number);

                            print_answer("Supprime...");

                            break;

                        case 'e':

                            printf("\n\n\nNOM COLONNE :");
                            char named[100];
                            scanf(" %s", named);
                            printf("\n");

                            rename_columns_name(acces_column_by_name(ptr_CDataframe, named));

                            break;


                        case 'f':


                            if (init_CDataframe == 1) {
                                LNODE *tmp;
                                int presence = 0, value;
                                printf("\n\n");
                                printf("------------------------------------------\n\n");
                                printf("VALEUR RECHERCHEE : ");
                                scanf(" %d", &value);
                                if (ptr_CDataframe != NULL) {
                                    tmp = ptr_CDataframe;
                                    while (tmp != NULL && presence != 1) {
                                        if (value_research(tmp->COLUMN, value)) {
                                            presence = 1;
                                        }
                                        tmp = (LNODE *) tmp->SUCC;
                                    }
                                }
                                if (presence == 1) {
                                    print_answer("La valeur est presente dans le ptr_CDataframe");
                                } else {
                                    print_answer("La valeur n'est pas presente dans le ptr_CDataframe");
                                }
                            } else {
                                init_CData();
                            }
                            break;

                        case 'g':


                            printf("\n\n\nNOM COLONNE :");
                            char namee[100];
                            scanf(" %s", namee);
                            printf("\n");

                            COLUMN *col = acces_column_by_name(ptr_CDataframe, namee);

                            int line_number;
                            printf("NUMERO LIGNE : ");
                            scanf(" %d", &line_number);
                            printf("\n");

                            printf("La valeur a la ligne %d de la colonne %s est %d\n", line_number, col->CHAINE,
                                   *((int *) col->DONNEES[line_number]));

                            printf("\n\nCHANGER VALEUR (OUI[1]/ NON[0]) : ");
                            int answer;
                            scanf(" %d", &answer);
                            printf("\n");

                            if (answer == 1) {
                                col->DONNEES[line_number] = type_choice(col);
                            }

                            break;


                        case 'h':

                            LNODE *tmp = ptr_CDataframe->head;

                            while (tmp->SUCC != NULL) {
                                tmp = tmp->SUCC;
                                printf("\n\n\n%s - ", tmp->COLUMN->CHAINE);
                            }
                            printf("%s\n", tmp->COLUMN->CHAINE);
                            break;

                        case '0':
                            categorie = 0;
                            break;


                    }
                }
                break;

            }


            case 4: {

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

                            printf("\n\n\nLe nombre de colonne du CDataframe est : %d",get_cdataframe_cols_size(ptr_CDataframe));

                            break;


                        case 'c':

                            LNODE * tmp = ptr_CDataframe->head;

                            printf("\n\n\nVALEUR A CHERCHER :");
                            void* value = type_choice(tmp->COLUMN);;
                            printf("\n");



                            ENUM_TYPE type = INT;

                            int occ = 0;

                            while(tmp != NULL) {
                                if (tmp->COLUMN->COLUMN_TYPE == type) {
                                    occ += occurence(tmp->COLUMN, *((int*)value));
                                    tmp = tmp->SUCC;
                                }
                            }
                            printf("Le nombre d'occurence de %d est : %d", *((int*)value), occ);




                            break;

                        case 'd':

                            LNODE * tmp1 = ptr_CDataframe->head;

                            printf("\n\n\nVALEUR A CHERCHER :");
                            void* value2 = type_choice(tmp1->COLUMN);;
                            printf("\n");

                            ENUM_TYPE type1 = INT;

                            int sup = 0;

                            while(tmp1 != NULL) {
                                if (tmp1->COLUMN->COLUMN_TYPE == type1) {
                                    sup += sup_x(tmp1->COLUMN, *((int*)value2));
                                    tmp1 = tmp1->SUCC;
                                }
                            }
                            printf("Le nombre d'occurence de %d est : %d", *((int*)value2), sup);

                            break;

                        case 'e':


                            LNODE * tmp3 = ptr_CDataframe->head;

                            printf("\n\n\nVALEUR A CHERCHER :");
                            void* value3 = type_choice(tmp3->COLUMN);;
                            printf("\n");

                            ENUM_TYPE type3 = INT;

                            int inf = 0;

                            while(tmp3 != NULL) {
                                if (tmp3->COLUMN->COLUMN_TYPE == type3) {
                                    inf += inf_x(tmp3->COLUMN, *((int*)value3));
                                    tmp3 = tmp3->SUCC;
                                }
                            }
                            printf("Le nombre d'occurence de %d est : %d", *((int*)value3), inf);

                            break;


                        case '0':
                            categorie = 0;
                            break;

                    }

                }
                break;
            }



            case 5 : {

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

                            char* column_name = NULL;
                            printf("\n\n\nNOM COLONNE :");
                            scanf(" %s", column_name);
                            printf("\n");

                            COLUMN* new_column = acces_column_by_name(ptr_CDataframe, column_name);

                            printf("\n\n\nTYPE DE TRI (ASC ou DES) :");
                            int sort_dir;
                            scanf(" %d", &sort_dir);
                            printf("\n");
                            sort(new_column, sort_dir);
                            print_col_by_index(new_column);

                            break;

                        case 'b':

                            char name_column[100];
                            printf("\n\n\nNOM COLONNE :");
                            scanf(" %s", name_column);

                            check_index(acces_column_by_name(ptr_CDataframe, name_column));

                            print_answer("Indice de la colonne efface...");

                            break;


                        case 'c':

                            char column[100];
                            printf("\n\n\nNOM COLONNE :");
                            scanf(" %s", column);

                            erase_index(acces_column_by_name(ptr_CDataframe, column));

                            print_answer("Indice de la colonne efface...");

                            break;

                        case 'd':
                                if(ptr_CDataframe == NULL) {

                                    printf("NOM DU FICHIER :");
                                    char file_name[100];
                                    scanf(" %s", file_name);
                                    printf("\n\n\n\n");

                                    printf("NOMBRE DE COLONNE :");
                                    int column_number;
                                    scanf(" %d", &column_number);
                                    printf("\n\n\n\n");

                                    ENUM_TYPE type[100];
                                    for(int i = 0; i<column_number; i++){
                                        printf("TYPE DE LA COLONNE [%d] :", i);
                                        scanf(" %d", &type[i]);
                                        printf("\n");
                                    }

                                    ptr_CDataframe = load_from_csv(file_name, type, column_number);

                                    print_answer("ptr_CDataframe cree...");
                                }
                                else{
                                    print_answer("CDataframe déjà rempli, veuillez en créer un nouveau...");
                                }

                            break;

                        case 'e':

                            printf("\n\n\nNOM DU FICHIER :");
                            char file_name[100];
                            scanf(" %s", file_name);
                            printf("\n\n\n\n");

                            save_into_csv(ptr_CDataframe, file_name);

                            print_answer("CDataframe sauvegarde dans le fichier...");

                            break;


                        case '0':
                            categorie = 0;
                            break;

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

    ENUM_TYPE cdata_type[] = {INT, INT, INT, INT, CHAR, INT, INT, CHAR, INT};
    int number_column = 3;
    CDATAFRAME* MIAM = create_cdataframe(cdata_type,  number_column);
    LNODE * tmp = MIAM->head;

    while (tmp!= NULL) {
        int* ch = (int*) malloc(sizeof (int));
        *ch= 1;
        insert_value(tmp->COLUMN, ch, tmp->COLUMN->COLUMN_TYPE);
        insert_value(tmp->COLUMN, ch, tmp->COLUMN->COLUMN_TYPE);
        print_col(tmp->COLUMN);
        tmp = tmp->SUCC;
    }

    printf("\n");

    save_into_csv(MIAM, "CHIPS.csv");

    CDATAFRAME* SLURP = load_from_csv("MIAM.csv", cdata_type, 3);

    printf("\n\n\n\n");
    tmp = SLURP->head;
    while (tmp!= NULL) {
        print_col(tmp->COLUMN);
        tmp = tmp->SUCC;
    }

    delete_cdataframe(&MIAM);
    delete_cdataframe(&SLURP);
    return 0;
}

