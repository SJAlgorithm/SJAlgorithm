#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void one(char **p, int index, int x) {
	p[index-1][x - 1] = 'b';
	return;
}
void two(char **p, int index, int x) {
	p[index - 1][x - 1] = 'a';
	return;
}
void three(char **p, int index) {
	int i;
	for (i = 18; i >= 0; i--) {
		p[index - 1][i+1] = p[index - 1][i];
	}
	p[index - 1][0] = 'a';
	return;
}
void four(char **p, int index) {
	int i;
	for (i = 0; i < 19; i++) {
		p[index - 1][i] = p[index - 1][i+1];
	}
	p[index - 1][19] = 'a';
	return;
}

int check(char **p,int n) {
	int i, j,cnt=0;
	int *a = (int *)calloc(n, sizeof(int));
	for (i = 0; i < n; i++) {
		if (a[i] != -1) {
			cnt++;
			for (j = i + 1; j < n; j++) {
				if (strcmp(p[i], p[j]) == 0) {
					a[j] = -1;
				}
			}
		}
	}
	return cnt;
}

int main() {
	int n, m, i,op,index,x,j;
	char **p;
	scanf("%d %d", &n, &m);
	p = (char **)malloc(n*sizeof(char *));
	for (i = 0; i < n; i++) {
		p[i] = (char *)malloc(21*sizeof(char));
		for (j = 0; j < 20; j++) {
			p[i][j] = 'a';
		}
		p[i][j] = '\0';
	}
	for (i = 0; i < m; i++) {
		scanf("%d %d", &op,&index);
		switch (op) {
		case 1:
			scanf("%d", &x);
			one(p, index, x);
			break;
		case 2:
			scanf("%d", &x);
			two(p, index, x);
			break;
		case 3:
			three(p, index);
			break;
		case 4:
			four(p, index);
			break;
		}
	}
	printf("%d", check(p,n));
}