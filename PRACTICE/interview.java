import java.util.ArrayList;
import java.util.List;

public class interview {

    /** Returns every unsigned integer that appears in `s`, in left‑to‑right order. */
    public static int[] findNumbers(String s) {
        List<Integer> list = new ArrayList<>();
        int i = 0, n = s.length();

        while (i < n) {
            // skip anything that is NOT a digit
            if (!Character.isDigit(s.charAt(i))) {
                i++;
                continue;
            }

            // collect the full run of consecutive digits
            int start = i;
            while (i < n && Character.isDigit(s.charAt(i))) i++;
            String digits = s.substring(start, i);

            list.add(Integer.parseInt(digits));  // store the number
        }

        // copy into a primitive int[]
        int[] arr = new int[list.size()];
        for (int k = 0; k < list.size(); k++)
            arr[k] = list.get(k);
        return arr;
    }

    // ---------- quick demo ----------
    public static void main(String[] args) {
        String text = "[1[2[3[4[5]]]]]";
        int[] nums = findNumbers(text);

        // pretty‑print result
        System.out.print("arr = [");
        for (int k = 0; k < nums.length; k++) {
            System.out.print(nums[k]);
            if (k + 1 < nums.length) System.out.print(", ");
        }
        System.out.println("]");
    }
}
