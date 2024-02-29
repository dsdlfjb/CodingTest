/*
����
�����̰� ���󿡼� ���� �����ϴ� ���� �Ҽ��̰�, ��̴� �Ҽ��� ������ ��� ���̴�. ���� �����̰� ���� �����־� �ϴ� �Ҽ��� 7331�̴�.

7331�� �Ҽ��ε�, �ű��ϰԵ� 733�� �Ҽ��̰�, 73�� �Ҽ��̰�, 7�� �Ҽ��̴�. ��, ���ʺ��� 1�ڸ�, 2�ڸ�, 3�ڸ�, 4�ڸ� �� ��� �Ҽ��̴�! �����̴� �̷� ���ڸ� �ű��� �Ҽ���� �̸� �ٿ���.

�����̴� N�ڸ��� ���� �߿��� � ������ �ű��� �Ҽ����� �ñ�������. N�� �־����� ��, �����̸� ���� N�ڸ� �ű��� �Ҽ��� ��� ã�ƺ���.

�Է�
ù° �ٿ� N(1 �� N �� 8)�� �־�����.

���
N�ڸ� �� �߿��� �ű��� �Ҽ��� ������������ �����ؼ� �� �ٿ� �ϳ��� ����Ѵ�.

���� �Է� 1
4
���� ��� 1
2333
2339
2393
2399
2939
3119
3137
3733
3739
3793
3797
5939
7193
7331
7333
7393
*/

#include <iostream>
using namespace std;

static int n;		// DFS �Լ� �ȿ����� ���� ���� �������� ����
void DFS (int num, int jaritsu);
bool isPrime (int num);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	DFS(2, 1);		// �Ҽ�, �ش� �Ҽ��� �ڸ���
	DFS(3, 1);
	DFS(5, 1);
	DFS(7, 1);
}

void DFS(int num, int jaritsu)
{
	if (jaritsu == n)
	{
		// �Ҽ��̸� ���
		if (isPrime(num))
			cout << num << "\n";
		return;
	}
	for (int i = 1; i < 10; i++)
	{
		if (i % 2 == 0) continue;

		if (isPrime(num * 10 + i))
		{
			DFS(num * 10 + i, jaritsu + 1);
		}
	}
}

bool isPrime(int num)
{
	for (int i = 2; i <= num / 2; i++)
	{
		if (num % i == 0) return false;
	}
	
	return true;
}