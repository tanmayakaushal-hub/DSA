class ProductOfNumbers {
public:
    vector<int> store;
    ProductOfNumbers() {
        store.push_back(1);
    }
    
    void add(int num) {
        if(num == 0){
            store.clear();
            store.push_back(1);
        }
        else{
            store.push_back(num * store.back());
        }
    }
    
    int getProduct(int k) {
        if(k >= store.size()) return 0;
        return store.back() / store[store.size() - k - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */