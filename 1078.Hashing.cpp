#include <cstdio>
#include <cstring>
#include <string>
 
using namespace std;
 
bool mark[10004];
bool test(int x) {
    if (x == 1) {
        return false;
    }
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}
 
int main() {
int m,n;
    scanf("%d%d",&m,&n);
    for (;!test(m);++m)
    ;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d",&x);
        if (i) {
            putchar(' ');
        }
        x %= m;
        int j;
        for (j = 0; j < m; ++j) {
            int key = (x + j * j) % m;
            if (!mark[key]) {
                printf("%d",key);
                mark[key] = true;
                break;
            }
        }    
             
        if (j >= m) {
            putchar('-');
        }
         
    }
    puts("");
    return 0;
}
