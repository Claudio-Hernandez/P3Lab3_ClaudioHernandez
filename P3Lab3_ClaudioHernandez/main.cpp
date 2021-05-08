#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include<time.h>
#include<stdlib.h>

using std::string;
using std::cout;
using std::cin;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int menu();
char* ejercicio1(int, char*,char*,int);
char** ejercicio2( int,int,int);
void ejercicio3(char**,char*,int,int, int, int,int);

int main(int argc, char** argv) {
	int opcion2;
	while(opcion2!=4) {
		switch(opcion2= menu()) {
			case 1: {
				cout<<"ingresa tamanio del arreglo:";
				int size =0;
				int size2=0;
				string numero2;
				cin>>size;
				char* palabra =  new char[size];

				for(int i=0; i<size; i++) {
					cout<<" ingrese :";
					cin>>palabra[i];
					//cout<<palabra[i];
					//cout<<"\n";


					if((int)palabra[i]>=48&&(int)palabra[i]<=57) {
						numero2 += palabra[i];

					} else {
						size2+= atoi(numero2.c_str());
						numero2="";
					}

				}
				cout<<size2<<"\n";
				char* descomprimido = new char[size2];
				for(int i =0; i<size2; i++) {
					descomprimido[i]=0;
				}

				ejercicio1(size,palabra,descomprimido,size2);
				for(int i =0; i<size2; i++) {
					cout<<descomprimido[i]<<",";
				}
				//ejercicio1(size,palabra,descomprimido);

				delete[] palabra;
				delete[] descomprimido;

				break;
			}
			case 2: {
				int columnas = 0;
				int filas =  0;
				int k = 0;
				cout<<"Ingrese columnas:";
				cin>>columnas;
				cout<<"ingrese filas:";
				cin>>filas;
				cout<<"ingrese numero de obstaculos:";
				cin>>k;
				char ** ma=ejercicio2( filas, columnas, k);
				for( int i =0; i<columnas; i++) {
					if(ma[i]) {
						delete[]ma[i];
						ma[i]=0;
					}
				}

				if(ma) {
					delete[] ma;
					ma=0;
				}

				break;
			}
			case 3: {
				//===================================================================
				cout<<"ingresa tamanio del arreglo:";
				int size =0;
				int size2=0;
				string numero2;
				cin>>size;
				char* palabra =  new char[size];

				for(int i=0; i<size; i++) {
					cout<<" ingrese instruccion :";
					cin>>palabra[i];


					if((int)palabra[i]>=48&&(int)palabra[i]<=57) {
						numero2 += palabra[i];

					} else {
						size2+= atoi(numero2.c_str());
						numero2="";
					}

				}
				cout<<size2<<"\n";
				char* descomprimido = new char[size2];
				for(int i =0; i<size2; i++) {
					descomprimido[i]=0;
				}

				ejercicio1(size,palabra,descomprimido,size2);
				cout<<"==================================\n";
				for(int i =0; i<size2; i++) {
					cout<<descomprimido[i]<<",";
				}
				cout<<"\n===================================\n";
				//======================================================================
				//================================================================
				int columnas = 0;
				int filas =  0;
				int k = 0;
				cout<<"Ingrese columnas:";
				cin>>columnas;
				cout<<"ingrese filas:";
				cin>>filas;
				cout<<"ingrese numero de obstaculos:";
				cin>>k;
				char ** matriz=ejercicio2( filas, columnas, k);
				//=================================================================
				cout<<"Ingrese la posicion en la fila inicial :";
				int pos  = 0;
				cin>>pos;
				cout<<"Ingrese la posicion en la columna inicial :";
				int pos2  = 0;
				cin>>pos2;
				ejercicio3(matriz,descomprimido,size2,filas,columnas,pos,pos2);
				//===================
				delete[] palabra;
				delete[] descomprimido;
				for( int i =0; i<columnas; i++) {
					if(matriz[i]) {
						delete[]matriz[i];
						matriz[i]=0;
					}
				}

				if(matriz) {
					delete[] matriz;
					matriz=0;
				}


				break;
			}//fin de case 3

		}//fin de switch
	}//fin de while
	return 0;
}//fin de main
int menu() {
	int opcion=0;


	while(opcion!=4) {
		cout<<"\n=============MENU==========\n1.Ejercicio 1\n2.Ejercicio 2\n3.Ejercicio 3\n4.Salir\nOpcion:";
		cin>>opcion;
		if(opcion<=4&&opcion>=1) {
			//return opcion;
			break;
		}

	}
	return opcion;


}
char* ejercicio1(int size,char* palabra,char* descomprimido,int size2) {
	//=================================================================

	//=================================================================
	//================================================================
	int cantidad = 0;
	string numero="";
	char carac;
	for(int i = 0; i<size; i++) {
		if((int)palabra[i]>=48&&(int)palabra[i]<=57) {
			numero += palabra[i];

		} else {

			carac  = palabra[i];
			//	cout<<"letra a imprimir:"<<carac<<"\n";
			cantidad= atoi(numero.c_str());
			//	cout<<"cantidad de veces a repetir"<<cantidad<<"\n";

			int k = 0;
			for(int j = 0 ; j<size2; j++) {

				if(descomprimido[j]==0) {
					//k=j;
					for(int g = j ; g<cantidad+j; g++) {

						descomprimido[g] =  carac;

					}
					break;
				}


			}
			numero="";
		}



	}
	return descomprimido;

}//fin de metodo ejercicio1
char** ejercicio2(int filas, int columnas,int k) {
	srand(time(NULL));
	char** matriz = 0;
	matriz =  new char*[columnas];
	//segunfo paso
	for( int i =0; i<columnas; i++) {
		matriz[i] = new char[filas];
	}

	for(int i = 0; i<filas; i++) {
		for(int j =0; j<columnas; j++) {
			matriz[i][j] = '-';

		}
	}
	for(int i = 0; i<k; i++) {

		int filaA=rand()%+(filas);
		int columnaA=rand()%+(columnas);
		//	cout<<"filaA: "<<filaA<<" columnaA:"<<columnaA<<"\n";
		matriz[filaA][columnaA] ='#';

	}
	for(int i = 0; i<filas; i++) {
		for(int j =0; j<columnas; j++) {
			cout<<matriz[i][j];

		}
		cout<<"\n";
	}
	return matriz;
}
void imprimir(char** matriz, int filas,int columnas) {
	for(int i = 0 ; i< filas; i++) {
		for(int j =0 ; j<columnas; j++) {
			cout<<matriz[i][j];
		}
		cout<<"\n";
	}
}
void ejercicio3(char** matriz,char* descomprimida,int size2,int filas, int columnas, int pos,int pos2) {
	for(int i = 0 ; i< size2; i++) {
		switch(descomprimida[i]) {
			case 'U': {
				if(matriz[pos-1][pos2]!='#') {
					pos= pos-1;
					matriz[pos][pos2] =  (char)186;
				} else {
					//continue;
				}
				break;
			}
			case 'D': {

				if(matriz[pos+1][pos2]!='#') {
					pos= pos+1;
					matriz[pos][pos2] =  (char)186;
				} else {
					//continue;
				}
				break;
			}
			case 'R': {
				if(matriz[pos][pos2+1]!='#') {
					pos2= pos2+1;
					matriz[pos][pos2] =  (char)205;
				} else {
					//	continue;
				}
				break;
			}
			case 'L': {

				if(matriz[pos][pos2-1]!='#') {
					pos2= pos2-1;
					matriz[pos][pos2] =  (char)205;
				} else {
					//	continue;
				}
				break;
			}



		}
		system("pause");
		system("cls");
		imprimir(matriz,filas,columnas);

	}

}


















