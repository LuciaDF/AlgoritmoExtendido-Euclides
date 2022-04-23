#include <iostream>
using namespace std;
/*
    a y b son NO negativos
    r ≤ b por el teorema de la division OJIto
    Teorema de la Recursividad => funcion recursiva
    Debe funcionar para todos los casos en general
    El minimo valor de a y b es 0 => Correctitud del algoritmo
        si a = 0 entonces mcd es b, y viceversa.
        Pero si ambos son 0 entonces el mcd es 0.
        a y b son NO negativos

 */

int a1,b1;
void Euclides_e (int a, int b, int*mcd, int* x, int* y)
{
    int x1,y1; // x y y primas
    if (b==0) // a.1 + b.0 = a => mcd
    {
        *mcd=a;
        *x=1;
        *y=0;
    }
    else
    {
        Euclides_e(b, a%b, mcd, x, y); // metodo de recursividad
        // Paso recursivo
        x1=*x;
        y1=*y;
        *x=y1;
        *y=x1-(a/b)*y1; // ecuacion => coeficientes uno por uno
    }
    a1=a;
    b1=b;
    // rectifico a y b para poder hallar y prima siguiente
    
}

int Euclides (int a, int b)
{
    if (b==0)
    {
        return a;
    }
    else
    {
        return Euclides(b, a%b);
    }
}

void MostrarDatos (int a, int b, int x, int y, int mcd)
{
    cout<<"MCD en combinación lineal"<<endl;
    cout<<a<<"( "<<x<<" ) "<<" + "<<b<<"( "<<y<<" ) "<<" = "<<mcd;
    cout<<endl;
}



int main()
{

    int m,xs,ys;
    xs=1;
    ys=0;
    cout<<"Digite dos numeros: ";cin>>a1>>b1;
    
    if (a1<=0 or b1<=0)
    {
        cout<<"Solo numeros positivos. "<<endl;
    }
    else
    {
        m = Euclides(a1, b1);
        
        Euclides_e(a1, b1, &m, &xs, &ys);
        MostrarDatos(a1, b1, xs, ys, m);

    }
   
    return 0;
}
