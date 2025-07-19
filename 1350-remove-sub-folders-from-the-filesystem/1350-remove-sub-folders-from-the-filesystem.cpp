class TrieNode {
public:
    TrieNode* child[27];
    bool isEnd;
    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 27; ++i) child[i] = NULL;
    }
};

int getIndex(char c) {
    if (c == '/') return 26;
    return c - 'a';
}

void insert(TrieNode& root, string s) {
    TrieNode* curr = &root;
    for (char c : s) {
        int idx = getIndex(c);
        if (curr->child[idx] == NULL) curr->child[idx] = new TrieNode();
        curr = curr->child[idx];
    }

    // add '/' at last
    curr->child[26] = new TrieNode();
    curr->child[26]->isEnd = true;
}

bool search(TrieNode& root, string s) {
    TrieNode* curr = &root;
    for (char c : s) {
        if (curr->isEnd) return true;
        int idx = getIndex(c);
        if (curr->child[idx] == NULL) return false;
        curr = curr->child[idx];
    }
    return curr->isEnd;
}

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        TrieNode root = TrieNode();
        vector<string> res;
        for (string f : folder) {
            if (search(root, f)) continue;
            insert(root, f);
            res.emplace_back(f);
        }
        return res;
    }
};