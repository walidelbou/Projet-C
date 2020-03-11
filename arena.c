#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int main(int argc,char**argv){


int pv_initJ1=10, pv_initM1=10, DE=0, J1=0, M1=0, tour=1, MAX=6, MIN=1, joueur_init=0,joueur_actuel=0, monstre_init=0, commencer_aleatoire=0, DE2=0, MAX2=2,MIN2=1;

    srand(time(NULL));



    printf("---Bienvenue dans l'AREEEEEENE---\n");
    printf("Joueur 1, entrez votre nombre\n");
    scanf("%d",&J1);
    printf("Monstre lvl 1, entrez votre nombre\n");
    scanf("%d",&M1);

    printf("Tour: %d\n",tour);

    printf("Point de vie initial du joueur :%d\n",pv_initJ1);
    printf("Point de vie initial du Monstre 1:%d\n",pv_initM1);

    /*printf("---Lancer de DE aleatoire---\n");
    DE2=(rand()%(MAX2-MIN2+1))+MIN2;

    if(DE2=1)
    */{

    printf("C'est %d (joueur 1) qui commence\n",J1);
    joueur_init=J1;

    /*}else if(DE2=2){
    printf("C'est %d (monstre lvl 1) qui commence\n",M1);
    Monstre_init=M1;
    */}


    while(pv_initM1>0 || pv_initJ1>0){


        if(joueur_init=J1){
            DE=(rand()% (MAX-MIN+1))+MIN;
            printf("%d POINT(S) EN MOINS POUR J2\n",DE);
            pv_initM1=pv_initM1-DE;
            printf("M1 Il vous reste %d points\n",pv_initM1);


            Monstre_init=M1;

        }else if(Monstre_init=M1){
            DE=(rand()% (MAX-MIN+1))+MIN;
            printf("%d POINT(S) EN MOINS POUR J1\n",DE);
            pv_initJ1=pv_initJ1-DE;
            printf("J1 Il vous reste %d points\n",pv_initJ1);


            joueur_init=J1;
        }
    tour++;
    }


    if(pv_initM1=0 && pv_initM1>pv_initJ1){
        printf("M1 a GAGNE");
    }else if(pv_initJ1=0 && pv_initJ1>pv_initM1){
        printf("J1 a GAGNE");
    }





return 0;
}
