import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.util.StringTokenizer;
import java.io.IOException;

public class Main{

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer sc = new StringTokenizer(br.readLine());

        int a = Integer.parseInt(sc.nextToken());
        int b = Integer.parseInt(sc.nextToken());

        System.out.println(a*b);

    }

}