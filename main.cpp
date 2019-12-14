/***********************************************************
Name: Cory Munselle
Assignment: Final
Purpose: Demonstrates proper functionality of the neural network
Notes: Quite a few things to note here. First, saving is done
 automatically when the network successfully predicts output.
 If you want to load the file, just uncomment the loadweights below.
 It also loads up whatever the relevant weights file is based on
 what's currently stored in the config. You can also save and load
 weights manually if you so choose.
***********************************************************/
#include "main.h"

int main(int argc, char **argv) {
    cout << "Creating the network..." << endl;
    NNetwork neuralNet;
    cout << "Network created." << endl;
    cout << endl;

    cout << "Running a dummy test before training..." << endl;
    neuralNet.test();
    cout << "Complete." << endl;
//    neuralNet.displayTrainingInput();
//    neuralNet.displayTrainingOutput();
    neuralNet.displayInputLayerWeights();
    neuralNet.displayHiddenLayerWeights();
    neuralNet.displayInputActivations();
    neuralNet.displayHiddenActivations();
    neuralNet.displayOutputActivations();
//    cout << "Loading weights..." << endl;
//    neuralNet.loadweights();
//    cout << "Weights loaded" << endl;
//    neuralNet.displayInputLayerWeights();
//    neuralNet.displayHiddenLayerWeights();
    neuralNet.displayInputActivations();
//    neuralNet.displayHiddenActivations();
    cout << "Now training..." << endl;
    neuralNet.train();
    cout << "Training complete." << endl;

    cout << "Now testing..." << endl;
    neuralNet.test();
    cout << "Testing complete." << endl;

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