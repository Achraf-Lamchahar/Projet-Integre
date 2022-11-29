# Projet-Integre

#include <stdio.h>
#include <string.h>

    typedef struct TitresPermi{
        int idTitre;
        char villeDep;
        char villArr;
        struct date date Titre;
    }TitrePermi;

    typedef struct Trajets{
        int idTrajets;
        char villeDep;
        char villeArr;
        int prix;
        struct Horaire heureTrajet;
    }Trajets;

    typedef struct Date{
        int jour;
        int mois;
        int annee;
    }Date;

    typedef struct Horaire{
        int heure;
        int minute;
        int seconde;
    }Horaire;

    typedef struct Reservation{
        struct date dateReserv;
        struct villeDep;
        struct villeArr;
        int Classe;
        int idTrajet;
    }Reservation;

void espaceAdministrateur(){
        printf("\n\tNom d'utilisateur:\t");
        scanf("%s", &username);
        printf("\n\tMot de passe:\t");
        scanf("%s", &password);
        if(strcmp(username,"admin") && strcmp(password,"admin")){
            printf("Connexion reussie !");
        }
        printf("\t******************************************");
        printf("\n\tEspace Administrateur");
        printf("\t******************************************");
        //ainsi de suite
}

void espaceVoyageur(){
        printf("\t******************************************");
        printf("\n\tEspace Voyageur");
        printf("\t******************************************");
        printf("\n\t1- Voir les trains disponibles:\t");
        printf("\n\t2- Reserver:\t");
        printf("\n\t3- Revenir au menu principal:\t");
}

void Reserver(){
    
}

void menu(){
    char username[20], password[20];
    int choix;
    printf("\t******************************************");
    printf("\n\t\tLet's Travel with ONCF");
    printf("\n\t******************************************");
    printf("\n\t1- Je suis un administrateur");
    printf("\n\t2- Je suis un voyageur");
    printf("\n\t3- Sortir de l'application");
    printf("\n\n\tDonner votre choix: ");
    scanf("%d", &choix);
    switch(choix){
        case 1:
            espaceAdministrateur();
        break;
        case 2:
            espaceVoyageur();
        break;
        case 3:
            printf("Cliquer sur un bouton");
    }
}
int main(){

       
    
    return 0;
}
