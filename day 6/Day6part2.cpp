//advent of code day 6 part 2

//includes
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>


using namespace std;

int main(){
    
    vector<int> input;
    vector<int64_t> fish(9,0);

    fstream newfile;

    newfile.open("Day6.txt",ios::in); 
    if (newfile.is_open()){
        string line;
        while(getline(newfile, line)){
            std::stringstream ss(line);

            for (int i=0; ss >> i;) {
                input.push_back(i);    
                if (ss.peek() == ',')
                    ss.ignore();
            } 

        }

    }
    newfile.close();

    for(auto el: input){
        fish[el] += 1;
    }

    int days = 0;
    while(days <= 256){
        int64_t total = 0;
        for(auto el: fish){
           total += el;
        }
        cout<<days << ": "<< total<<endl;

        //cout << fish[0]<<" ";
        
        int64_t zeros = fish[0];
        fish[0] = fish[1];

        for(int i = 1; i < fish.size()-1; i++){
            //cout << fish[i]<<" ";
            fish[i] = fish[i+1];
        }

        
        fish[6] += zeros;
        

        //cout << fish[8]<<" ";
        //cout<<endl<<endl;
        
        fish[8] = zeros;
         
        days++;
        
    }
    
}  