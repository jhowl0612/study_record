import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;

public class TestDrill{

    public static void main(String[] args) throws IOException {

        String s = "\\    /\\\n"
                + " )  ( ')\n"
                + "(  /  )\n"
                + " \\(__)|";

        System.out.println(s);

        String s2 = "|\\_/|\n" +
                "|q p|   /}\n" +
                "( 0 )\"\"\"\\\n" +
                "|\"^\"`    |\n" +
                "||_/=\\\\__|";

        System.out.println(s2);

//        Scanner sc = new Scanner(System.in);
//        int a = sc.nextInt();
//        int b = sc.nextInt();
//
//        System.out.println(a+b);

//        //5.
//        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
//
//        StringTokenizer st;
//
//        //test case loof 조회시 사
//        //int T = Integer.parseInt(br.readLine());
//
//        //입력된 1줄 조
//        st = new StringTokenizer(br.readLine());
//
//        int N = Integer.parseInt(st.nextToken());
//        int M = Integer.parseInt(st.nextToken());
//
//        System.out.println(N+M);
//
//        br.close();
//        bw.close();

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());

        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());

        System.out.println(a+b);

        br.close();

    }

}