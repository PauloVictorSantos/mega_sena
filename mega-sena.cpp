#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
const int linha=10000000,coluna=6;
int quina[linha][coluna];
int sorteio[6];
int am[6];
//Procedimento para gerar o cartão 
void Geracartao(int v[][6],int linha,int coluna){ 
     int num, j, tam=0;
     bool repete;
     v[linha][tam]=rand()%60+1;
     tam++;
     while(tam<coluna){
          num=rand()%60+1;
          repete=false;
          for (j=0;j<tam;j++){
              if (num==v[linha][j]){
                 repete=true;
              }
          }
          if (repete==false){
             v[linha][tam]=num;
             tam++; 
          }
     }
}
//Procedimento para ordenar crescentemente o cartão
void OrdenaCartao(int x[][6],int linha,int coluna){
     int aux; 
     for (int j=0;j<coluna-1;j++){
         for (int k=j+1;k<coluna;k++){
             if (x[linha][k]<x[linha][j]){
                aux=x[linha][j];
                x[linha][j]=x[linha][k];
                x[linha][k]=aux;
             }
         }
     }
}
//procedimento para imprimir a matriz
void ImprimeLinha(int f[][6],int linha,int coluna){
     cout<<"Cartao "<<linha+1<<": ";
     for (int i=0;i<coluna;i++){
         cout<<f[linha][i]<<" ";
     }
     cout<<endl;
}
//procedimentos para carregar a matriz com os 5000 cartões 
//Procedimento para carregar as colunas sem repetir
void CarregaMatriz(int v[][6],int linha,int coluna){ 
     int num, j, tam=0;
     bool existe;
     v[linha][tam]=rand()%60+1;
     tam++;
     while(tam<coluna){
          num=rand()%60+1;
          existe=false;
          for (j=0;j<tam;j++){
              if (num==v[linha][j]){
                 existe=true;
              }
          }
          if (existe==false){
             v[linha][tam]=num;
             tam++; 
          }
     }
}

//procedimento para carregar a linha
void CarregaLinha(int x[][6],int linha,int coluna){
      for(int i=0;i<linha;i++){
        CarregaMatriz(x,i,coluna); 
        OrdenaCartao(x,i,coluna);
        ImprimeLinha(x,i,coluna);
      }
}
//-------------------------------------------------Sorteio------------------------------------------
//procedimento para gerar sorteio
void Sorteio(int s[6], int linha){
	int numero_sorteio, d=0,tam=0;
	bool repete;
	repete=false;
	s[d]=rand()%60+1;
	tam++;
	while(tam<linha){
		numero_sorteio=rand()%60+1;
		for(int j=0;j<linha;j++){
			if(s[j]==numero_sorteio){
				repete=true;
			}
		}	
			if(repete==false){
				s[tam]=numero_sorteio;
				tam++;
			}
	}
}
//Ordena os números do sorteio
void OrdenaSorteio(int x[], int t){
int aux;
	for(int i=0 ; i<t-1;i++){
		for (int j=i+1; j<t;j++){	
			if(x[j]<x[i]){
				aux =x[i];
				x[i]=x[j];
				x[j]=aux;
			}
		}
	}
}
//imprime sorteio
void ImprimeSorteio(int f[], int n){
	cout<<"-------------Sorteio-------------"<<endl;
	for(int i=0; i<n;i++){
		cout<<f[i]<<" ";
	}
	cout<<endl;
	cout<<"---------------------------------"<<endl;
}
//Imprime os numeros que foram achados no cartão
void MostraNumerosAcerto(int m[6],int cont){
	for(int i=0;i<cont;i++){
		cout<<m[i]<<" ";
	}
}
//achar o ganhador
void AcharGanhador(int d[][6], int v[6], int linha, int coluna, int tam,int m[6]){
	for(int x=0;x<linha;x++){
			int cont=0;		 	
			for(int vet=0;vet<tam;vet++){
				for(int j=0;j<coluna;j++){
					if(d[x][j]==v[vet]){
						am[cont]=d[x][j];
						cont++;
					}
				}
					
			}
			if(cont==4){
				cout<<endl;
				cout<<"Cartao "<<x+1<<" acertou "<<cont<<" numeros"<<endl;
				cout<<"Os numeros achados no Cartao "<<x+1<<" foram: ";
				OrdenaSorteio(am, cont);
				MostraNumerosAcerto(am,cont);
				cout<<endl;
			}
			else if(cont==5){
				cout<<endl;
				cout<<"Cartao "<<x+1<<" acertou "<<cont<<" numeros"<<endl;
				cout<<"Os numeros achados no Cartao "<<x+1<<" foram: ";
				OrdenaSorteio(am, cont);
				MostraNumerosAcerto(am,cont);
				cout<<endl;
			}
			else if(cont==6){
				cout<<endl;
				cout<<"Cartao "<<x+1<<" acertou "<<cont<<" numeros"<<endl;
				cout<<"Os numeros achados no Cartao "<<x+1<<" foram: ";
				OrdenaSorteio(am, cont);
				MostraNumerosAcerto(am,cont);
				cout<<endl;
			}			
		}
}	
	

int main(){
	srand(time(NULL));
	CarregaLinha(quina,1000,6);
	Sorteio(sorteio,6);
	OrdenaSorteio(sorteio,6);
	ImprimeSorteio(sorteio,6);
	AcharGanhador(quina,sorteio,1000,6,6,am);
	system("pause");
}
