//
// Created by fedya on 23.07.17.
//

#ifndef GAME_LIST_FUNCTIONS_H
#define GAME_LIST_FUNCTIONS_H

#endif //GAME_LIST_FUNCTIONS_H

#include <debug_cpp.h>

template<typename T>
List_Elem<T> & List<T>::first() const{
    SUPER_ASSERT;
    if (count == 0)
        return final();
    return *first_;
}

template<typename T>
List_Elem<T> & List<T>::final() const{
    SUPER_ASSERT;
    return *final_;
}

template<typename T>
List_Elem<T> &List<T>::operator[](unsigned i) {
    SUPER_ASSERT;
    return search_by_index(i);
}

template<typename T>
List_Elem<T>* List_Elem<T>::add_before(T * value){
    add_before(new List_Elem<T> (value));
}

template<typename T>
List_Elem<T>* List_Elem<T>::add_before(List_Elem<T> * elem){
    elem->previous = this->previous;
    elem->next = this;
    this->previous = elem;
}

template<typename T>
List_Elem<T> *List<T>::find(T *value) const {
    SUPER_ASSERT;
    for (List_Elem<T> *elem = first_; elem; elem = elem->next) {
        if (Compare(elem, value) == 0) {
            return elem;
        }
    }
    return NULL;
}

template<typename T>
List_Elem<T> &List<T>::search_by_index(unsigned index) const {
    SUPER_ASSERT;
    List_Elem<T> *element = first_;
    for (unsigned i = 0; i < index; i++, element = element->next) {
        if (i > count)
            return final();
    }
    return *element;
}

template<typename T>
bool List<T>::ok() const {
    return true;
}

template<typename T>
int List<T>::dump() const {
    int i = 0;
    for (List_Elem<T> *elem = first_; elem != NULL; elem = elem->next) {
        printFe("Element %\n", i);
        elem->dump();
        std::cout << "\n";
        i++;
    }
    return 0;
}

template<typename T>
void List<T>::file_dump(FILE *file) const {
    SUPER_ASSERT;
    int k = 0;
    for (List_Elem<T> *elem = first_; elem; elem = elem->next) {
        fprintf(file, "msg%i db ", k++);
        elem->file_dump(file);
    }
}

template<typename T>
void List<T>::label_dump(FILE *file) const {
    SUPER_ASSERT;
    assert(file);
    long file_pointer = ftell(file);
    for (List_Elem<T> *element = first_; element; element = element->next) {
        int source = element->data_->source;
        if (!source)
            continue;
        if (source > 0) {
            //printf("source %i number %i name %s\n", source, element->data_->number, element->data_->name);
            fseek(file, source, SEEK_SET);
            char delta = (char) (element->data_->number - source - 1);
            fprintf(file, "%c", delta);
        } else {
            source = -source;
            //printf("source %i number %i name %s\n", source, element->data_->number, element->data_->name);
            fseek(file, source, SEEK_SET);
            int delta = element->data_->number - source - 4;
            write_int(file, delta);
        }
    }
    fseek(file, file_pointer, SEEK_SET);
}

template<typename T>
void List<T>::append(T *value) {
    List_Elem<T> *elem = new List_Elem<T>(this, value);
    append(elem);
}

template<typename T>
void List<T>::append(List_Elem<T> *elem) {
    SUPER_ASSERT;
    /*if (find(value)) {
        delete value;
        return;
    }*/

    count++;
    if (!first_) {
        first_ = elem;
        last_ = elem;
    } else {
        last_->next = elem;
        elem->previous = last_;
        last_ = elem;
    }
}

