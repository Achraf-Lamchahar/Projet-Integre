// il faut que la bd soit donnée par l'état et non pas élaborée par l'oncf
//donc ca serait un fichier qui contient tous les titres de permission avec les infos necessaires

#include<stdio.h>
#include<string.h>

typedef struct Date{
     int jour;
     int mois;
     int annee;
}Date;

typedef struct TitresPermi{
    int idTitre;
    char villeDep;
    char villArr;
    Date dateTitre;
}TitrePermi;

typedef struct Horaire{
    int heure;
    int minute;
    int seconde;
}Horaire;
    
typedef struct STrajet{
    int idTrajet;
    char villeDep[15];
    char villeArr[15];
    float Prix;
    char Train[10];
    char heureDep[5];
    char heureArr[5];
    int Duree;
}STrajet;

STrajet trajet;
STrajet nouveauTrajet;


void reserver(){
    struct Reservation reservation;
    FILE *file;
    printf("\tChoisir une date");
    printf("\n\tJour: ");
    scanf("%d", &reservation.dateReserv.jour);
    printf("\tMois: ");
    scanf("%d", &reservation.dateReserv.mois);
    printf("\tAnnee: ");
    scanf("%d", &reservation.dateReserv.annee);
    printf("\tChoisir la ville de depart:\t");
    //printf("\n\t1- Rabat");              zyad nzel 3liha
    //printf("\n\t2- Casablanca");

    scanf("%s", &reservation.villeDep);
    printf("\tChoisir la ville d'arrivee:\t");
    scanf("%s", &reservation.villeArr);
    afficher_trains();
    printf("\n\tChoisir un train:\t");
    scanf("%d", &train);
    printf("\n\tChoisir une classe:\t");
    printf("\n\t1- 1ere classe");
    printf("\n\t2- 2eme classe");
    scanf("%d", &reservation.classe);
    file = fopen("reservation.txt", "a");
    fwrite(&reservation, sizeof(reservation), 1, file);
    if(fwrite!=0)
        printf("\tReservation effectuee avec succes");
    else
        printf("\tReservation non effectuee\n\tVeuillez reessayer");
    fclose(file);
}

void menu(){
    printf("\t******************************************");
    printf("\n\t\tLet's Travel with ONCF");
    printf("\n\t******************************************");
    printf("\n\t1- Je suis un administrateur");
    printf("\n\t2- Je suis un voyageur");
    printf("\n\t3- Sortir de l'application");
    printf("\n\n\tDonner votre choix: ");
    scanf("%d", &choix);
    sous_menu(choix);
}

void sous_menu(int a){
    switch(a){
        case 1:
            espaceAdministrateur();
        break;
        case 2:
            espaceVoyageur();
        break;
        case 3:
            printf("application fermee");
            return 0;
         default:
            printf("Choix invalide!");
    }
}





    
void espaceVoyageur(){
        printf("\t******************************************");
        printf("\n\t\tEspace Voyageur");
        printf("\n\t*****************************************");
        printf("\n\t1- Voir les trains disponibles");
        printf("\n\t2- Reserver");
        printf("\n\t3- Revenir au menu principal");
        printf("\n\t4- Quitter l'application");
        printf("\n\n\tChoisir une operation:\t");
        scanf("%d", opr);
        sous_menu_voy(opr);
}

void sous_menu_voy(int a){
    if(a==1){
        //afficher_trains();        la meme que celle affichee a l'administrateur
    }
    else if(a==2){
        reserver();
    }
    else if(a==3){
        menu();
    }
    else if(a==4){
        printf("\tFermeture de l'application");
        return 0;
    }
    else{
        print("\tMauvais choix");
        return 0;
    }
}

}

void espaceAdministrateur(){
    char username[20], password[20];
    printf("\n\tNom d'utilisateur:\t");
    scanf("%s", &username);
    printf("\n\tMot de passe:\t");
    scanf("%s", &password);
    if(strcmp(username,"admin")==0 && strcmp(password,"admin")==0){
        printf("Connexion reussie !");
        printf("\n\t******************************************");
        printf("\n\t\tEspace Administrateur");
        printf("\n\t******************************************");
        printf("\n\t1- Ajouter un trajet\n");
        printf("\n\t2- Modifier un trajet\n");
        printf("\n\t3- Supprimer un trajet\n");
        printf("\n\t4- Afficher les trajets\n");
        printf("\n\t5- Retour\n");
        printf("Choisir le service : ");
        scanf("%d", &x);
        gerer_trajet(x);
    }
    else
        printf("Acces refuse !");
}

void gerer_trajet(int a)
{
    if (a==1) // ajout d'un trajet
        {

            struct STrajet trajet;
            FILE *file;

            printf("Identifiant du trajet : "); scanf("%d", &trajet.idTrajet);
            printf("Ville de depart : "); scanf("%s", &trajet.villeDep);
            printf("Ville d'arrivee : "); scanf("%s", &trajet.villeArr);
            printf("Prix : "); scanf("%f", &trajet.Prix);
            printf("Train : "); scanf("%s", &trajet.Train);
            printf("Heure de depart : "); scanf("%s", &trajet.heureDep);
            printf("Heure d'arrivee : "); scanf("%s", &trajet.heureArr);
            printf("Duree : "); scanf("%d", &trajet.Duree);

            file = fopen("FTrajets", "a");
            fwrite(&trajet, sizeof(trajet), 1, file);

            if (fwrite != 0) printf("Trajet ajoute avec succes.");
            else printf("erreur");
            fclose(file);

            
        }
    else if (a==2) //modification d'un trajet
    {
        struct STrajet trajet;
        struct STrajet NVtrajet;
        FILE *file;

        printf("Identifiant du trajet a modifier : "); scanf("%d", &NVtrajet.idTrajet);
        printf("Ville de depart : "); scanf("%s", &NVtrajet.villeDep);
        printf("Ville d'arrivee : "); scanf("%s", &NVtrajet.villeArr);
        printf("Prix : "); scanf("%f", &NVtrajet.Prix);
        printf("Train : "); scanf("%s", &NVtrajet.Train);
        printf("Heure de depart : "); scanf("%s", &NVtrajet.heureDep);
        printf("Heure d'arrivee : "); scanf("%s", &NVtrajet.heureArr);
        printf("Duree : "); scanf("%d", &NVtrajet.Duree);
        int nbTrajets=0;
        file = fopen("FTrajets", "r");
        while(fread(&trajet, sizeof(trajet), 1, file)){
            trajets[nbTrajets]=trajet;
            nbTrajets++;
        }
        fclose(file);
        remove("FTrajets");

        FILE *nfile;
        nfile = fopen("FMTrajets","a");
        for (int i=0; i<nbTrajets; i++){
            if (trajets[i].idTrajet != NVtrajet.idTrajet)
                fwrite(&trajets[i], sizeof(trajets[i]), 1, nfile);

            else
                fwrite(&NVtrajet, sizeof(NVtrajet), 1, nfile);
        }
        fclose(nfile);
        rename("FMTrajets", "FTrajets");

    }
    else if (a==3) //suppression d'un trajet
    {
        struct STrajet trajet;
        FILE *file;
        int IdS;
        printf("Identifiant du trajet a supprimer : "); scanf("%d", &IdS);

        file = fopen("FTrajets", "r");
        int nbTrajets = 0;
        while(fread(&trajet, sizeof(trajet), 1, file))
        {
            trajets[nbTrajets]=trajet;
            nbTrajets++;
        }
        fclose(file);
        remove("FTrajets");

        FILE *nf;
        nf = fopen("NFTrajets", "a");
        for (int i=0; i<nbTrajets; i++)
        {
            if (trajets[i].idTrajet != IdS)
                fwrite(&trajets[i], sizeof(trajets[i]), 1, nf);
        }
        fclose(nf);
        rename("NFTrajets", "FTrajets");

        printf("Trajet supprime avec succes.");

    }

    else if (a==4) //affichage d'un trajet
        {
        
        FILE *file;
        struct STrajet trajet;
        int nbTrajets = 0;
        file = fopen("FTrajets", "r");

        while (fread(&trajet, sizeof(trajet), 1, file)){
            trajets[nbTrajets] = trajet;
            nbTrajets++;
        }
        fclose(file);
        for (int i=0; i<nbTrajets; i++)
        {
            printf("\nIdentifiant du trajet : %d", trajets[i].idTrajet);
            printf("\nVille de depart : %s", trajets[i].villeDep);
            printf("\nVille d'arrivee : %s", trajets[i].villeArr);
            printf("\nPrix : %f DH", trajets[i].Prix);
            printf("\nTrain : %s", trajets[i].Train);
            printf("\nHeure de depart : %s", trajets[i].heureDep);
            printf("\nHeure d'arrivee : %s", trajets[i].heureArr);
            printf("\nDuree : %d h", trajets[i].Duree);
            printf("\n");
        }
        }
}

void reserver(){
    struct Reservation reservation;
    FILE *file;
    printf("\tChoisir une date");
    printf("\n\tJour: ");
    scanf("%d", &reservation.dateReserv.jour);
    printf("\tMois: ");
    scanf("%d", &reservation.dateReserv.mois);
    printf("\tAnnee: ");
    scanf("%d", &reservation.dateReserv.annee);
    printf("\tChoisir la ville de depart:\t");
    //printf("\n\t1- Rabat");              zyad nzel 3liha
    //printf("\n\t2- Casablanca");
    scanf("%s", &reservation.villeDep);
    printf("\tChoisir la ville d'arrivee:\t");
    scanf("%s", &reservation.villeArr);
    afficher_trains();
    printf("\n\tChoisir un train:\t");
    scanf("%d", &train);
    printf("\n\tChoisir une classe:\t");
    printf("\n\t1- 1ere classe");
    printf("\n\t2- 2eme classe");
    scanf("%d", &reservation.classe);
    file = fopen("reservation.txt", "a");
    fwrite(&reservation, sizeof(reservation), 1, file);
    if(fwrite!=0)
        printf("\tReservation effectuee avec succes");
    else
        printf("\tReservation non effectuee\n\tVeuillez reessayer");
    fclose(file);
}


int main(){
    menu();
    return 0;
}

