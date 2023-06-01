package loginSystem;
import java.util.Scanner;
public class Login {
	public void userInput() {
		Scanner input = new Scanner (System.in);
		System.out.print("Please Enter your name: ");
		String name = input.nextLine();
		System.out.print("Please Enter your PIN: ");
		int pin = input.nextInt();
		
		String acctName = "Joseph";
		int acctPIN = 112233;
		
		if(name.equals(acctName) && pin == acctPIN) {
			System.out.print("Access Granted. Hello, " + acctName);
		} else {
			System.out.print("Incorrect Username or Password. Please try again.");
		}
	}
}
class Main {
	public static void main(String args[]) {
		userInput();
	}
}