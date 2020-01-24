#include<stdio.h>
#include<iostream> 

int stack[100001]; 
char result[200002]; 

void push(int*, int*, int); 
void pop(int*, int*); 
int top(int*); 
bool is_empty(int); 

int main() { 
    int n, prev, temp; 
 	int stack_idx = 0; 
 	int result_idx = 0; 
 	int adder = 1; 
 	bool chk = true; 
 
	scanf("%d", &n); 

    for (int i = 0; i < n; ++i) { 
 		scanf("%d", &temp); 
		if (!chk) { 
 			continue; 
 		} 
 
 		if (adder <= n) { 
 			if (is_empty(stack_idx)) { 
				for (; adder <= temp; ++adder) { 
 					push(&stack_idx, &result_idx, adder); 
				} 
				pop(&stack_idx, &result_idx); 
 			} 
 			else { 
 				if (temp == top(&stack_idx)) { 
 					pop(&stack_idx, &result_idx); 
 				} 
                 else if (temp < top(&stack_idx)){ 
                     chk = false; 
                 } 
  				 else { 
 					 for (; adder <= temp; ++adder) { 
 						 push(&stack_idx, &result_idx, adder); 
 					} 
				pop(&stack_idx, &result_idx); 
 				} 
 			} 
 		} 
 		else { 
 			if (temp == top(&stack_idx)) { 
 				pop(&stack_idx, &result_idx); 
 			} 
 			else { 
 				chk = false; 
 			} 
 		} 
 		prev = temp; 
 	}  
 	if (chk) { 
		for (int i = 0; i < result_idx; ++i) { 
 			printf("%c\n", result[i]); 
 		} 
 	} 
 	else { 
 		printf("NO"); 
 	} 
 	return 0; 
 } 

void push(int* stack_idx, int* result_idx, int data) { 
	stack[(*stack_idx)++] = data; 
 	result[(*result_idx)++] = '+'; 
 	return; 
} 
 
 
void pop(int* stack_idx, int* result_idx) { 
	--(*stack_idx); 
 	result[(*result_idx)++] = '-'; 
	return; 
} 
int top(int* stack_idx) { 
 	if (is_empty(*stack_idx)) { 
		return -1; 
    } 
 	return stack[*stack_idx - 1]; 
} 
 
 
 bool is_empty(int stack_idx) { 
 	return (stack_idx == 0) ? true : false; 
} 
