#include<iostream>
#include<algorithm>
using namespace std;
int maxLength(char* a, int n, char* b, int m, int **arr)
{
	if (n == 0 || m == 0)
		return 1;
	if (arr[n + 1][m + 1] != 9999999)
		return arr[n + 1][m + 1];
	if (a[n] == b[m])
	{
		arr[n + 1][m + 1] = maxLength(a, n - 1, b, m - 1, arr) + 1;
	}
	else
		arr[n + 1][m + 1] = max(maxLength(a, n - 1, b, m, arr), maxLength(a, n, b, m - 1, arr));
	return arr[n + 1][m + 1];
}
void print(char* a, int i, char* b, int j, int **arr)
{
	if (i == 0 || j == 0)
		return;
	if (arr[i][j] == arr[i][j - 1])
		print(a, i, b, j - 1, arr);
	else if (arr[i][j] == arr[i - 1][j])
		print(a, i - 1, b, j, arr);
	else if (arr[i][j] != arr[i - 1][j - 1])
	{
		print(a, i - 1, b, j - 1, arr);
		cout << a[i-1] << endl;
	}
}
int main()
{
	char a[5] = {'A', 'D', 'D', 'A', 'H' };
	char b[7] = { 'D', 'A', 'A', 'D', 'H', 'A', 'A' };
	int n = 5;
	int m = 7;
	int **arr = new int*[n + 1];
	for (int i = 0; i < n+1; i++)
	{	
		arr[i] = new int[m+1];
		for (int j = 0; j < m+1; j++)
			arr[i][j] = 9999999;
	}
	cout << maxLength(a, n - 1, b, m - 1, arr) << endl;
	print(a, n, b, m, arr);
	system("pause");
}