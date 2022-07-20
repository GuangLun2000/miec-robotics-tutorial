import java.io.*;

public class SpecialAVLTree {
    private static Node root;
    static Node flag;

    //Create the Node
    private static class Node {
        private int key;
        private String value;
        Node leftChild, rightChild;
        int height;
        boolean isLazyRemove;

        public Node(int key, String value) {
            this.key = key;
            this.value = value;
        }

    }

    private static int height(Node node) {
        return node == null ? -1 : node.height;
    }

    //Rotation method
    private static Node rotateWithLeftChild(Node k2) {
        Node k1 = k2.leftChild;
        k2.leftChild = k1.rightChild;
        k1.rightChild = k2;
        k2.height = Math.max(height(k2.leftChild), height(k2.rightChild)) + 1;
        k1.height = Math.max(height(k1.leftChild), k2.height) + 1;

        return k1;
    }
    //Rotation method
    private static Node rotateWithRightChild(Node k2) {
        Node k1 = k2.rightChild;
        k2.rightChild = k1.leftChild;
        k1.leftChild = k2;
        k2.height = Math.max(height(k2.leftChild), height(k2.rightChild)) + 1;
        k1.height = Math.max(height(k1.rightChild), k2.height) + 1;

        return k1;
    }
    //doubleRotation method
    private static Node doubleWithLeftChildRightSubtree(Node k3) {
        k3.leftChild = rotateWithRightChild(k3.leftChild);
        return rotateWithLeftChild(k3);
    }
    //doubleRotation method
    private static Node doubleWithRightChildLeftSubtree(Node k3) {
        k3.rightChild = rotateWithLeftChild(k3.rightChild);
        return rotateWithRightChild(k3);
    }


    /*
    If there are not nodes, directly return
    If (Height of left subtree - height of right subtree) > 1, then right rotation
    If (Height of right subtree - height of left subtree) > 1, then left rotation
    Finally，return the height of the current node, itself also need to calculate, so（+1）.

    This comment is written by Hanlin Cai.
     */
    private static Node balance(Node node) {
        //If there are not nodes
        if (node == null)
            return node;
        //If (Height of left subtree - height of right subtree) > 1, then right rotation
        if (height(node.leftChild) - height(node.rightChild) > 1) {
            if (height(node.leftChild.leftChild) >= height(node.leftChild.rightChild)) {
                node = rotateWithLeftChild(node);
            } else {
                node = doubleWithLeftChildRightSubtree(node);
            }
        } else if (height(node.rightChild) - height(node.leftChild) > 1) {
            //If (Height of right subtree - height of left subtree) > 1, then left rotation
            if (height(node.rightChild.rightChild) >= height(node.rightChild.leftChild)) {
                node = rotateWithRightChild(node);
            } else {
                node = doubleWithRightChildLeftSubtree(node);
            }
        }
        //Finally，return the height of the current node, itself also need to calculate, so（+1）.
        node.height = Math.max(height(node.leftChild), height(node.rightChild)) + 1;
        return node;
    }

    // insert a new node into the AVL tree
    private static Node insert(int key, String value, Node currentRoot) {
        if (currentRoot == null)
            return new Node(key, value);

        if (key < currentRoot.key) {
            // the  position is less than current position, then insert it into the left child
            currentRoot.leftChild = insert(key, value, currentRoot.leftChild);
        } else if (key > currentRoot.key) {
            // the  position is greater than current position, then insert it into the right child
            currentRoot.rightChild = insert(key, value, currentRoot.rightChild);
        }
        //Rebalance
        return balance(currentRoot);
    }

    public static void insert(int key, String value) {
        root = insert(key, value, root);
    }

    public void remove(int key) {
        root = remove(key, root);
    }

    //Remove Node
    private Node remove(int toBeRemoved, Node currentRoot) {
        if (currentRoot == null)
            return currentRoot;

        if (toBeRemoved < currentRoot.key) {
            currentRoot.leftChild = remove(toBeRemoved, currentRoot.leftChild);
        } else if (toBeRemoved > currentRoot.key) {
            currentRoot.rightChild = remove(toBeRemoved, currentRoot.rightChild);
        } else if (currentRoot.leftChild != null && currentRoot.rightChild != null) {
            currentRoot.key = findMin(currentRoot.rightChild).key;
            currentRoot.rightChild = remove(currentRoot.key, currentRoot.rightChild);
        } else {
            currentRoot = (currentRoot.leftChild != null) ? currentRoot.leftChild : currentRoot.rightChild;
        }

        return balance(currentRoot);
    }

    // get the MIN value in AVLTree
    private Node findMin(Node currentRoot) {
        if (currentRoot == null)
            return currentRoot;

        while (currentRoot.leftChild != null)
            currentRoot = currentRoot.leftChild;

        return currentRoot;
    }

    //This code is created by Hanlin Cai in 2022/04/08.
    //sort the AVLTree in sortAscending().
    void sortAscending() {
        sortAscendingRec(root);
    }

    // A utility function to
    // do inorder traversal of AVLtree
    void sortAscendingRec(Node root) {
        if (root != null) {
            sortAscendingRec(root.leftChild);
            System.out.println(root.key + " " + root.value);
            sortAscendingRec(root.rightChild);
        }
    }


    static boolean search(int key) {
        if (flag == null) {
            return false;
        }
        if (flag.key == key) {
            if (flag.isLazyRemove){
                return false;
            }
            System.out.println(Integer.toString(flag.key) + " " + flag.value);
            return true;
        }
        if (key < flag.key) {
            flag = flag.leftChild;
        } else {
            flag = flag.rightChild;
        }
        return search(key);
    }

    static void lazyRemove(int key) {
        if (flag == null) {
            return;
        }
        if (flag.key == key) {
            flag.isLazyRemove = true;
            return;
        }
        if (key < flag.key) {
            flag = flag.leftChild;
        } else {
            flag = flag.rightChild;
        }
        lazyRemove(key);
    }

    //This code is created by Hanlin Cai in 2022/04/08.
    public static void main(String[] args) throws IOException {

        //Use InputStreamReader to read the data.
        SpecialAVLTree avlTree = new SpecialAVLTree();
        InputStreamReader ISR = new InputStreamReader(new FileInputStream("/Users/lancecai/Desktop/Lab-2022S/CS211_Algorithms&Data Structure 2/Lab2/Lab2_PopularNames.csv"));
        char[] chars = new char[100000];
        ISR.read(chars);
        String[] names = (new String(chars)).split("\n");
        for (int i = 0; i < names.length; i++) {
            int id = Integer.parseInt(names[i].split(",")[0]);
            String name = names[i].split(",")[1];
            insert(id, name);
        }

        System.out.println("--Task 1--");
        System.out.println("I have written the comment in my code.");


        System.out.println(" ");
        System.out.println("--Task 2--");
        //Print all the records line-by-line in an ascending order
        avlTree.sortAscending();


        System.out.println(" ");
        System.out.println("--Task 3--");
//        search(1999);
//        search(2001);
        flag = root;
        if (!search(1492)){
            System.out.println("No match records were found!");
        }
        flag = root;
        if (!search(2001)) {
            System.out.println("No match records were found!");
        }


        System.out.println(" ");
        System.out.println("--Task 4--");
        lazyRemove(1492);
        if (!search(1492)) {
            System.out.println("No match records were found! Because you have lazyRemove() it.");
        }
        //avlTree.sortAscending();


        System.out.println(" ");
        System.out.println("--Task 5--");
        flag = root;
        insert(1492, "Kora");
        search(1492);

        flag = root;
        insert(1492, "Kora1");
        search(1492);
        System.out.println("//Print the same key with two values on the screen.");
        System.out.println("//Thank you! Have a nice day~ :D");

        ISR.close();
    }
    //This code is created by Hanlin Cai in 2022/04/08 16:32
}