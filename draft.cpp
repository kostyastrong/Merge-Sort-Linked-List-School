//#define _GLIBCXX_DEBUG

#include<bits/stdc++.h>
#include <utility>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <map>

typedef long long ll;
typedef long double ld;
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
typedef std::vector<double> vd;

int const MAX = 1401;
double const eps = 2e-7;
int const MOD = 179179179;
int const pppower = 179;
int const INFint = 2e9 + 1000;

// #pragma GCC optimize("-ffast-math")

void solve();

signed main() {
    //freopen("a.in", "r", stdin);
    //srand(time(0));
    freopen("a.in", "r", stdin);
    solve();
}

struct node{
    int data;
    node *next, *prev;
};

void inputList(int n, node *& L) {
    /*L->next = new node;
    L->next->prev = L;
    L = L->next;       */
    std::cin >> L->data;
    for (int i = 1; i < n; ++i) {
        node* p = new node;
        std::cin >> p->data;
        L->next = p;
        p->prev = L;
        L = p;
    }
}

node* mergeSort(int n, node* L, node* R) {  // [L, R]
    if (n <= 1) return L;
    int left = n / 2;
    node* bet = L;
    for (int i = 1; i < left; ++i) {
        bet = bet->next;
    }
    node* Rnext = R->next, * betnext = bet->next;
    bet->next = nullptr; R->next = nullptr;
    node* good;

    L = mergeSort(n / 2, L, bet);
    betnext = mergeSort(n - n / 2, betnext, R);

    if (L->data < betnext->data) {
        good = L;
        L = L->next;
    } else {
        good = betnext;
        betnext = betnext->next;
    }
    node* retL = good;

    while (L != nullptr && betnext != nullptr) {
        if (L->data < betnext->data) {
            good->next = L;
            L = L->next;
        } else {
            good->next = betnext;
            betnext = betnext->next;
        }
        good = good->next;
    }

    while (L != nullptr) {
        good->next = L;
        L = L->next;
        good = good->next;
    }

    while (betnext != nullptr) {
        good->next = betnext;
        betnext = betnext->next;
        good = good->next;
    }

    good->next = Rnext;

    return retL;
}

void solve(){
    node* F = new node;
    node* L = F;
    int n;
    std::cin >> n;
    inputList(n, L);
    F = mergeSort(n, F, L);  // [node, copy_of_F, node, node, ... node, L, node]


    while (F != nullptr) {
        std::cout << F->data << ' ';
        F = F->next;
    }
}
