#include <stdio.h>
typedef long long ll;
struct SeTreeNode {
    int left, right;
    ll lazy;
    ll len;
    ll sum;
};
const int maxn = 400000; //开四倍空间，10的5次方
SeTreeNode tree[maxn];
ll a[100010];
void build(int id, int l, int r);
void update(int id, int l, int r, ll val);
void PushDown(int id);

ll query(int id, int l, int r);

int main()
{
    int T, n, a1, a2, q;
    ll a3;
    char s[12];
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    build(1, 1, n); //建树

    while (q--) {
        scanf(" %s", s);

        scanf("%d%d", &a1, &a2);
        if (s[0] == 'Q') {
            ll ans = query(1, a1, a2);
            printf("%lld\n", ans);
        }
        if (s[0] == 'C') {
            scanf("%lld", &a3);
            update(1, a1, a2, a3);
        }
    }
    return 0;
}
void build(int id, int l, int r)
{
    tree[id].left = l, tree[id].right = r;
    tree[id].len = tree[id].right - tree[id].left + 1;
    tree[id].lazy = 0;
    if (tree[id].left == tree[id].right) {
        tree[id].sum = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    tree[id].sum = tree[id * 2].sum + tree[id * 2 + 1].sum;
}
ll query(int id, int l, int r)
{
    if (tree[id].left >= l && tree[id].right <= r)
        return tree[id].sum;
    if (tree[id].left > r || tree[id].right < l)
        return 0;
    if (tree[id].lazy)
        PushDown(id);
    return query(id * 2, l, r) + query(id * 2 + 1, l, r);
}
void update(int id, int l, int r, ll val)
{
    if (tree[id].left >= l && tree[id].right <= r) {
        tree[id].sum += val * tree[id].len;
        tree[id].lazy += val;
        return;
    }
    if (tree[id].left > r || tree[id].right < l)
        return;
    if (tree[id].lazy)
        PushDown(id);
    update(id * 2, l, r, val);
    update(id * 2 + 1, l, r, val);
    tree[id].sum = tree[id * 2].sum + tree[id * 2 + 1].sum;
}
void PushDown(int id)
{
    if (tree[id].lazy) {
        tree[id * 2].lazy += tree[id].lazy;
        tree[id * 2 + 1].lazy += tree[id].lazy;
        tree[id * 2].sum += tree[id].lazy * tree[id * 2].len;
        tree[id * 2 + 1].sum += tree[id].lazy * tree[id * 2 + 1].len;
        tree[id].lazy = 0;
    }
}
//题目链接：https://vjudge.net/problem/POJ-3468
//暴露接口版不知要如何改写，但是基本的几个函数是绝对没问题的。
//函数中的大于等于符号不要写错