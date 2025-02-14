class ProductOfNumbers {
public:
    int crnt=1;
    int lstZero=-1;
    vector<int>prfx;
    bool parity=0;
    ProductOfNumbers() {
        crnt=1;
        parity=0;
        prfx=vector<int>(40005,1);
    }
    
    void add(int num) {
        if(!num)lstZero=crnt,prfx[crnt]=1;
        else prfx[crnt]=num*prfx[crnt-1];
        crnt++;
    }
    
    int getProduct(int k) {
        int right=crnt-1, left=crnt-1-k;
        if(left<lstZero){
            return 0;
        }
        else {
            return (prfx[crnt-1]/prfx[crnt-k-1]);
        }
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */