class Solution {
public:
    struct Node {
        int value;
        pair<int, int> coordinate;
        int parent;
        vector<int> childrens;
        Node(int value, pair<int, int> coordinate, int parent): value(value), coordinate(coordinate), parent(parent) {};
    };

    unordered_map<int, Node*> coordinates;

    void connect(Node* node, int t, vector<vector<int>>& grid){
        int i = node->coordinate.first, j = node->coordinate.second;
        int neighbor;
        Node* neighborNode;
        if(i > 0 && grid[i-1][j] <= t){
            neighbor = grid[i-1][j];
            neighborNode = coordinates[neighbor];
            unionSet(neighborNode, neighbor, node);
        }
        if(j > 0 && grid[i][j-1] <= t){
            neighbor = grid[i][j-1];
            neighborNode = coordinates[neighbor];
            if(node->parent != node->value){
                stealSet(neighborNode, neighbor, node);
            }
            else {
                unionSet(neighborNode, neighbor, node);
            }
        }
        if(i < grid.size() - 1 && grid[i+1][j] <= t){
            neighbor = grid[i+1][j];
            neighborNode = coordinates[neighbor];
            if(node->parent != node->value){
                stealSet(neighborNode, neighbor, node);
            }
            else {
                unionSet(neighborNode, neighbor, node);
            }
        }
        if(j < grid.size() - 1 && grid[i][j+1] <= t){
            neighbor = grid[i][j+1];
            neighborNode = coordinates[neighbor];
            if(node->parent != node->value){
                stealSet(neighborNode, neighbor, node);
            }
            else {
                unionSet(neighborNode, neighbor, node);
            }
        }
    }

    void stealSet(Node* neighborNode, int neighbor, Node* currNode){
        Node* parentNode = coordinates[neighborNode->parent];
        Node* currParentNode = coordinates[currNode->parent];
        if(parentNode == currParentNode) return;
        for(auto child: parentNode->childrens){
            Node* childNode = coordinates[child];
            childNode->parent = currParentNode->value;
            currParentNode->childrens.push_back(child);
        }
        parentNode->childrens.clear();
        parentNode->parent = currParentNode->value;
        currParentNode->childrens.push_back(parentNode->value);
        return;
    }

    void unionSet(Node* neighborNode, int neighbor, Node* currNode){
        Node* parentNode = coordinates[neighborNode->parent];
        currNode->parent = parentNode->value;
        parentNode->childrens.push_back(currNode->value);
    }

    int swimInWater(vector<vector<int>>& grid) {
        int length = grid.size();
        int endpoint = grid[length-1][length-1];
        int startpoint = grid[0][0];
        for(int i = 0 ; i < length ; i++){
            for(int j = 0 ; j < length ; j++){
                coordinates[grid[i][j]] = new Node(grid[i][j], {i, j}, grid[i][j]);
            }
        }
        for(int i = 0 ; i < length * length ; i++){
            if(coordinates[i] != nullptr){
                connect(coordinates[i], i, grid);
                if(coordinates[endpoint]->parent == coordinates[startpoint]->parent) return i;
            }
        }
        int result = 0;
        return result;
    }
};