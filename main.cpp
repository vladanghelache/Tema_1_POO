#include <iostream>
#include "nod.h"
#include "multime_dinamic.h"

using namespace std;


int main()
{
    nod*ob= new nod(100,nullptr);
    nod*ob2= new nod(101,nullptr);
    nod*ob3= new nod(100,nullptr);
    nod*ob4= new nod(103,nullptr);
    ob->set_next(ob2);
    ob2->set_next(ob3);
    ob3->set_next(ob4);

    multime_dinamic m;
    m.convert(ob);
    cout<<m;
    cout<<endl;
    multime_dinamic n;
    cin>>n;
    cout<<endl;
    cout<<n;
    cout<<endl;
    multime_dinamic reuniune(m+n);
    cout<<"<Reuniunea>"<<endl<<reuniune;
    cout<<endl;
    multime_dinamic intersectie(m*n);

    cout<<"<Intersectia>"<<endl<<intersectie;
    cout<<endl;
    multime_dinamic diferenta1(m-n);
    cout<<"<Diferenta 1>"<<endl<<diferenta1;
    cout<<endl;

    multime_dinamic diferenta2(n-m);
    cout<<"<Diferenta 2>"<<endl<<diferenta2;
    cout<<endl;

    multime_dinamic v[100];
    n_multimi(v);
    multime_dinamic b(v[0]+v[1]);
    cout<<b;
    return 0;
}
