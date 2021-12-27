#include<stdio.h>
#include<stdbool.h>
#define couleur(param) printf("\033[%sm",param)

int main()
{
 printf("\033[H\033[2J");
 printf("\n");
 printf("###############################################################################\n\n");
 printf("#######################  LANGAGE DE PROGRAMMATION EN C  #######################\n\n");
printf("-------------------------------------------------------------------------------------------\n");
 printf("----------------------------- Bonjour Monsieur/Madame --------------------------------\n\n");
 printf("------------------------ OPERATION MATHEMATIQUE AUX CHOIX -------------------------\n\n");
 printf("------------------------- vous n'aurez qu'à suivre simplement les instrucions ------------\n\n");
 int choix;
 char valeur[100];
 debut: printf("\n");
 couleur("7");
 couleur("1;5;43;31");
 printf("Choisissez une operation:");
 couleur("0");
 printf("\n");
 printf("1.Facteur Premier\n2.Triangle de Pascal\n3.Crible d'Eratosthène\n4.Stopper\n\n");
 fgets(valeur,sizeof valeur,stdin);
 if(sscanf(valeur,"%d",&choix)==1)
 {
   int vouloir,possibilite;
   switch(choix) //switch() est une fonction de choix
   {
     case 1: //pour le produit de facteur premier
     { 
     encore1: printf("1.Traiter\n2.Menu\n3.Fermer\n\n");//encore1 nous permettra de revenir ici avec goto
     fgets(valeur,sizeof valeur,stdin);
     if(sscanf(valeur,"%d",&possibilite)==1)
     {
       if(possibilite==1) //Traitement 
       { 
         printf("\033[H\033[2J");
         couleur("1;42;37");
printf("\t################################################################################\n");
printf("\t####                                                                    ########\n");
printf("\t####    Traitement de la decomposition en produit de facteur premier    ########\n");
printf("\t####                                                                    ########\n");
printf("\t################################################################################\n\n");
couleur("0");
         long int Nombre,diviseur=2,signe=0; /*diviseur=2 car c'est le plus petit nombre Premier*/
         do
         {
          printf("Nombre à decomposer en produit de facteur premiers?:");
          fgets(valeur,sizeof valeur,stdin);
         }
         while(sscanf(valeur,"%ld",&Nombre)!=1);
         if(Nombre>1)
         {
           couleur("7;32");
           printf("\n*********Voici votre décomposition  ***********\n\n");
           couleur("0");
           couleur("1;33");
           printf("%ld=",Nombre);
           while(Nombre>1) //On arrête la division si le nombre est inferieur à 1 
           {
            if(Nombre%diviseur==0) //Nombre%diviseur=0 ssi diviseur est premier
            {
               if(signe>0) //pour afficher le signe x
               {
                  printf("×"); // On affiche le signe "x" pour ilustrer la multiplication
               }
               printf("%ld",diviseur);
               Nombre=Nombre/diviseur; //On prend le quotien du nombre à chaque fois
               signe++; //Pour afficher les autre signe 'x'
            }
            else //On rentre ici quand le nombre n'est pas premier
               diviseur++;//On prend donc le nombre suivant
          }
         }
         else 
         {
           couleur("1;31");
           printf("\nDésolé la decomposition se fait avec des nombres positifs superieurs à 1");
           couleur("0");
         }
         couleur("0");
         printf("\n");//Separer l'affichage du programme au reste
         demande1: printf("\n");//revenir à la ligne pour la lisibilité
         printf("Souhaitez vous faire une autre opration?\n1.Oui\n2.Non\n\n");
         fgets(valeur,sizeof valeur,stdin);
         if(sscanf(valeur,"%d",&vouloir)==1)
         {
           if(vouloir==1)
           {
              printf("\033[H\033[2J");
              goto debut; //on vas au debut du programme
           }
           else if(vouloir==2) goto fin; //on ferme le programme
           else
           {
              printf("\033[H\033[2J");
              couleur("1;31");
              printf("Choix invalide \n");
              couleur("0");
              printf("Veillez choisir à nouveau");
              goto demande1;
           }
         }
         else
         {
            printf("\033[H\033[2J");
            couleur("1;5;31");
            printf("Erreur de saisi\n");
            couleur("0");
            printf("Saissisez maintenant un entier svp\n\n");
            goto demande1;
         }
        }
       else if(possibilite==2)
       {
          printf("\033[H\033[2J");
          goto debut; //On vas au début du programme
       }
       else if(possibilite==3) goto fin; //On ferme le programme
       else
       { 
           printf("\033[H\033[2J");
           couleur("1;31");
           printf("Choix invalide  \n");
           couleur("0");
           printf("Veillez choisir à nouveau\n");
           goto encore1; //on repart au debut du 1er cas (Facteur premiers)
       }
      }
      else
      {
        printf("\033[H\033[2J");
        couleur("1;5;31");
        printf("Erreur de saisi \n");
        couleur("0");
        printf("Saissisez maintenant un entier svp\n\n");
        goto encore1;
      }
     };break;
     case 2: //pour le triangle de Pascal
     {
       encore2: printf("1.Traiter\n2.Menu\n3.Fermer\n\n");
       fgets(valeur,sizeof valeur,stdin);
       if(sscanf(valeur,"%d",&possibilite)==1) //Traitement 
       {
         if(possibilite==1)
         {
         printf("\033[H\033[2J");
         couleur("1;42;37");
printf("\t###################################################################################\n");
printf("\t####                                                                          #####\n");
printf("\t#### Traitement du construction du pascal dans le developpement de (a+b)^n    #####\n");
printf("\t####                                                                          #####\n");
printf("\t###################################################################################\n\n");
couleur("0");
           long int i,j,n;
           do
           {
             printf("Entrer un entier positif n dans le developpement de (a+b)^n:");
             fgets(valeur,sizeof valeur,stdin);
           }
           while(sscanf(valeur,"%ld",&n)!=1); //On obligera l'utilisateur a entrer un nombre positif
           if(n>=0)
           {
            unsigned long T[n+1][n+1];// tableau de dimension 2 
            printf("\n");
            couleur("7;32");
            printf("Votre triangle de Pascal de (a+b)^%ld est: \n\n",n);
            couleur("0");
            couleur("1;33");
            T[0][0]=1; //la 1ere ligne et colonne sera initialiser à 1
            printf("%lu\n",T[0][0]); //on affiche ligne 1 colonne 1
            for(i=1; i<=n; i++)
            {
              T[i][0]=1; //la première colonne prendra 1;
              T[i][i]=1; //la diagonale prend 1 
              printf("%lu\t",T[i][0]); //on affiche la premiere colonne
              for(j=1; j<i; j++)
              {
                 T[i][j]=T[i-1][j-1]+T[i-1][j];/*ligne i colone j sera égal à la somme de la ligne i-1 colone i-1 et ligne i-1 colonne j*/
                 printf("%lu\t",T[i][j]);/*On affiche les lignes et colonnes different de la diagonale et la première colonne*/
              }
              printf("%lu\t\n",T[i][i]);//on affiche la diagonale
            }
           }
           else
           {
             couleur("1;31");
             printf("\nDésolé le triangle de Pascal se construit avec des nombres positifs");
             couleur("0");
           }
            couleur("0");
            demande2: printf("\n");
            printf("Souhaitez vous faire une autre operation?\n1.Oui\n2.Non\n\n");
            fgets(valeur,sizeof valeur,stdin);
            if(sscanf(valeur,"%d",&vouloir)==1)
            {
              if(vouloir==1)
              {
                 printf("\033[H\033[2J");
                 goto debut; //On repart au debut du programme
              }
              else if(vouloir==2) goto fin; //on ferme le programme
              else
              {
                printf("\033[H\033[2J");
                couleur("1;31");
                printf("Choix invalide \n");
                couleur("0");
                printf("Veillez choisir à nouveau");
                goto demande2;
              }
            }
            else 
            {
               printf("\033[H\033[2J");
               couleur("1;5;31");
               printf("Erreur de saisi \n");
               couleur("0");
               printf("Saissisez maintenant un entier svp\n\n");
               goto demande2;
            }
          }
          else if(possibilite==2)
          {
            printf("\033[H\033[2J");
            goto debut; //On repart au debut du programme
          }
          else if(possibilite==3) goto fin;  //On ferme le programme
          else
          {
             printf("\033[H\033[2J");
             couleur("1;31");
             printf("Choix invalide \n");
             couleur("0");
             printf("Veillez choisir à nouveau\n");
             goto encore2; //On repart au debut du cas 2 (Triangle de Pascal)
          }
        }
        else
        {
          printf("\033[H\033[2J");
          couleur("1;5;31");
          printf("Erreur de saisi \n");
          couleur("0");
          printf("Saissisez maintenant un entier svp\n\n");
          goto encore2;
        }
      };break;
      case 3:  //Pour le crible d'Eratosthène
      {
         encore3: printf("1.Traiter\n2.Menu\n3.Fermer\n\n");
         fgets(valeur,sizeof valeur,stdin);
         if(sscanf(valeur,"%d",&possibilite)==1)
         {
           if(possibilite==1) //Traitement
           {
             printf("\033[H\033[2J");
             couleur("1;42;37");
printf("\t###################################################################################\n");
printf("\t####                                                                           ####\n");
printf("\t#### Traitement du crible d'Erathostène pour la recherche des nombres premiers ####\n");
printf("\t####                                                                           ####\n");
printf("\t###################################################################################\n\n");
couleur("0");
              long int N,i;
              entier: printf("Entrer l'entier pour optenir les nombres premiers qui lui sont inferieur ou égal:");
              fgets(valeur,sizeof valeur,stdin);
              if(sscanf(valeur,"%ld",&N)==1)
              {
               if(N>=0)
               {
                bool Supprime[N];//On déclare un tableau de booléen
                printf("\n");
                couleur("7;32");
                printf("********Les nombres premiers inferieurs ou égales à %ld sont :\n\n",N);
                couleur("0");
                couleur("1;33");
                for(i=1; i<=N;i++)
                {
                   Supprime[i]=false;//Je suppose qu'aucune valeure n'est multiple d'une autre
                }
                for(i=2; i<=N; i++)
                {
                   if(!Supprime[i])//supprime[i]=false signifie que le nombre est premier
                   {
                     printf("%10ld\t",i); //On affiche ce nombre premier
                     int multiple=i+i; //multiple prend le plus petit multiple de i
                     while(multiple<=N) //un multiple d'un nombre depasse pas ce nombre 
                     {
                       Supprime[multiple]=true; //Je supprime les multiples de i
                       multiple+=i;//multiple prend le multiple suivant à supprimer
                     }
                   }
                }
                couleur("0");
               }
               else
               {
                 couleur("1;31");
                 printf("\nDésolé le crible s'applique sur des nombres positifs");
                 couleur("0");
           }
              }
              else
              {
                printf("\033[H\033[2J");
                couleur("1;5;31");
                printf("Erreur de saisi \n");
                couleur("0");
                printf("Saissisez maintenant un entier svp\n\n");
                goto entier;
              }
             demande3: printf("\n");//revient à la ligne pour un affichage visible
             printf("Souhaitez vous faire une operation?\n1.Oui\n2.Non\n\n");
             fgets(valeur,sizeof valeur,stdin);
             if(sscanf(valeur,"%d",&vouloir)==1)
             {
               if(vouloir==1)
               {
                  printf("\033[H\033[2J");
                  goto debut; //On repart au debut du programme
               }
               else if(vouloir==2) goto fin; //on ferme le programme
               else
               {
                  printf("\033[H\033[2J");
                  couleur("1;31");
                  printf("Choix invalide \n");
                  couleur("0");
                  printf("Veillez choisir à nouveau");
                  goto demande3;
               }
             }
             else
             {
                printf("\033[H\033[2J");
                couleur("1;5;31");
                printf("Erreur de saisi \n");
                couleur("0");
                printf("Saissisez maintenant un entier svp\n\n");
                goto debut;
             }
          }
          else if(possibilite==2)
          {
             printf("\033[H\033[2J");
             goto debut; //On repart au debut du programme
          }
          else if(possibilite==3) goto fin; //On repart à la fin du programme
          else
          {
             printf("\033[H\033[2J");
             couleur("1;31");
             printf("Choix invalide \n");
             couleur("0");
             printf("Veillez choisir à nouveau\n");
             goto encore3; //On reprend le cas 3 (crible d'Eratosthène)
          } 
        }
        else
        {
          printf("\033[H\033[2J");
          couleur("1;5;31");
          printf("Erreur de saisi \n");
          couleur("0");
          printf("Saissisez maintenant un entier svp\n\n");
          goto encore3;
        }
     };break;
     case 4:
     {
      fin:
      printf("\033[H\033[2J");
      printf("\n");
      couleur("1;40;33"); printf("###########################################################################################\n");
      printf("#######                                                                               #####\n");
      printf("#######   Merci d'avoir utiliser notre programme  aurevoir et a très bientôt   #####\n");
      printf("#######                                                                               #####\n");
      printf("###########################################################################################\n\n");
     };break;
     default:
     {
        printf("\033[H\033[2J");
        couleur("1;31");
        printf("Choix invalide ");
        couleur("0");
        goto debut;
     }
    }
   }
   else
   {
     printf("\033[H\033[2J");
     couleur("1;5;31");
     printf("Erreur de saisi \n");
     couleur("0");
     printf("Saissisez maintenant un entier svp\n");
     goto debut;
   }
   printf("------------------------------------- --------------------------------------------------------------------");
   couleur("0");
   printf("\n\n\n");
}
