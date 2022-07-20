import java.util.*;
import java.math.BigInteger;

public class PublicKeyCryptography
{
    public static void main (String args[]){
        // ADD YOUR CODE HERE>

        /**
         * p g y   Alice’s public key
         * c1 c2   Bob's cipher
         *
         * Pen and Paper Exercise
         * when the input = (29,2,3) and (23,27)
         * the result = 15
         */
        long p = 24852977l;
        long g = 2744l;
        long y = 8414508l;
        long c1 = 15268076l;
        long c2 = 743675l;

        // User input
//        Scanner sc = new Scanner(System.in);
//        long p = sc.nextLong();
//        long g = sc.nextLong();
//        long y = sc.nextLong();
//        sc.nextLine();
//        long c1 = sc.nextLong();
//        long c2 = sc.nextLong();
//        sc.close();

        long current = g;
        long power = 1;

        // Keep raising the generator to successive powers
        // until you find the one that gives you a match.
        // This code is created by Hanlin Cai
        while(current != y){
            current = modMult(current,g,p);
            if(current >= p){
                current = current % p;
            }
            power++;
        }
        long x = power;

        // All of this is a direct implementation of the ElGamal algorithm detailed in the notes
        // This code is created by Hanlin Cai
        long divisor = modPow(c1,p-1-x ,p);
        long res = modMult(divisor,c2 , p);
        System.out.println(res);

    }

    public static long modPow(long number, long power, long modulus){
        if(power==0)
            return 1;
        else if (power%2==0) {
            long halfpower=modPow(number, power/2, modulus);
            return modMult(halfpower,halfpower,modulus);
        }else{
            long halfpower=modPow(number, power/2, modulus);
            long firstbit = modMult(halfpower,halfpower,modulus);
            return modMult(firstbit,number,modulus);
        }
    }
    // Comment for function modPow(): Raises a number to a power with the given modulus.
    // When raising a number to a power, the number quickly becomes too large to handle.
    // You need to multiply numbers in such a way that the result is consistently moduloed to keep it in the range.
    // However, you want the algorithm to work quickly - having a multiplication loop would result in an O(n) algorithm!


    public static long modMult(long first, long second, long modulus){
        if(second==0)
            return 0;
        else if (second%2==0) {
            long half=modMult(first, second/2, modulus);
            return (half+half)%modulus;
        }else{
            long half=modMult(first, second/2, modulus);
            return (half+half+first)%modulus;
        }
    }
    // Comment for function modMult(): Multiplies the first number by the second number with the given modulus.
    // A long can have a maximum of 19 digits. Therefore, if you're multiplying two ten digits numbers the usual way,
    // things will go wrong. You need to multiply numbers in such a way that the result is consistently moduloed to keep it in the range.
    // However, you want the algorithm to work quickly having an addition loop would result in an O(n) algorithm!


}
// Experiment 05 PublicKeyCryptography
// This code is created by Hanlin Cai in 2022/05/20 Valentine's day 520
// MU number : 20122161
// FZU number: 832002117