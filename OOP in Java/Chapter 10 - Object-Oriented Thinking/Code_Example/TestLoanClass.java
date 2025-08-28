import java.util.Scanner;

public class TestLoanClass 
{
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        System.out.println("Enter annual interest rate, for example, 8.25: ");
        double annualInterestRate = input.nextDouble();

        System.out.println("Enter number of years as an integer, for example, 5: ");
        int numberOfYears = input.nextInt();

        System.out.println("Enter loan amount, for example, 120000.95: ");
        double loanAmount = input.nextDouble();

        Loan loan = new Loan(annualInterestRate, numberOfYears, loanAmount);

        System.out.printf("The loan was created on %s \n" + 
        "The monthly payment is %.2f\nThe total payment is %.2f\n",
        loan.getLoanDate().toString(),
        loan.getMonthlyPayment(),
        loan.getTotalPayment());

        input.close();
    }
}

class Loan {
    private double annualInterestRate;
    private int numberOfYears;
    private double loanAmount;
    private java.util.Date loanDate;
    
    // Default constructor
    public Loan() {
        this(2.5, 1, 1000);
    }
    
    // Parameterized constructor
    public Loan(double annualInterestRate, int numberOfYears, double loanAmount) {
        this.annualInterestRate = annualInterestRate;
        this.numberOfYears = numberOfYears;
        this.loanAmount = loanAmount;
        loanDate = new java.util.Date();
    }
    
    // Getter methods
    public double getAnnualInterestRate() { return annualInterestRate; }
    public int getNumberOfYears() { return numberOfYears; }
    public double getLoanAmount() { return loanAmount; }
    public java.util.Date getLoanDate() { return loanDate; }
    
    // Setter methods
    public void setAnnualInterestRate(double annualInterestRate) {
        this.annualInterestRate = annualInterestRate;
    }
    public void setNumberOfYears(int numberOfYears) {
        this.numberOfYears = numberOfYears;
    }
    public void setLoanAmount(double loanAmount) {
        this.loanAmount = loanAmount;
    }
    
    // Calculation methods
    public double getMonthlyPayment() {
        double monthlyInterestRate = annualInterestRate / 1200;
        double monthlyPayment = loanAmount * monthlyInterestRate / 
            (1 - (1 / Math.pow(1 + monthlyInterestRate, numberOfYears * 12)));
        return monthlyPayment;
    }
    
    public double getTotalPayment() {
        return getMonthlyPayment() * numberOfYears * 12;
    }
}