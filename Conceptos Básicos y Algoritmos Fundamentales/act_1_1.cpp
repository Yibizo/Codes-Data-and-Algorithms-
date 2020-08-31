#include <iostream>

using namespace std;

//O(n)
int sumaIterativa(int n){
    int sum = 0;//O(1)
    int loops = n;//O(1)
    for(int i=0;i<loops;i++){//O(n+1)
        sum += n;//O(1)
        n--;//O(1)
    }
    return sum;//O(1)
}

//O(n)
int sumaRecursiva(int n){
    if(n != 0){//O(n+1)
        return n + sumaRecursiva(n-1);//O(n)
    }
    return 0;//O(1)
}

//O(1)
int sumaDirecta(int n){
    int sum = (n*(n+1))/2;//O(1)
    return sum;//O(1)
}

int main(){
    int num;
    cout << "Ingresar numero: ";
    cin >> num;

    cout << "Suma Iterativa: " << sumaIterativa(num) << endl;
    cout << "Suma Recursiva: " << sumaRecursiva(num) << endl;
    cout << "Suma Directa: " << sumaDirecta(num) << endl;
}