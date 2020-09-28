#include<iostream>
#include<vector>
#include<map>
using namespace std;

enum child{
    left, 
    right
};

int main(int argc, char **argv){
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
    if(argc<2){
        cout<<"Too few arguments!\n";
        exit(0);
    }
    map<string, vector<string>> morseTree = {{"ROOT", {"E", "T"}}, {"E", {"I", "A"}}, {"T", {"N", "M"}}, {"I", {"S", "U"}}, {"A", {"R", "W"}}, {"N", {"D", "K"}}, {"M", {"G", "O"}}, {"S", {"H", "V"}}, {"U", {"F", "NIL"}}, {"R", {"L", "NIL"}}, {"W", {"P", "J"}}, {"D", {"B", "X"}}, {"K", {"C", "Y"}}, {"G", {"Z", "Q"}}};  
    string input = argv[1];
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