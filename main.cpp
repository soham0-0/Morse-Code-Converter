#include<iostream>
#include<vector>
#include<map>
using namespace std;

enum child{
    left, 
    right
};

void decode(string input){
/*
              Tree to find decoded output:

                          ROOT
                    /              \
   (left if . )    /                \   (right if - )
                  /                  \
                 /                    \
                /                      \
               E                        T
             /   \                  /       \
            /     \                /         \ 
           /       \              /           \ 
          I          A           N             M
        /   \      /   \        /  \         /   \
       S     U    R     W      D     K      G     O
      / \   /    /     / \    / \   / \    / \
     H   V F    L     P   J  B   X C   Y  Z   Q

*/
    map<string, vector<string>> morseTree = {{"ROOT", {"E", "T"}}, {"E", {"I", "A"}}, {"T", {"N", "M"}}, {"I", {"S", "U"}}, {"A", {"R", "W"}}, {"N", {"D", "K"}}, {"M", {"G", "O"}}, {"S", {"H", "V"}}, {"U", {"F", "NIL"}}, {"R", {"L", "NIL"}}, {"W", {"P", "J"}}, {"D", {"B", "X"}}, {"K", {"C", "Y"}}, {"G", {"Z", "Q"}}};  
    string output = "", cur = "ROOT";
    int spcount = 0;
    for(auto C: input){
        if(C == ' '){
            if(!spcount){ if(cur!="ROOT") output+=cur; spcount++; }
            else        { output+=" "; spcount=0; }
            cur="ROOT";
        }else{
            spcount = 0;
            if(C == '.')cur = morseTree[cur][child::left];
            else        cur = morseTree[cur][child::right];
        }
    }
    if(cur!="ROOT") output+=cur;
    cout<<"Decoded Text: "<<output<<endl;
}

void encode(string input){
    map<char, string> dec = {
        {'A', ".-"},
        {'B', "-..."},
        {'C', "-.-."},
        {'D', "-.."},
        {'E', "."},
        {'F', "..-."},
        {'G', "--."},
        {'H', "...."},
        {'I', ".."}, 
        {'J', ".---"},
        {'K', "-.-"},
        {'L', ".-.."},
        {'M', "--"},
        {'N', "-."},
        {'O', "---"},
        {'P', ".--."},
        {'Q', "--.-"},
        {'R', ".-."},
        {'S', "..."},
        {'T', "-"},
        {'U', "..-"},
        {'V', "...-"},
        {'W', ".--"},
        {'X', "-..-"},
        {'Y', "-.--"},
        {'Z', "--.."}
    };
    string output="";
    for(auto i: input){
        if(i!=' '){
            output+= dec[toupper(i)] + " ";
        }else{
            output+="  ";
        }
    }
    cout<<"Encoded Text: "<<output<<endl;
}

int main(int argc, char **argv){

    if(argc<3){
        cout<<"Too few arguments!\n";
        exit(0);
    }
    string operation = argv[1], input = argv[2];
    if(operation == "encode") encode(input);
    else if(operation == "decode") decode(input);
    else cout<<"Operation not identified! Aborting!";
    return 0;
}