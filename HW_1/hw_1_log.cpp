#include <iostream>
#include <bits/stdc++.h> 
#include <vector>

using namespace std;

//O(m log n)
int main(){
    
    vector <vector<int>> buildings = {{1,1,1,0,1,1},
                                      {1,1,0,0,0,1},
                                      {0,1,0,0,0,1},
                                      {0,1,0,0,0,1},
                                      {0,0,0,0,0,1}};
    int m = 6; //column
    int n = 5; //row
    bool tallestGet = false; //loop to check if tallest building value is obtained
    int highNum = 0;
    int middle = 0;
    int left = 0;
    int right = n-1;
    int tallestBuilding = 0; //row of tallest building

    while(tallestGet == false){
        
        middle = left + ((right-left)/2); //used for binary search

        for(int i=0;i<m;i++){

            //if 0 is found and 0 is not middle number
            if(0 == buildings[middle][i] && middle != highNum){
                tallestBuilding = i;
                right = middle - 1;
                break;
            }

            //get tallest building position if 0 is in middle position
            else if(0 == buildings[middle][i] && middle == highNum){
                tallestBuilding = i;
                tallestGet = true;
                break;
            }

            //used in order to keep searching, since 0 wasn't found
            else if(i == m - 1 && 0 != buildings[middle][i]){
                left = middle + 1;
                highNum = left;
            }
        }
    }

    //output
    cout << "Tallest building found in column 'm' = " << tallestBuilding << endl;
    
}

/*
This code runs using O(m log n) algorithm due to the use of binary search within the matrix of vectors. While the code runs, the
search space gets exponentially smaller and smaller, upo until it finds the given value of 0, and prints the 
tallest building. 
*/