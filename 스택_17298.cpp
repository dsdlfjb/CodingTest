/*
문제
크기가 N인 수열 A = A1, A2, ..., AN이 있다. 수열의 각 원소 Ai에 대해서 오큰수 NGE(i)를 구하려고 한다. Ai의 오큰수는 오른쪽에 있으면서 Ai보다 큰 수 중에서 가장 왼쪽에 있는 수를 의미한다. 그러한 수가 없는 경우에 오큰수는 -1이다.

예를 들어, A = [3, 5, 2, 7]인 경우 NGE(1) = 5, NGE(2) = 7, NGE(3) = 7, NGE(4) = -1이다. A = [9, 5, 4, 8]인 경우에는 NGE(1) = -1, NGE(2) = 8, NGE(3) = 8, NGE(4) = -1이다.

입력
첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000,000)이 주어진다. 둘째 줄에 수열 A의 원소 A1, A2, ..., AN (1 ≤ Ai ≤ 1,000,000)이 주어진다.

출력
총 N개의 수 NGE(1), NGE(2), ..., NGE(N)을 공백으로 구분해 출력한다.

예제 입력 1 
4
3 5 2 7
예제 출력 1 
5 7 7 -1
예제 입력 2 
4
9 5 4 8
예제 출력 2 
-1 8 8 -1
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> A(N, 0);
    vector<int> ans(N, 0);

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    stack<int> myStack;
    myStack.push(0);

    for (int i = 1; i < N; i++)
    {   
        // 스택이 비어있지 않고 현재 수열이 스택 top 위치의 값보다 크면
        while (!myStack.empty() && A[myStack.top()] < A[i])
        {
            ans[myStack.top()] = A[i];
            myStack.pop();
        }
        
        // 신규 데이터 push()
        myStack.push(i);
    }

    // 현재 수열의 길이까지 다 돌았는데도 스택이 비지 않았다면
    while (!myStack.empty())
    {
        ans[myStack.top()] = -1;
        myStack.pop();
    }

    for (int i = 0; i < N; i++)
    {
        cout << ans[i] << " ";
    }
}