#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

struct Racional{
    int num;
    int den;
};
/*******************************************************************************
Suma
*******************************************************************************/
Racional Suma(Racional a,Racional b){
    Racional r;
    r.num=(a.num*b.den)+(a.den*b.num);
    r.den=(a.den*b.den);
    return r;
}
/*******************************************************************************
resta
*******************************************************************************/
Racional Resta(Racional a,Racional b){
    Racional r;
    r.num=(a.num*b.den)-(a.den*b.num);
    r.den=(a.den*b.den);
    return r;
}
/*******************************************************************************
producto
*******************************************************************************/
Racional Producto(Racional a,Racional b){
    Racional r;
    r.num=(a.num*b.num);
    r.den=(a.den*b.den);
    return r;
}
/*******************************************************************************
divicion
*******************************************************************************/
Racional Division(Racional a,Racional b){
    Racional r;
    r.num=(a.num*b.den);
    r.den=(a.den*b.num);
    return r;
}
/*******************************************************************************
numerador
*******************************************************************************/
Racional Numerador1(Racional a,Racional b){
    Racional r;
    r.num=(a.num);
    return r;
}
Racional Numerador2(Racional a,Racional b){
    Racional r;
    r.num=(b.num);
    return r;
}
/*******************************************************************************
denominador
*******************************************************************************/
Racional Denominador1(Racional a,Racional b){
    Racional r;
    r.den=(a.den);
    return r;
}
Racional Denominador2(Racional a,Racional b){
    Racional r;
    r.den=(b.den);
    return r;
}
/*******************************************************************************
valor real
*******************************************************************************/
Racional ValorReal1(Racional a,Racional b){
    Racional r;
    r.num=(a.num);
    r.den=(a.den);
    return r;
}
Racional ValorReal2(Racional a,Racional b){
    Racional r;
    r.num=(b.num);
    r.den=(b.den);
    return r;
}
/*******************************************************************************
potencia
*******************************************************************************/
Racional Potencia(Racional a,Racional b){
    Racional r;
    r.num=pow(a.num,b.num);
    r.den=pow(a.den,b.num);
    return r;
}
/*******************************************************************************
principal
*******************************************************************************/
int main(){
    Racional n1,n2,s;
    n1.num=4;
    n1.den=3;
    n2.num=5;
    n2.den=2;
    s=Suma(n1,n2);
    cout<<s.num<<"/"<<s.den<<endl;
    s=Resta(n1,n2);
    cout<<s.num<<"/"<<s.den<<endl;
    s=Producto(n1,n2);
    cout<<s.num<<"/"<<s.den<<endl;
    s=Division(n1,n2);
    cout<<s.num<<"/"<<s.den<<endl;
    s=Numerador1(n1,n2);
    cout<<s.num<<" ";
    s=Numerador2(n1,n2);
    cout<<s.num<<endl;
    s=Denominador1(n1,n2);
    cout<<s.den<<" ";
    s=Denominador2(n1,n2);
    cout<<s.den<<endl;
    s=ValorReal1(n1,n2);
    cout<<s.num<<"/"<<s.den<<endl;
    s=ValorReal2(n1,n2);
    cout<<s.num<<"/"<<s.den<<endl;
    s=Potencia(n1,n2);
    cout<<s.num<<"/"<<s.den<<endl;
}


