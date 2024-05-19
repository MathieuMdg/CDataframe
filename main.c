#include <stdio.h>
#include "column.h"
#include "fonctions.h"
#include <stdlib.h>
#include <string.h>
#include "CDataframe.h"
#define ASC 0
#define DESC 1

int main() {

    int running = 0;

    CDATAFRAME* CDataframe = NULL;

    int init_CDataframe = 0;

    int full = 0;



    while (running == 1) {

        menu();


        int categorie;
        printf("_______________________________________________\n\n");
        printf("Choisissez parmi les categories ci-dessus (entrez le numero de la categorie choisie 1-4) : ");
        scanf(" %d", &categorie);


        char fonction;

        switch (categorie) {


            case 1 : {

                while (categorie == 1) {

                    for (int i = 0; i < 3; i++)
                        printf("\n");
                    printf("1. Alimentation\n\n");
                    printf("\t 'a' - Creation du CDataframe vide\n");
                    printf("\t 'b' - Remplissage du CDataframe a partir de saisies utilisateurs\n");
                    printf("\t 'c' - Remplissage en dur du CDataframe (utilise un CDataframe prerempli pour le reste des fonctionnalites)\n");
                    printf("\nChoisissez une fonctionnalite a, b ou c (pour revenir au menu tapez 0) :");
                    scanf(" %c", &fonction);

                    switch (fonction) {

                        case 'a':
                            if (init_CDataframe == 0) {
                                // Création du CDataframe (sous forme de liste chainée)
                                CDataframe = NULL;
                                for (int i = 0; i < 3; i++)
                                    printf("\n");
                                printf("====================================\n");
                                printf("|| CDataframe cree avec succes... ||\n");
                                printf("====================================\n");
                                init_CDataframe = 1;
                            } else {
                                int answer;
                                printf("\n\n");
                                printf("--------------------------------------");
                                printf("\n\n");
                                printf("====================================================================\n");
                                printf("|| Un CDataframe a deja ete cree, voulez-vous en creer un nouveau? ||\n");
                                printf("====================================================================\n\n\n\n");
                                printf("\tTapez 1 pour oui et 0 pour non (oui effacera le CDataframe actuel) : ");
                                scanf(" %d", &answer);
                                if (answer == 1) {
                                    CDataframe = NULL;
                                    full = 0;
                                    for (int i = 0; i < 3; i++)
                                        printf("\n");
                                    printf("============================================\n");
                                    printf("|| Nouveau CDataframe cree avec succes... ||\n");
                                    printf("============================================\n");
                                } else {
                                    for (int i = 0; i < 3; i++)
                                        printf("\n");
                                    printf("===================\n");
                                    printf("|| Annulation... ||\n");
                                    printf("===================\n");
                                }
                            }

                            break;

                        case 'b':


                            if (init_CDataframe == 1 && full == 0) {
                                int nbre_col;
                                for (int i = 0; i < 3; i++)
                                    printf("\n");
                                printf("CHOISIR NOMBRE DE COLONNE CDATAFRAME :");
                                scanf(" %d", &nbre_col);
                                for (int i = 0; i < 3; i++)
                                    printf("\n");
                                for (int i = 0; i < nbre_col; i++) {
                                    LNODE *new_lnode = (LNODE *) malloc(sizeof(LNODE));
                                    new_lnode->NUMBER_COLONNE = i;
                                    new_lnode->SUCC = NULL;
                                    printf("NOM DE LA COLONNE %d : ", i);
                                    char title[100] = "";
                                    char *ptr_title = malloc(strlen(title) + 1);
                                    enum enum_type type;
                                    scanf(" %s", title);
                                    strcpy(ptr_title, title);
                                    printf("\n\n\nTYPE DE LA COLONNE %s (NULLVAL[1] , UINT[2], INT[3], CHAR[4], FLOAT[5], DOUBLE[6], STRING[7], STRUCTURE[8]) : ", ptr_title);
                                    scanf(" %u", &type);
                                    printf("\n\n\n");
                                    new_lnode->COLUMN = create_column(type, ptr_title);
                                    int number_lines;
                                    printf("CHOISIR NOMBRE DE LIGNE POUR LA COLONNE [%d] %s : ", new_lnode->NUMBER_COLONNE, new_lnode->COLUMN->CHAINE);
                                    scanf(" %d", &number_lines);
                                    for (int i = 0; i < 3; i++)
                                        printf("\n");
                                    for (int j = 0; j < number_lines; j++) {
                                        void* value = type_choice(new_lnode->COLUMN);
                                        if (new_lnode->COLUMN->COLUMN_TYPE == STRING) {
                                            insert_value(new_lnode->COLUMN, value);
                                        }
                                        else {
                                            insert_value(new_lnode->COLUMN, &value);
                                        }
                                    }

                                    if (CDataframe == NULL) {
                                        CDataframe->head = new_lnode;
                                    } else {
                                        LNODE *tmp = CDataframe->head;
                                        while (tmp->SUCC != NULL) {
                                            tmp = (LNODE *) tmp->SUCC;
                                        }
                                        tmp->SUCC = (struct mailllon *) new_lnode;
                                    }
                                }
                                full = 1;
                            } else {
                                if (full == 1) {
                                    printf("\n\n\n");
                                    printf("============================================================\n");
                                    printf("|| Tableau deja rempli manuellement ou automatiquement... ||\n");
                                    printf("============================================================\n");
                                } else {
                                    init_CData();
                                }
                            }
                            break;


                        case 'c':


                            if (init_CDataframe == 1 && full == 0) {
                                LNODE *tmp;
                                for (int i = 0; i < 5; i++) {
                                    LNODE *nouveau = (LNODE *) malloc(sizeof(LNODE));
                                    nouveau->NUMBER_COLONNE = i;
                                    nouveau->SUCC = NULL;
                                    unsigned int number = 0;
                                    char title[100];
                                    sprintf(title, "colonne%d", i);
                                    char *ptr_title = malloc(strlen(title) + 1);
                                    strcpy(ptr_title, title);
                                    nouveau->COLUMN = create_column(UINT, ptr_title);
                                    for (int j = 0; j < 5; j++) {
                                        int good = 0;
                                        while (good == 0) {
                                            good = insert_value(nouveau->COLUMN, &number);
                                            number++;
                                        }
                                    }
                                    if (CDataframe == NULL) {
                                        CDataframe->head = nouveau;
                                    } else
                                    {
                                        LNODE *tmp = CDataframe->head;
                                        while (tmp->SUCC != NULL) {
                                            tmp = (LNODE *) tmp->SUCC;
                                        }
                                        tmp->SUCC = (struct mailllon *) nouveau;
                                    }
                                }
                                printf("\n\n\n");
                                printf("======================================\n");
                                printf("|| CDataframe rempli avec succes... ||\n");
                                printf("======================================\n");
                                full = 1;
                            } else {
                                if (full == 1) {
                                    printf("\n\n\n");
                                    printf("============================================================\n");
                                    printf("|| Tableau deja rempli manuellement ou automatiquement... ||\n");
                                    printf("============================================================\n");
                                } else {
                                    init_CData();
                                }
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

                while (categorie == 2) {

                    for (int i = 0; i < 3; i++)
                        printf("\n");
                    printf("2. Affichage\n\n");
                    printf("\t 'a' - Afficher tout le CDataframe\n");
                    printf("\t 'b' - Afficher une partie des lignes du CDataframe selon une limite fournie par un utilisateur\n");
                    printf("\t 'c' - Afficher une partie des colonnes du CDataframe selon une limite fournie par un utilisateur\n");
                    printf("\nChoisissez une fonctionnalite a, b ou c (pour revenir au menu tapez 0) :");
                    scanf(" %c", &fonction);

                    switch (fonction) {

                        case 'a':


                            if (init_CDataframe == 1) {
                                print_answer("Affichage...");
                                print_CData_chaine(CDataframe);
                            } else {
                                init_CData();
                            }
                            break;

                        case 'b':


                            if (init_CDataframe == 1) {
                                printf("\n\n\n");
                                print_CData_selected_lines(CDataframe);
                            } else {
                                init_CData();
                            }
                            break;


                        case 'c':


                            if (init_CDataframe == 1) {
                                print_CData_selected_column(CDataframe);
                            } else {
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


            case 3 : {

                while (categorie == 3) {

                    for (int i = 0; i < 3; i++)
                        printf("\n");
                    printf("3. Operations usuelles\n\n");
                    printf("\t 'a' - Ajouter une ligne de valeurs au CDataframe\n");
                    printf("\t 'b' - Supprimer une ligne de valeurs du CDataframe\n");
                    printf("\t 'c' - Ajouter une colonne au CDataframe\n");
                    printf("\t 'd' - Supprimer une colonne du CDataframe\n");
                    printf("\t 'e' - Renommer le titre d une colonne du CDataframe\n");
                    printf("\t 'f' - Verifier l existence d une valeur (recherche) dans le CDataframe\n");
                    printf("\t 'g' - Acceder/remplacer la valeur se trouvant dans une cellule du CDataframe en utilisant son numero de ligne\n\t\t et de colonne\n");
                    printf("\t 'h' - Afficher les noms des colonnes\n ");
                    printf("\nChoisissez une fonctionnalite a, b ou c (pour revenir au menu tapez 0) :");
                    scanf(" %c", &fonction);

                    switch (fonction) {

                        case 'a':


                            if (init_CDataframe == 1) {
                                int column_number;
                                printf("\n\n\n");
                                printf("NUMERO COLONNE : ");
                                scanf(" %d", &column_number);
                                column_number += 1;
                                LNODE *tmp;
                                if (CDataframe != NULL) {
                                    int i = 0;
                                    tmp = CDataframe->head;
                                    while (tmp != NULL && i < column_number - 1) {
                                        i++;
                                        tmp = (LNODE *) tmp->SUCC;
                                    }
                                    if (tmp == NULL) {
                                        print_answer("Colonne inexistante...");
                                    } else {
                                        ENUM_TYPE value;
                                        printf("\n\n\n");
                                        printf("VALEUR A AJOUTER : ");
                                        scanf(" %d", &value);
                                        printf("\n");
                                        insert_value(tmp->COLUMN, &value);
                                    }
                                }
                            } else {
                                init_CData();
                            }
                            break;

                        case 'b':


                            if (init_CDataframe == 1) {
                                LNODE *tmp = NULL;
                                int column_number;
                                printf("\n\n\n");
                                printf("NUMERO COLONNE : ");
                                scanf(" %d", &column_number);
                                column_number++;
                                if (CDataframe != NULL) {
                                    int i = 0;
                                    tmp = CDataframe->head;
                                    while (tmp != NULL && i < column_number - 1) {
                                        i++;
                                        tmp = (LNODE *) tmp->SUCC;
                                    }
                                }
                                if (tmp == NULL) {
                                    print_answer("Colonne inexistante...");
                                } else {
                                    delete_line(tmp->COLUMN);
                                }
                            } else {
                                init_CData();
                            }
                            break;


                        case 'c':


                            if (init_CDataframe == 1) {
                                LNODE *tmp;
                                int column_position;
                                printf("\n\n\n");
                                printf("POSITION NOUVELLE COLONNE (DEBUT[0], POSITION[0], FIN[-1]) : ");
                                scanf(" %d", &column_position);
                                printf("\n");
                                if (CDataframe != NULL) {
                                    LNODE * nouveau = NULL;
                                    nouveau = CData_create_column();
                                    switch (column_position) {

                                        case -1 :
                                            tmp = CDataframe;
                                            while (tmp->SUCC != NULL) {
                                                tmp = (LNODE *) tmp->SUCC;
                                            }
                                            tmp->SUCC = (struct mailllon *) nouveau;
                                            nouveau->SUCC = NULL;
                                            break;

                                        case 0:
                                            printf("fiefe");
                                            nouveau->SUCC = (struct mailllon *) CDataframe;
                                            CDataframe = nouveau;
                                            tmp = nouveau;
                                            tmp->NUMBER_COLONNE = 0;
                                            tmp = (LNODE *) tmp->SUCC;
                                            while (tmp != NULL) {
                                                tmp->NUMBER_COLONNE++;
                                                tmp = (LNODE *) tmp->SUCC;
                                            }
                                            printf("lo");
                                            break;

                                        default:
                                            int i = 0;
                                            tmp = CDataframe;
                                            while (tmp != NULL && i < column_position - 1) {
                                                tmp = (LNODE *) tmp->SUCC;
                                                i++;
                                            }
                                            nouveau->SUCC = tmp->SUCC;
                                            tmp->SUCC = (struct mailllon *) nouveau;
                                            break;
                                    }
                                }
                                else {
                                    LNODE *nouveau = (LNODE *) malloc(sizeof(LNODE));
                                    nouveau->NUMBER_COLONNE = 0;
                                    nouveau->SUCC = NULL;
                                    printf("NOM DE LA COLONNE %d : ", nouveau->NUMBER_COLONNE);
                                    char title[100] = "";
                                    char *ptr_title = malloc(strlen(title) + 1);
                                    enum enum_type type;
                                    scanf(" %s", title);
                                    strcpy(ptr_title, title);
                                    printf("\n\n\nTYPE DE LA COLONNE %s (NULLVAL[1] , UINT[2], INT[3], CHAR[4], FLOAT[5], DOUBLE[6], STRING[7], STRUCTURE[8]) : ",
                                           ptr_title);
                                    scanf(" %u", &type);
                                    printf("\n\n\n");
                                    nouveau->COLUMN = create_column(type, ptr_title);
                                    int number_lines;
                                    printf("CHOISIR NOMBRE DE LIGNE POUR LA COLONNE [%d] %s : ",
                                           nouveau->NUMBER_COLONNE, nouveau->COLUMN->CHAINE);
                                    scanf(" %d", &number_lines);
                                    for (int i = 0; i < 3; i++)
                                        printf("\n");
                                    for (int j = 0; j < number_lines; j++) {
                                        void *value = type_choice(nouveau->COLUMN);
                                        if (nouveau->COLUMN->COLUMN_TYPE == STRING) {
                                            insert_value(nouveau->COLUMN, value);
                                        } else {
                                            insert_value(nouveau->COLUMN, &value);
                                        }
                                    }
                                    CDataframe = nouveau;
                                    print_answer("COLONNE AJOUTEE");
                                }
                            }
                            else {
                                init_CData();
                            }
                            break;


                        case 'd':


                            if (init_CDataframe == 1) {
                                LNODE *tmp;
                                LNODE *ptmp;
                                int column_position;
                                printf("Position du nouveau LNODE a supprimer (0: debut, x: postion de x et -1 : fin : ");
                                scanf(" %d", &column_position);
                                if (CDataframe != NULL) {
                                    if (column_position == -1) {
                                        tmp = CDataframe;
                                        while (tmp->SUCC != NULL) {
                                            ptmp = tmp;
                                            tmp = (LNODE *) tmp->SUCC;
                                        }
                                        free(tmp);
                                        ptmp->SUCC = NULL;
                                    }
                                    if (column_position == 0) {
                                        tmp = CDataframe;
                                        delete_column(tmp->COLUMN);
                                        free(tmp);
                                    }
                                    if (column_position != 0 && column_position != -1) {
                                        int i = 0;
                                        column_position += 1;
                                        tmp = CDataframe;
                                        while (tmp != NULL && i < column_position - 1) {
                                            i++;
                                            ptmp = tmp;
                                            tmp = (LNODE *) tmp->SUCC;
                                        }
                                        if (tmp == NULL) {
                                            printf("La colonne n existe pas...");
                                        } else {
                                            ptmp->SUCC = tmp->SUCC;
                                            delete_column(tmp->COLUMN);
                                        }
                                    }
                                }
                            } else {
                                init_CData();
                            }
                            break;

                        case 'e':


                            if (init_CDataframe == 1) {
                                int column_number;
                                printf("------------------------------------------\n\n\n");
                                printf("CHOISIR NUMERO DE COLONNE : ");
                                scanf(" %d", &column_number);
                                printf("\n");
                                LNODE *tmp = NULL;
                                if (CDataframe != NULL) {
                                    int i = 0;
                                    tmp = CDataframe;
                                    while (tmp != NULL && i < column_number) {
                                        i++;
                                        tmp = (LNODE *) tmp->SUCC;
                                    }
                                }
                                if (tmp == NULL) {
                                    print_answer("Colonne inexistante...");
                                } else {
                                    printf("Nouveau nom de la colonne %s [%d]...\n ", tmp->COLUMN->CHAINE,
                                           column_number);
                                    rename_columns_name(tmp->COLUMN);
                                }
                            } else {
                                init_CData();
                            }
                            break;


                        case 'f':


                            if (init_CDataframe == 1) {
                                LNODE *tmp;
                                int presence = 0, value;
                                printf("\n\n");
                                printf("------------------------------------------\n\n");
                                printf("VALEUR RECHERCHEE : ");
                                scanf(" %d", &value);
                                if (CDataframe != NULL) {
                                    tmp = CDataframe;
                                    while (tmp != NULL && presence != 1) {
                                        if (value_research(tmp->COLUMN, value)) {
                                            presence = 1;
                                        }
                                        tmp = (LNODE *) tmp->SUCC;
                                    }
                                }
                                if (presence == 1) {
                                    print_answer("La valeur est presente dans le CDataframe");
                                } else {
                                    print_answer("La valeur n'est pas presente dans le CDataframe");
                                }
                            } else {
                                init_CData();
                            }
                            break;

                        case 'g':


                            if (init_CDataframe == 1) {
                                int column_number, line_number;
                                printf("\n\n\nNUMERO COLONNE : ");
                                scanf(" %d", &column_number);
                                printf("\n");
                                printf("NUMERO LIGNE : ");
                                scanf(" %d", &line_number);
                                printf("\n");
                                LNODE *tmp = NULL;
                                if (CDataframe != NULL) {
                                    int i = 0;
                                    tmp = CDataframe;
                                    while (tmp != NULL && i < column_number) {
                                        i++;
                                        tmp = (LNODE *) tmp->SUCC;
                                    }
                                }
                                if (tmp == NULL) {
                                    print_answer("La colonne n existe pas...");
                                } else {
                                    printf("La valeur a la ligne %d de la colonne %s [%d] est %d\n", line_number,
                                           tmp->COLUMN->CHAINE, column_number, tmp->COLUMN->DONNEES[line_number]);
                                    ENUM_TYPE value;
                                    printf("\n\nCHANGER VALEUR? (oui: 1/ non: 0) : ");
                                    scanf(" %d", &value);
                                    printf("\n");
                                    if (value) {
                                        printf("\n\nVALEUR : ");
                                        scanf(" %d", &value);
                                        printf("\n");
                                    }
                                }
                            } else {
                                init_CData();
                            }
                            break;


                        case 'h':


                            if (init_CDataframe == 1) {
                                printf("\n\n\n");
                                LNODE *tmp;
                                if (CDataframe != NULL) {
                                    tmp = CDataframe;
                                    printf("%s ", tmp->COLUMN->CHAINE);
                                    tmp = (LNODE *) tmp->SUCC;
                                    while (tmp != NULL) {
                                        printf("- %s ", tmp->COLUMN->CHAINE);
                                        tmp = (LNODE *) tmp->SUCC;
                                    }
                                }
                            } else {
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


                            if (init_CDataframe == 1) {
                                print_CData_number_lines(CDataframe);
                            } else {
                                init_CData();
                            }
                            break;

                        case 'b':


                            if (init_CDataframe == 1) {
                                print_CData_number_column(CDataframe);
                            } else {
                                init_CData();
                            }
                            break;


                        case 'c':


                            if (init_CDataframe == 1) {
                                LNODE *tmp;
                                int value, occ = 0;
                                printf("\n\n\nVALEUR RECHERCHEE? : ");
                                scanf(" %d", &value);
                                printf("\n");
                                if (CDataframe != NULL) {
                                    tmp = CDataframe;
                                    while (tmp != NULL) {
                                        if (value_research(tmp->COLUMN, value)) {
                                            occ++;
                                        }
                                        tmp = (LNODE *) tmp->SUCC;
                                    }
                                }
                                printf("La valeur recherchee est presente dans %d cellule(s).", occ);
                            } else {
                                init_CData();
                            }
                            break;

                        case 'd':


                            if (init_CDataframe == 1) {
                                LNODE *tmp;
                                int value, sup = 0;
                                printf("\n\n\nVALEUR RECHERCHEE? : ");
                                scanf(" %d", &value);
                                printf("\n");
                                if (CDataframe != NULL) {
                                    tmp = CDataframe;
                                    while (tmp != NULL) {
                                        sup += sup_x(tmp->COLUMN, value);
                                        tmp = (LNODE *) tmp->SUCC;
                                    }
                                }
                                printf("Le nombre de cellule contenant une valeur superieur a %d est de %d.", value,
                                       sup);
                            } else {
                                init_CData();
                            }
                            break;

                        case 'e':


                            if (init_CDataframe == 1) {
                                LNODE *tmp;
                                int value, inf = 0;
                                printf("<\n\n\nVALEUR RECHERCHEE? : ");
                                scanf(" %d", &value);
                                printf("\n");
                                if (CDataframe != NULL) {
                                    tmp = CDataframe;
                                    while (tmp != NULL) {
                                        inf += inf_x(tmp->COLUMN, value);
                                        tmp = (LNODE *) tmp->SUCC;
                                    }
                                }
                                printf("\n\n\n");
                                printf("========================================================================\n");
                                printf("|| Le nombre de cellule contenant une valeur inferieur a %d est de %d ||\n",
                                       value, inf);
                                printf("========================================================================\n");
                            } else {
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

            case 0 :
                printf("\n\n\n");
                printf("======================\n");
                printf("|| Fin de programme ||\n");
                printf("======================\n");
                running = 0;
        }
    }

    ENUM_TYPE cdata_type[] = {STRING, STRING, STRING, STRING, CHAR, INT, INT, CHAR, INT};
    int number_column = 3;
    CDATAFRAME* MIAM = create_cdataframe(cdata_type,  number_column);
    LNODE * tmp = MIAM->head;

    while (tmp!= NULL) {
        char ch[] = "hehe";
        insert_value(tmp->COLUMN, ch);
        insert_value(tmp->COLUMN, ch);
        print_col(tmp->COLUMN);
        tmp = tmp->SUCC;
    }

    printf("\n");

    printf("\hehr\n");
    save_into_csv(MIAM, "MIAM.csv");
    delete_cdataframe(&MIAM);
    return 0;
}

