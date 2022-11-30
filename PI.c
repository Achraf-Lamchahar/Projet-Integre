#include <stdio.h>
#include <string.h>

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

    typedef struct TitresPermi{
        int idTitre;
        char villeDep;
        char villArr;
        Date* date;
    }TitrePermi;

    typedef struct Trajets{
        int idTrajets;
        char villeDep;
        char villeArr;
        int prix;
        Horaire* heureTrajet;
    }Trajets;


    typedef struct Reservation{
        Date dateReserv;
        char villeDep;
        char villeArr;
        int Classe;
        int idTrajet;
    }Reservation;

void sousMenuEspaceAdministrateur(){
    printf("\t******************************************");
    printf("\n\t\tEspace Administrateur");
    printf("\n\t******************************************");
    
}

void espaceAdministrateur(){
    char username[30], password[30];
        printf("\n\tNom d'utilisateur:\t");
        scanf("%s", &username);
        printf("\n\tMot de passe:\t");
        scanf("%s", &password);
        if(!(strcmp(username,"admin") && strcmp(password,"admin"))){
            printf("\n\tConnexion reussie !\n");
            //ainsi de suite
        }
}

void espaceVoyageur(){
        printf("\t******************************************");
        printf("\n\t\tEspace Voyageur");
        printf("\n\t******************************************");
        printf("\n\t1- Voir les trains disponibles:\t");
        printf("\n\t2- Reserver un siège dans un train:\t");
        printf("\n\t3- Revenir au menu principal:\t");
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

       menu();
    
    return 0;
}