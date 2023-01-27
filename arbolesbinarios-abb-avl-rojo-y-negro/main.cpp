/************************************************************************************************
taller 8 estructura de datos
univercidad tecnologica de pereira 06/05/2022
brayan chiquito
    objetivo:       Este taller se deben implementar los métodos básicos de los arboles binarios de
                    búsqueda, AVL y rojo - negros
                    1. ABB
                    2. Arboles AVL
                    3. Arboles Rojo – Negros
                    4. Salir
                    Qué tipo de árbol Desea Implementar (1-4)? _

                    1. Insertar
                    2. Eliminar
                    3. Buscar
                    4. Ver el Árbol
                    5. Recorrer el árbol en En-orden
                    6. Recorrer el árbol en Pre-orden
                    7. Recorrer el árbol en Post-orden
                    8. Calcular el Peso del árbol
                    9. Altura del árbol
                    10. Contar Cuantas hojas Tiene el árbol
                    11. Padre de un Nodo
                    … Deben estar todas las funciones para los ABB
                    n. Regresar

                    Submenú AVL
                    1. Insertar
                    2. Eliminar
                    3. Buscar
                    4. Ver el Árbol
                    5. Regresar

                    Submenú Rojo - Negro
                    1. Insertar
                    2. Eliminar
                    3. Buscar
                    4. Ver el Árbol
                    5. Regresar

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

#include <cstdlib>
#include <iostream>

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <math.h>

#include "tabABB.h"
#include "AVL.h"
#include "rojonegro.h"

/***********************************************************************************************
menu arboles
***********************************************************************************************/
menu0(){
    cout<<"1.ABB\n";
    cout<<"2.AVL\n";
    cout<<"3.RBT\n";
    cout<<"4.Salir\n";
    cout<<"ingrese: ";
}
/***********************************************************************************************
menu ABB
***********************************************************************************************/
void menu(){
    cout<<"ABB\n";
    cout<<"1. insertar \n";
    cout<<"2. buscar \n";
    cout<<"3. elimiar\n";
    cout<<"4. ver arbol\n";
    cout<<"5. Recorrer en-orden\n";
    cout<<"6. Recorrer pre-orden\n";
    cout<<"7. Recorrer post-orden\n";
    cout<<"8. calcular peso del arbol\n";
    cout<<"9. altura del arbol\n";
    cout<<"10. contar cuntas hojas tiene el arbol\n";
    cout<<"11. padre de un nodo\n";
    cout<<"12. arboloes iguales\n";
    cout<<"13. arboloes isomorfos\n";
    cout<<"14. arboloes semejantes\n";
    cout<<"15. arbol lleno\n";
    cout<<"16. calcular nivel\n";
    cout<<"17. calcular nodos en un nivel\n";
    cout<<"18. calcular primos\n";
    cout<<"19. calcular mayor\n";
    cout<<"20. mostar numeros por nivel\n";
    cout<<"21. Salir\n";
    cout<<"insertar opcion: ";
}
/***********************************************************************************************
menu AVL
***********************************************************************************************/
void menu2(){
    cout<<"AVL\n";
    cout<<"1. insertar \n";
    cout<<"2. buscar \n";
    cout<<"3. elimiar\n";
    cout<<"4. ver arbol\n";
    cout<<"5. Salir\n";
    cout<<"insertar opcion: ";
}
/***********************************************************************************************
menu rojo y negro
***********************************************************************************************/
void menu3(){
    cout<<"RojoNegro\n";
    cout<<"1. insertar \n";
    cout<<"2. buscar \n";
    cout<<"3. elimiar\n";
    cout<<"4. ver arbol\n";
    cout<<"5. Salir\n";
    cout<<"insertar opcion: ";
}
/***********************************************************************************************
funcion principal ABB
***********************************************************************************************/
menuABB(){
    system("cls");
    ABB arbol = NULL;   //creal arbol
    int x,x1,num,num2,dato,n,i,mayor=0;;
    int op;
    bool b,b2,bande;             //elemento a insertar en cada nodo
    do{
        menu();cin>>op;
        switch(op){
            case 1:
                cout<<"Numero: ";cin>>x;
                insertar(arbol,x);
                verArbol(arbol,0);
            break;
            case 2:
                cout<<"Entre el nodo buscar: ";
                cin>>x;
                b=buscar(arbol,x);
                if(b==true)
                    cout<<"el dato "<<x<<" esta dentro del arbol"<<endl;
                else
                    cout<<"el dato "<<x<<" no existe dentro del arbol"<<endl;
            break;
            case 3:
                cout<<"Numero a eliminar: ";
                cin>>x;
                eliminar(arbol,x);
                verArbol(arbol,0);
            break;
            case 4:
                cout<<"\n Mostrar ABB \n\n";
                verArbol(arbol,0);
            break;
            case 5:
                cout<<"\n\n En orden   : "; enOrden(arbol);
                cout<<endl;
            break;
            case 6:
                cout<<"\n\n Pre orden  : "; preOrden(arbol);
                cout<<endl;
            break;
            case 7:
                cout<<"\n\n Post orden : "; postOrden(arbol);
                cout<<endl;
            break;
            case 8:
                num=0;
                pesoABB(arbol,num);
                cout<<"\nEl peso del arbol es: "<<num<<endl<<endl;
            break;
            case 9:
                num=0;
                num=alturaABB(arbol);
                cout<<"\nLa altura del arbol es: "<<num<<endl<<endl;
            break;
            case 10:
                num=0;
                hojasArbolABB(arbol,num);
                cout<<"\nHojas del arbol: "<<num<<endl<<endl;
            break;
            case 11:
                cout<<"Numero a buscar padre: ";
                cin>>x;
                if(x==arbol->nro){
                    cout<<"\nEs el nodo raiz."<<endl<<endl;
                }
                else{
                    num=0;
                    n=0;
                    i=0;
                    b=buscar(arbol,x);
                    if(b==true){
                        padreABB(arbol,x,n);
                        num=padre2ABB(arbol,x,n,i);
                        cout<<"\nEl padre es: "<<num<<endl<<endl;
                    }
                    else{
                        cout<<"\nNumero no valido.\n";
                    }
                }
            break;
            case 12:
                {
                    int op,num1=0,num2=0;
                    bool bande=true;
                    ABB arbol1 = NULL;
                    ABB arbol2 = NULL;
                    do{
                        system("cls");
                        cout<<"1.arbol 1"<<endl;
                        cout<<"2.arbol 2"<<endl;
                        cout<<"3.calcular "<<endl;
                        cout<<"4.salir "<<endl;
                        cout<<"opcion: ";cin>>op;
                        switch(op){
                            case 1:
                                cout<<"Numero: ";cin>>x;
                                insertar(arbol1,x);
                                verArbol(arbol1,0);
                                system("pause");
                            break;
                            case 2:
                                cout<<"Numero: ";cin>>x;
                                insertar(arbol2,x);
                                verArbol(arbol2,0);
                                system("pause");
                            break;
                            case 3:
                                num1=0;
                                num2=0;
                                pesoABB(arbol1,num1);
                                pesoABB(arbol2,num2);
                                if(num1==num2){
                                    bande=arbolesIguales(arbol1,arbol2);
                                    if(bande==true){
                                            cout<<"\nLos arboles son iguales\n";
                                    }
                                    else{
                                            cout<<"\nLos arboles no son iguales\n";
                                    }
                                }
                                else{
                                    cout<<"\nLos arboles no son iguales\n";
                                }
                                system("pause");
                            break;
                        }
                    }while(op!=4);
                }
            break;
            case 13:
                {
                    int op;
                    bool bande;
                    ABB arbol1 = NULL;
                    ABB arbol2 = NULL;
                    do{
                        system("cls");
                        cout<<"1.arbol 1"<<endl;
                        cout<<"2.arbol 2"<<endl;
                        cout<<"3.calcular "<<endl;
                        cout<<"4.salir "<<endl;
                        cout<<"opcion: ";cin>>op;
                        switch(op){
                            case 1:
                                cout<<"Numero: ";cin>>x;
                                insertar(arbol1,x);
                                verArbol(arbol1,0);
                                system("pause");
                            break;
                            case 2:
                                cout<<"Numero: ";cin>>x;
                                insertar(arbol2,x);
                                verArbol(arbol2,0);
                                system("pause");
                            break;
                            case 3:
                                bande=ABBisomorfos(arbol1,arbol2);
                                if(bande==true){
                                    cout<<"\nSon isomorfos\n";
                                }
                                else{
                                    cout<<"\nNo son isomorfos\n";
                                }
                                system("pause");
                            break;
                        }
                    }while(op!=4);
                }
            break;
            case 14:
                {
                   int op;
                    bool bande;
                    ABB arbol1 = NULL;
                    ABB arbol2 = NULL;
                    do{
                        system("cls");
                        cout<<"1.arbol 1"<<endl;
                        cout<<"2.arbol 2"<<endl;
                        cout<<"3.calcular "<<endl;
                        cout<<"4.salir "<<endl;
                        cout<<"opcion: ";cin>>op;
                        switch(op){
                            case 1:
                                cout<<"Numero: ";cin>>x;
                                insertar(arbol1,x);
                                verArbol(arbol1,0);
                                system("pause");
                            break;
                            case 2:
                                cout<<"Numero: ";cin>>x;
                                insertar(arbol2,x);
                                verArbol(arbol2,0);
                                system("pause");
                            break;
                            case 3:
                                int num1=0;
                                int num2=0;
                                pesoABB(arbol1,num1);
                                pesoABB(arbol2,num2);
                                if(num1==num2){
                                    bande=arbolesSemejantes(arbol1,arbol2);
                                    if(bande==true){
                                            cout<<"\nLos arboles son semejantes\n";
                                    }
                                    else{
                                            cout<<"\nLos arboles no son semejantes\n";
                                    }
                                }
                                else{
                                    cout<<"\nLos arboles no son semejantes\n";
                                }
                                system("pause");
                            break;
                        }
                    }while(op!=4);
                }
            break;
            case 15:
                bande=arbolLleno(arbol);
                if(bande==true){
                    cout<<"\nEl arbol esta lleno\n";
                }
                else{
                    cout<<"\nEl arbol no esta lleno\n";
                }
            break;
            case 16:
                n=0;
                bande=Vacio(arbol);
                if(bande==true){
                    cout<<"\nArbol vacio\n";
                }
                else{
                    cout<<"Numero: ";cin>>x;
                    num=nivelElemento(arbol,x,n);
                    if(num==1){
                        cout<<"\nNo se encontro el numero\n";
                    }
                    else{
                        cout<<"\nEl numero esta en el nivel: "<<n<<endl;
                    }
                }
            break;
            case 17:
                bande=Vacio(arbol);
                if(bande==true){
                    cout<<"\nArbol vacio\n";
                }
                else{
                    cout<<"Numero: ";cin>>x;
                    if(x==0){
                        cout<<"\nEl numero de nodos es: "<<1<<endl;
                    }
                    else{
                        cout<<"\nEl numero de nodos es: "<<elementosNivel(arbol,x)<<endl;
                    }
                }
            break;
            case 18:
                bande=Vacio(arbol);
                if(bande==true){
                    cout<<"\nArbol vacio\n";
                }
                else{
                    int niv=0;
                    niv=nivelesArbol(arbol);
                    if(niv<1){
                        cout<<"\nArbol muy pequeño\n";
                    }
                    else{
                        cout<<"\nCalcular primos\n";
                        cout<<"Numero 1: ";cin>>x;
                        cout<<"Numero 2: ";cin>>x1;
                        if(x==arbol->nro||x1==arbol->nro){
                            cout<<"\nUno o los dos numeros son la raiz\n";
                        }
                        else{
                            b=buscar(arbol,x);
                            b2=buscar(arbol,x1);
                            if(b==true&&b2==true){
                                int c=0,c1=0;
                                nivelElemento(arbol,x,c);
                                nivelElemento(arbol,x1,c1);
                                if(c>1&&c1>1){
                                    n=0;
                                    i=0;
                                    padreABB(arbol,x,n);
                                    num=padre2ABB(arbol,x,n,i);
                                    n=0;
                                    i=0;
                                    padreABB(arbol,x1,n);
                                    num2=padre2ABB(arbol,x,n,i);
                                    n=0;
                                    i=0;
                                    padreABB(arbol,num,n);
                                    num=padre2ABB(arbol,num,n,i);
                                    n=0;
                                    i=0;
                                    padreABB(arbol,num2,n);
                                    num2=padre2ABB(arbol,num2,n,i);
                                    if(num==num2){
                                       cout<<"\nSon primos\n";
                                    }
                                    else{
                                        cout<<"\nNo son primos\n";
                                    }
                                }
                                else{
                                    cout<<"\nNo validos\n";
                                }
                            }
                            else{
                                cout<<"\nNo validos\n";
                            }
                        }
                    }
                }
            break;
            case 19:
                mayorABB(arbol,mayor);
                cout<<"\nEl dato mayor es: "<<mayor<<endl;
            break;
            case 20:
                cout<<"Nivel: ";cin>>x;
                cout<<"\nLos datos en el nivel son:\n";
                verNivel(arbol,x);
                cout<<endl<<endl;
            break;
            }
    system("pause");system("cls");
    }while(op!=21);

    cout<<endl<<endl;
    system("pause");
    return 0;
}
/***********************************************************************************************
funcion principal AVL
***********************************************************************************************/
menuAVL(){
    system("cls");
    AVL arbol = NULL;   //creal arbol
    int x;
    int op;
    do{
        menu2();cin>>op;
        switch(op){
            case 1:
                cout<<"Numero: ";cin>>x;
                insertarAVL(arbol,x);
                verArbolAVL(arbol,0);
            break;
            case 2:
                cout<<"Numero: ";cin>>x;
                buscarAVL(arbol,x);
            break;
            case 3:
                cout<<"Numero: ";cin>>x;
                eliminarNodo(arbol,x);
            break;
            case 4:
                verArbolAVL(arbol,0);
            break;
            }
        system("pause");system("cls");
    }while(op!=5);

    cout<<endl<<endl;
    system("pause");
    return 0;
}
/***********************************************************************************************
funcion peincipal RBT
***********************************************************************************************/
menuRbt(){
    system("cls");
    RBT arbol = NULL;   //creal arbol
    int x;
    int op;
    do{
        menu3();cin>>op;
        switch(op){
            case 1:
                cout<<"Numero: ";cin>>x;
                insertarRbt(arbol,x);
                verArbolRbt(arbol,0);
            break;
            case 2:
                cout<<"Numero: ";cin>>x;
                buscarRbl(arbol,x);
            break;
            case 3:
                cout<<"Numero: ";cin>>x;
                eliminar_rbt(arbol,x);
            break;
            case 4:
                verArbolRbt(arbol,0);
            break;
            }
        system("pause");system("cls");
    }while(op!=5);

    cout<<endl<<endl;
    system("pause");
    return 0;
}
/***********************************************************************************************
funcion principal
***********************************************************************************************/
int main(){
    int opci;
    do{
        menu0();cin>>opci;
        switch(opci){
            case 1:
                menuABB();
            break;
            case 2:
                menuAVL();
            break;
            case 3:
                menuRbt();
            break;
            }
        system("pause");system("cls");
    }while(opci!=4);
    cout<<endl<<endl;
    system("pause");
    return 0;
}
