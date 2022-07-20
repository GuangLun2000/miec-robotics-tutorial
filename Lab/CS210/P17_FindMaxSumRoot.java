package MIEC_CS210;

import java.util.Scanner;

// This code is contributed by Lance Cai
// A class to store a binary tree node

class P17_FindMaxSumRoot
{
    int data;
    Node left = null, right = null;

    P17_FindMaxSumRoot(int data) {
        this.data = data;
    }
}

class Main
{
    // Function to print the root-to-leaf path with a given sum in a binary tree
    public static boolean printPath(Node root, int sum)
    {
        // base case
        if (sum == 0 && root == null) {
            return true;
        }

        // base case
        if (root == null) {
            return false;
        }

        // recur for the left and right subtree with reduced sum
        boolean right = printPath(root.right, sum - root.data);
        boolean left = false;

        if (!right) {
            right = printPath(root.left, sum - root.data);
        }

        // print the current node if it lies on a path with a given sum
        if (left || right) {
            System.out.print(root.data + " ");
        }

        return left || right;
    }

    // Function to calculate the maximum root-to-leaf sum in a binary tree
    public static int getRootToLeafSum(Node root)
    {
        // base case: tree is empty
        if (root == null) {
            return Integer.MIN_VALUE;
        }

        // base case: current node is a leaf node
        if (root.left == null && root.right == null) {
            return root.data;
        }

        // calculate the maximum node-to-leaf sum for the left child
        int right = getRootToLeafSum(root.right);

        // calculate the maximum node-to-leaf sum for the right child
        int left = getRootToLeafSum(root.left);

        // consider the maximum sum child
        return (right > left? right : left) + root.data;
    }

    // Function to print maximum sum root-to-leaf path in a given binary tree
    public static void findMaxSumPath(Node root)
    {
        int sum = getRootToLeafSum(root);
        System.out.print("Max sum is " +sum+ ", with a path [" );

        printPath(root, sum);
    }

    public static void main(String[] args)
    {
        // This code is contributed by Lance Cai
        /* The fucking tree
                  1
                /   \
               /     \
              2       3
             / \     / \
            8   4   5   6
               /   / \   \
             10   7   9   5
        */

        Scanner input = new Scanner(System.in);
        String str = input.next();
        String[] string = str.split(",");
        int[] numsInt1 = new int[string.length];
        for (int i = 0; i < string.length; i++) {
            numsInt1[i] = Integer.parseInt(string[i]);
            //System.out.print(numsInt1[i]+" ");
        }

        Node root = new Node(numsInt1[0]);
        root.left = new Node(numsInt1[1]);
        root.right = new Node(numsInt1[2]);

        root.left.left = new Node(numsInt1[3]);
        root.left.right = new Node(numsInt1[4]);
        root.right.left = new Node(numsInt1[5]);
        root.right.right = new Node(numsInt1[6]);

        root.left.left.left = new Node(numsInt1[7]);
        root.left.left.right = new Node(numsInt1[8]);
        root.left.right.left = new Node(numsInt1[9]);
        root.left.right.right  = new Node(numsInt1[10]);

        root.right.left.left = new Node(numsInt1[11]);
        root.right.left.right = new Node(numsInt1[12]);
        root.right.right.left = new Node(numsInt1[13]);
        root.right.right.right = new Node(numsInt1[14]);

        findMaxSumPath(root);
        System.out.print("]");
    }
}
// This code is contributed by Lance Cai
