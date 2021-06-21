#include<iostream>
#include<algorithm>
using namespace std;

typedef struct node {
	int data;
	struct node *left, *right;
}node;

node *insert(node *now, int data) {
	if (now == NULL) {
		now = new node();
		now->data = data;
		now->left = now->right = NULL;
	}
	else if (now->data <= data) {
		now->right=insert(now->right, data);
	}
	else {
		now->left = insert(now->left, data);
	}
	return now;
}

void postorder(node *now) {
	if (now == NULL) return;
	postorder(now->left);
	postorder(now->right);
	cout << now->data << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	node *root = NULL;
	int n;
	while (cin >> n) {
		if (n == EOF) break;
		root = insert(root, n);
	}
	postorder(root);
	return 0;
}
