    #include<bits/stdc++.h>
    using namespace std;
     
    #define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    typedef long long int ll;
    
    ll mex(ll a,ll b,set<ll> S)
    {
        for(ll i=a; i<=b+1; i++)
            if(S.find(i)==S.end())
                return i;
    }
    
    int main()
    {
        boost
        
        int t;
        cin>>t;
        
        while(t--)
        {
            set<ll> S;
            ll n,k,ans=0,a=LLONG_MIN,b,prev_a=LLONG_MIN,prev_b;
            cin>>n>>k;
            
            ll A[n+2];
            
            for(int i=0; i<n; i++){
                cin>>A[i];
                S.insert(A[i]);
                prev_a=max(prev_a,A[i]);
            }
            
            if(k == 0)
                cout<<S.size();
            else
            {
                
                prev_b=mex(0,prev_a,S);
                ll x=ceil((float)(prev_a+prev_b)/2);
                S.insert(x);
                a=max(prev_a,x);
                b=mex(prev_b,a,S);
                k--;
                
                //cout<<prev_a<<" "<<prev_b<<" "<<a<<" "<<b<<endl;
                
                while(k-- && (a!=prev_a || b!=prev_b))
                {
                    prev_a=a;
                    prev_b=b;
                    x=ceil((float)(prev_a+prev_b)/2);
                    S.insert(x);
                    a=max(prev_a,x);
                    b=mex(prev_b,a,S);
                    //cout<<x<<" "<<prev_a<<" "<<prev_b<<" "<<a<<" "<<b<<endl;
                
                }
                // for(auto i:S)
                //     cout<<i<<" ";
                // cout<<endl;
                cout<<S.size();
            }
            
            cout<<endl;
        }
        return 0;
    }
