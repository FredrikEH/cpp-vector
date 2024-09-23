//Fredrik Haupt caha6864

// Labb2, IntVector.cpp – definitioner av icke-triviala medlemsfunktioner

#include <iostream>
#include <initializer_list>
#include <string>
#include "IntVector.h"

//konstruktor utan parameter
IntVector::IntVector() : len(0), capacity(3){
    iptr = new int[capacity];
    for(int i = 0; i < capacity; ++i){
        iptr[i] = 0;
    }
}

//copy-konstruktor, tar en annan IntVector som parameter
IntVector::IntVector(const IntVector& other) : len(other.len), capacity(other.capacity){
    iptr = new int[len]; 
    for(int i = 0; i < len; ++i){
        iptr[i] = other.iptr[i];
    }
}

//konstruktor med initieringslista som parameter
IntVector::IntVector(const std::initializer_list<int>& ilist) : len(0), capacity(static_cast<int>(ilist.size())){
    iptr = new int[capacity];
    for(int j : ilist){
        iptr[len++] = j;
    }
}

//move-konstruktor
IntVector::IntVector(IntVector&& other) : len(other.len), capacity(other.capacity), iptr(other.iptr){
    other.len = 0;
    other.capacity = 0;
    other.iptr = nullptr;    
}

int IntVector::operator[](int i) const{
    //std::cout << "int IntVector::operator[](int i) const{\n";
    return iptr[i];
}

int& IntVector::operator[](int i){
    //std::cout << "int& IntVector::operator[](int i){\n";
    return iptr[i];
}

//operandöverlagring av << (utskriftsoperator)
std::ostream& operator<<(std::ostream& os, const IntVector& v){
    //std::cout << v.len << std::endl;
	for(int i = 0; i < v.len; ++i){
        //std::cout << "hej" << std::endl;
        //os << std::to_string(v.iptr[i]) << " ";
        os << v[i] << " ";
    }
	return os;
}

//operatoröverlagring av "="
const IntVector& IntVector::operator=(const IntVector& other){
    if(&other != this){
        delete[] iptr;
        len = other.len;
        capacity = other.capacity;
        iptr = new int[capacity]; 
        for(int i = 0; i < len; ++i){
            iptr[i] = other.iptr[i];
        }
    }
    return *this;
}

//lägger till ett element i IntVector
void IntVector::push_back(int i){
    //skapa ny större vektor om vekorn är full
    if(len == capacity){
        capacity = capacity * 2;
        int* tptr = new int[capacity];
        //kopiera den gamla vektorn till den nya vektorn
        for(int j = 0; j < len; ++j){
            tptr[j] = iptr[j];
        }
        //avallokera minne
        delete[] iptr;
        iptr = tptr;
    }
    //lägg till elementet sist i vektorn
    iptr[len] = i;
    //utöka len  
    ++len; 
}

//hämtar len
int IntVector::size() const{
    int result = len;
    return result;
}

//destruktor
IntVector::~IntVector(){
    delete[] iptr;
}