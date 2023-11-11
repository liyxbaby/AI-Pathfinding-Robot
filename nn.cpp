
#include <iostream>
#include <string>
#include <random>
#include <cmath>
#include "config.hpp"
#include "utils.hpp"
#include "nn.hpp"
using namespace std;

MLP::MLP()
{
    nStates = Config::nStates;
    nNeurons = Config::nNeurons;
    nActions = Config::nActions;
    nSamples = Config::nSamples;
    gamma = Config::gamma;
    learningRate = Config::learningRate;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<float> d(0, 1);

    W1 = Utils::create2DArray(nStates,nNeurons);
    b1 = Utils::create2DArray(1,nNeurons);
    W2 = Utils::create2DArray(nNeurons,nActions);
    b2 = Utils::create2DArray(1,nActions);

    batchHiddenLayerOutput = Utils::create2DArray(nSamples,nNeurons);
    batchOutput = Utils::create2DArray(nSamples,nActions);
    batchHiddenLayerNextOutput = Utils::create2DArray(nSamples,nNeurons);
    error  = Utils::create2DArray(nSamples,nActions);
    maxIndices  = Utils::create2DArrayOfIntegers(nSamples,1);
    dW2 = Utils::create2DArray(nNeurons, nActions);
    dW1 = Utils::create2DArray(nStates, nNeurons);
    db2 = Utils::create2DArray(1, nActions);
    db1 = Utils::create2DArray(1, nNeurons);
    action = Utils::create2DArrayOfIntegers(1,1);

    dOutput = Utils::create2DArray(nSamples,nNeurons);

    batchNextOutput = Utils::create2DArray(nSamples,nActions);

    W2Transposed = Utils::create2DArray(nActions, nNeurons);

    batchHiddenLayerOutputTransposed = Utils::create2DArray(nNeurons, nSamples);
    batchStateTransposed = Utils::create2DArray(nStates, nSamples);
    hiddenLayerOutput = Utils::create2DArray(1, nNeurons);
    output = Utils::create2DArray(1, nActions);

    for(int i = 0 ; i < nStates ; i++)
        for(int j = 0 ; j < nNeurons ; j++)
            W1[i][j] = (1*d(gen))/sqrt(nStates+nNeurons);

    for(int i = 0 ; i < nNeurons ; i++)
        for(int j = 0 ; j < nActions ; j++)
            W2[i][j] = (1*d(gen))/sqrt(nNeurons+nActions);
}

void MLP::learn(float** batchState, float** batchNextState, float** batchReward, int** batchAction)
{


    Utils::clear(batchHiddenLayerOutput,nSamples,nNeurons);
    Utils::clear(batchHiddenLayerNextOutput,nSamples,nNeurons);
    Utils::clear(batchOutput,nSamples,nActions);
    Utils::clear(batchNextOutput,nSamples,nActions);
    Utils::clear(error ,nSamples,nActions);

    Utils::clear(dW2,nNeurons, nActions);
    Utils::clear(dW1,nStates, nNeurons);