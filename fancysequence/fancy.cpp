class Fancy {
public:
    long long mod;
    long long mul;
    long long add;
    vector<long long> arr;

    long long modPow(long long a,long long b){
        long long res=1;
        a%=mod;
        while(b>0){
            if(b%2==1) res=(res*a)%mod;
            a=(a*a)%mod;
            b/=2;
        }
        return res;
    }

    long long modInv(long long x){
        return modPow(x,mod-2);
    }

    Fancy() {
        mod=1000000007;
        mul=1;
        add=0;
    }
    
    void append(int val) {
        long long v=val;
        v=(v-add)%mod;
        if(v<0) v+=mod;
        v=(v*modInv(mul))%mod;
        arr.push_back(v);
    }
    
    void addAll(int inc) {
        add=(add+inc)%mod;
    }
    
    void multAll(int m) {
        mul=(mul*m)%mod;
        add=(add*m)%mod;
    }
    
    int getIndex(int idx) {
        if(idx>=arr.size()) return -1;
        long long v=arr[idx];
        v=(v*mul)%mod;
        v=(v+add)%mod;
        return (int)v;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */