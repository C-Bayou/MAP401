#include <stdio.h>
#include "contour.h"
#include "geometrie2d.h"
#include "image.h"
 
 
// Algorithme permettant de déterminer le contour d'une image
 
int main(int argc, char **argv){
 
    Image I = lire_fichier_image(argv[1]);
    Point depart = trouver_pixel_depart(I);
    Point position = creer_point(depart.x - 1, depart.y - 1);
 
    Orientation o = Est;
    bool boucle = true;
    while (boucle){
        memoriser_position(position);
        avancer(&position,o);
        nouvelle_orientation(I,o,position);
        if ((position.x == depart.x - 1) && (position.y == depart.y - 1) && (o == Est)){
            boucle = false;
        }
    }
 
    memoriser_position(position);
}
