public class BJ4690 {
    public static void main(String[] args) {
        int a=0;
        StringBuilder sb = new StringBuilder();

        while(a<=100){
            double a3 = Math.pow(a,3);
            for (int i = 2; i<a;i++){
                for(int j=i; j<=a;j++){
                    for (int k=j; k<=a;k++){
                        double b3 = Math.pow(i,3);
                        double c3 = Math.pow(j,3);
                        double d3 = Math.pow(k,3);
                        if (a3 < b3+c3+d3) break;
                        else if(a3 == b3+c3+d3)
                            sb.append("Cube = "+ a+","+" Triple = ("+i+","+j+","+k+")"+"\n");
                    }
                }
            }
            a += 1;
        }
        System.out.println(sb);
    }
}
