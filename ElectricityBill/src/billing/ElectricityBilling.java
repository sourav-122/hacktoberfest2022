package billing;

import java.util.Scanner;

public class ElectricityBilling {

	public static void main(String[] args) {


		int units;  
		double billToPay = 0;  

		Scanner sc = new Scanner(System.in);  

		System.out.println("Enter number of units for calculating electricity bill.");  
		units = sc.nextInt();  


		if(units < 100)  
		{  
			billToPay = units * 1.20;  
		}  
		else if(units < 300){  
			billToPay = 100 * 1.20 + (units - 100) * 2;  
		}
		else if(units > 300)  
		{  
			billToPay = 100 * 1.20 + 200 * 2 + (units - 300) * 3;  
		}  
		System.out.println("The electricity bill for " +units+ " is : " + billToPay);

	}

}
