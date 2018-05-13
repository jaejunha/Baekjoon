import java.math.BigDecimal;
import java.util.Scanner;

public class Main {

	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		BigDecimal a = new BigDecimal(sc.next());
		int b = sc.nextInt();
		System.out.println(a.pow(b).toPlainString());
	}
}