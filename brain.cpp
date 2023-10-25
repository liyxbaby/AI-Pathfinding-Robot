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
        batchNextState = Utils::create2DArray(nSamples, nStates);
        batchReward = Utils::create2DArray(nSamples, 1);
        batchAction = Utils::create2DArrayOfIntegers(nSamples, 1);
        randomIndices = Utils::create2DArrayOfIntegers(nSamples, 1);
}

int DQN::update(float** reward, float** newState)
{
	//std::cout << "holy fucking shit" << std::endl;

    if(memory.cou