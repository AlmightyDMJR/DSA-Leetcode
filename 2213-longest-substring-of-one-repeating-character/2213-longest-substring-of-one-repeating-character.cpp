class Solution {
    struct Node {
        char leftChar, rightChar;
        int pref, suff, best, len;

        Node() {
            leftChar = rightChar = 0;
            pref = suff = best = len = 0;
        }

        Node(char c) {
            leftChar = rightChar = c;
            pref = suff = best = len = 1;
        }
    };

    vector<Node> tree;

    Node merge(Node &a, Node &b) {
        if (a.len == 0) return b;
        if (b.len == 0) return a;

        Node res;

        res.len = a.len + b.len;
        res.leftChar = a.leftChar;
        res.rightChar = b.rightChar;

        // Prefix
        res.pref = a.pref;

        if (a.pref == a.len && a.rightChar == b.leftChar) {
            res.pref = a.len + b.pref;
        }

        // Suffix
        res.suff = b.suff;

        if (b.suff == b.len && a.rightChar == b.leftChar) {
            res.suff = b.len + a.suff;
        }

        // Best answer completely inside one half
        res.best = max(a.best, b.best);

        // Best substring crossing the middle
        if (a.rightChar == b.leftChar) {
            res.best = max(res.best, a.suff + b.pref);
        }

        return res;
    }

    void build(string &s, int node, int l, int r) {
        if (l == r) {
            tree[node] = Node(s[l]);
            return;
        }

        int mid = l + (r - l) / 2;

        build(s, node * 2, l, mid);
        build(s, node * 2 + 1, mid + 1, r);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    void update(int node, int l, int r, int idx, char c) {
        if (l == r) {
            tree[node] = Node(c);
            return;
        }

        int mid = l + (r - l) / 2;

        if (idx <= mid) {
            update(node * 2, l, mid, idx, c);
        } else {
            update(node * 2 + 1, mid + 1, r, idx, c);
        }

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

public:
    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {
        int n = s.size();

        tree.resize(4 * n);

        // Build segment tree
        build(s, 1, 0, n - 1);

        vector<int> ans;

        for (int i = 0; i < queryCharacters.size(); i++) {
            int idx = queryIndices[i];
            char c = queryCharacters[i];

            // Update the character
            update(1, 0, n - 1, idx, c);

            // Root contains answer for entire string
            ans.push_back(tree[1].best);
        }

        return ans;
    }
};
