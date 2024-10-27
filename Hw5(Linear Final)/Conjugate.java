import java.util.Scanner;

public class Conjugate {

    
    public static void residual(int n, double a[][], double x[], double b[], double r[]) {
        for (int i = 0; i < n; i++) {
            r[i] = -1*b[i]; 
            for (int j = 0; j < n; j++) {
                r[i] += a[i][j] * x[j]; 
            }
        }
    }

    public static void findD(int n, double r[], double alpha, double d[]) {
        for (int i = 0; i < n; i++) {
            d[i] = -r[i] + alpha * d[i];
        }
    }

    public static double findLambda(int n, double r[], double d[], double a[][]) {
        double num = 0;
        for (int i = 0; i < n; i++) {
            num += d[i] * r[i]; 
        }

        double[] temp = new double[n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                temp[i] += d[j] * a[i][j]; 
            }
        }

        double value = 0;
        for (int i = 0; i < n; i++) {
            value += d[i] * temp[i]; 
        }

        return -num / value;
    }

  
    public static void findX(int n, double x[], double lambda, double d[]) {
        for (int i = 0; i < n; i++) {
            x[i] = x[i] + lambda * d[i];
        }
    }

    public static double findAlpha(int n, double r[], double d[], double a[][]) {
        double alpha = 0;
        double[] tempR = new double[n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                tempR[i] += r[j] * a[i][j]; 
            }
            alpha += tempR[i] * r[i];
        }

        double value = 0;
        double[] tempD = new double[n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                tempD[i] += d[j] * a[i][j]; 
            }
            value += tempD[i] * d[i]; 
        }

        return alpha / value;
    }

    public static double findError(double r[], int n) {
        double error = 0;
        for (int i = 0; i < n; i++) {
            error += r[i] * r[i]; 
        }
        return error;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Matrix size: ");
        int n = sc.nextInt();
        double[][] a = new double[n][n];
        double[] b = new double[n];
        double[] x = new double[n];
        double[] r = new double[n];
        double[] d = new double[n];
        double alpha = 0;
        double lambda = 0;
        double error = 1;

  
        System.out.println("Enter matrix A:");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                a[i][j] = sc.nextDouble();
            }
        }

        System.out.println("Enter vector b:");
        for (int i = 0; i < n; i++) {
            b[i] = sc.nextDouble();
        }

        System.out.println("Enter initial guess for x:");
        for (int i = 0; i < n; i++) {
            x[i] = sc.nextDouble();
        }
        int i = 1;
        do{
            residual(n, a, x, b, r);
            findD(n, r, alpha, d);
            lambda = findLambda(n, r, d, a);
            
            findX(n, x, lambda, d);
            if(i> 1){
                error = findError(r, n);
                alpha = findAlpha(n, r, d, a);
            }
        
            i++;
            

        }while(error >= 0.000001);
        System.out.println("count : "+i);
        for (int j = 0; j < n; j++) {
            System.out.println("x["+j+"] : "+x[j]);
        }
    
    }
}
