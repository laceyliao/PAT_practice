#include <cstdio>
#include <stack>
#include <cstring>
#include <string>
using namespace std;
 
stack<pair<int,int> > st;
char s[10];
 
 
int main() {
int n;
bool mark = false;
    scanf("%d",&n);
    for (n <<= 1; n; --n) {
        scanf("%s",s);
        if (s[1] == 'u') { //push
            int x;
            scanf("%d",&x);
            st.push(make_pair(x,0));
             
        }
        else {
            while ((!st.empty()) && (st.top().second == 1)) {
                if (mark) {
                    putchar(' ');
                }
                else {
                    mark = true;
                }
                printf("%d",st.top().first);
                st.pop();
            }
            if (!st.empty()) {
                st.top().second = 1;
            }
        }
    }
    while (!st.empty()) {
        if (mark) {
            putchar(' ');
        }
        else {
            mark = true;
        }
        printf("%d",st.top().first);
        st.pop();
    }
    puts("");    
    return 0;
}
