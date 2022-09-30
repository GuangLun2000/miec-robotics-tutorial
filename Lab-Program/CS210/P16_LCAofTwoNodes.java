package MIEC_CS210;

// This code is contributed by Lance Cai
// Java Program for Lowest Common Ancestor in a Binary Tree
// A O(n) solution to find LCA of two given values n1 and n2

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


    // A Binary Tree node
    class Node {
        int data;
        Node left, right;

        Node(int value) {
            data = value;
            left = right = null;
        }
    }

    public class P16_LCAofTwoNodes
    {

        Node root;
        private List<Integer> path1 = new ArrayList<>();
        private List<Integer> path2 = new ArrayList<>();

        // Finds the path from root node to given root of the tree.
        int findLCA(int n1, int n2) {
            path1.clear();
            path2.clear();
            return findLCAInternal(root, n1, n2);
        }

        private int findLCAInternal(Node root, int n1, int n2) {

            if (!findPath(root, n1, path1) || !findPath(root, n2, path2)) {
                System.out.println((path1.size() > 0) ? "n1 is present" : "n1 is missing");
                System.out.println((path2.size() > 0) ? "n2 is present" : "n2 is missing");
                return -1;
            }

            int i;
            for (i = 0; i < path1.size() && i < path2.size(); i++) {

                // System.out.println(path1.get(i) + " " + path2.get(i));
                if (!path1.get(i).equals(path2.get(i)))
                    break;
            }

            return path1.get(i-1);
        }

        // Finds the path from root node to given root of the tree, Stores the
        // path in a vector path[], returns true if path exists otherwise false
        private boolean findPath(Node root, int n, List<Integer> path)
        {
            // base case
            if (root == null) {
                return false;
            }

            // Store this node . The node will be removed if
            // not in path from root to n.
            path.add(root.data);

            if (root.data == n) {
                return true;
            }

            if (root.left != null && findPath(root.left, n, path)) {
                return true;
            }

            if (root.right != null && findPath(root.right, n, path)) {
                return true;
            }

            // If not present in subtree rooted with root, remove root from
            // path[] and return false
            path.remove(path.size()-1);

            return false;
        }

        // Driver code
        public static void main(String[] args)
        {
            // This code is contributed by Lance Cai
             /* The amazing tree
                  1
                /   \
              2       3
               \     / \
                4   5   6
                   / \
                  7   8
            */

            //System.out.println("please input tree: ");
            Scanner input = new Scanner(System.in);
            String str = input.next();
            String[] string = str.split(",");
            int[] numsInt1 = new int[string.length];
            for (int i = 0; i < string.length; i++) {
                numsInt1[i] = Integer.parseInt(string[i]);
                //System.out.print(numsInt1[i]+" ");
            }

            //System.out.println("please input num: ");
            int a = input.nextInt();
            int b = input.nextInt();

            P16_LCAofTwoNodes tree = new P16_LCAofTwoNodes();
            tree.root = new Node(numsInt1[0]);
            tree.root.left = new Node(numsInt1[1]);
            tree.root.right = new Node(numsInt1[2]);

            tree.root.left.left = new Node(numsInt1[3]);
            tree.root.left.right = new Node(numsInt1[4]);
            tree.root.right.left = new Node(numsInt1[5]);
            tree.root.right.right = new Node(numsInt1[6]);

            tree.root.left.left.left = new Node(numsInt1[7]);
            tree.root.left.left.right = new Node(numsInt1[8]);
            tree.root.left.right.left = new Node(numsInt1[9]);
            tree.root.left.right.right = new Node(numsInt1[10]);
            tree.root.right.left.left = new Node(numsInt1[11]);
            tree.root.right.left.right = new Node(numsInt1[12]);

            System.out.println(tree.findLCA(a,b));


        }
    }

// This code is contributed by Lance Cai 20122161
