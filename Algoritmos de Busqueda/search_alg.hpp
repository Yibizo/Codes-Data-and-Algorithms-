#include <iostream>
#include <vector>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <algorithm>

using namespace std;

template <class T>
class Busqueda{
protected:
    vector<T> elementos = {1,9,6,3,7,8,4,12,15};

public:
    Busqueda() = default;
    void sortVector(){
        sort(elementos.begin(),elementos.end());
    }
    T sizeVec(){
        return elementos.size();
    }
    T getVec(){
        return elementos;
    }/*
    void randomGenerate(){
        int randomNum;
        elementos.reserve(10);
        srand((unsigned int)time(NULL)); //random seed everytime
        for(int i=0;i<elementos.size();i++){
            randomNum = rand() % 10 + 1;
            while(find(elementos.begin(),elementos.end(),randomNum) != elementos.end()){
                randomNum = rand() % 10 + 1;
            }
            elementos[i] = randomNum;
        }
        for(int i=0;i<elementos.size();i++){
            cout << elementos[i] << ", " << endl;
        }
    }*/
    T getSequential(int n){
        int final = -1;
        for(int i=0;i<elementos.size();i++){
            if(n == elementos[i]){
                final = i;
                break;
            }
            else if(i == n-1){
                break;
            }
        }
        return final;
    }
    T getSequentialOne(int n){
        sortVector();
        return getSequential(n);
    }
    T getSequentialTwo(int n){
        sortVector();
        int final = -1;
        for(int i=0;i<elementos.size();i+=2){
            if(n == elementos[i]){
                final = i;
            }
            else if(n < elementos[i]){
                if(n == elementos[i-1]){
                    final = i-1;
                    break;
                }
                else{
                    break;
                }
            }
        }
        return final;
    }
    T getBinary(vector<int> _elementos,int left, int right, int n){
        if (right >= left) { 
            int middle = left + (right - left) / 2;
            if (_elementos[middle] == n){
                return middle;
            }   
            if (_elementos[middle] > n){
                return getBinary(_elementos, left, middle - 1, n);
            }
            return getBinary(_elementos, middle + 1, right, n);
        }
        return -1; 
    }

};