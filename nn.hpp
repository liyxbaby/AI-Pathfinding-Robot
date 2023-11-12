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
        float gamm