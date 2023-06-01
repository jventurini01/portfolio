package lab2;
import java.util.ArrayList;
public class Customer {
	private String customerName;
    private String socialSecurityNum;
    private ArrayList<Account> accounts;
    public Customer(String cusName, String ssn) {
        this.customerName = cusName;
        this.socialSecurityNum = ssn;
        this.accounts = new ArrayList<>();
    }
    public String getCusName() {
        return customerName;
    }

    public String getSsn() {
        return socialSecurityNum;
    }

    public ArrayList<Account> getAccounts() {
        return accounts;
    }
    public void addAccount(String accType, String accNum, double balance, String creditCardNum, int pinCode){
        Account createdAccount = new Account(accType, accNum, balance, creditCardNum, pinCode);
        accounts.add(createdAccount);
    }
}
