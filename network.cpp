//
// Created by Cory Munselle on 12/8/2019.
//
#include "network.h"

NNetwork::NNetwork() {
    srand(time(NULL));
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(4);

    nNetwork = new nNet;

    loadCfgParams();
    buildInputLayer();
    buildHiddenLayer();
    buildOutputLayer();
    buildIOData();
}

NNetwork::~NNetwork() {

}

/*
 * These are just debug routines that help you see what's in the
 * network and to make sure it's working right. They do not add
 * to the functionality of the network.
 */
void NNetwork::displayInputLayerWeights() {
    cout << "Input Layer Weights" << endl;
    for (int i=0;i < inUnits+1; i++) {
        for (int j=0;j < hidUnits; j++) {
           cout << nNetwork->inputLayer.w[i][j] << " ";
        }
        cout << endl;
    }
}
void NNetwork::displayHiddenLayerWeights() {
    cout << "Hidden Layer Weights" << endl;
    for (int i=0;i < hidUnits+1; i++) {
        for (int j=0;j < outUnits; j++) {
            cout << nNetwork->hiddenLayer.w[i][j] << " ";
        }
        cout << endl;
    }
}
void NNetwork::displayInputActivations() {
    

}
void NNetwork::displayHiddenActivations() {

}
void NNetwork::displayOutputActivations() {

}
void NNetwork::displayTrainingInput() {

}
void NNetwork::displayTrainingOutput() {

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
    return (rand()) / (RAND_MAX + 1.0) + (rand() % 2) - 1;
}

void NNetwork::loadCfgParams() {
    vector<float> contents;
    string line;
    ifstream inFile;
    inFile.open("config.txt");
    if (inFile.is_open() && inFile.peek() != ifstream::traits_type::eof())
    {
        while (getline(inFile, line))
        {
            int location = line.find("=");
            string strright = line.substr(location+1);
            contents.push_back(stof(strright));
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
    //cout << inUnits << ", " << hidUnits << ", " << outUnits << ", " << ioPairs << endl;
}

void NNetwork::buildInputLayer() {
    cout << "hey" << endl;
    nNetwork->inputLayer.x = new float[inUnits+1];
    nNetwork->inputLayer.w = new float*[inUnits+1];
    for (int i=0;i < inUnits+1; i++) {
        nNetwork->inputLayer.w[i] = new float[hidUnits];
    }
    cout << "dude" << endl;
    //bias node
    nNetwork->inputLayer.x[inUnits] = 1.0;
    for (int i=0;i < inUnits+1; i++) {
        for (int j=0; j < hidUnits; j++) {
            nNetwork->inputLayer.w[i][j] = randomWeight();
            cout << nNetwork->inputLayer.w[i][j] << endl;
        }
    }
    cout << "sup" << endl;
}
void NNetwork::buildHiddenLayer() {
    cout << "does" << endl;
    nNetwork->hiddenLayer.x = new float[hidUnits+1];
    nNetwork->hiddenLayer.w = new float*[hidUnits+1];
    nNetwork->hiddenLayer.e = new float[hidUnits];
    for (int i=0;i < hidUnits+1; i++) {
        nNetwork->hiddenLayer.w[i] = new float[outUnits];
    }
    cout << "this" << endl;
    //bias node
    nNetwork->hiddenLayer.x[hidUnits] = 1.0;
    for (int i=0;i < hidUnits+1; i++) {
        for (int j=0; j < outUnits; j++) {
            nNetwork->hiddenLayer.w[i][j] = randomWeight();
            cout << nNetwork->hiddenLayer.w[i][j] << endl;
        }
    }
    cout << "work" << endl;
}
void NNetwork::buildOutputLayer() {

}
void NNetwork::buildIOData() {

}
bool NNetwork::loadIOFile() {
    return false;
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