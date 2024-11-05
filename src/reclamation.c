#ifdef HAVE_CONFIG_H
#include<config.h>
#endif

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<gtk/gtk.h>
#include "reclamation.h"
enum
{
	Rid,
	Rtype,
	Rlist,
	Rbv,
	Rtexte,
	Rheure,
	Rminute,
	COLUMNS,
};
void ajouter_recl(reclamation r)
{

    FILE * f=fopen("reclamation.txt","a+");
    if(f!=NULL)
    {

	fprintf(f,"%s %s %s %s %s %s %s\n",r.id,r.type,r.list,r.bv,r.texte,r.d.heure,r.d.minute);
        fclose(f);
    }
}
void afficher_reclamation(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	char id[20];
	char type[20];
	char list[20];
	char bv[20];
	char texte[20];
	char heure[20];
	char minute[20];
	

	store=NULL;
	FILE* f=NULL;
	store=gtk_tree_view_get_model(liste);
	if(store==NULL)
	{
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("id", renderer, "text", Rid , NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("type", renderer, "text", Rtype , NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("list", renderer, "text", Rlist , NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("bv", renderer, "text", Rbv , NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("texte", renderer, "text", Rtexte, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("heure", renderer, "text", Rheure , NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
        renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("minute", renderer, "text", Rminute , NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}
store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

	f=fopen("reclamation.txt","r");
	if(f==NULL)
	{return;
	}	
	else 
	{
		f=fopen("reclamation.txt","a+");
			while(fscanf(f,"%s %s %s %s %s %s %s\n",id,type,list,bv,texte,heure,minute)!=EOF)
			{	
			gtk_list_store_append(store, &iter);
			gtk_list_store_set(store, &iter, Rid, id, Rtype, type, Rlist,list,Rbv, bv, Rtexte,texte, Rheure, heure, Rminute, minute, -1);
			}
	fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	g_object_unref(store);
	}
}
