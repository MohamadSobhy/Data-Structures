
package stackofinteger.java;

public class StackOFIntegerJava {

    int elements[];
    int size;
    int top;
    
    public StackOFIntegerJava(){
        this(16);
    }
    public StackOFIntegerJava(int size){
        this.size = size;
        top = -1;
        elements = new int [size];
    }
    public int peek(){
        return elements[size - 1];
    }
    public void push(int element){
        if(top >= size){
            System.out.println("Stack OverFlow.");
            return;
        }
        elements[++top] = element;
    }
    public int pop(){
        if(top < 0){
            System.out.println("Stack UnderFlow.");
            return -1;
        }
        return elements[top--];
    }
    public int getSize(){
        return top;
    }
    public boolean isEmpty(){
        if(top == -1)
            return true;
        return false;
    }
    public void print(){
        if(top == -1){
            System.out.println("Stack is Empty.");
            return;
        }
        for(int i = top ; i >= 0 ;i--)
            System.out.println("Element["+i+"] is "+ elements[i]);
    }
    public static void main(String[] args) {
        StackOFIntegerJava stack = new StackOFIntegerJava();
        stack.push(0);
        stack.push(1);
        stack.push(2);
        stack.push(3);
        stack.push(4);
        stack.print();
        stack.pop();
        System.out.println("--------------------------------------------");
        stack.print();
        stack.pop();
        stack.pop();
        stack.pop();
        stack.pop();
        stack.print();
        System.out.println("--------------------------------------------");
        stack.pop();
        
    }
    
}
