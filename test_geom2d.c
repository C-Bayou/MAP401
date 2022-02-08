
#include "geometrie2d.h"
#include <stdio.h>

int main (int argc, char **argv) {
    double x1,y1,x2,y2,N,r,P_S;
    Point P1, P2, S1;
    Vecteur V1, V2, V3, S2, P_V, P_P;
    if (argc < 1){
        printf("Usage %s : <fichier_test>", argv[0]);
    }

    FILE *f= fopen(argv[1], "r");
    fscanf(f, "%lf", &x1);
    fscanf(f, "\n%lf", &y1);
    fscanf(f, "\n\n%lf", &x2);
    fscanf(f, "\n\n\n%lf", &y2);

    P1 = creer_point(x1, y1);
    P2 = creer_point(x2, y2);
    V1 = creer_vecteur(x1, y1);
    V2 = creer_vecteur(x2, y2);

    //Récupération du résultat dans le fichier test :
    fscanf(f, "\n\n\n\n%lf", &V3.x);
    fscanf(f, "\n\n\n\n\n%lf", &V3.y);
    fscanf(f, "\n\n\n\n\n\n%lf", &S1.x);
    fscanf(f, "\n\n\n\n\n\n\n%lf", &S1.y);
    fscanf(f, "\n\n\n\n\n\n\n\n%lf", &S2.x);
    fscanf(f, "\n\n\n\n\n\n\n\n\n%lf", &S2.y);
    fscanf(f, "\n\n\n\n\n\n\n\n\n\n%lf", &P_V.x);
    fscanf(f, "\n\n\n\n\n\n\n\n\n\n\n%lf", &P_V.y);
    fscanf(f, "\n\n\n\n\n\n\n\n\n\n\n\n%lf", &P_P.x);
    fscanf(f, "\n\n\n\n\n\n\n\n\n\n\n\n\n%lf", &P_P.y);
    fscanf(f, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n%lf", &P_S);
    fscanf(f, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n%lf", &N);
    fscanf(f, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n%lf", &r);

    
    
    if (vect_bipoint(P1,P2).x != V3.x || vect_bipoint(P1,P2).y != V3.y){
        printf("ERREUR_FONCTION_VECT_BIPOINT\n");
    }
    else if (somme_point(P1,P2).x != S1.x || somme_point(P1,P2).y != S1.y){
        printf("ERREUR_FONCTION_SOMME_POINT\n");
    }
    else if (somme_vecteur(V1,V2).x != S2.x || somme_vecteur(V1,V2).y != S2.y){
        printf("ERREUR_FONCTION_SOMME_VECTEUR\n");
    }
    else if (produit_vecteur(V1,r).x != P_V.x || produit_vecteur(V1,r).y != P_V.y){
        printf("ERREUR_FONCTION_PRODUIT_VECTEUR\n");
    }
    else if (produit_point(P2,r).x != P_P.x || produit_point(P2,r).y != P_P.y){
        printf("ERREUR_FONCTION_PRODUIT_POINT\n");
    }
    else if (produit_scalaire(V1, V2) != P_S){
        printf("ERREUR_FONCTION_PRODUIT_SCALAIRE\n");
    }
    else if (norme(V1) != N){
        printf("ERREUR_FONCTION_NORME\n");
    }
    else{
        printf("TOUS LES TESTS OK\n");
    } 

} 