#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define TAMANHO 100
#define TAMANHOPDD 100

typedef struct 
{
int codigo;
char tipo[50];
float custo;
float autonomia;
float autonomiai;
}Mobilidade;

typedef struct
{
  int numero;
  int NIF;
  int codigo;
  float tempo;
  float tempoi;
  float distancia;
  float distanciai;
}Pedido;

int menu();
int menu()
{int opcao;
 do { printf("\n");
      printf("M E N U\n");
      printf("1 - Inserir Veiculo \n");
      printf("2 - Listar Veiculo\n");
      printf("3 - Remover Veiculo\n"); 
      printf("0 - Sair\n");
      printf("\n");
      printf("Opcao?");
      scanf("%d",&opcao);
      
    } 
 while ((opcao<0)||(opcao>20));
 return(opcao);
}


// Função para inserção de um novo atleta no array clube
// devolvendo como resultado 1 em caso de sucesso e 0 em caso de insucesso
int inserirV(Mobilidade c[], int qt, int cod, char tipo[], float custo, float at)
{
 if ((qt < TAMANHO) && (existe(c,qt,cod)==-1))
 {
  c[qt].codigo = cod;
  strcpy(c[qt].tipo,tipo); 
  c[qt].custo = custo;
  c[qt].autonomia = at;
  c[qt].autonomiai = at;
  return(1);
 }
 else return(0);
}


void listarv(Mobilidade c[], int quantidadeVeiculos)
{int i;
 for(i=0;i<quantidadeVeiculos;i++)
 {
  printf("N_Codigo: %d\n",c[i].codigo);
  printf("Tipo: %s\n",c[i].tipo);
  printf("Custo: %.2f\n",c[i].custo);
  printf("Autonomia %.2f\n",c[i].autonomia);
  printf("\n");
 }
}

int removerVeiculo(Mobilidade c[], int quantidadeVeiculos, int cod)
{int indice;
 indice = existe(c,quantidadeVeiculos,cod);
 if (indice==-1) return(0);
 else 
  {
    c[indice] = c[quantidadeVeiculos-1];
  return(1);
  }
}

int main()
{int resultado, resultadoP, codigo=0, opcao;
 float altura, peso, res;
 float aut;
 float autonomiai;
 char nome[50];
 float custo;
 char tipo[50];
 Pedido utilizacao[TAMANHOPDD];
 Mobilidade c[TAMANHO];
 int quantidadeVeiculos = 0; // Quantidade de atletas no array clube
 int quantidadeP = 0;
int NIF;
float tempo;
float distancia;
int num = 0,r;
float precoo;
int cod;
int cd;
int i=0;

 do
 {opcao = menu();
  switch(opcao)
  {case 1: 
  codigo = codigo+1; 
  printf("Tipo?");
  scanf("%s",tipo);
  printf("Custo($)?");
  scanf("%f",&custo);
  printf("Autonomia(km)?");
  scanf("%f",&aut);
  utilizacao[codigo-1].distanciai = aut;
  resultado = inserirV(c,quantidadeVeiculos,codigo,tipo,custo,aut);
   if (resultado==1) {
     printf("Inserido com sucesso!\n");
     quantidadeVeiculos++;   
      }
	   else printf("Não inserido!");
    	break;
  
  case 2:
  listarv(c,quantidadeVeiculos);
  break;
  case 3:
  printf("Codigo?");
	scanf("%d",&codigo);
	res = removerVeiculo(c,quantidadeVeiculos,codigo);
  if (res==1){
  quantidadeVeiculos--;
  printf("Removido com sucesso!\n");
	}
	  else printf("Codigo inexestente!");
  break;
  
  }
 }
 while(opcao != 0);
 return(0);
 }


