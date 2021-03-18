//import java.io.InputStreamReader;
//import java.io.BufferedReader;
//import java.io.IOException;
//import java.util.StringTokenizer;
//
//public class Main{
//
//    public static void main(String[] args) throws IOException{
//
//        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//
//        StringTokenizer st = new StringTokenizer(br.readLine());
//
//        double a = Double.parseDouble(st.nextToken());
//        double b = Double.parseDouble(st.nextToken());
//
//        System.out.println(a/b);
//
//        br.close();
//
//    }
//
//}

import java.util.Scanner;

public class Main{

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();

        System.out.println( ( a+b )%c );
        System.out.println( ( (a%c)+(b%c) )%c );
        System.out.println( ( a*b )%c );
        System.out.println( ( (a%c)*(b%c) )%c );

        sc.close();


    }

}