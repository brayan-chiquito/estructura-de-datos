/****************************************************
 Algoritmo: BFS (BUSQUEDA POR ANCHURA EN UN GRAFO)
 Tipo: Grafos
 Autor: Laura Camila Molina Osorio
 ****************************************************/
 /*Ejemplo de ingreso:

10 9

1 2
1 3
1 4
3 8
7 9
7 10
2 5
2 6
3 7

*/
#include<stdio.h>
#include <queue>

using namespace std;
#define MAX 500
vector<int> ady[ MAX ];  //lista de adyacencia
bool visitado[ MAX ];    //para nodos visitados

void bfs(){
    int ini , fin;
    printf("Nodo raiz: ");
    scanf( "%d" , &ini );
    printf("Nodo final: ");
    scanf( "%d" , &fin );
    queue<int> Q;
    Q.push( ini );
    int pasos = 0 , maxi = 0;
    while( !Q.empty() ){
       maxi = max( maxi , ( int ) Q.size() );              //simplemente para ver la memoria usada en la cola
       int actual = Q.front(); Q.pop();
       pasos++;
       if( actual == fin )break;                               //si se llego al destino

       visitado[ actual ] = true;
       for( int i = 0 ; i < ady[ actual ].size() ; ++i ){              //vemos adyacentes de nodo actual
          if( !visitado[ ady[ actual ][ i ] ] ){                   //si no esta visitado insertamos
             printf("%d --> %d\n" , actual , ady[ actual ][ i ] );  //vemos recorrido BFS
             Q.push( ady[ actual ][ i ] );
          }
       }
    }
    printf( "Memoria maxima: %d\n" , maxi );
    printf( "Nro Pasos: %d\n" , pasos );
}


int main(){

    int V , E , x , y;
    scanf( "%d %d" , &V , &E ); //Numero de vertices y numero de aristas

    for( int i = 1 ; i <= E ; ++i ){
        scanf( "%d %d" , &x , &y );  //Origen y destino
        ady[ x ].push_back( y );
    }
    bfs();

    return 0;
}
