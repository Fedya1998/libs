//
// Created by fedya on 29.06.17.
//

#ifndef GAME_SMALL_SHIT_H_H
#define GAME_SMALL_SHIT_H_H

#endif //GAME_SMALL_SHIT_H_H

enum errors{
    ERR_BAD_INDEX,
    ERROR_EMPTY_LINE = 1,
    ERROR_WRONG_PARENTHESES,
    ERROR_UNDEFINED_FUNCTION,
    ERROR_BAD_TREE,
    ERROR_WRONG_TYPE,
    ERROR_UNDEFINED_VALUE,
    ERROR_UNDEFINED_TYPE,
    ERROR_UNDEFINED_OPERATION,
    ERROR_LOST_LABEL
};

const int BAD_LABEL = 0;


class Label;

//template <typename T> int Compare_Label(List_Elem <T> * elem, Label * label);

template <typename T> class Buf;