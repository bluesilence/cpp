class MinStack {
public:
    void push(int x) {
        dataStack.push(x);
        //If there are duplicate mins, push all of them, otherwise when poping, we don't know if there is a duplicate min still in the stack and whether we should pop min.
        if (minStack.empty() || x <= minStack.top()) {
            minStack.push(x);
        }
    }

    void pop() {
        if (!dataStack.empty()) {
            int tmp = dataStack.top();
            if (tmp == minStack.top()) {
                minStack.pop();
            }
            
            dataStack.pop();
        }
    }

    int top() {
        return dataStack.top();
    }

    int getMin() {
        return minStack.top();
    }

private:
    stack<int> dataStack;
    stack<int> minStack;
};
