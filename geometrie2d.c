#include <stdio.h>
#include <math.h>
#include "geometrie2d.h"
 
Point creer_point(double x, double y){
    Point P = {x,y};
    return P;
}
 
Vecteur creer_vecteur(double x, double y){
    Vecteur V = {x,y};
    return V;
}
 
Vecteur vect_bipoint(Point A, Point B){
    return creer_vecteur((B.x - A.x), (B.y - A.y));
}
 
Point somme_point(Point P1, Point P2){
    return creer_point((P1.x)+(P2.x), (P1.y)+(P2.y));
}
 
Vecteur somme_vecteur(Vecteur A, Vecteur B){
    return creer_vecteur((A.x + B.x),(A.y + B.y));
}
 
Vecteur produit_vecteur(Vecteur A, double r){
    return creer_vecteur((r*A.x),(r*A.y));
}
 
Point produit_point(Point A, double r){
    return creer_point((r*A.x),(r*A.y));
}
 
double produit_scalaire(Vecteur A, Vecteur B){
    return (A.x)*(B.x) + (A.y)*(B.y);
}
 
double norme(Vecteur A){
    return sqrt((A.x)*(A.x) + (A.y)*(A.y));
}