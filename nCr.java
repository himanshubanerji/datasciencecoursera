// program to find the nCr 

import java.util.Scanner;
class fact {
    public int factorial (int n) {
        int fact = 1;
        for(int i=1; i<=n;i++)
            fact*=i;
        return fact;
    }
}
class nCr {
    public static void main (String[] args) {
        Scanner sc = new Scanner (System.in);

        System.out.println("Enter the value of n and r for nCr: ");
        int n = sc.nextInt();
        int r = sc.nextInt();

        fact obj = new fact();
        double ncr = obj.factorial(n) / (obj.factorial(r)* obj.factorial(n-r));

        System.out.println("The value of "+n+"C"+r+" is: "+ncr);
    }
}
