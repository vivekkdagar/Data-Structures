#include <iostream>

using namespace std;

void permutate(string s, int k) {
    // is a flag array that stores which characters have been used in the permutation
    static bool flag[20] = {0};

    // Stores the resultant string
    static char res[20];

    // Length of the string passed to the function
    static int t = s.length();
    
    if (k == t)
        cout << res << endl;
    else {
        for (int i{0}; i < t; i++)
            if (not flag[i]) {
                res[k] = s[i];
                flag[i] = true;
                permutate(s, k + 1);
                flag[i] = false;
            }
    }
}

// Method 2
void perm(string s, int l, int h) {         // h = last valid index, l = 0, s is the string
    int i;
    if(l == h)
        cout << s << endl;
    else {
        for(i = l; i <= h; i++) {
            std::swap(s[l], s[i]);
            perm(s,l+1,h);
            swap(s[l],s[i]);
        }
    }
}

int main() {
    perm("hello", 0, 4);
}
