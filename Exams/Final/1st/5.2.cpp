/*

Q5 (b) Write class Date that can output date in multiple formats (e.g., 02/18/2024, February 18, 2024). [12 marks]

Simple Java class using SimpleDateFormat:

import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Calendar;

public class DateClass {
    private Date date;

    public DateClass(int year, int month, int day) {
        Calendar cal = Calendar.getInstance();
        cal.set(year, month - 1, day); // month is 0-based in Calendar
        date = cal.getTime();
    }

    public String asNumeric() {
        return new SimpleDateFormat("MM/dd/yyyy").format(date);
    }

    public String asLongForm() {
        return new SimpleDateFormat("MMMM d, yyyy").format(date);
    }

    public static void main(String[] args) {
        DateClass d = new DateClass(2024, 2, 18);
        System.out.println(d.asNumeric());  // 02/18/2024
        System.out.println(d.asLongForm()); // February 18, 2024
    }
}


Explanation: Use SimpleDateFormat to format Date in different textual forms.

*/