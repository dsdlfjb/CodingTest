/*
����
BOJ �˰��� ķ������ �� N���� �����ϰ� �ִ�. ������� 0������ N-1������ ��ȣ�� �Ű��� �ְ�, �Ϻ� ������� ģ���̴�.

������ ������ ���� ģ�� ���踦 ���� ��� A, B, C, D, E�� �����ϴ��� ���غ����� �Ѵ�.

A�� B�� ģ����.
B�� C�� ģ����.
C�� D�� ģ����.
D�� E�� ģ����.
���� ���� ģ�� ���谡 �����ϴ��� ���ϴ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ����� �� N (5 �� N �� 2000)�� ģ�� ������ �� M (1 �� M �� 2000)�� �־�����.

��° �ٺ��� M���� �ٿ��� ���� a�� b�� �־�����, a�� b�� ģ����� ���̴�. (0 �� a, b �� N-1, a �� b) ���� ģ�� ���谡 �� �� �̻� �־����� ���� ����.

���
������ ���ǿ� �´� A, B, C, D, E�� �����ϸ� 1�� ������ 0�� ����Ѵ�.

���� �Է� 1
5 4
0 1
1 2
2 3
3 4
���� ��� 1
1

���� �Է� 2
5 5
0 1
1 2
2 3
3 0
1 4
���� ��� 2
1

���� �Է� 3
6 5
0 1
0 2
0 3
0 4
0 5
���� ��� 3
0
*/

#include <iostream>
#include <vector>
using namespace std;

static vector<vector<int>> A;		// ���� ����Ʈ A
static vector<bool> isVisited;			// �湮 �迭
static bool isArrive;
void DFS(int now, int depth);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	isArrive = false;
	cin >> n >> m;
	A.resize(n);
	isVisited = vector<bool>(n, false);

	for (int i = 0; i < m; i++)
	{
		int s, e;
		cin >> s >> e;
		// �� �������� ����
		A[s].push_back(e);
		A[e].push_back(s);
	}

	// ��帶�� DFS ����
	for (int i = 0; i < n; i++)
	{
		DFS(i, 1);	// ��� ��忡�� depth 1�� ����
		if (isArrive) break;
	}

	if (isArrive)
		cout << 1;

	else
		cout << 0;
}

void DFS(int now, int depth)
{
	if (depth == 5 || isArrive)
	{
		isArrive = true;
		return;
	}

	isVisited[now] = true;

	for (int i : A[now])
	{
		if (!isVisited[i])
			DFS(i, depth + 1);
	}

	isVisited[now] = false;
}