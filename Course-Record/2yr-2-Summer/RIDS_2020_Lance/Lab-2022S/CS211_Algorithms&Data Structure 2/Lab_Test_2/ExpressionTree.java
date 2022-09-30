package LabTest2;


import java.util.Stack;

public class ExpressionTree {
    static Stack stack = new Stack();

    Node root;

    class Node {
        public boolean isOperator;
        char elem;
        Node left, right;

        public Node(char elem) {
            this.elem = elem;
            left = right = null;
        }
    }

    static int precedence(char opr) {
        switch (opr) {
            case '+':
            case '-':
                return 1;

            case '*':
            case '/':
                return 2;

            case '^':
                return 3;
        }
        return -1;
    }

    static boolean isOperator(char opr) {
        if (opr == '+' || opr == '-' || opr == '*' || opr == '/' || opr == '^' || opr == '(' || opr == ')')
            return true;
        return false;
    }


    /*
     * Provide your implementation here. This method builds an expression tree from
     * a given algebra expression represented in postfix notation. You may refer to
     * the pseudocode given in the test sheet.
     */
    public void postfixBuild(String postfixExpression) {

        Node op1;
        Node op2;
        Node current,ch;
        Stack<Node> stack = new Stack<>();


        for (int i = 0; i < postfixExpression.length(); i++) {
            current = new Node(postfixExpression.charAt(i));
//            ch = new Node(NodepostfixExpression.charAt(i));
            
            if (current.isOperator) {
//                Node node = new Node(ch);
                stack.push(current);
            } else {
                //there maybe some pro
                op1 = stack.pop();
                op2 = stack.pop();
                current.left = op1;
                current.right = op2;
                stack.push(current);
            }
        }
        stack.pop();

    }

    public String printInfixNotation() {
        StringBuilder result = new StringBuilder();
        printInfixNotation(root, result);
        return result.toString();
    }

    /*
     * Provide your implementation here. You MUST use a recursive method for the
     * implementation of the method.
     */
    private void printInfixNotation(Node root, StringBuilder result) {

        Node currentNode = root;
        if (currentNode != null) {

            // Infix Notation
            printInfixNotation(currentNode.left,result);
            System.out.print(currentNode);
            printInfixNotation(currentNode.right,result);

        }


    }

    public void printPrefixNotation() {
        printPrefixNotation(root);
    }

    /*
     * Provide your implementation here. You MUST use an iterative method for the
     * implementation of the method. You may refer to the pseudocode given in the
     * test sheet.
     */
    private void printPrefixNotation(Node currentRoot) {
        if(currentRoot == null){
            return;
        }
        Stack<Node> stack = new Stack<>();
        stack.push(currentRoot);
        while (stack.size() != 0){
            ExpressionTree.Node viistingNode = stack.pop();
            System.out.print(viistingNode.elem);
            if (viistingNode.right != null){
                stack.push(viistingNode.right);
            }
            if (viistingNode.left != null){
                stack.push(viistingNode.left);
            }
        }


    }

    /*
    Although the code is not enough,
    But I've done my best to write these code.
    Thank you!

    Really thank you to give me 2nd chance, Hope u have a good day!

    Hanlin Cai 20122161
     */


    public static void main(String args[]) {
        String postfix = "ab*cd*+f-a+";

        ExpressionTree et = new ExpressionTree();

        et.postfixBuild(postfix);

        System.out.println("Infix:   " + et.printInfixNotation());

        System.out.print("Prefix:  ");
        et.printPrefixNotation();

    }

}