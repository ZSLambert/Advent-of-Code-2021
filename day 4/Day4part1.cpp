//advent of code day 4 part 1

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

        for(auto num: draw){
            int score;
            for(auto& board: boards){
                bool won;
                won = board.mark(num);
                if(won){
                    board.print();
                    score = board.getScore();
                    cout << score*num << endl;
                    return 0;
                }
            }
        }



    }   

}
