class TrieNode {
public:
    vector<TrieNode*> children = vector<TrieNode*>(26, nullptr);
    bool end = false;
};
class WordDictionary {
public:
    TrieNode* root = new TrieNode();

    void addWord(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            int i = c - 'a';
            if (!curr->children[i]) {
                curr->children[i] = new TrieNode();
            }
            curr = curr->children[i];
        }    
        curr->end = true;
    }
    
    bool search(string word) {
        return dfs(root, word, 0);
    }

private:
    bool dfs(TrieNode* root, string word, int i) {
        if (!root) {
            return false;
        }
        if (i == word.size()) {
            return root->end;
        }
        char c = word[i];
        bool res = false;
        if (c == '.') {
            for (int j = 0; j < 26; j++) {
                res = res or dfs(root->children[j], word, i+1);
            }
        } else {
            res = dfs(root->children[c-'a'], word, i+1);
        }
        return res;
    }
};
