#include <iostream>
#include <vector>

using namespace std;

int sumVector(vector<int> inputVector){
    if(inputVector.size() <= 1){
        return inputVector[0];
    }
    else{
        vector<int> slice(inputVector.begin() + 1, inputVector.begin()+inputVector.size());
        return inputVector[0] + sumVector(slice);
    }
}

int main(){
    vector<int> vecArray = {1,2,3,4};
    cout << sumVector(vecArray) << endl;
}