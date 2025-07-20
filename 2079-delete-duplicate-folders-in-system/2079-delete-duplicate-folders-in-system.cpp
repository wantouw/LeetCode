struct Node {
    string name;
    unordered_map<string, Node*> children;
    // string sign;
    bool deleted = false;
    Node(string name): name(name) {}    
};

class Solution {
public:

    void insert(Node* root, vector<string> path){
        Node* curr = root;
        for(auto& folder: path){
            if(curr->children[folder] == NULL){
                curr->children[folder] = new Node(folder);
                // curr = curr[folder];
            }
            curr = curr->children[folder];
        }
    }

    // string calcSign(Node* root, string name){
    //     if(root == NULL){
    //         return "";
    //     }

    //     return name + "(" + calcSign
    // }

    string fillSign(Node* root, unordered_map<string, vector<Node*>>& signMap){
        vector<string> paths;
        for(auto& [name, child]: root->children){
            // cout << "name: " << root->name << " child name: " << child->name << endl;
            string sign = name  + fillSign(child, signMap);
            paths.push_back(sign);
            // signMap[sign].push_back(child);
        }
        sort(paths.begin(), paths.end());
        string result = "(";
        for(auto& path: paths) result+= path;
        result += ")";
        // cout << "name: " << root->name << " sign result: " << result << endl;
        if(root->children.size()!=0) signMap[result].push_back(root);
        return result;
    }

    void checking(unordered_map<string, vector<Node*>>& signMap){
        for(auto& [name, nodes]: signMap){
            if(nodes.size() > 1){
                for(auto& node: nodes){
                    node->deleted = true;
                }
            }
        }
    }

    void ansDfs(Node* root, vector<string>& path, vector<vector<string>>& answer){
        // cout << "root: " << root->name << ", deleted: " << root->deleted << endl; 
        if(!root->deleted){
            path.push_back(root->name);
            answer.push_back(path);
            for(auto& [name, child]: root->children){
                ansDfs(child, path, answer);
            }
            path.pop_back();
        }
    }

    vector<vector<string>> getAnswer(Node* root, unordered_map<string, vector<Node*>>& signMap){
        vector<vector<string>> answer;
        for(auto& [name, child]: root->children){
            vector<string> path;
            ansDfs(child, path, answer);
        }
        return answer;
    }

    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        Node* root = new Node("");
        unordered_map<string, vector<Node*>> signMap;
        for(auto& path: paths){
            insert(root, path);
        }
        fillSign(root, signMap);
        // for(auto& [name, children]: signMap){
        //     cout << name << ", childSize: " << children.size() << endl;
        // }
        checking(signMap);
        return getAnswer(root, signMap);
    }
};