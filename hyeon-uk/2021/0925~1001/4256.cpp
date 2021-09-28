#include<iostream>
#include<algorithm>
using namespace std;

int preorder[1001];
int inorder[1001];
int n, t, cnt = 0;

void postorder(int left, int right) {
	if (left > right) {
		return;//베이스 케이스
	}
	int nodeInd;
    //현재 서브트리의 루트 검색
	for (int i = left; i <= right; i++) {
		if (preorder[cnt] == inorder[i]) {
			nodeInd = i;
			cnt++;//전위순회의 개념을 이용해서,다음 서브트리의 루트를 구하기위해 ++를 해준다.
			break;
		}

	}
	postorder(left, nodeInd - 1);//왼쪽 서브트리에 대한 재귀
	postorder(nodeInd + 1, right);//오른쪽 서브트리에 대한 재귀
	cout << inorder[nodeInd] << " ";//자기자신 출력
}

int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		cnt = 0;
		for (int i = 0; i < n; i++) {
			cin >> preorder[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> inorder[i];
		}
		postorder(0, n - 1);
		cout << "\n";
	}

	return 0;
}