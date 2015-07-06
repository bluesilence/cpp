class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        inStack.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if (outStack.empty()) {
            moveInToOut();
        }
        
        outStack.pop(); //Assume the pop is always valid
    }

    // Get the front element.
    int peek(void) {
        if (outStack.empty()) {
            moveInToOut();
        }
        
        return outStack.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return outStack.empty() && inStack.empty();
    }

private:
    stack<int> outStack;
    stack<int> inStack;
    
    void moveInToOut() {
        while (!inStack.empty()) {
            outStack.push(inStack.top());
            inStack.pop();
        }
    }
};
