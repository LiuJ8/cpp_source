    #include<iostream>
    #include<algorithm>
    #include<cstring>
    using namespace std;
    string s,t;
    const int N = 10000;
    int sum=1;
    int next[N];
    void getNext(string t)
    {
        int k=-1,j=0;
        next[0]=-1;
    while(j<(int)t.length())
    {
        if(k==-1||t[j]==t[k])
        {
            k++;j++;
            next[j]=k;
        }
        else k=next[k];
    }
    }
    int KMP(string s,string t)
    {
        int i=0,j=0;
        while(i<(int)s.length()&&j<(int)t.length())
        {
            if(j==-1||s[i]==t[j])
            {
                i++;j++;  
            }
            else j=next[j],sum++;
        }
        if(j>=(int)t.length()) return i-(int)t.length();
        return 0;

    }
    int main()
    {
    
        cin>>s>>t;
        getNext(t);
        if(KMP(s,t))  cout<<sum;
        else  cout<<"0";
    }