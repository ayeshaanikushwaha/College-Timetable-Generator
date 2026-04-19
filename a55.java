class BankAccount {
    private String accountNumber;
    private String accountHolderName;
    private double balance;

    public BankAccount(String accountNumber, String accountHolderName, double balance) {
        setAccountNumber(accountNumber);
        setAccountHolderName(accountHolderName);
        setBalance(balance);
    }

    public String getAccountNumber() {
        return accountNumber;
    }

    public void setAccountNumber(String accountNumber) {
        this.accountNumber = accountNumber;
    }

    public String getAccountHolderName() {
        return accountHolderName;
    }

    public void setAccountHolderName(String accountHolderName) {
        if (accountHolderName == null || accountHolderName.isBlank())
            this.accountHolderName = "Unknown";
        else
            this.accountHolderName = accountHolderName;
    }

    public double getBalance() {
        return balance;
    }

    private void setBalance(double balance) {
        this.balance = Math.max(balance, 0);
    }

    public void deposit(double amount) {
        if (amount > 0) balance += amount;
        else System.out.println("Invalid deposit!");
    }

    public void withdraw(double amount) {
        if (amount > 0 && balance >= amount) balance -= amount;
        else System.out.println("Insufficient funds!");
    }

    public void displayAccount() {
        System.out.printf("Account: %s | Holder: %s | Balance: ₹%.2f%n", accountNumber, accountHolderName, balance);
    }

    public static void main(String[] args) {
        BankAccount b1 = new BankAccount("B1001", "Anshu", 10000);
        b1.deposit(5000);
        b1.withdraw(2000);
        b1.displayAccount();

        BankAccount b2 = new BankAccount("B1002", "", -100);
        b2.displayAccount();
        b2.withdraw(100);
    }
}

