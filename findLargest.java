//program to create a class largest and find the largest of 3 numbers

import java.util.Scanner;
class largest
{
	public double maximum(double a, double  b, double c)
	{
		double max = (a>b) ?  ( (a>c) ?a:c ) : ( (b>c) ?b:c);
		return max;
	}
}

class findLargest {
	public static void main (String[] args){
		Scanner sc = new Scanner(System.in);

		System.out.println("Input 3 numbers: ");
		double num1 = sc.nextDouble();
		double num2 = sc.nextDouble();
		double num3 = sc.nextDouble();

		largest obj = new largest();

		double largest = obj.maximum(num1, num2, num3);
		System.out.println("The largest of "+num1+", "+num2+" and "+num3+" is "+largest);

	}
}
