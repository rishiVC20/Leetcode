#define ll long long
map<ll,ll>mp;
set<ll,greater<ll>>st;

struct TrieNode{
    bool flag=false;
    map<char, TrieNode*> children;
    int cnt=0;
    void setEnd(){
        flag=true;
    }
    bool isEnd=false;
    // bool isEnd(){
    //     return flag;
    // }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }

    void insert(string word, int k) {
        TrieNode* current = root;
        for (int i=0; i<word.size(); i++) {
            if (current->children.find(word[i]) == current->children.end()) {
                current->children[word[i]] = new TrieNode();
            }
            current = current->children[word[i]];
            current->cnt++;
            if(current->cnt>=k){
                // cout<<"lg ";
                mp[i+1]++;
                if(mp[i+1]==1){
                    // cout<<"gh ";
                    st.insert(i+1);
                }
            }
        }
        current->isEnd = true;
    }

    void erase(string &word, int k) {
        TrieNode *current = root;
        for(int i=0; i<word.size(); i++){
            current=current->children[word[i]];
            current->cnt--;
            if(current->cnt == k-1){
                // cout<<"hh ";
                // if(mp.find(i+1)==mp.end()){
                //     continue;
                // }
                mp[i+1]--;
                // cout<<i<<' '<<mp[i+1]<<endl;
                if(mp[i+1]==0){
                    st.erase(i+1);
                }
            }
        }
        current->isEnd=true;
    } 
};


class Solution {
public:
    vector<int> longestCommonPrefix(vector<string>& words, int k) {
        mp.clear();
        st.clear();
        Trie* tr=new Trie();
        vector<int>ans;
        for(auto i:words){
            tr->insert(i,k);
        }
        // for(auto i:st){
        //     cout<<i<<' ';
        // }
        // cout<<endl;
        for(int i=0; i<words.size(); i++){
            tr->erase(words[i],k);
            // for(auto i:st){
            //     cout<<i<<' ';
            // }
            // cout<<endl;
            if(st.size()==0){
                // cout<<"ho ";
                ans.push_back(0);
            }
            else{
                ans.push_back(*st.begin());
            }
            tr->insert(words[i],k);
        }

        return ans;
    }
};