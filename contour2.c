#include <stdio.h>
#include "contour.h"
#include "image.h"
#include "geometrie2d.h"
#include "sequence_points.h"
 
Point trouver_pixel_depart(Image I){
    Point depart = creer_point(1,1);
    Orientation o = Est;
    double L = largeur_image(I);
 
    while (!((get_pixel_image(I, depart.x, depart.y) == NOIR) && (get_pixel_image(I, depart.x, (depart.y) - 1) == BLANC))){
        if (depart.x <= L){
            avancer(&depart,o);
        }
        else{
            depart = creer_point(1, depart.y+1);
        }
    }
    return depart;
}
 
Liste_Point memoriser_position(Liste_Point L, Point p){
    return ajouter_element_liste_Point(L,p);
}
 
void avancer(Point *p, Orientation o){
    switch(o){
        case Nord:
            p->y--;
            break;
        case Sud:
            p->y++;
            break;
        case Ouest:
            p->x--;
            break;
        case Est:
            p->x++;
            break;
    }
}
 
void tourner_a_gauche(Orientation *o){
    switch(*o){
        case Nord:
            *o = Ouest;
            break;
        case Sud:
            *o = Est;
            break;
        case Est:
            *o = Nord;
            break;
        case Ouest:
            *o = Sud;
            break;
    }
}
 
void tourner_a_droite(Orientation *o){
    switch(*o){
        case Nord:
            *o = Est;
            break;
        case Sud:
            *o = Ouest;
            break;
        case Est:
            *o = Sud;
            break;
        case Ouest:
            *o = Nord;
            break;
    }
}
 
void affiche_o(Orientation o){
    switch(o){
        case Nord:
            printf("NORD\n");
            break;
        case Est:
            printf("EST\n");
            break;
        case Ouest:
            printf("OUEST\n");
            break;
        case Sud:
            printf("SUD\n");
            break;
    }
}
 
 
 
void nouvelle_orientation(Image I, Orientation *o, Point p){
    Pixel pG;
    Pixel pD;
 
    switch(*o){
        case Nord:
            pG = get_pixel_image(I, p.x, p.y);
            pD = get_pixel_image(I, p.x+1, p.y);
            break;
        case Sud:
            pG = get_pixel_image(I, p.x+1, p.y+1);
            pD = get_pixel_image(I, p.x, p.y+1);
            break;
        case Est:
            pG = get_pixel_image(I, p.x+1, p.y);
            pD = get_pixel_image(I, p.x+1, p.y+1);
            break;
        case Ouest:
            pG = get_pixel_image(I, p.x, p.y+1);
            pD = get_pixel_image(I, p.x, p.y);
            break;
    }
 
    if (pG == NOIR){
        tourner_a_gauche(o);
    }
    else if (pD == BLANC){
        tourner_a_droite(o);
    }
}
 
void ecrire_contour_file(Liste_Point L, char *sortie){
    FILE *f = fopen(sortie,"w");
 
    Point p;
    int n = 1;
    int contour = L.taille + 1; // nombre de segments
    fprintf(f,"%d\n\n", n);
    fprintf(f,"%d\n", contour);
 
    Tableau_Point t = sequence_points_liste_vers_tableau(L);
 
    for (int k = 0; k < contour; k++){
        p = t.tab[k];
        fprintf(f," %.1f %.1f\n", p.x, p.y);
    }
 
    fclose(f);
}
 
// Algorithme permettant de d??terminer le contour d'une image, et de stocker le contour dans une s??quence de points
 
void contour(char *filename, char *sortie){
    Liste_Point L = creer_liste_Point_vide();
 
    Image I = lire_fichier_image(filename);
    Point depart = trouver_pixel_depart(I);
    Point position = creer_point(depart.x - 1, depart.y - 1);
    Orientation o = Est;
    bool boucle = true;
    while (boucle){
        L = memoriser_position(L,position);
        avancer(&position,o);
        nouvelle_orientation(I,&o,position);
        if ((position.x == depart.x - 1) && (position.y == depart.y - 1) && (o == Est)){
            boucle = false;
        }
    }
 
    memoriser_position(L,position);
 
    // ??criture du contour dans un fichier texte
 
    ecrire_contour_file(L,sortie);
 
}
