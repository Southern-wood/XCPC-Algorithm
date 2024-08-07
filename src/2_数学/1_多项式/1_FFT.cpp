#include <bits/stdc++.h>

using namespace std;

typedef complex<double> Complex;
typedef vector<Complex> Poly;
const double Pi = acos(-1);
int r[10000010];
int n, m, limit = 1, cnt;
void FFT(Poly &f, bool inv = false) {
	for (int i = 0; i < limit; i++) {
		if (i < r[i]) {
			swap(f[i], f[r[i]]);
		}
	}
	for (int len = 2; len <= limit; len <<= 1) {
		Complex Omega0 = polar(1.0, 2 * Pi / len);
		for (int i = 0; i < limit; i += len) {
			Complex Omega = Complex(1, 0);
			int mid = len >> 1;
			for (int j = i; j < i + mid; j++, Omega *= Omega0) {
				Complex a = f[j], b = f[j + mid] * Omega;
				f[j] = a + b;
				f[j + mid] = a - b;
			}
		}
	}
	if (inv) {
		reverse(f.begin() + 1, f.end() - 1);
		for (auto &i :f) {
            i /= limit;
		}
	}
}
signed main() {
	cin >> n >> m;
	while (limit <= n + m) {
		limit <<= 1;
		cnt++;
	}
	for (int i = 0; i < limit; i++) {
		r[i] = (r[i >> 1] >> 1) | ((i & 1) << (cnt - 1));
	}
    Poly a(limit + 1),b(limit + 1);
    for (int i = 0;i <= n;i++) {
        cin >> a[i];
    }
    for (int i = 0;i <= m;i++) {
        cin >> b[i];
    }
    FFT(a);
    FFT(b);
    for (int i = 0;i <= limit;i++) {
        a[i] = a[i] * b[i];
    }
    FFT(a,1);
    for (int i = 0;i <= n + m;i++) {
        cout << int(a[i].real() + 0.5) << " ";
    }
}