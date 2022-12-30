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


/****--Main--****/
int main() {

    int cherche_matricule;//Var pour la recherche de le theme par l'etudiant.

//////////////////////////////////////

    int max_diff;//Affichage du liste des projets.
    char max_theme[20];//Afichage du liste des projets.

//////////////////////////////////////

    char max_nom[20], max_prenom[20];//Affichage du liste de BAC.
    int max_matricule;//Affichage du liste de BAC.
    float max_moyenne;//Affichage du liste de BAC.

//////////////////////////////////////

    int choix_prj_aff;// Choix du projet pour l'affectation.
    int choix; // Choix du menu.

/////////////////////////////////////

    int nmbProjet, nmbEtudiant;// Nombre d'Etudiant et Nombre de projet.

/////////////////////////////////////

    char decision; // Decision Pour retourner vers le Menu ou terminer le Programme.

/////////////////////////////////////

    struct Projet TabProjet[10]; // Tableau Pour les Projets.
    struct Etudiant TabEtud[10]; //Tableau Pour les Etudiants.

/////////////////////////////////////  

    /***--Menu--***/
    menu:

        printf("--> Choisir un nombre dans le menu :\n\n");
        printf("     <---------Menu--------->\n\n");//Bold
        
        puts("\t1-Ajouter des Etudiants.\n");
        puts("\t2-Ajouter des Projets.\n");
        puts("\t3-Affecter deux Etudiants a un Projet.\n");
        puts("\t4-Afficher la liste de BAC.\n");
        puts("\t5-Afficher la liste des themes.\n");
        puts("\t6-Chercher un theme.");
        printf("\n");
        printf("     <----------------------->\n\n");
        printf("--> Votre choix est : ");
        scanf("%d", &choix);

        printf("\n**************************************************\n\n");
    /**--Fin Menu--**/

    /***--Ajouter des etudiants--***/
   if (choix == 1)
   {
        printf("--> Combien d'Etudiants vous voulez ajouter : ");
        scanf("%d", &nmbEtudiant);

        /*-Loop Pour Remplire les Informations de l'etudiant-*/
            for ( int rows = 0 ; rows < nmbEtudiant; rows++)
            {
                printf("\n\t--> Nom de %d Etudiant(e) : ",rows+1);
                scanf(" %[^\n]",&TabEtud[rows].nom);
                /*****Nom de l'etudiant*****/
                printf("\t--> Prenom de %d Etudiant(e) : ",rows+1);
                scanf(" %[^\n]",&TabEtud[rows].prenom);
                /*****Prenom de l'etudiant*****/

                printf("\t--> Matricule de %d Etudiant(e)[4 chiffres] : ",rows+1);
                scanf("%d",&TabEtud[rows].matricule);
                /*****Matricule de l'etudiant****/

                printf("\t--> Moyenne de BAC de %d Etudiant(e) : ",rows+1);
                scanf("%f",&TabEtud[rows].moyenne);
                /****Moyenne de BAC de l'etudiant****/

                printf("\n");

            }
        /*-Fin Loop-*/

        printf("**************************************************\n\n");
   }        
    /***--Fin AjouEtud--***/        

    /***--Ajouter des projets--***/
    if(choix == 2){

        printf("--> Combien de Projet vous voulez ajouter : ");
        scanf("%d",&nmbProjet);//nombre des projets

        printf("\n");

            /**--Loop Pour remplire les Informations du projet--**/
            for (int remp_proj = 0; remp_proj < nmbProjet; remp_proj++){
                
                printf("\t--> Theme %d : ", remp_proj+1);
                scanf(" %[^\n]",&TabProjet[remp_proj].theme);
                /****Le Theme****/

                printf("\t--> La difficulte [1-10] : ");
                scanf("%d",&TabProjet[remp_proj].diff);
                /*****La difficulte entre [1-10]*****/
                
                printf("\n");
            }
            /*-Fin Loop-*/

        printf("**************************************************\n\n");
    }        
    /***--Fin AjouProj--***/         


    /***--Affecter deux etudiants--***/
    if (choix == 3)
    {
        puts("--> Choisir un projet :\n");
        /*-Loop pour afficher les projets-*/
        for ( int affich_projet = 0; affich_projet < nmbProjet; affich_projet++)
        {
                printf("\t-Projet %d :\n",affich_projet+1);//Bold
                printf("\t -> Theme : %s",TabProjet[affich_projet].theme);
                printf("\n");
                printf("\t -> Difficulte : %d",TabProjet[affich_projet].diff);
                printf("\n\n");
        }
        /*-Fin Loop affch proj-*/

        printf("--> Votre choix est : ");
        scanf("%d",&choix_prj_aff);//choix du projet

         printf("\n<----------------------->\n\n");

        /*-L'affectation avec le Matricule de les etudiants(2 etud)-*/
        printf("--> Entrer le Matricule de 1er etudiant(e)[4 chiffres] : ");
        scanf("%d",&TabProjet[choix_prj_aff-1].etudiant1);//Matricule etudiant 1.

        printf("--> Entrer le Matricule de 2eme etudiant(e)[4 chiffres] : ");
        scanf("%d",&TabProjet[choix_prj_aff-1].etudiant2);//Matricule etudiant 2.
        /*-Fin Affectation-*/

            printf("\n<----------------------->\n\n");

        /*-Affichage du projet choisis apres l'affectation de les etudiants-*/
        printf("\t-Projet %d :\n", choix_prj_aff);
            printf("\t -> Theme : %s",TabProjet[choix_prj_aff-1].theme);//Theme de projet.
            printf("\n");
            printf("\t -> Difficulte : %d",TabProjet[choix_prj_aff-1].diff);//Diff de projet.
            printf("\n");
            printf("\t -> Etudiant(e) 1 : #%d",TabProjet[choix_prj_aff-1].etudiant1);//Matricule de l'etudiant 1.
            printf("\n");
            printf("\t -> Etudiant(e) 2 : #%d",TabProjet[choix_prj_aff-1].etudiant2);//Matricule de l'etudiant 2.
            printf("\n\n");
        /*-Fin Affichage-*/

        printf("**************************************************\n\n");    
    }        
    /***--Fin AffEtud--***/ 

    /**--Affichage de la liste de BAC--***/
    if(choix == 4 ){

        /****--Loop Pour l'ordre decroissant des moyennes--****/
        for (int cmptr1 = 0; cmptr1 < nmbEtudiant; ++cmptr1) 
        {
            for (int cmptr2 = cmptr1 + 1; cmptr2 < nmbEtudiant; ++cmptr2) 
            {
                if (TabEtud[cmptr1].moyenne < TabEtud[cmptr2].moyenne) 
                {   
                    /*Swap (variables created to hold the data)*/
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
        /**--Fin classment moyenne etud ordre decroissant--**/

        /*-Affichage de la liste de BAC en ordre decroissant-*/
        printf("     <---------Liste du BAC--------->\n");//Bold

        printf("\n");

        /*-Loop pour classer les etudiants en ordre decroissant-*/
        for (int classment_etudiant = 0; classment_etudiant < nmbEtudiant; classment_etudiant++)
        {   
            
            printf("\t%d\\-%s %s [#%d] : %.2f ", classment_etudiant+1, TabEtud[classment_etudiant].nom, TabEtud[classment_etudiant].prenom, TabEtud[classment_etudiant].matricule, TabEtud[classment_etudiant].moyenne);
            printf("\n\n"); 
        }
        /*-Fin Loop Affich Ord Decroiss Etud-*/

        printf("     <------------------------------->\n\n");

        printf("**************************************************\n\n");
    }
    /***--Fin Affch Lis BAC--***/

    /***--Affichage de la liste des projets--***/
    if(choix == 5){
    
        /*-Loop Pour l'ordre croissant des difficultes-*/
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
        /*-Fin Loop Classment Ordre Croiss Diffi-*/

       /*-Loop pour l'affichage de la Liste des Projets en ordre croissant-*/
        printf("( Note: Difficulte des Themes [ le plus facile (1) --> le plus difficile (10) ] )\n\n");
        printf("     <---------Liste des Themes--------->\n\n");//Bold
        
        for (int classment_projet = 0; classment_projet < nmbProjet; classment_projet++)
        {
            printf("\t--Theme %d : %s\n",classment_projet+1,TabProjet[classment_projet].theme);//Afficher Theme
            printf("\t--Difficulte : %d\n",TabProjet[classment_projet].diff);//Afficher Difficulte

            printf("\n");
        }
        /*-Fin Loop Affch Lis Proj Ordre Croiss-*/

        printf("     <---------------------------------->\n\n");

        printf("**************************************************\n\n");
    }
    /***--Fin AffLisProj--***/

    /***--Cherche d'un theme--***/
    if (choix == 6 )
    {   
        char verif, decision_aff_proj;

        //Verification 
        printf("---> Avant de chercher un theme, est-ce que tu as ajouté des etudiants/projets et affecté des etudiants? [O/N] : ");
        scanf(" %c",&verif);

        printf("\n");

        //Condition si vraie demmare la recherche 
        if (verif == 'O' || verif == 'o')
        {
            printf("     <----------------------------------------->\n\n");
            printf("--> Entrer le Matricule de l'etudiant [4 chiffres] :");
            scanf("%d",&cherche_matricule);

            printf("\n     <----------------------------------------->\n\n");

            /**--Loop pour comparer le matricule saisi avec les matricules stockés apres l'affectation(e1 et e2)--**/
            for (int comp_matricule = 0; comp_matricule < nmbProjet; comp_matricule++)
            {   
                /*
                 *compare les deux matricules stockés avec le matricule saisi
                 */
                if (TabProjet[comp_matricule].etudiant1 == cherche_matricule || TabProjet[comp_matricule].etudiant2 == cherche_matricule)
                {   
                    //Si l'un des matricules est égale a le matricule saisi
                    //Affichage du theme cherché.
                    printf("--> Votre Theme est : %s\n\n",TabProjet[comp_matricule].theme);

                    //Choix pour afficher le Projet complet.
                    printf("--> Afficher le Projet Complet? [O/N] : ");
                    scanf(" %c",&decision_aff_proj);

                    printf("\n\n");

                    printf("     <----------------------------------------->\n\n");

                    //Affichage du projet complet si la condition est vraie.
                    if(decision_aff_proj == 'O' || decision_aff_proj == 'o')
                    {
                        /*-Affichage du projet apres la recherche du matricule-*/
                        printf("\t-Projet %d :\n", comp_matricule+1);
                            printf("\t -> Theme : %s",TabProjet[comp_matricule].theme);//Theme de projet.
                            printf("\n");
                            printf("\t -> Difficulte : %d",TabProjet[comp_matricule].diff);//Diff de projet.
                            printf("\n");
                            printf("\t -> Etudiant(e) 1 : #%d",TabProjet[comp_matricule].etudiant1);//Matricule de l'etudiant 1.
                            printf("\n");
                            printf("\t -> Etudiant(e) 2 : #%d",TabProjet[comp_matricule].etudiant2);//Matricule de l'etudiant 2.
                            printf("\n\n");

                    }/*-Fin Affichage Projet Complet-*/

                }/*-Fin Comparaison Condition Vraie-*/ 

            }/*-Fin Comparaison Loop-*/

        }/*-Fin Condition Verif Vraie-*/

        /*-Condition si verif fausse-*/
        else if (verif == 'N' || verif == 'n')
        {
            printf("\n\n\t--> Retourner vers le menu et ajouter des etudiants/projets puis affecter des etudiants<--\n\n");

        }/*-Fin si verif fausse-*/   

        printf("\n**************************************************\n\n");
    }
    /***--Fin CherTheme--***/

    /*-Condition si le choix n'est pas disponible dans le menu-*/
    if (choix > 6)
    {
        printf("\tChoix Indisponible!!\n");
        printf("--> Entrer un nombre dans le menu!!\n\n");
        printf("\n**************************************************\n\n");
    }
    /*-Fin Condit chx-*/
    

    /***--Retourner vers le menu ou terminer le programme--***/
    printf("--> Terminer le Programme? [O/N] : ");
    scanf(" %c",&decision);

    printf("\n");

    if (decision == 'N' || decision == 'n' )
    {
        printf("**************************************************\n\n");
        goto menu;
    }
    printf("\n\n\n");
    
    printf("<---------------------------\\Programme Terminer/--------------------------->\n\n");
    /***********-Fin decision-***********/

    /*****------Fin du Programme------******/
}
/********************-Fin Main--********************/
