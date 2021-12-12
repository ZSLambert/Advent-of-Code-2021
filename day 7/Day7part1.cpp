//advent of code day 7 part 1

//includes
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <fstream>


using namespace std;

int64_t calculateFuel(vector<int64_t> input, int64_t alignment){
    int64_t ans = 0;
    for(auto el: input){
        ans += abs(alignment - el);
    }
    return ans;
}

int main(){
    
    vector<int64_t> crabs;
    int64_t max = INT64_MIN;
    int64_t min = INT64_MAX;

    fstream newfile;

    newfile.open("Day7.txt",ios::in); 
    if (newfile.is_open()){
        string line;
        while(getline(newfile, line)){
            std::stringstream ss(line);

            for (int64_t i=0; ss >> i;) {
                crabs.push_back(i);    
                if (ss.peek() == ','){
                    ss.ignore();
                }
                if(i < min){
                    min = i;
                }
                if(i>max){
                    max=i;
                }
                    
            } 
        }

    }
    newfile.close();

    /*for(auto el: crabs){
        cout<<el<<" ";
    }
    cout<<endl;*/

    cout<< "min: "<<min<<endl;
    cout<< "max: "<<max<<endl;

    int64_t leastfuel = INT_MAX;
    bool leastReached = false;
    int64_t prevSplit;

    while(!leastReached){
        int64_t middle = (max-min)/2;
        int64_t split = min + middle;
        cout<< "split: "<<split<<endl;

        int64_t left = split-1;
        int64_t right = split;

        int64_t leftfuel = calculateFuel(crabs,left);
        int64_t rightfuel = calculateFuel(crabs,right);

        cout<< "left: "<<leftfuel<<endl;
        cout<< "right: "<<rightfuel<<endl<<endl;
        
        if(leftfuel< rightfuel){
            max = left;
            if(leftfuel<leastfuel){
                leastfuel = leftfuel;
                prevSplit = split;
            }
            else{
                max = std::max(prevSplit,split);
                min = std::min(prevSplit,split);
                if(max == min){
                    leastReached = true;
                }
            }
            
        }
        else if(rightfuel<leftfuel){
            min = right;
            if(rightfuel<leastfuel){
                leastfuel = rightfuel;
                prevSplit = split;
            }
            else{
                max = std::max(prevSplit,split);
                min = std::min(prevSplit,split);
                if(max == min){
                    leastReached = true;
                }
            }
        }
    }

    cout<<"final: "<< leastfuel <<endl;
   

}