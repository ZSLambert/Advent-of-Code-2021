
#include <vector>

using namespace std;


class Board{
private:
    vector<vector<int>> board;

    bool won(){
        vector<int> col_totals(5,0);
        for(int row_idx=0; row_idx< board.size() ; row_idx++){
            int row_total = 0;
           
            for(int col_idx=0; col_idx< board[row_idx].size(); col_idx++){
                if(board[row_idx][col_idx] == -1){
                    row_total += board[row_idx][col_idx];
                    col_totals[col_idx] += board[row_idx][col_idx];
                }
            }
            if(row_total == -5){
                //cout<<"won in row"<<endl;
                return true;
            }

        }
        for(auto el : col_totals){
            if (el == -5){
                //cout<<"won in cols"<<endl;
                return true;
            } 
        }

        return false;
    }
public:
    
    Board(vector<vector<int>> newBoard){
        board = newBoard;
    }


    bool mark(int toMark){
        for(auto& row: board){
            for(auto& el: row){
                if(el == toMark){
                    el = -1;
                    return won();  
                }
            }
        }
        return false;
    }

    int getScore(){
        int final = 0;
        for(auto row: board){
            for(auto el: row){
                if(el != -1){
                    final += el;
                }
            }
        }
        return final;
    }

    void print(){
        for(auto row: board){
            for(auto el: row){
                cout << el << " ";
            }
            cout<< endl;   
        }
    }

};