//
// Created by Cory Munselle on 11/26/2019.
//
#include "main.h"

int main(int argc, char **argv) {
    NNetwork neuralNet;
    /*if (argc > 1) {
        filename = argv[1];
        if (dumpToArray(filename, &contents)) {
            config.inUnits = contents[0];
            config.hidUnits = contents[1];
            config.outUnits = contents[2];
            config.ioPairs = contents[3];
            config.maxEpoch = contents[4];
            config.off = contents[5];
            config.on = contents[6];
            config.offSoft = contents[7];
            config.onSoft = contents[8];
            config.learnRate = contents[9];
            config.ee = contents[10];
        }
        cout << setprecision(1) << config.inUnits << endl;
        cout << setprecision(1) << config.hidUnits << endl;
        cout << setprecision(1) << config.outUnits << endl;
        cout << setprecision(1) << config.ioPairs << endl;
        cout << setprecision(1) << config.maxEpoch << endl;
        cout << setprecision(1) << config.off << endl;
        cout << setprecision(1) << config.on << endl;
        cout << setprecision(1) << config.offSoft << endl;
        cout << setprecision(1) << config.onSoft << endl;
        cout << setprecision(2) << config.learnRate << endl;
        cout << setprecision(10) << config.ee << endl;
        }*/
    cout << "hey gamers" << endl;
    neuralNet.displayInputLayerWeights();
    neuralNet.displayHiddenLayerWeights();
}