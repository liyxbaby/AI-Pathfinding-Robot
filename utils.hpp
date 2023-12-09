#ifndef UTILS_H_
#define UTILS_H_
#include <string>
#include "xil_types.h"

class Utils
{
    public:
        static void    stateDecoder(float ** state, std::string command);
        static float** create2DArray(int r, int c);
        static void    clear(float** x, int r, int c);
        static void    clearIntegers(int** x, int r, int c);
        static int**   create2DArrayOfIntegers(int r, int c);
        static void    dot(float** result, float ** x, float ** y, int m, int n, int p);
        static void    sum(float ** x, float ** y, int r, int c);
        static void    copy(float ** x, float ** y, int r, int c);
        static void    distance(float** result, float ** x,  int r, int c);
        static void    relu(float ** x, int 