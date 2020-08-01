/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    /*
    使用哈希表visited进行深度遍历，深度遍历实际上就是递归遍历图中节点：
    1. 当遍历到的节点为空时，返回NULL；
    2. 当遍历到的节点已被访问过，直接返回使用该节点创建的新节点；
    3. 否则，使用该节点创建新节点，并在visited中进行标记：
    3.1 新节点的值为原始节点的值；
    3.2 新节点的邻接列表为与原始节点的邻接列表中的节点一一对应的新节点，在对应过程中，如果不存在该节点，递归调用DFS进行创建，如果存在，则为情况2，直接返回该新节点；
    */
    Node* DFS(Node* node, map<Node*, Node*> &visited){
        if(!node) return NULL;
        /*
        count()为在哈希表中统计个数的方法，可用于判断是否存在该键
        */
        if(visited.count(node)) return visited[node];
        Node* new_node = new Node(node->val);
        visited[node] = new_node;
        for(int i=0; i<node->neighbors.size(); i++){
            new_node->neighbors.push_back(DFS(node->neighbors[i], visited));
        }
        return new_node;
    }

    /*
    图的克隆过程其实就是图的遍历过程，因此可以使用DFS或BFS，又因为图为无向连通图，为了避免重复遍历节点，使用哈希表记录已访问节点；
    由于是做深拷贝，所以哈希表中键值对分别为原节点：新节点，用于返回新节点；
    */
    Node* cloneGraph(Node* node) {
        map<Node*, Node*> visited;
        return DFS(node, visited);
    }
};


/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    /*
    使用哈希表visited进行广度遍历：
    1. 当节点为空时，返回NULL；
    2. 定义队列用来存储当前访问的节点，并将当前节点push进队列中；
    3. 将当前节点作为键，使用当前节点创建的新节点作为值存入visited（新节点的邻接列表先不管）；
    4. 当队列不为空时，循环遍历队列中的节点：
    4.1 取出队头元素，循环遍历队头结点的邻接节点：
    4.1.1 当节点没有访问过时，创建新节点，将原节点push到队列中，并在visited中进行标记；（由于是先创建后标记，所以可以保证visited中的每一个键节点对应的值节点都已经被创建过）
    4.1.2 将队头结点对应的新节点的邻接节点赋值为队头结点的邻接节点对应的新节点；
    */
    Node* DFS(Node* node, map<Node*, Node*> &visited){
        if(!node) return NULL;
        queue<Node*> nodeQ;
        nodeQ.push(node);
        Node* new_node = new Node(node->val);
        visited[node] = new_node;
        while(!nodeQ.empty()){
            Node* temp = nodeQ.front();
            nodeQ.pop();
            for(int i=0; i<temp->neighbors.size(); i++){
                if(!visited.count(temp->neighbors[i])){
                    Node* new_temp = new Node(temp->neighbors[i]->val);
                    visited[temp->neighbors[i]] = new_temp;
                    nodeQ.push(temp->neighbors[i]);
                }
                visited[temp]->neighbors.push_back(visited[temp->neighbors[i]]);
            }
        }
        return new_node;
    }

    /*
    图的克隆过程其实就是图的遍历过程，因此可以使用DFS或BFS，又因为图为无向连通图，为了避免重复遍历节点，使用哈希表记录已访问节点；
    由于是做深拷贝，所以哈希表中键值对分别为原节点：新节点，用于返回新节点；
    */
    Node* cloneGraph(Node* node) {
        map<Node*, Node*> visited;
        return DFS(node, visited);
    }
};