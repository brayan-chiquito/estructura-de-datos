/************************************************************************************************
taller numero 2 estructura de datos
univercidad tecnologica de pereira 27/02/2022
brayan chiquito
    objetivo: 1.Elaborar un Programa que permite ordenar el vector llamado “mivector”
                usando los métodos de ordenamiento
                de: Insercion Directa, Burbuja , Quicksort , Shellsort.
                El programa debe medir el tiempo en segundos que tarda cada método
                en realizar el ordenamiento del vector.
                los datos del vector estarán guardados en archivos, pruebe los diferentes
                métodos de ordenamiento con la siguiente cantidad de datos (n)
                (datos aleatorios entre 0 y 999)
************************************************************************************************/
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include <ctime>
using namespace std;
void OrdInsercion (long *a, int n,double &time);
void MostrarVector (long *Vector,int n);
void OrdBurbuja (long *a, int n,double &time);
void OrdenacionShell(long *a, int n,double &time);
void Quicksort(long *a, int primero, int ultimo);
void Llenar(long *Vector,int &n);
void LeerArchivo(long *Vector,long n);
unsigned t0,t1; //global para el tiempo
int Menu();
/************************************************************************************************
funcion principal
************************************************************************************************/
int main(){
    int opcion;
    double time;
    long n=1000000;
    long *Vector = new long[n]; // definicon del vector para usarlo de tamaño long
    for(;;){                    //bucle para menu de opciones
        opcion=Menu();
        switch(opcion){
            case 1:
                system("cls");
                cout<<"ingrese tamaño a ordenar: ";cin>>n;
                LeerArchivo(Vector,n);              //leer archivo de datos
                OrdInsercion(Vector,n,time);        //metodo de ordenamiento insercion retorna tiempo
                cout<<"time:"<<time<<endl;          //se muetras el tiempo que tardo
                getch();
            break;
            case 2:
                system("cls");
                cout<<"ingrese tamaño a ordenar: ";cin>>n;
                LeerArchivo(Vector,n);              //leer archivo de datos
                OrdBurbuja(Vector,n,time);          //metodo de ordenamiento burbuja retorna tiempo
                cout<<"time:"<<time<<endl;          //se muetras el tiempo que tardo
                getch();
            break;
            case 3:
                system("cls");
                cout<<"ingrese tamaño a ordenar: ";cin>>n;
                LeerArchivo(Vector,n);              //leer archivo de datos
                OrdenacionShell(Vector,n,time);     //metodo de ordenamiento shell retorna tiempo
                cout<<"time:"<<time<<endl;          //se muetras el tiempo que tardo
                getch();
            break;
            case 4:{
                system("cls");
                cout<<"ingrese tamaño a ordenar: ";cin>>n;
                LeerArchivo(Vector,n);              //leer archivo de datos
                t0=clock();                         //se inica timepo por fuera ya que es metodo recursivo
                Quicksort(Vector,0,n-1);            //metodo de ordenamiento quickshort retorna tiempo
                t1=clock();
                double time=(double(t1-t0)/CLOCKS_PER_SEC);
                cout<<"time:"<<time<<endl;          //se muetras el tiempo que tardo
            }
                getch();
            break;
            case 5:
                return 0;                           //cerrar programa
        }
    }
}
/************************************************************************************************
funcion menu
************************************************************************************************/
int Menu(){
    system("cls");
    int op;
    cout<<"1.metodo de ordenamiento por insercion.\n";
    cout<<"2.metodo de ordemaniento por burbuja.\n";
    cout<<"3.metodo de ordenamiento por shell.\n";
    cout<<"4.metodo de ordenamiento por quicksort.\n";
    cout<<"5.salir.\n";
    cout<<"ingrese una opcion (1-6):";cin>>op;      //ingresar opcion
    return op;
}
/************************************************************************************************
funcion de ordenamiento por metodo insercion
************************************************************************************************/
void OrdInsercion (long *a, int n,double &time)
{
    int i, j;
    int aux;
    t0=clock();
    for (i = 1; i < n; i++){
        /* índice j explora la sublista a[i-1]..a[0] buscando la
        posición correcta del elemento destino, lo asigna a a[j] */
        j = i;
        aux = *(a+i);
        // se localiza el punto de inserción explorando hacia abajo */
        while (j > 0 && aux < *(a+j-1))
        {
        // desplazar elementos hacia arriba para hacer espacio */
        *(a+j) = *(a+j-1);
        j--;
        }
        *(a+j) = aux;
    }
    t1=clock();
    time=(double(t1-t0)/CLOCKS_PER_SEC);

}
/************************************************************************************************
funcion de ordenamiento por metodo burbuja
************************************************************************************************/
void OrdBurbuja (long *a, int n,double &time){
    int interruptor = 1;
    int pasada, j;
    t0=clock();
    for (pasada = 0; pasada < n-1 && interruptor; pasada++){
        // bucle externo controla la cantidad de pasadas
        interruptor = 0;
        for (j = 0; j < n-pasada-1; j++)
            if (*(a+j) > *(a+j+1)){
            // elementos desordenados, es necesario intercambio
            long aux;
            interruptor = 1;
            aux = *(a+j);
            *(a+j) = *(a+j+1);
            *(a+j+1) = aux;
        }
    }
    t1=clock();
    time=(double(t1-t0)/CLOCKS_PER_SEC);
}
/************************************************************************************************
funcion de ordenamiento por metodo shell
************************************************************************************************/
void OrdenacionShell(long *a,int n,double &time){
    int intervalo, i, j, k;
    intervalo = n / 2;
    t0=clock();
    while (intervalo > 0){
           for (i = intervalo; i < n; i++){
                j=i- intervalo;
                while (j >= 0){
                    k=j+ intervalo;
                    if (*(a+j) <= *(a+k))
                    j = -1; // así termina el bucle, par ordenado
                else{
                double temp;
                temp = *(a+j);
                *(a+j) = *(a+k);
                *(a+k) = temp;
                j -= intervalo;
                }
            }
        }
    intervalo = intervalo / 2;
    }
    t1=clock();
    time=(double(t1-t0)/CLOCKS_PER_SEC);

}
/************************************************************************************************
funcion de ordenamiento por metodo quicksort
************************************************************************************************/
void Quicksort(long *a,int primero,int ultimo){
    int i, j, central;
    double pivote;
    central = (primero + ultimo)/2;
    pivote = *(a+central);
    i = primero;
    j = ultimo;
    do {
        while (*(a+i) < pivote) i++;
        while (*(a+j) > pivote) j--;
        if (i<=j){
            double tmp;
            tmp = *(a+i);
            *(a+i) = *(a+j);
            *(a+j) = tmp; // intercambia a[i] con a[j]
            i++;
            j--;
        }
    }while (i <= j);
    if (primero < j)
    Quicksort(a, primero, j);// mismo proceso con sublista izqda
    if (i < ultimo)
    Quicksort(a, i, ultimo); // mismo proceso con sublista drcha
}
/************************************************************************************************
funcion leer archivo
************************************************************************************************/
void LeerArchivo(long *Vector,long n){
	ifstream leer;
	char dato[20];
	leer.open ("datos.txt");
	if (leer.good())
	{
		cout<<"El archivo fue abierto correctamente..."<<endl;
        int i=0;
        while(!leer.eof()==-1||i<n){
            leer>>dato;
            *(Vector+i)=atol(dato);
            i++;
        }
        leer.close();
	}
	else
	{
		cout<<"El archivo no se pudo abrir..."<<endl;

	}
}
