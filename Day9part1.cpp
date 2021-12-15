//advent of code day 9 part 1

//includes
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <regex>


using namespace std;

vector<int> stringToVect(string input){
    regex rgx("[0-9]+");
    smatch match;
    vector<char> temp_vect;
    vector<int> ans;

    for(int i = 0; i < input.length(); i++){
        temp_vect.push_back(input[i]);
    }

    for(auto el : temp_vect){
        ans.push_back(el - '0');
    }

    return ans;
}

int main(){
    
    vector<vector<int>> input;
    vector<int> final;

    fstream newfile;

    newfile.open("Day9.txt",ios::in); 
    if (newfile.is_open()){
        string line;
        while(getline(newfile, line)){
            if(line.empty()){
                continue;
            } 

            input.push_back(stringToVect(line));    

        }

    }
    newfile.close();
    //rows
    for(int i=0;i<input.size();i++){
        //col
        for(int j=0;j<input[i].size();j++){
            if(i == 0){
                if(j == 0){
                    if (input[i][j] < input[i][j+1] && input[i][j] < input[i+1][j]){
                        final.push_back(input[i][j]);
                    }
                }
                else if(j == input[i].size()-1){
                    if (input[i][j] < input[i][j-1] && input[i][j] < input[i+1][j]){
                        final.push_back(input[i][j]);
                    }
                }
                else{
                    if (input[i][j] < input[i][j+1] && input[i][j] < input[i][j-1] && input[i][j] < input[i+1][j]){
                        final.push_back(input[i][j]);
                    }

                }
            }
            else if(i == input.size()-1){
                if(j == 0){
                    if (input[i][j] < input[i][j+1] && input[i][j] < input[i-1][j]){
                        final.push_back(input[i][j]);
                    }
                }
                else if(j == input[i].size()-1){
                    if (input[i][j] < input[i][j-1] && input[i][j] < input[i-1][j]){
                        final.push_back(input[i][j]);
                    }
                }
                else{
                    if (input[i][j] < input[i][j+1] && input[i][j] < input[i][j-1] && input[i][j] < input[i-1][j]){
                        final.push_back(input[i][j]);
                    }

                }
            }
            else{
                if(j == 0){
                    if (input[i][j] < input[i][j+1] && input[i][j] < input[i+1][j] && input[i][j] < input[i-1][j]){
                        final.push_back(input[i][j]);
                    }
                }
                else if(j == input[i].size()-1){
                    if (input[i][j] < input[i][j-1]  && input[i][j] < input[i+1][j] && input[i][j] < input[i-1][j]){
                        final.push_back(input[i][j]);
                    }
                }
                else{
                    if (input[i][j] < input[i][j+1] && input[i][j] < input[i][j-1] && input[i][j] < input[i+1][j] && input[i][j] < input[i-1][j]){
                        final.push_back(input[i][j]);
                    }

                }

            }

        }

    }

    /*for(auto row: input){
        for(auto el: row){
            cout<<el<<" ";
        }
        cout<<endl;
    }*/
    int risk = 0;
    for(auto el: final){
        risk += el+1;
        //cout<<el<<" "; 
    }
    cout<<"  Risk level: "<< risk <<endl;
}