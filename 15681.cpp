#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
    int parent = -1;
    vector<int> children;
    int num_of_subtree_vertice = 1;
};

int N, R, Q;
vector<vector<int>> adj;
vector<TreeNode> nodes;


void Input();
void Solution();
int MakeTree(int root);

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    Solution();
}

int MakeTree(int root)
{
    TreeNode& rootNode = nodes[root];
    for(auto child : adj[root])
    {
        TreeNode& childNode = nodes[child];
        if(childNode.parent == -1)
        {
            childNode.parent = root;
            rootNode.children.push_back(child);
            rootNode.num_of_subtree_vertice += MakeTree(child);
        }
    }
    return rootNode.num_of_subtree_vertice;
}

void Input()
{
    cin >> N >> R >> Q;
    --R;
    cin.ignore();
    nodes = vector<TreeNode>(N);
    adj = vector<vector<int>>(N);
    for(int i = 0; i < N - 1; ++i)
    {
        int from, to;
        cin >> from >> to;
        cin.ignore();
        --from;
        --to;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
    nodes[R].parent = R;
    MakeTree(R);
}

void Solution()
{
    Input();
    for(int i = 0; i < Q; ++i)
    {
        int root;
        cin >> root;
        --root;
        cout << nodes[root].num_of_subtree_vertice << '\n';
    }
    // cout << endl;
}