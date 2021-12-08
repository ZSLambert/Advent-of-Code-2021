//advent of code day 4 part 2

//includes
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <regex>
#include <board.hpp>


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

    newfile.open("Day4.txt",ios::in); 
    if (newfile.is_open()){

        vector<int> draw;
        vector<vector<int>> newBoard;
        vector<Board> boards;

        string firstline;
        getline(newfile, firstline);

        draw = stringToVect(firstline);


        string line;
        while(getline(newfile, line)){
            if(line.empty()){
                continue;
            }
            newBoard.push_back(stringToVect(line));     
            if(newBoard.size() == 5){
                boards.push_back(newBoard);
                newBoard.clear();
            }   
        }
        newfile.close();
        
        int score;
        int num_scored;
        int prev =INT_MIN;
        for(auto& board: boards){
            int current=0;
            for(auto num: draw){
                bool won;
                won = board.mark(num);
                current +=1;
                if(won){
                    if (current > prev){
                        score = board.getScore();
                        num_scored = num;
                        prev=current;    
                    } 
                    break;   
                }
            }
        }
        cout <<"score: "<<score<< " num: "<<num_scored<< endl; 
        cout << score*num_scored << endl;



    }   

}
