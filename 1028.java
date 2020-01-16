import java.util.*;


class Stu{
    String id;
    String name;
    int grade;
}

class Main{
    public static void main(String []args){
        int n,c;
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        c = sc.nextInt();
        ArrayList<Stu> arr = new ArrayList<Stu>();
        for(int i = 0; i < n; i++){
            Stu s = new Stu();
            s.id = sc.next();
            s.name = sc.next();
            s.grade = sc.nextInt();
            arr.add(s);            
        }
        sc.close();
        if(c == 1)
            Collections.sort(arr, new Comparator<Stu>(){
                public int compare(Stu a, Stu b){
                    return a.id.compareTo(b.id);
                }
            });
        if(c == 2)
            Collections.sort(arr, new Comparator<Stu>(){
                public int compare(Stu a, Stu b){
                    int f = a.name.compareTo(b.name);
                    if(f == 0){
                        return a.id.compareTo(b.id);
                    }
                    else{
                        return f;
                    }
                }
            });

        if( c== 3){
            Collections.sort(arr, new Comparator<Stu>(){
                public int compare(Stu a, Stu b){
                    if(a.grade == b.grade){
                        return a.id.compareTo(b.id);
                    }
                    else{
                        return a.grade < b.grade ? 1 : -1;
                    }
                }
            });
        }

        for(int i = 0; i < n; i++){
            Stu a = arr.get(i);
            System.out.println(a.id + " " + a.name + " " + a.grade);
        }

    }



}