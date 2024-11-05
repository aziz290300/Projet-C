

#define reclamation_H_INCLUDED
#include <gtk/gtk.h>
#include <stdio.h>

typedef struct{
char heure[20];
char minute[20];
} date;
typedef struct{
char id[20];
char type[20];
char list[20];
char bv[20];
char texte[20];
date d;
}reclamation ;
void ajouter_recl(reclamation r);
void afficher_reclamation(GtkWidget *liste);
