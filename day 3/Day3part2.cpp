//advent of code day 3 part 2

//includes
#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
#include <fstream>



using namespace std;

int toDec(vector<bool> toCon){
    int ans=0;
    reverse(toCon.begin(),toCon.end());
    for(int i=0; i < toCon.size();i++){
        if(toCon[i]){
            ans+= pow(2,i);
        }
    }
    return ans;
}

//ToDO: simplify to make usible for co2 and oxy
bool commonB( vector<vector<bool>> info, int bitpos){
    //calculate number of 1 and 0 in bit positions and save to vector
    vector<int> bits{0,0};
    bool commonBit;
    for(auto row:info){
        if(row[bitpos]){
            bits[1] += 1;
        }
        else{
            bits[0] += 1;
        }
    }
    
    //create vector that is bits number in size where true means 1 is most common for the bit position
    if (bits[0] > bits[1]){
        commonBit = false;
    }
    else{
        commonBit = true; 
    }


    return commonBit;
}

int main(){
    
    int life;

    vector<vector<bool>> data;

    fstream newfile;

    newfile.open("Day3_part1.txt",ios::in); 
    if (newfile.is_open()){
        string line;
        int numDigets;
        

        //read in each line of the file and put into data
        while (getline(newfile, line)) {
            vector<bool> thing;
            numDigets = line.size();
            for (int j=0; j < line.size(); j++){
                thing.push_back(line[j] == '1');
            }
            data.push_back(thing);
        }
        newfile.close();

        vector<vector<bool>> oxygen = data;
        vector<vector<bool>> co2 = data;

        // narrow down to rating value for oxygen
        for(int i = 0; oxygen.size() > 1; i++){
            bool common = commonB(oxygen,i);
            auto oxygenIt = oxygen.begin();
            while (oxygenIt != oxygen.end()){
                if (oxygenIt->at(i) != common){
                    oxygenIt = oxygen.erase(oxygenIt);
                } else {
                    oxygenIt++;
                }
            }
        }
         // narrow down to rating value for co2
        for(int i = 0; co2.size() > 1; i++){
            bool common = !commonB(co2,i);
            auto co2It = co2.begin();
            while (co2It != co2.end()){
                if (co2It->at(i) != common){
                    co2It = co2.erase(co2It);    
                } else {
                    co2It++;
                }
            }
        }
        
        //convert to decimal
        int oxy = toDec(oxygen[0]);
        int c = toDec(co2[0]);
        
        //get final answer
        life = oxy*c;



        cout<< "oxy: " << oxy << endl;
        cout<< "co2: " << c << endl;
        cout<< "Life: " << life << endl;



    }
}
