void twoStacks :: push1(int x)
{
 if(top1<top2-1)
   arr[++top1]=x;
 else
  cout<<"Stack Overflow";

}

/* The method push to push element into the stack 2*/
void twoStacks ::push2(int x)
{
 if(top1<top2-1)
  arr[--top2]=x;
 else
  cout<<"Stack Overflow";
}

/* The method pop to pop element from the stack 1 */
//Return the popped element
int twoStacks ::pop1()
{
 if(top1>=0)
  return arr[top1--];
 else
  return -1;

}
/* The method pop to pop element from the stack 2 */
//Return the popped element
int twoStacks :: pop2()
{
 if(top2<size)
  return arr[top2++];
 else
  return -1;
}
