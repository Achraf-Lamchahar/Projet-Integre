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
FILE *file;
Reservation reservation;



void menu(){
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
            printf("application fermee");
            return 0;
         default:
            printf("Choix invalide!");
    }
}

void espaceAdministrateur(){
    int choix;
    char username[20], password[20];
    printf("\n\tNom d'utilisateur:\t");
    scanf("%s", &username);
    printf("\n\tMot de passe:\t");
    scanf("%s", &password);
    if(strcmp(username,"admin")==0 && strcmp(password,"admin")==0){
        printf("Connexion reussie !");
        printf("\t******************************************");
        printf("\n\tEspace Administrateur");
        printf("\t******************************************");
        printf("\n/t1- Ajouter un trajet");
        printf("\n/t2- Modifier un trajet");
        printf("\n/t3- Supprimer un trajet");
        printf("\n/t4- Afficher les trajets");
        printf("\n/t5- Retour");
        printf("\n/tChoisir le service: ");
        scanf("%d", &choix);
        menuGestionTrajets(choix);
    }
    else printf("Acces refusé.");
}

//Cette solution utilise les tableaux alors qu'il faut travailler avec fseek

void ajouterTrajet(){
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

void modifierTrajet(){       
    printf("Identifiant du trajet a modifier : "); scanf("%d", &nouveauTrajet.idTrajet);
    printf("Ville de depart : "); scanf("%s", &nouveauTrajet.villeDep);
    printf("Ville d'arrivee : "); scanf("%s", &nouveauTrajet.villeArr);
    printf("Prix : "); scanf("%f", &nouveauTrajet.Prix);
    printf("Train : "); scanf("%s", &nouveauTrajet.Train);
    printf("Heure de depart : "); scanf("%s", &nouveauTrajet.heureDep);
    printf("Heure d'arrivee : "); scanf("%s", &nouveauTrajet.heureArr);
    printf("Duree : "); scanf("%d", &nouveauTrajet.Duree);
    int nbTrajets=0;
    file = fopen("FTrajets", "r");
    while(fread(&trajet, sizeof(trajet), 1, file)){
        trajet[nbTrajets]=trajet; //prk ouvrir un fichier en tant que tableau !!
        nbTrajets++;
    }
    fclose(file); 
    remove("FTrajets");

    FILE *nfile;        
    nfile = fopen("FMTrajets","a");
    for (int i=0; i<nbTrajets; i++){
        if (trajets[i].idTrajet != nouveauTrajet.idTrajet)
            fwrite(&trajets[i], sizeof(trajets[i]), 1, nfile);
        else{ 
            fwrite(&nouveauTrajet, sizeof(nouveauTrajet), 1, nfile);
        }
    }
    fclose(nfile);
    rename("FMTrajets", "FTrajets");
}

void supprimerTrajet(){
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
        for (int i=0; i<nbTrajets; i++){
            if (trajets[i].idTrajet != IdS)
                fwrite(&trajets[i], sizeof(trajets[i]), 1, nf);
        }
        fclose(nf);
        rename("NFTrajets", "FTrajets");

        printf("Trajet supprime avec succes.");
}

void afficherTrajet(){
        int nbTrajets = 0;
        file = fopen("FTrajets", "r");

        while (fread(&trajet, sizeof(trajet), 1, file)){
            trajets[nbTrajets] = trajet;
            nbTrajets++;
        }
        fclose(file);
        for (int i=0; i<nbTrajets; i++){
            printf("\nIdentifiant du trajet : %d", trajets[i].idTrajet);
            printf("\nVille de depart : %s", trajets[i].villeDep);
            printf("\nVille d'arrivee : %s", trajets[i].villeArr);
            printf("\nPrix : %f DH", trajets[i].Prix);
            printf("\nTrain : %s", trajets[i].Train);
            printf("\nHeure de depart : %s", trajets[i].heureDep);
            printf("\nHeure d'arrivee : %s", trajets[i].heureArr);
            printf("\nDuree : %d h", trajets[i].Duree);
        }
}

void menuGestionTrajets(int a)
{
    switch(a){
    case 1:
        ajouterTrajet();
    break;
    case 2 :
        modifierTrajet();
    break;
    case 3:
        supprimerTrajet();
    break;
    case 4:
        afficherTreajet();
    break;
    default:
        printf("\nOption Invalide!");
    break;
    }
}

int main(){
    menu();
    return 0;
}
