---
layout:     page
title:      String Algorithms
id:         string
path:       Library/String
anchors:
    LexicographicallySmallestRotation: Lexicographically Smallest Rotation
---

<a name="LexicographicallySmallestRotation"></a>

- **Implementation of Booth's algorithm to find lexicographically minimal string rotation**
    - *Running Time*
        - `O(n)`
    - *Input*
        - `s`, string
    - *Output*
        - `k`, minimum index such that `s[k...(n-1)]+s[0..(k-1)]` is the minimal of all rotation of `s`
    - *Tested Problems*
        - UVA: 719

{% highlight cpp %}
int LexicographicallySmallestRotation (string& s) {
    int n = s.size();
    string t = s + s;
    vector <int> f (2 * n, -1);
    int k = 0;
    for (int j = 1; j < 2 * n; ++j) {
        int i = f[j - k - 1];
        while (i != -1 && t[j] != t[k + i + 1]) {
            if (t[j] < t[k + i + 1]) {
                k = j - i - 1;
            }
            i = f[i];
        }
        if (i == -1 && t[j] != t[k + i + 1]) {
            if (t[j] < t[k + i + 1]) {
                k = j;
            }
            f[j - k] = -1;
        } else {
            f[j - k] = i + 1;
        }
    }
    return k;
}
{% endhighlight %}