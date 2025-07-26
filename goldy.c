#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define Max_Char 20 //max of char that can be used in the name and color
#define Max_Players 5//max number of players

void ListPlayers();//purpose to list the players
void CandT();//function used to clear and give a sleep(2) 

int counter =0;

typedef struct {

  char name[Max_Char];
  char color[Max_Char];
  long long int balance;

} player;//player struct

player players[Max_Players];//global array of players

void start(){

  int plays = 0;
  printf("Quantos jogadores:");
    scanf("%d",&plays);
    counter = plays;
  
  for (int i=0;i<counter;i++){
      printf("Digite o nome:");
        scanf("%s", players[i].name);
      printf("Digite a cor:");
        scanf("%s", players[i].color);
      players[i].balance = 25000000;
  }
  system("clear");
  printf("Players Registrados:\n");
  ListPlayers();
  CandT();
}//register the players and "start" the game

void ListPlayers(){
  for(int i=0;i<counter;i++){
      printf("-------------------------------\n");
      printf("(%d) - %s | %s | %lld\n",i+1,players[i].name,players[i].color,players[i].balance);
      printf("-------------------------------\n");
  }
  
}//this only lists the players avoiding tons of unecessary code.
int PayMenu(){
  int opt=0;
  printf("Escolha:\n\033[91m(1) - pagar\033[0m\n\033[92m(2) - receber\033[0m\n\033[94m(3) - voltar\033[0m\n[+]:");
    scanf("%d",&opt);
  return opt;
}
int pay(int index){
  int aux=0,sel=0,op2=0;
  long long int value;
  aux = PayMenu();
  switch (aux) {
    case 1:
      printf("Quem vai receber:\n");
      ListPlayers();
        scanf("%d",&sel);
        sel--;
      printf("Digite o valor:");
        scanf("%lld",&value);
      players[sel].balance += value;
      players[index].balance -= value;
      printf("\033[91mValor de: %lld | Depositado para: %s\033[0m\n\n",value,players[sel].name);
    break;
    case 2:
      printf("Receber:\n(1)-Beneficio\n(2)-Pró-Labore\n");
        scanf("%d",&op2);
      if(op2 == 1){
        printf("Quem vai receber:\n");
        ListPlayers();
        scanf("%d",&sel);
        sel--;
        printf("Digite o valor:");
        scanf("%lld",&value);
        players[sel].balance += value;
        printf("\033[91mValor de: %lld | Depositado para: %s\033[0m\n\n",value,players[sel].name);
      }else if(op2 == 2){
        printf("Quem vai receber:\n");
        ListPlayers();
        scanf("%d",&sel);
        sel--;
        players[sel].balance += 200000;
      }
      break;
    case 3:
      break;
    default:
      printf("Escolha uma das opções!!\n");
      break;
  }
}

void exec(){
  int idx=0;
  do {
    ListPlayers();
    printf("[+]:");
      scanf("%d",&idx);
      idx--;
    printf("Vez de: %s!\n",players[idx].name);
    pay(idx);
  
}while(idx >= 0);
int menu(){
  int opt = 0;
    scanf("%d",&opt);
  return opt;
  }
}
void CandT(){
  sleep(2);
  system("clear");
}
void Img(){

  printf("\033[93m");
    printf(R"EOF(
            
 ██████╗  ██████╗ ██╗     ██████╗ ██╗   ██╗
██╔════╝ ██╔═══██╗██║     ██╔══██╗╚██╗ ██╔╝
██║  ███╗██║   ██║██║     ██║  ██║ ╚████╔╝ 
██║   ██║██║   ██║██║     ██║  ██║  ╚██╔╝  
╚██████╔╝╚██████╔╝███████╗██████╔╝   ██║   
 ╚═════╝  ╚═════╝ ╚══════╝╚═════╝    ╚═╝   
                                                           
)EOF");
    printf("\033[0m");
    printf("\033[91m");
}//displays some image (ascii art)

int game(){
  int op = 0;
  while (op != 3) {
    system("clear");
    Img();
    printf("Uma Ferramenta Para um Certo Jogo de Tabuleiro\n\n");
    printf("\033[0m");
    printf(" \033[92m(1) - Jogar\033[0m\n \033[94m(2) - historico\033[0m\n \033[91m(3) - Sair\033[0m\n");
      scanf("%d",&op);
      switch(op){
        case 1:
          start();//the function that start the players
          exec();//make the entire game run
        break;
        case 2:
        //logs();
        break;
        case 3:
        break;
        default:
          printf("escolha uma das opções!!\n");
        break;
      }
   }
}//game function that hold start(),exec() and logs function on the main loop.
int main(){
  game();
}
