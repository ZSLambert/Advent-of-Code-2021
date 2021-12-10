//advent of code day 6 part 1

//includes
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>


using namespace std;

int main(){
    
    vector<int> fish;

    fstream newfile;

    newfile.open("Day6.txt",ios::in); 
    if (newfile.is_open()){
        string line;
        while(getline(newfile, line)){
            std::stringstream ss(line);

            for (int i=0; ss >> i;) {
                fish.push_back(i);    
                if (ss.peek() == ',')
                    ss.ignore();
            } 

        }

    }
    newfile.close();

    cout<<fish.size()<<endl;
    int days = 0;
    while(days < 80){
        int zeros = 0;
        for(auto& el: fish){
            //cout<<el<<" ";
            if(el == 0){
                el = 6;
                zeros += 1;   
            }
            else{
                el--;
            }
        }
        for (int i =0; i< zeros;i++){
            fish.push_back(8);
        }
        //cout<<endl;
        days++;
    }

    cout<<fish.size()<<endl;
    
}  