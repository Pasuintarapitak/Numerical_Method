import java.util.Scanner;


public class newton_interpotion {
    static double[] x;
    static double[] fx;
    public static double f(int x1 ,int x0 , int i){
        if( i == 0){
            return fx[x0];
        }
        else if(i == 1){
            return (fx[x1] - fx[x0]) / (x[x1] - x[x0]); 
        }
        return ( f(x1, x0+1, i-1) - f(x1-1, x0, i-1) ) / (x[x1] - x[x0]);
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        x = new double[n];
        fx= new double[n];
        for (int i = 0; i < n; i++) {
            System.out.print("x["+i+"] : ");
            x[i] = sc.nextDouble();
  
        } 
        for (int i = 0; i < n; i++) {
            System.out.print("fx["+i+"] : ");
            fx[i] = sc.nextDouble();
        } 
        int stdID = 40462;
        double temp = 1;
        double total = 0;
        for (int i = 0; i < n; i++) {
            temp = 1;
            for (int j = 0; j < i; j++) {
                temp = temp*(stdID - x[j]);
            }
            total += f(i, 0, i) * temp;
        }
        System.out.println(total);

    }
}