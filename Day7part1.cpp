//advent of code day 7 part 1

//includes
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>


using namespace std;

int calculateFuel(vector<int> input, int alignment){
    int ans = 0;
    for(auto el: input){
        ans += abs(alignment - el);
    }
    return ans;
}

int main(){
    
    vector<int> crabs;
    int max = INT_MIN;
    int min = INT_MAX;

    fstream newfile;

    newfile.open("Day7_sample.txt",ios::in); 
    if (newfile.is_open()){
        string line;
        while(getline(newfile, line)){
            std::stringstream ss(line);

            for (int i=0; ss >> i;) {
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

    for(auto el: crabs){
        cout<<el<<" ";
    }
    cout<<endl;

    cout<< "min: "<<min<<endl;
    cout<< "max: "<<max<<endl;

    int middle = (max-min)/2;
    int split = min + middle;
    cout<< "split: "<<split<<endl;

    int left = split-1;
    int right = split+1;

    int leftfuel = calculateFuel(crabs,left);
    int rightfuel = calculateFuel(crabs,right);

    cout<< "left: "<<leftfuel<<endl;
    cout<< "right: "<<rightfuel<<endl;

}