import com.someOrg.core.Student;
import com.someOrg.core.BankAccount;

public class Encapsulation {
    public static void main(String[] args) {
        Student vidyarthi = new Student();
        vidyarthi.name("Testksn Kwsnk");
        vidyarthi.age(18);
        vidyarthi.rollNo(359982244);
        vidyarthi.school = "Thapar Institute of Engineering and Technology, Patiala";

        vidyarthi.printInfo();

        BankAccount studentAcc = new BankAccount(vidyarthi);
        studentAcc.deposit(50000.0);

        BankAccount.Loan educationLoan = studentAcc.new Loan(100000, 2, 4);
        educationLoan.register();

        System.out.println(studentAcc.getAmountOwed());

        studentAcc.printProfile();
    }
}
