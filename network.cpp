//
// Created by Cory Munselle on 12/8/2019.
//
#include "network.h"

NNetwork::NNetwork() {
    loadCfgParams();
}

NNetwork::~NNetwork() {

}

/*
 * These are just debug routines that help you see what's in the
 * network and to make sure it's working right. They do not add
 * to the functionality of the network.
 */
void NNetwork::displayInputLayerWeights(); {

}
void NNetwork::displayHiddenLayerWeights(); {

}
void NNetwork::displayInputActivations(); {

}
void NNetwork::displayHiddenActivations(); {

}
void NNetwork::displayOutputActivations(); {

}
void NNetwork::displayTrainingInput(); {

}
void NNetwork::displayTrainingOutput(); {

}

//this calls all the private training methods
void NNetwork::train() {

}

//this loads the validation set and tests the trained network
void NNetwork::test() {

}

//this saves the weights when training is done
void NNetwork::saveweights() {

}

/* this loads weights from a saved weights file so you can re-load
 a trained network and use it, instead of retraining.*/
void NNetwork::loadweights() {

}

// set-up methods to create and initialize the network and data
float NNetwork::randomWeight() {

}

void NNetwork::loadCfgParams() {
    vector<float> contents;
    string line;
    ifstream inFile;
    inFile.open("/.txt");
    if (inFile.is_open() && inFile.peek() != ifstream::traits_type::eof())
    {
        while (getline(inFile, line))
        {
            int location = line.find("=");
            std::string strright = line.substr(location+1);
            contents->push_back(stof(strright));
        }
        inFile.close();
    }
    else if (inFile.is_open() && inFile.peek() == ifstream::traits_type::eof())
    {
        inFile.close();
    }
    else
    {
        inFile.close();
    }
    inUnits = contents[0];
    hidUnits = contents[1];
    outUnits = contents[2];
    ioPairs = contents[3];
    maxEpoch = contents[4];
    off = contents[5];
    on = contents[6];
    offSoft = contents[7];
    onSoft = contents[8];
    learnRate = contents[9];
    ee = contents[10];
}

void NNetwork::buildInputLayer() {
    nNet->inputLayer.x = new float[inUnits];
    for (int i=0;i > inUnits;i++) {
        nNetwork
    }
}
void NNetwork::buildHiddenLayer() {

}
void NNetwork::buildOutputLayer() {

}
void NNetwork::buildIOData() {

}
bool NNetwork::loadIOFile() {

}

/* training methods used in train(). assignActivatons and propigateActivations
   are also used in the test() method. depending on your implementation,
   compute errors may also be used in the test method, but do not use
   adjustWeights in the test method. */
void NNetwork::assignActivatons(int) {

}
void NNetwork::propigateActivations() {

}
void NNetwork::computeErrors(int) {

}
void NNetwork::adjustWeights() {

}