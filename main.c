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
int existe(Mobilidade c[], int qt , int cod);
int existepdd(Pedido utilizacao[], int qt , int cod);
int inserirV(Mobilidade c[], int qt, int cod, char tipo[], float custo, float aut);
int inserirP(Pedido utilizacao[],Mobilidade c[], int qt, int num, int NIF, int cod, float tempo, float distancia);
int lerP(Pedido utilizacao[],Mobilidade c[]);
int lerV(Mobilidade c[]);

int menu()
{int opcao;
 do { printf("M E N U\n");
      printf("1 - Inserir Veiculo \n");
      printf("2 - Listar Veiculo\n");
      printf("3 - Remover Veiculo\n"); 
      printf("4 - Inserir Pedido\n");
      printf("5 - Listar Pedido\n");
      printf("6 - Remover Pedido\n");
      printf("7 - Guardar veiculos\n");
      printf("8 - Ler veiculos\n");
      printf("9 - Guardar pedidos\n");
      printf("10 - Ler pedidos\n");
      printf("11 - Consultar veiculo\n");
      printf("12 - Custo do pedido\n");
      printf("13 - Ordenar pelo N_ordem\n");
      printf("0 - Sair\n");
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

int inserirP(Pedido utilizacao[],Mobilidade c[],int qt, int num, int NIF, int cod, float tempo, float distancia)
{
  if ((qt < TAMANHOPDD) && (existepdd(utilizacao,qt,num)==-1))
  
  { 
    utilizacao[qt].numero = num;
    utilizacao[qt].NIF = NIF;
    utilizacao[qt].codigo = cod;
    utilizacao[qt].tempo = tempo;
    utilizacao[qt].tempoi = tempo;
    utilizacao[qt].distancia = distancia;
    return(1);
  }
  else return(0);
}

void consulta(Pedido utilizacao[], Mobilidade c[],int qt,int qtt, int cod, int num, int NIF, float autonomiai)
{
  int i=0;
   cod--;
  for(i=0;i<=qt;i++){
  if(utilizacao[cod].codigo==utilizacao[i].codigo)
 {
  printf("Numero de Pedido: %d\n", utilizacao[i].numero);
  printf("NIF: %d\n", utilizacao[i].NIF);
  printf("Tempo Inicio: %.2f\n", utilizacao[i].tempoi);
  printf("Tempo Termino: %.2f\n", utilizacao[i].tempo);
  printf("Codigo do veiculo: %d\n", utilizacao[i].codigo);
  printf("Autonomia: %.2f\n", utilizacao[cod].distanciai);
  printf("\n");
  }
 }
 }

void ordenarN(Pedido utilizacao[], int qt)
{int i,j;
 Pedido aux;
 for(i=0;i<qt;i++)
   for(j=i+1;j<qt;j++)
	   if (utilizacao[i].numero>utilizacao[j].numero)
	   {memcpy(&aux,&utilizacao[i],sizeof(Pedido));
	    memcpy(&utilizacao[i],&utilizacao[j],sizeof(Pedido));
	    memcpy(&utilizacao[j],&aux,sizeof(Pedido));
	   }
}


void custopreco(Pedido utilizacao[], Mobilidade c[],int n, float custo,int cod)
{
  int i;
  float preco;
  float aut;
  float pre;
  n--;
  preco = c[n].custo/c[n].autonomiai;
  aut = c[n].autonomiai - c[n].autonomia;
  pre = preco*aut;
  printf("Custo: %.2f\n", pre);
	printf("\n");

}

int auton(Pedido utilizacao[], Mobilidade c[],int qt, float distancia, int cod){
int i=0;
  cod--;
 
  if (distancia <= c[cod].autonomia){
  c[cod].autonomia = c[cod].autonomia - distancia;
  return(c[cod].autonomia);
}
else{ 
  for (i=cod+1;i<qt;i++){
  //for (i=cod+1;i>=0;i--){
  if(c[i].autonomia >= distancia)
  if(strcmp(c[cod].tipo,c[i].tipo) == 0 ){
  //Se for igual 0 tem mesmo nome
printf("Existe um veiculo do mesmo tipo tem o codigo %i\n", c[i].codigo);
printf("Com a Autonomia %.2f\n",c[i].autonomia);
	  printf("\n");

  //}
  }}


  //
  for (i=cod+1;i>=0;i--){
  if(c[i].autonomia >= distancia)
  if(strcmp(c[cod].tipo,c[i].tipo) == 0 ){
  //Se for igual 0 tem mesmo nome
printf("Existe um veiculo do mesmo tipo tem o codigo %i\n", c[i].codigo);
printf("Com a Autonomia %.2f\n",c[i].autonomia);
	  printf("\n");

  //}
  }}

return(-1);

}
}
//}

void listarv(Mobilidade c[], int quantidadeVeiculos)
{int i;
 for(i=0;i<quantidadeVeiculos;i++)
 {
  printf("N_Codigo: %d\n",c[i].codigo);
  printf("Tipo: %s\n",c[i].tipo);
  printf("Custo: %.2f\n",c[i].custo);
  printf("Autonomia %.2f\n",c[i].autonomia);
  printf("Autonomia Inicial %.2f\n",c[i].autonomiai);
  printf("\n");
 }
}

void listarp(Pedido P[], int quantidadeP)
{int i;
 for(i=0;i<quantidadeP;i++)
 {
  printf("N_Pedido: %d\n",P[i].numero);
  printf("NIF: %d\n",P[i].NIF);
  printf("Cod veiculo: %d\n",P[i].codigo);
  printf("Tempo: %.2f\n",P[i].tempo);
  printf("Distancia: %.2f\n",P[i].distancia);
  printf("\n");
 }
}

int existe(Mobilidade c[], int qt, int cod)
{int i=0;
 while (i<qt)
 {if (c[i].codigo==cod) return(i);
  i++;
 }
 return(-1);
}

int existepdd(Pedido utilizacao[], int qt, int cod)
{int i=0;
while (i<qt)
{
  if(utilizacao[i].codigo==cod) return(i);
  i++;
}
return (-1);
}

int existe2(Pedido utilizacao[], int qt, int num)
{int i=0;
while (i<qt)
{
  if(utilizacao[i].numero==num) return(i);
  i++;
}
return (-1);
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

int removerPedido(Pedido utilizacao[], int qt, int num)
{int indice;
 indice = existe2(utilizacao,qt,num);
 if (indice==-1) return(0);
 else 
  {
    utilizacao[indice] = utilizacao[qt-1];
	 printf("\n");
  return(1);
  }
}

int lerP(Pedido P[],Mobilidade c[])
{FILE* fp;
 int qt,num,NIF,cod, resultadoP;
 float tempo, distancia;
 fp = fopen("pedidos.txt","rt");
 qt = 0;
 while(!feof(fp)) 
 {fscanf(fp,"N_Pedido: %d\n",&num);
  fscanf(fp,"NIF: %d\n",&NIF);
  fscanf(fp,"Cod veiculo: %d\n",&cod);
  fscanf(fp,"Tempo: %f\n",&tempo);
  fscanf(fp,"Distancia: %f\n",&distancia);
  fscanf(fp,"\n");
  resultadoP = inserirP(P,c,qt,num,NIF,cod,tempo,distancia);
  if (resultadoP==1) qt++;
 }
 fclose(fp);
 return(qt);
}

void guardarP(Pedido P[], int quantidadeP)
{int i;
 FILE* fp;
 fp = fopen("pedidos.txt","wt");
 for(i=0;i<quantidadeP;i++)
 {fprintf(fp,"N_Pedido: %d\n",P[i].numero);
  fprintf(fp,"NIF: %d\n",P[i].NIF);
  fprintf(fp,"Cod veiculo: %d\n",P[i].codigo);
  fprintf(fp,"Tempo: %.2f\n",P[i].tempo);
  fprintf(fp,"Distancia: %.2f\n",P[i].distancia);
  fprintf(fp,"\n");
 }
 fclose(fp);
}

int lerV(Mobilidade c[])
{FILE* fp;
 int qt,cod,resultadoV;
 float autonomia;
 float custo;
 char tip[50];
 fp = fopen("veiculos.txt","rt");
 qt = 0;
 while(!feof(fp)) 
 {fscanf(fp,"Codigo do veiculo: %d\n",&cod);
  fscanf(fp,"Tipo de veiculo: %s\n",tip);
  fscanf(fp,"Custo: %f\n",&custo);
  fscanf(fp,"Autonomia: %f\n",&autonomia);
  fscanf(fp,"\n");
  resultadoV = inserirV(c,qt,cod,tip,custo,autonomia);
  if (resultadoV==1) qt++;
 }
 fclose(fp);
 return(qt);
}

void guardarV(Mobilidade P[], int quantidadeVeiculos)
{int i;
 FILE* fp;
 fp = fopen("veiculos.txt","wt");
 for(i=0;i<quantidadeVeiculos;i++)
 {fprintf(fp,"Codigo do veiculo: %d\n",P[i].codigo);
  fprintf(fp,"Tipo de veiculo: %s\n",P[i].tipo);
  fprintf(fp,"Custo: %f\n",P[i].custo);
  fprintf(fp,"Autonomia: %.2f\n",P[i].autonomia);
  fprintf(fp,"\n");
 }
 fclose(fp);
}

int main()
{int resultado, resultadoP, codigo=0, opcao;
 float altura, peso, res;
 float aut;
 float autonomiai;
 float auton;
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
 int fsdf;
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
     printf("Inserido com sucesso!");
     printf("\n");
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
  printf("Removido com sucesso!");
	}
	  else printf("Codigo inexestente!");
  break;
  case 4:
  num = num+1;
  printf("Veículos disponíveis:");
  printf("\n");
  listarv(c,quantidadeVeiculos);
  printf("Insira o codigo do veículo:");
  scanf("%i", &cod);
  
  if (existe(c,quantidadeVeiculos,cod)!=-1)
  {
  printf("NIF?");
  scanf("%i",&NIF);
  printf("Tempo(min)?");
  scanf("%f",&tempo);
  printf("Distancia(km)?");
  scanf("%f",&distancia);
  
  resultadoP = inserirP(utilizacao,c,quantidadeP,num,NIF,cod, tempo, distancia);
  r = auton(utilizacao,c,quantidadeVeiculos,distancia,cod);
  if (resultadoP==1 && r >= 0) {
     printf("Pedido realizado!");
     quantidadeP++;  
             
      }
      
	   else{ printf("Nao inserido!\n");
     }
     }
  else printf("Codigo inexistente!\n\n");
    break;

  case 5:
    listarp(utilizacao,quantidadeP);
    break;
  case 6:
  printf("Insira o N_ordem que deseja remover:");
	scanf("%d",&num);
	res = removerPedido(utilizacao,quantidadeP,num);
  if (res==1){
  quantidadeP--;
  printf("Removido com sucesso!\n");
	}
	  else printf("Codigo inexistente!\n");
    break;
  case 7:
  	guardarV(c, quantidadeVeiculos);
  	break;
  case 8:
  	quantidadeVeiculos = lerV(c);
  	break;
  case 9:
  	guardarP(utilizacao, quantidadeP);
  	break;
  case 10:
  	quantidadeP = lerP(utilizacao,c);
  	break;
  case 11:
    listarv(c,quantidadeVeiculos);
    printf("Insira o codigo do veiculo que deseja consultar:");
    scanf("%d",&cod);
    
    if (existe(c,quantidadeVeiculos,cod)!=-1)
    {
      consulta(utilizacao,c,quantidadeP,quantidadeVeiculos,cod,num, NIF, autonomiai);
    }
    else
    {
      printf("Codigo inexistente!");
      printf("\n");
    }
    break;
  case 12:
    printf("Pedidos:\n");
    listarp(utilizacao,quantidadeP);
    printf("Insira o N_de ordem:");
    scanf("%d",&num);
    
    if (existepdd(utilizacao,quantidadeP,cod)!=-1)
     custopreco(utilizacao,c,num,custo,cod);
    else
    printf("Numero inexistente");
   printf("\n");
    break;
  case 13:
    ordenarN(utilizacao,quantidadeP);
   
    listarp(utilizacao,quantidadeP);
  break;
    
  }
 }
 while(opcao != 0);
 return(0);
 }

