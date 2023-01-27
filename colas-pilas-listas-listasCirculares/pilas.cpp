/************************************************************************************************
taller numero 4 estructura de datos
univercidad tecnologica de pereira 07/03/2022
brayan chiquito
    objetivo:       1. Invertir los elementos de una pila.
                    2. Informar si el elemento X se encuentra presente en la pila P.
                    3. Hacer una función boolean que indique si una pila se encuentra ordenada
                    ascendentemente.
                    4. Indicar si las pilas P1 y P2 son iguales (tienen los mismos elementos y en el
                    mismo orden).
                    5. Hacer una función que reciba una pila de objetos y saque de la pila el objeto
                    X (si existe) y deje la pila con los objetos restantes en el mismo orden.
                    Ayuda: utilice
                    otra pila.
                    6. Agrega el elemento X en la posición pos de la pila P, desplazando todos los
                    elementos una posición. Solo puede usar los métodos de la clase Pila. Ayuda:
                    Utilice otra pila.
                    7. Recibe una pila P, un elemento X y dos pilas vacías P1 y P2, y deja en
                    la pila P1 los elementos de P mayores que X y en P2 los otros.
************************************************************************************************/
#include <stdlib.h>
#include <iostream>
using namespace std;
/************************************************************************************************

************************************************************************************************/
/************************************************************************************************
estructura
************************************************************************************************/
struct nodo{
    int nro;
    struct nodo *sgte;
};
typedef nodo *ptrPila;
/************************************************************************************************
funcion apilar pila
    objetivo:       agregar un nuevo dato a la pila creando un nuevo espacio cada vez
    funcion:        push(ptrPila &p,int valor)
    ejemplo:        ingresar dato -> 1

    resultado:      pila
                    1
************************************************************************************************/
void push(ptrPila &p,int valor){
    ptrPila aux;
    aux = new(struct nodo);
    aux->nro=valor;
    aux->sgte=p;
    p=aux;
}
/************************************************************************************************
funcion desapilar pila
    objetivo:       eliminar o sacar un dato de la pila
    funcion:        int pop(ptrPila &p)
    ejemplo:        ingresar en menu sacar pila

    resultado:      numero desapilado
                    1
************************************************************************************************/
int pop(ptrPila &p){
    int num;
    ptrPila aux;
    aux=p;
    num=aux->nro;

    p=aux->sgte;
    delete(aux);
    return num;
}
/************************************************************************************************
funcion mostrar pila
    objetivo:       mostrar pila
    funcion:        mostrar_pila(ptrPila p)
    ejemplo:        ingresar en menu mostar pila

    resultado:      pila
                    1
************************************************************************************************/
void  mostrar_pila(ptrPila p){
    ptrPila aux;
    aux = p;
    while(aux != NULL){
        cout<<"\t"<<aux->nro<<endl;
        aux=aux->sgte;
    }
}
/************************************************************************************************
funcion destruit pila
    objetivo:       destruir una pila completa
    funcion:        destruir_pila(ptrPila &p)
    ejemplo:        ingresar en menu mostar pila

    resultado:      pila eliminada
************************************************************************************************/
void destruir_pila(ptrPila &p){
    ptrPila aux;
    while(p != NULL){
        aux = p;
        p = aux->sgte;
        delete(aux);
    }
}
/************************************************************************************************
funcion invertir pila
    objetivo:       Invertir los elementos de una pila.
    funcion:        Invertir_Pila(ptrPila &p)
    ejemplo:        pila
                            4
                            3
                            2
                            1
    resultado:      pila
                            1
                            2
                            3

************************************************************************************************/
void Invertir_Pila(ptrPila &p){
    ptrPila Paux = NULL;
    while(p!=NULL){
        push(Paux,pop(p));
    }
    p=Paux;
}
/************************************************************************************************
funcion buscar pila
    objetivo:       Informar si el elemento X se encuentra presente en la pila P.
    funcion:        buscar_pila(ptrPila p, int dato)
    ejemplo:        pila
                            4
                            3
                            2
                            1
                    numero a buscar -> 3
    resultado:    "dato encontrado"
************************************************************************************************/
bool buscar_pila(ptrPila p, int dato){
    ptrPila aux;
    aux=p;
    while(aux!=NULL){
        if(aux->nro==dato){
            return true;
        }
        aux=aux->sgte;
    }
    return false;
}
/************************************************************************************************
funcion saber orden de pila
    objetivo:       Hacer una función boolean que indique si una pila se encuentra ordenada
                    ascendentemente.
    funcion:        saber_orden(ptrPila p1,int n)
    ejemplo:        pila
                            4
                            3
                            2
                            1
    resultado:      esta ordenado de forma acendente
************************************************************************************************/
bool saber_orden(ptrPila p1,int n){
    ptrPila aux = NULL;
    ptrPila aux2 = NULL;
    int conta=0,mayor=9999;
    aux=p1;
    aux2=p1;
    while(aux!=NULL){
            if(aux->nro<mayor){
                    mayor=aux->nro;
                    conta++;
            }
            aux=aux->sgte;
    }
    if(conta==n){
        return true;
    }
    else{
        return false;
    }
}

/************************************************************************************************
 funcion comparar pilas
    objetivo:       Indicar si las pilas P1 y P2 son iguales (tienen los mismos elementos y en el
                    mismo orden).
    funcion:        comparar_pila(ptrPila p1,ptrPila p2, int &conta)
    ejemplo:        pila            pila
                            4           4
                            3           3
                            2           2
                            1           1
    resultado:    "las pilas son iguales y con el mismo orden"
************************************************************************************************/
void comparar_pila(ptrPila p1,ptrPila p2, int &conta){
    ptrPila aux1;
    ptrPila aux2;
    aux1=p1;
    aux2=p2;
    while(aux1!=NULL){
        if(aux1->nro==aux2->nro){
           conta++;
        }
        aux1=aux1->sgte;
        aux2=aux2->sgte;
    }
}
/************************************************************************************************
funcion eliminar numero en pila
    objetivo:       Hacer una función que reciba una pila de objetos y saque de la pila el objeto
                    X (si existe) y deje la pila con los objetos restantes en el mismo orden.
                    Ayuda: utilice
                    otra pila..
    funcion:        eliminar_numero(ptrPila &p1,int num)
    ejemplo:        pila
                            4
                            3
                            2
                            1
                    numero a eliminar -> 3
    resultado:      pila
                            4
                            2
                            1
************************************************************************************************/
void eliminar_numero(ptrPila &p1,int num){
    ptrPila Paux=NULL;
    while(p1!=NULL){
            if(p1->nro!=num){
                push(Paux,pop(p1));
            }
            else{
                int num2;
                ptrPila aux;
                aux=p1;
                num2=aux->nro;
                p1=aux->sgte;
                delete(aux);
            }
    }
    p1=Paux;
}

/************************************************************************************************
funcion agregar numero a la pila
    objetivo:       Agrega el elemento X en la posición pos de la pila P, desplazando todos los
                    elementos una posición. Solo puede usar los métodos de la clase Pila. Ayuda:
                    Utilice otra pila.
    funcion:        agregar_elemento(ptrPila &p1,int num, int num2)
    ejemplo:        pila
                            4
                            2
                            1
                    numero a agregar -> 3
                    posicion -> 3
    resultado:      pila
                            4
                            3
                            2
                            1
************************************************************************************************/
void agregar_elemento(ptrPila &p1,int num, int num2){
    ptrPila Paux=NULL;
    int i=0;
    while(p1!=NULL){
        if(i==num2){
            push(Paux,num);
        }
        else{
           push(Paux,pop(p1));
        }
        i++;
    }
    p1=Paux;
}
/************************************************************************************************
funcion separan pila en mayor y menos
    objetivo:       Recibe una pila P, un elemento X y dos pilas vacías P1 y P2, y deja en
                    la pila P1 los elementos de P mayores que X y en P2 los otros.
    funcion:        mayor_menor(ptrPila &p1,ptrPila &p2,ptrPila &p3,int num)
    ejemplo:        pila
                            5
                            4
                            3
                            2
                            1
                    numero -> 3
    resultado:      pila 1          pila 2
                            3               5
                            2               4
                            1
************************************************************************************************/
void mayor_menor(ptrPila &p1,ptrPila &p2,ptrPila &p3,int num){
    int i=0;
    while(p1!=NULL){
        if(p1->nro>num){
            push(p2,pop(p1));
        }
        else{
            push(p3,pop(p1));
        }
    }
}
/************************************************************************************************
 menu
************************************************************************************************/
void menu(){
    cout<<"\n\t IMPLEMENTACION DE PILAS EN C++\n\n";
    cout<<" 1. APILLAR                               "<<endl;
    cout<<" 2. DESAPILAR                             "<<endl;
    cout<<" 3. ORDEN DE LA PILA                      "<<endl;
    cout<<" 4. MOTRAR PILA                           "<<endl;
    cout<<" 5. DESTRUIR PILA                         "<<endl;
    cout<<" 6. INVERTIR PILA                         "<<endl;
    cout<<" 7. BUSCAR DATO                           "<<endl;
    cout<<" 8. COMPARAR DOS PILAS                    "<<endl;
    cout<<" 9. REMOVER UN ELEMENTO                   "<<endl;
    cout<<" 10. AGREGAR UN ELEMENTO                   "<<endl;
    cout<<" 11. MAYORES Y MENORES                     "<<endl;
    cout<<" 12. SALIR                                "<<endl;
    cout<<"\n INGRESE OPCION: ";
}
/************************************************************************************************
 funcion principal
************************************************************************************************/
int main(){
    ptrPila p = NULL; //creando pilka
    int dato;
    int op;
    bool bande=false;
    int x;  //numero que devuelve la funcion pop
    system("color 0b");
    do{
        menu(); cin>>op;
        switch(op){
            case 1:
                cout<<"\n NUMERO A APILAR: "; cin>>dato;
                push(p,dato);
                cout<<"\n\n\t\tNumero "<<dato<<" apilado...\n\n";
            break;
            case 2:
                x= pop( p );
                cout<<"\n\n\t\tNumero "<<x<<" desapilando...\n\n";
            break;
            case 3:
                {
                    ptrPila p1 = NULL;
                    int op1,n,dato1,i,num;
                    bool bande=false;
                    cout<<"\n CANTIDAD DE NUMEROS PARA PILA: "; cin>>n;
                    i=0;
                    while(i<n){
                            system("cls");
                        cout<<"\n PILA 1 NUMERO "<<i+1<<endl;
                        cout<<"\n NUMERO A APILAR: "; cin>>dato1;
                        push(p1,dato1);
                        i++;
                    }
                    mostrar_pila(p1);
                    bande=saber_orden(p1,n);
                    if(bande==true){
                        cout<<"\n\n\t\testa ordenado de forma acendente\n\n";
                    }
                    else{
                        cout<<"\n\n\t\tno esta ordenado de forma acendente\n\n";
                    }
                }
            break;
            case 4:
                cout<<"\n\n MOSTRAR PILA\n\n";
                if(p!=NULL)
                    mostrar_pila(p);
                else
                    cout<<"\n\n\tPila vacia..!"<<endl;
            break;
            case 5:
                destruir_pila(p);
                cout<<"\n\n\t\tPila eliminada...\n\n";
            break;
            case 6:
                Invertir_Pila(p);
                mostrar_pila(p);
            break;
            case 7:
                cout<<"\n NUMERO A BUSCAR: "; cin>>dato;
                bande=buscar_pila(p,dato);
                if(bande==true){
                    cout<<"\n\n\t\tdato encontrado "<<dato<<"\n\n";
                }
                else{
                    cout<<"\n\n\t\tdato no encontrado\n\n";
                }

            break;
            case 8:
                {
                    ptrPila p1 = NULL;
                    ptrPila p2 = NULL;
                    int op1,canti,n,i,dato1,n2,conta=0;
                    cout<<"\n CANTIDAD DE NUMEROS PARA PILA 1: "; cin>>n;
                    i=0;
                    while(i<n){
                            system("cls");
                        cout<<"\n PILA 1 NUMERO "<<i+1<<endl;
                        cout<<"\n NUMERO A APILAR: "; cin>>dato1;
                        push(p1,dato1);
                        i++;
                    }
                    cout<<"\n CANTIDAD DE NUMEROS PARA PILA 2: "; cin>>n2;
                    i=0;
                    while(i<n2){
                            system("cls");
                        cout<<"\n PILA 2 NUMERO "<<i+1<<endl;
                        cout<<"\n NUMERO A APILAR: "; cin>>dato1;
                        push(p2,dato1);
                        i++;
                    }
                    if(n==n2){
                        comparar_pila(p1,p2,conta);
                        if(conta==n){
                           cout<<"\n\n\t\tlas pilas son iguales y con el mismo orden\n\n";
                        }
                        else{
                            cout<<"\n\n\t\tlas pilas no son iguales\n\n";
                        }
                    }
                    else{
                        cout<<"\n\n\t\tlas pilas no son iguales\n\n";
                    }
                    cout<<"\n\n MOSTRAR PILA 1\n\n";
                    mostrar_pila(p1);
                    cout<<"\n\n MOSTRAR PILA 2\n\n";
                    mostrar_pila(p2);
                }
            break;
            case 9:
                {
                    ptrPila p1 = NULL;
                    int op1,n,dato1,i,num;
                    cout<<"\n CANTIDAD DE NUMEROS PARA PILA: "; cin>>n;
                    i=0;
                    while(i<n){
                            system("cls");
                        cout<<"\n PILA 1 NUMERO "<<i+1<<endl;
                        cout<<"\n NUMERO A APILAR: "; cin>>dato1;
                        push(p1,dato1);
                        i++;
                    }
                    mostrar_pila(p1);
                    cout<<"\n NUMERO A ELIMINAR: "; cin>>num;
                    eliminar_numero(p1,num);
                    Invertir_Pila(p1);
                    mostrar_pila(p1);
                }
            break;
            case 10:
                {
                    ptrPila p1 = NULL;
                    int op1,n,dato1,i,num,num2;
                    cout<<"\n CANTIDAD DE NUMEROS PARA PILA: "; cin>>n;
                    i=0;
                    while(i<n){
                            system("cls");
                        cout<<"\n PILA 1 NUMERO "<<i+1<<endl;
                        cout<<"\n NUMERO A APILAR: "; cin>>dato1;
                        push(p1,dato1);
                        i++;
                    }
                    cout<<"\n NUMERO A AGREGAR: "; cin>>num;
                    cout<<"\n POSICION: "; cin>>num2;
                    cout<<"\n\n PILA \n\n";
                    mostrar_pila(p1);
                    agregar_elemento(p1,num,num2);
                    Invertir_Pila(p1);
                    cout<<"\n\n PILA \n\n";
                    mostrar_pila(p1);
                }
            break;
            case 11:
                {
                    ptrPila p1 = NULL;
                    ptrPila p2 = NULL;
                    ptrPila p3 = NULL;
                    int op1,n,dato1,i,num;
                    cout<<"\n CANTIDAD DE NUMEROS PARA PILA: "; cin>>n;
                    i=0;
                    while(i<n){
                            system("cls");
                        cout<<"\n PILA 1 NUMERO "<<i+1<<endl;
                        cout<<"\n NUMERO A APILAR: "; cin>>dato1;
                        push(p1,dato1);
                        i++;
                    }
                    cout<<"\n NUMERO: "; cin>>num;
                    cout<<"\n\n PILA 1\n\n";
                    mostrar_pila(p1);
                    mayor_menor(p1,p2,p3,num);
                    cout<<"\n\n PILA 2\n\n";
                    Invertir_Pila(p2);
                    mostrar_pila(p2);
                    cout<<"\n\n PILA 3\n\n";
                    Invertir_Pila(p3);
                    mostrar_pila(p3);
                }
            break;
        }
        cout<<endl<<endl;
        system("pause"); system("cls");
    }while(op!=12);
    return 0;
}

