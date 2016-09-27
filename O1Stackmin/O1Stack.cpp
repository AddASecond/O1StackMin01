#include <stdio.h>
#include <string.h>

//typedef struct varRETURN {
//	int *a, *b, len_a;
//}RETURN,*PRETURN;

int pop(int *a, int *b, int len_a){
	a[len_a-1] = 0xFFFFFFFFCCCCCCCC;
	b[len_a-1] = 0xFFFFFFFFCCCCCCCC;
	len_a = len_a - 1;
	return len_a;
};

int push(int *a, int *b, int len_a, int input) {
	a[len_a] = input;
	b[len_a] = a[len_a];
	if (len_a > 0 && a[len_a] > b[len_a - 1]) {
		b[len_a] = b[len_a -1];
	}
	len_a = len_a + 1;
	return len_a;
}

int main() {
	int input, a[10], b[10], i = 0, len_a = 0;
	char action[6];
	//1.1 Read the default value of uninitialized array
	//0xFFFF FFFF CCCC CCCC
	//for (i = 0; i < sizeof(a) / 4; i++) {
	//	printf("%d\n", a[i]);
	//}
	
	////1.2 push all the given numbers
	//for (i = 0; i < sizeof(a)/4; i++) {
	//	scanf_s("%d",&input);
	//	len_a = push(a,b,len_a,input);
	//	//len_a = len_a + 1;
	//	//b[i] = a[i];
	//	//if (i > 0 && a[i] > b[i - 1]) {
	//	//	b[i] = b[i-1];
	//	//}
	//	printf("length: %d\n", len_a);
	//	printf("%d,%d\n",a[i],b[i]);
	//}

	//1.3 test code (there is a space in the end)
	//printf("length: %d\n", len_a);

	//if (!strcmp(action, "push")) { 
	//	printf("haha,push begin!\n"); 
	//}
	//else { printf("%s",action); }
	printf("Welcome to O(1) Stack.\nPlease input push/pop to take stack actions and end to exit.\n");
	while (strcmp(action, "end")) {
		// read the input action
		scanf_s("%s", action, 6);
		printf("Your input is: %s\n", action);
		if (!strcmp(action, "push") && len_a < sizeof(a) / 4) {
			printf("Please input a number to push into the stack:\n");
			scanf_s("%d", &input);
			len_a = push(a, b, len_a, input);
			printf("Number %d is pushed into the stack.\n", a[len_a-1]);
			printf("Stack length: %d, min is %d\n", len_a,b[len_a-1]);
		}
		else if (!strcmp(action, "pop") && len_a > 0) {
			printf("Number %d is poped from the stack:\n", a[len_a-1]);
			len_a = pop(a, b, len_a);
			printf("Stack length: %d, min is %d\n", len_a,b[len_a-1]);
		}
		else {
			printf("Can't push/pop because size of array\n");
		}
	}

	//printf("%s",action);
	//len_a = pop(a,b,len_a);
	//printf("length: %d\n", len_a);
	//for (i = 0; i < sizeof(a) / 4; i++) {
	//	printf("%d,%d\n", a[i], b[i]);
	//}
	return 0;
}