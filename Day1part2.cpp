//advent of code day 1 part 2

//includes
#include <iostream>
#include <string>
#include <vector>
#include <fstream>


using namespace std;

int main(){

    vector<int> data;
    vector<int> groups;
    
    int increases;

    int current;
    int previouse = INT_MAX;

    
    fstream newfile;

    newfile.open("Day1_part1.txt",ios::in); 
    if (newfile.is_open()){   
        string line;
        while(getline(newfile, line)){ 
            data.push_back(stoi(line));      
        }
        newfile.close();
        for (int i=0 ; i < data.size()-2 ; i++){
            int a = data[i];
            int b = data[i+1];
            int c = data[i+2];

            groups.push_back(a+b+c);
        }
        
        for (int x : groups){
            current = x;
            if(current > previouse){
                increases += 1;
            }
            previouse = current;
        }
        cout << increases << " ";
    }

}