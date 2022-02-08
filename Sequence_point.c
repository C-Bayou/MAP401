#include "sequence_points.h"
 
Liste_Point creer_liste_Point_vide()
{
    Liste_Point L = {0, NULL, NULL};
    return L;
}
 
Cellule_Liste_Point *creer_element_liste_Point(Point v)
{
    Cellule_Liste_Point *el;
    el = (Cellule_Liste_Point *)malloc(sizeof(Cellule_Liste_Point));
    if (el==NULL)
    {
        fprintf(stderr, "creer_element_liste_Point : allocation impossible\n");
        exit(-1);
    }
    el->data = v;
    el->suiv = NULL;
    return el;
}
 
/* ajouter l'�l�ment e en fin de la liste L, renvoie la liste L modifi�e */
Liste_Point ajouter_element_liste_Point(Liste_Point L, Point e)
{
    Cellule_Liste_Point *el;
   
    el = creer_element_liste_Point(e);
    if (L.taille == 0)
    {
        /* premier �l�ment de la liste */
        L.first = L.last = el;
    }
    else
    {
        L.last->suiv = el;
        L.last = el;
    }
    L.taille++;
    return L;
}
 
Tableau_Point sequence_points_liste_vers_tableau(Liste_Point L)
{
    Tableau_Point T;
   
    /* taille de T = taille de L */
    T.taille = L.taille;
   
    /* allocation dynamique du tableau de Point */
    T.tab = malloc(sizeof(Point) * T.taille);
    if (T.tab == NULL)
    {
        /* allocation impossible : arret du programme avec un message */
        fprintf(stderr, "sequence_points_liste_vers_tableau : ");
        fprintf(stderr, " allocation impossible\n");
        exit(-1);
    }
   
    /* remplir le tableau de points T en parcourant la liste L */
    int k = 0; /* indice de l'�l�ment dans T.tab */
    Cellule_Liste_Point *el = L.first; /* pointeur sur l'�l�ment dans L */
    while (el)
    {
        T.tab[k] = el->data;
        k++; /* incr�menter k */
        el = el->suiv; /* passer � l'�lement suivant dans la liste chainee */
    }
   
    return T;
}
