#include <iostream>
#include <random>
 #include "config.hpp"
 #include "utils.hpp"
 #include "memory.hpp"
using namespace std;

Memory::Memory()
{
        counter = 0;
        size = Config::memoryCapacity;
        nSamples = Config::nSamples;
        nNeurons = Config::nNeurons;
        nActions