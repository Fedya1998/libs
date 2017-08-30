//
// Created by fedya on 06.05.17.
//


#include <cstdlib>
#include <iostream>
#include <fstream>
#include <my_debug.h>
#include <list_h.h>



int write_int(FILE *file, int i);


template<typename T>
class List_Elem {
public:
    List<T> *header_ = NULL;
    T *data_ = NULL;
    List_Elem<T> *next = NULL;
    List_Elem<T> *previous = NULL;

    List_Elem<T>(T *data) : data_(data) {}

    List_Elem<T>(List<T> *header, T *data) : header_(header), data_(data) {}

    List_Elem<T>(List<T> *header) : header_(header) {}

    List_Elem<T>() {}

    void delete_recursively() {
        if (next)
            delete next;
        Gde;
        delete data_;
        delete this;
    }

    ~List_Elem<T>(){
        if (previous)
            previous->next = next;
        if (next)
            next->previous = previous;
        return;
    }


    List_Elem* add_before(T * value);

    List_Elem* add_before(List_Elem<T> * elem);

    bool ok() const{
        return header_ && data_;
    }

    void dump() const{
        printFe("Elem %\nNext %\nData", this, next);
        if (data_)
            data_->dump();
        else
            printf(" (Nil)\n");
    }

    void file_dump(FILE *file) const{
        fprintf(file, "\'%s\'", (char *) data_);
        fprintf(file, ", 0\n");
    }

    friend List_Elem<T> &operator++(List_Elem<T> &element, int) {
        List_Elem<T> *current = &element;
        if (element.next)
            element = *element.next;
        else
            element = *element.header_->final_;
        return *current;
    };

    void operator=(List_Elem<T> &element) {
        this->data_ = element.data_;
        this->next = element.next;
        this->previous = element.previous;
    }

    bool operator==(const List_Elem<T> &right) const{
        if (data_ == (right.data_))
            return true;
        else if (!data_ || !right.data_)
            return false;
        else if (*data_ == *right.data_)
            return true;
        return false;
    }

    bool operator!=(const List_Elem<T> &right) const{
        return !(*this == right);
    }
};


template<typename T>
class List {
//private:
public:
    List_Elem<T> *first_ = NULL;
    List_Elem<T> *last_ = NULL;
    List_Elem<T> *final_ = NULL;

    List_Elem<T> & final() const;

    List_Elem<T> & first() const;

    size_t count = 0;
public:
    List<T>() : final_(new List_Elem<T>) {};

    ~List<T>() {
        delete final_;
        if (!first_)
            return;
        first_->delete_recursively();
    };

    int (*Compare)(List_Elem<T> *, T *);

    void append(T *value);

    void append(List_Elem<T> * elem);

    List_Elem<T> *find(T *value) const;

    List_Elem<T> &search_by_index(unsigned index) const;

    bool ok() const;

    int dump() const;

    void file_dump(FILE *file) const;

    void label_dump(FILE *file) const;

    List_Elem<T> &operator[](unsigned i);
};


#include <list_functions.h>

#ifndef NEW_PROC_LIST_H
#define NEW_PROC_LIST_H
#endif