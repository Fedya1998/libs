//
// Created by fedya on 06.05.17.
//

#include <cstdlib>
#include "small_shit_h.h"
#include "list_h.h"

#ifndef NEW_PROC_SMALL_SHIT_H
#define NEW_PROC_SMALL_SHIT_H

#endif //NEW_PROC_SMALL_SHIT_H



class Label{
public:
    char * name;
    size_t number;
    int source;
    Label():name(NULL), number(BAD_LABEL), source (0){};
    ~Label(){
        free(name);
    }

};

template <typename T> int Compare_Label(List_Elem <T> * elem, Label * label){
    return strcmp(elem->m_data->name, label->name);
}



template <typename T> class Buf{
public:
    T * m_data;
    size_t m_current;
    T operator [](int i){
        if (i < 0 || i > m_count) {
            puts("Zhopa in Buf\n");
            return ERR_BAD_INDEX;
        }
        return m_data[i];
    }
    Buf(size_t size):m_count(size){};
    ~Buf(){
        free(m_data);
    }
    size_t get_count(){
        return m_count;
    }
    void append(T value){
        if (m_current >= m_count){
            printf("Buffer overfilled\n");
            return;
        }
        this[m_current++] = value;
    }

private:
    size_t m_count;
};

template <typename T> int Compare_Char_Buf(List_Elem <T> * elem, Buf <char> * str){
    //printf("Prishlo elem %s, str %s\n", elem->m_data->m_data, str->m_data);
    return strcmp(elem->m_data->m_data, str->m_data);
}