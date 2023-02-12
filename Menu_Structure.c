
#include<stdlib.h>
#include<stdio.h>
#include <string.h>
#define size 100
typedef struct etudiant Etudiant;


//Definition de struture etudiant
struct etudiant
{

    char nom[10];
    char prenom[10];
    char matiere[20];
    float note;
};


//--------------------------------------Definition des fonctions du Menu--------------------------------------

//Ajouter un etudiant 
int AjouterEtudiant(Etudiant tab[size], int i)
{
    //Creation d'un fichier texte pour enregistrer les données de chaque etudiant
    FILE* fp;
    fp = fopen("fichierinfo.txt", "a");

    if (fp == NULL)
    {
        fprintf(stderr, "Erreur d'ouverture du fichier\n");
        return -1;
    }

    printf("\n Ajouter les details de etudiant\n\n");

    printf("Entrez votre nom  : ");
    scanf("%s", tab[i].nom);

    //Pour le nom

    printf("Entrez votre prenom : ");
    scanf("%s", tab[i].prenom);

    //Pour la Matiere
    printf("Entrez votre matiere : ");
    scanf("%s", tab[i].matiere);

    //Pour la note
    printf("Entrez votre note: ");
    while (scanf("%f", &tab[i].note)!= 1 || tab[i].note < 0 || tab[i].note > 20)
    {
        printf("Entrez une note valide (entre 0 et 20): ");
        fflush(stdin);
    }

    fprintf(fp, "%s\n%s\n%s\n%f\n", tab[i].nom, tab[i].prenom, tab[i].matiere, tab[i].note);

    fclose(fp);

    printf("\n ajout avec succes !!\n");
    return 0;
}


//Afficher tout les informations des etudiant
void AfficherTousEtu(Etudiant tab[size], int i)
{
    printf("\t\t----------------------------------------------------------- \n\n");

    printf("\t\t ----Affiche tout les etudiants----\n");

    for (int j = 0; j < i; j++)
    {
        printf("\t\tNom : %s \n", tab[j].nom);
        printf("\t\tPrenom : %s \n", tab[j].prenom);
        printf("\t\tMatiere : %s \n", tab[j].matiere);
        printf("\t\tNote : %f \n", tab[j].note);
        printf("\t\t----------------------------------------------------------- \n\n");
    }
}

//Afficher uniquement les informations de l'etudiant que nous souhaitons voir en fonction de son nom
void AfficherParNom(Etudiant tab[size], char chaine[10])
{
    char temp[20];
    printf("\n Entrez le nom de l'etudiant que vous souhaitez voir \n");
    scanf("%s", temp);

    const int i;
    for (int i = 0; i <size; i++)
    {
        if (strcmp(tab[i].nom, temp)==0)
        {
            printf(" Les informations de l'etudiant sont : \n");
            printf("Le nom est : %s\n",  tab[i].nom);
            printf("Le prenom est : %s\n",  tab[i].prenom);
            printf("La matiere c'est : %s\n",  tab[i].matiere);
            printf("La note est :%f\n",  tab[i].note);

        }
    }
}

//supprimer uniquement les informations de l'etudiant que nous souhaitons en fonction de son nom
void SupprimerEtudiant(Etudiant tab[size],char chaine[10])
{

    int i;
    printf("Entrer le Nom d'etudiant que vous souhaitez supprimer : ");
    scanf("%s",chaine);
    for (int j = 0; j<=size; j++)
    {
        if (strcmp(tab[j].nom,chaine)==0)
        {
            for (int i=j; i<=100-1; i++)
            {tab[i] = tab[i+1];

            }
            i--;

            printf("\n\n suppression réussie !!!!!! \n\n");

        }

    }
}

//Modifier des information pour seul etudiant que nous souhaitons en fonction de leur nom
void ModifEtudiant(Etudiant tab[size], char chaine[10])
{
    printf("Entrer le Nom d'étudiant que vous souhaitez modifier ces informations :\n ");
    scanf("%s",chaine);
    for (int j = 0; j < size; j++)
    {
        if (strcmp(tab[j].nom,chaine)==0)
        {

            printf("Inserer les nouvelles informations de %s : \n",chaine);
            printf("Donner le nom de l'étudiant : ");
            scanf("%s",tab[j].nom);

            //Prenom
            printf("Donner le prenom de l'étudiant : ");
            scanf("%s",tab[j].prenom);

            //Matiere
            printf("Donner le nom de la matière : ");
            scanf("%s",tab[j].matiere);


            //Note
            printf("Donner la note : ");
            while (scanf("%f", &tab[j].note)!= 1 || tab[j].note < 0 || tab[j].note > 20)
            {
                printf("Entrez une note valide (entre 0 et 20): ");
                fflush(stdin);
            }




            printf("\n => Données enregistrées\n");

        }



    }


}




//Modifier uniquement une information (ex:juste la note) pour seul etudiant que nous souhaitons en fonction de leur nom
void Modifier_Juste_Un_elementEtudiant(Etudiant tab[size],char chaine[10])
{

    FILE *fp;
    fp=fopen("fichier2.txt","a");
    int temp;
    printf("Entrez nom \n");
    scanf("%s", chaine);
    int i;

    for (int j = 0; j < size; j++)
    {

        if (strcmp(tab[j].nom,chaine)==0)
        {
            printf("1. Nom \n"
                   "2. prenom\n"
                   "3. Matiere\n"
                   "4. note\n");

            int c;
            scanf("%d", &c);
            switch(c) {
                case 1:
                    printf("Inserer les nouvelles informations de %s : \n",chaine);
                    printf("Donner le nom de l'étudiant : ");
                    scanf("%s",tab[j].nom);
                    break;
                case 2:
                    printf("Donner le prenom de l'étudiant : ");
                    scanf("%s",tab[j].prenom);
                    break;
                case 3:
                    printf("Donner le nom de la matière : ");
                    scanf("%s",tab[j].matiere);

                    break;
                case 4:
                    printf("Donner la note : ");
                    scanf("%f",&tab[j].note);
                    break;
                default:
                    exit(0);


                    fprintf(fp, "%s\n%s\n%s\n%f\n", tab[j].nom, tab[j].prenom, tab[j].matiere, tab[j].note);

                    fclose(fp);
                    printf("avec succes ");


            }

            fprintf(fp, "%s\n%s\n%s\n%f\n", tab[j].nom, tab[j].prenom, tab[j].matiere, tab[j].note);

            fclose(fp);
            printf("avec succes ");

        }
    }

}





//-------------------------------------------------------------------------------------------------------------------/

void main(void)
{

    int choix;
    Etudiant tab1[size];
    int i = 0;
    char chaine[10];


    while (1)
    {

        printf("\n\n\n\t\t\t************************************Menu**************************************************\n\n");
        printf("\t\t\t1. Ajouter un Etudiant\n");
        printf("\t\t\t2. Afficher tous les etudiants\n");
        printf("\t\t\t3. Afficher par nom un etudiant \n");
        printf("\t\t\t4. Supprimer un etudiant\n");
        printf("\t\t\t5. Modifier un Etudiant\n");
        printf("\t\t\t6. Modifier juste un element de etudiant\n");
        printf("\t\t\t7. Quitter\n");
        printf("\n\t\t\t  Entrez votre choix :");



        printf("Entrer votre choix : ");
        scanf("%d",&choix);

        switch(choix)
        {
            case 1 :
                AjouterEtudiant(tab1, i);
                i++;


                break;

            case 2 :
                AfficherTousEtu(tab1, i);

                break;
            case 3 :
                AfficherParNom(tab1, chaine);

                break;

            case 4 :
                SupprimerEtudiant(tab1,chaine);
                i--;
                break;

            case 5 :
                ModifEtudiant(tab1,chaine);
                break;

            case 6 :
                Modifier_Juste_Un_elementEtudiant(tab1,chaine);
                break;

            case 7 :
                exit(0);
                printf("\n***************************\n");
                printf(" Fin de programme \n");
                printf("\n***************************\n");
                break;

            default : printf("\"\\n\\t\\t\\tChoix Invalide!! veuillez choisir de 1 à 6 \" ");
        }

    }



}