#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/****--Structure Pour Les Infos de L'Etudiant--****/
typedef struct Etudiant {
    /* data */
    char nom[20];
    char prenom[20];
    char matricule[4];
    float moyenne;
}etudiant;

/****--Structure Pour Les Infos de Projet--****/
typedef struct Projet {
    /* data */
    char theme[20];
    int diff;
    char etudiant1[4]; //L'Etudiant 1 affecté dans le projet par Matricule
    char etudiant2[4]; //L'Etudiant 2 affecté dans le projet par Matricule
}projet;
/*******************************************/


/***---Fonction Pour ajouter des etudiants---***/
int AddEtudiant(int nmbEtudiant)
{
    int rows;

    struct Etudiant TabEtud[nmbEtudiant]; // Tableau Pour les Etudiant


    /* Loop Pour Remplire les Informations de l'etudiant */
    for (rows=0; rows < nmbEtudiant; rows++)
    {
        printf("\t--> Nom de %d Etudiant : ",rows+1);
        scanf("%s",&TabEtud[rows].nom);
        /**********/
        printf("\t--> Prenom de %d Etudiant : ",rows+1);
        scanf("%s",&TabEtud[rows].prenom);
        /**********/
        printf("\t--> Matricule de %d Etudiant : ",rows+1);
        scanf("%s",&TabEtud[rows].matricule);
        /*********/
        printf("\t--> Moyenne de BAC de %d Etudiant : ",rows+1);
        scanf("%f",&TabEtud[rows].moyenne);

        printf("\n");

    }

}
/***--Fin de La Fonction--***/

/************************************************/

int main(){
    int nmbProjet;
    int choix_prj_aff;
    int choix; //Choix du menu.
    int nmbEtud;//Nombre d'Etudiant et Nombre de projet.
    char decision; //Decision Pour retourner vers le Menu ou terminer le Programme.
    struct Projet TabProjet[nmbProjet];
    menu:
        printf("--> Choisir un nombre dans le menu :\n\n");

        puts("\t1-Ajouter un Etudiant");
        puts("\t2-Ajouter un Projet");
        puts("\t3-Affecter deux Etudiants a un Projet");
        puts("\t4-Afficher la liste de BAC");
        puts("\t5-Afficher la liste des themes");
        puts("\t6-Chercher un theme");
        printf("\n");

        printf("--> Votre choix est : ");
        scanf("%d", &choix);

        printf("\n<----------------------->\n\n");


    /*************************************************/
    switch (choix)
    {
        
        
        case 1:
            printf("--> Combien d'Etudiant vous voulez ajouter : ");
            scanf("%d",&nmbEtud);
            printf("\n");
            AddEtudiant(nmbEtud);
            break;

        case 2:
            int rows, nmbProjet;

            printf("--> Combien de projet vous voulez ajouter : ");
            scanf("%d",&nmbProjet);

            /* --Loop Pour remplire les Informations du projet-- */
            for ( rows = 0; rows < nmbProjet; rows++){
                
                printf("\t--> Theme %d : ",rows+1);
                scanf("%19s",&TabProjet[rows].theme);
                /****Le Theme****/

                printf("\t--> La difficulte [1-10] : ");
                scanf("%3d",&TabProjet[rows].diff);
                /*****La difficulte entre [1-10]*****/
                 //printf("HEllo");
                printf("\n");
            }
            break;

        /*case 3:
            int i, choix_prj_aff;
            puts("--> Choisir un projet :");

            for (int i = 0; i < nmbProjet; i++)
            {
                printf("\t%d- Projet %d :\n",i+1,i+1);
                printf("\t -> %s",TabProjet[i].theme);
                printf("\n");
                printf("\t -> %d",&TabProjet[i].diff);
                printf("\n\n");
            };
            printf("-->Votre choix est : ");
            scanf("%d",&choix_prj_aff);

            printf("\n<----------------------->\n\n");


            printf("--> Entrer le Matricule de 1 etudiant : ");
            scanf(" %s",&TabProjet[choix_prj_aff-1].etudiant1);

            printf("--> Entrer le Matricule de 2 etudiant : ");
            scanf("%s",&TabProjet[choix_prj_aff-1].etudiant2);

            printf("\n<----------------------->\n\n");

            printf("-Projet %d est maintenant :\n", choix_prj_aff);

                printf("\t -> %s",&TabProjet[choix_prj_aff-1].theme);
                printf("\n");
                printf("\t -> %d",&TabProjet[choix_prj_aff-1].diff);
                printf("\n");
                printf("\t -> Etudiant 1 : %s ",TabProjet[choix_prj_aff-1].etudiant1);
                printf("\n");
                printf("\t -> Etudiant 2 : %s",TabProjet[choix_prj_aff-1].etudiant2);
                printf("\n\n");


            break;*/

        default:
            printf("******* Nombre n'est pas disponible dans le menu!! *********\n    Choisir un nombre dans le menu svp!!\n\n");
            break;
    }
    /************************************************/


    /* ---retourner vers le menu ou terminer le programme--- */
    printf("--> Terminer le Programme? [O/N] : ");
    scanf(" %c",&decision);
    printf("\n");
    if (decision == 'N' )
    {
        goto menu;
    }
    printf("\n<----------------------->\n\n");
    /****************************************/

}
