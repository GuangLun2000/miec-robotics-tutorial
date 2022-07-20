package MIEC_CS211.Lab1_0325;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;

public class BSTSortingDemo {
    private NodeBST root;

    class NodeBST{
        private int key;
        private int freq;
        private NodeBST leftChild,rightChild;

        public NodeBST(int key){
            this.key = key;
            this.freq = freq;

        }
    }

    public void insert(int key){
        root = insert(root,key);
    }

    public NodeBST insert(NodeBST currentRoot, int key){
        if(currentRoot==null){
            currentRoot = new NodeBST(key);
        }
        if(key < currentRoot.key){
            currentRoot.leftChild = insert(currentRoot.leftChild , key);
        } else if(key > currentRoot.key){
            currentRoot.rightChild = insert(currentRoot.rightChild , key);
        } else {
            currentRoot.freq += 1;
        }
        return currentRoot;
    }

    public void sortAscending() {
        sortAscending(root);
    }

    private void sortAscending(NodeBST currentRoot){
        if(currentRoot == null){
            return;
        }
        sortAscending(currentRoot.leftChild);
        if (currentRoot.freq > 1){
            for (int i = 0; i < currentRoot.freq; i++) {
                System.out.println(currentRoot.key);
            }
        } else {
            System.out.println(currentRoot.key);
        }
        sortAscending(currentRoot.rightChild);
    }

    public void sortDescending(NodeBST currentRoot){
        if(currentRoot == null){
            return;
        }
        sortDescending(currentRoot.rightChild);
        if(currentRoot.freq > 1){
            for (int i = 0; i < currentRoot.freq; i++) {
                System.out.println(currentRoot.key);
            }
        } else {
            System.out.println(currentRoot);
        }
        sortDescending(currentRoot.leftChild);
    }

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
        //tree.sortAscending();
        tree.sortDescending();

        // This code is contributed by Lance Cai
    }

}

