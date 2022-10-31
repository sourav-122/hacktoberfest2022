package stack;
import java.util.*;
import java.io.*;

class Stack1{
Scanner sc = new Scanner(System.in);
int maxsize=10;
float stck[];
int top;
Stack1(int max)
{
 maxsize = max;
 top = -1;
 stck= new float[maxsize];
 }
boolean isFull() {
if(top==(maxsize-1))
return true;

else
return false;
}
boolean isEmpty() {
if(top==-1)
return false;
else
    return true;
}

float pop() {
if(top==-1)
System.out.println("Stack is empty");
else
return stck[top--];
return 0;
}
void push(float num) {
if(isFull()==true)
System.out.println("Stack is full");
else
top++;
stck[top]=num;
}
void evaluate(String s) {
  float x=0, y=0;
  char ch[] = s.toCharArray();
  for(char c:ch) {
 if(c>='0' && c<='9') {
push((float)(c-'0'));
 }
 else {
y = pop();
x = pop();
switch(c) {
case '+':
push(x+y);
break;
case '-':
push(x-y);
break;
case '*':
push(x*y);
break;
case '/':
push(x/y);
break;
}
 }
 }
System.out.println(pop());
}
void reverse() {
System.out.println("Enter your choice :\n1.Reverse numbers\n2.Reverse String");
int ch = sc.nextInt();
if(ch==1) {
System.out.println("Enter the number of elements in stack : ");
  int m = sc.nextInt();
 for(int i=0;i<m;i++) {
 System.out.println("Enter the element in stack");
 float val = sc.nextInt();
 push(val);
 }
 for (int i=0;i<m;i++) {
System.out.println(pop());
}}
 else {
System.out.println("Enter String :");
String s = sc.next();
char ch1[] = s.toCharArray();
for(int i=s.length()-1;i>=0;i--) {
System.out.println(ch1[i]);
}
 }
}
}
public class Stacks {
public  static void main(String args[]) throws IOException {
Scanner sc = new Scanner(System.in);
InputStreamReader ir = new InputStreamReader(System.in);
BufferedReader br = new BufferedReader(ir);
int max = 10;
Stack1 obj = new Stack1(max);
int ch=0, n=0;
do {
System.out.println("Enter your choice\n1. Reverse function\n2. Evaluate function");
ch = sc.nextInt();
switch(ch) {
   case 1:{
      obj.reverse();
       break;
}
   case 2:{
   System.out.println("Enter the postfix expression to evaluate ");
   String s = br.readLine();
   obj.evaluate(s);
   break;  
}
   default:
       System.out.println("Invalid input");
}
System.out.println("Do you want to continue :\nPress 1 for yes\nPress 0 to exit");
n=sc.nextInt();
}
while(n==1);
}
}
