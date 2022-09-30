package MIEC_CS211;

import java.io.*;
import java.util.*;
import java.util.HashMap;
import java.util.Map;


class Node{
    Node left;
    Node right;
    Character character;

    public Node(Character character){
        this.character=character;
    }
    public void setChar(Character character){
        this.character=character;
    }

    @Override
    public String toString() {
        return "Node{" +
                "character=" + character +
                '}';
    }

    // Using the preOrder to output the string
    public void preOreder(){
        System.out.println(this);
        if(this.left!=null){
            this.left.preOreder();
        }if(this.right!=null){
            this.right.preOreder();
        }
    }


    /*
    Construct a binary tree for the Huffman codewords. The method must be named:
    "public void constructHuffmanTree(String codewords)”.
    Provide comment for the method to explain how the algorithm works.
     */

    public void constructHuffmanTree(String codewords){
        //Use HashMap to put the corresponding password and letter
        Map<String,Character> list=new HashMap<>();
        StringBuilder stringBuilder=new StringBuilder();
        for(int i=0;i<codewords.length();i++){
            if(codewords.charAt(i)=='1'||codewords.charAt(i)=='0'){
                stringBuilder.append(codewords.charAt(i));
            }else{ //Store in map to form corresponding key-value pairs
                list.put(stringBuilder.toString(),codewords.charAt(i));
                //clean up
                stringBuilder=new StringBuilder();
            }
        }


        for (Map.Entry<String,Character> entry : list.entrySet()) {
//          To find the password
            String code=entry.getKey();
            Node node=this;
            for(int i=0;i<code.length();i++){
                if(code.charAt(i)=='0'){//If it is empty, then a new node is created
                    if(node.left==null){
                        Node left=new Node(null);
                        node.left=left;
                        node=left;
                    }else{
                        node=node.left;}
                }else{
                    if(node.right==null){
                        Node right=new Node(null);
                        node.right=right;
                        node=right;
                    }else{
                        node=node.right;}
                }
            }
            char c=entry.getValue();
            node.setChar(c);
        }

    }

    /*
    Use the constructed binary tree to decode the cipher text and print the decoded text on screen.
    NOTE: you must use the binary tree to decode the cipher text. The decoding method must be named:
    “public String decode(String cipher)”
    Provide comment for the method to explain how your decoding algorithm works.
     */
    public String decode(String cipher){
        StringBuilder stringBuilder = new StringBuilder();
        StringBuilder result=new StringBuilder();
        for(int i=0;i<cipher.length();i++){
            stringBuilder.append(cipher.charAt(i));
            Node node=this;

            /*
            In theory, we don't need to check the first few password bits
            because they must be empty, and just go to the last one
            But then you still have to do things outside of the loop
            and the code is still there, so I'm just going to go through each loop and look it up~
             */

            for(int j=0;j<stringBuilder.length();j++){
                if(stringBuilder.charAt(j)=='0'){
                    node=node.left;
                    if(node.character!=null){
                        result.append(node.character);
                        stringBuilder=new StringBuilder();
                    }
                }else{
                    node=node.right;
                    if(node.character!=null){
                        result.append(node.character);
                        stringBuilder=new StringBuilder();
                    }
                }
            }
        }
        return result.toString();
    }

}
// This code is contributed by Lance Cai 832002117


public class HuffmanDecoder {

    public static void main(String[] args) throws IOException {

        // 助教您好，在此处进行测试！
        // 助教您好，在此处进行测试！
        // 助教您好，在此处进行测试！
        File f = new File("/Users/lancecai/Desktop/Lab-2022S/CS211_Algorithms&Data Structure 2/Lab1/Cipher.txt");
        FileReader fre = new FileReader(f);
        BufferedReader bre=new BufferedReader(fre);
        String line1 = bre.readLine();
        String line2 = bre.readLine();
        Node node=new Node(null);
        node.constructHuffmanTree(line1);
        String codewordsDecoder = node.decode(line2);
        System.out.println(codewordsDecoder);

//        String password = "110 01000001&111011.00100111A00100110B01000000D01000011E001000I00100100S0010101T00100101W0111a11101011b01101c01010d1111e01001f00000g11100h1010i0010100k1000l01100m01011n0001o1110100p1011r0011s1001t00001u01000010v010001w11101010x001011y";
//        String codewords = "001001011111100001101000101100111111010010001110010000000111100101111100010010010011011000010110110010000110111111001111001000001110001001111000000000001101110101001111000110000111100010000010001110111100100001101001010011111011011001101001000010111110000010111100000100111010010110000011001010011110010111110001110011011000010110110010000110111111001111001110101101010110011110000000000011011101010011110001100001111001000110101000100011001100011100101001111110001011000100001101111011101001011000100000101101110110000111100110000011011111111011110100101001101001101101011110101110011110111100010101111001010001111010100011110100111100111111001001101010110011100111011101001011011101101100110100110101111000110010001000110110010100110000101001110100111100101000111100110000010101000001100011111110111100010001101010010111001111101011100110100001010110111100010000010111100110001110101011111101010100111000111010011001110100100011111011111011110001010111100111111001001000110001000000101000110100101100000110100001111110101111011111110101011111011011011010001111110011110010001101010001000110111010111111110111000111101101010111110111100111010110101011011100011110110101011111011111011110001001101111110101111110111010100010111100100100011011110100111100111111001101111000111100010001111010110000011110011111011";
//        Node node=new Node(null);
//        node.constructHuffmanTree(password);
//        String codewordsDecoder = node.decode(codewords);
//        System.out.println(codewordsDecoder);
//        This code is contributed by Lance Cai 832002117

    }
}