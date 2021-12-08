//advent of code day 3 part 1

//includes
#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
#include <fstream>



using namespace std;

int toDec(vector<int> toCon){
    int ans=0;
    reverse(toCon.begin(),toCon.end());
    for(int i=0; i < toCon.size();i++){
        if(toCon[i] == 1){
            ans+= pow(2,i);
        }
    }
    return ans;
}

int main(){
    
    int power;

    vector<vector<bool>> data;

    fstream newfile;

    newfile.open("Day3_part1.txt",ios::in); 
    if (newfile.is_open()){
        string line;
        int numDigets;
        
        while (getline(newfile, line)) {
            vector<bool> thing;
            numDigets = line.size();
            for (int j=0; j < line.size(); j++){
                thing.push_back(line[j] == '1');
            }
            data.push_back(thing);
        }

        vector<vector<int>> bits(numDigets, {0,0});
        vector<int> gamma(numDigets);
        vector<int> epsilon(numDigets);
        for( int i=0; i < data.size(); i++){
            for (int j=0; j < data[i].size(); j++){
               if(data[i][j]){
                   bits[j][1] += 1;
               }
               else{
                   bits[j][0] += 1;
               }
            }
        }
        for( int i=0; i < bits.size(); i++){
            if (bits[i][0]> bits[i][1]){
                gamma[i]= 0;
                epsilon[i] = 1;
            }
            else{
                gamma[i]= 1;
                epsilon[i] = 0; 
            } 
        }
        newfile.close();

        int decGamma = toDec(gamma);
        int decEpsilon = toDec(epsilon);
        power = decGamma*decEpsilon;

        cout<< "gamma: " << decGamma << endl;
        cout<< "epsilon: " << decEpsilon << endl;
        cout<< "power: " << power << endl;



    }
}
