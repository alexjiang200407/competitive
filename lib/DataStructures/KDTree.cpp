#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cassert>
#include <bitset>
#include <cstring>
#include <queue>
#include <set>
#include <cmath>
#include <tuple>
#include <map>

using namespace std;

typedef long long ll;
#define int ll
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long> vl;
typedef string str;
typedef pair<int, int> pii;
typedef pair<long, long> pllll;

#define all(a) a.begin(), a.end()
#define Debug(x) cout << #x " = " << (x) << '\n'
#define for_n(s, e, i) for (ll i = s; i < e; i++)
#define for_e(e,of) for (auto& e : of)
#define pb push_back

const ll MOD=1e9+7;
ll madd(ll a, ll b) { return (a + b) % MOD; }

const int directions[4][2]={-1,0,0,-1,0,1,1,0};

// Template class for KDTree with K dimensions
template <size_t K, typename T>
class KDTree {
private:
    // Node structure representing each point in the KDTree
    struct Node {
        // Point in K dimensions
        array<T, K> point; 
        // Pointer to left child
        Node* left;          
        // Pointer to right child
        Node* right;            

        // Constructor to initialize a Node
        Node(const array<T, K>& pt) : point(pt), left(nullptr), right(nullptr) {}
    };

    Node* root; // Root of the KDTree

    // Recursive function to insert a point into the KDTree
    Node* insertRecursive(Node* node, const array<T, K>& point, int depth) {
        // Base case: If node is null, create a new node
        if (node == nullptr) return new Node(point);

        // Calculate current dimension (cd)
        int cd = depth % K;

        // Compare point with current node and decide to go left or right
        if (point[cd] < node->point[cd])
            node->left = insertRecursive(node->left, point, depth + 1);
        else
            node->right = insertRecursive(node->right, point, depth + 1);

        return node;
    }

    // Recursive function to search for a point in the KDTree
    bool searchRecursive(Node* node, const array<T, K>& point, int depth) const {
        // Base case: If node is null, the point is not found
        if (node == nullptr) return false;

        // If the current node matches the point, return true
        if (node->point == point) return true;

        // Calculate current dimension (cd)
        int cd = depth % K;

        // Compare point with current node and decide to go left or right
        if (point[cd] < node->point[cd])
            return searchRecursive(node->left, point, depth + 1);
        else
            return searchRecursive(node->right, point, depth + 1);
    }

    // returns the number of points in this sub tree that lie inside the hyper rectangle formed by q_min and q_max
    int rangeQueryRecursive(Node* node, const array<T, K>& q_min, const array<T, K>& q_max, int depth) const {
        // Base case: If node is null, return 0
        if (node == nullptr) return 0;

        // Check if the current node lies within the range
        bool inside = true;
        for (size_t i = 0; i < K; i++) {
            if (node->point[i] < q_min[i] || node->point[i] > q_max[i]) {
                inside = false;
                break;
            }
        }

        // Start with a count of 1 if the point is inside the range
        int count = inside ? 1 : 0;

        // Calculate the current dimension (cd)
        int cd = depth % K;

        // Recursively check left and right subtrees, depending on the range
        if (q_min[cd] <= node->point[cd]) {
            count += rangeQueryRecursive(node->left, q_min, q_max, depth + 1);
        }
        if (q_max[cd] >= node->point[cd]) {
            count += rangeQueryRecursive(node->right, q_min, q_max, depth + 1);
        }

        return count;
    }

    // Recursive function to print the KDTree
    void printRecursive(Node* node, int depth) const {
        // Base case: If node is null, return
        if (node == nullptr) return;

        // Print current node with indentation based on depth
        for (int i = 0; i < depth; i++) cout << "  ";
        cout << "(";
        for (size_t i = 0; i < K; i++) {
            cout << node->point[i];
            if (i < K - 1) cout << ", ";
        }
        cout << ")" << endl;

        // Recursively print left and right children
        printRecursive(node->left, depth + 1);
        printRecursive(node->right, depth + 1);
    }

public:
    // Constructor to initialize the KDTree with a null root
    KDTree() : root(nullptr) {}

    // Public function to insert a point into the KDTree
    void insert(const array<T, K>& point) {
        root = insertRecursive(root, point, 0);
    }

    // Public function to search for a point in the KDTree
    bool search(const array<T, K>& point) const {
        return searchRecursive(root, point, 0);
    }

    // Public function to count points within a K-dimensional range
    int rangeQuery(const array<T, K>& q_min, const array<T, K>& q_max) const {
        return rangeQueryRecursive(root, q_min, q_max, 0);
    }

    // Public function to print the KDTree
    void print() const {
        printRecursive(root, 0);
    }
};
