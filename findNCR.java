//program to compute nCr

import java.util.Scanner;
class fact 
{
	public int factorial(int n)
	{
		int fact = 1;
		for(int i=1; i<n; i++)
			fact*=i;
		return fact;
	}
}

class findNCR
{
	public static void main (String[] args)
	{
		Scanner sc = new Scanner(System.in);

		System.out.println("Enter the value of N and R to calculate nCr: ");
		int N = sc.nextInt();
		int R = sc.nextInt();

		fact obj = new fact();

		int n = obj.factorial(N);
		int r = obj.factorial(R);
		int nr = obj.factorial(N-R);
		int ncr = n/(nr*r);

		System.out.println(N+"C"+R+" = "+ncr);
	}
}

