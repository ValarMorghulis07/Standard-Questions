void SortedStack :: sort()
{
  stack<int>stk;
  while(!s.empty())
  {
    int temp=s.top();
    s.pop();
    while(!stk.empty() && stk.top()>temp)
    {
     s.push(stk.top());
     stk.pop();
    }
    stk.push(temp);
  }
  while(!stk.empty())
  {
    cout<<stk.top()<<" ";
    stk.pop();
  }

}
