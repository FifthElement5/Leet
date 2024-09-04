#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

// Definicja struktury węzła drzewa binarnego
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        unordered_map<int, TreeNode*> parentMap;
        TreeNode* startNode = findStartNode(root, startValue);
        populateParentMap(root, parentMap);

        queue<TreeNode*> q;
        q.push(startNode);
        unordered_set<TreeNode*> visitedNodes;
        unordered_map<TreeNode*, pair<TreeNode*, string>> pathTracker;
        visitedNodes.insert(startNode);

        while (!q.empty()) {
            TreeNode* currentNode = q.front();
            q.pop();

            if (currentNode->val == destValue) {
                return backtrackPath(currentNode, pathTracker);
            }

            if (parentMap.find(currentNode->val) != parentMap.end()) {
                TreeNode* parentNode = parentMap[currentNode->val];
                if (visitedNodes.find(parentNode) == visitedNodes.end()) {
                    q.push(parentNode);
                    pathTracker[parentNode] = {currentNode, "U"};
                    visitedNodes.insert(parentNode);
                }
            }

            if (currentNode->left != nullptr && visitedNodes.find(currentNode->left) == visitedNodes.end()) {
                q.push(currentNode->left);
                pathTracker[currentNode->left] = {currentNode, "L"};
                visitedNodes.insert(currentNode->left);
            }

            if (currentNode->right != nullptr && visitedNodes.find(currentNode->right) == visitedNodes.end()) {
                q.push(currentNode->right);
                pathTracker[currentNode->right] = {currentNode, "R"};
                visitedNodes.insert(currentNode->right);
            }
        }

        return "";
    }

private:
    string backtrackPath(TreeNode* node, unordered_map<TreeNode*, pair<TreeNode*, string>> pathTracker) {
        string path;
        while (pathTracker.count(node)) {
            path += pathTracker[node].second;
            node = pathTracker[node].first;
        }
        reverse(path.begin(), path.end());
        return path;
    }

    void populateParentMap(TreeNode* node, unordered_map<int, TreeNode*>& parentMap) {
        if (node == nullptr) return;

        if (node->left != nullptr) {
            parentMap[node->left->val] = node;
            populateParentMap(node->left, parentMap);
        }

        if (node->right != nullptr) {
            parentMap[node->right->val] = node;
            populateParentMap(node->right, parentMap);
        }
    }

    TreeNode* findStartNode(TreeNode* node, int startValue) {
        if (node == nullptr) return nullptr;

        if (node->val == startValue) return node;

        TreeNode* leftResult = findStartNode(node->left, startValue);
        if (leftResult != nullptr) return leftResult;
        return findStartNode(node->right, startValue);
    }
};

// Funkcja pomocnicza do tworzenia nowego węzła
TreeNode* createNode(int val) {
    return new TreeNode(val);
}

int main() {
    // Tworzenie przykładowego drzewa: [5,1,2,3,null,6,4]
    TreeNode* root = createNode(5);
    root->left = createNode(1);
    root->right = createNode(2);
    root->left->left = createNode(3);
    root->right->left = createNode(6);
    root->right->right = createNode(4);

    int startValue = 3;
    int destValue = 6;

    Solution sol;
    string directions = sol.getDirections(root, startValue, destValue);
    cout << "Directions from " << startValue << " to " << destValue << ": " << directions << endl;

    // Zwalnianie pamięci (możesz dodać bardziej zaawansowane zwalnianie, jeśli jest to potrzebne)
    delete root->left->left;
    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
