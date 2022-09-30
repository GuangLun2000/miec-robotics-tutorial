// CS211 Experiment 06 Hashing Table
// This code is created by Hanlin Cai in 2022/06/17

import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Hashing {

    public static void main (String[] args){
        //Number of items to be added to the hash table.
        int items = 10;
        //When items = 10, number of Collisions = 0.
        System.out.println("The size of string array is: "+ items);
        String[] contents = new String[items]; //Creating a string array of size 'items'
        try {
            File myObj = new File("/Users/lancecai/Desktop/Lab-2022S/CS211_Algorithms&Data Structure 2/Lab6/dictionary.txt");
            Scanner myReader = new Scanner(myObj);
            int i=0;
            // Iterating through the array and adding strings
            while (myReader.hasNextLine() & i<items) {
                contents[i]=myReader.nextLine();
                i++;
            }
            myReader.close();
            System.out.println(i + " word strings were read from the file.");
        } catch (FileNotFoundException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }
        HashTable mytable = new HashTable(); //Creating a new object (mytable) of type HashTable
        Solution mysolution = new Solution(mytable); //Creating a new object (mysolution) of type Solution which passes in the HashTable
        mysolution.fill(contents); //Filling the contents of mysolution object with string array contents
        System.out.println("Hanlin Cai CS211 2022/06/17");
        //Iterating through the string array and swapping current string position with rand array position
        for(int i=0;i<items;i++)
        {
            int rand = (int)(Math.random()*items); //Returns random int between 0 and times (i.e. 0 and 2);
            String temp = contents[i];
            contents[i]=contents[rand];
            contents[rand]=temp;
        }
        //Iterating through the string array to search for a particular string (word)
        for(int i=0;i<items;i++)
        {
            int slot = mysolution.find(contents[i]); //slot = array positon of searched string
            //If string not found in array position return error
            if(!mytable.check(slot,contents[i]))
            {
                System.out.println("\n error!");
            }
        }
        System.out.println("Number of Collisions: " + mytable.gettotal()); //Printing the number of collisions

    }

}

// This code is created by Hanlin Cai in 2022/06/17
class HashTableRes
{
    public int size = 	1009 ; //Setting size of HashTable (no. of slots)
    private String[] hashTable; //Creating string called hashTable
    private int total=0; //Counter used to return number of collisions

    //Function that creates a string array of size 99991 and sets all slots = "";
    public HashTableRes()
    {
        hashTable = new String[size];
        for(int i=0;i<size;i++)
        {
            hashTable[i]="";
        }
    }
    //Function that checks for a particular string in the hashTable (PARTICULAR STRING OR JUST A STRING I.E. CHECK FOR FREE SLOT)
    public boolean check(int slot, String check)
    {
        if(hashTable[slot].equals(check)) //If current string = string passed in, return true
        {
            return true;
        }
        else //Else, increment the number of collisions and return false
        {
            total++;
            return false;
        }
    }

    //Function that sets slot of hashTable = string
    public void set(int slot, String word)
    {
        hashTable[slot]=word;
    }

    //Function that returns total number of collisions
    public int gettotal()
    {
        return total;
    }
}

// This code is created by Hanlin Cai in 2022/06/17
class Sol
{
    HashTable mytable = new HashTable();
    static int size;
    public Sol(HashTable input){
        mytable = input;
        size = input.size;
    }

    //Function to find words in hashTable
    //fill this in so as to minimize collisions
    //this method should return the slot in the HashTable where the word is
    public int find(String word){
        //fill this in so as to minimize collisions
        //takes in the HashTable object and the word to be found
        //the only thing you can do with the HashTable object is call "check"
        //this method should return the slot in the hashtable where the word is

        int index = getHashKey(word);
        int doubleHashIndex = getDoubleHashKey(word);
        //While there's a collision
        while(mytable.check(index, word) == false){
            //Add the double hash jump size until you find word
            index= index + doubleHashIndex;
            index= index % size;
        }
        return index;
    }


    //fill this in using some hashing strategy
    //this should add all the words in the array into the HashTable
    public void fill(String[] array){
        //takes in the array of Strings to be placed in the mytable HashTable
        //this should add all the words into the hashtable using some system
        //then it should fill the hashtable array

        for(int i=0; i<array.length;i++){
            int index = getHashKey(array[i]);
            int doubleHash = getDoubleHashKey(array[i]);

            //While there are collisions
            while(mytable.check(index, "") == false){
                //Add double hash jump until a free slot is found
                index=index+doubleHash;
                index=index%size;
            }
            mytable.set(index, array[i]);
        }
    }

    //this is the primary hash key function - it should return a number which is a slot in the hash table
    //for words, a good strategy is to raise each character to successive powers of the alphabet size
    //assume that the alphabet is ASCII characters - a total of 256 possibilities
    //each successive character value should be raised to successive powers of 256
    //the whole thing is added together and then moduloed to create a hash table index
    public static int getHashKey(String word){
        BigInteger a;
        BigInteger b;
        BigInteger power = new BigInteger("29");
        BigInteger result = new BigInteger("0");

        //Multiply each char in the string by successive powers of 29 and add them together
        for(int i = 0; i < word.length(); i++){
            a = new BigInteger(Integer.toString(word.charAt(i)));
            b = power.pow(i);
            result = result.add(a.multiply(b));
        }
        BigInteger tableSize = new BigInteger(Integer.toString(size));
        result = result.mod(tableSize);
        return result.intValue();
    }

    //this method should be different to the primary hash function
    //it should return a different number for words which generated the same primary hash key value
    public static int getDoubleHashKey(String word){
        int start = 7;

        for(int i = 0; i < word.length(); i++)
            start = 31 * start + word.charAt(i);

        int max = 7; //Max jump size
        return max - (start % max);
    }

}

// CS211 Experiment 06 Hashing Table
// This code is created by Hanlin Cai in 2022/06/17
// MU number : 20122161
// FZU number: 832002117