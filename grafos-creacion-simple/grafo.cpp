#include "TADgrafo.h"
#include <iostream>

using namespace std;

int main(){
    Grafo Migrafo;
    int x;
    Migrafo=crearGrafo();
    x=vacioGrafo(Migrafo);
    if(x==1)
        cout<<"\nel grafo esta vacio...\n";
    else
        cout<<"\nel grafo esta con datos...\n";
    Migrafo=insertarVertice(Migrafo,1);
    Migrafo=insertarVertice(Migrafo,2);
    Migrafo=insertarVertice(Migrafo,3);
    Migrafo=insertarVertice(Migrafo,4);
    Migrafo=insertarVertice(Migrafo,5);
    cout<<"\nlista de vertices o nodos\n";
    imprimirListaV(Migrafo);

    x=vacioGrafo(Migrafo);
    if(x==1)
        cout<<"\nel grafo esta vacio...\n";
    else
        cout<<"\nel grafo esta con datos...\n";

    Migrafo=insertarArco(Migrafo,1,2,50);
    Migrafo=insertarArco(Migrafo,2,1,35);
    Migrafo=insertarArco(Migrafo,2,3,15);
    Migrafo=insertarArco(Migrafo,3,4,10);
    Migrafo=insertarArco(Migrafo,3,5,25);
    Migrafo=insertarArco(Migrafo,4,5,20);
    cout<<"\n\nlista de arcos\n";
    imprimirListaA(Migrafo);
    ListaVertice listadoNodo;
    listadoNodo=sucesores(Migrafo,3);
    cout<<endl;
    mostrarLista(listadoNodo);
    return 0;
}
