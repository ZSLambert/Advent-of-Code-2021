//advent of code day 8 part 2

//includes
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <regex>



using namespace std;

//{a,b,c,d,e,f,g}
vector<bool> zero={1,1,1,0,1,1,1};
vector<bool> one={0,0,1,0,0,1,0};
vector<bool> two={1,0,1,1,1,0,1};
vector<bool> three={1,0,1,1,0,1,1};
vector<bool> four={0,1,1,1,0,1,0};
vector<bool> five={1,1,0,1,0,1,1};
vector<bool> six={1,1,0,1,1,1,1};
vector<bool> seven={1,0,1,0,0,1,0};
vector<bool> eight={1,1,1,1,1,1,1};
vector<bool> nine={1,1,1,1,0,1,1};

int letterCount(vector<bool> input){
    int ans = 0;
    for(auto el: input){
        if(el){
            ans+=1;
        }
    }
    return ans;

}

int conToNum(vector<bool> toCon, vector<int> con){
    vector<bool> ans(7,0);
    int final;
    for(int i =0; i<con.size(); i++){
        if(toCon[con[i]]){
            ans[i] = true;
        }
    }

    if(equal(ans.begin(), ans.end(), zero.begin())){
        final = 0;
    }
    else if(equal(ans.begin(), ans.end(), one.begin())){
        final = 1;
    }
    else if(equal(ans.begin(), ans.end(), two.begin())){
        final = 2;
    }
    else if(equal(ans.begin(), ans.end(), three.begin())){
        final = 3;
    }
    else if(equal(ans.begin(), ans.end(), four.begin())){
        final = 4;
    }
    else if(equal(ans.begin(), ans.end(), five.begin())){
        final = 5;
    }
    else if(equal(ans.begin(), ans.end(), six.begin())){
        final = 6;
    }
    else if(equal(ans.begin(), ans.end(), seven.begin())){
        final = 7;
    }
    else if(equal(ans.begin(), ans.end(), eight.begin())){
        final = 8;
    }
    else if(equal(ans.begin(), ans.end(), nine.begin())){
        final = 9;
    }
    return final;
}

vector<bool> covertToBool(string letter){
    vector<bool> tmp_vect(7,0);
    for(int i=0;i<letter.size();i++){
        char tmp = letter[i];
        switch(tmp){
            case 'a' :
                tmp_vect[0] = 1;
                break;
            case 'b' :
                tmp_vect[1] = 1;
                break;
            case 'c' :
                tmp_vect[2] = 1;
                break;
            case 'd' :
                tmp_vect[3] = 1;
                break;
            case 'e' :
                tmp_vect[4] = 1;
                break;
            case 'f' :
                tmp_vect[5] = 1;
                break;
            case 'g' :
                tmp_vect[6] = 1;
                break;

        }

    }
    return tmp_vect;

}

vector<int> forSure(vector<vector<bool>> input ){
    vector<int> output(7,0);
    for(int i =0;i< input[0].size(); i++){
        int ans  = 0;
        for(int j =0;j< input.size(); j++){
            if(input[j][i]){
                ans+=1;
            }
        }
        if (ans == 4){
            output[4] = i;
        }
        else if (ans == 6){
            output[1] = i;
        }
        else if (ans == 9){
            output[5] = i;
        }
        else if (ans == 8){
            output[0] = 11;
            output[2] = 11;
        }
        else if (ans == 7){
            output[3] = 12;
            output[6] = 12;
        }

    }
    return output;
}


int main(){
    
    fstream newfile;

    newfile.open("Day8.txt",ios::in); 
    if (newfile.is_open()){        
        int total = 0;
        
        regex rgx("([a-z]+) ([a-z]+) ([a-z]+) ([a-z]+) ([a-z]+) ([a-z]+) ([a-z]+) ([a-z]+) ([a-z]+) ([a-z]+) \\| ([a-z]+) ([a-z]+) ([a-z]+) ([a-z]+)");
        string line;
        while(getline(newfile, line)){
            if(line.empty()){
                continue;
            } 

            
            vector<vector<bool>> newNum;
            smatch match;
            vector<int>::iterator new_end;
            vector<int>::iterator new_end_seven;
            //split line into direction and number
            if(regex_search(line,match,rgx)){
                int num1,num2,num3,num4;
                for(int i= 1; i <=10; i++){
                    newNum.push_back(covertToBool(match[i].str()));

                }
                
                vector<int> conversion = forSure(newNum);
                
                for(auto row:newNum){
                    //finding  C using one
                    if(letterCount(row) == letterCount(one)){
                        for(int i =0; i<row.size() ; i++){
                            
                            if(row[i] && i!= conversion[5]){
                                conversion[2] = i;
                            }
                        }
                    }
                }

                for(auto row:newNum){
                    //finding  a using seven
                    if(letterCount(row) == letterCount(seven)){
                        for(int i =0; i<row.size() ; i++){
                            
                            if(row[i] && i!= conversion[5] && i!= conversion[2]){
                                conversion[0] = i;
                            }
                        }
                    }
                }


                for(auto row:newNum){
                    //finding  D using four
                    if(letterCount(row) == letterCount(four)){
                        for(int i =0; i<row.size() ; i++){
                            
                            if(row[i] && i!= conversion[1] && i!= conversion[2] && i!= conversion[5]){
                                conversion[3] = i;
                            }
                        }
                    }
                }

                for(auto row:newNum){
                    //finding  g using eight
                    if(letterCount(row) == letterCount(eight)){
                        for(int i =0; i<row.size() ; i++){
                            
                            if(row[i] && i!= conversion[0] && i!= conversion[1] && i!= conversion[2] && i!= conversion[3] && i!= conversion[4] && i!= conversion[5]){
                                conversion[6] = i;
                            }
                        }
                    }
                }
                




                for(auto el: conversion){
                    cout<<el<<" ";
                }

                for(int i= 11; i <=14; i++){
                    vector<bool> tmpNum = covertToBool(match[i].str());
                    int convert = conToNum(tmpNum, conversion);
                    if(i ==11){
                        num1 = convert;
                    }
                    else if(i ==12){
                        num2 = convert;
                    }
                    else if(i ==13){
                        num3 = convert;
                    }
                    else if(i ==14){
                        num4 = convert;
                    }

                }

                total += (num1*1000)+(num2*100)+(num3*10)+num4;

                cout<< (num1*1000)+(num2*100)+(num3*10)+num4  <<endl;

                
            }
  
        }
        newfile.close();

        cout<<"total: " <<total<<endl;
    }
}