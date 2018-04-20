#include "iostream"
#include "stdio.h"
#include "math.h"
#include <cmath>

using namespace std;

double F(double x){
    return ((pow(x,2))+x-1); //Setear la función a ocupar, tu f(x)
}
//a ->  Limite inferior
//b ->  Limite superior
//eps -> epsilon / criterio de 
//l0 = b-a; abs(Pn-P)<=l0/2^n<=eps
//n>= log2(l0/eps)
double biseccion(double a, double b, double eps ){
    int cont = 1;
    int MAXIT = 100;
    double c, error;
    double fc, fa, fb;
    while(cont<=MAXIT){
        c=(a+b)/2;
        fa = F(a);
        fb = F(b);
        fc = F(c);
        error = abs(b-c);
        cout << "a= " << a << ", b= " << b << ", c= " << c << "\n";
        cout << "fa= " << fa << ", fb= " << fb << ", fc= " << fc << "\n";
        cout << "================================================" << "\n";
        if (fc == 0 || error < eps){
            return c;
        }
        if ((fa*fc)>0){
            a=c;
        }else{
            b=c;
        }
        cont = cont+1;
    }
    return c;
}

int main(){
    cout << biseccion(0,1,0.001) << "\n";
    return 0;
}