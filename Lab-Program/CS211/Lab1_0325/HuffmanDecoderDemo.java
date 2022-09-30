package MIEC_CS211.Lab1_0325;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class HuffmanDecoderDemo {
    public NodeDemo huffmanTree;

    public HuffmanDecoderDemo(){
        huffmanTree = new NodeDemo(2);
    }

    public class NodeDemo {
        int key;
        char value;
        NodeDemo left, right;

        NodeDemo(int key) {
            this.key = key;
        }
    }

    public void constructHuffmanTreeDemo(String codewords) {
        //定义一个tempRoot
        NodeDemo currentRoot = huffmanTree;
        for (int i = 0; i < codewords.length(); i++) {
            if (codewords.charAt(i) == '0') {
                if (currentRoot.left == null) {
                    currentRoot.left = new NodeDemo(0);
                }
                currentRoot = currentRoot.left;
                //1、先向左
            } else if (codewords.charAt(i) == '1') {
                if (currentRoot.right == null) {
                    currentRoot.right = new NodeDemo(1);
                }
                currentRoot = currentRoot.right;
                //2、后向右
            }

            if(i < (codewords.length()-1) && codewords.charAt(i+1) != '0' && codewords.charAt(i+1) != '1'){
                currentRoot.value = codewords.charAt(++i);
                currentRoot = huffmanTree;
            }
        }
    }


    public String decode(String cipher){
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < cipher.length(); i++) {
            NodeDemo root = huffmanTree;
            while (root.left != null && root.right != null && i<cipher.length()){
                if (cipher.charAt(i) == '1'){
                    root = root.right;
                } else {
                    root = root.left;
                }
                i++;
            }
            if (root != null){
                sb.append(root.value);
            }

        }
        return sb.toString();
    }



    public static void main(String[] args) {

        HuffmanDecoderDemo hd = new HuffmanDecoderDemo();
        Scanner sc;
        try {
            sc = new Scanner(new File("/Users/lancecai/Desktop/Lab-2022S/CS211_Algorithms&Data Structure 2/Lab1/Cipher.txt"));
            String codewords = sc.nextLine();
            String ciper = sc.nextLine();

            hd.constructHuffmanTreeDemo(codewords);
            System.out.println(hd.decode(ciper));

        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }

    }

}








