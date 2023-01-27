#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <list>
#include<stdio.h>
#include <vector>
#include <queue>
#define MAX 10005
#define Node pair< int , int > //definimos el nodo como un par( first , second ) donde first es el vertice adyacente y second el peso de la arista
#define INF 1<<30 //definimos un valor grande que represente la distancia infinita inicial, basta conque sea superior al maximo valor del peso en alguna de las aristas



using namespace std;
/***************************
****************************/
struct nodo{
    int nro;
    struct nodo *sgte;
};
typedef nodo *ptrPila;

/***************************
****************************/
typedef struct NodoV
  {  int dato;
     struct NodoV *sig;
     int marcado;
        } *ListaVertice;

typedef struct NodoA
  {  int origen;
     int destino;
     int costo;
     struct NodoA *sig;
        } *ListaArco;


typedef struct nodoGrafo{
        ListaVertice v;
        ListaArco a;
        } Grafo;


Grafo crearGrafo()
  {
      Grafo g;
      g.v=NULL;
      g.a=NULL;
      return g;
  }
//si

/***************************
****************************/
void push(ptrPila &p,int valor){
    ptrPila aux;
    aux = new(struct nodo);
    aux->nro=valor;
    aux->sgte=p;
    p=aux;
}
int pop(ptrPila &p){
    int num;
    ptrPila aux;
    aux=p;
    num=aux->nro;

    p=aux->sgte;
    delete(aux);
    return num;
}
void  mostrar_pila(ptrPila p){
    ptrPila aux;
    aux = p;
    while(aux != NULL){
        cout<<"\t"<<aux->nro<<endl;
        aux=aux->sgte;
    }
}
/***************************
****************************/
void mostrarLista(ListaVertice lista){
    ListaVertice aux;
    aux=lista;
    while(aux!=NULL){
        cout<<aux->dato<<" ";
        aux=aux->sig;
    }
    cout<<endl;
}
void mostrarLista1(ListaArco lista){
    ListaArco aux;
    aux=lista;
    while(aux!=NULL){
        cout<<aux->costo<<" ";
        aux=aux->sig;
    }
    cout<<endl;
}
//si
// Funci�n para adicionar un vertice a la lista de v�rtices
Grafo insertarVertice (Grafo g, int x)
{
   ListaVertice nuevo=(ListaVertice) malloc(sizeof (struct NodoV));
   nuevo->sig=g.v;
   nuevo->dato=x;
   nuevo->marcado=0;   // el vertice no esta marcado
   g.v=nuevo;
   return g;
}

//si

void imprimirListaV(Grafo g)
{
     ListaVertice k=g.v;
     while (k!=NULL)
     {
           printf(" \n%d     %d",k->dato, k->marcado);
           k=k->sig;
           }
 }

//si
// Funci�n para adicionar un arco a la lista de arcos
Grafo insertarArco (Grafo g, int x, int y, int z)
{
   ListaArco nuevo=(ListaArco) malloc(sizeof (struct NodoA));
   nuevo->sig=g.a;
   nuevo->origen=x;
   nuevo->destino=y;
   nuevo->costo=z;
   g.a=nuevo;
   return g;
}

//si
// imprime la lista de arcos
void imprimirListaA(Grafo g)
{
     ListaArco k=g.a;
     while (k!=NULL)
     {
           printf(" \n%d    %d     %d",k->origen, k->destino, k->costo);
           k=k->sig;
           }
 }

//si
ListaVertice verticesGrafo (Grafo g)
 {
     return g.v;
 }

//si
ListaArco arcosGrafo (Grafo g)
 {
     return g.a;
 }

//si
Grafo cambiarListaV (Grafo g, ListaVertice k)
{
   g.v = k;
   return g;
}

//si
Grafo cambiarListaA (Grafo g, ListaArco k)
{
   g.a = k;
   return g;
}

//si
int vacioGrafo (Grafo g)
       // Devuelve verdadero si el grafo es vacio
    {
      if (g.v==NULL)
         return 1;
      else
         return 0;
    }
//modificar
// elimina un vertice del grafo
Grafo eliminarVertice (Grafo g, int x)
{
    ListaVertice k=g.v, p;

    if (g.v!=NULL)
        {
           if (g.v->dato == x)
             {
              g.v = g.v->sig;
              free(k);
              }
           else
             {
               while ((k->sig != NULL) && (k->sig->dato != x))
                  k=k->sig;
               if (k->sig!=NULL)
                  {
                     p=k->sig;
                     k->sig=p->sig;
                     free(p);
                  }
             }
        }
     return g;
 }
//si
// Elimina un arco que parta del origen x al destino y
Grafo eliminarArco (Grafo g, int x, int y)
{
    ListaArco k=g.a, p;

    if (g.a!=NULL)
        {
           if ((g.a->origen == x) && (g.a->destino == y))
             {
              g.a = g.a->sig;
              free(k);
              }
           else
             {
               while ((k->sig != NULL) && !((k->sig->origen == x) && (k->sig->destino == y)))
                  k=k->sig;
               if (k->sig!=NULL)
                  {
                     p=k->sig;
                     printf("\n el arco a borrar es %d   %d",p->origen,p->destino);
                     k->sig=p->sig;
                     free(p);
                  }
             }
        }
     return g;
 }

//si
 // retorna el costo del arco desde x hasta y
 int costoArco (Grafo g, int x, int y)
  {
    ListaArco k=g.a;

    while (k != NULL)
      {
       if ((k->origen == x) && (k->destino == y))
          return k->costo;
       k=k->sig;
      }
    return -1;       // no encontr� el arco
  }

//si
// retorna el n�mero de v�rtices asociados al grafo
int ordenGrafo(Grafo g)
  {
    int orden=0;
    ListaVertice k=g.v;

    while (k != NULL)
      {
        orden++;
        k=k->sig;
      }
    return orden;
  }


//si
// marca un vertice de grafo
Grafo marcarVertice (Grafo g, int x)
{
    ListaVertice k=g.v;

    while (k!=NULL)
        {
           if (k->dato == x)
             {
              k->marcado = 1;
              k=NULL;
             }
           else
             k=k->sig;
        }
     return g;
 }

//si
// desmarca un vertice de grafo
Grafo desmarcarVertice (Grafo g, int x)
{
    ListaVertice k=g.v;
    while (k!=NULL)
        {
           if (k->dato == x)
             {
              k->marcado = 0;
              k=NULL;
             }
           else
             k=k->sig;
        }
     return g;
 }

// desmarca todos los vertices del grafo
Grafo desmarcarGrafo (Grafo g)
{
    ListaVertice k=g.v;

    while (k!=NULL)
        {
           k->marcado = 0;
           k=k->sig;
        }
     return g;
 }

//si
//Indica si un v�rtice est� marcado
int marcadoVertice (Grafo g, int x)
{
    ListaVertice k=g.v;
    while (k!=NULL)
        {
           if (k->dato == x)
             {
              if (k->marcado == 0)
                  return 0;
              else
                  return 1;
             }
           else
             k=k->sig;
        }
     return 0;
 }

//si
ListaVertice sucesores(Grafo g, int x)
{
   ListaArco k=g.a;
   ListaVertice ver=NULL, nuevo;

    while (k != NULL)
      {
       if (k->origen == x)
          {  // se agrega a la lista el destino del arco como sucesor de x
            nuevo=(ListaVertice) malloc(sizeof (struct NodoV));
            nuevo->sig=ver;
            nuevo->dato=k->destino;
            nuevo->marcado=0;   // el vertice no esta marcado
            ver=nuevo;
            //printf("\nsucesor %d  ",nuevo->dato);
          }
       k=k->sig;
      }
   return ver;
}

void eliminarVertice3(ListaVertice lista,int x,int num,Grafo Migrafo){
    ListaVertice aux;
    aux=lista;
    while(aux!=NULL){
        if(aux->dato==num){
            Migrafo=eliminarArco(Migrafo,x,num);
        }
        aux=aux->sig;
    }
    cout<<endl;
}

Grafo eliminarVertice2(Grafo Migrafo){
    ListaVertice listadoNodo1;
    listadoNodo1=verticesGrafo(Migrafo);
    mostrarLista(listadoNodo1);

    ListaVertice listadoNodo;
    int num;
    cout<<"ingrese el vertice a eliminar";cin>>num;
    ListaVertice aux;
    aux=listadoNodo1;
    while(aux!=NULL){
        cout<<aux->dato<<endl;
        listadoNodo=sucesores(Migrafo,aux->dato);
        mostrarLista(listadoNodo);
        eliminarVertice3(listadoNodo,aux->dato,num,Migrafo);
        cout<<endl;
        aux=aux->sig;
    }
    Migrafo=eliminarVertice(Migrafo,num);
    return Migrafo;
}

int contarArcos(Grafo g){
    int n=0;
     ListaArco k=g.a;
     while (k!=NULL)
     {
           n++;
           k=k->sig;
           }
    return n;
 }

 int contarVertices(Grafo g){
     int n=0;
     ListaVertice k=g.v;
     while (k!=NULL)
     {
           n++;
           k=k->sig;
           }
    return n;
 }

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


void BFS(Grafo g,int ver, int arco){
    ptrPila p = NULL;
    ptrPila p1 = NULL;
    int V , E , x , y,i=0;
    V=ver;
    E=arco;
    ListaArco k=g.a;

    cout<<endl;
    while (k!=NULL){
        push(p,k->origen);
        push(p1,k->destino);
        k=k->sig;
        }
    while (i<E){
        x=pop(p);
        y=pop(p1);
        ady[ x ].push_back( y );
        i++;
        }
    bfs();

    system("pause");
}

class Graph{
    int V; //Numero de vertices
    list<int> *adj; //arreglo de listas de adyacencia
    bool *visited; //matriz de visitados.
public:
        Graph(int V); //Constructor
        void addEdge(int v,int w); //GRAFO Dirigido de v -> w
        void DFS(int v); //DFS iniciando de v
};
Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
    this->visited = new bool[this->V];
    for(int i=0;i<this->V;i++) this->visited[i] = false;
}
void Graph::addEdge(int v,int w){
    adj[v].push_back(w); //agrega w a la posicion v
    //adj[w].push_back(v); si fuera no dirigido
}
void Graph::DFS(int v){
    this->visited[v] = true; //marca el nodo actual como visitado e imprimelo
    cout << v << " ";

    list<int>::iterator it;
    for(it = adj[v].begin(); it!=adj[v].end();++it){ //nodos adyacentes
        if(!this->visited[*it]){
            DFS(*it);
        }
    }
}
int DFS(Grafo g,int A){
    int x,y,i=0;
    int arcos=A;
    arcos+=1;
    ptrPila p = NULL;
    ptrPila p1 = NULL;
    Graph G(arcos);
    ListaArco k=g.a;
    while (k!=NULL){
        push(p,k->origen);
        push(p1,k->destino);
        k=k->sig;
        }
    while (i<A){
        x=pop(p);
        y=pop(p1);
        G.addEdge(x,y);
        i++;
        }
    int src;
    cout << "La DFS de G es (iniciando de el vertice): ";cin>>src;
    cout<< endl << endl;
    G.DFS(src);
    cout<<endl;
    system("pause");
}

struct cmp {
    bool operator() ( const Node &a , const Node &b ) {
        return a.second > b.second;
    }
};
vector< Node > ady1[ MAX ]; //lista de adyacencia
int distancia[ MAX ];      //distancia[ u ] distancia de vértice inicial a vértice con ID = u
bool visitado1[ MAX ];      //para vértices visitados
priority_queue< Node , vector<Node> , cmp > Q; //priority queue propia del c++, usamos el comparador definido para que el de menor valor este en el tope
int previo[ MAX ];         //para la impresion de caminos

//función de inicialización
void init(int V){
    for( int i = 0 ; i <= V ; ++i ){
        distancia[ i ] = INF;  //inicializamos todas las distancias con valor infinito
        visitado1[ i ] = false; //inicializamos todos los vértices como no visitados
        previo[ i ] = -1;      //inicializamos el previo del vertice i con -1
    }
}

//Paso de relajacion
void relajacion( int actual , int adyacente , int peso ){
    //Si la distancia del origen al vertice actual + peso de su arista es menor a la distancia del origen al vertice adyacente
    if( distancia[ actual ] + peso < distancia[ adyacente ] ){
        distancia[ adyacente ] = distancia[ actual ] + peso;  //relajamos el vertice actualizando la distancia
        previo[ adyacente ] = actual;                         //a su vez actualizamos el vertice previo
        Q.push( Node( adyacente , distancia[ adyacente ] ) ); //agregamos adyacente a la cola de prioridad
    }
}

//Impresion del camino mas corto desde el vertice inicial y final ingresados
void print( int destino ){
    if( previo[ destino ] != -1 )    //si aun poseo un vertice previo
        print( previo[ destino ] );  //recursivamente sigo explorando
    printf("%d " , destino );        //terminada la recursion imprimo los vertices recorridos
}

void dijkstra( int inicial,int V ){
    init(V); //inicializamos nuestros arreglos
    Q.push( Node( inicial , 0 ) ); //Insertamos el vértice inicial en la Cola de Prioridad
    distancia[ inicial ] = 0;      //Este paso es importante, inicializamos la distancia del inicial como 0
    int actual , adyacente , peso;
    while( !Q.empty() ){                   //Mientras cola no este vacia
        actual = Q.top().first;            //Obtengo de la cola el nodo con menor peso, en un comienzo será el inicial
        Q.pop();                           //Sacamos el elemento de la cola
        if( visitado1[ actual ] ) continue; //Si el vértice actual ya fue visitado entonces sigo sacando elementos de la cola
        visitado1[ actual ] = true;         //Marco como visitado el vértice actual

        for( int i = 0 ; i < ady1[ actual ].size() ; ++i ){ //reviso sus adyacentes del vertice actual
            adyacente = ady1[ actual ][ i ].first;   //id del vertice adyacente
            peso = ady1[ actual ][ i ].second;        //peso de la arista que une actual con adyacente ( actual , adyacente )
            if( !visitado1[ adyacente ] ){        //si el vertice adyacente no fue visitado
                relajacion( actual , adyacente , peso ); //realizamos el paso de relajacion
            }
        }
    }
    puts("\n**************Impresion de camino mas corto**************");
    printf("Ingrese vertice destino: ");
    int destino;
    scanf("%d" , &destino );
    print( destino );
    printf("\n");
    printf( "Distancias mas cortas iniciando en vertice %d\n" , inicial );
    for( int i = 1 ; i <= destino ; ++i ){
        printf("Vertice %d , distancia mas corta = %d\n" , i , distancia[ i ] );
    }
}


int DIJKSTRA(Grafo g, int ver,int arc){
    int E ,i=0, origen, destino , peso , inicial;
    ptrPila p = NULL;
    ptrPila p1 = NULL;
    ptrPila p2 = NULL;
    E=arc;
    ListaArco k=g.a;
    while (k!=NULL){
        push(p,k->origen);
        push(p1,k->destino);
        push(p2,k->costo);
        k=k->sig;
        }
    mostrar_pila(p);
    cout<<endl;
    mostrar_pila(p1);
    cout<<endl;
    mostrar_pila(p2);
    cout<<endl;
    while (i<E){
        origen=pop(p),
        destino=pop(p1),
        peso=pop(p2);

        ady1[ origen ].push_back( Node( destino , peso ) ); //consideremos grafo dirigido
        ady1[ destino ].push_back( Node( origen , peso ) ); //grafo no dirigido
        i++;
        }
    printf("Ingrese el vertice inicial: ");
    scanf("%d" , &inicial );
    dijkstra( inicial , ver);
    system("pause");
}


/*********************
*********************/
# include "iostream"
# include <conio.h>
# include <stdio.h>
# include <stdlib.h>

using namespace std;

struct vertice {
       int nod;
       int marca;
       struct vertice *sig;
       struct arco *arc;
};

struct arco {
       struct vertice *ver;
       int marca;
       int suma;
       int clave;
       struct arco *sig;
};


struct vertice *pri, *nue, *aux, *ult, *aux2;
struct arco *nueArc, *auxArc, *arcMen, *auxArc2, *antArc;
char auxNod, auxNod2, ban2, let;
int ban, enlace, ban3, ban4, numVer;

void actualizarCampos ();
void crearVertice();
void enlazarVertices();
void enlazar();
void listarAdyacencia();
void obtenerArcoMenor();
void listarAdyacenciaPrim ();
void sumaCaminos();

void crearVertice (int dato) {
     system ("cls");
     if (pri == NULL){
        pri = new vertice;
        pri->nod=dato;
        pri->marca = 0;
        pri->arc = NULL;
        pri->sig = NULL;
        ult = pri;
     }
     else {
          do {
              aux = pri;
              ban = 0;
              while (aux != NULL){
                    if (aux->nod == dato){
                          ban = 1;
                    }
                    aux = aux->sig;
              }
              if (ban == 1) {
                     return ;
              }
          }while (ban == 1);
          nue = new vertice;
          nue->nod = dato;
          nue->marca = 0;
          nue->sig = NULL;
          nue->arc = NULL;
          ult->sig = nue;
          ult = nue;
     }

}

void enlazarVertices (int dato1,int dato2,int dato3) {
     system ("cls");
     if (pri != NULL){
        aux = pri;
        while (aux != NULL){
              cout << aux->nod << "\n";
              aux = aux->sig;
        }
        cout << "\nDigite la letra del nodo al cual desea enlazar: ";
        auxNod=dato1;
        ban = 0;
        while (ban == 0){
              aux = pri;
              while (aux != NULL && ban == 0){
                   if (aux->nod == auxNod){
                      ban = 1;
                   }
                   aux = aux->sig;
              }
              if (ban == 0){
                 return;
              }
        }
        auxNod2=dato2;
        ban = 0;
        while (ban == 0){
              aux = pri;
              while (auxNod2 == auxNod){
                    return;
              }
              while (aux != NULL && ban == 0){
                   if (aux->nod == auxNod2){
                      ban = 1;
                   }
                   aux = aux->sig;
              }
              if (ban == 0){
                 return;
              }
        }
        aux = pri;
        while (aux->nod != auxNod){
              aux = aux->sig;
        }
        auxArc = aux->arc;
        ban3 = 0;
        while (auxArc != NULL && ban3 == 0){
              if (auxArc->ver->nod == auxNod2){
                 ban3 = 1;
              }
              auxArc = auxArc->sig;
        }

        enlazar();
        cout << "\nEnlace creado correctamente.";
     }
}

void enlazar(){
        int valor;
        aux = pri;
        while (aux->nod != auxNod){
              aux = aux->sig;
        }
        aux2 = pri;
        while (aux2->nod != auxNod2){
              aux2 = aux2->sig;
        }
        if (aux->arc == NULL){
           nueArc = new arco;
           nueArc->ver = aux2;
           cout << "\nDigite el valor del enlace: ";
           enlace=valor;
           /*
           while (nueArc->clave < 0){
                 cout << "\nEl valor debe ser positivo\nDigite el valor del enlace: ";
                 cin >> enlace;
           }
           */
           nueArc->clave = enlace;
           nueArc->marca = 0;
           nueArc->suma = 0;
           nueArc->sig = NULL;
           aux->arc = nueArc;
           if (aux2->arc == NULL){
               nueArc = new arco;
               nueArc->ver = aux;
               nueArc->clave = enlace;
               nueArc->marca = 0;
               nueArc->suma = 0;
               nueArc->sig = NULL;
               aux2->arc = nueArc;
            }
            else {
               nueArc = new arco;
               nueArc->ver = aux;
               nueArc->clave = enlace;
               nueArc->marca = 0;
               nueArc->suma = 0;
               nueArc->sig = NULL;
               auxArc = aux2->arc;
               while (auxArc->sig != NULL){
                     auxArc = auxArc->sig;
               }
               auxArc->sig = nueArc;
            }
        }
        else {
           nueArc = new arco;
           nueArc->ver = aux2;
           enlace=valor;
           /*
           while (enlace < 0){
                 cout << "\nEl valor debe ser positivo\nDigite el valor del enlace: ";
                 cin >> enlace;
           }
           */
           nueArc->clave = enlace;
           nueArc->marca = 0;
           nueArc->suma = 0;
           nueArc->sig = NULL;
           auxArc = aux->arc;
           while (auxArc->sig != NULL){
                 auxArc = auxArc->sig;
           }
           auxArc->sig = nueArc;
           if (aux2->arc == NULL){
               nueArc = new arco;
               nueArc->ver = aux;
               nueArc->clave = enlace;
               nueArc->marca = 0;
               nueArc->suma = 0;
               nueArc->sig = NULL;
               aux2->arc = nueArc;
            }
            else {
               nueArc = new arco;
               nueArc->ver = aux;
               nueArc->clave = enlace;
               nueArc->marca = 0;
               nueArc->suma = 0;
               nueArc->sig = NULL;
               auxArc = aux2->arc;
               while (auxArc->sig != NULL){
                     auxArc = auxArc->sig;
               }
               auxArc->sig = nueArc;
            }
        }
}

void obtenerArcoMenor () {
     aux2 = pri;
     arcMen = NULL;
     while (aux2 != NULL){
           if (aux2->marca == 1){
                      auxArc = aux2->arc;
                      while (auxArc != NULL){
                            if (auxArc->marca == 1){
                                  if (arcMen == NULL){
                                         arcMen = auxArc;
                                  }
                                  else{
                                       if (auxArc->clave < arcMen->clave){
                                              arcMen = auxArc;
                                       }
                                  }
                            }
                            auxArc = auxArc->sig;
                      }
           }
           aux2 = aux2->sig;
     }
     arcMen->marca = 3;
     arcMen->ver->marca = 1;
}

void obtenerSumaMenor () {
     aux2 = pri;
     arcMen = NULL;
     while (aux2 != NULL){
           if (aux2->marca == 1){
                      auxArc = aux2->arc;
                      while (auxArc != NULL){
                            if (auxArc->marca == 1){
                                  if (arcMen == NULL){
                                         arcMen = auxArc;
                                  }
                                  else{
                                       if (auxArc->suma < arcMen->suma){
                                              arcMen = auxArc;
                                       }
                                  }
                            }
                            auxArc = auxArc->sig;
                      }
           }
           aux2 = aux2->sig;
     }
     arcMen->marca = 3;
     arcMen->ver->marca = 1;
     auxArc = arcMen->ver->arc;
     while (auxArc != NULL){
           auxArc->suma = arcMen->suma + auxArc->clave;
           auxArc = auxArc->sig;
     }
}

void paso2 (){
            obtenerArcoMenor();
            cout << "\nEl arco menor es: "<< arcMen->ver->nod << " vale: " << arcMen->clave;
            getch();
            aux = arcMen->ver;
            auxArc = aux->arc;
            while (auxArc != NULL){
                  if (auxArc->ver->marca == 0){
                         aux2 = pri;
                         while (aux2 != NULL){
                               if (aux2 != aux && aux2->marca == 1){
                                     auxArc2 = aux2->arc;
                                     while (auxArc2 != NULL){
                                           if (auxArc->ver->nod == auxArc2->ver->nod){
                                                  if (auxArc->clave < auxArc2->clave){
                                                         auxArc2->marca = 2;
                                                         auxArc->marca = 1;
                                                  }
                                                  else {
                                                       auxArc->marca = 2;
                                                       auxArc2->marca = 1;
                                                  }
                                           }
                                           auxArc2 = auxArc2->sig;
                                     }
                               }
                               aux2 = aux2->sig;
                         }
                         if (auxArc->marca == 0){
                                auxArc->marca = 1;
                         }
                  }
                  else {
                       auxArc->marca = 2;
                  }
                  auxArc = auxArc->sig;
            }
}




void algoritmoPrim () {
     system("cls");
     if (pri != NULL){
            actualizarCampos();
            cout << "Digite el vertice inicial: ";
            cin >> auxNod;
            ban = 0;
            while (ban == 0){
                  aux = pri;
                  while (aux != NULL){
                        if (aux->nod == auxNod){
                               ban = 1;
                        }
                        aux = aux->sig;
                  }
                  if (ban == 0){
                         cout << "\nNo existe un nodo con esa letra.";
                         aux = pri;
                         cout << "\n---Lista de Nodos---\n";
                         while (aux != NULL){
                               cout << aux->nod << " ";
                               aux = aux->sig;
                         }
                         cout << "\nDigite uno de los anteriores nodos: ";
                         cin >> auxNod;
                  }
            }
            aux = pri;
            while (aux->nod != auxNod){
                  aux = aux->sig;
            }
            aux->marca = 1;
            auxArc = aux->arc;
            while (auxArc != NULL){
                  auxArc->marca = 1;
                  auxArc = auxArc->sig;
            }
            cout << "\nSe han marcado todos los arcos para el vertice elegido.";
            ban2 = 1;
            while (ban2 == 1){
                  paso2();
                  ban2 = 0;
                  aux = pri;
                  while (aux != NULL){
                        if (aux->marca == 0){
                               ban2 = 1;
                        }
                        aux = aux->sig;
                  }
            }
            listarAdyacenciaPrim ();
            sumaCaminos();
     }
     getch();
}

void listarAdyacencia () {
     system ("cls");
     if (pri != NULL){
        aux = pri;
        cout << "---Lista de Adyacencia---\n";
        while (aux != NULL){
              auxArc = aux->arc;
              cout << "\n|\n" << aux->nod << "->";
              while (auxArc != NULL){
                    cout << auxArc->ver->nod << " ";
                    auxArc = auxArc->sig;
              }
              aux = aux->sig;
        }
        getch();
     }
}

void sumaCaminos () {
     aux = pri;
     int suma = 0;
     while (aux != NULL){
           auxArc = aux->arc;
           while (auxArc != NULL){
                 if (auxArc->marca == 3){
                        suma = suma + auxArc->clave;
                 }
                 auxArc = auxArc->sig;
           }
           aux = aux->sig;
     }
     cout << "\nLa suma de los caminos es: " << suma;
}

void listarAdyacenciaPrim () {
     if (pri != NULL){
        aux = pri;
        cout << "\n---Lista de Adyacencia---\n";
        while (aux != NULL){
              auxArc = aux->arc;
              cout << "\n|\n" << aux->nod << "->";
              while (auxArc != NULL){
                    if (auxArc->marca == 3)
                    cout << auxArc->ver->nod << " ";
                    auxArc = auxArc->sig;
              }
              aux = aux->sig;
        }
     }
}


void liberarMemoria () {
     if (pri != NULL){
        aux = pri;
        while (aux != NULL){
              auxArc = aux->arc;
              while (auxArc != NULL){
                    aux->arc = aux->arc->sig;
                    delete auxArc;
                    auxArc = aux->arc;
              }
              pri = pri->sig;
              delete aux;
              aux = pri;
        }
     }
     cout << "Memoria Libre";
     getch();
}



void actualizarCampos () {
     aux = pri;
     while (aux != NULL){
           auxArc = aux->arc;
           while (auxArc != NULL){
                 auxArc->marca = 0;
                 auxArc->suma = 0;
                 auxArc = auxArc->sig;
           }
           aux->marca = 0;
           aux = aux->sig;
     }
}

void prim(Grafo g,int ver,int arc){
    int dato,origen,destino,peso;
    ptrPila p = NULL;
    ptrPila p1 = NULL;
    ptrPila p2 = NULL;
    ptrPila p3 = NULL;
    ListaVertice k=g.v;
    while (k!=NULL){
        push(p,k->dato);
        k=k->sig;
        }
    int i=0;
    while(i<ver){
        dato=pop(p);
        cout<<dato;
        crearVertice(dato);
        i++;
    }
    ListaArco k1=g.a;
    while (k1!=NULL){
        push(p1,k1->origen);
        push(p2,k1->destino);
        push(p3,k1->costo);
        k=k->sig;
        }
    i=0;
    while (i<arc){
        origen=pop(p1),
        destino=pop(p2),
        peso=pop(p3);
        enlazarVertices(origen,destino,peso);
        i++;
    }
    //crearVertice();
    //enlazarVertices(); getch();
    //listarAdyacencia();
    //algoritmoPrim();
    //liberarMemoria ();
}
