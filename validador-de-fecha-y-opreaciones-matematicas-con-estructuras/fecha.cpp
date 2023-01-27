/************************************************************************************************
taller numero 2 estructura de datos
univercidad tecnologica de pereira 28/02/2022
brayan chiquito
    objetivo:   elaborar un algoritmo con estructuras para determinar si una fecha ingresada
                es valida
    funcion:    ValidarFecha --> 20/02/2020
                se envia fecha que esta denstro de un escrticura donde en la funcion
                ValidarFecha(Fecha anio,Fecha dia,Fecha mes) se compara primero si es un año
                biciesto para luego comprombar si el mes y el año son validos retornando un true
************************************************************************************************/
#include <iostream>
#include <stdlib.h>
using namespace std;
struct Fecha{
    int dd;
    int mm;
    int aaaa;
};
/***********************************************************************************************
funcion validar fecha
***********************************************************************************************/
bool ValidarFecha(Fecha anio,Fecha dia,Fecha mes){
    bool r;
    if(anio.aaaa%4!=0 || (anio.aaaa%100==0 && anio.aaaa%400!=0)){      //se determina si es o no un año bisiesto
        switch(mes.mm){                 //se busca el mes
            case 1:
                if(dia.dd<=31){
                    r=true;
                }
            break;
            case 2:
                if(dia.dd<=28){
                    r=true;
                }
            break;
            case 3:
                if(dia.dd<=31){
                    r=true;
                }
            break;
            case 4:
                if(dia.dd<=30){
                    r=true;
                }
            break;
            case 5:
                if(dia.dd<=31){
                    r=true;
                }
            break;
            case 6:
                if(dia.dd<=30){
                    r=true;
                }
            break;
            case 7:
                if(dia.dd<=31){
                    r=true;
                }
            break;
            case 8:
                if(dia.dd<=31){
                    r=true;
                }
            break;
            case 9:
                if(dia.dd<=30){
                    r=true;
                }
            break;
            case 10:
                if(dia.dd<=31){
                    r=true;
                }
            break;
            case 11:
                if(dia.dd<=30){
                    r=true;
                }
            break;
            case 12:
                if(dia.dd<=31){
                    r=true;
                }
            break;
            default:                    //en caso de no estar fecha no valida
                r=false;
        }
    }
    else{
        switch(mes.mm){
            case 1:
                if(dia.dd<=31){
                    r=true;
                }
            break;
            case 2:
                if(dia.dd<=29){
                    r=true;
                }
            break;
            case 3:
                if(dia.dd<=31){
                    r=true;
                }
            break;
            case 4:
                if(dia.dd<=30){
                    r=true;
                }
            break;
            case 5:
                if(dia.dd<=31){
                    r=true;
                }
            break;
            case 6:
                if(dia.dd<=30){
                    r=true;
                }
            break;
            case 7:
                if(dia.dd<=31){
                    r=true;
                }
            break;
            case 8:
                if(dia.dd<=31){
                    r=true;
                }
            break;
            case 9:
                if(dia.dd<=30){
                    r=true;
                }
            break;
            case 10:
                if(dia.dd<=31){
                    r=true;
                }
            break;
            case 11:
                if(dia.dd<=30){
                    r=true;
                }
            break;
            case 12:
                if(dia.dd<=31){
                    r=true;
                }
            break;
            default:
                r=false;
        }
    }
    return r;
}
/***********************************************************************************************
funcion principal
***********************************************************************************************/
int main(){
    Fecha dia,mes,anio;         //datos de estrcutura
    int dd,mm,aaaa;             //variables
    bool bande=false;
    cout<<"ingrese dia: ";cin>>dia.dd;      //ingresar dia
    cout<<"ingrese mes: ";cin>>mes.mm;      //ingresar mes
    cout<<"ingrese año_: ";cin>>anio.aaaa;  //ingresar año
    bande=ValidarFecha(anio,dia,mes);       //llamdo a funcion
    cout<<"fecha "<<dia.dd<<"/"<<mes.mm<<"/"<<anio.aaaa<<endl;  //mostrar fecha ingresada
    if(bande==true){                    //en caso de que la fceha sea valida mostrar mensaje que lo valida
        cout<<"fecha valida."<<endl;
    }
    else{
        cout<<"fecha no valida.";       //en caso que no fecha no valida
    }
}
