//
// Created by fedya on 05.05.17.
//

#include <cstdlib>

#ifndef NEW_PROC_STACK_H
#define NEW_PROC_STACK_H

#endif //NEW_PROC_STACK_H

template <typename T> class Stack{
public:
    explicit Stack(size_t max_count){
        m_data = (T *)calloc(sizeof(T), max_count);
    }

    ~Stack(){
        free(m_data);
    }

    void push(T value);
    T pop();
    void dump() const;
    //size_t get_count() const
private:
    T *m_data = NULL;
    size_t m_count = 0;
};

#include "stack_functions.h"