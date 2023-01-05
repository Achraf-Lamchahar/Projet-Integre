#include<stdio.h>
#include<string.h>
#include<windows.h>

typedef struct SHoraire{
    char heure[3], minute[3];
} SHoraire;

typedef struct SDate{
    char jour[3], mois[3], annee[5];
} SDate;

typedef struct STrain{
    char nomTrain[15];
    int idTrain, nbrPlacesMax;
}STrain;

typedef struct STrajet
{
    char villeDep[15], villeArr[15], idTrajet[20], idTrajetJour[15];
    float Prix;
    STrain trajetTrain;
    SHoraire Duree, heureDep, heureArr;
    SDate dateTrajet;
    int placesReservees;
}STrajet;


typedef struct STicket
{
    SDate dateDep;
    char stationDep[20], stationArr[20], nom[15], prenom[15];

}STicket;

typedef struct STitre{
    char nom[15], prenom[15], villeDep[15], villeArr[15];
    int idTitre, nbrUtilisation;
}STitre;

STitre titre;
STitre titres[50];
STrajet trajets[50];
STrajet trajet;
STrajet NVtrajet;
STrain train;
STrain NVtrain;
STrain trains[30];
STicket ticket;
STicket NVticket;

FILE* file;
FILE* file1;
FILE* nfile;
FILE* nfile1;
FILE* nf;
FILE* fileT;
FILE* file2;

void afficherTrajets()
{
    int nbTrajets = 0;
    file = fopen("fichierDesTrajets.txt", "r");
    while (fread(&trajet, sizeof(trajet), 1, file)){
        trajets[nbTrajets] = trajet;
        nbTrajets++;
    }
    fclose(file);
    for (int i=0; i<nbTrajets; i++)
    {
        printf("\nIdentifiant du trajet : %s", trajets[i].idTrajet);
        printf("\nIdenitfiant du trajet dans son jour: %s", trajets[i].idTrajetJour);
        printf("\nVille de depart : %s", trajets[i].villeDep);
        printf("\nVille d'arrivee : %s", trajets[i].villeArr);
        printf("\nPrix : %f DH", trajets[i].Prix);
        printf("\nTrain : %s", trajets[i].trajetTrain.nomTrain);
        printf("\nNombre de places maximal: %d", trajets[i].trajetTrain.nbrPlacesMax);
        printf("\nNombre de places reservees: %d", trajets[i].placesReservees);
        printf("\nHeure de depart : %s:%s", trajets[i].heureDep.heure, trajets[i].heureDep.minute);
        printf("\nHeure d'arrivee : %s:%s", trajets[i].heureArr.heure, trajets[i].heureArr.minute);
        printf("\nDuree : %sh%smin", trajets[i].Duree.heure, trajets[i].Duree.minute);
        printf("\nDate : %s/%s/%s", trajets[i].dateTrajet.jour, trajets[i].dateTrajet.mois, trajets[i].dateTrajet.annee);
        printf("\n");
    }
}

void ajouterTrajet()
{
    int idTrainTrajet;
    char buffer1[15], buffer2[20];
    trajet.placesReservees=0;
    printf("\n\t\tVille de depart : "); scanf("%s", &trajet.villeDep);
    printf("\t\tVille d'arrivee : "); scanf("%s", &trajet.villeArr);
    printf("\t\tPrix : "); scanf("%f", &trajet.Prix);
    printf("\t\t\tHoraire du depart :");
    printf("\n\t\tHeure(en 2 chiffres) : "); scanf("%s", &trajet.heureDep.heure);
    printf("\t\tMinutes(en 2 chiffres) : "); scanf("%s", &trajet.heureDep.minute);
    printf("\t\t\tHoraire d'arrivee :");
    printf("\n\t\tHeure(en 2 chiffres) : "); scanf("%s", &trajet.heureArr.heure);
    printf("\t\tMinutes(en 2 chiffres) : "); scanf("%s", &trajet.heureArr.minute);
    printf("\t\t\tDuree :");
    printf("\n\t\tDuree(h en 2 chiffres) : "); scanf("%s", &trajet.Duree.heure);
    printf("\t\tDuree(min en 2 chiffres) : "); scanf("%s", &trajet.Duree.minute);
    printf("\t\t\tDate du trajet :");
    printf("\n\t\tJour(en 2 chiffres) : "); scanf("%s", &trajet.dateTrajet.jour);
    printf("\t\tMois(en 2 chiffres) : "); scanf("%s", &trajet.dateTrajet.mois);
    printf("\t\tAnnee(en 4 chiffres) : "); scanf("%s", &trajet.dateTrajet.annee);

    int nbTrains = 0;
    file1 = fopen("fTrains.txt", "r");
    while (fread(&train, sizeof(train), 1, file1)){
        trains[nbTrains] = train;
        nbTrains++;
    }
    fclose(file1);

    printf("Entrer l'identifiant du train associe a ce trajet: "); scanf("%d", &idTrainTrajet);
    while (rechercheTrain(idTrainTrajet, trains, nbTrains)==0){
        printf("le train ayant cet identifiant n'existe pas.");
        printf("Entrer l'identifiant du train associe a ce trajet: "); scanf("%d", &idTrainTrajet);}


    for(int j=0; j<nbTrains; j++)
    {
        if(trains[j].idTrain==idTrainTrajet)
        {
            strcpy(trajet.trajetTrain.nomTrain, trains[j].nomTrain);
            trajet.trajetTrain.idTrain=trains[j].idTrain;
            trajet.trajetTrain.nbrPlacesMax=trains[j].nbrPlacesMax;
        }
    }

    printf("Le train associe a ce trajet: %s\n", trajet.trajetTrain.nomTrain);
    printf("Nombre de places maximal: %d\n", trajet.trajetTrain.nbrPlacesMax);

    buffer1[0]=trajet.villeDep[0];
    buffer1[1]=trajet.villeDep[1];
    buffer1[2]=trajet.villeArr[0];
    buffer1[3]=trajet.villeArr[1];
    strcat(buffer1,trajet.dateTrajet.jour);
    strcat(buffer1,trajet.dateTrajet.mois);
    strcat(buffer1,trajet.dateTrajet.annee);

    strcpy(buffer2,buffer1);
    strcat(buffer2,trajet.heureDep.heure);
    strcat(buffer2,trajet.heureDep.minute);

    strcpy(trajet.idTrajetJour,buffer1);
    strcpy(trajet.idTrajet,buffer2);

    printf("L'identifiant de ce trajet: %s", trajet.idTrajet);

    file = fopen("fichierDesTrajets.txt", "a");
    fwrite(&trajet, sizeof(trajet), 1, file);
    if (fwrite != 0) printf("\nTrajet ajoute avec succes.\n");
    else printf("erreur");
    fclose(file);
}

void modifierTrajet()
{
    char idTM[20];
    printf("\nEntrer l'identifiant du trajet que vous voulez modifier: "); scanf("%s", &idTM);
    int nbTrajets = 0;
    file = fopen("fichierDesTrajets.txt", "r");
    while (fread(&trajet, sizeof(trajet), 1, file)){
        trajets[nbTrajets] = trajet;
        nbTrajets++;
    }
    fclose(file);
    if (rechercheTrajet(idTM, trajets, nbTrajets))
    {
        remove("fichierDesTrajets.txt");
        int idTrainTrajet;
        char buffer1[15], buffer2[20];
        NVtrajet.placesReservees=0;
        printf("\n\t\tVille de depart : "); scanf("%s", &NVtrajet.villeDep);
        printf("\t\tVille d'arrivee : "); scanf("%s", &NVtrajet.villeArr);
        printf("\t\tPrix : "); scanf("%f", &NVtrajet.Prix);
        printf("\t\t\tHoraire du depart :");
        printf("\n\t\tHeure(en 2 chiffres) : "); scanf("%s", &NVtrajet.heureDep.heure);
        printf("\t\tMinutes(en 2 chiffres) : "); scanf("%s", &NVtrajet.heureDep.minute);
        printf("\t\t\tHoraire d'arrivee :");
        printf("\n\t\tHeure(en 2 chiffres) : "); scanf("%s", &NVtrajet.heureArr.heure);
        printf("\t\tMinutes(en 2 chiffres) : "); scanf("%s", &NVtrajet.heureArr.minute);
        printf("\t\t\tDuree :");
        printf("\n\t\tDuree(h en 2 chiffres) : "); scanf("%s", &NVtrajet.Duree.heure);
        printf("\t\tDuree(min en 2 chiffres) : "); scanf("%s", &NVtrajet.Duree.minute);
        printf("\t\t\tDate du trajet :");
        printf("\n\t\tJour(en 2 chiffres) : "); scanf("%s", &NVtrajet.dateTrajet.jour);
        printf("\t\tMois(en 2 chiffres) : "); scanf("%s", &NVtrajet.dateTrajet.mois);
        printf("\t\tAnnee(en 4 chiffres) : "); scanf("%s", &NVtrajet.dateTrajet.annee);

        int nbTrains = 0;
        file1 = fopen("fTrains.txt", "r");
        while (fread(&train, sizeof(train), 1, file1)){
            trains[nbTrains] = train;
            nbTrains++;
        }
        fclose(file1);

        printf("Entrer l'identifiant du train associe a ce trajet: "); scanf("%d", &idTrainTrajet);
        while (rechercheTrain(idTrainTrajet, trains, nbTrains)==0){
            printf("le train ayant cet identifiant n'existe pas.");
            printf("Entrer l'identifiant du train associe a ce trajet: "); scanf("%d", &idTrainTrajet);}


        for(int j=0; j<nbTrains; j++)
        {
            if(trains[j].idTrain==idTrainTrajet)
            {
                strcpy(NVtrajet.trajetTrain.nomTrain, trains[j].nomTrain);
                NVtrajet.trajetTrain.idTrain=trains[j].idTrain;
                NVtrajet.trajetTrain.nbrPlacesMax=trains[j].nbrPlacesMax;
            }
        }

        printf("Le train associe a ce trajet: %s\n", NVtrajet.trajetTrain.nomTrain);
        printf("Nombre de places maximal: %d\n", NVtrajet.trajetTrain.nbrPlacesMax);

        buffer1[0]=NVtrajet.villeDep[0];
        buffer1[1]=NVtrajet.villeDep[1];
        buffer1[2]=NVtrajet.villeArr[0];
        buffer1[3]=NVtrajet.villeArr[1];
        strcat(buffer1,NVtrajet.dateTrajet.jour);
        strcat(buffer1,NVtrajet.dateTrajet.mois);
        strcat(buffer1,NVtrajet.dateTrajet.annee);

        strcpy(buffer2,buffer1);
        strcat(buffer2,NVtrajet.heureDep.heure);
        strcat(buffer2,NVtrajet.heureDep.minute);

        strcpy(NVtrajet.idTrajetJour,buffer1);
        strcpy(NVtrajet.idTrajet,buffer2);

        printf("L'identifiant de ce trajet: %s", NVtrajet.idTrajet);

        nfile = fopen("fichierNouveauTrajets.txt","a");
        for (int i=0; i<nbTrajets; i++){
            if (strcmp(trajets[i].idTrajet,idTM)!=0)
                fwrite(&trajets[i], sizeof(trajets[i]), 1, nfile);

            else
                fwrite(&NVtrajet, sizeof(NVtrajet), 1, nfile);
        }
        fclose(nfile);
        rename("fichierNouveauTrajets.txt", "fichierDesTrajets.txt");
    }
    else
        printf("\nLe trajet ayant cet identifiant n'existe pas.");
}

void supprimerTrajet()
{
    int ch12;
    char IdTS[20];
    printf("\n\tIdentifiant du trajet a supprimer : "); scanf("%s", &IdTS);
    file = fopen("fichierDesTrajets.txt", "r");
    int nbTrajets = 0;
    while(fread(&trajet, sizeof(trajet), 1, file))
    {
        trajets[nbTrajets]=trajet;
        nbTrajets++;
    }
    fclose(file);

    if (rechercheTrajet(IdTS, trajets, nbTrajets))
    {
        remove("fichierDesTrajets.txt");
        nf = fopen("fichierTrajetsSupprimes.txt", "a");
        for (int i=0; i<nbTrajets; i++)
        {
            if (strcmp(trajets[i].idTrajet,IdTS)!=0)
                fwrite(&trajets[i], sizeof(trajets[i]), 1, nf);
        }
        fclose(nf);
        rename("fichierTrajetsSupprimes.txt", "fichierDesTrajets.txt");
        printf("\nTrajet supprime avec succes.");
    }
    else
        printf("Le trajet ayant cet identifiant n'existe pas.");
}

int rechercheTrajet(char idTM[20], STrajet trajets[50], int nbTrajets)
{
    for(int i=0; i<nbTrajets; i++)
    {
        if (strcmp(trajets[i].idTrajet,idTM)==0)
            return 1;
    }
    return 0;
}

int rechercheTrajetJour(char idTM[15], STrajet trajets[50], int nbTrajets)
{
    for(int i=0; i<nbTrajets; i++)
    {
        if (strcmp(trajets[i].idTrajetJour,idTM)==0)
            return 1;
    }
    return 0;
}

int rechercheTrain(int idTrainTrajet, STrain trains[30], int nbTrains)
{
    for(int i=0; i<nbTrains; i++)
    {
        if (trains[i].idTrain==idTrainTrajet)
            return 1;
    }
    return 0;
}

int rechercheTitre(int idTitre, STitre titres[50], int nbTitres)
{
    for(int j=0; j<nbTitres; j++)
    {
        if(titres[j].idTitre==idTitre)
            return 1;
    }
    return 0;
}

void supprimerTrain()
{
    int ch12, IdTS;
    printf("\n\tIdentifiant du trajet a supprimer : "); scanf("%d", &IdTS);
    int nbTrains = 0;
    file1 = fopen("fTrains.txt", "r");
    while (fread(&train, sizeof(train), 1, file1)){
        trains[nbTrains] = train;
        nbTrains++;
    }
    fclose(file1);

    if (rechercheTrain(IdTS, trains, nbTrains))
    {
        remove("fTrains.txt");
        nf = fopen("fichierTrainsSupprimes.txt", "a");
        for (int i=0; i<nbTrains; i++)
        {
            if (trains[i].idTrain!=IdTS)
                fwrite(&trains[i], sizeof(trains[i]), 1, nf);
        }
        fclose(nf);
        rename("fichierTrainsSupprimes.txt", "fTrains.txt");
        printf("\nTrain supprime avec succes.");
    }
    else
        printf("Le train ayant cet identifiant n'existe pas.");
}

void modifierTrain()
{
    int idTM;
    printf("\nEntrer l'identifiant du trajet que vous voulez modifier: "); scanf("%d", &idTM);
    int nbTrains = 0;
    file1 = fopen("fTrains.txt", "r");
    while (fread(&train, sizeof(train), 1, file1)){
        trains[nbTrains] = train;
        nbTrains++;
    }
    fclose(file1);
    if (rechercheTrain(idTM, trains, nbTrains))
    {
        remove("fTrains.txt");
        printf("\n\t\tNom du train : "); scanf("%s", &NVtrain.nomTrain);
        printf("\t\tNombre de places maximal : "); scanf("%d", &NVtrain.nbrPlacesMax);
        NVtrain.idTrain=idTM;

        nfile1 = fopen("fichierNouveauTrains.txt","a");
        for (int i=0; i<nbTrains; i++){
            if (trains[i].idTrain!=NVtrain.idTrain)
                fwrite(&trains[i], sizeof(trains[i]), 1, nfile1);

            else
                fwrite(&NVtrain, sizeof(NVtrain), 1, nfile1);
        }
        fclose(nfile1);
        rename("fichierNouveauTrains.txt", "fTrains.txt");
        printf("\nTrain modifie avec succes.");
    }
    else
        printf("\nLe train ayant cet identifiant n'existe pas.");
}

void afficherTrains()
{
    int nbTrains = 0;
    file1 = fopen("fTrains.txt", "r");
    while (fread(&train, sizeof(train), 1, file1)){
        trains[nbTrains] = train;
        nbTrains++;
    }
    fclose(file1);

    for (int i=0; i<nbTrains; i++)
    {
        printf("\nIdentifiant du train : %d", trains[i].idTrain);
        printf("\nNom du train : %s", trains[i].nomTrain);
        printf("\nNombre de places maximal : %d", trains[i].nbrPlacesMax);
        printf("\n");
    }
}

void ajouterTrain()
{
    printf("Enter le nom du train: "); scanf("%s", &train.nomTrain);
    printf("Enter l'identifiant du train: "); scanf("%d", &train.idTrain);
    printf("Entrer le nombre des places maximal de ce train: "); scanf("%d", &train.nbrPlacesMax);

    file1 = fopen("fTrains.txt", "a");
    fwrite(&train, sizeof(train), 1, file1);
    if (fwrite != 0) printf("\nTrain ajoute avec succes.\n");
    else printf("erreur");
    fclose(file1);
}

int espaceTrajets()
{
    int choix;
    printf("\n\n\t******************************************");
    printf("\n\t\tEspace des trajets");
    printf("\n\t******************************************");
    do{
    printf("\n1-Ajouter un trajet");
    printf("\t2- Modifier un trajet\n");
    printf("\t3- Supprimer un trajet\n");
    printf("\n4-Afficher les trajets");
    printf("\t5- Retour\n");
    printf("\n\tChoisir le service : ");
    scanf("%d", &choix);
    switch(choix){
        case 1:
            ajouterTrajet();
        break;
        case 2:
            modifierTrajet();
        break;
        case 3:
            supprimerTrajet();
        break;
        case 4:
            afficherTrajets();
        break;
        case 5:
            printf("\nRetour vers le menu principal.\n");
            return 0;
        break;
        default:
            printf("choix invalide, veuillez réessayer!\n");
            espaceTrajets();
        break;
    }
    } while (choix != 5);
}

int espaceTrains()
{
    int choix;
    printf("\n\n\t******************************************");
    printf("\n\t\tEspace des trains");
    printf("\n\t******************************************");
    do{
    printf("\n1-Ajouter un train");
    printf("\t2- Modifier un train\n");
    printf("\t3- Supprimer un train\n");
    printf("\n4-Afficher les trains");
    printf("\t5- Retour\n");
    printf("\n\tChoisir le service : ");
    scanf("%d", &choix);
    switch(choix){
        case 1:
            ajouterTrain();
        break;
        case 2:
            modifierTrain();
        break;
        case 3:
            supprimerTrain();
        break;
        case 4:
            afficherTrains();
        break;
        case 5:
            printf("\nRetour vers le menu principal.\n");
            return 0;
        break;
        default:
            printf("choix invalide, veuillez réessayer!\n");
            espaceTrains();
        break;
    }
    } while (choix != 5);
}

int allerSimpleVerifi(int nbTrajets, STrajet trajets[50], char buff[15], STicket ticket)
{
    int in=0, L1[5];
    for (int i=0; i<nbTrajets; i++)
    {
        if(strcmp(trajets[i].idTrajetJour, buff)==0 && trajets[i].placesReservees<trajets[i].trajetTrain.nbrPlacesMax)
        {
            L1[in]=i;
            in++;
            printf("\n%d-Ville de depart : %s", in, trajets[i].villeDep);
            printf("\nVille d'arrivee : %s", trajets[i].villeArr);
            printf("\nPrix : %f DH", trajets[i].Prix);
            printf("\nTrain : %s", trajets[i].trajetTrain.nomTrain);
            printf("\nHeure de depart : %s:%s", trajets[i].heureDep.heure, trajets[i].heureDep.minute);
            printf("\nHeure d'arrivee : %s:%s", trajets[i].heureArr.heure, trajets[i].heureArr.minute);
            printf("\nDuree : %sh%smin", trajets[i].Duree.heure, trajets[i].Duree.minute);
            printf("\nDate : %s/%s/%s\n", trajets[i].dateTrajet.jour, trajets[i].dateTrajet.mois, trajets[i].dateTrajet.annee);
        }
    }
    switch(in){
        case 0:
            printf("\nLes trains sont tous pleins.");
        break;
        case 1:
            ;
            int ch14;
            do
            {
            printf("\nVoulez-vous reserver?");
            printf("\nOui           |        taper<1>");
            printf("\nNon           |        taper<2>");
            printf("\n=====> ");
            scanf("%d", &ch14);
            switch(ch14){
            case 2:
                printf("\nRetour vers le menu principal.\n");
                return 0;
            break;
            case 1:
                ;
                int ch15;
                do
                {
                printf("\nVous etes un EIOR?");
                printf("\nOui           |        taper<1>");
                printf("\nNon           |        taper<2>");
                printf("\n====> ");
                scanf("%d", &ch15);
                switch(ch15){
                    case 1:
                        ;
                        int idTitre1, b1;
                        printf("\nEntrer l'identifiant de votre titre de permission: "); scanf("%d", &idTitre1);
                        int nbTitres = 0;
                        fileT = fopen("fichierDesTitresPermission.txt", "r");
                        while (fread(&titre, sizeof(titre), 1, fileT)){
                            titres[nbTitres] = titre;
                            nbTitres++;
                        }
                        fclose(fileT);
                        if (rechercheTitre(idTitre1, titres, nbTitres))
                        {
                            for(int i=0; i<nbTitres; i++)
                            {
                                if(titres[i].idTitre==idTitre1)
                                    b1=i;
                            }
                            if(strcmp(trajets[L1[0]].villeDep,titres[b1].villeDep)==0 && strcmp(trajets[L1[0]].villeArr,titres[b1].villeArr)==0)
                            {
                                if(titres[b1].nbrUtilisation<2)
                                {
                                    printf("\nVoici le billet de ce voyage:\n");
                                    printf("\nVille de depart : %s", trajets[L1[0]].villeDep);
                                    printf("\nVille d'arrivee : %s", trajets[L1[0]].villeArr);
                                    printf("\nPrix : %f DH", (trajets[L1[0]].Prix)*0.3);
                                    printf("\nTrain : %s", trajets[L1[0]].trajetTrain.nomTrain);
                                    printf("\nHeure de depart : %s:%s", trajets[L1[0]].heureDep.heure, trajets[L1[0]].heureDep.minute);
                                    printf("\nHeure d'arrivee : %s:%s", trajets[L1[0]].heureArr.heure, trajets[L1[0]].heureArr.minute);
                                    printf("\nDuree : %sh%smin", trajets[L1[0]].Duree.heure, trajets[L1[0]].Duree.minute);
                                    printf("\nDate : %s/%s/%s", trajets[L1[0]].dateTrajet.jour, trajets[L1[0]].dateTrajet.mois, trajets[L1[0]].dateTrajet.annee);
                                    printf("\n");
                                    int ch17;
                                    do
                                    {
                                        printf("\nvoulez-vous reserver?");
                                        printf("\nOui           |        taper<1>");
                                        printf("\nNon           |        taper<2>");
                                        printf("\n=====> ");
                                        scanf("%d", &ch17);
                                        switch(ch17){
                                        case 1:
                                            ;
                                            char buf[15];
                                            strcpy(buf,titres[b1].villeDep);
                                            strcpy(titres[b1].villeDep,titres[b1].villeArr);
                                            strcpy(titres[b1].villeArr,buf);
                                            (titres[b1].nbrUtilisation)+=1;
                                            remove("fichierDesTitresPermission.txt");
                                            nfile = fopen("fichierNouveauTitres.txt","a");
                                            for (int i=0; i<nbTitres; i++){
                                                if (titres[i].idTitre!=titres[b1].idTitre)
                                                    fwrite(&titres[i], sizeof(titres[i]), 1, nfile);

                                                else
                                                    fwrite(&titres[b1], sizeof(titres[b1]), 1, nfile);
                                            }
                                            fclose(nfile);
                                            rename("fichierNouveauTitres.txt", "fichierDesTitresPermission.txt");
                                            (trajets[L1[0]].placesReservees)+=1;
                                            remove("fichierDesTrajets.txt");
                                            nfile = fopen("fichierNouveauTrajets.txt","a");
                                            for (int i=0; i<nbTrajets; i++){
                                                if (strcmp(trajets[i].idTrajet,trajets[L1[0]].idTrajet)!=0)
                                                    fwrite(&trajets[i], sizeof(trajets[i]), 1, nfile);

                                                else
                                                    fwrite(&trajets[L1[0]], sizeof(trajets[L1[0]]), 1, nfile);
                                            }
                                            fclose(nfile);
                                            rename("fichierNouveauTrajets.txt", "fichierDesTrajets.txt");
                                            file2 = fopen("fichierTickets.txt", "a");
                                            fwrite(&ticket, sizeof(ticket), 1, file2);
                                            fclose(file2);
                                            printf("\nLa reservation est bien faite. Merci.\n");
                                            return 0;
                                        break;
                                        case 2:
                                            printf("\nRetour vers le menu principal.\n");
                                            return 0;
                                        break;
                                        default:
                                            printf("choix invalide, veuillez reessayer!\n");
                                            allerSimple();
                                        break;
                                        }
                                    }while(ch17!=2);
                                }
                                else
                                    printf("\nCe titre de permission est deja utilise!");
                            }
                            else
                                printf("\nVous ne pouvez pas utiliser ce titre de permission pour acheter ce billet.");
                        }
                        else
                            printf("\nLe titre de permission ayant cet identifiant n'existe pas.");
                    return 0;
                    break;
                    case 2:
                        (trajets[L1[0]].placesReservees)+=1;
                        remove("fichierDesTrajets.txt");
                        nfile = fopen("fichierNouveauTrajets.txt","a");
                        for (int i=0; i<nbTrajets; i++){
                            if (strcmp(trajets[i].idTrajet,trajets[L1[0]].idTrajet)!=0)
                                fwrite(&trajets[i], sizeof(trajets[i]), 1, nfile);

                            else
                                fwrite(&trajets[L1[0]], sizeof(trajets[L1[0]]), 1, nfile);
                        }
                        fclose(nfile);
                        rename("fichierNouveauTrajets.txt", "fichierDesTrajets.txt");
                        file2 = fopen("fichierTickets.txt", "a");
                        fwrite(&ticket, sizeof(ticket), 1, file2);
                        fclose(file2);
                        printf("\nVoici le billet de votre voyage:\n");
                        printf("\nVille de depart : %s", trajets[L1[0]].villeDep);
                        printf("\nVille d'arrivee : %s", trajets[L1[0]].villeArr);
                        printf("\nPrix : %f DH", trajets[L1[0]].Prix);
                        printf("\nTrain : %s", trajets[L1[0]].trajetTrain.nomTrain);
                        printf("\nHeure de depart : %s:%s", trajets[L1[0]].heureDep.heure, trajets[L1[0]].heureDep.minute);
                        printf("\nHeure d'arrivee : %s:%s", trajets[L1[0]].heureArr.heure, trajets[L1[0]].heureArr.minute);
                        printf("\nDuree : %sh%smin", trajets[L1[0]].Duree.heure, trajets[L1[0]].Duree.minute);
                        printf("\nDate : %s/%s/%s", trajets[L1[0]].dateTrajet.jour, trajets[L1[0]].dateTrajet.mois, trajets[L1[0]].dateTrajet.annee);
                        printf("\n");
                        printf("\nLa reservation est bien faite. Merci.\n");
                    return 0;
                    break;
                    default:
                        printf("choix invalide, veuillez réessayer!\n");
                        allerSimple();
                    break;
                }
                }while(ch15!=2);
            break;
            default:
                printf("choix invalide, veuillez réessayer!\n");
                allerSimple();
            break;
            }
            }while(ch14!=2);
        break;
        default:
            ;
            int ch18;
            do
            {
            printf("\nVoulez-vous reserver?");
            printf("\nOui           |        taper<1>");
            printf("\nNon           |        taper<2>");
            printf("\n====> ");
            scanf("%d", &ch18);
            switch(ch18){
            case 2:
                printf("\nRetour vers le menu principal.\n");
                return 0;
            break;
            case 1:
                ;
                int ch19, inc;
                do
                {
                printf("\nEntrer votre choix: "); scanf("%d", &inc);
                while(inc>in){
                    printf("\nEntrer votre choix: "); scanf("%d", &inc);
                }
                printf("\nVous etes un EIOR?");
                printf("\nOui           |        taper<1>");
                printf("\nNon           |        taper<2>");
                printf("\n=====> "); scanf("%d", &ch19);
                switch(ch19){
                    case 1:
                        ;
                        int idTitre1, b1;
                        printf("\nEntrer l'identifiant de votre titre de permission: "); scanf("%d", &idTitre1);
                        int nbTitres = 0;
                        fileT = fopen("fichierDesTitresPermission.txt", "r");
                        while (fread(&titre, sizeof(titre), 1, fileT)){
                            titres[nbTitres] = titre;
                            nbTitres++;
                        }
                        fclose(fileT);
                        if (rechercheTitre(idTitre1, titres, nbTitres))
                        {
                            for(int i=0; i<nbTitres; i++)
                            {
                                if(titres[i].idTitre==idTitre1)
                                    b1=i;
                            }
                            if(strcmp(trajets[L1[inc-1]].villeDep,titres[b1].villeDep)==0 && strcmp(trajets[L1[inc-1]].villeArr,titres[b1].villeArr)==0)
                            {
                                if(titres[b1].nbrUtilisation<2)
                                {
                                    printf("\nVoici le billet de ce voyage:\n");
                                    printf("\nVille de depart : %s", trajets[L1[inc-1]].villeDep);
                                    printf("\nVille d'arrivee : %s", trajets[L1[inc-1]].villeArr);
                                    printf("\nPrix : %f DH", (trajets[L1[inc-1]].Prix)*0.3);
                                    printf("\nTrain : %s", trajets[L1[inc-1]].trajetTrain.nomTrain);
                                    printf("\nHeure de depart : %s:%s", trajets[L1[inc-1]].heureDep.heure, trajets[L1[inc-1]].heureDep.minute);
                                    printf("\nHeure d'arrivee : %s:%s", trajets[L1[inc-1]].heureArr.heure, trajets[L1[inc-1]].heureArr.minute);
                                    printf("\nDuree : %sh%smin", trajets[L1[inc-1]].Duree.heure, trajets[L1[inc-1]].Duree.minute);
                                    printf("\nDate : %s/%s/%s", trajets[L1[inc-1]].dateTrajet.jour, trajets[L1[inc-1]].dateTrajet.mois, trajets[L1[inc-1]].dateTrajet.annee);
                                    printf("\n");
                                    int ch17;
                                    do
                                    {
                                        printf("\nvoulez-vous reserver?");
                                        printf("\nOui           |        taper<1>");
                                        printf("\nNon           |        taper<2>");
                                        printf("\n=====> ");
                                        scanf("%d", &ch17);
                                        switch(ch17){
                                        case 1:
                                            ;
                                            char buf[15];
                                            strcpy(buf,titres[b1].villeDep);
                                            strcpy(titres[b1].villeDep,titres[b1].villeArr);
                                            strcpy(titres[b1].villeArr,buf);
                                            (titres[b1].nbrUtilisation)+=1;
                                            remove("fichierDesTitresPermission.txt");
                                            nfile = fopen("fichierNouveauTitres.txt","a");
                                            for (int i=0; i<nbTitres; i++){
                                                if (titres[i].idTitre!=titres[b1].idTitre)
                                                    fwrite(&titres[i], sizeof(titres[i]), 1, nfile);

                                                else
                                                    fwrite(&titres[b1], sizeof(titres[b1]), 1, nfile);
                                            }
                                            fclose(nfile);
                                            rename("fichierNouveauTitres.txt", "fichierDesTitresPermission.txt");
                                            (trajets[L1[inc-1]].placesReservees)+=1;
                                            remove("fichierDesTrajets.txt");
                                            nfile = fopen("fichierNouveauTrajets.txt","a");
                                            for (int i=0; i<nbTrajets; i++){
                                                if (strcmp(trajets[i].idTrajet,trajets[L1[0]].idTrajet)!=0)
                                                    fwrite(&trajets[i], sizeof(trajets[i]), 1, nfile);
                                                else
                                                    fwrite(&trajets[L1[inc-1]], sizeof(trajets[L1[inc-1]]), 1, nfile);
                                            }
                                            fclose(nfile);
                                            rename("fichierNouveauTrajets.txt", "fichierDesTrajets.txt");
                                            file2 = fopen("fichierTickets.txt", "a");
                                            fwrite(&ticket, sizeof(ticket), 1, file2);
                                            fclose(file2);
                                            printf("\nLa reservation est bien faite. Merci.\n");
                                            return 0;
                                        break;
                                        case 2:
                                            printf("\nRetour vers le menu principal.\n");
                                            return 0;
                                        break;
                                        default:
                                            printf("choix invalide, veuillez reessayer!\n");
                                            allerSimple();
                                        break;
                                        }
                                    }while(ch17!=2);
                                }
                                else
                                    printf("\nCe titre de permission est deja utilise!");
                            }
                            else
                                printf("\nVous ne pouvez pas utiliser ce titre de permission pour acheter ce billet.");
                        }
                        else
                            printf("\nLe titre de permission ayant cet identifiant n'existe pas.");
                    return 0;
                    break;
                    case 2:
                        (trajets[L1[inc-1]].placesReservees)+=1;
                        remove("fichierDesTrajets.txt");
                        nfile = fopen("fichierNouveauTrajets.txt","a");
                        for (int i=0; i<nbTrajets; i++){
                            if (strcmp(trajets[i].idTrajet,trajets[L1[inc-1]].idTrajet)!=0)
                                fwrite(&trajets[i], sizeof(trajets[i]), 1, nfile);

                            else
                                fwrite(&trajets[L1[inc-1]], sizeof(trajets[L1[inc-1]]), 1, nfile);
                        }
                        fclose(nfile);
                        rename("fichierNouveauTrajets.txt", "fichierDesTrajets.txt");
                        file2 = fopen("fichierTickets.txt", "a");
                        fwrite(&ticket, sizeof(ticket), 1, file2);
                        fclose(file2);
                        printf("\nVoici le billet de votre voyage:\n");
                        printf("\nVille de depart : %s", trajets[L1[inc-1]].villeDep);
                        printf("\nVille d'arrivee : %s", trajets[L1[inc-1]].villeArr);
                        printf("\nPrix : %f DH", trajets[L1[inc-1]].Prix);
                        printf("\nTrain : %s", trajets[L1[inc-1]].trajetTrain.nomTrain);
                        printf("\nHeure de depart : %s:%s", trajets[L1[inc-1]].heureDep.heure, trajets[L1[inc-1]].heureDep.minute);
                        printf("\nHeure d'arrivee : %s:%s", trajets[L1[inc-1]].heureArr.heure, trajets[L1[inc-1]].heureArr.minute);
                        printf("\nDuree : %sh%smin", trajets[L1[inc-1]].Duree.heure, trajets[L1[inc-1]].Duree.minute);
                        printf("\nDate : %s/%s/%s", trajets[L1[inc-1]].dateTrajet.jour, trajets[L1[inc-1]].dateTrajet.mois, trajets[L1[inc-1]].dateTrajet.annee);
                        printf("\n");
                        printf("\nLa reservation est bien faite. Merci.\n");
                    return 0;
                    break;
                    default:
                        printf("choix invalide, veuillez réessayer!\n");
                        allerSimple();
                    break;
                }
                }while(ch19!=2);
            break;
            default:
                printf("choix invalide, veuillez réessayer!\n");
                allerSimple();
            break;
            }
            }while(ch18!=2);
        break;
    }
}

/*int doubleReservation(int C1, int c2, STrajet trajets[50], STicket ticket, STitres titres[50])
{
    int ch24;
    do
    {
        printf("\nvoulez-vous l'ajouter au panier?");
        printf("\nOui           |        taper<1>");
        printf("\nNon           |        taper<2>");
        printf("\n=====> ");
        scanf("%d", &ch24);
        switch(ch24)
        {
        case 1:
            printf("\n\tBillet d'aller:                                      \tBiller de retour:");
            printf("\nVille de depart : %s                                  Ville de depart : %s", trajets[L1[0]].villeDep, trajets[L2[0]].villeDep);
            printf("\nVille d'arrivee : %s                                  Ville d'arrivee : %s", trajets[L1[0]].villeArr, trajets[L2[0]].villeArr);
            printf("\nPrix : %f DH                                          Prix : %f DH", trajets[L1[0]].Prix, (trajets[L2[0]].Prix)*0.3);
            printf("\nTrain : %s                                            Train : %s", trajets[L1[0]].trajetTrain.nomTrain, trajets[L2[0]].trajetTrain.nomTrain);
            printf("\nHeure de depart : %s:%s                               Heure de depart : %s:%s", trajets[L1[0]].heureDep.heure, trajets[L1[0]].heureDep.minute, trajets[L2[0]].heureDep.heure, trajets[L2[0]].heureDep.minute);
            printf("\nHeure d'arrivee : %s:%s                               Heure d'arrivee : %s:%s", trajets[L1[0]].heureArr.heure, trajets[L1[0]].heureArr.minute, trajets[L2[0]].heureArr.heure, trajets[L2[0]].heureArr.minute);
            printf("\nDuree : %sh%smin                                      Duree : %sh%smin", trajets[L1[0]].Duree.heure, trajets[L1[0]].Duree.minute, trajets[L2[0]].Duree.heure, trajets[L2[0]].Duree.minute);
            printf("\nDate : %s/%s/%s                                       Date : %s/%s/%s\n", trajets[L1[0]].dateTrajet.jour, trajets[L1[0]].dateTrajet.mois, trajets[L1[0]].dateTrajet.annee, trajets[L2[0]].dateTrajet.jour, trajets[L2[0]].dateTrajet.mois, trajets[L2[0]].dateTrajet.annee);
            printf("\n                         Montant total: %f DH", (trajets[L1[0]].Prix)+(trajets[L2[0]].Prix));
            int ch25;
            do
            {
                printf("\nVoulez-vous completer l'achat des deux billets?");
                printf("\n1-Oui         |       taper<1>");
                printf("\n2-Non         |       taper<2>");
                printf("\n====> "); scanf("%d", &ch25);
                switch(ch25)
                {
                case 1:
                    strcpy(NVticket.nom,ticket.nom);
                    strcpy(NVticket.prenom,ticket.prenom);
                    strcpy(NVticket.stationDep,ticket.stationArr);
                    strcpy(NVticket.stationArr,ticket.stationDep);
                    strcpy(NVticket.dateDep.jour,dateRetJour);
                    strcpy(NVticket.dateDep.mois,dateRetMois);
                    strcpy(NVticket.dateDep.annee,dateRetAnnee);

                    (titres[b1].nbrUtilisation)+=2;
                    remove("fichierDesTitresPermission.txt");
                    nfile = fopen("fichierNouveauTitres.txt","a");
                    for (int i=0; i<nbTitres; i++){
                        if (titres[i].idTitre!=titres[b1].idTitre)
                            fwrite(&titres[i], sizeof(titres[i]), 1, nfile);

                        else
                            fwrite(&titres[b1], sizeof(titres[b1]), 1, nfile);
                    }
                    fclose(nfile);
                    rename("fichierNouveauTitres.txt", "fichierDesTitresPermission.txt");
                    (trajets[L1[0]].placesReservees)+=1;
                    (trajets[L2[0]].placesReservees)+=1;
                    remove("fichierDesTrajets.txt");
                    nfile = fopen("fichierNouveauTrajets.txt","a");
                    for (int i=0; i<nbTrajets; i++){
                        if (strcmp(trajets[i].idTrajet,trajets[L1[0]].idTrajet)==0)
                            fwrite(&trajets[L1[0]], sizeof(trajets[L1[0]]), 1, nfile);
                        else
                        {
                            if(strcmp(trajets[i].idTrajet,trajets[L2[0]].idTrajet)==0)
                                fwrite(&trajets[L2[0]], sizeof(trajets[L2[0]]), 1, nfile);
                            else
                                fwrite(&trajets[i], sizeof(trajets[i]), 1, nfile);
                        }
                    }
                    fclose(nfile);
                    rename("fichierNouveauTrajets.txt", "fichierDesTrajets.txt");
                    file2 = fopen("fichierTickets.txt", "a");
                    fwrite(&ticket, sizeof(ticket), 1, file2);
                    fwrite(&NVticket, sizeof(NVticket), 1, file2);
                    fclose(file2);
                    printf("\nLa reservation est bien faite. Merci.\n");
                    return 0;
                break;
                case 2:
                    printf("\nRetour vers le menu principal.\n");
                    return 0;
                break;
                default:
                    printf("choix invalide, veuillez reessayer!\n");
                    allerRetour();
                break;
                }
            }while(ch25!=2);
        break;
        case 2:
            ;
            int ch22;
            printf("\nVoulez-vous completer l'achat du billet d'aller?");
            printf("\n1-Oui         |       taper<1>");
            printf("\n2-Non         |       taper<2>");
            printf("\n====> "); scanf("%d", &ch22);
            switch(ch22)
            {
            case 1:
                ;
                char buf[15];
                strcpy(buf,titres[b1].villeDep);
                strcpy(titres[b1].villeDep,titres[b1].villeArr);
                strcpy(titres[b1].villeArr,buf);
                (titres[b1].nbrUtilisation)+=1;
                remove("fichierDesTitresPermission.txt");
                nfile = fopen("fichierNouveauTitres.txt","a");
                for (int i=0; i<nbTitres; i++){
                    if (titres[i].idTitre!=titres[b1].idTitre)
                        fwrite(&titres[i], sizeof(titres[i]), 1, nfile);

                    else
                        fwrite(&titres[b1], sizeof(titres[b1]), 1, nfile);
                }
                fclose(nfile);
                rename("fichierNouveauTitres.txt", "fichierDesTitresPermission.txt");
                (trajets[L1[0]].placesReservees)+=1;
                remove("fichierDesTrajets.txt");
                nfile = fopen("fichierNouveauTrajets.txt","a");
                for (int i=0; i<nbTrajets; i++){
                    if (strcmp(trajets[i].idTrajet,trajets[L1[0]].idTrajet)!=0)
                        fwrite(&trajets[i], sizeof(trajets[i]), 1, nfile);

                    else
                        fwrite(&trajets[L1[0]], sizeof(trajets[L1[0]]), 1, nfile);
                }
                fclose(nfile);
                rename("fichierNouveauTrajets.txt", "fichierDesTrajets.txt");
                file2 = fopen("fichierTickets.txt", "a");
                fwrite(&ticket, sizeof(ticket), 1, file2);
                fclose(file2);
                printf("\nLa reservation est bien faite. Merci.\n");
                return 0;
            break;
            case 2:
                printf("\nRetour vers le menu principal.\n");
                return 0;
            break;
            default:
                printf("choix invalide, veuillez reessayer!\n");
                allerRetour();
            break;
            }
        break;
        default:
            printf("choix invalide, veuillez reessayer!\n");
            allerRetour();
        break;
        }
    }while(ch24!=2);
}*/

void allerSimple()
{
    char buffer[6], buff[15];
    printf("\nVeillez remplir les champs suivants:");
    printf("\nNom: "); scanf("%s", &ticket.nom);
    printf("\nPrenom: "); scanf("%s", &ticket.prenom);
    printf("\nVille de depart: "); scanf("%s", &ticket.stationDep);
    printf("\nVille d'arrivee: "); scanf("%s", &ticket.stationArr);
    printf("\nDate de depart: ");
    printf("\nJour (en 2 chiffres): "); scanf("%s", &ticket.dateDep.jour);
    printf("\nMois (en 2 chiffres): "); scanf("%s", &ticket.dateDep.mois);
    printf("\nAnnee (en 4 chiffres): "); scanf("%s", &ticket.dateDep.annee);
    printf("\n");

    buffer[0]=toupper(ticket.stationDep[0]);
    buffer[1]=toupper(ticket.stationDep[1]);
    buffer[2]=toupper(ticket.stationArr[0]);
    buffer[3]=toupper(ticket.stationArr[1]);

    strcpy(buff, buffer);
    strcat(buff,ticket.dateDep.jour);
    strcat(buff,ticket.dateDep.mois);
    strcat(buff,ticket.dateDep.annee);

    int nbTrajets = 0;
    file = fopen("fichierDesTrajets.txt", "r");
    while (fread(&trajet, sizeof(trajet), 1, file)){
        trajets[nbTrajets] = trajet;
        nbTrajets++;
    }
    fclose(file);

    if(rechercheTrajetJour(buff, trajets, nbTrajets))
    {
        allerSimpleVerifi(nbTrajets, trajets, buff, ticket);
    }
    else
        printf("\nPas de trains disponibles.");
}


int allerRetour()
{
    int ch21;
    do
    {
        printf("\nVous etes un EIOR?");
        printf("\nOui           |        taper<1>");
        printf("\nNon           |        taper<2>");
        printf("\n====> ");
        scanf("%d", &ch21);
        switch(ch21)
        {
        case 1:
            ;
            char buffer[6], buffer1[6], buff[15], buff1[15], dateRetJour[3], dateRetMois[3], dateRetAnnee[5];
            printf("\nVeillez remplir les champs suivants:");
            printf("\nNom: "); scanf("%s", &ticket.nom);
            printf("\nPrenom: "); scanf("%s", &ticket.prenom);
            printf("\nVille de depart: "); scanf("%s", &ticket.stationDep);
            printf("\nVille d'arrivee: "); scanf("%s", &ticket.stationArr);
            printf("\nDate de depart: ");
            printf("\nJour (en 2 chiffres): "); scanf("%s", &ticket.dateDep.jour);
            printf("\nMois (en 2 chiffres): "); scanf("%s", &ticket.dateDep.mois);
            printf("\nAnnee (en 4 chiffres): "); scanf("%s", &ticket.dateDep.annee);
            printf("\n");
            printf("\nDate de retour: ");
            printf("\nJour (en 2 chiffres): "); scanf("%s", &dateRetJour);
            printf("\nMois (en 2 chiffres): "); scanf("%s", &dateRetMois);
            printf("\nAnnee (en 4 chiffres): "); scanf("%s", &dateRetAnnee);
            printf("\n");

            buffer[0]=toupper(ticket.stationDep[0]);
            buffer[1]=toupper(ticket.stationDep[1]);
            buffer[2]=toupper(ticket.stationArr[0]);
            buffer[3]=toupper(ticket.stationArr[1]);

            buffer1[0]=toupper(ticket.stationArr[0]);
            buffer1[1]=toupper(ticket.stationArr[1]);
            buffer1[2]=toupper(ticket.stationDep[0]);
            buffer1[3]=toupper(ticket.stationDep[1]);

            strcpy(buff, buffer);
            strcat(buff,ticket.dateDep.jour);
            strcat(buff,ticket.dateDep.mois);
            strcat(buff,ticket.dateDep.annee);

            strcpy(buff1, buffer1);
            strcat(buff1,dateRetJour);
            strcat(buff1,dateRetMois);
            strcat(buff1,dateRetAnnee);

            int nbTrajets = 0;
            file = fopen("fichierDesTrajets.txt", "r");
            while (fread(&trajet, sizeof(trajet), 1, file)){
                trajets[nbTrajets] = trajet;
                nbTrajets++;
            }
            fclose(file);

            if(rechercheTrajetJour(buff, trajets, nbTrajets))
            {
                if(rechercheTrajetJour(buff1, trajets, nbTrajets))
                {
                    printf("\n           <<<<<ALLER:>>>>>");
                    printf("\n\nTrains proposes pour la date de depart: \n");
                    int in=0, L1[5];
                    for (int i=0; i<nbTrajets; i++)
                    {
                        if(strcmp(trajets[i].idTrajetJour, buff)==0 && trajets[i].placesReservees<trajets[i].trajetTrain.nbrPlacesMax)
                        {
                            L1[in]=i;
                            in++;
                            printf("\n%d-Ville de depart : %s", in, trajets[i].villeDep);
                            printf("\nVille d'arrivee : %s", trajets[i].villeArr);
                            printf("\nPrix : %f DH", trajets[i].Prix);
                            printf("\nTrain : %s", trajets[i].trajetTrain.nomTrain);
                            printf("\nHeure de depart : %s:%s", trajets[i].heureDep.heure, trajets[i].heureDep.minute);
                            printf("\nHeure d'arrivee : %s:%s", trajets[i].heureArr.heure, trajets[i].heureArr.minute);
                            printf("\nDuree : %sh%smin", trajets[i].Duree.heure, trajets[i].Duree.minute);
                            printf("\nDate : %s/%s/%s\n", trajets[i].dateTrajet.jour, trajets[i].dateTrajet.mois, trajets[i].dateTrajet.annee);
                        }
                    }
                    switch(in)
                    {
                    case 0:
                        printf("\nLes trains sont tous pleins.");
                    break;
                    case 1:
                        ;
                        int ch14;
                        do
                        {
                        printf("\nVoulez-vous voir le billet avec la remise?");
                        printf("\nOui           |        taper<1>");
                        printf("\nNon           |        taper<2>");
                        printf("\n=====> ");
                        scanf("%d", &ch14);
                        switch(ch14){
                        case 2:
                            printf("\nRetour vers le menu principal.\n");
                            return 0;
                        break;
                        case 1:
                            ;
                            int idTitre1, b1;
                            printf("\nEntrer l'identifiant de votre titre de permission: "); scanf("%d", &idTitre1);
                            int nbTitres = 0;
                            fileT = fopen("fichierDesTitresPermission.txt", "r");
                            while (fread(&titre, sizeof(titre), 1, fileT)){
                                titres[nbTitres] = titre;
                                nbTitres++;
                            }
                            fclose(fileT);
                            if (rechercheTitre(idTitre1, titres, nbTitres))
                            {
                                for(int i=0; i<nbTitres; i++)
                                {
                                    if(titres[i].idTitre==idTitre1)
                                        b1=i;
                                }
                                if(strcmp(trajets[L1[0]].villeDep,titres[b1].villeDep)==0 && strcmp(trajets[L1[0]].villeArr,titres[b1].villeArr)==0)
                                {
                                    if(titres[b1].nbrUtilisation==0)
                                    {
                                        printf("\nVoici le billet de ce voyage:\n");
                                        printf("\nVille de depart : %s", trajets[L1[0]].villeDep);
                                        printf("\nVille d'arrivee : %s", trajets[L1[0]].villeArr);
                                        printf("\nPrix : %f DH", (trajets[L1[0]].Prix)*0.3);
                                        printf("\nTrain : %s", trajets[L1[0]].trajetTrain.nomTrain);
                                        printf("\nHeure de depart : %s:%s", trajets[L1[0]].heureDep.heure, trajets[L1[0]].heureDep.minute);
                                        printf("\nHeure d'arrivee : %s:%s", trajets[L1[0]].heureArr.heure, trajets[L1[0]].heureArr.minute);
                                        printf("\nDuree : %sh%smin", trajets[L1[0]].Duree.heure, trajets[L1[0]].Duree.minute);
                                        printf("\nDate : %s/%s/%s", trajets[L1[0]].dateTrajet.jour, trajets[L1[0]].dateTrajet.mois, trajets[L1[0]].dateTrajet.annee);
                                        printf("\n");
                                        int ch17;
                                        do
                                        {
                                            printf("\nvoulez-vous l'ajouter au panier?");
                                            printf("\nOui           |        taper<1>");
                                            printf("\nNon           |        taper<2>");
                                            printf("\n=====> ");
                                            scanf("%d", &ch17);
                                            switch(ch17)
                                            {
                                            case 1:
                                                /*strcpy(NVtrajet.idTrajet,trajets[L1[0]].idTrajet);
                                                strcpy(NVtrajet.idTrajetJour,trajets[L1[0]].idTrajetJour);
                                                strcpy(NVtrajet.villeDep,trajets[L1[0]].villeDep);
                                                strcpy(NVtrajet.villeArr,trajets[L1[0]].villeArr);
                                                strcpy(NVtrajet.trajetTrain.nomTrain,trajets[L1[0]].trajetTrain.nomTrain);
                                                NVtrajet.trajetTrain.idTrain=trajets[L1[0]].trajetTrain.idTrain;
                                                NVtrajet.trajetTrain.nbrPlacesMax=trajets[L1[0]].trajetTrain.nbrPlacesMax;
                                                strcpy(NVtrajet.heureDep.heure,trajets[L1[0]].heureDep.heure);
                                                strcpy(NVtrajet.heureDep.minute,trajets[L1[0]].heureDep.minute);
                                                strcpy(NVtrajet.heureArr.heure,trajets[L1[0]].heureArr.heure);
                                                strcpy(NVtrajet.heureArr.minute,trajets[L1[0]].heureArr.minute);
                                                strcpy(NVtrajet.Duree.heure,trajets[L1[0]].Duree.heure);
                                                strcpy(NVtrajet.Duree.minute,trajets[L1[0]].Duree.minute);
                                                strcpy(NVtrajet.dateTrajet.jour,trajets[L1[0]].dateTrajet.jour);
                                                strcpy(NVtrajet.dateTrajet.mois,trajets[L1[0]].dateTrajet.mois);
                                                strcpy(NVtrajet.dateTrajet.annee,trajets[L1[0]].dateTrajet.annee);
                                                NVtrajet.Prix=(trajets[L1[0]].Prix)*0.3;
                                                NVtrajet.placesReservees=trajets[L1[0]].placesReservees;*/

                                                printf("\n           <<<<<Retour:>>>>>");
                                                printf("\n\nTrains proposes pour la date de retour: \n");
                                                int im=0, L2[5];
                                                for (int i=0; i<nbTrajets; i++)
                                                {
                                                    if(strcmp(trajets[i].idTrajetJour, buff1)==0 && trajets[i].placesReservees<trajets[i].trajetTrain.nbrPlacesMax)
                                                    {
                                                        L2[im]=i;
                                                        im++;
                                                        printf("\n%d-Ville de depart : %s", im, trajets[i].villeDep);
                                                        printf("\nVille d'arrivee : %s", trajets[i].villeArr);
                                                        printf("\nPrix original: %f DH", trajets[i].Prix);
                                                        printf("\nPrix apres remise: %f DH", (trajets[i].Prix)*0.3);
                                                        printf("\nTrain : %s", trajets[i].trajetTrain.nomTrain);
                                                        printf("\nHeure de depart : %s:%s", trajets[i].heureDep.heure, trajets[i].heureDep.minute);
                                                        printf("\nHeure d'arrivee : %s:%s", trajets[i].heureArr.heure, trajets[i].heureArr.minute);
                                                        printf("\nDuree : %sh%smin", trajets[i].Duree.heure, trajets[i].Duree.minute);
                                                        printf("\nDate : %s/%s/%s\n", trajets[i].dateTrajet.jour, trajets[i].dateTrajet.mois, trajets[i].dateTrajet.annee);
                                                    }
                                                }
                                                switch(im)
                                                {
                                                case 0:
                                                    printf("\nLes trains de la date de retour sont tous pleins.");
                                                    int ch22;
                                                    do
                                                    {
                                                        printf("\nVoulez-vous completer l'achat du billet d'aller?");
                                                        printf("\n1-Oui         |       taper<1>");
                                                        printf("\n2-Non         |       taper<2>");
                                                        printf("\n====> "); scanf("%d", &ch22);
                                                        switch(ch22)
                                                        {
                                                        case 1:
                                                            ;
                                                            char buf[15];
                                                            strcpy(buf,titres[b1].villeDep);
                                                            strcpy(titres[b1].villeDep,titres[b1].villeArr);
                                                            strcpy(titres[b1].villeArr,buf);
                                                            (titres[b1].nbrUtilisation)+=1;
                                                            remove("fichierDesTitresPermission.txt");
                                                            nfile = fopen("fichierNouveauTitres.txt","a");
                                                            for (int i=0; i<nbTitres; i++){
                                                                if (titres[i].idTitre!=titres[b1].idTitre)
                                                                    fwrite(&titres[i], sizeof(titres[i]), 1, nfile);

                                                                else
                                                                    fwrite(&titres[b1], sizeof(titres[b1]), 1, nfile);
                                                            }
                                                            fclose(nfile);
                                                            rename("fichierNouveauTitres.txt", "fichierDesTitresPermission.txt");
                                                            (trajets[L1[0]].placesReservees)+=1;
                                                            remove("fichierDesTrajets.txt");
                                                            nfile = fopen("fichierNouveauTrajets.txt","a");
                                                            for (int i=0; i<nbTrajets; i++){
                                                                if (strcmp(trajets[i].idTrajet,trajets[L1[0]].idTrajet)!=0)
                                                                    fwrite(&trajets[i], sizeof(trajets[i]), 1, nfile);

                                                                else
                                                                    fwrite(&trajets[L1[0]], sizeof(trajets[L1[0]]), 1, nfile);
                                                            }
                                                            fclose(nfile);
                                                            rename("fichierNouveauTrajets.txt", "fichierDesTrajets.txt");
                                                            file2 = fopen("fichierTickets.txt", "a");
                                                            fwrite(&ticket, sizeof(ticket), 1, file2);
                                                            fclose(file2);
                                                            printf("\nLa reservation est bien faite. Merci.\n");
                                                            return 0;
                                                        break;
                                                        case 2:
                                                            printf("\nRetour vers le menu principal.\n");
                                                            return 0;
                                                        break;
                                                        default:
                                                            printf("choix invalide, veuillez reessayer!\n");
                                                            allerRetour();
                                                        break;
                                                        }
                                                    }while(ch22!=2);
                                                break;
                                                case 1:
                                                    ;
                                                    int ch24;
                                                    do
                                                    {
                                                        printf("\nvoulez-vous l'ajouter au panier?");
                                                        printf("\nOui           |        taper<1>");
                                                        printf("\nNon           |        taper<2>");
                                                        printf("\n=====> ");
                                                        scanf("%d", &ch24);
                                                        switch(ch24)
                                                        {
                                                        case 1:
                                                            printf("\n\tBillet d'aller:                                      \tBiller de retour:");
                                                            printf("\nVille de depart : %s                                  Ville de depart : %s", trajets[L1[0]].villeDep, trajets[L2[0]].villeDep);
                                                            printf("\nVille d'arrivee : %s                                  Ville d'arrivee : %s", trajets[L1[0]].villeArr, trajets[L2[0]].villeArr);
                                                            printf("\nPrix : %f DH                                          Prix : %f DH", (trajets[L1[0]].Prix)*0.3, (trajets[L2[0]].Prix)*0.3);
                                                            printf("\nTrain : %s                                            Train : %s", trajets[L1[0]].trajetTrain.nomTrain, trajets[L2[0]].trajetTrain.nomTrain);
                                                            printf("\nHeure de depart : %s:%s                               Heure de depart : %s:%s", trajets[L1[0]].heureDep.heure, trajets[L1[0]].heureDep.minute, trajets[L2[0]].heureDep.heure, trajets[L2[0]].heureDep.minute);
                                                            printf("\nHeure d'arrivee : %s:%s                               Heure d'arrivee : %s:%s", trajets[L1[0]].heureArr.heure, trajets[L1[0]].heureArr.minute, trajets[L2[0]].heureArr.heure, trajets[L2[0]].heureArr.minute);
                                                            printf("\nDuree : %sh%smin                                      Duree : %sh%smin", trajets[L1[0]].Duree.heure, trajets[L1[0]].Duree.minute, trajets[L2[0]].Duree.heure, trajets[L2[0]].Duree.minute);
                                                            printf("\nDate : %s/%s/%s                                       Date : %s/%s/%s\n", trajets[L1[0]].dateTrajet.jour, trajets[L1[0]].dateTrajet.mois, trajets[L1[0]].dateTrajet.annee, trajets[L2[0]].dateTrajet.jour, trajets[L2[0]].dateTrajet.mois, trajets[L2[0]].dateTrajet.annee);
                                                            printf("\n                         Montant total: %f DH", (trajets[L1[0]].Prix)+(trajets[L2[0]].Prix));
                                                            int ch25;
                                                            do
                                                            {
                                                                printf("\nVoulez-vous completer l'achat des deux billets?");
                                                                printf("\n1-Oui         |       taper<1>");
                                                                printf("\n2-Non         |       taper<2>");
                                                                printf("\n====> "); scanf("%d", &ch25);
                                                                switch(ch25)
                                                                {
                                                                case 1:
                                                                    strcpy(NVticket.nom,ticket.nom);
                                                                    strcpy(NVticket.prenom,ticket.prenom);
                                                                    strcpy(NVticket.stationDep,ticket.stationArr);
                                                                    strcpy(NVticket.stationArr,ticket.stationDep);
                                                                    strcpy(NVticket.dateDep.jour,dateRetJour);
                                                                    strcpy(NVticket.dateDep.mois,dateRetMois);
                                                                    strcpy(NVticket.dateDep.annee,dateRetAnnee);

                                                                    (titres[b1].nbrUtilisation)+=2;
                                                                    remove("fichierDesTitresPermission.txt");
                                                                    nfile = fopen("fichierNouveauTitres.txt","a");
                                                                    for (int i=0; i<nbTitres; i++){
                                                                        if (titres[i].idTitre!=titres[b1].idTitre)
                                                                            fwrite(&titres[i], sizeof(titres[i]), 1, nfile);

                                                                        else
                                                                            fwrite(&titres[b1], sizeof(titres[b1]), 1, nfile);
                                                                    }
                                                                    fclose(nfile);
                                                                    rename("fichierNouveauTitres.txt", "fichierDesTitresPermission.txt");
                                                                    (trajets[L1[0]].placesReservees)+=1;
                                                                    (trajets[L2[0]].placesReservees)+=1;
                                                                    remove("fichierDesTrajets.txt");
                                                                    nfile = fopen("fichierNouveauTrajets.txt","a");
                                                                    for (int i=0; i<nbTrajets; i++){
                                                                        if (strcmp(trajets[i].idTrajet,trajets[L1[0]].idTrajet)==0)
                                                                            fwrite(&trajets[L1[0]], sizeof(trajets[L1[0]]), 1, nfile);
                                                                        else
                                                                        {
                                                                            if(strcmp(trajets[i].idTrajet,trajets[L2[0]].idTrajet)==0)
                                                                                fwrite(&trajets[L2[0]], sizeof(trajets[L2[0]]), 1, nfile);
                                                                            else
                                                                                fwrite(&trajets[i], sizeof(trajets[i]), 1, nfile);
                                                                        }
                                                                    }
                                                                    fclose(nfile);
                                                                    rename("fichierNouveauTrajets.txt", "fichierDesTrajets.txt");
                                                                    file2 = fopen("fichierTickets.txt", "a");
                                                                    fwrite(&ticket, sizeof(ticket), 1, file2);
                                                                    fwrite(&NVticket, sizeof(NVticket), 1, file2);
                                                                    fclose(file2);
                                                                    printf("\nLa reservation est bien faite. Merci.\n");
                                                                    return 0;
                                                                break;
                                                                case 2:
                                                                    printf("\nRetour vers le menu principal.\n");
                                                                    return 0;
                                                                break;
                                                                default:
                                                                    printf("choix invalide, veuillez reessayer!\n");
                                                                    allerRetour();
                                                                break;
                                                                }
                                                            }while(ch25!=2);
                                                        break;
                                                        case 2:
                                                            ;
                                                            int ch22;
                                                            printf("\nVoulez-vous completer l'achat du billet d'aller?");
                                                            printf("\n1-Oui         |       taper<1>");
                                                            printf("\n2-Non         |       taper<2>");
                                                            printf("\n====> "); scanf("%d", &ch22);
                                                            switch(ch22)
                                                            {
                                                            case 1:
                                                                ;
                                                                char buf[15];
                                                                strcpy(buf,titres[b1].villeDep);
                                                                strcpy(titres[b1].villeDep,titres[b1].villeArr);
                                                                strcpy(titres[b1].villeArr,buf);
                                                                (titres[b1].nbrUtilisation)+=1;
                                                                remove("fichierDesTitresPermission.txt");
                                                                nfile = fopen("fichierNouveauTitres.txt","a");
                                                                for (int i=0; i<nbTitres; i++){
                                                                    if (titres[i].idTitre!=titres[b1].idTitre)
                                                                        fwrite(&titres[i], sizeof(titres[i]), 1, nfile);

                                                                    else
                                                                        fwrite(&titres[b1], sizeof(titres[b1]), 1, nfile);
                                                                }
                                                                fclose(nfile);
                                                                rename("fichierNouveauTitres.txt", "fichierDesTitresPermission.txt");
                                                                (trajets[L1[0]].placesReservees)+=1;
                                                                remove("fichierDesTrajets.txt");
                                                                nfile = fopen("fichierNouveauTrajets.txt","a");
                                                                for (int i=0; i<nbTrajets; i++){
                                                                    if (strcmp(trajets[i].idTrajet,trajets[L1[0]].idTrajet)!=0)
                                                                        fwrite(&trajets[i], sizeof(trajets[i]), 1, nfile);

                                                                    else
                                                                        fwrite(&trajets[L1[0]], sizeof(trajets[L1[0]]), 1, nfile);
                                                                }
                                                                fclose(nfile);
                                                                rename("fichierNouveauTrajets.txt", "fichierDesTrajets.txt");
                                                                file2 = fopen("fichierTickets.txt", "a");
                                                                fwrite(&ticket, sizeof(ticket), 1, file2);
                                                                fclose(file2);
                                                                printf("\nLa reservation est bien faite. Merci.\n");
                                                                return 0;
                                                            break;
                                                            case 2:
                                                                printf("\nRetour vers le menu principal.\n");
                                                                return 0;
                                                            break;
                                                            default:
                                                                printf("choix invalide, veuillez reessayer!\n");
                                                                allerRetour();
                                                            break;
                                                            }
                                                        break;
                                                        default:
                                                            printf("choix invalide, veuillez reessayer!\n");
                                                            allerRetour();
                                                        break;
                                                        }
                                                    }while(ch24!=2);
                                                break;
                                                default:
                                                    ;
                                                    int ch23;
                                                    do
                                                    {
                                                        printf("\nvoulez-vous reserver?");
                                                        printf("\nOui           |        taper<1>");
                                                        printf("\nNon           |        taper<2>");
                                                        printf("\n=====> ");
                                                        scanf("%d", &ch23);
                                                        switch(ch23)
                                                        {
                                                        case 1:
                                                            ;
                                                            int imc;
                                                            printf("\nEntrer votre choix :"); scanf("%d", &imc);
                                                            while(imc>im){
                                                                printf("\nEntrer votre choix: "); scanf("%d", &imc);
                                                            }
                                                            printf("\nVoici le billet de ce voyage:\n");
                                                            printf("\nVille de depart : %s", trajets[L2[imc-1]].villeDep);
                                                            printf("\nVille d'arrivee : %s", trajets[L2[imc-1]].villeArr);
                                                            printf("\nPrix : %f DH", (trajets[L2[imc-1]].Prix)*0.3);
                                                            printf("\nTrain : %s", trajets[L2[imc-1]].trajetTrain.nomTrain);
                                                            printf("\nHeure de depart : %s:%s", trajets[L2[imc-1]].heureDep.heure, trajets[L2[imc-1]].heureDep.minute);
                                                            printf("\nHeure d'arrivee : %s:%s", trajets[L2[imc-1]].heureArr.heure, trajets[L2[imc-1]].heureArr.minute);
                                                            printf("\nDuree : %sh%smin", trajets[L2[imc-1]].Duree.heure, trajets[L2[imc-1]].Duree.minute);
                                                            printf("\nDate : %s/%s/%s", trajets[L2[imc-1]].dateTrajet.jour, trajets[L2[imc-1]].dateTrajet.mois, trajets[L2[imc-1]].dateTrajet.annee);
                                                            printf("\n");

                                                            int ch26;
                                                            printf("\nvoulez-vous l'ajouter au panier?");
                                                            printf("\nOui           |        taper<1>");
                                                            printf("\nNon           |        taper<2>");
                                                            printf("\n=====> ");
                                                            scanf("%d", &ch26);
                                                            switch(ch26)
                                                            {
                                                            case 1:
                                                            break;
                                                            case 2:
                                                            break;
                                                            default:
                                                            break;
                                                            }




                                                        break;
                                                        case 2:
                                                        break;
                                                        default:
                                                        break;
                                                        }
                                                    }while(ch23!=2);
                                                break;
                                                }
                                            break;
                                            case 2:
                                            break;
                                            default:
                                            break;
                                            }
                                        }while(ch17!=2);
                                    }
                                    else
                                        printf("\nCe titre de permission est deja utilise!");
                                }
                                else
                                printf("\nVous ne pouvez pas utiliser ce titre de permission pour acheter ce billet.");
                            }
                            else
                                printf("\nLe titre de permission ayant cet identifiant n'existe pas.");
                        break;
                        default:
                        break;
                        }
                        }while(ch14!=2);
                    break;
                    default:
                    break;
                    }
                }
                else
                printf("\nPas de trains disponibles pour la date de retour.\n");
                int ch20;
                do
                {
                    printf("\nvoulez-vous reserver juste pour la date de depart?");
                    printf("\nOui           |        taper<1>");
                    printf("\nNon           |        taper<2>");
                    printf("\n=====> ");
                    scanf("%d", &ch20);
                    switch(ch20){
                    case 1:
                        allerSimpleVerifi(nbTrajets, trajets, buff, ticket);
                    return 0;
                    break;
                    case 2:
                        printf("\nRetour vers le menu principal.\n");
                        return 0;
                    break;
                    default:
                        printf("choix invalide, veuillez reessayer!\n");
                        allerRetour();
                    break;
                    }
                }while(ch20!=2);
            }
            else
                printf("\nPas de trains disponibles.");
        break;
        case 2:
        break;
        default:
        break;
        }
    }while(ch21!=2);
}
    //***************************************************************************




   /* if(rechercheTrajetJour(buff, trajets, nbTrajets))
    {
        if(rechercheTrajetJour(buff1, trajets, nbTrajets))
        {
            int ch21;
            do
            {
            printf("\nVous etes un EIOR?");
            printf("\nOui           |        taper<1>");
            printf("\nNon           |        taper<2>");
            printf("\n====> ");
            scanf("%d", &ch21);
            switch(ch21){
                case 1:
                    ;
                    int idTitre1, b1;
                    printf("\nEntrer l'identifiant de votre titre de permission: "); scanf("%d", &idTitre1);
                    int nbTitres = 0;
                    fileT = fopen("fichierDesTitresPermission.txt", "r");
                    while (fread(&titre, sizeof(titre), 1, fileT)){
                        titres[nbTitres] = titre;
                        nbTitres++;
                    }
                    fclose(fileT);
                    if (rechercheTitre(idTitre1, titres, nbTitres))
                    {
                        for(int i=0; i<nbTitres; i++)
                        {
                            if(titres[i].idTitre==idTitre1)
                                b1=i;
                        }
                        if(strcmp(trajets[L1[0]].villeDep,titres[b1].villeDep)==0 && strcmp(trajets[L1[0]].villeArr,titres[b1].villeArr)==0)
                        {
                            if(titres[b1].nbrUtilisation==0)
                            {

                                switch(in){
                                    case 0:
                                        printf("\nLes trains sont tous pleins.");
                                    break;
                                    case 1:
                                        ;
                                        int ch14;
                                        do
                                        {
                                        printf("\nVoulez-vous reserver?");
                                        printf("\nOui           |        taper<1>");
                                        printf("\nNon           |        taper<2>");
                                        printf("\n=====> ");
                                        scanf("%d", &ch14);
                                        switch(ch14){
                                        case 2:
                                            printf("\nRetour vers le menu principal.\n");
                                            return 0;
                                        break;
                                        case 1:
                                            ;

                                        break;
                                        default:
                                            printf("choix invalide, veuillez réessayer!\n");
                                            allerSimple();
                                        break;
                                        }
                                        }while(ch14!=2);
                                    break;
                                    default:
                                        ;
                                        int ch18;
                                        do
                                        {
                                        printf("\nVoulez-vous reserver?");
                                        printf("\nOui           |        taper<1>");
                                        printf("\nNon           |        taper<2>");
                                        printf("\n====> ");
                                        scanf("%d", &ch18);
                                        switch(ch18){
                                        case 2:
                                            printf("\nRetour vers le menu principal.\n");
                                            return 0;
                                        break;
                                        case 1:
                                            ;
                                            int ch19, inc;
                                            do
                                            {
                                            printf("\nEntrer votre choix: "); scanf("%d", &inc);
                                            while(inc>in){
                                                printf("\nEntrer votre choix: "); scanf("%d", &inc);
                                            }
                                            printf("\nVous etes un EIOR?");
                                            printf("\nOui           |        taper<1>");
                                            printf("\nNon           |        taper<2>");
                                            printf("\n=====> "); scanf("%d", &ch19);
                                            switch(ch19){
                                                case 1:
                                                    ;
                                                    int idTitre1, b1;
                                                    printf("\nEntrer l'identifiant de votre titre de permission: "); scanf("%d", &idTitre1);
                                                    int nbTitres = 0;
                                                    fileT = fopen("fichierDesTitresPermission.txt", "r");
                                                    while (fread(&titre, sizeof(titre), 1, fileT)){
                                                        titres[nbTitres] = titre;
                                                        nbTitres++;
                                                    }
                                                    fclose(fileT);
                                                    if (rechercheTitre(idTitre1, titres, nbTitres))
                                                    {
                                                        for(int i=0; i<nbTitres; i++)
                                                        {
                                                            if(titres[i].idTitre==idTitre1)
                                                                b1=i;
                                                        }
                                                        if(strcmp(trajets[L1[inc-1]].villeDep,titres[b1].villeDep)==0 && strcmp(trajets[L1[inc-1]].villeArr,titres[b1].villeArr)==0)
                                                        {
                                                            if(titres[b1].nbrUtilisation<2)
                                                            {
                                                                printf("\nVoici le billet de ce voyage:\n");
                                                                printf("\nVille de depart : %s", trajets[L1[inc-1]].villeDep);
                                                                printf("\nVille d'arrivee : %s", trajets[L1[inc-1]].villeArr);
                                                                printf("\nPrix : %f DH", (trajets[L1[inc-1]].Prix)*0.3);
                                                                printf("\nTrain : %s", trajets[L1[inc-1]].trajetTrain.nomTrain);
                                                                printf("\nHeure de depart : %s:%s", trajets[L1[inc-1]].heureDep.heure, trajets[L1[inc-1]].heureDep.minute);
                                                                printf("\nHeure d'arrivee : %s:%s", trajets[L1[inc-1]].heureArr.heure, trajets[L1[inc-1]].heureArr.minute);
                                                                printf("\nDuree : %sh%smin", trajets[L1[inc-1]].Duree.heure, trajets[L1[inc-1]].Duree.minute);
                                                                printf("\nDate : %s/%s/%s", trajets[L1[inc-1]].dateTrajet.jour, trajets[L1[inc-1]].dateTrajet.mois, trajets[L1[inc-1]].dateTrajet.annee);
                                                                printf("\n");
                                                                int ch17;
                                                                do
                                                                {
                                                                    printf("\nvoulez-vous reserver?");
                                                                    printf("\nOui           |        taper<1>");
                                                                    printf("\nNon           |        taper<2>");
                                                                    printf("\n=====> ");
                                                                    scanf("%d", &ch17);
                                                                    switch(ch17){
                                                                    case 1:
                                                                        ;
                                                                        char buf[15];
                                                                        strcpy(buf,titres[b1].villeDep);
                                                                        strcpy(titres[b1].villeDep,titres[b1].villeArr);
                                                                        strcpy(titres[b1].villeArr,buf);
                                                                        (titres[b1].nbrUtilisation)+=1;
                                                                        remove("fichierDesTitresPermission.txt");
                                                                        nfile = fopen("fichierNouveauTitres.txt","a");
                                                                        for (int i=0; i<nbTitres; i++){
                                                                            if (titres[i].idTitre!=titres[b1].idTitre)
                                                                                fwrite(&titres[i], sizeof(titres[i]), 1, nfile);

                                                                            else
                                                                                fwrite(&titres[b1], sizeof(titres[b1]), 1, nfile);
                                                                        }
                                                                        fclose(nfile);
                                                                        rename("fichierNouveauTitres.txt", "fichierDesTitresPermission.txt");
                                                                        (trajets[L1[inc-1]].placesReservees)+=1;
                                                                        remove("fichierDesTrajets.txt");
                                                                        nfile = fopen("fichierNouveauTrajets.txt","a");
                                                                        for (int i=0; i<nbTrajets; i++){
                                                                            if (strcmp(trajets[i].idTrajet,trajets[L1[0]].idTrajet)!=0)
                                                                                fwrite(&trajets[i], sizeof(trajets[i]), 1, nfile);
                                                                            else
                                                                                fwrite(&trajets[L1[inc-1]], sizeof(trajets[L1[inc-1]]), 1, nfile);
                                                                        }
                                                                        fclose(nfile);
                                                                        rename("fichierNouveauTrajets.txt", "fichierDesTrajets.txt");
                                                                        file2 = fopen("fichierTickets.txt", "a");
                                                                        fwrite(&ticket, sizeof(ticket), 1, file2);
                                                                        fclose(file2);
                                                                        printf("\nLa reservation est bien faite. Merci.\n");
                                                                        return 0;
                                                                    break;
                                                                    case 2:
                                                                        printf("\nRetour vers le menu principal.\n");
                                                                        return 0;
                                                                    break;
                                                                    default:
                                                                        printf("choix invalide, veuillez reessayer!\n");
                                                                        allerSimple();
                                                                    break;
                                                                    }
                                                                }while(ch17!=2);
                                                            }
                                                            else
                                                                printf("\nCe titre de permission est deja utilise!");
                                                        }
                                                        else
                                                            printf("\nVous ne pouvez pas utiliser ce titre de permission pour acheter ce billet.");
                                                    }
                                                    else
                                                        printf("\nLe titre de permission ayant cet identifiant n'existe pas.");
                                                return 0;
                                                break;
                                                case 2:                                                                                     // +
                                                    (trajets[L1[inc-1]].placesReservees)+=1;
                                                    remove("fichierDesTrajets.txt");
                                                    nfile = fopen("fichierNouveauTrajets.txt","a");
                                                    for (int i=0; i<nbTrajets; i++){
                                                        if (strcmp(trajets[i].idTrajet,trajets[L1[inc-1]].idTrajet)!=0)
                                                            fwrite(&trajets[i], sizeof(trajets[i]), 1, nfile);

                                                        else
                                                            fwrite(&trajets[L1[inc-1]], sizeof(trajets[L1[inc-1]]), 1, nfile);
                                                    }
                                                    fclose(nfile);
                                                    rename("fichierNouveauTrajets.txt", "fichierDesTrajets.txt");
                                                    file2 = fopen("fichierTickets.txt", "a");
                                                    fwrite(&ticket, sizeof(ticket), 1, file2);
                                                    fclose(file2);
                                                    printf("\nVoici le billet de votre voyage:\n");
                                                    printf("\nVille de depart : %s", trajets[L1[inc-1]].villeDep);
                                                    printf("\nVille d'arrivee : %s", trajets[L1[inc-1]].villeArr);
                                                    printf("\nPrix : %f DH", trajets[L1[inc-1]].Prix);
                                                    printf("\nTrain : %s", trajets[L1[inc-1]].trajetTrain.nomTrain);
                                                    printf("\nHeure de depart : %s:%s", trajets[L1[inc-1]].heureDep.heure, trajets[L1[inc-1]].heureDep.minute);
                                                    printf("\nHeure d'arrivee : %s:%s", trajets[L1[inc-1]].heureArr.heure, trajets[L1[inc-1]].heureArr.minute);
                                                    printf("\nDuree : %sh%smin", trajets[L1[inc-1]].Duree.heure, trajets[L1[inc-1]].Duree.minute);
                                                    printf("\nDate : %s/%s/%s", trajets[L1[inc-1]].dateTrajet.jour, trajets[L1[inc-1]].dateTrajet.mois, trajets[L1[inc-1]].dateTrajet.annee);
                                                    printf("\n");
                                                    printf("\nLa reservation est bien faite. Merci.\n");
                                                return 0;
                                                break;
                                                default:
                                                    printf("choix invalide, veuillez réessayer!\n");
                                                    allerSimple();
                                                break;
                                            }
                                            }while(ch19!=2);
                                        break;
                                        default:
                                            printf("choix invalide, veuillez réessayer!\n");
                                            allerSimple();
                                        break;
                                        }
                                        }while(ch18!=2);
                                    break;
                                }
                                printf("\nVoici le billet de ce voyage:\n");
                                printf("\nVille de depart : %s", trajets[L1[0]].villeDep);
                                printf("\nVille d'arrivee : %s", trajets[L1[0]].villeArr);
                                printf("\nPrix : %f DH", (trajets[L1[0]].Prix)*0.3);
                                printf("\nTrain : %s", trajets[L1[0]].trajetTrain.nomTrain);
                                printf("\nHeure de depart : %s:%s", trajets[L1[0]].heureDep.heure, trajets[L1[0]].heureDep.minute);
                                printf("\nHeure d'arrivee : %s:%s", trajets[L1[0]].heureArr.heure, trajets[L1[0]].heureArr.minute);
                                printf("\nDuree : %sh%smin", trajets[L1[0]].Duree.heure, trajets[L1[0]].Duree.minute);
                                printf("\nDate : %s/%s/%s", trajets[L1[0]].dateTrajet.jour, trajets[L1[0]].dateTrajet.mois, trajets[L1[0]].dateTrajet.annee);
                                printf("\n");
                                int ch17;
                                do
                                {
                                    printf("\nvoulez-vous reserver?");
                                    printf("\nOui           |        taper<1>");
                                    printf("\nNon           |        taper<2>");
                                    printf("\n=====> ");
                                    scanf("%d", &ch17);
                                    switch(ch17){
                                    case 1:
                                        ;
                                        char buf[15];
                                        strcpy(buf,titres[b1].villeDep);
                                        strcpy(titres[b1].villeDep,titres[b1].villeArr);
                                        strcpy(titres[b1].villeArr,buf);
                                        (titres[b1].nbrUtilisation)+=1;
                                        remove("fichierDesTitresPermission.txt");
                                        nfile = fopen("fichierNouveauTitres.txt","a");
                                        for (int i=0; i<nbTitres; i++){
                                            if (titres[i].idTitre!=titres[b1].idTitre)
                                                fwrite(&titres[i], sizeof(titres[i]), 1, nfile);

                                            else
                                                fwrite(&titres[b1], sizeof(titres[b1]), 1, nfile);
                                        }
                                        fclose(nfile);
                                        rename("fichierNouveauTitres.txt", "fichierDesTitresPermission.txt");
                                        (trajets[L1[0]].placesReservees)+=1;
                                        remove("fichierDesTrajets.txt");
                                        nfile = fopen("fichierNouveauTrajets.txt","a");
                                        for (int i=0; i<nbTrajets; i++){
                                            if (strcmp(trajets[i].idTrajet,trajets[L1[0]].idTrajet)!=0)
                                                fwrite(&trajets[i], sizeof(trajets[i]), 1, nfile);

                                            else
                                                fwrite(&trajets[L1[0]], sizeof(trajets[L1[0]]), 1, nfile);
                                        }
                                        fclose(nfile);
                                        rename("fichierNouveauTrajets.txt", "fichierDesTrajets.txt");
                                        file2 = fopen("fichierTickets.txt", "a");
                                        fwrite(&ticket, sizeof(ticket), 1, file2);
                                        fclose(file2);
                                        printf("\nLa reservation est bien faite. Merci.\n");
                                        return 0;
                                    break;
                                    case 2:
                                        printf("\nRetour vers le menu principal.\n");
                                        return 0;
                                    break;
                                    default:
                                        printf("choix invalide, veuillez reessayer!\n");
                                        allerSimple();
                                    break;
                                    }
                                }while(ch17!=2);
                            }
                            else
                                printf("\nCe titre de permission est deja utilise!");
                        }
                        else
                            printf("\nVous ne pouvez pas utiliser ce titre de permission pour acheter ce billet.");
                    }
                    else
                        printf("\nLe titre de permission ayant cet identifiant n'existe pas.");
                return 0;
                break;
                case 2:
                    (trajets[L1[0]].placesReservees)+=1;
                    remove("fichierDesTrajets.txt");
                    nfile = fopen("fichierNouveauTrajets.txt","a");
                    for (int i=0; i<nbTrajets; i++){
                        if (strcmp(trajets[i].idTrajet,trajets[L1[0]].idTrajet)!=0)
                            fwrite(&trajets[i], sizeof(trajets[i]), 1, nfile);

                        else
                            fwrite(&trajets[L1[0]], sizeof(trajets[L1[0]]), 1, nfile);
                    }
                    fclose(nfile);
                    rename("fichierNouveauTrajets.txt", "fichierDesTrajets.txt");
                    file2 = fopen("fichierTickets.txt", "a");
                    fwrite(&ticket, sizeof(ticket), 1, file2);
                    fclose(file2);
                    printf("\nVoici le billet de votre voyage:\n");
                    printf("\nVille de depart : %s", trajets[L1[0]].villeDep);
                    printf("\nVille d'arrivee : %s", trajets[L1[0]].villeArr);
                    printf("\nPrix : %f DH", trajets[L1[0]].Prix);
                    printf("\nTrain : %s", trajets[L1[0]].trajetTrain.nomTrain);
                    printf("\nHeure de depart : %s:%s", trajets[L1[0]].heureDep.heure, trajets[L1[0]].heureDep.minute);
                    printf("\nHeure d'arrivee : %s:%s", trajets[L1[0]].heureArr.heure, trajets[L1[0]].heureArr.minute);
                    printf("\nDuree : %sh%smin", trajets[L1[0]].Duree.heure, trajets[L1[0]].Duree.minute);
                    printf("\nDate : %s/%s/%s", trajets[L1[0]].dateTrajet.jour, trajets[L1[0]].dateTrajet.mois, trajets[L1[0]].dateTrajet.annee);
                    printf("\n");
                    printf("\nLa reservation est bien faite. Merci.\n");
                return 0;
                break;
                default:
                    printf("choix invalide, veuillez réessayer!\n");
                    allerSimple();
                break;
            }
            }while(ch21!=2);

            printf("\nTrains proposes pour la date de depart: ");
            int in=0, L1[5];
            for (int i=0; i<nbTrajets; i++)
            {
                if(strcmp(trajets[i].idTrajetJour, buff)==0 && trajets[i].placesReservees<trajets[i].trajetTrain.nbrPlacesMax)
                {
                    L1[in]=i;
                    in++;
                    printf("\n%d-Ville de depart : %s", in, trajets[i].villeDep);
                    printf("\nVille d'arrivee : %s", trajets[i].villeArr);
                    printf("\nPrix : %f DH", trajets[i].Prix);
                    printf("\nTrain : %s", trajets[i].trajetTrain.nomTrain);
                    printf("\nHeure de depart : %s:%s", trajets[i].heureDep.heure, trajets[i].heureDep.minute);
                    printf("\nHeure d'arrivee : %s:%s", trajets[i].heureArr.heure, trajets[i].heureArr.minute);
                    printf("\nDuree : %sh%smin", trajets[i].Duree.heure, trajets[i].Duree.minute);
                    printf("\nDate : %s/%s/%s\n", trajets[i].dateTrajet.jour, trajets[i].dateTrajet.mois, trajets[i].dateTrajet.annee);
                }
            }
            switch(in){
                case 0:
                    printf("\nLes trains sont tous pleins.");
                break;
                case 1:
                    ;
                    int ch14;
                    do
                    {
                    printf("\nVoulez-vous reserver?");
                    printf("\nOui           |        taper<1>");
                    printf("\nNon           |        taper<2>");
                    printf("\n=====> ");
                    scanf("%d", &ch14);
                    switch(ch14){
                    case 2:
                        printf("\nRetour vers le menu principal.\n");
                        return 0;
                    break;
                    case 1:
                        ;

                    break;
                    default:
                        printf("choix invalide, veuillez réessayer!\n");
                        allerSimple();
                    break;
                    }
                    }while(ch14!=2);
                break;
                default:
                    ;
                    int ch18;
                    do
                    {
                    printf("\nVoulez-vous reserver?");
                    printf("\nOui           |        taper<1>");
                    printf("\nNon           |        taper<2>");
                    printf("\n====> ");
                    scanf("%d", &ch18);
                    switch(ch18){
                    case 2:
                        printf("\nRetour vers le menu principal.\n");
                        return 0;
                    break;
                    case 1:
                        ;
                        int ch19, inc;
                        do
                        {
                        printf("\nEntrer votre choix: "); scanf("%d", &inc);
                        while(inc>in){
                            printf("\nEntrer votre choix: "); scanf("%d", &inc);
                        }
                        printf("\nVous etes un EIOR?");
                        printf("\nOui           |        taper<1>");
                        printf("\nNon           |        taper<2>");
                        printf("\n=====> "); scanf("%d", &ch19);
                        switch(ch19){
                            case 1:
                                ;
                                int idTitre1, b1;
                                printf("\nEntrer l'identifiant de votre titre de permission: "); scanf("%d", &idTitre1);
                                int nbTitres = 0;
                                fileT = fopen("fichierDesTitresPermission.txt", "r");
                                while (fread(&titre, sizeof(titre), 1, fileT)){
                                    titres[nbTitres] = titre;
                                    nbTitres++;
                                }
                                fclose(fileT);
                                if (rechercheTitre(idTitre1, titres, nbTitres))
                                {
                                    for(int i=0; i<nbTitres; i++)
                                    {
                                        if(titres[i].idTitre==idTitre1)
                                            b1=i;
                                    }
                                    if(strcmp(trajets[L1[inc-1]].villeDep,titres[b1].villeDep)==0 && strcmp(trajets[L1[inc-1]].villeArr,titres[b1].villeArr)==0)
                                    {
                                        if(titres[b1].nbrUtilisation<2)
                                        {
                                            printf("\nVoici le billet de ce voyage:\n");
                                            printf("\nVille de depart : %s", trajets[L1[inc-1]].villeDep);
                                            printf("\nVille d'arrivee : %s", trajets[L1[inc-1]].villeArr);
                                            printf("\nPrix : %f DH", (trajets[L1[inc-1]].Prix)*0.3);
                                            printf("\nTrain : %s", trajets[L1[inc-1]].trajetTrain.nomTrain);
                                            printf("\nHeure de depart : %s:%s", trajets[L1[inc-1]].heureDep.heure, trajets[L1[inc-1]].heureDep.minute);
                                            printf("\nHeure d'arrivee : %s:%s", trajets[L1[inc-1]].heureArr.heure, trajets[L1[inc-1]].heureArr.minute);
                                            printf("\nDuree : %sh%smin", trajets[L1[inc-1]].Duree.heure, trajets[L1[inc-1]].Duree.minute);
                                            printf("\nDate : %s/%s/%s", trajets[L1[inc-1]].dateTrajet.jour, trajets[L1[inc-1]].dateTrajet.mois, trajets[L1[inc-1]].dateTrajet.annee);
                                            printf("\n");
                                            int ch17;
                                            do
                                            {
                                                printf("\nvoulez-vous reserver?");
                                                printf("\nOui           |        taper<1>");
                                                printf("\nNon           |        taper<2>");
                                                printf("\n=====> ");
                                                scanf("%d", &ch17);
                                                switch(ch17){
                                                case 1:
                                                    ;
                                                    char buf[15];
                                                    strcpy(buf,titres[b1].villeDep);
                                                    strcpy(titres[b1].villeDep,titres[b1].villeArr);
                                                    strcpy(titres[b1].villeArr,buf);
                                                    (titres[b1].nbrUtilisation)+=1;
                                                    remove("fichierDesTitresPermission.txt");
                                                    nfile = fopen("fichierNouveauTitres.txt","a");
                                                    for (int i=0; i<nbTitres; i++){
                                                        if (titres[i].idTitre!=titres[b1].idTitre)
                                                            fwrite(&titres[i], sizeof(titres[i]), 1, nfile);

                                                        else
                                                            fwrite(&titres[b1], sizeof(titres[b1]), 1, nfile);
                                                    }
                                                    fclose(nfile);
                                                    rename("fichierNouveauTitres.txt", "fichierDesTitresPermission.txt");
                                                    (trajets[L1[inc-1]].placesReservees)+=1;
                                                    remove("fichierDesTrajets.txt");
                                                    nfile = fopen("fichierNouveauTrajets.txt","a");
                                                    for (int i=0; i<nbTrajets; i++){
                                                        if (strcmp(trajets[i].idTrajet,trajets[L1[0]].idTrajet)!=0)
                                                            fwrite(&trajets[i], sizeof(trajets[i]), 1, nfile);
                                                        else
                                                            fwrite(&trajets[L1[inc-1]], sizeof(trajets[L1[inc-1]]), 1, nfile);
                                                    }
                                                    fclose(nfile);
                                                    rename("fichierNouveauTrajets.txt", "fichierDesTrajets.txt");
                                                    file2 = fopen("fichierTickets.txt", "a");
                                                    fwrite(&ticket, sizeof(ticket), 1, file2);
                                                    fclose(file2);
                                                    printf("\nLa reservation est bien faite. Merci.\n");
                                                    return 0;
                                                break;
                                                case 2:
                                                    printf("\nRetour vers le menu principal.\n");
                                                    return 0;
                                                break;
                                                default:
                                                    printf("choix invalide, veuillez reessayer!\n");
                                                    allerSimple();
                                                break;
                                                }
                                            }while(ch17!=2);
                                        }
                                        else
                                            printf("\nCe titre de permission est deja utilise!");
                                    }
                                    else
                                        printf("\nVous ne pouvez pas utiliser ce titre de permission pour acheter ce billet.");
                                }
                                else
                                    printf("\nLe titre de permission ayant cet identifiant n'existe pas.");
                            return 0;
                            break;
                            case 2:                                                                                     // +
                                (trajets[L1[inc-1]].placesReservees)+=1;
                                remove("fichierDesTrajets.txt");
                                nfile = fopen("fichierNouveauTrajets.txt","a");
                                for (int i=0; i<nbTrajets; i++){
                                    if (strcmp(trajets[i].idTrajet,trajets[L1[inc-1]].idTrajet)!=0)
                                        fwrite(&trajets[i], sizeof(trajets[i]), 1, nfile);

                                    else
                                        fwrite(&trajets[L1[inc-1]], sizeof(trajets[L1[inc-1]]), 1, nfile);
                                }
                                fclose(nfile);
                                rename("fichierNouveauTrajets.txt", "fichierDesTrajets.txt");
                                file2 = fopen("fichierTickets.txt", "a");
                                fwrite(&ticket, sizeof(ticket), 1, file2);
                                fclose(file2);
                                printf("\nVoici le billet de votre voyage:\n");
                                printf("\nVille de depart : %s", trajets[L1[inc-1]].villeDep);
                                printf("\nVille d'arrivee : %s", trajets[L1[inc-1]].villeArr);
                                printf("\nPrix : %f DH", trajets[L1[inc-1]].Prix);
                                printf("\nTrain : %s", trajets[L1[inc-1]].trajetTrain.nomTrain);
                                printf("\nHeure de depart : %s:%s", trajets[L1[inc-1]].heureDep.heure, trajets[L1[inc-1]].heureDep.minute);
                                printf("\nHeure d'arrivee : %s:%s", trajets[L1[inc-1]].heureArr.heure, trajets[L1[inc-1]].heureArr.minute);
                                printf("\nDuree : %sh%smin", trajets[L1[inc-1]].Duree.heure, trajets[L1[inc-1]].Duree.minute);
                                printf("\nDate : %s/%s/%s", trajets[L1[inc-1]].dateTrajet.jour, trajets[L1[inc-1]].dateTrajet.mois, trajets[L1[inc-1]].dateTrajet.annee);
                                printf("\n");
                                printf("\nLa reservation est bien faite. Merci.\n");
                            return 0;
                            break;
                            default:
                                printf("choix invalide, veuillez réessayer!\n");
                                allerSimple();
                            break;
                        }
                        }while(ch19!=2);
                    break;
                    default:
                        printf("choix invalide, veuillez réessayer!\n");
                        allerSimple();
                    break;
                    }
                    }while(ch18!=2);
                break;
            }
            }
            else

    }
    else
        printf("\nPas de trains disponibles.");
}*/

int espaceReservation()
{
   printf("\n******************************************\n");
    printf("              Espace de reservation\n");
    printf("******************************************\n");

    int choix;

    do{
        printf("\n1- Aller simple:\n");
        printf("2- Aller-retour:\n");
        printf("3-Retour\n");

        printf("\nEntrez votre choix:");
        scanf("%d", &choix);

        switch(choix){
            case 1:
                allerSimple();
            break;
            case 2:
                allerRetour();
            break;
            case 3:
                printf("\nRetour vers le menu principal.\n");
                return 0;
            break;
            default:
                printf("choix invalide, veuillez réessayer!\n");
                espaceVoyageur();
            break;
        }
    } while ( choix != 3);
}

int espaceVoyageur(){

    printf("\n******************************************\n");
    printf("              Espace Voyageur\n");
    printf("******************************************\n");

    int choix;

    do{
        printf("\n1- Acheter un billet:\n");
        printf("2- Revenir au menu principal:\n");

        printf("\nEntrez votre choix:");
        scanf("%d", &choix);

        switch(choix){
            case 1:
                espaceReservation();
            break;
            case 2:
                printf("\nRetour vers le menu principal.\n");
                return 0;
            break;
            default:
                printf("choix invalide, veuillez réessayer!\n");
                espaceVoyageur();
            break;
        }
    } while ( choix != 2);
}

int espaceAdministrateur()
{
    char username[20], password[20];
    int choix;
    printf("\n\tNom d'utilisateur:\t");
    scanf("%s", &username);
    printf("\n\tMot de passe:\t");
    scanf("%s", &password);
    if(strcmp(username,"admin")==0 && strcmp(password,"admin")==0){
        printf("\n\tConnexion reussie !");
        printf("\n\n\t******************************************");
        printf("\n\t\tEspace Administrateur");
        printf("\n\t******************************************");
        do{
        printf("\n 1- Espace des trains         |        taper <1>");
        printf("\n 2- Espace des trajets         |        taper <2>");
        printf("\n\t 3- Retour                    |        taper<3>\n");
        printf("\n\tChoisir le service : ");
        scanf("%d", &choix);
        switch(choix){
            case 1:
                espaceTrains();
            break;
            case 2:
                espaceTrajets();
            break;
            case 3:
                printf("\nRetour vers le menu principal.\n");
                return 0;
            break;
            default:
                printf("choix invalide, veuillez réessayer!\n");
                espaceAdministrateur();
            break;
        }
    } while (choix != 3);
    }
    else printf("Acces refuse.");
}

int menu(){

    printf("\n******************************************\n");
    printf("Voyageons avec ONCF!\n");
    printf("******************************************\n");

    int choix;

    do{
        printf("\n1- Je suis un administrateur.");
        printf("\n2- Je suis un voyageur.");
        printf("\n3- Sortir de l'application.");

        printf("\n\nDonner votre choix: ");
        scanf("%d", &choix);

        switch(choix){
            case 1:
                espaceAdministrateur();
            break;
            case 2:
                espaceVoyageur();
            break;
            case 3:
                printf("\nMerci d'avoir utiliser notre application, a bientot.\n");
                return 0;
            break;
            default:
                printf("choix invalide, veuillez reessayer!");
                menu();
            break;
        }
    } while ( choix != 3);
}

int main()
{
    menu();
    return 0;
}
