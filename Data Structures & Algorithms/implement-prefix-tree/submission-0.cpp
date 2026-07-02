class TrieNode {
public:
    vector<TrieNode*> children = vector<TrieNode*>(26, nullptr);
    bool endOfWord = false;
    TrieNode() {}
};
class PrefixTree {
    TrieNode* root = new TrieNode();
public:
    PrefixTree() {}
    
    void insert(string word) {
        TrieNode* temp = root;
        for (char c : word) {
            int i = c - 'a';
            if (!temp->children[i]) {
                temp->children[i] = new TrieNode();
            }
            temp = temp->children[i];
        }
        temp->endOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* temp = root;
        for (char c : word) {
            int i = c - 'a';
            if (!temp->children[i]) {
                return false;
            }
            temp = temp->children[i];
        }
        return temp->endOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* temp = root;
        for (char c : prefix) {
            int i = c - 'a';
            if (!temp->children[i]) {
                return false;
            }
            temp = temp->children[i];
        }
        return true;
    }
};
