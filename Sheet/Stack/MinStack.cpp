#include <bits/stdc++.h>
using namespace std;

class MinStack {    // O(1) time for finding minimum in stack
public:
    stack<int> allData;
    stack<int> minData;
    
public:
    MinStack() {
        // allData=new stack();
        // minData=new stack();
        
    }
    
    void push(int val) {
        allData.push(val);
        if(minData.size()==0 || val<=minData.top()){
            minData.push(val);
        }
    }
    
    void pop() {
        int data=allData.top();
        if(data==minData.top()){
            minData.pop();
        }
        allData.pop();
    }
    
    int top() {
        int data=allData.top();
        return data;
    }
    
    int getMin() {
        int data=minData.top();
        return data;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */