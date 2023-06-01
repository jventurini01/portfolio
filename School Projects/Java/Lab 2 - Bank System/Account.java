package lab2;
import java.util.Scanner;
public class Account {

    String accountType;
    String accountNumber;
    double balance;
    String creditCardNumber;
    int pinCode;

    public Account(String accType, String accNum, double balance, String ccn, int pin) {
        this.accountType = accType;
        this.accountNumber = accNum;
        this.balance = balance;
        //ccn is an abbreviation for creditCardNumber
        this.creditCardNumber = ccn;
        this.pinCode = pin;

    }

    public void deposit(double depositValue) {
        this.balance = balance + depositValue;
        System.out.println("You have deposited " + depositValue + "and you now have " + balance);
    }

    public void withdraw(double withdrawalValue) {
        this.balance = balance - withdrawalValue;
        System.out.println("You have withdrawn " + withdrawalValue + " and your remaining balance is " + balance);
    }
    
    public double checkBalance() {
        System.out.println("Your current balance is " + balance);
        return balance;
    }

    public void showInfo() {
        System.out.println("Your account type is: " + accountType + "\n" + "Your account number is: " + accountNumber + "\n" + "Your balance is currently: " + balance);
    }

    public void showMenu() {
        System.out.println("Hello, valued customer! To get started, please select an option from below.");
        System.out.println("Type in A to make a deposit.");
        System.out.println("Type in B to make a withdrawal.");
        System.out.println("Type in C to check your balance.");
        System.out.println("Type in D to show info.");
        Scanner input = new Scanner(System.in);
        String option = input.nextLine();
        if(option.equals("A")) {
            System.out.println("Enter an amount to be deposited: ");
            double depositValue = input.nextDouble();
            deposit(depositValue);

        } else if(option.equals("B")) {
            System.out.println("Enter an amount to be withdrawn: ");
            double withdrawalValue = input.nextDouble(); 
            withdraw(withdrawalValue);

        } else if(option.equals("C")) {
            checkBalance();

        } else if(option.equals("D")) {
            showInfo();
        
        } else {
            System.out.println("Invalid Input. Please try again.");
            
        }
    }
}
