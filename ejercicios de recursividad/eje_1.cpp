#include <iostream>

using namespace std;

int mcd(int m, int n){
    int r = m%n;
    if(m<0 || n<0){
        throw"illegal negative number/s";
    }
    if(m<n){
        throw"number 'n' is higher than 'm'";
    }
    if(r==0){
        return n;
    }
    return mcd(n,r);
}

int main(){
    int num1,num2;
    cout << "First number: ";
    cin >> num1;
    cout << "Second number: ";
    cin >> num2;
    cout << mcd(num1,num2) << endl;
}