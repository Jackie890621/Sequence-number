#include <stdio.h>
#define iint unsigned long long

iint mod(iint a, iint b, iint c, iint d) 
{
	iint x = ((a % 999999937) * b) % 999999937;
	iint y = ((c % 999999937) * d) % 999999937;
	return ((x % 999999937) + y) % 999999937;
}

iint multiply(int n)
{
	iint M[2][2] = {{1, 2}, {1, 0}};
	iint result[2][2] = {{1, 2}, {1, 0}};
	iint temp[2][2];
	for (int i = 3; i <= n; i++) {
		temp[0][0] = mod(M[0][0], result[0][0], M[0][1], result[1][0]);
		temp[0][1] = mod(M[0][0], result[0][1], M[0][1], result[1][1]);
		temp[1][0] = mod(M[1][0], result[0][0], M[1][1], result[1][0]);
		temp[1][1] = mod(M[1][0], result[0][1], M[1][1], result[1][1]);
		for (int j = 0; j < 2; j++) {
                	for (int k = 0; k < 2; k++) {
				result[j][k] = temp[j][k];
			}
		}
	}
	return (result[1][0] + result[1][1]) % 999999937;
}

int main() 
{
	int n;
	int order[100];
	iint ans[100];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &order[i]);
	}
	//printf("\n\n");
	for (int i = 0; i < n; i++) {
		ans[i] = multiply(order[i]);
		printf("%llu\n", ans[i]);
	}
	return 0;
}
