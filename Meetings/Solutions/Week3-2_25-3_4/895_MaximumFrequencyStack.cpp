class FreqStack {
    
    unordered_map<int, int> freq; // key -> element, value -> frequency
    unordered_map<int, stack<int>> group; // key -> frequency, value -> stack of elements with atleast that frequency
    int maxFreq; // maximum frequency
    
public:
    FreqStack() : maxFreq(0) {}
    
    void push(int x) {
        ++freq[x];
        group[freq[x]].push(x);
        if(freq[x] > maxFreq) {
            maxFreq = freq[x];
        }
    }
    
    int pop() {
        int popVal = group[maxFreq].top();
        group[maxFreq].pop();
        --freq[popVal];
        if(group[maxFreq].empty()) {
            group.erase(maxFreq);
            --maxFreq;
        }
        return popVal;
    }
};
