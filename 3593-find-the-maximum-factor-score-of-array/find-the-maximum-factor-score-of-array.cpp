class Solution {
    #define ll long long
public:
    ll LCM(ll a, ll b){
        a=(a/__gcd(a,b))*b;
        return a;
    }
    long long maxScore(vector<int>& nums) {
        ll n=nums.size();
        sort(nums.begin(),nums.end());
        ll cn=0;
        if(n==1){
            return nums[0]*nums[0];
        }
        ll c=nums[0],g=nums[0];

        for(ll i=0; i<=n; i++){
            vector<ll>a;
            for(ll j=0; j<n; j++){
                if(i==j)
                    continue;
                a.push_back(nums[j]);    
            }
            ll g1=a[0],c1=a[0];
            for(auto i:a){
                g1=__gcd(i,g1);
                c1=lcm(i,c1);
            }
            cn=max(cn,g1*c1);
        }

        return cn;
        
        
    }
};
// #include <vector>
// #include <algorithm>
// #include <bits/stdc++.h> // For std::gcd
// using namespace std;

// class Solution {
//     #define ll long long

// public:
//     // Function to calculate LCM
//     ll LCM(ll a, ll b) {
//         return (a / __gcd(a, b)) * b;
//     }

//     long long maxScore(vector<int>& nums) {
//         ll n = nums.size();
        
//         // Edge case for small arrays
//         if (n == 1) return nums[0];
        
//         // Prefix and Suffix Arrays for GCD
//         vector<ll> prefixGCD(n), suffixGCD(n);
//         prefixGCD[0] = nums[0];
//         suffixGCD[n - 1] = nums[n - 1];
        
//         // Calculate prefix and suffix GCDs
//         for (ll i = 1; i < n; i++) {
//             prefixGCD[i] = __gcd(prefixGCD[i - 1], (ll)nums[i]);
//         }
//         for (ll i = n - 2; i >= 0; i--) {
//             suffixGCD[i] = __gcd(suffixGCD[i + 1],(ll) nums[i]);
//         }
        
//         // Prefix and Suffix Arrays for LCM
//         vector<ll> prefixLCM(n), suffixLCM(n);
//         prefixLCM[0] = nums[0];
//         suffixLCM[n - 1] = nums[n - 1];
        
//         // Calculate prefix and suffix LCMs
//         for (ll i = 1; i < n; i++) {
//             prefixLCM[i] = LCM(prefixLCM[i - 1], nums[i]);
//         }
//         for (ll i = n - 2; i >= 0; i--) {
//             suffixLCM[i] = LCM(suffixLCM[i + 1], nums[i]);
//         }

//         // Calculate max score by excluding each element
//         ll maxScore = 0;
//         for (ll i = 0; i < n; i++) {
//             // Calculate GCD and LCM for the array excluding nums[i]
//             ll excludedGCD = (i == 0) ? suffixGCD[1] : (i == n - 1 ? prefixGCD[n - 2] : __gcd(prefixGCD[i - 1], suffixGCD[i + 1]));
//             ll excludedLCM = (i == 0) ? suffixLCM[1] : (i == n - 1 ? prefixLCM[n - 2] : LCM(prefixLCM[i - 1], suffixLCM[i + 1]));
            
//             // Update max score with the product of excluded GCD and LCM
//             maxScore = max(maxScore, excludedGCD * excludedLCM);
//         }

//         return maxScore;
//     }
// };
