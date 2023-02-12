#include <stdio.h>
#include <stdlib.h>
//#include <math.h
#include <string.h>

int main(int argc, char*argv[])
{
    int num1, num2, resultat = 0, f = 1, i, pgcd, max;
    char operateur;
    //argc nombre total (4: a.out, num1, num2, +) d'arguments dans le tableau argv
    //argc nombre total (3: a.out, num1,!) d'arguments dans le tableau argv
  

    // Vérifier si le nombre d'arguments est correct
    if(argc==3){
        num1 = atoi(argv[1]);// atoi convertit une chaîne de caractères en entier
        operateur = *argv[2];
    }else if (argc==4){
        num1 = atoi(argv[1]);// atoi convertit une chaîne de caractères en entier
        num2 = atoi(argv[2]);/// atoi convertit une chaîne de caractères en entier
        operateur = *argv[3];
    }
    
    
    if ((argc != 3 && argc != 4) || (argc == 3 && argv[2][1] != '\0') || (argc == 4 && argv[3][1] != '\0')) {
        printf("Nombre d'arguments incorrect.\n");
        return 1;// Le code de retour 1 indique qu'une erreur s'est produite
    }
    // Utilisation d'un switch pour traiter les opérateurs 
    switch(operateur){
        case '+':
            resultat = num1 + num2;
            printf("\n  resultat  %d %c %d  = %d", num1, operateur, num2, resultat);
            break;
            
        case '-':
            resultat = num1 - num2;
            printf("\n  resultat  %d %c %d  = %d", num1, operateur, num2, resultat);
            break;          
        case 'x':
            resultat = num1 * num2;
            printf("\n  resultat  %d %c %d  = %d", num1, operateur, num2, resultat);
            break;
        case '/':
            resultat = num1 / num2;
            printf("\n  resultat  %d %c %d  = %d", num1, operateur, num2, resultat);
            break;
        case '%':
            resultat = num1 % num2;
            printf("\n  resultat  %d %c %d  = %d", num1, operateur, num2, resultat);
            break;
        case '!':
            for (i = 1; i <= num1; i++){
                f = f * i;
             }
            printf("Factorielle de %d = %d\n", num1, f);
            break;
            
        case 'L':
            for(i=1; i <= num1 && i <= num2; ++i)
            {
                if(num1%i==0 && num2%i==0)
                pgcd = i;
            }
            printf(" PGCD de deux nombres %d et %d est %d.", num1, num2, pgcd);
            break;
        case 'p':
            max = (num1 > num2) ? num1 : num2;
            while (max % num1 != 0 || max % num2 != 0){
                max++;
            }
            printf("Le PPCM de %d et %d est %d.", num1, num2, max);
            break;    
    
        default:
            printf("\n Opérateur non valide ");
            
            
    }
    return 0;
}
