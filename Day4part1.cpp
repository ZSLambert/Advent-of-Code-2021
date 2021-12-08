//advent of code day 4 part 1

//includes
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <regex>


using namespace std;

vector<int> stringToVect(string input){
    regex rgx("[0-9]+");
    smatch match;
    vector<int> ans;

    while(regex_search(input,match,rgx)){
        ans.push_back(stoi(match[0].str()));
        input = match.suffix().str();
    }

    return ans;
}

int main(){
    
    fstream newfile;

    newfile.open("Day4_sample.txt",ios::in); 
    if (newfile.is_open()){

        vector<int> draw;

        string firstline;
        getline(newfile, firstline);

        draw = stringToVect(firstline);

        for(auto num: draw){
            cout << num << endl;
        }

        /*string line;
        while(getline(newfile, line)){ 
                  
        }*/

    }   

}
