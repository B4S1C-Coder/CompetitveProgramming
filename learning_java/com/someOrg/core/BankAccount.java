package com.someOrg.core;

import java.time.Instant;

public class BankAccount {
    private Student m_holderStudent;
    private long m_accountNumber = Instant.now().getEpochSecond();
    private double m_balance = 0.0;
    private boolean m_hasLoan = false;
    private Loan[] m_currentLoans = new Loan[5]; // .length returns 5 regradless of how many objs in arr
    private int m_loanCount = 0;                 // To maintain the actual count of registered loans

    public class Loan {
        private double m_principal;
        private double m_interestRate;
        private int m_timePeriod;
        private long m_loanID = Instant.now().getEpochSecond();

        public Loan(double principal, double interestRate, int timePeriod) {

            if (principal < 10000.0) {
                throw new IllegalArgumentException("Principal must be atleast 10,000 INR");
            }

            if ((interestRate < 0) || (interestRate > 100)) {
                throw new IllegalArgumentException("Interest rate must belong to [0, 100]");
            }

            if (timePeriod < 0) {
                throw new IllegalArgumentException("Time Period must be positive");
            }

            this.m_principal = principal;
            this.m_interestRate = interestRate;
            this.m_timePeriod = timePeriod;
        }

        public void reviseLoanArgeement(double interestRate, int timePeriod) {
            if ((interestRate < 0) || (interestRate > 100)) {
                throw new IllegalArgumentException("Interest rate must belong to [0, 100]");
            }

            if (timePeriod < 0) {
                throw new IllegalArgumentException("Time Period must be positive");
            }
            this.m_interestRate = interestRate;
            this.m_timePeriod = timePeriod;
        }

        public long id() {
            return m_loanID;
        }
        public double principal() {
            return m_principal;
        }
        public double interestRate() {
            return m_interestRate;
        }
        public int timePeriod() {
            return m_timePeriod;
        }
        public double amountToPay() {
            return m_principal + ((m_interestRate/100.0)*m_principal*(double)m_timePeriod);
        }
        public void register() {
            if (m_loanCount == 4) {
                return;
            }
            if (!m_hasLoan) {
                m_hasLoan = true;
            }
            // m_currentLoans[m_loanCount] = BankAccount().Loan(this.m_principal, this.m_interestRate, this.m_timePeriod);
            m_currentLoans[m_loanCount] = this;
            m_loanCount++;
        }
    }

    public BankAccount(Student student) {
        this.m_holderStudent = student;
    }

    public void deposit(double amount) {
        m_balance += amount;
    }

    public double getAmountOwed() {
        double sum = 0;

        for (Loan loan: m_currentLoans) {
            sum += loan.amountToPay();
        }

        return sum;
    }

    public void printProfile() {
        System.out.println("------------------------------------");
        System.out.println("Name: " + m_holderStudent.name());
        System.out.println("Age : " + m_holderStudent.age());
        System.out.println("Acc : " + m_accountNumber);
        System.out.println("Bal : " + m_balance);
        System.out.println("Lo C: " + m_loanCount);
        System.out.println("hasL: " + m_hasLoan);
        System.out.println("CurL: ");

        for (Loan loan: m_currentLoans) {
            System.out.println("      " + loan.id());
        }

        System.out.println("------------------------------------");
    }
}
