class Solution {
public:
    vector<int> parent, sz;

    int find_set(int x){
        if(parent[x] == x) return x;
        return parent[x] = find_set(parent[x]);
    }

    bool make_union(int x, int y){
        int a = find_set(x);
        int b = find_set(y);
        if(a == b) return true;
        if(sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
        return false;
    }

    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size()+1;                         // for 3x3 we need 4x4 matrix, so n = grid.size()+1
        parent.resize(n*n);
        sz.resize(n*n);
        for(int i = 0; i<n*n; i++){
            parent[i] = i;
            sz[i] = 1;
        }

        vector<int> rank(n*n, -1);
        int ans = 1;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(i == 0 || j == 0 || i == n-1 || j == n-1){
                    int y = i*n + j;
                    make_union(0, y);                  // to make outerboundary as a cycle
                }
            }
        }
        for(int i = 0; i<grid.size(); i++){
            string str = grid[i];
            for(int j = 0; j<str.size(); j++){
                if(str[j] == '/'){                     // if str[j] = '/' pt are ={ (i+1, j ) , ( i, j+1)}
                    int x = (i+1)*n + j;
                    int y = i*n + (j+1);
                    if (make_union(x, y))
                        ans++;
                }
                else if(str[j] == '\\'){               // if str[j] = '\\' pt are ={ (i, j ) , ( i+1, j+1)}
                    int x = (i + 1) * n + (j+1);
                    int y = i * n + (j);
                    if(make_union(x, y)) ans++;
                }                                      // for str[j] = ' ' just continue.
            }
        }
        return ans;
    }
}; 