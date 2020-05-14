class Node{
    public:
    char data;
    unordered_map <char,Node*> child;
    bool terminal;
    Node(char d)
    {
        data = d;
        terminal = false;
    }
};
class Trie {
public:
    /** Initialize your data structure here. */
    Node* root;
    int cnt;
    Trie() {
        root = new Node('\0');
        cnt = 0;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
         Node* temp = root;
        for(int i=0;i<word.size();i++)
        {
            char ch = word[i];
            if(temp->child.count(ch))
            {
                temp = temp->child[ch];
            }
            else
            {
                Node* n = new Node(ch);
                temp->child[ch] = n;
                temp = n;
            }
        }
        temp->terminal = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* temp = root;
        for(int i=0;i<word.size();i++)
        {
            char ch = word[i];
            if(temp->child.count(ch) == 0)
            {
                return false;
            }
            else
            {
                temp = temp->child[ch];
            }
        }
        return temp->terminal;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string pre) {
        Node* temp = root;
        for(int i=0;i<pre.size();i++)
        {
            char ch = pre[i];
            if(temp->child.count(ch) == 0)
            {
                return false;
            }
            else
            {
                temp = temp->child[ch];
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
