import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Source27184178 {

    public static void main(String[] args) throws NumberFormatException, IOException {
        //1.
        //System.out.println("Hello World!");

        //2.
        //System.out.println("강한친구 대한육군");
        //System.out.println("강한친구 대한육군");

        //3.
        //System.out.println("\\    /\\");
        //System.out.println(" )  ( ')");
        //System.out.println("(  /  )");
        //System.out.println(" \\(__)|");

        //4.
        //System.out.println("|\\_/|");
        //System.out.println("|q p|   /}");
        //System.out.println("( 0 )\"\"\"\\");
        //System.out.println("|\"^\"`    |");
        //System.out.println("||_/=\\\\__|");

        //5.
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st;

        //test case loof 조회시 사
        //int T = Integer.parseInt(br.readLine());

        //입력된 1줄 조
        st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        System.out.println(N+M);

        br.close();
        bw.close();

    }
}