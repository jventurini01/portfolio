package lab2;
import java.util.ArrayList;
import java.util.List;
public class MainClass {
	public static void main(String[] args) {
		Account Cristian = new Account("Checking","1",42069.85,"1234-5678-9000-2020",678349);
		Account Julio = new Account("Savings","5",8000.00,"0987-6543-2100-0202",431100);
		Account Joseph = new Account("Savings","3",12345.67,"4311-7070-6060-8637",765234);
		
		List<Account> accountList = new ArrayList<>();
		accountList.add(Cristian);
		accountList.add(Julio);
		accountList.add(Joseph);
		
		Cristian.showMenu();

	}

}
