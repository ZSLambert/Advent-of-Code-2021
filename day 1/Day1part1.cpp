//advent of code day 1 part 1

//includes
#include <iostream>
#include <string>
#include <vector>
#include <fstream>


using namespace std;

int main(){

    vector<int> data;
    
    int increases;

    bool first = false;

    int current;
    int previouse;

    
    fstream newfile;

    newfile.open("Day1_part1.txt",ios::in); 
    if (newfile.is_open()){   
        string line;
        while(getline(newfile, line)){ 
            data.push_back(stoi(line));      
        }
        newfile.close();
        for (int x : data){
            if (first == false){
                previouse = x;
                first = true;
            }
            else{
                current = x;
                if(current > previouse){
                    increases += 1;
                }
                previouse = current;
            }
        }
        cout << increases << " ";
    }


}
