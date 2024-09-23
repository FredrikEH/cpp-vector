#ifndef INTVECTOR_H
#define INTVECTOR_H

#include <initializer_list>

class IntVector{
    public:
        IntVector(); //konstruktor utan argument
        IntVector(const IntVector& other); //copy-konstruktor, tar en annan IntVector som argument
        IntVector(const std::initializer_list<int>& ilist); //konstruktor som tar argument
        IntVector(IntVector&& other); //move-konstruktor
        void push_back(int i); //lägger till ett element i IntVector
        int size() const; //funktion för att hämta antal element i array
        ~IntVector(); //destruktor
        int operator[](int i) const;
        const IntVector& operator=(const IntVector& other); //operatoröverlagring av tilldelningsoperatorn, "=" 
        int& operator[](int i);
    private:
        int len; //antal element i vektorn
        int capacity; //max antal element i vektorn
        int* iptr = nullptr; //pekare till första elementet i vektorn
        friend std::ostream& operator<<(std::ostream& os, const IntVector& v); //utskriftsoperator
};

#endif
