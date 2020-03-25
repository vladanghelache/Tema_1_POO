#ifndef NOD_H_INCLUDED
#define NOD_H_INCLUDED
class nod
{
    int nr;
    nod *next;
public:
    nod(int,nod*);
    nod();
    ~nod();
    int get_nr()const;
    nod* get_next()const;
    void set_nr(int);
    void set_next(nod*);
    void afisare()const;
};


#endif // NOD_H_INCLUDED
