//
// Created by fedya on 05.05.17.
//

#ifndef NEW_PROC_STACK_FUNCTIONS_H
#define NEW_PROC_STACK_FUNCTIONS_H

#endif //NEW_PROC_STACK_FUNCTIONS_H

#include <cstdio>
#include <iostream>


template <typename T>
void Stack<T>::push(T value){
    m_data[m_count++] = value;

}

template <typename T>
T Stack<T>::pop(){
    return m_data[m_count--];
}

template <typename T>
void Stack<T>::dump() const{
    printf("Stack:\n");
    for(int i = 0; i < m_count; i++){
        printf("\t[%.3i] = ", i);
        std::cout<<m_data[i]<<'\n';
    }
}
