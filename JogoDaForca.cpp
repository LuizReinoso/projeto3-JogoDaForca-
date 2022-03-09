
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<ctype.h>
#include <windows.h>
void jogo (char palavra[], char temp[]);
void maiuscula (char palavra[]);
void forca(char corpo[6], int tentativa);

int main () {
    int i,j;
    char wordsdata[10][15]= {"pera","goiaba","banana","uva","kiwi","pitanga","carambola","jabuticaba","amora","lima"};
    char palavra[10],temp[10];
    srand(time(NULL));
    i=rand()%5;
    for(j=0;wordsdata[i][j]!='\0';j++){
        palavra[j]=wordsdata[i][j];
        temp[j]='_';
    }
    palavra[j]='\0';
    temp[j]='\0';
    jogo(palavra,temp);

return 0;

}

void forca(char corpo[10], int tentativa){
     printf ("  _ _ \n");
     printf (" |   |\n");
     printf (" |   %c \n",corpo[5]);
     printf (" |  %c",corpo[3]);
     printf ("%c",corpo[4]);
     printf ("%c \n",corpo[2]);
     printf (" |  %c",corpo[1]);
     printf (" %c \n",corpo[0]);
     printf ("_|_   \n");
}

void maiuscula (char palavra[]){
    int i;
    for(i=0;palavra[i]!='\0';i++){
    palavra[i] = toupper(palavra[i]);
    }
    palavra[i]='\0';
}

void jogo (char palavra[], char temp[]){
    int k,erro=-1,acerto=0,achou,tentativa=6;
    char letra,corpo[6];
    do { 
        system("color 0A");
        achou=0;
        forca(corpo,tentativa);
        printf("\n\tJOGO DA FORCA!\n\n\n\t");
        printf("  %s",temp);
        printf("\n\n\nVoce tem ,somente, 6 Tentativas! --->\tTentativa %d",tentativa);
        printf("\n\nTente uma letra: ");
        scanf("%c",&letra);
        fflush(stdin);
        letra=tolower(letra);
        system("cls");
        for(k=0; palavra[k]!='\0';k++){
            if(letra==palavra[k]){
                temp[k]=letra;
                acerto++;
                achou=1;
            }
        }
        if(achou==0) {
            erro++;
            tentativa--;
            switch (tentativa) {
             case 0: corpo[0]='o'; break;
             case 1: corpo[1]='/'; break;
             case 2: corpo[2]='-'; break;
             case 3: corpo[3]='-'; break;
             case 4: corpo[4]='|'; break;
             case 5: corpo[5]='O'; break;
            }
        }

        if(acerto==strlen(palavra)){
            maiuscula(palavra);
            printf("\n\t%s",palavra);
            printf("\n\n\n\tPARABENS VOCE ACERTOU!"); break;
        }
        if(erro>=5){
            maiuscula(palavra);
            printf("\nA palavra secreta era: %s",palavra);
            printf("\n\n\n\tTENTE NOVAMENTE VOCE ERROU!"); break;
        }

    } while (erro<5);
}
