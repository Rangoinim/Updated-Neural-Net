//
// Created by Cory Munselle on 11/26/2019.
//
#include "main.h"

int main(int argc, char **argv) {
    if (argc > 1) {
        filename = argv[1];
        }
    NNetwork neuralNet;
    neuralNet.displayInputLayerWeights();
    neuralNet.displayHiddenLayerWeights();
    cout << "Saving weights..." << endl;
    neuralNet.saveweights();
    cout << "Weights saved" << endl;
    neuralNet.displayInputActivations();
    neuralNet.displayHiddenActivations();
    cout << "now training..." << endl;
    neuralNet.train();
    cout << "training complete" << endl;
    neuralNet.displayInputLayerWeights();
    neuralNet.displayHiddenLayerWeights();
    neuralNet.displayInputActivations();
    neuralNet.displayHiddenActivations();
    neuralNet.displayOutputActivations();
    neuralNet.displayTrainingInput();
    neuralNet.displayTrainingOutput();
}