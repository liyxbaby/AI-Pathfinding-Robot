#include "config.hpp"
#include "nn.hpp"
#include "memory.hpp"
#include "utils.hpp"
#include "brain.hpp"
#include <iostream>

DQN::DQN()
{
        nStates  = Config:: nStates;
        nNeurons = Config:: nNeurons;
        nActions = Config:: nActions;
        nSamples = Config:: nSamples;
        Memory memory;
        MLP network;
        lastState = Utils::create2DArray(1,nStates);
        lastAction = Utils::create2DArrayOfIntegers(1,1);
        lastReward = Utils::create2DArray(1,1);
        action = 0;
        batchState = Utils::create2DArray(nSamples, nStates);
        batchNextState = Utils::create2DArray(nSa