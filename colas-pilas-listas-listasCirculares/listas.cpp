/************************************************************************************************
taller 6 estructura de datos
univercidad tecnologica de pereira 07/04/2022
brayan chiquito
    objetivo:       1. Dada una lista de elementos y un número P, devolver el número de veces que
                       está el valor de P en la lista.
                    2. Dada una lista, hacer una función que invierta sus datos en ella misma y la
                       devuelva invertida.
                    3. Hacer una función que reciba una lista y devuelva el promedio de los datos de la lista.
                    4. Hacer una función que reciba una lista y devuelva el mayor valor datos existentes.
                    5. Hacer una función que reciba una lista e indique si está ordenada
                       ascendentemente.
************************************************************************************************/

#include <iostream>
#include <stdlib.h>
using namespace std;
/***********************************************************************************************
estructura nodo lista
***********************************************************************************************/
struct nodo{
    int nro;
    struct nodo *sgte;
};
typedef struct nodo *Tlista;
/***********************************************************************************************
funcion incertar al inicio
***********************************************************************************************/
void insertarInicio(Tlista &lista,int valor){
    Tlista q;
    q=new(struct nodo);
    q->nro = valor;
    q->sgte=lista;
    lista = q;
}
/***********************************************************************************************
funcion mostrar lista
***********************************************************************************************/
void mostrarLista(Tlista lista){
    Tlista aux;
    aux=lista;
    while(aux!=NULL){
        cout<<aux->nro<<" ";
        aux=aux->sgte;
    }
    cout<<endl;
}
/***********************************************************************************************
funcion insetra al final
***********************************************************************************************/
void insertarFinal(Tlista &lista,int valor){
    Tlista t,q = new(struct nodo);
    q->nro = valor;
    q->sgte = NULL;
    if(lista==NULL){
        lista = q;
    }
    else{
        t=lista;
        while(t->sgte!=NULL){
            t=t->sgte;
        }
        t->sgte=q;
    }
}
/***********************************************************************************************
funcion insertar antes o despues
***********************************************************************************************/
int insertarAntesDespues(){
    int _op,band;
    cout<<endl;
    cout<<"\t 1. Antes de la posicion   "<<endl;
    cout<<"\t 2. Despues de la posicion "<<endl;
    cout<<"\n\t Opcion: ";cin>>_op;
    if(_op==1)
        band = -1;
    else
        band = 0;
    return band;
}
/***********************************************************************************************
funcion insertra elemento en posicion x
***********************************************************************************************/
void insertarElemento(Tlista &lista,int valor,int pos){
    Tlista q,t;
    int i;
    q=new(struct nodo);
    q->nro = valor;
    if(pos==1){
        q->sgte = lista;
        lista = q;
    }
    else{
        int x = insertarAntesDespues();
        t=lista;
        for(i=1;t!=NULL;i++){
            if(i==pos+x){
                q->sgte=t->sgte;
                t->sgte=q;
                return;
            }
            t=t->sgte;
        }
    }
    cout<<"Error...Posicion no encontrada...!"<<endl;
}
/***********************************************************************************************
funcion buscar elemento
***********************************************************************************************/
void buscarElemento(Tlista lista,int valor){
    Tlista q = lista;
    int i = 1, band = 0;
    while(q!=NULL){
        if(q->nro==valor){
            cout<<endl<<"Encontrado en posicion "<<i<<endl;
            band = 1;
        }
        q = q->sgte;
        i++;
    }
    if(band==0)
        cout<<"\n\nNumero no encontrado..!"<<endl;
}
/***********************************************************************************************
funcion eliminar elemento
***********************************************************************************************/
void eliminarElemento(Tlista &lista,int valor){
    Tlista p, ant;
    p=lista;
    if(lista!=NULL){
        while(p!=NULL){
            if(p->nro==valor){
                if(p==lista)
                    lista==lista->sgte;
                else
                    ant->sgte=p->sgte;
                delete(p);
                return;
            }
            ant = p;
            p = p->sgte;
        }
    }
    else{
        cout<<" Lista vacia..!";
    }
}
/***********************************************************************************************
funcion eliminar repetidos
***********************************************************************************************/
void eliminarRepetidos(Tlista &lista,int valor){
    Tlista q,ant;
    q=lista;
    ant = lista;
    while(q!=NULL){
        if(q->nro==valor){
            if(q==lista){
                lista = lista->sgte;
                delete(q);
                q=lista;
            }
            else{
                ant->sgte=q->sgte;
                delete(q);
                q=ant->sgte;
            }
        }
        else{
                ant = q;
        q = q->sgte;
        }
    }
    cout<<"\n\n Valor eliminado..!"<<endl;
}
/***********************************************************************************************
funcion contar repetido
    objetivo:       Dada una lista de elementos y un número P, devolver el número de veces que
                    está el valor de P en la lista.
    funcion:        eliminarRepetidos(Tlista &lista,int valor)
                    se recorre la lista buscando cuantas veces se encuentra el elemnto
    ejemplo:        lista(1,2,3,4,3).
                    numero: 3

    resultado:      El numero se repite 2 veces
***********************************************************************************************/
int contarDato(Tlista &lista,int valor){
    Tlista aux;
    aux=lista;
    int conta=0;
    while(aux!=NULL){
        if(aux->nro==valor){
            conta++;
        }
        aux=aux->sgte;
    }
    return conta;
}
/***********************************************************************************************
funcion invertir lista
    objetivo:       Dada una lista, hacer una función que invierta sus datos en ella misma y la
                    devuelva invertida.
    funcion:        invertirDatos(Tlista &lista) por medio de varios apuntadores se cambia la
                    direecion de donde apuntna para si invertirlos
    ejemplo:        lista(1,2,3,4,5)

    resultado:      lista(5,4,3,2,1)
***********************************************************************************************/

void invertirDatos(Tlista &lista){
    Tlista aux_actu=lista;          //apuntador actual
    Tlista aux_ante=NULL;           //apuntado anterior
    Tlista aux_sig=aux_actu ? aux_actu->sgte:NULL;  //apuntador siguiente
    while(aux_actu){
        aux_actu->sgte = aux_ante;
        aux_ante=aux_actu;
        aux_actu=aux_sig;
        aux_sig=aux_actu ? aux_actu->sgte:NULL;
    }
    lista=aux_ante;
}
/***********************************************************************************************
funcion promedio de numeros
    objetivo:       Hacer una función que reciba una lista y devuelva el promedio de los datos
                    de la lista.
    funcion:        promedioDatos(Tlista lista) recorrer la lista sumando los numeros que
                    contiene para luego sacar promedio
    ejemplo:        lista(1,2,3,4,5).

    resultado:      El promedio es: 3
***********************************************************************************************/
int promedioDatos(Tlista lista){
    Tlista aux=lista;
    int total=0,promedio=0,conta=0;
    while(aux!=NULL){
        total=total+aux->nro;
        conta++;
        aux=aux->sgte;
    }
    promedio=total/conta;
    return promedio;
}
/***********************************************************************************************
funcion dato mayor
    objetivo:       Hacer una función que reciba una lista y devuelva el mayor valor datos existentes.
    funcion:        datoMayor(Tlista lista) recorrer la lista buscando el dato mayor
    ejemplo:        lista(1,2,3,4,5)

    resultado:      El dato mayor es: 5
***********************************************************************************************/
int datoMayor(Tlista lista){
    Tlista aux=lista;
    int mayor=0;
    while(aux!=NULL){
        if(aux->nro>mayor){
            mayor=aux->nro;
        }
        aux=aux->sgte;
    }
    return mayor;
}
/***********************************************************************************************
funcion dato mayor
    objetivo:       Hacer una función que reciba una lista e indique si está ordenada
                    ascendentemente.
    funcion:        ordenLista(Tlista lista) recorrer la lista mirando si el dato siguinet
                    es mayor al anterior
    ejemplo:        lista(1,2,3,4,5)

    resultado:      Esta ordenada de forma acendente
***********************************************************************************************/
bool ordenLista(Tlista lista){
    Tlista aux=lista;
    bool bande;
    int conta1=0,conta2=0,mayor=9999;
    while(aux!=NULL){
        if(aux->nro<mayor){
            mayor=aux->nro;
            conta1++;
        }
        conta2++;
        aux=aux->sgte;
    }
    if(conta1==conta2){
        return true;
    }
    else{
        return false;
    }
}
/***********************************************************************************************
menu
***********************************************************************************************/
void menu1(){
    cout<<"\n\t\tLISTA ENLAZADA SIMPLE\n\n";
    cout<<" 1. ISNSERTAR AL INICIO              "<<endl;
    cout<<" 2. INSERTAR AL FINAL                "<<endl;
    cout<<" 3. INSERTAR EN UNA POSICION         "<<endl;
    cout<<" 4. MOSTRAR LISTA                    "<<endl;
    cout<<" 5. BUSCAR ELEMENTO                  "<<endl;
    cout<<" 6. ELIMINAR ELEMENTO 'V'            "<<endl;
    cout<<" 7. ELIMINAR ELEMENTO CON VALOR 'V'  "<<endl;
    cout<<" 8. CONTAR CUANTO SE REPITE DATO     "<<endl;
    cout<<" 9. INVERTIR LISTA                   "<<endl;
    cout<<" 10. PROMEDIO DE DATOS               "<<endl;
    cout<<" 11. DATO MAYOR                      "<<endl;
    cout<<" 12. ORDEN LISTA                     "<<endl;
    cout<<" 13. SALIR                           "<<endl;
    cout<<"\n INGRESE OPCION: ";

}
/***********************************************************************************************
funcion pricipal
***********************************************************************************************/
int main(){
        Tlista lista = NULL;
        int op;
        int _dato;
        int pos;
        system("color 0b");
        do{
            menu1();
            cin>>op;
            switch(op){
                case 1:
                    cout<<"\n NUMERO A INSERTAR: ";
                    cin>>_dato;
                    insertarInicio(lista,_dato);
                break;
                case 2:
                    cout<<"\n NUMERO A INSERTAR: ";
                    cin>>_dato;
                    insertarFinal(lista,_dato);
                break;
                case 3:
                    cout<<"\n NUMERO A INSERTAR: ";
                    cin>>_dato;
                    cout<<"Posicion: ";
                    cin>>pos;
                    insertarElemento(lista,_dato,pos);
                break;
                case 4:
                    cout<<"\n\n MOSTRAR LISTA\n\n";
                    mostrarLista(lista);
                break;
                case 5:
                    cout<<"\n Valor a buscar: ";
                    cin>>_dato;
                    buscarElemento(lista,_dato);
                break;
                case 6:
                    cout<<"\n Valor a eliminar: ";
                    cin>>_dato;
                    eliminarElemento(lista,_dato);
                break;
                case 7:
                    cout<<"\n Valor repetido a eliminar: ";
                    cin>>_dato;
                    eliminarRepetidos(lista,_dato);
                break;
                case 8:
                    {
                        Tlista lista = NULL;
                        int op;
                        int _dato;
                        int n,i,conta=0;
                        cout<<"\n tamaño lista: ";cin>>n;
                        i=0;
                        while(i<n){
                                system("cls");
                            cout<<"\n NUMERO A INSERTAR "<<i+1<<": ";
                            cin>>_dato;
                            insertarInicio(lista,_dato);
                            i++;
                        }
                        system("cls");
                        cout<<"\n NUMERO A BUSCAR: ";cin>>_dato;
                        conta=contarDato(lista,_dato);
                        if(conta>0){
                            cout<<"\n El numero se repite "<<conta<<" veces"<<endl;
                        }
                        else{
                            cout<<"\n El numero no se encuentra dentro de la lista"<<endl;
                        }
                    }
                break;
                case 9:
                    {
                        Tlista lista = NULL;
                        int op;
                        int _dato;
                        int n,i,conta=0;
                        cout<<"\n tamaño lista: ";cin>>n;
                        i=0;
                        while(i<n){
                                system("cls");
                            cout<<"\n NUMERO A INSERTAR "<<i+1<<": ";
                            cin>>_dato;
                            insertarInicio(lista,_dato);
                            i++;
                        }
                        system("cls");
                        mostrarLista(lista);
                        invertirDatos(lista);
                        mostrarLista(lista);
                    }
                break;
                case 10:
                    {
                       Tlista lista = NULL;
                        int op;
                        int _dato;
                        int n,i,conta=0;
                        cout<<"\n tamaño lista: ";cin>>n;
                        i=0;
                        while(i<n){
                                system("cls");
                            cout<<"\n NUMERO A INSERTAR "<<i+1<<": ";
                            cin>>_dato;
                            insertarInicio(lista,_dato);
                            i++;
                        }
                        _dato=promedioDatos(lista);
                        cout<<"\n El promedio es: "<<_dato<<endl;
                    }
                break;
                case 11:
                    {
                       Tlista lista = NULL;
                        int op;
                        int _dato;
                        int n,i,mayor;
                        cout<<"\n tamaño lista: ";cin>>n;
                        i=0;
                        while(i<n){
                                system("cls");
                            cout<<"\n NUMERO A INSERTAR "<<i+1<<": ";
                            cin>>_dato;
                            insertarInicio(lista,_dato);
                            i++;
                        }
                        mayor=datoMayor(lista);
                        cout<<"\n El dato mayor es: "<<mayor<<endl;
                    }
                break;
                case 12:
                    {
                       Tlista lista = NULL;
                        int op;
                        int _dato;
                        int n,i;
                        bool bande;
                        cout<<"\n tamaño lista: ";cin>>n;
                        i=0;
                        while(i<n){
                                system("cls");
                            cout<<"\n NUMERO A INSERTAR "<<i+1<<": ";
                            cin>>_dato;
                            insertarInicio(lista,_dato);
                            i++;
                        }
                        bande=ordenLista(lista);
                        if(bande==true){
                            cout<<"\n Esta ordenada de forma acendente"<<endl;
                        }
                        else{
                            cout<<"\n No esta ordenada de forma acendente"<<endl;
                        }
                    }
                break;
            }
            cout<<endl<<endl;
            system("pause");
            system("cls");
        }while(op!=13);
        system("pause");
        return 0;
}
