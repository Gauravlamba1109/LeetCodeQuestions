class Node{
    public int a;
    public int b;

    public Node(int a, int b){
        this.a = a;
        this.b = b;
    }


}

class MinStack {


/*
 push, pop, top, and retrieving the minimum element in constant time.

simple stack : const time : push, pop, 
hashmap for getting min ele 

4,9,5,3,5,3,2,5,3,2
*/ 
    public final Stack<Node>st;

    public MinStack() {
        this.st = new Stack<>();    
    }
    
    public void push(int value) {
        int b = value;
        if(st.size()>0){
            b = Math.min(b,st.peek().b);
        }
        Node n = new Node(value,b);
        st.push(n);
        return ;
    }
    
    public void pop() {
        st.pop();
        return ;
    }
    
    public int top() {
        return st.peek().a;
    }
    
    public int getMin() {
        return st.peek().b;
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(value);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */