#ifndef _GEOMETRIE2D_H_
#define _GEOMETRIE2D_H_
 
typedef struct Vecteur_ {
    double x,y; /* coordonnées */
} Vecteur;
 
typedef struct Point_ {
    double x,y; /* coordonnées */
} Point;
 
/* Crée le point de coordonnées (x,y) */
Point creer_point(double x, double y);
 
/* Crée le vecteur de coordonnées (x,y) */
Vecteur creer_vecteur(double x, double y);
 
/* Vecteur correspondant au bipoint AB */
Vecteur vect_bipoint(Point A, Point B);
 
/* Somme de deux points P1 et P2 */
Point somme_point(Point P1, Point P2);
 
/* Somme de deux vecteurs A et B */
Vecteur somme_vecteur(Vecteur A, Vecteur B);
 
/* Produit du réel r par le vecteur A */
Vecteur produit_vecteur(Vecteur A, double r);
 
/* Produit du réel r par le point A */
Point produit_point(Point A, double r);
 
/* Produit scalaire de A et B */
double produit_scalaire(Vecteur A, Vecteur B);
 
/* Norme du vecteur A */
double norme(Vecteur A);
#endif
