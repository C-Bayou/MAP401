#include <stdio.h>
#include "contour.h"
#include "image.h"
#include "geometrie2d.h"
#include "image.c"
 
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
 
void memoriser_position(Point p){
    printf("(%.1f,%.1f)\n", p.x, p.y);
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