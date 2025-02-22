/***********************************************************
Name: Cory Munselle
Assignment: Final
Purpose: header file for network.cpp
Notes:
***********************************************************/

/* This is a sample header file for a neural network. A few things
 * to note about this file...
 * *** It is only a simple proof-of-concept header file. It does not conform
 *     to all the specifications in your project assignment. It is ONLY meant
 *     a guide to help you think about how you will structure your network.
 *     Your final network will have more functionality than this one.
 * *** There are many ways to structure a neural network. You are free to
 *     structure yours any way you like so long as it follows good programming
 *     practice and is efficient and well structured.
 * *** This file "cheats" and has all parameters in #define. These should be in
 *     a configuration file except for iopairs which you have to find
 *     dynamically by testing your input file
 */

#ifndef NNETWORK_H
#define NNETWORK_H

#include <cctype>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <vector>

using namespace std;

/*
 * The following are some of the things you will put in a configuration file.
 * DO NOT do it like this, put these values, and anything else you need
 * in a cfg file. The purpose of the cfg file is so that if you change
 * the structure of your network, you should not need to recompile.
 * Also, you should not have the number of io pairs specified anywhere,
 * you need to deduce that number from the data file itself.
 */

/* input layer consisting of activations x (neurons) and weights w
   to the hidden layer. these are created as pointers that will be allocated
 * as 1 and 2 dimensional arrays. */
struct inLayer {
    float *x; /*activation for each neuron in the input layer*/
    float **w; /*weights from input layer to hidden layer*/
};

/* hidden layer consisting of activations x (neurons) and weights w
   to the output layer and errors in the hidden neurons. these are created
 * as pointers that will be allocated as 1 and 2 dimensional arrays. */
struct hidLayer {
    float *x; /*activation for each neuron in the hidden layer*/
    float **w; /*weights from input layer to output layer*/
    float *e; /*errors in hidden layer*/
};

/* output layer consisting of activations x (neurons) and 
   errors in the output neurons. these are created as pointers that
 * will be allocated as 1 and 2 dimensional arrays. */
struct outLayer {
    float *x; /*activation for each neuron in the output layer*/
    float *e; /*errors in output layer*/
};

// the structure defining the whole neural network structure
struct nNet {
    inLayer inputLayer;
    hidLayer hiddenLayer;
    outLayer outputLayer;
};

class NNetwork {
public:

    NNetwork();
    ~NNetwork();

    /*
     * These are just debug routines that help you see what's in the
     * network and to make sure it's working right. They do not add
     * to the functionality of the network.
     */
    void displayInputLayerWeights();
    void displayHiddenLayerWeights();
    void displayInputActivations();
    void displayHiddenActivations();
    void displayOutputActivations();
    void displayTrainingInput();
    void displayTrainingOutput();
    void earlyCompleteMessage();

    //this calls all the private training methods
    void train();

    //this loads the validation set and tests the trained network
    void test();

    //this saves the weights when training is done
    void saveweights();

    /* this loads weights from a saved weights file so you can re-load
     a trained network and use it, instead of retraining.*/
    bool loadweights();


private:
    /* this file is for debug purposes. I save my MSE from compute errors so
       I can look at it and see how training is working. This will dramatically
       slow down your network so you should be able to turn this on and off
       as needed or find a smart way to make it aster.*/
    ofstream msefile;

    // basic data for the network. these are initialized in loadCfgParams()
    // or in your constructor or however you want to do it.
    int inUnits, hidUnits, outUnits, ioPairs, maxEpoch, numInput, numOutput, numCorrect;
    float off, on;
    float offSoft, onSoft;
    float learnRate;
    float ee;

    // Contains the parameters from the config file for loading into the above variables
    vector<float> contents;

    // Filename for the data file that the program is going to use
    string filename;

    // Filename of the weights file to save to or load from
    string weightsfn;

    // Set to true if the accuracy check is flipped before the epochs complete
    bool earlyComplete;

    /* holds the data set for training. these are initialized in buildIOData()
       and loaded in loadIOFile() */
    float **inputData, **outputData;

    // a pointer to a neural network. this will be dynamically allocated
    nNet *nNetwork;

    // set-up methods to create and initialize the network and data
    void scanFile();
    static float randomWeight();
    void loadCfgParams();
    void buildInputLayer();
    void buildHiddenLayer();
    void buildOutputLayer();
    void buildIOData();
    void loadIOFile();
    void checkAccuracy();
    // I tried getting Means Squared Error calculated, but it's 3 AM and my brain hurts
    //void mseCalc(int);
    void findWeightsFile();

    /* training methods used in train(). assignActivatons and propigateActivations
       are also used in the test() method. depending on your implementation,
       compute errors may also be used in the test method, but do not use
       adjustWeights in the test method. */
    void assignActivatons(int);
    void propigateActivations();
    void computeErrors(int);
    void adjustWeights();

};

#endif /* NNETWORK_H */


