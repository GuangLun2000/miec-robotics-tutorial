package MIEC_CS211.Lab1_0325;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;

class BSTSorting {

    // Driver Code
    public static void main(String[] args) throws IOException {
        BSTSorting tree = new BSTSorting();

        // This code is contributed by Lance Cai 832002117

        File f = new File("/Users/lancecai/Desktop/Lab-2022S/CS211_Algorithms&Data Structure 2/Lab1/RandomNumbers.txt");
        FileReader fre = new FileReader(f);
        BufferedReader bre = new BufferedReader(fre);
        String str = "";
        while ((str = bre.readLine()) != null) {
            System.out.println(str);
            String[] string = str.split(" ");
            int[] numsInt1 = new int[string.length];
            for (int i = 0; i < string.length; i++) {
                numsInt1[i] = Integer.parseInt(string[i]);
                //System.out.print(numsInt1[i]+" ");
            }
            for (int i = 0; i < string.length; i++) {
                tree.insert(numsInt1[i]);
            }
        }

        bre.close();
        fre.close();

        // print inorder traversal of the BST by sortAscending() && sortDescending()
        tree.sortAscending();
        //tree.sortDescending();

        // This code is contributed by Lance Cai
    }


    /* Class containing left
       and right child of current node
     * and key value*/
    class Node {
        int key;
        Node left, right;

        public Node(int item) {
            key = item;
            left = right = null;
        }
    }

    // Root of BST
    Node root;

    // Constructor
    BSTSorting() {
        root = null;
    }
    BSTSorting(int value) {
        root = new Node(value);
    }

    // This method mainly calls insertRec()
    void insert(int key) {
        root = insertRec(root, key);
    }
    /* A recursive function to
       insert a new key in BST */
    Node insertRec(Node root, int key) {

        /* If the tree is empty,
           return a new node */
        if (root == null) {
            root = new Node(key);
            return root;
        }

        /* Otherwise, recur down the tree */
        if (key < root.key)
            root.left = insertRec(root.left, key);
        else if (key > root.key)
            root.right = insertRec(root.right, key);

        /* return the (unchanged) node pointer */
        return root;
    }


    // This method mainly calls InorderRec()
    void sortAscending() {
        sortAscendingRec(root);
    }
    // A utility function to
    // do inorder traversal of BST
    void sortAscendingRec(Node root) {
        if (root != null) {
            sortAscendingRec(root.left);
            System.out.println(root.key);
            sortAscendingRec(root.right);
        }
    }


    void sortDescending() {
        sortDescendingRec(root);
    }

    // A utility function to
    // do inorder traversal of BST
    void sortDescendingRec(Node root) {
        if (root != null) {
            sortDescendingRec(root.right);
            System.out.println(root.key);
            sortDescendingRec(root.left);
        }
    }


}

// This code is contributed by Lance Cai 832002117 20122161