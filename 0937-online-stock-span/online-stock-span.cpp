class StockSpanner {
private:
    stack<pair<int, int>> stk;
    int i;

public:
    StockSpanner() {
        i = 0;
    }
    
    int next(int price) {
        while(!stk.empty() && stk.top().first <= price) stk.pop();
        
        int res = stk.empty() ? i +1  : i - stk.top().second;
        
        stk.push({price, i});
        i++;

        return res;

    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */