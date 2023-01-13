struct TrieNode{
    TrieNode* left, *right, *mid;
    char val;
    bool end;
};

TrieNode* newNode(char val){
    TrieNode* root = new TrieNode;
    root->val = val;
    root->left = NULL;
    root->right = NULL;
    root->mid = NULL;
    root->end = false;

    return root;
}

TrieNode* insert(TrieNode* root, string key, int idx = 0){
    if(idx >= key.length())
        return NULL;
    
    if(!root){
        root = newNode(key[idx]);
        root->mid = insert(root->mid, key, idx + 1);
        if(idx == key.length() - 1)
            root->end = true;
        return root;
    }

    if(root->val == key[idx]){
        insert(root->mid, key, idx + 1);
        if(idx == key.length() - 1)
            root->end = true;
    }

    else if(root->val > key[idx])
        insert(root->left, key, idx);
    
    else
        insert(root->right, key, idx);

    return root;
}

bool find(TrieNode* root, string key, int idx = 0){
    if(!root || idx >= key.length())
        return false;

    if(root->val == key[idx]){
        if(idx == key.length() - 1){
            if(root->end)
                return true;
            return false;
        }

        return find(root->mid, key, idx + 1);
    }

    if(root->val > key[idx])
        return find(root->left, key, idx);

    return find(root->right, key, idx);
}

int main(){
    TrieNode* root = NULL;
    root = insert(root, "aman");
    root = insert(root, "amanda");
    root = insert(root, "chaman");
    root = insert(root, "man");
    root = insert(root, "cat");

    cout<<find(root, "aman")<<endl;
    cout<<find(root, "amanda")<<endl;
    cout<<find(root, "chaman")<<endl;
    cout<<find(root, "man")<<endl;
    cout<<find(root, "cat")<<endl;
    cout<<find(root, "dog")<<endl;
    cout<<find(root, "am")<<endl;

}