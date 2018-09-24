#include <algorithm>
#include <cstring>
#include <cstdio>
 
using namespace std;
 
struct node {
char id[15];
int score;
int location;
int local_rank;
int final_rank;
};
 
node a[30010];
 
bool cmp1(const node &a,const node &b) {
    return a.score > b.score;
}
 
bool cmp2(const node &a,const node &b) {
    return cmp1(a, b) || ((a.score == b.score) && (strcmp(a.id, b.id) < 0));
}
 
int main() {
int m, n = 0;
    scanf("%d",&m);
    for (int i = 1; i <= m; ++i) {
        int p;
        scanf("%d",&p);
        for (int j = 0; j < p; ++j) {
            scanf("%s%d",a[n + j].id, &a[n + j].score);
            a[n + j].location = i;
        }
        sort(a + n, a + n + p, cmp1);
        for (int j = 0, r = 1; j < p; ++j) {
            a[n + j].local_rank = (j && (a[n + j].score == a[n + j - 1].score))?r:(r = j + 1);
        }
        n += p;
    }
    sort(a, a + n, cmp2);
    printf("%d\n",n);
    for (int i = 0, r = 1; i < n; ++i) {
        printf("%s %d %d %d\n",a[i].id, (i && (a[i].score == a[i - 1].score))?r:(r = i + 1), a[i].location, a[i].local_rank);
    }
    return 0;
}
