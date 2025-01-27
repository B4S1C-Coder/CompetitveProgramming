#include <queue>

class MyStack {
public:
    MyStack() {}
    
    void push(int x) {
        m_underlyingQ.push(x);
        m_topElem = x;
    }
    
    int pop() {
        int lastVal = m_underlyingQ.back();

        for (int i = 0; i < m_underlyingQ.size() - 1; i++) {
            int curr = m_underlyingQ.front();
            m_underlyingQ.pop();
            m_underlyingQ.push(curr);
        }
        m_underlyingQ.pop();

        m_topElem = m_underlyingQ.back();

        return lastVal;
    }
    
    int top() {
        return m_topElem;
    }
    
    bool empty() {
        return m_underlyingQ.empty();
    }
private:
    std::queue<int> m_underlyingQ;
    int m_topElem;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
