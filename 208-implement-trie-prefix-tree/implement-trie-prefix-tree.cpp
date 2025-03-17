class Trie {
public:
    struct TrieNode{
        bool flag=false;
        map<char, TrieNode*> children;
        
        int cnt=0;
        void setEnd(){
            flag=true;
        }
        bool isEnd=false;
    };
    map<string,int>mp;
    TrieNode* root;
    Trie() {
        root=new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* current=root;
        for(int i=0; i<word.size(); i++){
            if(current->children.find(word[i])==current->children.end()){
                current->children[word[i]]=new TrieNode();
            }
            current=current->children[word[i]];
            string d=word.substr(0,i+1);
            mp[d]++;
        }
        current->isEnd=true;
    }
    
    bool search(string word) {
        TrieNode* current=root;
        for(auto i:word){
            if(current->children.find(i)==current->children.end()){
                return false;
            }
            current=current->children[i];
        }
        return current->isEnd;
    }
    
    bool startsWith(string prefix) {
        if(mp.find(prefix)!=mp.end()){
            return true;
        }
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */