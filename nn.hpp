#include <random>
#ifndef NN_HPP_
#define NN_HPP_


class MLP
{
    public:
        MLP();
    	float  ** W1;
    	float  ** b1;
    	float  ** W2;
    	float  ** b2;
        float gamma;
        float learningRate;
        int W1r;
        int W1c;
        int W2r;
        int W2c;
        int b1r;
        int b1c;
        int b2r;
        int b2c;
        int nStates;
        int nNeurons;
        int nActions;
        int nSamples;
        float  ** batchHiddenLayerOutput;
        float  ** batchOutput;
        float  ** batchNextOutput;
        bool init;
        float  ** batchHiddenLayerNextOutput;
        float  ** target;
        float  ** error;
        int  ** maxIndices;
        float  ** dW2;
        float  ** dW1;
        float  ** db2;
      