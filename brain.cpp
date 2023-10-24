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
        MLP network