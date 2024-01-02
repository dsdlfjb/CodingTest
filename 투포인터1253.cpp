/*
문제
N개의 수 중에서 어떤 수가 다른 수 두 개의 합으로 나타낼 수 있다면 그 수를 “좋다(GOOD)”고 한다.

N개의 수가 주어지면 그 중에서 좋은 수의 개수는 몇 개인지 출력하라.

수의 위치가 다르면 값이 같아도 다른 수이다.

입력
첫째 줄에는 수의 개수 N(1 ≤ N ≤ 2,000), 두 번째 줄에는 i번째 수를 나타내는 Ai가 N개 주어진다. (|Ai| ≤ 1,000,000,000, Ai는 정수)

출력
좋은 수의 개수를 첫 번째 줄에 출력한다.

예제 입력 1 
10
1 2 3 4 5 6 7 8 9 10
예제 출력 1 
8
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<int> A(N, 0);

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    int res = 0;

    for (int k = 0; k < N; k++)
    {
        long find = A[k];
        int i = 0;
        int j = N - 1;

        // 투 포인터 알고리즘
        while (i < j)
        {
            if (A[i] + A[j] == find) 
            {
                if (i != k && j != k)
                {
                    res++;
                    break;
                }

                else if (i == k)
                {
                    i++;
                }

                else
                {
                    j--;
                }
            }

            else if (A[i] + A[j] < find)
            {
                i++;
            }

            else
            {
                j--;
            }
        }
    }

    cout << res << "\n";
}