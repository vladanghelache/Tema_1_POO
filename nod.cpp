#include "nod.h"
#include <bits/stdc++.h>
nod::nod(int x, nod*p):nr(x),next(p){}
nod::nod():nr(0),next(nullptr){}
nod::~nod()
{

    if(next!=nullptr)
    {
        delete next;
    }

}
int nod::get_nr()const
{
    return nr;
}
nod* nod::get_next()const
{
    return next;
}
void nod::set_nr(int x)
{
    nr=x;
}
void nod::set_next(nod*p)
{
    next=p;
}
void nod::afisare()const
{
    std::cout<<nr<<" ";
}

