class Account {
    private String accountNumber;
    private String accountHolder;
    private double balance;

    public String getAccountNumber() {
        return accountNumber;
    }

    public void setAccountNumber(String accountNumber) {
        this.accountNumber = accountNumber;
    }

    public String getAccountHolder() {
        return accountHolder;
    }

    public void setAccountHolder(String accountHolder) {
        this.accountHolder = accountHolder;
    }

    public double getBalance() {
        return balance;
    }

    public void deposit(double amount) {
        if (amount > 0) balance += amount;
        else System.out.println("Invalid deposit amount!");
    }

    public void withdraw(double amount) {
        if (amount > 0 && amount <= balance)
            balance -= amount;
        else
            System.out.println("Invalid or insufficient balance!");
    }

    public static void main(String[] args) {
        Account acc = new Account();
        acc.setAccountNumber("A1001");
        acc.setAccountHolder("Anshu");
        acc.deposit(5000);
        acc.withdraw(1200);
        System.out.println("Balance: ₹" + acc.getBalance());
    }
}
