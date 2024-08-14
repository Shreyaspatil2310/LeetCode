class Solution {
public:

    void store(int a, map<int, int>& mp) {
        for(int i=2; i<=a; i++) {
            int ele = i;
            int div = 2;
            while(ele > 1) {
                while(ele % div == 0 && ele > 1) {
                    ele /= div;
                    mp[div]++;
                }
                div++;
            }
        }
    }
    
    int uniquePaths(int m, int n) {
        // find (m+n-2)! / (m-1)(n-1)

        map<int, int> motha;
        map<int, int> chota1;
        map<int, int> chota2;

        long long a = m + n - 2;

        store(a, motha);
        store(m-1, chota1);
        store(n-1, chota2); 

        for(auto i: motha) {
            if(chota1[i.first]) {
                int mini = min(motha[i.first], chota1[i.first]);
                motha[i.first] -= mini;
                chota1[i.first] -= mini;
                if(motha[i.first] == 0) motha.erase(i.first);
                if(chota1[i.first] == 0) chota1.erase(i.first);
            }
        }

        for(auto i: motha) {
            if(chota2[i.first]) {
                int mini = min(motha[i.first], chota2[i.first]);
                motha[i.first] -= mini;
                chota2[i.first] -= mini;
                if(motha[i.first] == 0) motha.erase(i.first);
                if(chota2[i.first] == 0) chota2.erase(i.first);
            }
        }

        a = 1;
        long long m1 = 1;
        long long n1 = 1;

        for(auto i: motha) a *= pow(i.first, i.second);
        for(auto i: chota1) m1 *= pow(i.first, i.second);
        for(auto i: chota2) n1 *= pow(i.first, i.second);

        a /= m1;
        a /= n1;

        return (int) a;
    }
};