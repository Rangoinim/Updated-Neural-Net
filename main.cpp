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
}