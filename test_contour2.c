#include <stdio.h>
#include "contour.h"
#include "geometrie2d.h"
#include "image.h"
 
// Ecriture de l'ensemble des points du contour de l'image du fichier donné en argument, dans un fichier .contour
 
int main(int argc, char **argv){
   
    if (argc < 3){
        printf("Ligne de commande : ./test_contour <fichier> <fichier> \n");
        return 1;
    }
 
    contour(argv[1],argv[2]);
}
