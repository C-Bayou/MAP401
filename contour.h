#ifndef _CONTOUR_H_
#define _CONTOUR_H_
 
#include "geometrie2d.h"
#include "image.h"
 
typedef enum {Nord, Est, Sud, Ouest} Orientation;
 
// Renvoie le premier pixel noir dont le pixel au dessus de lui est blanc.
Point trouver_pixel_depart(Image I);
 
// Affiche la position du robot.
void memoriser_position(Point p);
 
// Avance le robot de 1.
void avancer(Point *p, Orientation o);
 
// Calcule la nouvelle orientation.
void nouvelle_orientation(Image I, Orientation *o, Point p);
 
// Tourne l'orientation du robot vers la droite.
void tourner_a_droite(Orientation *o);
 
// Tourne l'orientation du robot vers la gauche.
void tourner_a_gauche(Orientation *o);
 
#endif
