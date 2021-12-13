//advent of code day 8 part 1

//includes
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <regex>


using namespace std;

int letterCount(vector<bool> input){
    int ans = 0;
    for(auto el: input){
        if(el){
            ans+=1;
        }
    }
    return ans;

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


int main(){
    
    fstream newfile;

    newfile.open("Day8.txt",ios::in); 
    if (newfile.is_open()){

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
        
        int total = 0;
        
        regex rgx("([a-z]+) ([a-z]+) ([a-z]+) ([a-z]+) ([a-z]+) ([a-z]+) ([a-z]+) ([a-z]+) ([a-z]+) ([a-z]+) \\| ([a-z]+) ([a-z]+) ([a-z]+) ([a-z]+)");
        string line;
        while(getline(newfile, line)){
            if(line.empty()){
                continue;
            } 
            vector<bool> newNum;
            smatch match;
            //split line into direction and number
            if(regex_search(line,match,rgx)){
                for(int i= 11; i <=14; i++){
                    newNum = covertToBool(match[i].str());
                    if(letterCount(newNum) == letterCount(one) || letterCount(newNum) == letterCount(four) || letterCount(newNum) == letterCount(seven) || letterCount(newNum) == letterCount(eight) ){
                        total += 1;
                    }
                }
                
            }
  
        }
        newfile.close();

        cout<<"total: " <<total<<endl;
    }
}