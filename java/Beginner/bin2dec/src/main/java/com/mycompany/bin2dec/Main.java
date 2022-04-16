package com.mycompany.bin2dec;
import java.util.Scanner;

public class Main {
    
    Scanner scan = new Scanner(System.in);

    public static void main(String[] args) {
        Main app = new Main();
        System.out.println("This app will take your binary number and convert it"
                + " to decimal.");
        app.menu();  
    }
    
    private void menu()
    {
        String response;
        while (true)
        {
            System.out.println("(1) Convert Binary to Decimal \n(2) Exit App");
            response = scan.next();
            if (response.equals("1"))
            {
                this.validateInput(); 
            }
            else if (response.equals("2"))
            {
                System.out.println("Goodbye!");
                break;
            }
        }   
    }
    private void validateInput()
    {
        String userBin = "";
        int count;
    
        while (true)
        {
            count = 0;
            System.out.println("Please enter a binary number to be converted. "
                    + "\nMust be between 1-8 binary numerals long:");
            userBin = scan.next(); //assigning string to input

            for (int i = 0; i < userBin.length(); i++)
            {
               char currChar = userBin.charAt(i);
               if (currChar == '0' || currChar == '1')
               {
                   count += 1;
               }                
            }
            //validation for length and numerals
            if (count < userBin.length())
            {
                System.out.println("Please enter a valid binary num.");
            }
            if (userBin.length() > 8)
            {
                System.out.println("Ensure binary num is 8 or less numerals.");
            }
            if (userBin.length() <= 8 && count == userBin.length()) 
            {
                break;
            }               
        }  
       this.convertBin(userBin);
    }
    
    private void convertBin(String userBin)
    {
       System.out.println("The decimal equivalent of " + userBin + " is: " + 
               Integer.parseInt(userBin, 2)); //converting string to int, and passing radix of 2 (base 2)
    }
    
}
