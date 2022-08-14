class Solution {
    void dfs(unordered_map<string, vector<string>>& adjList,vector<vector<string>>& ladders, vector<string>& seq, string word, string beginWord){
        if (word == beginWord){
            ladders.push_back(seq);
            return;
        }
        vector<string> wordList = adjList[word];
        for(int i=0; i<wordList.size(); i++){
            seq.push_back(wordList[i]);
            dfs(adjList,ladders, seq, wordList[i], beginWord);
            seq.pop_back();
        }
        return;
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        // Get unique words and add beginWord if not exists
        unordered_set<string> uniqueWords;
        uniqueWords.insert(beginWord);
        for(string word: wordList){
            uniqueWords.insert(word);
        }
        unordered_set<string> visited;
        vector<vector<string>> ladders;
        queue<string> q;
        q.push(beginWord);
        visited.insert(beginWord);
        unordered_map<string, vector<string>> adjList;
        while(!q.empty()){
            int nodeCount = q.size();
            while(nodeCount--){
                string lastWordInSeq = q.front();
                q.pop();
                for(int i=0; i<lastWordInSeq.size(); i++){
                    string currWord = lastWordInSeq;
                    for(char c = 'a'; c<='z'; c++){
                        if (c == currWord[i]){
                            continue;
                        }
                        currWord[i] = c;
                        if (uniqueWords.find(currWord) != uniqueWords.end()){
                            adjList[currWord].push_back(lastWordInSeq);
                            if (visited.find(currWord) == visited.end()){
                                q.push(currWord);
                            }
                            visited.insert(currWord);
                        }
                    }
                }
            }
            for(string word: visited) uniqueWords.erase(word);
            visited.clear();
        }
        vector<string> currSeq(1, endWord);
        dfs(adjList, ladders, currSeq, endWord, beginWord);
        for(int i=0; i<ladders.size(); i++) reverse(ladders[i].begin(), ladders[i].end());
        return ladders;   
    }
};