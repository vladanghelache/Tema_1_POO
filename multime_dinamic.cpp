#include "nod.h"
#include "multime_dinamic.h"
#include <bits/stdc++.h>

multime_dinamic::multime_dinamic(int x, nod* p):nr_elem(x),lst(p) {}
multime_dinamic::multime_dinamic():nr_elem(0),lst(nullptr) {}
multime_dinamic::multime_dinamic(const multime_dinamic& m)
{
    nr_elem = m.nr_elem;
    nod* p = m.get_lst();
    nod* q= new nod(p->get_nr(),nullptr);
    p=p->get_next();
    lst=q;
    while(p!=nullptr)
    {
        nod* elem=new nod(p->get_nr(),nullptr);
        p=p->get_next();
        q->set_next(elem);
        q=q->get_next();
    }



}
multime_dinamic::~multime_dinamic()
{

    if (lst!=nullptr)
    {
        delete lst;
    }

}

nod* multime_dinamic::get_lst()const
{
    return lst;
}
int multime_dinamic::get_nr_elem()const
{
    return nr_elem;
}
void multime_dinamic::set_nr_elem(int x)
{
    this->nr_elem=x;
}

void multime_dinamic::convert(nod*lista)
{
    this->lst=lista;
    this->nr_elem=0;
    while(lista!=nullptr)
    {
        nod*q=lista;
        this->nr_elem+=1;
        while(q->get_next()!=nullptr)
        {

            if(lista->get_nr()==q->get_next()->get_nr())
            {
                nod* elem=q->get_next();
                q->set_next(elem->get_next());
                elem->set_next(nullptr);
                delete elem;
            }
            else
                q=q->get_next();
        }
        lista=lista->get_next();
    }
}
std::istream &operator >> (std::istream &input, multime_dinamic &m)
{
    int x;
    std::cout<<"Introduceti numarul de elemente: ";
    input>>m.nr_elem;
    std::cout<<"Introduceti elementele: ";
    input>>x;
    nod*p= new nod(x,nullptr);
    m.lst=p;

    for(int i=0; i<m.nr_elem-1; i++)
    {
        input>>x;
        nod*q= new nod(x,nullptr);
        p->set_next(q);
        p=p->get_next();
    }
    return input;
}
std::ostream &operator << (std::ostream &output, multime_dinamic &m)
{
    nod* p=m.get_lst();
    output<<"Multimea: ";
    while(p!=nullptr)
    {
        p->afisare();
        p=p->get_next();
    }
    output<<std::endl<<"Numarul de elemente: "<<m.nr_elem<<std::endl;
    return output;
}
void n_multimi(multime_dinamic v[])
{
    std::cout<<"Introduceti numarul de multimi: ";
    int n;
    std::cin>>n;
    for(int i=0;i<n;i++)
        std::cin>>v[i];

    for(int i=0;i<n;i++)
        std::cout<<v[i];
}
multime_dinamic multime_dinamic::operator+(multime_dinamic &m)
{
    nod*q=this->get_lst();
    nod* elem1=new nod(q->get_nr(),nullptr);

    multime_dinamic reun(this->get_nr_elem(),elem1);
    q=q->get_next();
    while(q!=nullptr)
    {
        nod* elem2=new nod(q->get_nr(),nullptr);
        elem1->set_next(elem2);
        elem1=elem1->get_next();
        q=q->get_next();
    }

    nod* p=m.get_lst();
    while(p!=nullptr)
    {
        q=this->get_lst();
        int ok=1;
        while(q!=nullptr)
        {
            if(q->get_nr()==p->get_nr())
                ok=0;
            q=q->get_next();
        }
        if (ok==1)
        {
            nod* elem2=new nod(p->get_nr(),nullptr);
            elem1->set_next(elem2);
            elem1=elem1->get_next();
            reun.set_nr_elem(reun.get_nr_elem()+1);
        }
        p=p->get_next();
    }
    elem1->set_next(nullptr);

    return reun;
}
multime_dinamic multime_dinamic::operator*(multime_dinamic &m)
{
    nod* elem1=new nod;
    multime_dinamic inter(0,elem1);
    int n=0;
    nod* p=this->get_lst();

    while(p!=nullptr)
    {
        nod* q=m.get_lst();
        while(q!= nullptr)
        {
            if(p->get_nr()==q->get_nr())
            {
                if(n==0)
                {
                    elem1->set_nr(p->get_nr());
                    n++;
                }
                else
                {
                    nod* elem2=new nod(p->get_nr(),nullptr);
                    elem1->set_next(elem2);
                    elem1=elem1->get_next();
                    n++;
                }

            }
            q=q->get_next();
        }
        p=p->get_next();

    }
    inter.set_nr_elem(n);
    return inter;
}
multime_dinamic multime_dinamic::operator-(multime_dinamic &m)
{
    nod* elem1=new nod;
    multime_dinamic difer(0,elem1);
    int n=0;
    nod* p=this->get_lst();

    while(p!=nullptr)
    {
        nod* q=m.get_lst();
        int ok=1;
        while(q!= nullptr)
        {
            if(p->get_nr()==q->get_nr())
            {
                ok=0;

            }
            q=q->get_next();
        }
        if(ok==1)
        {
            if(n==0)
            {
                elem1->set_nr(p->get_nr());
                n++;
            }
            else
            {
                nod* elem2=new nod(p->get_nr(),nullptr);
                elem1->set_next(elem2);
                elem1=elem1->get_next();
                n++;
            }
        }
        p=p->get_next();

    }
    difer.set_nr_elem(n);

    return difer;
}
