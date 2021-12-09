//advent of code day 5 part 1

//includes
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <regex>


using namespace std;

int main(){
    
    vector<vector<int>> grid(1000,vector<int>(1000, 0));

    fstream newfile;

    regex rgx("([0-9]+),([0-9]+) -> ([0-9]+),([0-9]+)");

    newfile.open("Day5_sample.txt",ios::in); 
    if (newfile.is_open()){   
        string line;
        while(getline(newfile, line)){ 
            int x1,x2,y1,y2;
            smatch match;
            //split line into direction and number
            if(regex_search(line,match,rgx)){
                cout<< match[0].str() << endl;
                x1 = stoi(match[1].str());
                y1 = stoi(match[2].str());
                x2 = stoi(match[3].str());
                y2 = stoi(match[4].str());
            }
            cout <<"x1: "<< x1 <<" y1: "<< y1 <<" x2: "<< x2 <<" y2: "<< y2 << endl;

            if(x1 == x2 || y1 == y2){

            }

                 
        }
        newfile.close();
    }
}