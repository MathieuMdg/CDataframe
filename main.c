#include <stdio.h>
#include "column.h"
#include "fonctions.h"
#include <stdlib.h>
#include <string.h>


int main() {

    int running = 1;

    maillon *CDataframe = NULL;

    int init_CDataframe = 0;


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


                            if (init_CDataframe == 1) {
                                int nbre_col;
                                for (int i = 0; i < 3; i++)
                                    printf("\n");
                                printf("\tChoisir le nombre de colonne du CDataframe (ce nombre pourra etre modifie plus tard) :");
                                scanf(" %d", &nbre_col);
                                for (int i = 0; i < 3; i++)
                                    printf("\n");
                                for (int i = 0; i < nbre_col; i++) {
                                    maillon *nouveau = (maillon *) malloc(sizeof(maillon));
                                    nouveau->INDEX = i;
                                    nouveau->SUCC = NULL;
                                    printf("\nQuel est le nom de la colonne %d : ", i);
                                    char title[100] = "";
                                    char *ptr_title = malloc(strlen(title) + 1);
                                    scanf(" %s", title);
                                    strcpy(ptr_title, title);
                                    nouveau->COLUMN = create_column(ptr_title);
                                    int number_lines;
                                    printf("Choisir un nombre de ligne pour la colonne [%d] %s : ", nouveau->INDEX,
                                           nouveau->COLUMN->CHAINE);
                                    scanf(" %d", &number_lines);
                                    for (int i = 0; i < 3; i++)
                                        printf("\n");
                                    for (int j = 0; j < number_lines; j++) {
                                        int value;
                                        printf("\nChoisir une valeur pour la ligne [%d] de la colonne %s [%d] :", j,
                                               nouveau->COLUMN->CHAINE, nouveau->INDEX);
                                        scanf(" %d", &value);
                                        insert_value(nouveau->COLUMN, value);
                                    }

                                    if (CDataframe == NULL) {
                                        CDataframe = nouveau;
                                    } else {
                                        maillon *tmp = CDataframe;
                                        while (tmp->SUCC != NULL) {
                                            tmp = (maillon *) tmp->SUCC;
                                        }
                                        tmp->SUCC = (struct mailllon *) nouveau;
                                    }
                                }
                            } else {
                                init_CData();
                            }
                            break;


                        case 'c':


                            if (init_CDataframe == 1) {
                                maillon *tmp;
                                int random = 0;
                                for (int i = 0; i < 5; i++) {
                                    maillon *nouveau = (maillon *) malloc(sizeof(maillon));
                                    nouveau->INDEX = i;
                                    nouveau->SUCC = NULL;
                                    char title[100];
                                    sprintf(title, "colonne%d", i);
                                    char *ptr_title = malloc(strlen(title) + 1);
                                    strcpy(ptr_title, title);
                                    nouveau->COLUMN = create_column(ptr_title);
                                    insert_value(nouveau->COLUMN, random);
                                    insert_value(nouveau->COLUMN, random + 1);
                                    insert_value(nouveau->COLUMN, random + 2);
                                    insert_value(nouveau->COLUMN, random + 3);
                                    insert_value(nouveau->COLUMN, random + 4);
                                    if (CDataframe == NULL) {
                                        CDataframe = nouveau;
                                    } else {
                                        maillon *tmp = CDataframe;
                                        while (tmp->SUCC != NULL) {
                                            tmp = (maillon *) tmp->SUCC;
                                        }
                                        tmp->SUCC = (struct mailllon *) nouveau;
                                    }
                                    random += 5;
                                }
                                printf("\n\n\n");
                                printf("======================================\n");
                                printf("|| CDataframe rempli avec succes... ||\n");
                                printf("======================================\n");
                            }
                            else {
                                init_CData();
                            }
                            break;

                        case '0':
                            categorie = 0;
                            break;

                    }

                }
            }


            case 2: {

                while (categorie == 2) {

                    for (int i = 0; i < 3; i++)
                        printf("\n");
                    printf("2. Affichage\n\n");
                    printf("\t 'a' - Afficher tout le CDataframe\n");
                    printf("\t 'b' - Afficher une partie des lignes du CDataframe selon une limite fournie par l utilisateur\n");
                    printf("\t 'c' - Afficher une partie des colonnes du CDataframe selon une limite fournie par l’utilisateur\n");
                    printf("\nChoisissez une fonctionnalite a, b ou c (pour revenir au menu tapez 0) :");
                    scanf(" %c", &fonction);

                    switch (fonction) {

                        case 'a':


                            if (init_CDataframe == 1) {
                                print_CData_chaine(CDataframe);
                            } else {
                                init_CData();
                            }
                            break;

                        case 'b':


                            if (init_CDataframe == 1) {
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
            }
                break;

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
                                printf("Choisir le numero de la colonne : ");
                                scanf(" %d", &column_number);
                                maillon *tmp;
                                if (CDataframe != NULL) {
                                    int i = 0;
                                    tmp = CDataframe;
                                    while (tmp != NULL && i < column_number - 1) {
                                        i++;
                                        tmp = (maillon *) tmp->SUCC;
                                    }
                                    if (tmp == NULL) {
                                        printf("La colonne n existe pas...");
                                    } else {
                                        int value;
                                        printf("Choisir une valeur a ajouter : ");
                                        scanf(" %d", &value);
                                        insert_value(tmp->COLUMN, value);
                                    }
                                }
                            } else {
                                init_CData();
                            }
                            break;

                        case 'b':


                            if (init_CDataframe == 1) {
                                maillon *tmp;
                                int column_number;
                                printf("Choisir le numero de la colonne : ");
                                scanf(" %d", &column_number);
                                if (CDataframe != NULL) {
                                    int i = 0;
                                    tmp = CDataframe;
                                    while (tmp != NULL && i < column_number - 1) {
                                        i++;
                                        tmp = (maillon *) tmp->SUCC;
                                    }
                                }
                                if (tmp == NULL) {
                                    printf("La colonne n existe pas...");
                                } else {
                                    delete_line(tmp->COLUMN);
                                }
                            } else {
                                init_CData();
                            }
                            break;


                        case 'c':


                            if (init_CDataframe == 1) {
                                maillon *tmp;
                                int column_position;
                                printf("Position du nouveau maillon (0: debut, x: postion de x et -1 : fin : ");
                                scanf(" %d", &column_position);
                                if (CDataframe != NULL) {
                                    maillon *nouveau = (maillon *) malloc(sizeof(maillon));
                                    char title[100];
                                    printf("Nom de la colonne : ");
                                    scanf(" %s", title);
                                    char *ptr_title = malloc(strlen(title) + 1);
                                    strcpy(ptr_title, title);
                                    nouveau->COLUMN = create_column(ptr_title);
                                    if (column_position == -1) {
                                        tmp = CDataframe;
                                        while (tmp->SUCC != NULL) {
                                            tmp = (maillon *) tmp->SUCC;
                                        }
                                        tmp->SUCC = (struct mailllon *) nouveau;
                                        nouveau->SUCC = NULL;
                                    }
                                    if (column_position == 0) {
                                        nouveau->SUCC = (struct mailllon *) CDataframe;
                                        CDataframe = nouveau;
                                    }
                                    if (column_position != 0 && column_position != -1) {
                                        int i = 0;
                                        tmp = CDataframe;
                                        while (tmp != NULL && i < column_position - 2) {
                                            i++;
                                            tmp = (maillon *) tmp->SUCC;
                                        }
                                    }
                                    if (tmp == NULL) {
                                        printf("La colonne n existe pas...");
                                    } else {
                                        nouveau->SUCC = tmp->SUCC;
                                        tmp->SUCC = (struct mailllon *) nouveau;
                                    }
                                }
                            } else {
                                init_CData();
                            }
                            break;


                        case 'd':


                            if (init_CDataframe == 1) {
                                maillon *tmp;
                                maillon *ptmp;
                                int column_position;
                                printf("Position du nouveau maillon a supprimer (0: debut, x: postion de x et -1 : fin : ");
                                scanf(" %d", &column_position);
                                if (CDataframe != NULL) {
                                    if (column_position == -1) {
                                        tmp = CDataframe;
                                        while (tmp->SUCC != NULL) {
                                            ptmp = tmp;
                                            tmp = (maillon *) tmp->SUCC;
                                        }
                                        free(tmp);
                                        ptmp->SUCC = NULL;
                                    }
                                    if (column_position == 0) {
                                        tmp = CDataframe;
                                        CDataframe = (maillon *) CDataframe->SUCC;
                                        delete_column(tmp->COLUMN);
                                        free(tmp);
                                    }
                                    if (column_position != 0 && column_position != -1) {
                                        int i = 0;
                                        tmp = CDataframe;
                                        while (tmp != NULL && i < column_position - 1) {
                                            i++;
                                            ptmp = tmp;
                                            tmp = (maillon *) tmp->SUCC;
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
                                printf("Choisir le numero de colonne : ");
                                scanf(" %d", &column_number);
                                maillon *tmp;
                                if (CDataframe != NULL) {
                                    int i = 0;
                                    tmp = CDataframe;
                                    while (tmp != NULL && i < column_number - 1) {
                                        i++;
                                        tmp = (maillon *) tmp->SUCC;
                                    }
                                }
                                if (tmp == NULL) {
                                    printf("La colonne n existe pas...");
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
                                maillon *tmp;
                                int presence = 0, value;
                                printf("Quelle est la valeur recherchee? : ");
                                scanf(" %d", &value);
                                if (CDataframe != NULL) {
                                    tmp = CDataframe;
                                    while (tmp != NULL && presence != 1) {
                                        if (value_research(tmp->COLUMN, value)) {
                                            presence = 1;
                                        }
                                        tmp = (maillon *) tmp->SUCC;
                                    }
                                }
                                if (presence == 1) {
                                    printf("La valeur est presente dans le CDataframe");
                                } else {
                                    printf("La valeur n'est pas present dans le CDataframe");
                                }
                            } else {
                                init_CData();
                            }
                            break;

                        case 'g':


                            if (init_CDataframe == 1) {
                                int column_number, line_number;
                                printf("Choisir le numero de colonne : ");
                                scanf(" %d", &column_number);
                                printf("Choisir le numero de la ligne : ");
                                scanf(" %d", &line_number);
                                maillon *tmp;
                                if (CDataframe != NULL) {
                                    int i = 0;
                                    tmp = CDataframe;
                                    while (tmp != NULL && i < column_number - 1) {
                                        i++;
                                        tmp = (maillon *) tmp->SUCC;
                                    }
                                }
                                if (tmp == NULL) {
                                    printf("La colonne n existe pas...");
                                } else {
                                    printf("La valeur a la ligne %d de la colonne %s [%d] est %d", line_number,
                                           tmp->COLUMN->CHAINE, column_number, tmp->COLUMN->DONNEES[line_number]);
                                    int value;
                                    printf("Voulez-vous la changer? (oui: 1/ non: 0) : ");
                                    scanf(" %d", &value);
                                    if (value) {
                                        printf("Choisir une valeur a ajouter : ");
                                        scanf(" %d", &value);
                                        tmp->COLUMN->DONNEES[line_number] = value;
                                    }
                                }
                            } else {
                                init_CData();
                            }
                            break;


                        case 'h':


                            if (init_CDataframe == 1) {
                                maillon *tmp;
                                if (CDataframe != NULL) {
                                    tmp = CDataframe;
                                    printf("%s ", tmp->COLUMN->CHAINE);
                                    tmp = (maillon *) tmp->SUCC;
                                    while (tmp != NULL) {
                                        printf("- %s ", tmp->COLUMN->CHAINE);
                                        tmp = (maillon *) tmp->SUCC;
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
                                maillon *tmp;
                                int value, occ = 0;
                                printf("Quelle est la valeur recherchee? : ");
                                scanf(" %d", &value);
                                if (CDataframe != NULL) {
                                    tmp = CDataframe;
                                    while (tmp != NULL) {
                                        if (value_research(tmp->COLUMN, value)) {
                                            occ++;
                                        }
                                        tmp = (maillon *) tmp->SUCC;
                                    }
                                }
                                printf("La valeur recherchee est presente dans %d cellule(s).", occ);
                            } else {
                                init_CData();
                            }
                            break;

                        case 'd':


                            if (init_CDataframe == 1) {
                                maillon *tmp;
                                int value, sup = 0;
                                printf("Quelle est la valeur recherchee? : ");
                                scanf(" %d", &value);
                                if (CDataframe != NULL) {
                                    tmp = CDataframe;
                                    while (tmp != NULL) {
                                        sup += sup_x(tmp->COLUMN, value);
                                        tmp = (maillon *) tmp->SUCC;
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
                                maillon *tmp;
                                int value, inf = 0;
                                printf("Quelle est la valeur recherchee? : ");
                                scanf(" %d", &value);
                                if (CDataframe != NULL) {
                                    tmp = CDataframe;
                                    while (tmp != NULL) {
                                        inf += inf_x(tmp->COLUMN, value);
                                        tmp = (maillon *) tmp->SUCC;
                                    }
                                }
                                printf("Le nombre de cellule contenant une valeur inferieur a %d est de %d.", value,
                                       inf);
                            } else {
                                init_CData();
                            }
                            break;


                        case '0':
                            categorie = 0;
                            break;

                    }

                }
            }
        }


    }

    return 0;
}