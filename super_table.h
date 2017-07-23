//
// Created by fedya on 06.05.17.
//

#include <cstdlib>

#ifndef NEW_PROC_SUPER_TABLE_H
#define NEW_PROC_SUPER_TABLE_H

#endif //NEW_PROC_SUPER_TABLE_H


template <typename T1, typename T2> class Super_Table{
public:
    size_t m_count;
    Super_Table(size_t count): m_count(count){
        data1 = (T1 *) calloc(sizeof(T1), count);
        data2 = (T2 *) calloc(sizeof(T2), count);
    }
    ~Super_Table(){
        free(data1);
        free(data2);
    }
    int (*compare1)(T1 val1, T1 val2);
    int (*compare2)(T2 val1, T2 val2);
    int find(T1 param) const{
        for (int i = 0; i < m_count; i++) {
            if (compare1(data1[i], param) == 0)
                return i;
        }
    }
    int find(T2 param) const{
        for (int i = 0; i < m_count; i++) {
            if (compare2(param, data2[i]) == 0)
                return i;
        }
    }
    T1 * data1;
    T2 * data2;
    void dump() const{
        for (int i = 0; i < m_count; i++) {
            std::cout<<data1[i]<<" --- "<<data2[i]<<'\n';
        }
    }
};