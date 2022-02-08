#include "image.h"
#include "types_macros.h"




int main (int argc, char ** argv){
    Image P1,P2;
    UINT H,L;
    if (argc < 2){
        printf("Usage %s : <Image>", argv[0]);
    }
    H= 9;
    L= 7;
    P1= creer_image(L, H);
    P2= creer_image(L, H);
    P1= lire_fichier_image(argv[1]);
    P2= negatif_image (P1);
    ecrire_image(P2); //on peut vérifier le négatif de l'image P1 en ouvrant le fichier test_image.pbm
    supprimer_image(&P1);

}



