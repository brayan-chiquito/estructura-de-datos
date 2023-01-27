#include "TADgrafo.h"
#include <iostream>

using namespace std;

int main(){
    Grafo Migrafo,Migrafo1;
    int x,y;
    Migrafo=crearGrafo();
    Migrafo1=crearGrafo();
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
    /*                          //demas funciones funcionales descativadas
    ListaVertice listadoNodo;
    listadoNodo=sucesores(Migrafo,3);
    cout<<endl;
    mostrarLista(listadoNodo);
    cout<<"\n\n";
    ListaVertice listadoNodo1;
    listadoNodo1=verticesGrafo(Migrafo);
    mostrarLista(listadoNodo1);
    cout<<"\n\n";
    ListaArco listadoNodo2;
    listadoNodo2=arcosGrafo(Migrafo);
    mostrarLista1(listadoNodo2);
    cout<<"\n\n";

    ListaVertice listadoNodo3;
    listadoNodo3=verticesGrafo(Migrafo1);
    mostrarLista(listadoNodo3);

    Migrafo=cambiarListaV(Migrafo,listadoNodo3);
    imprimirListaV(Migrafo);
    cout<<"\n\n";

    ListaArco listadoNodo4;
    listadoNodo4=arcosGrafo(Migrafo1);
    mostrarLista1(listadoNodo4);
    Migrafo=cambiarListaA(Migrafo,listadoNodo4);
    imprimirListaA(Migrafo);
    cout<<"\n\n";

    cout<<"\nQue arco desea eliminar?\n";
    cout<<"origen: ";cin>>x;
    cout<<"destino: ";cin>>y;
    Migrafo=eliminarArco(Migrafo,x,y);
    imprimirListaA(Migrafo);

    int costo;
    cout<<"\nQue costo desea saber?\n";
    cout<<"origen: ";cin>>x;
    cout<<"destino: ";cin>>y;
    costo=costoArco(Migrafo,x,y);
    if(costo==-1){
        cout<<"no se encontro el arco"<<endl;
    }
    else{
        cout<<"el costo es "<<costo<<endl;
    }

    int vortices;
    vortices=ordenGrafo(Migrafo);
    cout<<"\nNumero de vortices: "<<vortices;

    cout<<"\nque vortice desea marcar?: ";cin>>x;
    Migrafo=marcarVertice(Migrafo,x);
    imprimirListaV(Migrafo);
    cout<<"\nque vortice desea desmarcar?: ";cin>>x;
    Migrafo=desmarcarVertice(Migrafo,x);
    imprimirListaV(Migrafo);

    cout<<"\nque vortice desea marcar?: ";cin>>x;
    Migrafo=marcarVertice(Migrafo,x);
    imprimirListaV(Migrafo);
    cout<<"\nque vortice desea marcar?: ";cin>>x;
    Migrafo=marcarVertice(Migrafo,x);
    imprimirListaV(Migrafo);
    Migrafo=desmarcarGrafo(Migrafo);
    cout<<endl;
    imprimirListaV(Migrafo);

    cout<<"\nque vortice desea marcar?: ";cin>>x;
    Migrafo=marcarVertice(Migrafo,x);
    imprimirListaV(Migrafo);
    int marcado;
    cout<<"\nnumero: ";cin>>x;
    marcado=marcadoVertice(Migrafo,x);
    if(marcado==1)
        cout<<"esta marcado"<<endl;
    else
        cout<<"no esta marcado"<<endl;

    cout<<endl;
    Migrafo=eliminarVertice2(Migrafo);
    cout<<"\nlista de vertices o nodos\n";
    imprimirListaV(Migrafo);
    cout<<"\n\nlista de arcos\n";
    imprimirListaA(Migrafo);
    */
    cout<<"\nHola\n";
    imprimirListaV(Migrafo);
    cout<<endl<<endl;
    int arc,ver;
    ver=contarVertices(Migrafo);
    arc=contarArcos(Migrafo);
    //BFS(Migrafo,ver,arc);         //funciona
    //DFS(Migrafo,arc);             //funciona
    //DIJKSTRA(Migrafo,ver,arc);    //funciona
    //prim(Migrafo,ver,arc); //actualmente con un error desconocido
    return 0;
}
