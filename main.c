#define REALOC_SIZE 256

typedef struct {
    char CHAINE[20];
    int TAILLE_PHYSIQUE;
    int TAILLE_LOGIQUE;
    int* DONNEES;
}COLUMN;
