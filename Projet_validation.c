#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/****--Structure Pour Les Infos de L'Etudiant--****/
struct Etudiant {
    /* data */
    char nom[20];
    char prenom[20];
    int  matricule;
    float moyenne;
};

/****--Structure Pour Les Infos de Projet--****/
struct Projet {
    /* data */
    char theme[20];
    int diff;
    int etudiant1; //L'Etudiant 1 affecté dans le projet par Matricule
    int etudiant2; //L'Etudiant 2 affecté dans le projet par Matricule
};
/*******************************************/


/*******************************************/
int main() {

    int max_diff;
    char max_theme[20];

    char max_nom[20], max_prenom[20];
    int max_matricule;
    float max_moyenne;

    int choix_prj_aff;// Choix du projet pour l'affectation.
    int choix; // Choix du menu.

    int nmbProjet, nmbEtudiant;// Nombre d'Etudiant et Nombre de projet.

    char decision; // Decision Pour retourner vers le Menu ou terminer le Programme.

    struct Projet TabProjet[10]; // Tableau Pour les Projets
    struct Etudiant TabEtud[10]; //Tableau Pour les Etudiants
    
    menu:

        printf("--> Choisir un nombre dans le menu :\n\n");
        printf("     <---------\e[1m Menu\e[m --------->\n\n");
        
        puts("\t1-Ajouter des Etudiants.\n");
        puts("\t2-Ajouter des Projets.\n");
        puts("\t3-Affecter deux Etudiants a un Projet.\n");
        puts("\t4-Afficher la liste de BAC.\n");
        puts("\t5-Afficher la liste des themes.\n");
        puts("\t6-Chercher un theme.");
        printf("\n");
        printf("     <------------------------>\n\n");
        printf("--> Votre choix est : ");
        scanf("%d", &choix);

        printf("\n**************************************************\n\n");
        

    /**************************************************/
   if (choix == 1)
   {
        printf("--> Combien d'Etudiants vous voulez ajouter : ");
        scanf("%d", &nmbEtudiant);

        /* Loop Pour Remplire les Informations de l'etudiant */
            for ( int rows = 0 ; rows < nmbEtudiant; rows++)
            {
                printf("\n\t--> Nom de %d Etudiant(e) : ",rows+1);
                scanf("%s",&TabEtud[rows].nom);
                /**********/
                printf("\t--> Prenom de %d Etudiant(e) : ",rows+1);
                scanf("%s",&TabEtud[rows].prenom);
                /**********/

                printf("\t--> Matricule de %d Etudiant(e)[4 chiffres] : ",rows+1);
                scanf("%d",&TabEtud[rows].matricule);
                /*********/
                printf("\t--> Moyenne de BAC de %d Etudiant(e) : ",rows+1);
                scanf("%f",&TabEtud[rows].moyenne);

                printf("\n");

            }
        printf("**************************************************\n\n");
   }        
    /***************************************************/        

    /***************************************************/    
    if(choix == 2){
        printf("--> Combien de Projet vous voulez ajouter : ");
        scanf("%d",&nmbProjet);

        printf("\n");

            /**--Loop Pour remplire les Informations du projet--**/
            for (int i = 0; i < nmbProjet; i++){
                
                printf("\t--> Theme %d : ", i+1);
                scanf("%s",&TabProjet[i].theme);
                /****Le Theme****/

                printf("\t--> La difficulte [1-10] : ");
                scanf("%d",&TabProjet[i].diff);
                /*****La difficulte entre [1-10]*****/
                
                printf("\n");
            }
        printf("**************************************************\n\n");
    }        
    /****************************************************/        


    /****************************************************/
    if (choix == 3)
    {
        puts("--> Choisir un projet :\n");

        for ( int j = 0; j < nmbProjet; j++)
        {
                printf("\t-\e[1mProjet\e[m %d :\n",j+1,j+1);
                printf("\t -> Theme : %s",TabProjet[j].theme);
                printf("\n");
                printf("\t -> Difficulte : %d",TabProjet[j].diff);
                printf("\n\n");
        }
        printf("--> Votre choix est : ");
        scanf("%d",&choix_prj_aff);

         printf("\n<----------------------->\n\n");


        printf("--> Entrer le Matricule de 1er etudiant(e)[4 chiffres] : ");
        scanf("%d",&TabProjet[choix_prj_aff-1].etudiant1);

        printf("--> Entrer le Matricule de 2eme etudiant(e)[4 chiffres] : ");
        scanf("%d",&TabProjet[choix_prj_aff-1].etudiant2);

            printf("\n<----------------------->\n\n");

        printf("\t-Projet %d :\n", choix_prj_aff);
            printf("\t -> Theme : %s",TabProjet[choix_prj_aff-1].theme);
            printf("\n");
            printf("\t -> Difficulte : %d",TabProjet[choix_prj_aff-1].diff);
            printf("\n");
            printf("\t -> Etudiant(e) 1 : #%d",TabProjet[choix_prj_aff-1].etudiant1);
            printf("\n");
            printf("\t -> Etudiant(e) 2 : #%d",TabProjet[choix_prj_aff-1].etudiant2);
            printf("\n\n");

        printf("**************************************************\n\n");    
    }        
    /**********************************************************/

    if(choix == 4 ){

        /****--Loop Pour l'ordre decroissant des moyennes--****/
        for (int cmptr1 = 0; cmptr1 < nmbEtudiant; ++cmptr1) 
        {
            for (int cmptr2 = cmptr1 + 1; cmptr2 < nmbEtudiant; ++cmptr2) 
            {
                if (TabEtud[cmptr1].moyenne < TabEtud[cmptr2].moyenne) 
                {   
                    strcpy(max_nom, TabEtud[cmptr1].nom);
                    strcpy(max_prenom, TabEtud[cmptr1].prenom);
                    max_moyenne = TabEtud[cmptr1].moyenne;
                    max_matricule = TabEtud[cmptr1].matricule;

                    strcpy(TabEtud[cmptr1].nom, TabEtud[cmptr2].nom);
                    strcpy(TabEtud[cmptr1].prenom, TabEtud[cmptr2].prenom);
                    TabEtud[cmptr1].moyenne = TabEtud[cmptr2].moyenne;
                    TabEtud[cmptr1].matricule = TabEtud[cmptr2].matricule;

                    strcpy(TabEtud[cmptr2].nom, max_nom);
                    strcpy(TabEtud[cmptr2].prenom, max_prenom);
                    TabEtud[cmptr2].matricule = max_matricule;
                    TabEtud[cmptr2].moyenne = max_moyenne;
                }
            }
        }
        /**--Fin du Loop--**/

        printf("     <---------\e[1m Liste du BAC\e[m --------->\n");

        printf("\n");

        for (int a = 0; a < nmbEtudiant; a++)
        {   
            
            printf("\t%d\\-%s %s [#%d] : %.2f ", a+1, TabEtud[a].nom, TabEtud[a].prenom, TabEtud[a].matricule, TabEtud[a].moyenne);
            printf("\n\n"); 
        }
        printf("     <-------------------------------->\n\n");

        printf("**************************************************\n\n");
    }

    if(choix == 5){
        /****--Loop Pour l'ordre croissant des difficultes--****/
        for (int cmptr3 = 0; cmptr3 < nmbProjet; ++cmptr3) 
        {
 
            for (int cmptr4 = cmptr3 + 1; cmptr4 < nmbProjet; ++cmptr4)
            {
 
                if (TabProjet[cmptr3].diff > TabProjet[cmptr4].diff) 
                {
 
                    max_diff =  TabProjet[cmptr3].diff;
                    strcpy(max_theme, TabProjet[cmptr3].theme);


                    TabProjet[cmptr3].diff = TabProjet[cmptr4].diff;
                    strcpy(TabProjet[cmptr3].theme, TabProjet[cmptr4].theme);
                    
                    strcpy(TabProjet[cmptr4].theme, max_theme);
                    TabProjet[cmptr4].diff = max_diff;

 
                }
 
            }
 
        }

       printf("     <---------\e[1m Liste des Difficultes\e[m --------->\n\n");
        for (int g = 0; g < nmbProjet; g++)
        {
            printf("\t--Theme %d : %s\n",g+1,TabProjet[g].theme);
            printf("\t--Difficulte : %d\n",g+1,TabProjet[g].diff);

            printf("\n");
        }
        printf("     <----------------------------------------->\n\n");

        printf("<**************************************************>\n\n");
    }

    /* ---retourner vers le menu ou terminer le programme--- */
    printf("--> Terminer le Programme? [O/N] : ");
    scanf(" %c",&decision);

    printf("\n");

    if (decision == 'N' )
    {
        printf("<**************************************************>\n\n");
        goto menu;
    }
    printf("\n\n\n");
    
    printf("<---------------------------\\Programme Terminer/--------------------------->\n\n");
   
    /****************************************/

    /**--Fin du Programme--**/

}
