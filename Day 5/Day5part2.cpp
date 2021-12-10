//advent of code day 5 part 2

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

    newfile.open("Day5.txt",ios::in); 
    if (newfile.is_open()){   
        string line;
        while(getline(newfile, line)){ 
            int x1,x2,y1,y2;
            smatch match;
            //split line into direction and number
            if(regex_search(line,match,rgx)){
                //cout<<match[0].str()<<endl;
                x1 = stoi(match[1].str());
                y1 = stoi(match[2].str());
                x2 = stoi(match[3].str());
                y2 = stoi(match[4].str());
            }


            if(x1==x2){
                if(y1<y2){
                    for(int i = y1; i <= y2; i++){
                        grid[i][x1] += 1;
                    }
                }
                else if(y2<y1){
                    for(int i = y2; i <= y1; i++){
                        grid[i][x1] += 1;
                    }
                }
                
            }
            else if(y1==y2){
                if(x1<x2){
                    for(int i = x1; i <= x2; i++){
                        grid[y1][i] += 1;
                    }
                }
                else if(x2<x1){
                    for(int i = x2; i <= x1; i++){
                        grid[y1][i] += 1;
                    }
                }
                
            }
            else{
                if(x1<x2){
                    if(y1<y2){
                        int i = x1;
                        int j = y1;
                        while(i <= x2 && j <= y2 ){
                            grid[j][i] += 1;
                            j++;
                            i++;
                        }
                    }
                    else if(y2<y1){
                        int i = x1;
                        int j = y1;
                        while(i <= x2 && j >= y2 ){
                            grid[j][i] += 1;
                            j--;
                            i++;
                        }
                    }
                }
                else if(x2<x1){
                   if(y1<y2){
                        int i = x1;
                        int j = y1;
                        while(i >= x2 && j <= y2 ){
                            grid[j][i] += 1;
                            j++;
                            i--;
                        }
                    }
                    else if(y2<y1){
                        int i = x1;
                        int j = y1;
                        while(i >= x2 && j >= y2 ){
                            grid[j][i] += 1;
                            j--;
                            i--;
                        }
                    }
                }
              
            }

        /*for(auto row: grid){
            for(auto el: row){
                cout<< el << " ";
            }  
            cout<<endl; 
        } 
        cout<<endl;*/

                 
        }
        int total = 0 ;
        for(auto row: grid){
            for(auto el: row){
                //cout<< el << " ";
                if(el>1){
                    total += 1;
                }
            }  
            //cout<<endl; 
        }

        cout<< total << endl;
        newfile.close();
    }
}