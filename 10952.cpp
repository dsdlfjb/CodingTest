/*
문제
두 정수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을 작성하시오.

입력
입력은 여러 개의 테스트 케이스로 이루어져 있다.

각 테스트 케이스는 한 줄로 이루어져 있으며, 각 줄에 A와 B가 주어진다. (0 < A, B < 10)

입력의 마지막에는 0 두 개가 들어온다.

출력
각 테스트 케이스마다 A+B를 출력한다.

예제 입력 1 
1 1
2 3
3 4
9 8
5 2
0 0
예제 출력 1 
2
5
7
17
7
*/

#include <iostream>
using namespace std;

int main()
{
    int a, b;

    while(1)
    {
        cin >> a >> b;

        if (a == 0 && b == 0)
            break;
            
        cout << a + b << endl;
    }

    return 0;
}