//program to generate first n prime number 

import java.util.Scanner;
class isPrime {
    public boolean findPrime (int n) {

        int check = 0;
        for(int i=1; i<=n; i++)
            if(n%i == 0)
                check++;
        if(check == 2)
            return true;
        else
            return false;
    }
}

class prime {
    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter n to generate n prime numbers: ");
        int n = sc.nextInt();

        isPrime obj = new isPrime();

        for(int i=1; i<=n; i++)
        {
           boolean check =  obj.findPrime(i);
           if(check)
               System.out.println(i+", ");
        }

    }
}
