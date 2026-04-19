import java.util.*;

interface Account {
    void deposit(double amount);
    void withdraw(double amount);
    void calculateInterest();
    void viewBalance();
}
class SavingAccount implements Account {
    private String accountHolder;
    private double balance;
    private double interestRate = 0.05; 
    public SavingAccount(String accountHolder, double initialBalance) {
        this.accountHolder = accountHolder;
        this.balance = initialBalance;
    }

    @Override
    public void deposit(double amount) {
        balance += amount;
        System.out.println(accountHolder + " deposited ₹" + amount);
    }

    @Override
    public void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            System.out.println(accountHolder + " withdrew ₹" + amount);
        } else {
            System.out.println("Insufficient balance!");
        }
    }

    @Override
    public void calculateInterest() {
        double interest = balance * interestRate;
        balance += interest;
        System.out.println("Interest of ₹" + interest + " added to " + accountHolder + "'s savings account.");
    }

    @Override
    public void viewBalance() {
        System.out.println("Savings Account Balance of " + accountHolder + ": ₹" + balance);
    }

    public void lockInSavings() {
        System.out.println(accountHolder + "'s savings are locked for long-term deposit.");
    }
}

class CurrentAccount implements Account {
    private String accountHolder;
    private double balance;
    private double overdraftLimit = 5000.0;

    public CurrentAccount(String accountHolder, double initialBalance) {
        this.accountHolder = accountHolder;
        this.balance = initialBalance;
    }

    @Override
    public void deposit(double amount) {
        balance += amount;
        System.out.println(accountHolder + " deposited ₹" + amount);
    }

    @Override
    public void withdraw(double amount) {
        if (balance + overdraftLimit >= amount) {
            balance -= amount;
            System.out.println(accountHolder + " withdrew ₹" + amount);
        } else {
            System.out.println("Withdrawal exceeds overdraft limit!");
        }
    }

    @Override
    public void calculateInterest() {
        System.out.println("No interest for current accounts.");
    }

    @Override
    public void viewBalance() {
        System.out.println("Current Account Balance of " + accountHolder + ": ₹" + balance);
    }

    public void issueCheque() {
        System.out.println("Cheque issued from " + accountHolder + "'s current account.");
    }
}

class BankingSystem {
    private List<Account> accounts = new ArrayList<>();

    public void addAccount(Account acc) {
        accounts.add(acc);
        System.out.println("Account added successfully!");
    }

    public void showAllAccounts() {
        System.out.println("\n--- Bank Accounts Summary ---");
        for (Account acc : accounts) {
            acc.viewBalance();
        }
    }
}

public class demo1 {
    public static void main(String[] args) {
        BankingSystem bank = new BankingSystem();

        SavingAccount saving = new SavingAccount("Anshu", 10000);
        CurrentAccount current = new CurrentAccount("Riya", 20000);

        bank.addAccount(saving);
        bank.addAccount(current);

        saving.deposit(2000);
        saving.calculateInterest();
        saving.lockInSavings();

        current.withdraw(25000);
        current.issueCheque();

        bank.showAllAccounts();
    }
}
