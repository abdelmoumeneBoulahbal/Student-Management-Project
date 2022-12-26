#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int choix;

/****--Structure Pour Les Infos de L'Etudiant--****/
typedef struct Etudiant
{
    /* data */
    char nom[20];
    char prenom[20];
    char matricule[4];
    float moyenne;
}Etudiant;

/****--Structure Pour Les Infos de Projet--****/
typedef struct Projet
{
    /* data */
    char theme[20];
    int diff;
    char etudiant1[4]; //L'Etudiant 1 affecté dans le projet par Matricule
    char etudiant2[4]; //L'Etudiant 2 affecté dans le projet par Matricule
}Projet;
/********************************************/



/***---Fonction Pour ajouter des etudiants---***/
int AddEtudiant(int nmbEtudiant)
{
    int rows;

    Etudiant TabEtud[nmbEtudiant]; // Tableau Pour les Etudiant

    
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


/****---Fonction Pour ajouter des Projets---****/
int AddProjet(int nmbProjet){
    
    int rows;
    char Add_etud_proj;// Ajouter un etudiant dans le projet 

    Projet TabProj[nmbProjet]; // Tableau pour les projets

    /* --Loop Pour remplire les Informations du projet-- */
    for ( rows = 0; rows < nmbProjet; rows++)
    {
        printf("\t--> Theme %d : ",rows+1);
        scanf(" %s",&TabProj[rows].theme);
        /****Le Theme****/

        printf("\t--> La difficulte [1-10] : ");
        scanf(" %i",&TabProj[rows].diff);
        /*****La difficulte entre [1-10]*****/

        printf("\n");
    }
    

        /*int choix_prj_aff;

        puts("--> Choisir un projet :");
            
        for (int i = 0; i < nmbProjet; i++)
        {
                printf("\t%d- Projet %d :\n",i+1,i+1);
                printf("\t  -> %s",TabProj[i].theme);
                printf("\n");
                printf("\t  -> %d",TabProj[i].diff);
                printf("\n\n");
        }
        printf("-->Votre choix est : ");
        scanf("%d",&choix_prj_aff);
    
        printf("\n<----------------------->\n\n");

            
        printf("\t--> Entrer le Matricule de 1 etudiant : ");
        scanf("%s",&TabProj[choix_prj_aff-1].etudiant1);
            
        printf("\t--> Entrer le Matricule de 2 etudiant : ");
        scanf("%s",&TabProj[choix_prj_aff-1].etudiant2);
                
        printf("\n<----------------------->\n\n");*/

        /***--Choix Pour ajouter deux etudiants dans le projet--***/
        /*printf("--> Ajouter des Etudiants(2 Max) dans ce projet? [O/N] : ");
        scanf(" %c",&Add_etud_proj);

        printf("\n");

        /***--Si le choix est Oui--
        if (Add_etud_proj == 'O')
        {
            printf("\t--> Ecrire le Matricule de 1 etudiant : ",rows+1);
            scanf("%s",&TabProj[rows].etudiant1);
            

            printf("\t--> Ecrire le Matricule de 2 etudiant : ",rows+1);
            scanf("%s",&TabProj[rows].etudiant2);   
        }*/

}
/***--Fin de La Fonction--***/

/************************************************/
int AffEtudiant(int nmbPrjAff){

    int choix_prj_aff;

    Projet TabProj[nmbPrjAff];

    puts("--> Choisir un projet :");
    
    for (int i = 0; i < nmbPrjAff; i++)
    {
        printf("\t%d- Projet %d :\n",i+1,i+1);
        printf("\t -> %s",TabProj[i].theme);
        printf("\n");
        printf("\t -> %d",TabProj[i].diff);
        printf("\n\n");
    }
    printf("-->Votre choix est : ");
    scanf("%d",&choix_prj_aff);

    printf("\n<----------------------->\n\n");

    
     printf("--> Entrer le Matricule de 1 etudiant : ");
     scanf("%s",&TabProj[choix_prj_aff-1].etudiant1);
     
     printf("--> Entrer le Matricule de 2 etudiant : ");
     scanf("%s",&TabProj[choix_prj_aff-1].etudiant2);
        
    printf("\n<----------------------->\n\n");   
}

int main(){
    
    int choix; //Choix du menu.
    int nmbEtud, nmbPrj; //Nombre d'Etudiant et Nombre de projet. 
    char decision; //Decision Pour retourner vers le Menu ou terminer le Programme.
    
    Projet TabProj[nmbPrj];

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
        printf("--> Combien de projet vous voulez ajouter : ");
        scanf("%d",&nmbPrj);
        printf("\n");
        AddProjet(nmbPrj);
        break;
    case 3:
        AffEtudiant(nmbPrj);
        break;

    default:
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
    
    /****************************************/
    
}