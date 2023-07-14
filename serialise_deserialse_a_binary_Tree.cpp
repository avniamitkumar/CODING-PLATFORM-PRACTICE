class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string serialTree = "";
        serializeTree(root, serialTree);
        return serialTree;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int index = 0;
        return deserializeTree(data, index);
    }
    
private:
    void serializeTree(TreeNode* node, string& serialTree) {
        if (node) serialTree += to_string(node->val) + ",";
        else {
            serialTree += "#,";
            return;
        }
        serializeTree(node->left, serialTree);
        serializeTree(node->right, serialTree);
    }
    
    TreeNode* deserializeTree(string& data, int& idx) {
        if (idx >= data.size()-1) return nullptr;
        TreeNode *node = nullptr;
        string s = "";
        while (data[idx]!=',') {
            s += data[idx];
            idx++;
        }
        if (s=="#") {
            return nullptr;
        } else {
            node = new TreeNode();
            node->val = stoi(s);
        }

        node->left = deserializeTree(data, ++idx);
        node->right = deserializeTree(data, ++idx);
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));