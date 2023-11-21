#include <iostream>
#include <string>
#include "config.hpp"
#include "utils.hpp"
#include <math.h>
using namespace std;

// FUNCTION FOR DECODING STATES INCOMING FROM UART COMMANDS
void Utils::stateDecoder(float ** state, string command)
{
for (int i=0; i<=Config::nStates; i++)
    if(command[i] == '1')
        state[0][i] = 1;
    else
        state[0][i] = 0;
}

// FUNCTION FOR CREATING AND INITIALIZING A 2D POINTER
float** Utils::create2DArray(int r, int c)
{
    float** array2D = 0;
    array2D = new float*[r];
    for (int h = 0; h < r; h++)
    {
        array2D[h] = new float[c];
        for (int w = 0; w < c; w++)
        {
                array2D[h][w] = 0;
        }
    }
    retu