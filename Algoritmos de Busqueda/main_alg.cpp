#include "search_alg.hpp"

using namespace std;

int main(){
    clock_t tStart = clock();
    Busqueda<int> b;
    vector<int> test = {1,2,5,7,9,10,12,15,16,19};
    int num = 9;
    sort(test.begin(),test.end());
    int size = b.sizeVec();
    //b.randomGenerate();
    printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

    cout << b.getSequential(num) << endl;
    printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    cout << b.getSequentialOne(num) << endl;
    printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    cout << b.getSequentialTwo(num) << endl;
    printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    cout << b.getBinary(test,0,size-1,num) << endl;
    printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
}