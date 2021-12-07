//advent of code day 2 part 2

//includes
#include <iostream>
#include <string>
#include <fstream>
#include <regex>


using namespace std;

int main(){

    int horizontal = 0;
    int depth = 0;
    int aim = 0;

    fstream newfile;

    newfile.open("Day2_part1.txt",ios::in); 
    if (newfile.is_open()){
        string line;
        regex rgx("([a-zA-Z]+) ([0-9]+)");
        while (getline(newfile, line)) {
            smatch match;
            //split line into direction and number
            if(regex_search(line,match,rgx)){
                string word = match[1].str();
                int num = stoi(match[2].str());
                if(word.compare("forward") == 0){
                    horizontal += num;
                    depth += aim*num;

                }
                else if(word.compare("down") == 0){
                    aim += num;
                    
                }
                else if(word.compare("up") == 0){
                    aim -= num;
                    
                }
            } 
        }
        newfile.close();
        cout << horizontal << endl;
        cout << depth << endl;
        cout << horizontal*depth << endl;
    }


}