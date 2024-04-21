#include <stdio.h>
#include "column.h"
#include <stdlib.h>
#include <string.h>


int main(){
    int running = 1;
///    char title[20];
///    char* ptr_title;
///    printf("Choisir un nom de colonne : ");
///    scanf(" %s", title);
///    ptr_title = title;
///    COLUMN* ptr_colonne = create_column(ptr_title);
///    int val;
///    printf("Choisir une valeur : ");
///    scanf("%d", &val);
///    if (insert_value(ptr_colonne, val)) {
///        printf("Value added successfully to my column\n");
///    }
///    else
///        printf("Error adding value to my column\n");

///    insert_value(ptr_colonne, 7);
///    insert_value(ptr_colonne, 5);
///    insert_value(ptr_colonne, 9);
///    insert_value(ptr_colonne, 7);
///    insert_value(ptr_colonne, 9);
///    insert_value(ptr_colonne, 187);
///    insert_value(ptr_colonne, 7);
///    print_col(ptr_colonne);
///    printf("\n%d", occurence(ptr_colonne, 9));
///    printf("\n%d",positionx(ptr_colonne, 2));
///    printf("\n%d", sup_x(ptr_colonne, 8));
///    printf("\n%d", inf_x(ptr_colonne, 8));
///    delete_column(&ptr_colonne);



    // Création du CDataframe (version tableau de Colonne)
//    COLUMN** CDataframe = NULL;
//    int nbre_col;
//    printf("Nombre de colonne du CDataframe? :");
//    scanf(" %d", &nbre_col);

//    CDataframe = (COLUMN**)malloc(sizeof(COLUMN*));



    // Remplir le CDataframe par saisies utilisateur
//    for (int CData_column = 0; CData_column < nbre_col; CData_column++) {
//        char title[100] = "";
//        char* ptr_title = malloc(strlen(title) + 1);
//        printf("\nNom de la colonne numero %d :", CData_column);
//        scanf(" %s", title);
//        strcpy(ptr_title, title);
//        CDataframe[CData_column] = create_column(ptr_title);
//    }



//    for (int CData_column = 0; CData_column < nbre_col; CData_column++) {
//        int nbre_valeur;
//        printf("Combien de valeurs dans la colonne %d nommee %s: ", CData_column, CDataframe[CData_column]->CHAINE);
//        scanf(" %d", &nbre_valeur);
//        for (int column_line = 0; column_line<nbre_valeur; column_line++) {
//            int val;
//            printf("La valeur %d de la colonne %s : ", column_line, CDataframe[CData_column]->CHAINE);
//            scanf(" %d", &val),
//            insert_value(CDataframe[CData_column], val);
//       }
//        print_col(CDataframe[CData_column]);
//    }



    // Affichage du CDataframe
//    print_CData(CDataframe, nbre_col);
//    printf("\n\n");
//    add_line(CDataframe, nbre_col);
//    print_CData(CDataframe, nbre_col);

//    rename_columns_name(CDataframe, nbre_col);
//    print_CData(CDataframe, nbre_col);

//    value_research(CDataframe, nbre_col, 3);

//    print_lines(CDataframe, nbre_col);

//    printf(" %d", equal_x(CDataframe, nbre_col));
//    printf(" %d", CData_inf_x(CDataframe, nbre_col));
//    printf(" %d", CData_sup_x(CDataframe, nbre_col));

//    for (int CData_column; CData_column < nbre_col; CData_column++) {
//        delete_column(&CDataframe[CData_column]);
//    }



maillon *CDataframe = NULL;

int init_CDataframe = 0;


while (running == 1) {

    menu();



    int categorie;
    printf("_______________________________________________\n\n");
    printf("Choississez parmi les categories ci-dessus (entrez le numero de la categorie choisie 1-4) : ");
    scanf(" %d", &categorie);


    char fonction;

    switch (categorie) {


        case 1 : {

            while(categorie ==1) {

            for(int i = 0; i<3; i++)
                printf("\n");
            printf("1. Alimentation\n\n");
            printf("\t 'a' - Creation du CDataframe vide\n");
            printf("\t 'b' - Remplissage du CDataframe a partir de saisies utilisateurs\n");
            printf("\t 'c' - Remplissage en dur du CDataframe (utilise un CDataframe prerempli pour le reste des fonctionnalites)\n");
            printf("\nChoisissez une fonctionnalite a, b ou c (pour revenir au menu tapez 0) :");
            scanf(" %c", &fonction);

            switch (fonction) {

                case 'a':
                    if(init_CDataframe == 0) {
                        // Création du CDataframe (sous forme de liste chainée)
                        CDataframe = NULL;
                        for(int i = 0; i<3; i++)
                            printf("\n");
                        printf("CDataframe cree avec succes...");
                        init_CDataframe = 1;
                    }
                    else {
                        int answer;
                        printf("Un CDataframe a deja ete cree, voulez-vous en creer un nouveau? Tapez 1 pour oui et 0 pour non (oui effacera le CDataframe actuel) : ");
                        scanf(" %d", &answer);
                        if(answer == 1) {
                            CDataframe = NULL;
                            for(int i = 0; i<3; i++)
                                printf("\n");
                            printf("Nouveau CDataframe cree avec succes...");
                        }
                        else {
                            for(int i = 0; i<3; i++)
                                printf("\n");
                            printf("Annulation...");
                        }
                    }

                    break;

                case 'b':


                    if(init_CDataframe == 1) {
                        int nbre_col;
                        for(int i = 0; i<3; i++)
                            printf("\n");
                        printf("Choisir le nombre de colonne du CDataframe (ce nombre pourra être modifie plus tard) :");
                        scanf(" %d", &nbre_col);
                        for(int i = 0; i<3; i++)
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
                            for(int i = 0; i<3; i++)
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
                    }
                    else {
                        printf("Il faut initialiser le CDataframe...");
                    }
                    break;



                case 'c':


                    if(init_CDataframe == 1) {
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
                    }
                    else {
                        printf("Il faut initialiser le CDataframe...");
                    }
                    break;

                case '0':
                    categorie = 0;
                    break;

            }

            }
        }



        case 2: {

            while(categorie ==2) {

                for(int i = 0; i<3; i++)
                    printf("\n");
                printf("2. Affichage\n\n");
                printf("\t 'a' - Afficher tout le CDataframe\n");
                printf("\t 'b' - Afficher une partie des lignes du CDataframe selon une limite fournie par l utilisateur\n");
                printf("\t 'c' - Afficher une partie des colonnes du CDataframe selon une limite fournie par l’utilisateur\n");
                printf("\nChoisissez une fonctionnalite a, b ou c (pour revenir au menu tapez 0) :");
                scanf(" %c", &fonction);

                switch (fonction) {

                    case 'a':


                        if(init_CDataframe == 1) {
                            print_CData_chaine(CDataframe);
                        }
                        else {
                            printf("Il faut initialiser le CDataframe...");
                        }
                        break;

                    case 'b':


                        if(init_CDataframe == 1) {
                            print_CData_selected_lines(CDataframe);
                        }
                        else {
                            printf("Il faut initialiser le CDataframe...");
                        }
                        break;



                    case 'c':


                        if(init_CDataframe == 1) {
                            print_CData_selected_column(CDataframe);
                        }
                        else {
                            printf("Il faut initialiser le CDataframe...");
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
            break;
        }
        case 4: {

            while(categorie ==4) {

                for(int i = 0; i<3; i++)
                    printf("\n");
                printf("4. Analyse et statistiques\n\n");
                printf("\t 'a' - Afficher le nombre de lignes\n");
                printf("\t 'b' - Afficher le nombre de colonnes\n");
                printf("\t 'c' - Nombre de cellules contenant une valeur egale a x (x donné en parametre)\n");
                printf("\t 'd' - Nombre de cellules contenant une valeur superieure a x (x donné en parametre)\n");
                printf("\t 'e' - Nombre de cellules contenant une valeur inferieure a x(x donné en parametre)\n");
                printf("\nChoisissez une fonctionnalite a, b ou c (pour revenir au menu tapez 0) :");
                scanf(" %c", &fonction);

                switch (fonction) {

                    case 'a':


                        if(init_CDataframe == 1) {
                            print_CData_number_lines(CDataframe);
                        }
                        else {
                            printf("Il faut initialiser le CDataframe...");
                        }
                        break;

                    case 'b':


                        if(init_CDataframe == 1) {
                            print_CData_number_column(CDataframe);
                        }
                        else {
                            printf("Il faut initialiser le CDataframe...");
                        }
                        break;



                    case 'c':


                        if(init_CDataframe == 1) {
                            maillon* tmp ;
                            int value, occ =0;
                            printf("Quelle est la valeur recherchee? : ");
                            scanf(" %d", &value);
                            if (CDataframe != NULL)
                            {
                                tmp = CDataframe;
                                while(tmp != NULL)
                                {
                                    if(value_research(tmp->COLUMN, value)) {
                                        occ++;
                                    }
                                    tmp = (maillon *) tmp->SUCC;
                                }
                            }
                            printf("La valeur recherchee est presente dans %d cellule(s).", occ);
                        }
                        else {
                            printf("Il faut initialiser le CDataframe...");
                        }
                        break;

                    case 'd':


                        if(init_CDataframe == 1) {
                            maillon* tmp ;
                            int value, sup =0;
                            printf("Quelle est la valeur recherchee? : ");
                            scanf(" %d", &value);
                            if (CDataframe != NULL)
                            {
                                tmp = CDataframe;
                                while(tmp != NULL)
                                {
                                    sup += sup_x(tmp->COLUMN, value);
                                    tmp = (maillon *) tmp->SUCC;
                                }
                            }
                            printf("Le nombre de cellule contenant une valeur superieur a %d est de %d.", value, sup);
                        }
                        else {
                            printf("Il faut initialiser le CDataframe...");
                        }
                        break;

                    case 'e':


                        if(init_CDataframe == 1) {
                            maillon* tmp ;
                            int value, inf =0;
                            printf("Quelle est la valeur recherchee? : ");
                            scanf(" %d", &value);
                            if (CDataframe != NULL)
                            {
                                tmp = CDataframe;
                                while(tmp != NULL)
                                {
                                    inf += inf_x(tmp->COLUMN, value);
                                    tmp = (maillon *) tmp->SUCC;
                                }
                            }
                            printf("Le nombre de cellule contenant une valeur inferieur a %d est de %d.", value, inf);
                        }
                        else {
                            printf("Il faut initialiser le CDataframe...");
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





while(running == 0) {
// Création du CDataframe (sous forme de liste chainée)
    maillon *CDataframe = NULL;
    int nbre_col;
    printf("Nombre de colonne du CDataframe? :");
    scanf(" %d", &nbre_col);


    maillon *tmp;

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
        insert_value(nouveau->COLUMN, 3);
        insert_value(nouveau->COLUMN, 4);
        insert_value(nouveau->COLUMN, 8);
        insert_value(nouveau->COLUMN, 5);
        insert_value(nouveau->COLUMN, 7);
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
    print_CData_chaine(CDataframe);

    print_CData_selected_column(CDataframe);
    printf("\n---------------------------\n");
    print_CData_selected_lines(CDataframe);
    free(CDataframe);

}
    return 0;
}



