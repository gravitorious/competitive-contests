    #include <bits/stdc++.h>
    using namespace std;
    #define int long long
     
    void solve()
    {
    }
     
    signed main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int T;
        cin >> T;
        while (T--)
        {
            string s;
            cin >> s;
            int n = -1;
            // char ch = 'a';
            cout << s.size() - 2 << endl;
            for (int i = s.size() - 2; i >= 0; i--)
            {
                if (s[i] == s[i + 1])
                {
                    n = i + 1;
                    break;
                }
            }
            // cout << n << endl;
            if (n == -1)
            {
                char ch;
                if (s[s.size() - 1] == 'z')
                    ch = 'a';
                else
                    ch = s[s.size() - 1] + 1;
                // s.push_back('b');
                // cout<<ch<<endl;
                // cout<<"here"<<endl;
                cout << s;
                cout << ch << endl;
                // cout << s << ch << endl;
     
                continue;
            }
            int j = 0;
            for (int i = 0; i <= s.size(); i++)
            {
                if (i == n)
                {
                    //    if(n == s.size())
                    char ch = (((s[n] - 'a') + 1) % 26) + 'a';
                    cout << ch;
                }
                else
                {
                    cout << s[j];
                    j++;
                }
            }
            cout << endl;
        }
        return 0;
    }