#include <bits/stdc++.h>
using namespace std;

const long long P = 31;
const long long MOD = 1e9 + 9;

vector<long long> get_hashes(const string &s) {
    int n = s.size();
    vector<long long> h(n + 1, 0), p(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        h[i] = (h[i - 1] + (s[i - 1] - 'a' + 1) * p[i - 1]) % MOD;
        p[i] = (p[i - 1] * P) % MOD;
    }
    return h;
}

long long substring_hash(const vector<long long>& h, const vector<long long>& p, int l, int r) {
    long long res = (h[r] - h[l] + MOD) % MOD;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string big;
    int n;
    cin >> big >> n;

    vector<string> small(n);
    for (int i = 0; i < n; i++) cin >> small[i];

    int L = big.size();
    vector<long long> h_big = get_hashes(big), p(L + 1, 1);
    for (int i = 1; i <= L; i++) p[i] = (p[i - 1] * P) % MOD;

    vector<long long> small_hash;
    for (auto &s : small) {
        long long h = 0, pp = 1;
        for (char c : s) {
            h = (h + (c - 'a' + 1) * pp) % MOD;
            pp = (pp * P) % MOD;
        }
        small_hash.push_back(h);
    }

    int i = 0;
    bool ok = true;
    while (i < L) {
        bool found = false;
        for (int j = 0; j < n; j++) {
            int len = small[j].size();
            if (i + len <= L) {
                long long h_sub = substring_hash(h_big, p, i, i + len);
                if (h_sub == (small_hash[j] * p[i]) % MOD) {
                    i += len;
                    found = true;
                    break;
                }
            }
        }
        if (!found) {
            ok = false;
            break;
        }
    }

    cout << (ok ? "YES" : "NO");
}