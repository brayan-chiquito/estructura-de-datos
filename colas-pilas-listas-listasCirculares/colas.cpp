
/************************************************************************************************
taller numero 4 estructura de datos
univercidad tecnologica de pereira 07/03/2022
brayan chiquito
    objetivo:       1. Invertir los elementos de una cola.
                    2. Informar si el elemento X se encuentra presente en la cola C.
                    3. Hacer una función boolean que indique si una cola se encuentra ordenada
                       ascendentemente.
                    4. Indicar si las colas C1 y C2 son iguales (tienen los mismos elementos y en el
                       mismo orden).
                    5. Agrega el elemento X en la posición pos de la cola C, desplazando todos los
                       elementos una posición. Solo puede usar los métodos de la clase Cola. Ayuda:
                       Utilice otra cola.
                    6. Recibe una cola C, un elemento X y dos colas vacías C1 y C2, y deja en la cola
                       C1 los elementos de C mayores que X y en C2 los otros.
************************************************************************************************/
#include <iostream>
#include <stdlib.h>
using namespace std;
/***********************************************************************************************
estructura
***********************************************************************************************/
struct nodo{
    int nro;
    struct nodo *sgte;
};

typedef nodo *ptrPila;
/***********************************************************************************************
estrucutura cola
***********************************************************************************************/
struct cola{
    nodo *delante;
    nodo *atras;
};
/***********************************************************************************************
funcion push para pila
***********************************************************************************************/
void push(ptrPila &p,int valor){
    ptrPila aux;
    aux = new(struct nodo);
    aux->nro=valor;
    aux->sgte=p;
    p=aux;
}
/***********************************************************************************************
funcion pop para pila
***********************************************************************************************/
int pop(ptrPila &p){
    int num;
    ptrPila aux;
    aux=p;
    num=aux->nro;

    p=aux->sgte;
    delete(aux);
    return num;
}
/***********************************************************************************************
funcion encolar
***********************************************************************************************/
void encolar(struct cola &q,int valor){
    struct nodo *aux = new(struct nodo);
    aux->nro = valor;
    aux->sgte = NULL;
    if(q.delante==NULL)
        q.delante = aux;
    else
        (q.atras)->sgte = aux;
    q.atras = aux;
}
/***********************************************************************************************
funcion desencolar
***********************************************************************************************/
int desencolar(struct cola &q){
    int num;
    struct nodo *aux;
    aux = q.delante;
    num = aux->nro;
    q.delante = (q.delante)->sgte;
    delete(aux);
    return num;
}
/***********************************************************************************************
funcion mostrar cola
***********************************************************************************************/
void muestraCola(struct cola q){
    struct nodo *aux;
    aux = q.delante;
    while(aux != NULL){
        cout<<"  "<<aux->nro;
        aux = aux->sgte;
    }
}
/***********************************************************************************************
funcion vaciar cola
***********************************************************************************************/
void vaciarCola(struct cola &q){
    struct nodo *aux;
    while(q.delante != NULL){
        aux = q.delante;
        q.delante = aux->sgte;
        delete(aux);
    }
    q.delante=NULL;
    q.atras=NULL;
}
/***********************************************************************************************
funcion invertir cola
    objetivo:       Invertir los elementos de una cola
    funcion:        invertirCola(struct cola &q), por medio de una pila se desencola y vuelve
                    a encolar para inverstir los datos
    ejemplo:        ingresar dato -> 1 2 3 4

    resultado:      cola 4 3 2 1
***********************************************************************************************/
void invertirCola(struct cola &q){
    ptrPila p = NULL;           //se crea una plia
    int num;
    while(q.delante!=NULL){
        num=desencolar(q);      //se desencola
        push(p,num);            //se enplia el dato desencolado
    }
    while(p!=NULL){
        num=pop(p);             //se desmplia
        encolar(q,num);         //se encola el dato desemplilado
    }
}
/***********************************************************************************************
funcion encontrar dato
    objetivo:       Informar si el elemento X se encuentra presente en la cola C.
    funcion:        enconraDato(struct cola q,int num) se recorre una cola y en caso de que se
                    encuentre el dato ingresado retorna un true de no ser asi se retorna false
    ejemplo:        ingresar dato -> 1 2 3 4
                    numero a buscar -> 2

    resultado:      Numero 2 encontrado
***********************************************************************************************/
bool enconraDato(struct cola q,int num){
    struct nodo *aux;
    aux = q.delante;
    while(aux!=NULL){           //se recorre la cola por medio de un aux
        if(aux->nro==num){      //si se encuentra numero retornar true
            return true;
        }
        aux = aux->sgte;        //pasar al siguente dato
    }
    return false;               //en caos de no encontrar dato reorrnar false
}
/***********************************************************************************************
funcion orden de la cola
    objetivo:       Hacer una función boolean que indique si una cola se encuentra ordenada
                    ascendentemente.
    funcion:        ordenCola(struct cola q,int n) se recorre la cola preguntando si el dato
                    anterior es menor al siguiente
    ejemplo:        ingresar dato -> 1 2 3 4

    resultado:      Esta ordenada de forma acendente
***********************************************************************************************/
bool ordenCola(struct cola q,int n){
    struct nodo *aux;
    aux = q.delante;
    int mayor=0,conta=0;        //defina el dato que mayor que guarda el numero anterior y contador
    while(aux!=NULL){           //se recorre cola con aux
        if(aux->nro>mayor){
            mayor=aux->nro;     //se compara dato anterior con el siguente
            conta++;
        }
        aux = aux->sgte;
    }
    if(conta==n)
        return true;            //si se cumple retornar true
    else
        return false;           //si no se cumple retornar false
}
/***********************************************************************************************
funcion comparar colas
    objetivo:       Indicar si las colas C1 y C2 son iguales (tienen los mismos elementos y en el
                    mismo orden).
    funcion:        compararColas(struct cola q,struct cola q1,int n)se comparn si dos colas son
                    del mismo tamaño por medio del bucle while se compara dato por dato
    ejemplo:        ingresar dato 1 -> 1 2 3 4
                    ingresar dato 2 -> 1 2 3 4

    resultado:      Son iguales
***********************************************************************************************/
bool compararColas(struct cola q,struct cola q1,int n){
    struct nodo *aux;
    struct nodo *aux1;
    aux = q.delante;                //se asigan aux para cola 1
    aux1 = q1.delante;              //se asigana aux2 para la cola 2
    int conta=0;
    while(aux!=NULL){
        if(aux->nro==aux1->nro){         //se compara dato por dato
            conta++;                    //incrementa el contador
        }
        aux = aux->sgte;                //se asiga el siguiente dato
        aux1 = aux1->sgte;
    }
    if(conta==n){                   //en caso de contador ser igual a n se retorna true
        return true;
    }
    else{
        return false;
    }

}
/***********************************************************************************************
funcion agregar dato a la cola
    objetivo:       Agrega el elemento X en la posición pos de la cola C, desplazando todos los
                    elementos una posición. Solo puede usar los métodos de la clase Cola. Ayuda:
                    Utilice otra cola.
    funcion:        agregarDAtoCola(struct cola &q,int num1,int num2) por medio de otra cola se
                    desncola la principal en la segunda agregando el dato en la posicion dada
                    para volver a encolar la segunda cola en la principal
    ejemplo:        ingresar dato 1 -> 1 2 3 4
                    posicicon -> 2
                    numero -> 5

    resultado:      cola -> 1 2 5 3 4
***********************************************************************************************/
void agregarDAtoCola(struct cola &q,int num1,int num2){
    struct cola q1;                 //se genera nueva cola
    q1.delante = NULL;              //se asigan los datos a la nueva cola
    q1.atras = NULL;
    int i=0,dato;
    while(q.delante!=NULL){         //se recorre la cola principal
        if(i==num1){
            encolar(q1,num2);       //cuando se esta en al posicion querida se encola el dato
        }
            dato=desencolar(q);     //se desencola el dato de la principal
            encolar(q1,dato);       //se ecnola en al secundaria
        i++;
    }
    while(q1.delante!=NULL){
        dato=desencolar(q1);        //se desencola la secundaria
        encolar(q,dato);            //se ecnola la principal con el dato nuevo
    }
}
/***********************************************************************************************
funcion separa la cola entre mayor y menor
    objetivo:       Recibe una cola C, un elemento X y dos colas vacías C1 y C2, y deja en la cola
                    C1 los elementos de C mayores que X y en C2 los otros.
    funcion:        colaMayorMenor(struct cola q1,struct cola &q2,struct cola &q3,int num)
                    se recorre la principal y en caso de se menor o igual el dato se
                    envia a la segunda o tercera cola
    ejemplo:        ingresar dato 1 -> 1 2 3 4 5
                    numero -> 3

    resultado:      cola 2 -> 1 2 3
                    cola 3 -> 4 5
***********************************************************************************************/
void colaMayorMenor(struct cola q1,struct cola &q2,struct cola &q3,int num){
    struct nodo *aux;
    aux = q1.delante;           //se asiga aux para recorrer la cola prinncipal
    while(aux != NULL){
        if(aux->nro<=num){          //se compara para saber si es menor o igual
            encolar(q2,aux->nro);   //se encola en la segunda
        }
        else{
            encolar(q3,aux->nro);   //se encola en la tercera
        }
        aux = aux->sgte;            //siguiente dato
    }
}
/***********************************************************************************************
funcion menu
***********************************************************************************************/
void menu(){
    cout<<"\n\t IMPLEMENTACION DE COLAS EN C++\n\n";
    cout<<" 1. ENCOLAR                              "<<endl;
    cout<<" 2. DESENCOLAR                           "<<endl;
    cout<<" 3. MOSTRAR COLA                         "<<endl;
    cout<<" 4. VACIAR COLA                          "<<endl;
    cout<<" 5. INVERTIR DATOS                       "<<endl;
    cout<<" 6. ENCONTRAR DATO                       "<<endl;
    cout<<" 7. SABER ORDEN                          "<<endl;
    cout<<" 8. COMPARAR DOS COLAS                   "<<endl;
    cout<<" 9. INGRESAR DATO EN UNA POSICION        "<<endl;
    cout<<" 10.SEPARAR COLAS EN MAYORES Y MENORES   "<<endl;
    cout<<" 11.SALIR                                "<<endl;
    cout<<"\n INGRESE OPCION: ";
}
/***********************************************************************************************
funcion principal
***********************************************************************************************/
int main(){
    struct cola q;
    q.delante = NULL;
    q.atras = NULL;
    int dato;
    int op;
    int x;
    system("color 0b");
    do{
        menu();cin>>op;
        switch(op){
            case 1:
                cout<<"\n NUMERO A ENCOLAR: ";cin>>dato;
                encolar(q,dato);
                cout<<"\n\n\t\tNumero "<<dato<<" encolado\n\n";
            break;
            case 2:
                x=desencolar(q);
                cout<<"\n\n\t\tDato "<<x<<" desencolado\n\n";
            break;
            case 3:
                cout<<"\n\nMOSTRAR COLA\n\n";
                if(q.delante!=NULL)
                    muestraCola(q);
                else
                    cout<<"\n\n\t\tCola vacia\n\n";
                cout<<endl;
            break;
            case 4:
                vaciarCola(q);
                cout<<"\n\n\t\tVacia\n\n";
            break;
            case 5:
                cout<<"Cola"<<endl;
                muestraCola(q);
                cout<<endl;
                invertirCola(q);
                muestraCola(q);
                cout<<endl;
            break;
            case 6:
                {
                    struct cola q1;
                    q1.delante = NULL;
                    q1.atras = NULL;
                    int n,dato1,i,num;
                    bool bande;
                    cout<<"\n CANTIDAD DE NUMEROS PARA COLA: "; cin>>n;
                    i=0;
                    while(i<n){
                            system("cls");
                        cout<<"\n COLA 1 NUMERO "<<i+1<<endl;
                        cout<<"\n NUMERO A ENCOLAR: "; cin>>dato1;
                        encolar(q1,dato1);
                        i++;
                    }
                    system("cls");
                    cout<<"\n NUMERO A BUSCAR: "; cin>>num;
                    bande=enconraDato(q1,num);
                    if(bande==true)
                        cout<<"\n\n\t\tNumero "<<num<<" encontrado\n\n";
                    else
                        cout<<"\n\n\t\tNumero "<<num<<" no encontrado\n\n";
                }
            break;
            case 7:
                {
                   struct cola q1;
                    q1.delante = NULL;
                    q1.atras = NULL;
                    int n,dato1,i,num;
                    bool bande;
                    cout<<"\n CANTIDAD DE NUMEROS PARA COLA: "; cin>>n;
                    i=0;
                    while(i<n){
                            system("cls");
                        cout<<"\n COLA 1 NUMERO "<<i+1<<endl;
                        cout<<"\n NUMERO A ENCOLAR: "; cin>>dato1;
                        encolar(q1,dato1);
                        i++;
                    }
                    system("cls");
                    cout<<"\n\nMOSTRAR COLA\n\n";
                    if(q1.delante!=NULL)
                        muestraCola(q1);
                    else
                        cout<<"\n\n\t\tCola vacia\n\n";
                    cout<<endl;
                    bande=ordenCola(q1,n);
                    if(bande==true)
                        cout<<"\n\n\t\tEsta ordenada de forma acendente\n\n";
                    else
                        cout<<"\n\n\t\tNo esta ordenada de forma acendente\n\n";
                }
            break;
            case 8:
                {
                   struct cola q1;
                   struct cola q2;
                    q1.delante = NULL;
                    q1.atras = NULL;
                    q2.delante = NULL;
                    q2.atras = NULL;
                    int n,n1,dato1,i,num;
                    bool bande;
                    cout<<"\n CANTIDAD DE NUMEROS PARA COLA: "; cin>>n;
                    i=0;
                    while(i<n){
                            system("cls");
                        cout<<"\n COLA 1 NUMERO "<<i+1<<endl;
                        cout<<"\n NUMERO A ENCOLAR: "; cin>>dato1;
                        encolar(q1,dato1);
                        i++;
                    }
                    i=0;
                    cout<<"\n CANTIDAD DE NUMEROS PARA COLA: "; cin>>n1;
                    while(i<n1){
                            system("cls");
                        cout<<"\n COLA 2 NUMERO "<<i+1<<endl;
                        cout<<"\n NUMERO A ENCOLAR: "; cin>>dato1;
                        encolar(q2,dato1);
                        i++;
                    }
                    system("cls");
                    cout<<"\n\nMOSTRAR COLA 1\n\n";
                    if(q1.delante!=NULL)
                        muestraCola(q1);
                    else
                        cout<<"\n\n\t\tCola vacia\n\n";
                    cout<<endl;
                    cout<<"\n\nMOSTRAR COLA 2\n\n";
                    if(q2.delante!=NULL)
                        muestraCola(q2);
                    else
                        cout<<"\n\n\t\tCola vacia\n\n";
                    cout<<endl;
                    if(n==n1){
                        bande=compararColas(q1,q2,n);
                        if(bande==true){
                            cout<<"\n\n\t\tSon iguales\n\n";
                        }
                        else{
                            cout<<"\n\n\t\tNo son iguales\n\n";
                        }
                    }
                    else{
                        cout<<"\n\n\t\tNo son igaules \n\n";
                    }
                }
            break;
            case 9:
                {
                    struct cola q1;
                    q1.delante = NULL;
                    q1.atras = NULL;
                    int n,dato1,i,num1,num2;
                    bool bande;
                    cout<<"\n CANTIDAD DE NUMEROS PARA COLA: "; cin>>n;
                    i=0;
                    while(i<n){
                            system("cls");
                        cout<<"\n COLA  NUMERO "<<i+1<<endl;
                        cout<<"\n NUMERO A ENCOLAR: "; cin>>dato1;
                        encolar(q1,dato1);
                        i++;
                    }
                    system("cls");
                    cout<<"\n\nMOSTRAR COLA \n\n";
                    if(q1.delante!=NULL)
                        muestraCola(q1);
                    else
                        cout<<"\n\n\t\tCola vacia\n\n";
                    cout<<endl;
                    cout<<"\n POSICION EN LA QUE VA EL NUMERO: "; cin>>num1;
                    cout<<"\n NUMERO: "; cin>>num2;
                    agregarDAtoCola(q1,num1,num2);
                    cout<<"\n\nMOSTRAR COLA 1\n\n";
                    if(q1.delante!=NULL)
                        muestraCola(q1);
                    else
                        cout<<"\n\n\t\tCola vacia\n\n";
                    cout<<endl;
                }
            break;
            case 10:
                {
                   struct cola q1;
                   struct cola q2;
                   struct cola q3;
                    q1.delante = NULL;
                    q1.atras = NULL;
                    q2.delante = NULL;
                    q2.atras = NULL;
                    q3.delante = NULL;
                    q3.atras = NULL;
                    int n,n1,dato1,i,num;
                    bool bande;
                    cout<<"\n CANTIDAD DE NUMEROS PARA COLA: "; cin>>n;
                    i=0;
                    while(i<n){
                            system("cls");
                        cout<<"\n COLA 1 NUMERO "<<i+1<<endl;
                        cout<<"\n NUMERO A ENCOLAR: "; cin>>dato1;
                        encolar(q1,dato1);
                        i++;
                    }
                    system("cls");
                    cout<<"\n\nMOSTRAR COLA 1\n\n";
                    if(q1.delante!=NULL)
                        muestraCola(q1);
                    else
                        cout<<"\n\n\t\tCola vacia\n\n";
                    cout<<endl;
                    cout<<"\n NUMERO: "; cin>>num;
                    colaMayorMenor(q1,q2,q3,num);
                    cout<<"\n\nMOSTRAR COLA 2\n\n";
                    if(q2.delante!=NULL)
                        muestraCola(q2);
                    else
                        cout<<"\n\n\t\tCola vacia\n\n";
                    cout<<endl;
                    cout<<"\n\nMOSTRAR COLA 3\n\n";
                    if(q3.delante!=NULL)
                        muestraCola(q3);
                    else
                        cout<<"\n\n\t\tCola vacia\n\n";
                    cout<<endl;
                }
            break;
        }
        system("pause");system("cls");
    }while(op!=11);
}
