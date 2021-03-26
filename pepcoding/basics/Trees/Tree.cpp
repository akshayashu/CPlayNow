#include <bits/stdc++.h>
#define ll long long
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL)

using namespace std;

class TreeNode
{
public:
	int val;
	TreeNode *left = NULL;
	TreeNode *right = nullptr;
	TreeNode(int data){
		val = data;
	}
	
};

TreeNode* addNode(TreeNode *root, int val){
	if(root == NULL){
		return new TreeNode(val);
	}

	if(root->val > val){
		root->left = addNode(root->left, val);
	}else{
		root->right = addNode(root->right, val);
	}
	return root;
}

TreeNode* constructTree(vector<int> a, int start, int end){
	if(start > end){
		return NULL;
	}

	int mid = (start + end)/2;
	TreeNode *node = new TreeNode(a[mid]);

	node->left = constructTree(a, start, mid-1);
	node->right = constructTree(a, mid+1, end);

	return node;
}

TreeNode* constructTree(vector<int> a){
	return constructTree(a, 0, a.size()-1);
}

void inOrder(TreeNode *root){
	if(root == NULL){
		return;
	}
	inOrder(root->left);
	cout<<root->val<<" ";
	inOrder(root->right);
}

int height(TreeNode *root){
	return (root == NULL) ? -1 : max(height(root->left)+1, height(root->right)+1);
}

int main(){

	fastIO;

	vector<int> a = {1, 2, 4, 7, -2, 6, 8, 14, -4, 72};

	TreeNode *root = constructTree(a);

	inOrder(root);
	cout<<"\nHeight : "<<height(root)<<endl;

	return 0;
}