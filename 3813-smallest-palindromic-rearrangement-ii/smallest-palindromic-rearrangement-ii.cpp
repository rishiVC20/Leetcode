// class Solution {
//     #define ll long long
//     const int mod=1e9+7;
// public:
//     ll power(ll base, ll exponent){
//         if (exponent < 0){
//             return 0;
//         }
//         ll ans = 1;
//         while (exponent){
//             if (exponent%2==0){
//                 base = (base*base) % mod;
//                 exponent = exponent/2;
//             }
//             else{
//                 ans = (ans*base) % mod;
//                 exponent--;
//             }
//         }
//         return ans;
//     }
//     ll mul (ll a, ll b){
//         a = a % mod;
//         b = b % mod;
//         return (((a * b) % mod) + mod) % mod;
//     }
//     ll invmod(ll a){
//         return power(a, mod - 2);
//     }
//     ll div(ll a, ll b){
//         a = a % mod;
//         b = b % mod;
//         return mul(a, invmod(b));
//     }
//     ll factorial(ll n) {
//         if (n == 0) {
//             return 1; 
//         } else {
//             return (n * factorial(n - 1))%mod; 
//         }
//     }
//     string smallestPalindrome(string s, int k) {
//         vector<int>v(26,0);
//         for(auto i:s){
//             v[i-'a']++;
//         }
//         int n=s.size();
//         vector<int>d(n);
//         int j=0;
//         for(int i=0; i<26; i++){
//             while(v[i]>1){
//                 d[j]=i;
//                 d[n-j-1]=i;
//                 v[i]-=2;
//                 j++;
//             }
//         }
//         int h=-1;
//         for(int i=0; i<26; i++){
//             if(v[i]>0){
//                 d[n/2]=i;
//                 h=i;
//                 break;
//             }
//         }
//         string ans="";
//         for(int i=0; i<n; i++){
//             char z=d[i]+'a';
//             ans.push_back(z);
//         }
//         // cout<<ans<<' ';
//         string pk;
//         map<char,int>mp;
//         vector<int>dd(26,0);
//         for(int i=0; i<n/2; i++){
//             pk.push_back(ans[i]);
//             mp[ans[i]]++;
//             dd[ans[i]-'a']++;
//         }
//         // cout<<pk<<' ';
//         // unordered_set<string>st;
//         // vector<string>vec;
//         string vec;
//         ll cal=factorial(n/2);
//         ll dl=1;
//         for(auto i:mp){
//             dl=(dl*factorial(i.second))%mod;
//         }
//         cal=div(cal,dl);
//         cout<<cal<<' ';
//         if(cal<k){
//             cout<<"hi ";
//             return "";
//         }
//         string fin="";
//         for(int i=0; i<n/2; i++){
//             for(int j=0; j<26; j++){
//                 if(dd[j]==0)
//                     continue;

//                 dd[j]--;
//                 ll cp=factorial(n/2-i-1);
//                 mp[j+'a']--;
//                 ll hp = 1;
//                 for (auto kp : mp) {
//                     if(kp.second==0)
//                         continue;
//                     hp = (hp * factorial(kp.second)) % mod;
//                 }
//                 cp = div(cp, hp);
//                 // cout<<cp<<' ';
//                 if(k>cp){
//                     k-=cp;
//                     dd[j]++;
//                     mp[j+'a']++;
//                 }
//                 else{
//                     // mp[j+'a']--;
//                     fin.push_back(j+'a');
//                     break;
//                 }
//             }
//             // cout<<endl;
//         }
//         string g=fin;
//         if(h!=-1){
//             fin.push_back(h+'a');
//         }
//         reverse(g.begin(),g.end());
//         fin+=g;
//         return fin;

//     }
// };

// //641071511 


class Solution {
public:
    string smallestPalindrome(string s, int k) {
        // Combination calculator
        auto comb = [](int n, int r, long long max_value) -> long long {
            if (r > n) return 0;
            r = min(r, n - r);
            
            long long result = 1;
            for (int i = 1; i <= r; i++) {
                result = result * (n - r + i) / i;
                if (result >= max_value) return max_value;
            }
            return result;
        };
        
        // Permutation counter
        auto countPerms = [&comb](const vector<int>& counts, int positions, long long max_value) -> long long {
            long long perms = 1;
            int remaining = positions;
            
            for (int count : counts) {
                long long ways = comb(remaining, count, max_value);
                perms *= ways;
                if (perms >= max_value) return max_value;
                remaining -= count;
            }
            return perms;
        };
        
        // Maximum needed
        long long max_perms_needed = k + 1LL;
        
        // Character counts
        vector<int> char_freq(26, 0);
        for (char c : s) {
            char_freq[c - 'a']++;
        }
        
        // Process characters
        string middle = "";
        vector<int> half_counts(26, 0);
        
        for (int i = 0; i < 26; i++) {
            if (char_freq[i] % 2 == 1) {
                middle = string(1, 'a' + i);
            }
            half_counts[i] = char_freq[i] / 2;
        }
        
        // Calculate half length
        int half_len = 0;
        for (int count : half_counts) {
            half_len += count;
        }
        
        // Count total possible palindromes
        long long total_palindromes = countPerms(half_counts, half_len, max_perms_needed);
        
        // Check if k is valid
        if (k > total_palindromes) {
            return "";
        }
        
        // Build the first half
        string first_half = "";
        for (int pos = 0; pos < half_len; pos++) {
            for (int c = 0; c < 26; c++) {
                if (half_counts[c] == 0) continue;
                
                // Try this character
                half_counts[c]--;
                
                // Count palindromes with this prefix
                long long palindromes_with_prefix = countPerms(
                    half_counts, half_len - pos - 1, max_perms_needed
                );
                
                if (k > palindromes_with_prefix) {
                    // Skip this character
                    k -= palindromes_with_prefix;
                    half_counts[c]++;
                } else {
                    // Use this character
                    first_half += ('a' + c);
                    break;
                }
            }
        }
        
        // Build the full palindrome
        string result = first_half + middle;
        for (int i = first_half.size() - 1; i >= 0; i--) {
            result += first_half[i];
        }
        
        return result;
    }
};