#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif
#include <gtk/gtk.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "reclamation.h"
#include <string.h>


int cocher[0]={0};
void
on_afficher_clicked                    (GtkWidget      *objet,
                                        gpointer         user_data)
{

	GtkWidget *ajouter_reclamation, *affichage ,*list_aff;

	ajouter_reclamation=lookup_widget(objet,"ajouter_reclamation");
	gtk_widget_destroy(ajouter_reclamation);

	affichage=lookup_widget(objet,"affichage");
	affichage=create_affichage();
	gtk_widget_show(affichage);
list_aff=lookup_widget(affichage,"list_aff");
afficher_reclamation(list_aff);
}


void
on_ajouter_clicked                     (GtkWidget      *objet,
                                        gpointer         user_data)
{
char id[50];
char type[50];
char list[50];
char bv[50];
char texte[50];
char heure[50];
char minute[50];
int h=0 , m=0;
 reclamation r;

GtkWidget *input1, *input2, *input3, *input4, *input5, *input6, *input7, *input8,*input9;
	GtkWidget *ajouter_reclamation;
	GdkColor color;
ajouter_reclamation=lookup_widget(objet,"ajouter_reclamation");
	
	input1=lookup_widget(objet,"idajout");
	input2=lookup_widget(objet,"type_ajout");
	input3=lookup_widget(objet,"liste_ajout");
	input4=lookup_widget(objet,"bv_ajout");
	input5=lookup_widget(objet,"reclam_ajout");
	input6=lookup_widget(objet,"h_ajout");
	input7=lookup_widget(objet,"m_ajout");
        input8=lookup_widget(objet,"label8");
        input9=lookup_widget(objet,"alerte");

	strcpy(r.id,gtk_entry_get_text(GTK_ENTRY(input1)));
	strcpy(r.texte,gtk_entry_get_text(GTK_ENTRY(input5)));

       h=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input6));
	sprintf(heure,"%d",h);                                               
       m=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input7));
	sprintf(minute,"%d",m); 

strcpy(r.d.heure,heure);
strcpy(r.d.minute,minute);
	
strcpy(r.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input2)));
strcpy(r.list,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input3)));
strcpy(r.bv,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input4)));

if(cocher[0]==1)
	{
	gdk_color_parse("green",&color);
	gtk_widget_modify_fg(input8,GTK_STATE_NORMAL,&color);
	gtk_label_set_text(GTK_LABEL(input9),"Succée de l'ajout");

	ajouter_recl(r);
	
	cocher[0]=0;
			
      	}
	else 
	{
	gdk_color_parse("red",&color);
	gtk_widget_modify_fg(input8,GTK_STATE_NORMAL,&color);
	gtk_label_set_text(GTK_LABEL(input9),"ajout échouée");
	}
                           
}


void
on_annuler_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_actualiseraff_clicked               (GtkWidget      *objet,
                                        gpointer         user_data)
{

}


void
on_annuleraff_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_retouraff_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *ajouter_reclamation, *affichage ;
affichage=lookup_widget(objet,"affichage");

	gtk_widget_destroy(affichage);

		ajouter_reclamation=lookup_widget(objet,"ajouter_reclamation");
	ajouter_reclamation=create_ajouter_reclamation();
	gtk_widget_show(ajouter_reclamation);
}




void
on_label8_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
	{
		cocher[0]=1;
	}

}

