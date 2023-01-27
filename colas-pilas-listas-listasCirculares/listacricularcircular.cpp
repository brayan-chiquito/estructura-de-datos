/************************************************************************************************
taller numero 4 estructura de datos
univercidad tecnologica de pereira 07/04/2022
brayan chiquito
    objetivo:       El problema de Flavio Josefo es un problema teórico que se encuentra en
                    matemática y ciencias de la computación. El nombre hace referencia a Flavio
                    Josefo, un historiador judío que vivió en el siglo I. Según lo que cuenta
                    Josefo, él y 40 soldados camaradas se encontraban atrapados en una cueva,
                    rodeados de romanos. Prefirieron suicidarse antes que ser capturados y
                    decidieron que echarían a suertes quién mataba a quién. Los últimos que
                    quedaron fueron él y otro hombre. Entonces convenció al otro hombre que
                    debían entregarse a los romanos en lugar de matarse entre ellos. Josefo
                    atribuyó su supervivencia a la suerte o a la Providencia.
************************************************************************************************/
#include <iostream>
#include <stdlib.h>
#include<time.h>
using namespace std;
/***********************************************************************************************
estructura nodo
***********************************************************************************************/
struct nodo{
    int nro;
    struct nodo *sgte;
};
/***********************************************************************************************
estructura cola circular
***********************************************************************************************/
struct colacircular{
    nodo *delante;
    nodo *atras;
};
/***********************************************************************************************
funcion eliminar dato
    objetivo:       eliminar un dato cada cierta cantidad de veces indicada por el numero
                    generado aleatoriamente.
    funcion:        eliminarElemento(struct colacircular &q,int &n,int num)
                    al se una cola circular se recorre eliminado el dato en la posocion del contador
                    si el numero es el rpimero de la cola se le asigna tambien al puntero de atras
                    para no danar la cola
    ejemplo:        1 2 3 4 num:2

    resultado:      1 4
***********************************************************************************************/
void eliminarElemento(struct colacircular &q,int &n,int num){
    struct nodo *aux,*ant;          //aux tipo colacurcular
    int i=1,a;
    aux=q.delante;              //aux asignado de cola
    while(n>2){
        if(i==num){
            if(aux==q.delante){     // si el dato es el primero se le asiga tambien el atras
                q.delante=q.delante->sgte;
                q.atras=q.delante;
            }
            else{
                ant->sgte=aux->sgte;    //anterios siguente apunta se conecta con el siguiente del eliminado
            }
            delete(aux);            //eliminar
            n--;                //disminuir n cantidad de datos
            i=0;
        }
        i++;
        ant=aux;            //gaurdar anterior
        aux=aux->sgte;
    }
}
/***********************************************************************************************
funcion encolar
    objetivo:       encolar un dato
    funcion:        (struct colacircular &q,int valor) agregar dato

    ejemplo:        1 2 3 4

    resultado:      1 2 3 4
***********************************************************************************************/
void encolar(struct colacircular &q,int valor){
    struct nodo *aux = new(struct nodo);
    aux->nro = valor;
    aux->sgte = q.delante;
    if(q.delante==NULL)
        q.delante = aux;
    else
        (q.atras)->sgte = aux;
    q.atras = aux;
}
/***********************************************************************************************
funcion mostrar
    objetivo:       mostra los datos
    funcion:        (struct colacircular &q,int valor) mostrar dato

    ejemplo:        q1

    resultado:      dat1 dat2 dat3.......
***********************************************************************************************/
void muestraCola(struct colacircular q,int n){
    struct nodo *aux;
    int i,a;
    aux = q.delante;
    i=0;
    a=0;
    while(i<1){
        cout<<"  "<<aux->nro;
        aux = aux->sgte;
        a++;
        if(a==n){
                cout<<endl;
            i++;
            a=0;
        }
    }
}
/***********************************************************************************************
funcion principal
***********************************************************************************************/
int main(){
    struct colacircular q1;
    q1.delante = NULL;
    q1.atras = NULL;
    int n,dato1,i,num;
    bool bande;
    cout<<"\n CANTIDAD DE NUMEROS PARA COLA: "; cin>>n;
    i=0;
    srand (time(NULL));
    while(i<n){
        system("cls");
        dato1=1+rand()%40;
        encolar(q1,dato1);
        i++;
    }
    cout<<"Numeros.\n";
    muestraCola(q1,n);
    cout<<endl;
    num=1+rand()%9;
    cout<<"Numero aleatoria del 1-9 para eliminar: "<<num<<endl<<endl;;
    eliminarElemento(q1,n,num);
    cout<<"Dos numeros restantes de la eliminacion.\n";
    muestraCola(q1,n);
    return 0;
}
