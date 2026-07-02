class TrieNode {
public:
    vector<TrieNode*> children = vector<TrieNode*>(26, nullptr);
    bool end = false;
};
class Solution {
    vector<vector<char>> board;
    TrieNode* root;
    vector<string> res;

    void insert(TrieNode* root, string word, int i) {
        if (i == word.size()) {
            root->end = true;
            return;
        }
        int x = word[i] - 'a';
        if (!root->children[x]) {
            root->children[x] = new TrieNode();
        }
        insert(root->children[x], word, i+1);
    }
    
    bool search(TrieNode* root, string word, int i) {
        if (i == word.size()) {
            if (root->end) {
                root->end = false;
                return true;
            }
            return false;
        }
        int x = word[i] - 'a';
        if (!root->children[x]) {
            return false;
        }
        return search(root->children[x], word, i+1);
    }

    void backtrack(TrieNode* root, string& curr, int i, int j) {
        if (i < 0 or j < 0 or i >= board.size() or j >= board[0].size() or board[i][j] == '#') {
            return;
        }
        char c = board[i][j];
        int x = c - 'a';
        if (!root->children[x]) {
            return;
        }
        board[i][j] = '#';
        curr.push_back(c);
        if (search(this->root, curr, 0)) {
            res.push_back(curr);
        }
        backtrack(root->children[x], curr, i+1, j);
        backtrack(root->children[x], curr, i-1, j);
        backtrack(root->children[x], curr, i, j+1);
        backtrack(root->children[x], curr, i, j-1);
        curr.pop_back();
        board[i][j] = c;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        this->board = board;
        TrieNode* root = new TrieNode();
        for (auto& w : words) {
            insert(root, w, 0);
        }
        this->root = root;
        string curr = "";
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                backtrack(root, curr, i, j);
            }
        }
        return res;
    }
};
