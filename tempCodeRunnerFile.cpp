 // void max()
    // {
    //     int bigger = 0;
    //     for (int i = 0; i <= top; i++)
    //     {
    //         if (arr[i] > bigger)
    //         {
    //             bigger = arr[i];
    //         }
    //     }
    //     cout << bigger << endl;
    // }
    // void min()
    // {
    //     int bigger = INT_MAX;
    //     for (int i = 0; i <= top; i++)
    //     {
    //         if (arr[i] < bigger)
    //         {
    //             bigger = arr[i];
    //         }
    //     }
    //     cout << bigger << endl;
    // }
    // void sum()
    // {
    //     int summ = 0;
    //     for (int i = 0; i <= top; i++)
    //     {
    //         summ += arr[i];
    //     }
    //     cout << summ << endl;
    // }
    // void reverse()
    // {
    //     int start = 0;
    //     int end = top;
    //     while (start < end)
    //     {
    //         int a = arr[start];
    //         arr[start] = arr[end];
    //         arr[end] = a;
    //         start++;
    //         end--;
    //     }
    // }
    // void palindrome()
    // {
    //     int start = 0;
    //     int end = top;
    //     while (start < end)
    //     {
    //         if (arr[start] != arr[end])
    //         {
    //             cout << "not palindrome";
    //             return;
    //         }
    //         start++;
    //         end--;
    //     }
    //     cout << "palindrome";
    // }
    // bool balanced(string s)
    // {
    //     stack<char> ch;
    //     for (char a : s)
    //     {
    //         if (a == '(' || a == '{' || a == '[')
    //         {
    //             ch.push(a);
    //         }
    //         else
    //         {
    //             if (ch.empty())
    //             {
    //                 return;
    //             }
    //             if (a == ')' && ch.top() != '(' || a == '}' && ch.top() != '{' || a == ']' && ch.top() != '[')
    //             {
    //             return;
    //             }
    //             ch.pop();
    //         }
    //     }
    //     return ch.empty();
    // }
    // void sort(){
    //     for(int i=0;i<=top;i++){
    //         for (int j = i+1; j <=top; j++)
    //         {
                
    //             if(arr[i]>arr[j]){
    //             int temp=arr[i];
    //             arr[i]=arr[j];
    //             arr[j]=temp;
    //         }
    //        }
        
           

    //    }
    // }