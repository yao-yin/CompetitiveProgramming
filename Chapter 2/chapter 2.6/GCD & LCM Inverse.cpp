//https://imulan.hatenablog.jp/entry/2016/10/28/045502, compiler G++
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <climits>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

#define long unsigned long long

long mod_mul(long a, long b, long mod){
    long res=0;
    a%=mod;
    while(b){
        if(b&1){
            res+=a;
            if(res>mod) res-=mod;
        }
        a <<= 1;
        if(a>mod) a-=mod;
        b >>= 1;
    }
    return res;
}

// x^n mod
long mod_pow(long x, long n, long mod){
  long res=1;
  x%=mod;
  while(n){
    if(n&1) res=mod_mul(res,x,mod);
    x=mod_mul(x,x,mod);
    n>>=1;
  }
  return res;
}

// Miller-Rabin Primality Test
bool miller_rabin(long n){
    // using primes up to 37 is enough to judge 64 bit integer
    const int primes[] = {2,3,5,7,11,13,17,19,23,29,31,37};
    const int nprime = 12;
    long m = n-1, s=0;

    if(n<=1) return false;  // 1 or 0 or negative
    if(n%2==0) return n==2; // even number
    for(int i=0; i<nprime; i++){ //embeded primes and its multiple
        if(n == primes[i]) return true;
        if(n%primes[i] == 0) return false;
    }

    while(m%2==0){ s++; m>>=1; } // n=m*2^s+1
    // Miller-Rabin primality test
    for(int i=0; i<nprime; i++){
        long a = primes[i];
        long y = mod_pow(a, m, n);
        if(y==1) continue;
        bool flg=true;
        for(int j=0; flg && (j<s); j++){
            if(y==n-1) flg=false;
            y = mod_mul(y, y, n);
        }
        if(flg==false) continue;
        return false;
    }
    return true;
}

long pollard_rho(long n, int c){
    long x=2,y=2,d=1;
    while(d==1)
    {
        x = mod_mul(x,x,n) + c;
        y = mod_mul(y,y,n) + c;
        y = mod_mul(y,y,n) + c;
        d = __gcd((x>y)?x-y:y-x,n);
    }
    if(d==n) return pollard_rho(n,c+1);
    return d;
}

const int MAX_PRIME=300000;
vector<int> primes;
vector<bool> is_prime;

void init_primes(){
    is_prime = vector<bool>(MAX_PRIME+1,true);
    is_prime[0] = is_prime[1] = false;
    for(int i=2; i<=MAX_PRIME; ++i){
        if(is_prime[i]){
            primes.push_back(i);
            for(int j=i*2; j<=MAX_PRIME; j+=i) is_prime[j]=false;
        }
    }
}

bool isPrime(long n)
{
    if(n<=MAX_PRIME) return is_prime[n];
    else return miller_rabin(n);
}

void factorize(long n, map<long,int> &factors){
    if(isPrime(n)) factors[n]++;
    else{
        for(int i=0; i<primes.size(); ++i){
            int p=primes[i];
            while(n%p==0){
                factors[p]++;
                n/=p;
            }
        }
        if(n!=1){
            if(isPrime(n)) factors[n]++;
            else{
                long d=pollard_rho(n,1);
                factorize(d,   factors);
                factorize(n/d, factors);
            }
        }
    }
}

pair<long,long> solve(long GCD, long LCM)
{
    map<long,int> factors;
    factorize(LCM/GCD,factors);

    vector<long> mul_factors;
    each(itr,factors)
    {
        long tmp=1;
        rep(i,itr->second) tmp*=itr->first;
        mul_factors.pb(tmp);
    }

    long min_sum=ULLONG_MAX;
    long ansx=1, ansy=1;
    int M=mul_factors.size();
    rep(mask,1<<M)
    {
        long tx=1, ty=1;
        rep(i,M)
        {
            if(mask>>i&1) tx*=mul_factors[i];
            else ty*=mul_factors[i];
        }
        if(tx+ty<min_sum)
        {
            if(tx>ty) swap(tx,ty);
            min_sum=tx+ty;
            ansx=tx;
            ansy=ty;
        }
    }

    return pair<long,long>(ansx,ansy);
}

int main()
{
    init_primes();

    long GCD,LCM;
    while(cin >>GCD >>LCM)
    {
        pair<long,long> ans=solve(GCD,LCM);
        cout << GCD*ans.fi << " " << GCD*ans.se << endl;
    }
    return 0;
}