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

// FUNC