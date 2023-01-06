class Solution {
public:
    int ladderLength(string startWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        q.push({startWord,1});

        unordered_set<string> st(wordList.begin(),wordList.end());
        st.erase(startWord);

        while(!q.empty()){
            string word=q.front().first;
            int steps=q.front().second;
            q.pop();
            if(word == endWord){
                return steps;
            }

            for(int i=0;i<word.size();i++){
                char orignal=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    //it exist in the set
                    if(st.find(word)!=st.end()){
                        st.erase(word);
                        q.push({word,steps+1});
                    }
                }
                word[i]=orignal;
            }

        }
        return 0;

    }
};
