#include<stdio.h>
#include<stdlib.h>

// Defintion d'une cellule double
struct celluleDouble
{
    int element;
    struct celluleDouble * suivant;
    struct celluleDouble * precedent;
};
typedef struct celluleDouble celluleDouble;
// Fin de la definition d'une cellule double

// Defintion d'une liste doublement chainee
struct listeDouble
{
    celluleDouble * debut;
    celluleDouble * fin;
    unsigned longueur;
};
typedef struct listeDouble listeDouble;
// Fin de la definition d'une liste double

// Prototypes
int listeDoubleVide(listeDouble);
void affichageListeDouble(listeDouble);
void ajoutDebut(int, listeDouble *);
void ajoutFin(int,listeDouble *);
void suppressionDebut(listeDouble *);
void suppressionFin(listeDouble *);
void libererListeDouble(listeDouble);

/************************ Implementation des fonctions ***********************/

// La fonction test_vide_listeDouble

int listeDoubleVide(listeDouble L)
{
    if(L.debut==NULL)
        return 1;
    return 0;
}

// La fonction affichage

void affichageListeDouble(listeDouble L)
{
    /* Si la liste est vide */
    if(listeDoubleVide(L)==1)
    {
        printf("[]\n");
        // On sort de la fonction
        return;
    }
    /* On continue si la liste st non vide */
    celluleDouble *temp=L.debut;
    printf("[");
    while(temp->suivant!=NULL)
    {
        printf("%d, ",temp->element);
        temp=temp->suivant;
    }
    if(temp!=NULL)
        printf("%d",temp->element);
    printf("]\n");
}


// La fonction ajourDebut()

void ajoutDebut(int x,listeDouble * L)
{
    /* Declaration et initialisation de la cellue a ajouter */
    celluleDouble * C=(celluleDouble *)malloc(sizeof(celluleDouble));
    C->element=x;
    C->suivant=L->debut;
    C->precedent=NULL;
    /* Fin initialisation de la cellule double */
    
    /* Cas ou la liste L est vide */
    if(listeDoubleVide(*L)==1)
    {
        L->debut=C;
        L->fin=C;
        L->longueur=1;
        return;
    }
    /* Si la liste L n'est pas vide */
    L->debut->precedent=C;
    L->debut=C;
    L->longueur+=1;
    return;
}

// La fonction ajourFin()

void ajoutFin(int x,listeDouble *L)
{
    /** Declaration et initialisation de la cellue a ajouter **/
    celluleDouble * C=(celluleDouble *)malloc(sizeof(celluleDouble));
    C->element=x;
    C->precedent=L->fin;
    C->suivant=NULL;
    /** Fin initialisation de la cellule double **/
    
    /* Si la liste L est vide on ajoute au debut */
    if(listeDoubleVide(*L)==1)
    {
        ajoutDebut(x,L);
        return;
    }
    /* Si la liste n'est pas vide */
    L->fin->suivant=C;
    L->fin=C;
    L->longueur+=1;
    return;
}

// La fonction suppressionDebut()
void suppressionDebut(listeDouble * L)
{
    /* Cas d'une liste vide */
    if(listeDoubleVide(*L)==1)
        return;
    /* Cas d'une liste a un seul element */
    if(L->longueur==1)
    {
        L->longueur=0;
        if(L->debut!=NULL)
            free(L->debut);
        L->debut=NULL;
        return;
    }
    /* declaration d'un pointeur temporaire vers la premiere celluleDouble */
    celluleDouble * temp=L->debut;
    /* Deplacement du debut de la liste vers la celluleDouble suivante */
    L->debut=L->debut->suivant;
    L->longueur-=1;
    /* Liberation de la premiere celluleDouble*/
    free(temp);
    return;
}

// La fonction suppressionFin()

void suppressionFin(listeDouble * L)
{
    if(listeDoubleVide(*L)==1)
        return;
    /* Cas d'une liste a un seul element */
    if(L->longueur==1)
    {
        suppressionDebut(L);
        return;
    }
    /* declaration d'un pointeur temporaire vers la derniere celluleDouble */
    celluleDouble * temp=L->fin;
    /* Deplacement de la fin de la liste vers la celluleDouble precedente */
    L->fin=L->fin->precedent;
    L->fin->suivant=NULL;
    L->longueur-=1;
    free(temp);
    return;
}

// La fonction librer

void libererListeDouble(listeDouble L)
{
    while(L.debut!=NULL)
    {
        celluleDouble * temp=L.debut;
        L.debut=L.debut->suivant;
        free(temp);
    }
}


void sort_list(listeDouble* P){
    int i,j,k;
    listeDouble temp=*P, temp2=*P;
    while(temp.debut->suivant!=NULL){
        while(temp2.debut->suivant!=NULL){
            if(temp.debut->element>temp2.debut->suivant->element){
                k=temp.debut->element;
                temp.debut->element=temp2.debut->suivant->element;
                temp2.debut->suivant->element=k;
            }
            temp2.debut=temp2.debut->suivant;
        }
        temp.debut=temp.debut->suivant;
        temp2=temp;
    }
    return;
}

void merge_lists(listeDouble* P,listeDouble * L){
    listeDouble temp=*P;
    temp.fin->suivant=(*L).debut;
    return;
}

void remove_duplicated(listeDouble* L){
    listeDouble temp=*L;
    listeDouble temp2=*L;
    while(temp.debut->suivant!=NULL){
        if(temp.debut->element==temp.debut->suivant->element){
            if(temp.debut->suivant->suivant==NULL){
                temp2.debut=temp.debut;
                temp.debut->suivant=NULL;
                temp2.debut=temp2.debut->suivant;
                free(temp2.debut);
                return;
            }
            else{
                temp2.debut=temp.debut;
                temp2.debut=temp2.debut->suivant;
                temp.debut->suivant=temp.debut->suivant->suivant;
                temp2.debut->suivant=NULL;
                free(temp2.debut);
            }
        }
        else{
            temp.debut=temp.debut->suivant;
        }
    }
}

int Randoms(int lower, int upper)
{
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}
  

int main(){
    listeDouble P={NULL,NULL,0};
    listeDouble L={NULL,NULL,0};
    srand(time(0));
    for (int i=0;i<100;i++){
        ajoutDebut(Randoms(0,40),&P);
    }
    printf("List P: ");
    affichageListeDouble(P);
    for (int i=0;i<30;i++){
        ajoutDebut(Randoms(0,40),&L);
    }
    printf("List L: ");
    affichageListeDouble(L);
    merge_lists(&P,&L);
    printf("List P merged with L: ");
    affichageListeDouble(P);
    sort_list(&P);
    printf("List P: ");
    affichageListeDouble(P);
    remove_duplicated(&P);
    printf("List P without doubles: ");
    affichageListeDouble(P);
    libererListeDouble(P);
    return 0;
}
