/***********************************************************
Name: Cory Munselle
Assignment: Final
Purpose: Demonstrates proper functionality of the neural network
Notes:
***********************************************************/
#include "main.h"

int main(int argc, char **argv) {
    cout << "Creating the network..." << endl;
    NNetwork neuralNet;
    cout << "Network created" << endl;
    neuralNet.displayInputLayerWeights();
    neuralNet.displayHiddenLayerWeights();
//    cout << "Loading weights..." << endl;
//    neuralNet.loadweights();
//    cout << "Weights loaded" << endl;
//    neuralNet.displayInputLayerWeights();
//    neuralNet.displayHiddenLayerWeights();
//    neuralNet.displayInputActivations();
//    neuralNet.displayHiddenActivations();
    cout << "now training..." << endl;
    neuralNet.train();
    cout << "training complete" << endl;

    cout << "Now testing..." << endl;
    neuralNet.test();
    cout << "Testing complete" << endl;

//    cout << "Saving weights..." << endl;
//    neuralNet.saveweights();
//    cout << "Weights saved" << endl;

    neuralNet.displayInputLayerWeights();
    neuralNet.displayHiddenLayerWeights();
//    neuralNet.displayInputActivations();
//    neuralNet.displayHiddenActivations();
//    neuralNet.displayOutputActivations();
//    neuralNet.displayTrainingInput();
//    neuralNet.displayTrainingOutput();
}