#ifndef MULTIME_DINAMIC_H_INCLUDED
#define MULTIME_DINAMIC_H_INCLUDED
#include "nod.h"
#include <iostream>
class multime_dinamic
{
    nod *lst= new nod();
    int nr_elem;
public:
    multime_dinamic();
    multime_dinamic(int, nod*);
    multime_dinamic(const multime_dinamic&);
    ~multime_dinamic();
    nod* get_lst()const;
    int get_nr_elem()const;
    void set_nr_elem(int);
    void convert(nod*);
    multime_dinamic operator+(multime_dinamic&);
    multime_dinamic operator*(multime_dinamic&);
    multime_dinamic operator-(multime_dinamic&);
    friend std::ostream &operator << (std::ostream &output, multime_dinamic &m);
    friend std::istream &operator >> (std::istream &input, multime_dinamic &m);
    friend void n_multimi(multime_dinamic[]);
};

#endif // MULTIME_DINAMIC_H_INCLUDED
