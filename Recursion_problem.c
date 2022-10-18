//Problem on Recursion (Tower of Hanoi problem)
#include<stdio.h>
#include<conio.h>
int move(int n, char source, char dest, char aux) {
if(n==1)
printf("Move disc from %c to %c \n", source, dest);
else {
move(n-1, source, aux, dest);
move(1, source, dest, aux);
move(n-1, aux, dest, source);
}
}
int main() {
int n, r;
char A, B, C;
printf("Enter the number of disc: \n");
scanf("%d", &n);
move(n, 'A', 'B', 'C');
printf("\n");
return 0;
}
