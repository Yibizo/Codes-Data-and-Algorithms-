#include <iostream>
#include <string>

using namespace std;

int digit_sum(int n){
    if(n==0){
        return 0;
    }
    return(n%10+digit_sum(n/10));
}

int main(){
    int num;
    cout << "Input number: ";
    cin >> num;
    cout << digit_sum(num) << endl;
}