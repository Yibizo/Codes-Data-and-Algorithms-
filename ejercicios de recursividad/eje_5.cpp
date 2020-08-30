#include <iostream>

using namespace std;

int reverse(int n,int r){
	if (n < 10){
		return (r*10+n);
	}
	else{
		return reverse(n/10,r*10+n%10);
	}
}

int main(){
    int num;
    cout << "Enter number: ";
    cin >> num;
    cout << reverse(num,0) << endl;
}