//program to find roots of a quadratic equation using different class

import java.util.Scanner;
class roots 
{
	public void calc(int a, int b, int c)
	{
		int check;
		double D = (b*b) - 4*a*c;
		if ( D == 0.0 )
			check = 0;
		else if ( D > 0.0 )
			check = 1;
		else
			check = -1;
		switch (check)
		{
			case 0:
				System.out.println("The roots are real and equal");
				double r = (-b + Math.sqrt(D))/(2.0*a);
				System.out.println("Roots = "+r);
				break;

			case 1:
				System.out.println("The roots are real and unequal");
				double r1 = (-b + Math.sqrt(D))/(2.0*a);
				double r2 = (-b - Math.sqrt(D))/(2.0*a);
				System.out.println("Root1 = "+r1);
				System.out.println("Root2 = "+r2);
				break;
			case -1:
				System.out.println("The rooots are imaginary");
				double rp = (-b * 1.0)/(2*a);
				double im = (Math.sqrt(Math.abs(D)))/(2.0*a);
				System.out.println("Root1 = "+rp+"+i"+im);
				System.out.println("Root1 = "+rp+"-i"+im);
		}
	}
}

class findRoots 
{
	public static void main (String[] args)
	{
		Scanner sc = new Scanner(System.in);

		System.out.println("Input the coefficients of the quadratic equation a,b,c: ");
		int a = sc.nextInt();
		int b = sc.nextInt();
		int c = sc.nextInt();

		if(a == 0)
		{
			while ( a==0 )
			{
				System.out.println ("Please enter a valid quadratic equation:");
				a = sc.nextInt();
				b = sc.nextInt();
				c = sc.nextInt();
			}
		}
		roots ob = new roots();

		ob.calc(a, b, c);
	}
}
