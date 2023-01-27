/************************************************************************************************
taller 8 estructura de datos
univercidad tecnologica de pereira 06/05/2022
brayan chiquito
    objetivo:
                    1. Calcular el peso de un árbol binario.
                    2. Calcular la altura de un árbol binario.
                    3. Contar cuantas hojas tiene un árbol binario.
                    4. Hacer una función que devuelva el padre de un elemento dado en el
                       árbol.
                    5. Indicar con una función boolean, si dos árboles binarios son iguales.
                    6. Indicar con una función boolean, si dos árboles binarios son isomorfos
                       (tienen la misma forma).
                    7. Indicar con una función boolean si dos árboles binarios son semejantes
                       (tienen los mismos elementos aunque no tengan la misma forma)
                    8. Hacer una función boolean que indique si un árbol binario está lleno.
                    9. Calcular el nivel de un elemento en un árbol binario.
                    10. Hacer una función que indique cuantos elementos tiene un árbol binario
                        en un nivel dado.
                    11. Hacer una función que reciba dos elementos e indique si son primos (sus
                        padres son hermanos).
                    12. Un árbol de valores enteros es estable, si para todo elemento su padre
                        es mayor. Hacer una función que reciba un árbol binario de enteros e
                        indique si es estable.
                    13. Hacer una función que retorne el mayor elemento del árbol.
                    14. Hacer una función que retorne una lista con los elementos del nivel dado
                        N.
                    15. Elimina del árbol binario un elemento dado, conservando su recorrido en
                        inorden salvo por elemento retirado.
************************************************************************************************/

#include <iostream>
#include <cstdlib>
using namespace std;
/***********************************************************************************************
estrucutra arbol
***********************************************************************************************/
struct nodo{
    int nro;
    struct nodo *izq,*der;
};

typedef struct nodo *ABB;
/***********************************************************************************************
funcion crear nodo
***********************************************************************************************/
ABB crearNodo(int x){
    ABB nuevoNodo = new(struct nodo);
    nuevoNodo->nro=x;
    nuevoNodo->izq = NULL;
    nuevoNodo->der = NULL;

    return nuevoNodo;
}
/***********************************************************************************************
funcion insertar
***********************************************************************************************/
void insertar(ABB &arbol, int x){
    if(arbol==NULL){
        arbol=crearNodo(x);
    }
    else if(x<arbol->nro)
        insertar(arbol->izq,x);
    else if(x>arbol->nro)
        insertar(arbol->der,x);
}
/***********************************************************************************************
funcion mostar pre orden
***********************************************************************************************/
void preOrden(ABB arbol){
    if(arbol!=NULL){
        cout<<arbol->nro<<" ";
        preOrden(arbol->izq);
        preOrden(arbol->der);
    }
}
/***********************************************************************************************
funcion mostrar en orden
***********************************************************************************************/
void enOrden(ABB arbol){
    if(arbol!=NULL){
        enOrden(arbol->izq);
        cout<<arbol->nro<<" ";
        enOrden(arbol->der);
    }
}
/***********************************************************************************************
funcion mostrar post orden
***********************************************************************************************/
void postOrden(ABB arbol){
    if(arbol!=NULL){
        postOrden(arbol->izq);
        postOrden(arbol->der);
        cout<<arbol->nro<<" ";
    }
}
/***********************************************************************************************
funcion ver arbol
***********************************************************************************************/
void verArbol(ABB arbol,int n){
    if(arbol==NULL)
        return;
    verArbol(arbol->der,n+1);
    for(int i=0;i<n;i++)
        cout<<"  ";
    cout<<arbol->nro<<endl;
    verArbol(arbol->izq,n+1);
}
/***********************************************************************************************
funcion buscar dato
***********************************************************************************************/
bool buscar(ABB arbol,int dato){
    int r=0;
    if(arbol==NULL)
        return r;
    if(dato<arbol->nro)
        r=buscar(arbol->izq,dato);
    else if(dato>arbol->nro)
        r=buscar(arbol->der,dato);
    else
        r=1;
    return r;
}
/***********************************************************************************************
funcion eliminar dato
***********************************************************************************************/
void eliminar(ABB &arbol,int x)
{
    ABB aux1,aux2;
    if(arbol==NULL) return;
    if(x>arbol->nro)
         eliminar(arbol->der,x);
    if(x<arbol->nro)
        eliminar(arbol->izq,x);
    if(x==arbol->nro)
    {
        if(arbol->der==NULL && arbol->izq==NULL) //Si el nodo es hoja
        {
            arbol=NULL;
            return;
        }
        if(arbol->der!=NULL && arbol->izq==NULL)
        {
            arbol=arbol->der;
            return;
        }
            aux1=arbol;
            aux2=arbol->izq;
            while(aux2->der!=NULL)
            {
                aux1=aux2;
                aux2=aux2->der;
            }
            arbol->nro=aux2->nro;
            if(aux1==arbol)
                arbol->izq=aux2->izq;
            else
            aux1->der=aux2->izq;
    }
}
/***********************************************************************************************
funcion peso de un arbol
    objetivo:       Calcular el peso de un árbol binario.
    funcion:        pesoABB(ABB arbol,int &num) se recore el arbol y mientras avanza se tiene
                    un contador de cuantos nodos hay
    ejemplo:        insertar(5-7-1).

    resultado:      el peso es: 3
***********************************************************************************************/
int pesoABB(ABB arbol,int &num){
    if(arbol!=NULL){
        pesoABB(arbol->izq,num);
        pesoABB(arbol->der,num);
        num++;
    }
}
/***********************************************************************************************
funcion altura de un arbol
    objetivo:       Calcular la altura de un árbol binario.
    funcion:        int alturaABB(ABB arbol) re recorren ambaz rama para ver su altura y dependiendo
                    la mas alta se devuelve el resultado
    ejemplo:        insertar(5-1-6)

    resultado:      la altura es: 2
***********************************************************************************************/
int alturaABB(ABB arbol)
{
    if(arbol==NULL) return 0;
    else{
         if (arbol->izq==NULL && arbol->der==NULL) return 1;
         int altIzq=0;
         int altDer=0;
         if(arbol->izq) altIzq=alturaABB(arbol->izq);
         if(arbol->der) altDer=alturaABB(arbol->der);

         if(altIzq>altDer)
               return altIzq+1;
         else
               return altDer+1;
         }
}
/***********************************************************************************************
funcion contar hojas del arbol
    objetivo:       Contar cuantas hojas tiene un árbol binario.
    funcion:        hojasArbolABB(ABB arbol,int &num) se recorre el arbol y se pregunta por los nodos
                    que tiene sus dos ramas en NULL lo que lo hace hoja
    ejemplo:        insertar(5-1-6)

    resultado:      hojas: 2
***********************************************************************************************/
int hojasArbolABB(ABB arbol,int &num){
    if(arbol!=NULL){
        if(arbol->der==NULL&&arbol->izq==NULL){
            num++;
        }
        hojasArbolABB(arbol->izq,num);
        hojasArbolABB(arbol->der,num);
    }
}
/***********************************************************************************************
funcion padre de un nodo
    objetivo:       Hacer una función que devuelva el padre de un elemento dado en el
                    árbol.
    funcion:        padreABB(ABB arbol,int dato,int &n)
                    padre2ABB(ABB arbol,int dato,int n,int &i) se busca la posicion del numero en
                    la parte 1 para dejar un contador que el a parte do buscara el numero otra vez
                    pero parar en la posicion del padre
    ejemplo:        insertar(5-1-6)
                    nodos a buscar padre: 1

    resultado:      el padre es: 5
***********************************************************************************************/
int padreABB(ABB arbol,int dato,int &n){
    if(arbol->nro==dato){
        return 0;
    }
    else if(dato<arbol->nro){
        n++;
        padreABB(arbol->izq,dato,n);
    }
    else{
        n++;
        padreABB(arbol->der,dato,n);
    }
}
int padre2ABB(ABB arbol,int dato,int n,int &i){
    if(i==(n-1)){
        return arbol->nro;
    }
    else if(dato<arbol->nro){
        i++;
        padre2ABB(arbol->izq,dato,n,i);
    }
    else{
        i++;
        padre2ABB(arbol->der,dato,n,i);
    }
}
/***********************************************************************************************
funcion arboles iguales
    objetivo:       Indicar con una función boolean, si dos árboles binarios son iguales.
    funcion:        arbolesIguales(ABB arbol1,ABB arbol2)
                    se coomparan los dos arboles dato a dato para saber si son iguales, pasando por el
                    filtro de si tiene el mismo peso y forma
    ejemplo:        insertar 1(5-6-1) insertar 2(5-6-1)

    resultado:      los arboles son iguales
***********************************************************************************************/
bool arbolesIguales(ABB arbol1,ABB arbol2){
    int r;
    if(arbol1==NULL||arbol2==NULL){
        return r;
    }
    if(arbol1->nro==arbol2->nro){
        r=arbolesIguales(arbol1->der,arbol2->der);
        r=arbolesIguales(arbol1->izq,arbol2->izq);
    }
    else{
        return false;
    }

}
/***********************************************************************************************
funcion arbol vacio
    objetivo:       saber si un arbol esta vacio
    funcion:        Vacio(ABB arbol)
    ejemplo:        vacio(arbol)

    resultado:      false
***********************************************************************************************/
bool Vacio(ABB arbol){
    if(arbol==NULL)
        return true;
    else return false;
}
/***********************************************************************************************
funcion arboles isomorfos
    objetivo:       Indicar con una función boolean, si dos árboles binarios son isomorfos
                    (tienen la misma forma).
    funcion:        ABBisomorfos(ABB arbol1,ABB arbol2)
                    auxIso(ABB arbol1,ABB arbol2,bool &band)
                    se comparan los dos arboles para ves si tienen la misma forma
    ejemplo:        insertar 1(5-6-1) insertar 2(5-6-1)

    resultado:      son isomorfos
***********************************************************************************************/
void auxIso(ABB arbol1,ABB arbol2,bool &band){
    if(arbol1->der && !arbol2->der || !arbol1->der && arbol2->der){
        band=false;
        return;
    }
    else{
        if(arbol1->der && arbol2->der)
            auxIso(arbol1->der,arbol2->der,band);
    }
    if(arbol1->izq && !arbol2->izq || !arbol1->izq && arbol2->izq){
        band=false;
        return;
    }
    else{
        if(arbol1->izq && arbol2->izq)
            auxIso(arbol1->izq,arbol2->izq,band);
    }
}
bool ABBisomorfos(ABB arbol1,ABB arbol2){
    cout<<"";
    if(Vacio(arbol1)||Vacio(arbol2)){
        return false;
    }
    else{
        bool band;
        band=true;
        auxIso(arbol1,arbol2,band);
        return band;
    }
}
/***********************************************************************************************
funcion arboles semejantes
    objetivo:       Indicar con una función boolean si dos árboles binarios son semejantes
                    (tienen los mismos elementos aunque no tengan la misma forma)
    funcion:        arbolesSemejantes(ABB arbol1,ABB arbol2) se dan los dos arboles y en el primero
                    se dal dato por dato para luego comprara con el arbol dos completamente a hasta
                    encontrar o no el dato
    ejemplo:        insertar 1(5-6-1) insertar 2(1-5-6)

    resultado:      son semejantes
***********************************************************************************************/
bool arbolesSemejantes(ABB arbol1,ABB arbol2){
    int r;
    if(arbol1==NULL){
        return r;
    }
    r=buscar(arbol2,arbol1->nro);
    if(r==true){
        arbolesSemejantes(arbol1->der,arbol2);
        arbolesSemejantes(arbol1->izq,arbol2);
    }
    else{
        return r;
    }
}
/***********************************************************************************************
funcion saber si es hoja
***********************************************************************************************/
int esHojaABB(ABB nodoABB)
{
   return !nodoABB->der && !nodoABB->izq;
}
/***********************************************************************************************
funcion arbol lleno
    objetivo:       Hacer una función boolean que indique si un árbol binario está lleno.
    funcion:        auxLleno(ABB arbol,bool &band)
                    arbolLleno(ABB arbol)
                    se entga un arbol y se pregunta nodo por nodo aver si es hoja o no para dar
                    con si esta lleno o no
    ejemplo:        insertar (5-6-1)

    resultado:      el arbol esta lleno
***********************************************************************************************/
void auxLleno(ABB arbol,bool &band){
    if(!esHojaABB(arbol) && arbol->der && arbol->izq){
            auxLleno(arbol->der,band);
            auxLleno(arbol->izq,band);
            }
    if(!arbol->der && arbol->izq || arbol->der && !arbol->izq){
        band=false;
        return;
    }
}
bool arbolLleno(ABB arbol){
    if(Vacio(arbol)){
        return false;
    }
    else{
        bool band;
        band=true;
        auxLleno(arbol,band);
        return band;
    }
}
/***********************************************************************************************
funcion nivel de un elemento
    objetivo:       Calcular el nivel de un elemento en un árbol binario.
    funcion:        nivelElemento(ABB arbol,int dato,int &n)
                    se busca dependiend si el dato es mayor o menor  al raiz para elejir la rama
                    donde se determina el nivel del dato
    ejemplo:        insertar (5-6-1)
                    numero a buscar: 6

    resultado:      nivel: 1
***********************************************************************************************/
int nivelElemento(ABB arbol,int dato,int &n){
    if(arbol->nro==dato){
        return 0;
    }
    if(arbol==NULL){
        return 1;
    }
    if(dato<arbol->nro){
        n++;
        nivelElemento(arbol->izq,dato,n);
    }
    else if(dato>arbol->nro){
        n++;
        nivelElemento(arbol->der,dato,n);
    }
}
/***********************************************************************************************
funcion niveles de un arbol
    objetivo:       saber cuantos nivles tien un rabol
    funcion:        nivelesArbol(ABB arbol)
                    se miran las dos ramas para dternimar cual es la mas larga y sus niveles
    ejemplo:        insertar (5-6-1)

    resultado:      niveles: 1
***********************************************************************************************/
int nivelesArbol(ABB arbol){
    if(arbol!=NULL){
        int izq=nivelesArbol(arbol->izq)+1;
        int der=nivelesArbol(arbol->der)+1;
        if(izq>der)
            return izq;
        return der;
    }
    return -1;
}
/***********************************************************************************************
funcion elementos de un nivel
    objetivo:       Hacer una función que indique cuantos elementos tiene un árbol binario
                    en un nivel dado.
    funcion:        elementosNivel(ABB arbol,int n)
                    se busca el nivel deseado con un contador dice cuantos datos estan en ese nivel
    ejemplo:        insertar(5-6-1)
                    numero:1

    resultado:      los numeros el nivel son: 2
***********************************************************************************************/
int elementosNivel(ABB arbol,int n){
    if(arbol!=NULL){
        if(n==0)
            return elementosNivel(arbol->izq,n-1) + elementosNivel(arbol->der,n-1) + 1;
        return elementosNivel(arbol->izq,n-1) + elementosNivel(arbol->der,n-1);
    }
    return 0;
}
/***********************************************************************************************
funcion mayor de un arbol
    objetivo:       Hacer una función que retorne el mayor elemento del árbol.
    funcion:        mayorABB(ABB arbol,int &mayor)
                    se recorre un arbol buscando el mayor
    ejemplo:        insertar(5-6-1)

    resultado:      el mayor es: 6
***********************************************************************************************/
void mayorABB(ABB arbol,int &mayor){
    if(arbol!=NULL){
        if(arbol->nro>mayor){
            mayor=arbol->nro;
        }
        mayorABB(arbol->izq,mayor);
        mayorABB(arbol->der,mayor);
    }
}
/***********************************************************************************************
funcion ver datos por nivel
    objetivo:       Hacer una función que retorne una lista con los elementos del nivel dado
                    N.
    funcion:        verNivel(ABB arbol,int n)
    ejemplo:        insertar(5-6-1)
                    nivel: 1

    resultado:      datos en el niverl: 6 1
***********************************************************************************************/
void verNivel(ABB arbol,int n){
    if(arbol!=NULL){
        if(n==0)
            cout<<arbol->nro<<" ";
        verNivel(arbol->izq,n-1);
        verNivel(arbol->der,n-1);
    }
}
/***********************************************************************************************
resto de ejercicios se hacen usando las funciones anterirores
***********************************************************************************************/
