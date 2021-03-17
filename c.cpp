    #include<bits/stdc++.h>
    using namespace std;
     
    #define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    typedef long long int ll;
    
    int gcd(int A, int B){
        if(!B)  return A;
        else    return gcd(B,A%B);
    }
    
    void solve()
    {
        int n;
        bool flag = true;
        cin>>n;
        
        set<int> S;
        int ele,cnt[101]={0};
        vector<int> V;
        
        for(int i=0; i<n; i++){
            cin>>ele;
            S.insert(ele);
            cnt[ele]++;
        }
        
        while(flag)
        {
            flag=false;
            for(auto i:S)
            {
                if(cnt[i]!=0){
                    V.push_back(i);
                    cnt[i]--;
                }
                if(cnt[i]>0)
                    flag=true;
            }
        }
        for(auto i:V) 
            cout<<i<<" ";
        cout<<endl;
        V.clear();
        S.clear();
    }
    

    int main()
    {
        boost
        
        int t;
        cin>>t;
        
        while(t--)
            solve();

        return 0;
    }
