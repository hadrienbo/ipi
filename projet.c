#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "projet.h"
int SIZE=4;

struct Score{
  int J1;
  int J2;
};

int paires(char*** jeu){
  int p=0;
  int i;
  int j;
  int k;
  int l;
  for(i=0;i<SIZE;i++){
	for(j=0;j<SIZE;j++){
	  if(strcmp(jeu[i][j],"*")!=0){
	      for(k=0;k<SIZE;k++){
		for(l=0;l<SIZE;l++){
		  if((i!=k || j!=l) && strcmp(jeu[i][j],jeu[k][l])==0){
		    p++;
		  }
		}
	      }
	  }
	}
  }
  return p/2;
}


char*** init_tuiles(int n){
  int i;
  int k;
  
  srand(time(NULL));
  int a=rand()%(SIZE)+0;
  int b=rand()%(SIZE)+0;
  
  /*création d'un tableau tab qui contiendra toutes les tuiles saisies par l'utilisateur */
  char** tab=(char**)malloc(n*sizeof(char*));
  printf("%d tuiles à créer :\n",n);
  for(k=0;k<n;k++){
    tab[k]=(char*)malloc(8*sizeof(char));
    printf("la valeur de la tuile numéro %d (14 caractères max) : ",k);
    scanf("%s",&tab[k][0]);
    printf("\n");
    }
 /* création du tableau tuiles*/
  char*** tuiles=(char***)malloc(SIZE*sizeof(char**));
  for(k=0;k<SIZE;k++){
    tuiles[k]=(char**)malloc(SIZE*sizeof(char*));
    for(i=0;i<SIZE;i++){
      tuiles[k][i]=(char*)malloc(15*sizeof(char));
      tuiles[k][i]="vide";    /*les cases du tableau sont initialisées à "vide"*/
    }
  }
  
  for(k=0;k<n;k++){
    while(strcmp(tuiles[a][b],"vide")!=0){
      a=rand()%(SIZE)+0;
      b=rand()%(SIZE)+0;
    }
    tuiles[a][b]=tab[k];
    while(strcmp(tuiles[a][b],"vide")!=0){
     
      a=rand()%(SIZE)+0;
     
      b=rand()%(SIZE)+0;
     
    }
    tuiles[a][b]=tab[k];
  }
  return tuiles;
}

char*** init_jeu(char*** tuiles){
  int k;
  int i;
  char*** jeu=(char***)malloc(SIZE*sizeof(char**));
  for(k=0;k<SIZE;k++){
    jeu[k]=(char**)malloc(SIZE*sizeof(char*));
    for(i=0;i<SIZE;i++){
      jeu[k][i]=(char*)malloc(15*sizeof(char));
      if(strcmp(tuiles[k][i],"vide")!=0){
	  jeu[k][i]="*";
      }
      else{
	jeu[k][i]="vide";
      }
    }
  }
  return jeu;
}

int retourner2(char*** jeu,char*** tuiles, int* J){
  int i;
  int j;
  int k;
  int l;
  printf("tapez la ligne puis la touche entrée puis la colonne de la première tuile que vous voulez retourner (entre 0 et %d) puis la touche entrée :\n",SIZE);
  scanf("%d",&i);
  scanf("%d",&j);
  if(0<=i && i<=(SIZE-1) && 0<=j && j<=(SIZE-1) && strcmp(jeu[i][j],"*")==0){
    printf("tapez maintenant la ligne puis la touche entrée puis la colonne de la deuxième tuile que vous voulez retourner (entre 0 et %d) puis la touche entrée :\n",SIZE);
    scanf("%d",&k);
    scanf("%d",&l);
    if(0<=k && k<=(SIZE-1) && 0<=l && l<=(SIZE-1) && strcmp(jeu[k][l],"*")==0 && (i!=k || j!=l)){
      jeu[i][j]=tuiles[i][j];
      jeu[k][l]=tuiles[k][l];
      if (strcmp(jeu[i][j],jeu[k][l])==0){
	*J+=1;
      }
      for(i=0;i<SIZE;i++){
	for(j=0;j<SIZE;j++){
	  printf("%s ",jeu[i][j]);
	}
	printf("\n");
      }
      
      return 0;
    }
  }
  printf("entrées non valides\n");
  return 1;
}

int tour(char*** jeu, char*** tuiles,int* J){
  int a=*J;
  while(retourner2(jeu,tuiles,J)==1){
    retourner2(jeu,tuiles,J);}
  if(*J>a){
    printf("le joueur remporte 1 point et rejoue\n");
    return 0;}
  return 1;
}
  
  
int main(void){
  int i;
  int j;
  int n;
  int rejouer=0;
  struct Score score;
  score.J1=0;
  score.J2=0;
  if(SIZE%2==0){
    n=SIZE*SIZE/2;
  }
  else{
    n=(SIZE*SIZE-1)/2;
  }
  char*** tuiles=init_tuiles(n);
  char *** jeu=init_jeu(tuiles);
  
  for(i=0;i<SIZE;i++){
    for(j=0;j<SIZE;j++){
      printf("%s ",tuiles[i][j]);
    }
    printf("\n");
  }
   printf("\n");
   for(i=0;i<SIZE;i++){
    for(j=0;j<SIZE;j++){
      printf("%s ",jeu[i][j]);
    }
    printf("\n");
   }
   while(paires(jeu)!=n){
     printf("à J1 de jouer\n");
     while(rejouer==0){
       rejouer=tour(jeu,tuiles,&score.J1);
       if(paires(jeu)==n){
	 if(score.J1>score.J2){
	   printf("J1 gagne !!\n");
	 }
	 else if(score.J1==score.J2){
	   printf("match nul !!\n");
	 }
	 else{
	   printf("J2 gagne !!\n");
	 }
       }
     }
    rejouer=0;
        
    printf("à J2 de jouer\n");
    while(rejouer==0){
       rejouer=tour(jeu,tuiles,&score.J2);
   }
   if(paires(jeu)==n){
     if(score.J1>score.J2){
       printf("J1 gagne !!\n");
	 }
     else if(score.J1==score.J2){
       printf("match nul !!\n");
     }
     else{
       printf("J2 gagne !!\n");
	 }
   }
  rejouer=0;
   }
if(score.J1>score.J2){
	   printf("J1 gagne !!\n");
	 }
 else if(score.J1==score.J2){
       printf("match nul !!\n");
 }
 else{
   printf("J2 gagne !!\n");
 }
 free(tuiles);
 free(jeu);
return 0;
}
  

 
  
 
  
    
