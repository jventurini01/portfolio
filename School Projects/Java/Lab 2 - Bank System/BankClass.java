package lab2;
import java.util.ArrayList;
public class BankClass {
	private String accountName; // acct name
    private String licenseNum; // license number
    private ArrayList<Customer> customers; // array list of customers
    public void Bank(String name, String licenseNum) {
        this.accountName = name;
        this.licenseNum = licenseNum;
        this.customers = new ArrayList<>();
    }
    public String getName() {
        return accountName;
    }

    public String getLicenseNum() {
        return licenseNum;
    }

    public ArrayList<Customer> getCustomers() {
        return customers;
    }
    // method to add a new customer
    public void addCustomer(String name, String ssn){
        customers.add(new Customer(name, ssn));
    }
}