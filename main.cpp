#include<iostream>
#include<vector>
#include<map>
using namespace std;

enum child{
    left, 
    right
};

int main(){
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
    cout<<"Enter Encoded Text (1 space to seperate letters and 2 spaces to seperate words): ";
    string input; getline(cin, input);
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
    output+=cur;
    cout<<"Decoded Text: "<<output<<endl;
    return 0;
}