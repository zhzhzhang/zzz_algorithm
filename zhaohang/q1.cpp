#include<iostream>
#include<map>
#include<string>
#include<vector>

using namespace std;

map<string, int> wordmap;
int main() {
    vector<string> wordList;
    wordList.push_back("hot");
    wordList.push_back("dot");
    wordList.push_back("dog");
    wordList.push_back("lot");
    wordList.push_back("log");
    wordList.push_back("cog");
    if(wordList.size() == 0) return 0;
    wordmap["cog"] = 0;
    dfs("hit", "cog", wordList);
    return wordmap["hit"];
}

int dfs(string beginWord, string endWord, vector<string>& wordList){
        if(beginWord == endWord) {
            return 0;
        }
        if(wordmap.find(beginWord) != wordmap.end()) {
           return wordmap[beginWord]; 
        }
        int minTime = INT_MAX;
        for(int i = 0; i < beginWord.size(); i++) {
            string nextWord = beginWord.replace(0,1,"c");
            if(beginWord == "cit") {
                wordmap[beginWord] = 422;
                return 0;
            }
            else {
                wordmap[beginWord] = 98;
                return 0;
            }
            if(find(wordList.begin(), wordList.end(), nextWord) != wordList.end()){
                //minTime = min(minTime, dfs(nextWord, endWord, wordList));
                wordmap[beginWord] = 22;
                return 0;
            }
        }
        wordmap[beginWord] = 5673;
        return wordmap[beginWord];
}