#include <iostream>
#include <bits/stdc++.h> 
#include <vector>
#include <algorithm>

using namespace std;

//O(m+n)
int main(){

    vector <vector<int>> buildings = {{1,1,1,0,1,1},
                                      {1,1,0,0,0,1},
                                      {0,1,0,0,0,1},
                                      {0,1,0,0,0,1},
                                      {0,0,0,0,0,1}};
    int m = 6; //column
    int n = 5; //row
    int check = 0; //value to pass to next loop
    int tallestBuilding = 0; //row of tallest building

    //check if 0 is in row
    for(int i=0;i<n;i++){
        if(find(buildings[i].begin(),buildings[i].end(),0) != buildings[i].end()){
            check = i;
            break;
        }
    }

    //check position of 0, once found
    for(int i=0;i<m;i++){
        if(buildings[check][i] == 0){
            tallestBuilding = i;
            break;
        }
    }

    //output
    cout << "Tallest building found in column 'm' = " << tallestBuilding << endl;

}

/*
This code runs using O(m + n) algorithm due to having two consecutive for loops, and not having a for loop inside another 
one crating an O(m * n) algorithm instead of the intended O(m + n). First loop checks if matrix has a 0, then second loop
getting its row position, finally printing the tallest building. 
*/