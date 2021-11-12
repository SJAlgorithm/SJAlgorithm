import java.util.*;

public class Main {
    static Vector<Person> v=new Vector<>();
    static int n;

    static class Person implements Comparable<Person>{
        int weight;
        int height;

        public Person(int weight, int height) {
            this.weight = weight;
            this.height = height;
        }


        @Override
        public int compareTo(Person o) {
            if(this.weight<o.weight&&this.height<o.height){
                return 1;
            }
            else{
                return 0;
            }
        }
    }

    public static void main(String[] args){
        Scanner scanner=new Scanner(System.in);
        n=scanner.nextInt();

        for(int i=0;i<n;i++){
            int w=scanner.nextInt();
            int h=scanner.nextInt();

            v.add(new Person(w,h));
        }
        for(int i=0;i<n;i++){
            int rank=1;
            for(int j=0;j<n;j++){
                if(i==j) continue;
                if(v.get(i).compareTo(v.get(j))==1) rank++;
            }
            System.out.print(rank+" ");
        }
    }

}
