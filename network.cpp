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
    cout << "Input Activations" << endl;
    for (int i=0; i < inUnits+1; i++) {
        cout << nNetwork->inputLayer.x[i] << " ";
    }
    cout << endl;
}

void NNetwork::displayHiddenActivations() {
    cout << "Hidden Activations" << endl;
    for (int i=0; i < hidUnits+1; i++) {
        cout << nNetwork->hiddenLayer.x[i] << " ";
    }
    cout << endl;
}
void NNetwork::displayOutputActivations() {
    cout << "Output Activations" << endl;
    for (int i=0; i < outUnits; i++) {
        cout << nNetwork->outputLayer.x[i] << " ";
    }
    cout << endl;
}
void NNetwork::displayTrainingInput() {
    cout << "Training Input" << endl;
    for (int i=0;i < ioPairs; i++) {
        for (int j=0;j < numInput; j++) {
            cout << inputData[i][j] << " ";
        }
        cout << endl;
    }
}
void NNetwork::displayTrainingOutput() {
    cout << "Training Output" << endl;
    for (int i=0;i < ioPairs; i++) {
        for (int j=0;j < numOutput; j++) {
            cout << outputData[i][j] << " ";
        }
        cout << endl;
    }
}

//this calls all the private training methods
void NNetwork::train() {
    for (int i=0; i < maxEpoch; i++) {
        for (int j=0; j < ioPairs; j++) {
            assignActivatons(j);
            propigateActivations();
            computeErrors(j);
            adjustWeights();
        }
    }

}

//this loads the validation set and tests the trained network
void NNetwork::test() {
    for (int i=0; i < ioPairs; i++) {
        assignActivatons(i);
        propigateActivations();
        displayOutputActivations();
        computeErrors(i);
    }
}

//this saves the weights when training is done
void NNetwork::saveweights() {
    ofstream myfile;
    myfile.open("networkWeights.txt", ios::in | ios::trunc);
    if (myfile.is_open()) {
        for (int i = 0; i < inUnits + 1; i++) {
            for (int j = 0; j < hidUnits; j++) {
                myfile << fixed << setprecision(4) << nNetwork->inputLayer.w[i][j];
                if (j < hidUnits - 1) {
                    myfile << " ";
                }
            }
            myfile << "\n";
        }
        for (int i = 0; i < hidUnits + 1; i++) {
            for (int j = 0; j < outUnits; j++) {
                myfile << fixed << setprecision(4) << nNetwork->hiddenLayer.w[i][j];
                if (j < outUnits - 1) {
                    myfile << " ";
                }
            }
            myfile << "\n";
        }
    }
   myfile.close();
}

/* this loads weights from a saved weights file so you can re-load
 a trained network and use it, instead of retraining.*/
void NNetwork::loadweights() {
    ifstream weightsFile;
    weightsFile.open("networkWeights.txt");
    string line, temp;
    int col = 0;
    if (weightsFile.is_open() && weightsFile.peek() != ifstream::traits_type::eof()) {
        for (int i = 0; i < inUnits + 1; i++) {
            getline(weightsFile, line);
            for (int j = 0; j < line.size(); j++) {
                if (line[j] != ' ') {
                    temp += line[j];
                    if (j == line.size() - 1) {
                        nNetwork->inputLayer.w[i][col] = stof(temp);
                        temp.clear();
                        col++;
                    }
                } else {
                    nNetwork->inputLayer.w[i][col] = stof(temp);
                    temp.clear();
                    col++;
                }
            }
            col = 0;
            temp.clear();
        }
        col = 0;
        temp.clear();
        for (int i = 0; i < hidUnits + 1; i++) {
            getline(weightsFile, line);
            for (int j = 0; j < line.size(); j++) {
                if (line[j] != ' ') {
                    temp += line[j];
                    if (j == line.size() - 1) {
                        nNetwork->hiddenLayer.w[i][col] = stof(temp);
                        temp.clear();
                        col++;
                    }
                } else {
                    nNetwork->hiddenLayer.w[i][col] = stof(temp);
                    temp.clear();
                    col++;
                }
            }
            col = 0;
            temp.clear();
        }
        weightsFile.close();
    }
    else if (weightsFile.is_open() && weightsFile.peek() == ifstream::traits_type::eof()) {
        weightsFile.close();
    }
    else {
        weightsFile.close();
    }
}
//PRIVATE FUNCTIONS

void NNetwork::scanFile() {
    string line;
    int spaceCount = 0;
    int totalCount = 0;
    ifstream inFile;
    inFile.open(filename);
    if (inFile.is_open() && inFile.peek() != ifstream::traits_type::eof())
    {
        while (getline(inFile, line))
        {
            if (spaceCount == 0) {
                for (int i = 0; i < line.size(); i++) {
                    numInput = 0;
                    if (line[i] == ' ') {
                        spaceCount++;
                    }
                }
                numInput = spaceCount + 1;
            }
            totalCount++;
        }
        spaceCount = 0;
        for (int i=0; i < line.size(); i++) {
            if (line[i] == ' ') {
                spaceCount++;
            }
        }
        numOutput = spaceCount+1;
        ioPairs = (totalCount / 2);
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
            int location = line.find('=');
            string token = line.substr(location+1);
            if (isalpha(token[0])) {
                filename = token;
            }
            else {
                contents.push_back(stof(token));
            }
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
    maxEpoch = contents[3];
    off = contents[4];
    on = contents[5];
    offSoft = contents[6];
    onSoft = contents[7];
    learnRate = contents[8];
    ee = contents[9];
    //cout << inUnits << ", " << hidUnits << ", " << outUnits << ", " << ioPairs << endl;
}

void NNetwork::buildInputLayer() {
    nNetwork->inputLayer.x = new float[inUnits+1];
    nNetwork->inputLayer.w = new float*[inUnits+1];
    for (int i=0;i < inUnits+1; i++) {
        nNetwork->inputLayer.w[i] = new float[hidUnits];
    }
    //bias node
    for (int i=0; i < inUnits+1; i++) {
        nNetwork->inputLayer.x[i] = 1.0;
    }
    for (int i=0;i < inUnits+1; i++) {
        for (int j=0; j < hidUnits; j++) {
            nNetwork->inputLayer.w[i][j] = randomWeight();
            //cout << nNetwork->inputLayer.w[i][j] << endl;
        }
    }
}
void NNetwork::buildHiddenLayer() {
    nNetwork->hiddenLayer.x = new float[hidUnits + 1];
    nNetwork->hiddenLayer.w = new float *[hidUnits + 1];
    nNetwork->hiddenLayer.e = new float[hidUnits + 1];
    for (int i = 0; i < hidUnits + 1; i++) {
        nNetwork->hiddenLayer.w[i] = new float[outUnits];
    }
    //bias node
    for (int i = 0; i < hidUnits + 1; i++) {
        nNetwork->hiddenLayer.x[i] = 1.0;
    }
    for (int i = 0; i < hidUnits + 1; i++) {
        for (int j = 0; j < outUnits; j++) {
            nNetwork->hiddenLayer.w[i][j] = randomWeight();
            //cout << nNetwork->hiddenLayer.w[i][j] << endl;
        }
    }
}
void NNetwork::buildOutputLayer() {
    nNetwork->outputLayer.x = new float[outUnits];
    nNetwork->outputLayer.e = new float[outUnits];
}
void NNetwork::buildIOData() {
    scanFile();
    inputData = new float *[ioPairs];
    for (int i = 0; i < ioPairs; i++) {
        inputData[i] = new float[numInput];
    }
    outputData = new float *[ioPairs];
    for (int i = 0; i < ioPairs; i++) {
        outputData[i] = new float[numOutput];
    }
    if (loadIOFile()) {
        cout << "you did it" << endl;
    }
    else {
        cout << "uh oh" << endl;
    }
}
bool NNetwork::loadIOFile() {
    bool success = false;
    string line;
    ifstream inFile;
    inFile.open(filename);
    if (inFile.is_open() && inFile.peek() != ifstream::traits_type::eof())
    {
        int col = 0;
        for(int i = 0; i < ioPairs; i++){
            getline(inFile, line);
            for(int j = 0; j < line.size(); j++){
                if(line[j] != ' '){
                    inputData[i][col] = line[j] - '0';
                    //cout << inputData[i][col] << " ";
                    col++;
                }
            }
            col = 0;
            //cout << endl;
        }
        for(int i = 0; i < ioPairs; i++){
            getline(inFile, line);
            for(int j = 0; j < line.size(); j++){
                if(line[j] != ' '){
                    outputData[i][col] = line[j] - '0';
                    //cout << outputData[i][col] << " ";
                    col++;
                }
            }
            col = 0;
            //cout << endl;
        }
        inFile.close();
        success = true;
    }
    else if (inFile.is_open() && inFile.peek() == ifstream::traits_type::eof())
    {
        inFile.close();
    }
    else
    {
        inFile.close();
    }
    return success;
}

/* training methods used in train(). assignActivatons and propigateActivations
   are also used in the test() method. depending on your implementation,
   compute errors may also be used in the test method, but do not use
   adjustWeights in the test method. */
void NNetwork::assignActivatons(int j) {
    for (int i=0;i < inUnits; i++) {
        nNetwork->inputLayer.x[i] = inputData[j][i];
    }
}
void NNetwork::propigateActivations() {
    float sum = 0.0;
    for (int i=0;i < hidUnits; i++) {
        for (int j=0; j < inUnits+1; j++) {
            sum = sum + (nNetwork->inputLayer.x[j] * nNetwork->inputLayer.w[j][i]);
        }
        //sigmoid me captain
        nNetwork->hiddenLayer.x[i] = 1.0 / (1.0 + pow(ee, -sum));
        sum = 0.0;
    }
    sum = 0.0;
    for (int i=0; i < outUnits; i++) {
        for (int j=0; j < hidUnits+1; j++) {
            sum = sum + (nNetwork->hiddenLayer.x[j] * nNetwork->hiddenLayer.w[j][i]);
        }
        //sigmoid round two
        nNetwork->outputLayer.x[i] = 1.0 / (1.0 + pow(ee, -sum));
        sum = 0.0;
    }
}
void NNetwork::computeErrors(int current) {
    float sum = 0.0;
    for (int i=0; i < outUnits; i++) {
        nNetwork->outputLayer.e[i] = nNetwork->outputLayer.x[i] * ((1.0 - nNetwork->outputLayer.x[i]) * (outputData[current][i] - nNetwork->outputLayer.x[i]));
    }
    for (int j=0; j < hidUnits; j++) {
        for (int i=0; i < outUnits; i++) {
            sum = sum + nNetwork->outputLayer.e[i] * nNetwork->hiddenLayer.w[j][i];
        }
        nNetwork->hiddenLayer.e[j] = (nNetwork->hiddenLayer.x[j] * (1 - nNetwork->hiddenLayer.x[j])) * sum;
        sum = 0.0;
    }
}
void NNetwork::adjustWeights() {
    for (int i = 0; i < hidUnits+1; i++) {
        for (int j = 0; j < outUnits; j++) {
            nNetwork->hiddenLayer.w[i][j] = nNetwork->hiddenLayer.w[i][j] + (learnRate * nNetwork->outputLayer.e[j] * nNetwork->hiddenLayer.x[i]);
        }
    }
    for (int i = 0; i < inUnits; i++) {
        for (int j = 0; j < hidUnits; j++) {
            //cout << nNetwork->inputLayer.w[i][j] << endl;
            nNetwork->inputLayer.w[i][j] = nNetwork->inputLayer.w[i][j] + (learnRate * nNetwork->hiddenLayer.e[j] * nNetwork->inputLayer.x[i]);
            //cout << nNetwork->inputLayer.w[i][j] << endl;
        }
    }
}

