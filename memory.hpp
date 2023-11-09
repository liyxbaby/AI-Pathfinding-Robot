#ifndef MEMORY_H__
#define MEMORY_H__
#include <random>

class Memory
{
    public:
        Memory();
        void generateRandomIndices(int** result);
        void sampleStates(float** result, int** indices);
        void sampleNextStates(float** result, int** indices);
   