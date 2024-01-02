/*
문제
수 N개 A1, A2, ..., AN이 주어진다. 이때, 연속된 부분 구간의 합이 M으로 나누어 떨어지는 구간의 개수를 구하는 프로그램을 작성하시오.

즉, Ai + ... + Aj (i ≤ j) 의 합이 M으로 나누어 떨어지는 (i, j) 쌍의 개수를 구해야 한다.

입력
첫째 줄에 N과 M이 주어진다. (1 ≤ N ≤ 106, 2 ≤ M ≤ 103)

둘째 줄에 N개의 수 A1, A2, ..., AN이 주어진다. (0 ≤ Ai ≤ 109)

출력
첫째 줄에 연속된 부분 구간의 합이 M으로 나누어 떨어지는 구간의 개수를 출력한다.

예제 입력 1 
5 3
1 2 3 1 2
예제 출력 1 
7
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<long> S(N, 0);
    vector<long> C(M, 0);
    long answer = 0;
    cin >> S[0];

    for (int i = 1; i < N; i++)
    {
        int tmp = 0;
        cin >> tmp;
        S[i] = S[i - 1] + tmp;
    }

    for (int i = 0; i < N; i++)
    {
        // 합 배열의 모든 값에 % 연산 수행
        int remainder = S[i] % M;

        // 0 ~ i 까지의 구간 합 자체가 0일 때 정답에 더하기
        if (remainder == 0)
        {
            answer++;
        }

        // 나머지가 같은 인덱스의 개수 세기
        C[remainder]++;
    }

    for (int i = 0; i < M; i++)
    {
        if (C[i] > 1)
        {
            // 나머지가 같은 인덱스 중 2개를 뽑는 경우의 수를 더하기
            // C[i]개 중에 2개를 뽑는 경우의 수 계산 공식 => (C[i] * C[i] - 1) / 2
            answer += (C[i] * (C[i] - 1) / 2);
        }
    }

    cout << answer << "\n";
}