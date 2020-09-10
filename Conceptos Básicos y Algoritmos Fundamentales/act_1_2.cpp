/*
Este programa ordena y busca elementos en vectores ordenados y no ordenados
Autor: Diego Mejía Suárez - A01024228
Fecha de creación: 08/09/2020
*/

#include <bits/stdc++.h>

using namespace std;

//ordena el vector tomando un valor, separandolo en una segunda lista y buscar un numero que sea mayor
void ordenaInsercion(vector<int> &vectorSort_){
    int arraySize = vectorSort_.size();
    for(size_t i=1;i<arraySize;i++){
        int comparisonNum = vectorSort_[i];
        int j = i-1;
        while(j>=0 && vectorSort_[j]>comparisonNum){
            vectorSort_[j+1] = vectorSort_[j];
            j = j-1;
        }
        vectorSort_[j+1] = comparisonNum;
    }
}

//compara 2 elementos y cambian posiciones si el segundo es mayor que el primero
void ordenaBurbuja(vector<int> &vectorSort_){
    int arraySize = vectorSort_.size();
    for(size_t i=0;i<arraySize-1;i++){
        for(size_t j=0;j<arraySize-i-1;j++){
            //comparison to check if swap is made
            if(vectorSort_[j]>vectorSort_[j+1]){
                //swap values
                int temp=vectorSort_[j];
                vectorSort_[j]=vectorSort_[j+1];
                vectorSort_[j+1]=temp;
            }
        }
    }
}

//funcion utilizada en quick sort para la seleccion del punto de pivote del que se parte la busqueda 
int puntoParticion(vector<int> &vectorSort_,int low,int high){
    int pivotPoint = vectorSort_[high];
        int i = (low-1);

        for(size_t j = low;j<=high-1;j++){
            if(vectorSort_[j]<pivotPoint){
                i++;
                int temp1 = vectorSort_[i];
                vectorSort_[i] = vectorSort_[j];
                vectorSort_[j] = temp1;
            }
        }
        int temp2 = vectorSort_[i+1];
        vectorSort_[i+1] = vectorSort_[high];
        vectorSort_[high] = temp2;
        return i+1;
}

//usando el punto pivote, y apuntadores de ambos lados se acomodan los elementos de acuerdo a sus valores
void ordenaQuick(vector<int> &vectorSort_,int low,int high){
    if(low<high){
        int partitionValue = puntoParticion(vectorSort_,low,high);
        //sort both elements before and after the partition value
        ordenaQuick(vectorSort_,low,partitionValue-1);
        ordenaQuick(vectorSort_,partitionValue+1,high);
    }
}

//busca los elementos del vector por 1 paso de manera lineal
int busqSecuencial(vector<int> vectorSearch_,int n){
    int final = -1;
    for(size_t i=0;i<vectorSearch_.size();i++){
        if(n == vectorSearch_[i]){
            final = i;
            break;
        }
    }
    return final;
}

//inicia desde la mitad del vector, y compara ambos lados para determinar donde se podria encontrar el valor, recursivamente llegando al elemento
int busqBinaria(vector<int> vectorSearch_,int left,int right,int n){
    if (right >= left) { 
        int middle = left + (right - left) / 2;
        if (vectorSearch_[middle] == n){
            return middle;
        }   
        if (vectorSearch_[middle] > n){
            return busqBinaria(vectorSearch_, left, middle - 1, n);
        }
        return busqBinaria(vectorSearch_, middle + 1, right, n);
    }
    return -1; 
}

int main(){
    //definir tamaño de vector
    cout << "Ingresar tamano de vector deseado (limite 10,000): ";
    int vectorSize;
    while(cin>>vectorSize){
        if(vectorSize>0){
            break;
        }
        else{
            cout << "Numero invalido, ingresar numero mayor a 0: ";
        }
    }
    vector<int> vec1(vectorSize);

    //generar números aleatorios en vector
    srand (time(NULL));
    for(size_t i=0;i<vectorSize;i++){
        int randomNum = rand()%10000+1;
        while(find(vec1.begin(),vec1.end(),randomNum) != vec1.end()){
            randomNum = rand()%10000+1;
        }
        vec1[i] = randomNum;
    }

    //Cantidad de números a buscar
    cout << "Ingresar cantidad de busquedas que se desea hacer: ";
    int cantidadBusquedas;
    while(cin>>cantidadBusquedas){
        if(cantidadBusquedas>0){
            break;
        }
        else{
            cout << "Numero invalido, ingresar numero mayor a 0: ";
        }
    }

    //ingresar números a buscar en vector usando ambas búsquedas
    int numBusqueda;
    for(size_t i=0;i<cantidadBusquedas;i++){
        cout << "Ingresar numero a buscar: ";
        cin >> numBusqueda;
        cout << "Indice del numero " << numBusqueda << " usando Busqueda Secuencial: " << busqSecuencial(vec1,numBusqueda) << endl;
        cout << "Ingresar numero de algoritmo de ordenamiento a utilizar para la busqueda binaria:\n1 para Insertion Sort\n2 para Bubble Sort\n3 para Quick Sort\nInput: ";
        int ordenNum;
        while(cin>>ordenNum){
            if(ordenNum<=3 && ordenNum>=0){
                break;
            }
            else{
                cout << "Numero invalido, ingresar numero del 1 al 3: ";
            }
        }
        //hacer copia para segunda búsqueda
        vector<int> vec2(vec1);

        //ordenar vector de acuerdo a selección
        if(ordenNum == 1){
            ordenaInsercion(vec2);
            cout << "(Vector ordenado para Busqueda Binaria usando Insertion Sort)" << endl;
        }
        else if(ordenNum == 2){
            ordenaBurbuja(vec2);
            cout << "(Vector ordenado para Busqueda Binaria usando Bubble Sort)" << endl;
        }
        else{
            ordenaQuick(vec2,0,vec2.size()-1);
            cout << "(Vector ordenado para Busqueda Binaria usando Quick Sort)" << endl;
        }
        
        cout << "Indice del numero " << numBusqueda << " usando Busqueda Binaria: " << busqBinaria(vec2,0,vec2.size()-1,numBusqueda) << endl;
    }
}
