class Solution {
public:

    struct TrieNode {

        int child[26];
        int bestIndex;

        TrieNode() {

            memset(child, -1, sizeof(child));
            bestIndex = -1;
        }
    };

    vector<TrieNode> trie;

    Solution() {
        trie.push_back(TrieNode());
    }

    // old: updateNode()
    void updateBestIndex(int node, vector<string>& wordsContainer, int index) {

        if (trie[node].bestIndex == -1) {
            trie[node].bestIndex = index;
            return;
        }

        int oldLen = wordsContainer[trie[node].bestIndex].size();
        int newLen = wordsContainer[index].size();

        if (newLen < oldLen) {
            trie[node].bestIndex = index;
        }
        else if (newLen == oldLen && index < trie[node].bestIndex) {
            trie[node].bestIndex = index;
        }
    }

    // old: insert()
    void insertWordIntoTrie(string &word, int index, vector<string>& wordsContainer) {

        int node = 0;

        updateBestIndex(node, wordsContainer, index);

        for (char ch : word) {

            int c = ch - 'a';

            if (trie[node].child[c] == -1) {

                trie[node].child[c] = trie.size();
                trie.push_back(TrieNode());
            }

            node = trie[node].child[c];

            updateBestIndex(node, wordsContainer, index);
        }
    }

    // old: match()
    int findBestMatchingIndex(string &word) {

        int node = 0;

        for (char ch : word) {

            int c = ch - 'a';

            if (trie[node].child[c] == -1)
                break;

            node = trie[node].child[c];
        }

        return trie[node].bestIndex;
    }

    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {

        for (int i = 0; i < wordsContainer.size(); i++) {

            reverse(wordsContainer[i].begin(), wordsContainer[i].end());

            insertWordIntoTrie(wordsContainer[i], i, wordsContainer);
        }

        vector<int> ans;

        for (auto &query : wordsQuery) {

            reverse(query.begin(), query.end());

            ans.push_back(findBestMatchingIndex(query));
        }

        return ans;
    }
};