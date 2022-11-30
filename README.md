// il faut que la bd soit donnée par l'état et non pas élaborée par l'oncf
//donc ca serait un fichier qui contient tous les titres de permission avec les infos necessaires

#include<stdio.h>
#include<string.h>

int x, choix;
typedef struct STrajet
{
    int idTrajet;
    char villeDep[15];
    char villeArr[15];
    float Prix;
    char Train[10];
    char heureDep[5];
    char heureArr[5];
    int Duree;
}STrajet;

STrajet trajets[50];

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

void sous_menu(int a)
{
    switch(a){
        case 1:
            espaceAdministrateur();
        break;
        case 2:
            //espaceVoyageur();
        break;
        case 3:
            printf("Cliquer sur un bouton");
    }

}

void espaceAdministrateur()
{
    char username[20], password[20];
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
    printf("\n1- Ajouter un trajet\n");
    printf("2- Modifier un trajet\n");
    printf("3- Supprimer un trajet\n");
    printf("4- Afficher les trajets\n");
    printf("5- Retour\n");
    printf("Choisir le service : ");
    scanf("%d", &x);
    gerer_trajet(x);
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






int main(){


    menu();
    return 0;
}

