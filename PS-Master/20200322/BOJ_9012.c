#include<stdio.h>
#include<string.h>
#include<stdlib.h>

main()
{
	int N,stack=0;
	char arr[5001];
	char result[10001];
	*result = 0;
	scanf("%d", &N);
	getchar();
	for (int i = 0; i < N; i++)
	{
		gets(arr);
		for (int j = 0; *(arr + j) != 0; j++)
		{
			if (*(arr + j) == '(') stack += 1;
			else stack -= 1;
			if (stack < 0) { stack = -1; break; }
		}
		if (stack == 0) strcat(result, "YES\n");
		else strcat(result, "NO\n");
		stack = 0;
	}
	printf("%s", result);
}