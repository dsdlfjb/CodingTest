/*
문제
BOJ 알고리즘 캠프에는 총 N명이 참가하고 있다. 사람들은 0번부터 N-1번으로 번호가 매겨져 있고, 일부 사람들은 친구이다.

오늘은 다음과 같은 친구 관계를 가진 사람 A, B, C, D, E가 존재하는지 구해보려고 한다.

A는 B와 친구다.
B는 C와 친구다.
C는 D와 친구다.
D는 E와 친구다.
위와 같은 친구 관계가 존재하는지 안하는지 구하는 프로그램을 작성하시오.

입력
첫째 줄에 사람의 수 N (5 ≤ N ≤ 2000)과 친구 관계의 수 M (1 ≤ M ≤ 2000)이 주어진다.

둘째 줄부터 M개의 줄에는 정수 a와 b가 주어지며, a와 b가 친구라는 뜻이다. (0 ≤ a, b ≤ N-1, a ≠ b) 같은 친구 관계가 두 번 이상 주어지는 경우는 없다.

출력
문제의 조건에 맞는 A, B, C, D, E가 존재하면 1을 없으면 0을 출력한다.

예제 입력 1
5 4
0 1
1 2
2 3
3 4
예제 출력 1
1

예제 입력 2
5 5
0 1
1 2
2 3
3 0
1 4
예제 출력 2
1

예제 입력 3
6 5
0 1
0 2
0 3
0 4
0 5
예제 출력 3
0
*/

#include <iostream>
#include <vector>
using namespace std;

static vector<vector<int>> A;		// 연결 리스트 A
static vector<bool> isVisited;			// 방문 배열
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
		// 양 방향으로 저장
		A[s].push_back(e);
		A[e].push_back(s);
	}

	// 노드마다 DFS 실행
	for (int i = 0; i < n; i++)
	{
		DFS(i, 1);	// 모든 노드에서 depth 1로 시작
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