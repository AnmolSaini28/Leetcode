struct Node {
    string value;
    vector<Node*> next;

    void add(vector<string>& path, int id){
        if(!next.empty() && next.back()->value==path[id]) next.back()->add(path, id+1); 
        else next.push_back(new Node(path[id]));
    }

    void build(unordered_set<int>& marked, int& id, vector<vector<string>>& answer, vector<string>& create, bool b){
        int current_id = id;

        if(!b || marked.contains(id)){
            for(auto node : next){
                node->build(marked, ++id, answer, create, false);
            }
        } else {
            create.push_back(value);
            answer.push_back(create);
            for(auto node : next){
                node->build(marked, ++id, answer, create, true);
            }
            create.pop_back();
        }
    }
};

class Solution {
public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        sort(paths.begin(), paths.end());

        auto root = new Node("/");
        for(auto& path : paths)
            root->add(path, 0);

        // folder - id
        unordered_map<string, int> folders;
        unordered_set<int> marked;
        int id = -1;
        dfs(folders, marked, root, id);
        

        vector<vector<string>> answer;
        answer.reserve(paths.size());
        vector<string> temp;
        id = -1;
        for(auto node : root->next){
            node->build(marked, ++id, answer, temp, true);
        }

        return answer;
    }

private:
    string dfs(unordered_map<string, int>& folders, unordered_set<int>& marked, Node* node, int& id){
        if(node->next.empty()) return node->value;

        int current_id = id;
        string sub;
        for(auto next : node->next){
            ++id;
            sub+=dfs(folders, marked, next, id)+"|";
        }

        auto it = folders.find(sub);
        if(it==folders.end()){
            folders[sub] = current_id;
        } else {
            marked.insert(current_id);
            marked.insert(it->second);
        }

        return node->value+":"+sub;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();