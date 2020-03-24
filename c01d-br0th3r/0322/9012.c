#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct StackType {
	int top;
	char buf[50];
} StackType;

void init(StackType *s) {
	s->top = -1;
}

int is_Empty(StackType *s) {
	if (s->top == -1) {
		return 1;
	}
	
	else {
		return 0;
	}
}

void push(StackType *s, char data) {
	s->top++;
	s->buf[s->top] = data;
}

int pop(StackType *s) {
	if (is_Empty(s) == 1) {
		return 1;
	}
	
	else {
		s->top--;
		return 0;
	}
}

int main() {
	StackType s;
	int i, j, N;
	int flag = 0;
	char buf[50];
	
	scanf("%d", &N);
	
	for (i = 0; i < N; i++) {
		init(&s);
		
		scanf("%s", buf);
		
		for (j = 0; j < strlen(buf); j++) {
			if (buf[j] == '(') {
				push(&s, buf[j]);
			}
			
			else if (buf[j] == ')') {
				flag = pop(&s);
				
				if (flag == 1) {
					break;
				}
			}
		}
		
		if (flag == 1 || s.top != -1) {
			printf("NO\n");
		}
		
		else {
			printf("YES\n");
		}
		
		flag = 0;
	}
	
	return 0;
}
