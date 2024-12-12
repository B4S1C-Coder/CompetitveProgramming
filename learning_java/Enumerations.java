import com.someOrg.enums.TestEnum;

public class Enumerations {
    public static void main(String[] args) {
        System.out.println(TestEnum.SUNDAY);
        System.out.println(TestEnum.SUNDAY.ordinal()); // 0 (int) (as this was defined first in ordinal)
        System.out.println(TestEnum.SUNDAY.name()); // SUNDAY (String)

        String day = TestEnum.THURSDAY.name();
        System.out.println(day);

        TestEnum[] values = TestEnum.values(); // returns array containg all the values of the enum

        for (TestEnum i: values) {
            System.out.println(i+" "+i.ordinal());
        }

        TestEnum someday = TestEnum.MONDAY;
        someday.display();

        // Old switch case
        TestEnum bday = TestEnum.WEDNESDAY;

        switch (bday) {
            case TestEnum.WEDNESDAY:{
                System.out.println("Bday!");
                break;
            }
            case TestEnum.THURSDAY: {
                System.out.println("Low classes!");
                break;
            }
        
            default: {
                System.out.println("Defualt case");
            }
        }

        // New switch case (after Java 12)
        String res = switch (bday) {
            case MONDAY -> "Mon";
            case TUESDAY -> "Tue";
            case WEDNESDAY -> "Wed";
            default -> "Other";
        };

        System.out.println(res);

    }
}
