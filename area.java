//Program to find area of circle
import java.util.Scanner;

public class Area{
		 public static void main(String[] args) {
		 		double area;
		 		System.out.println("enter number");
				Scanner num=new Scanner(System.in);
		 		double r=num.nextDouble();
		 		area=3.14*r*r;
		 		System.out.println("Area of Circle With Radius"+r+"="+area);
			
		}
}