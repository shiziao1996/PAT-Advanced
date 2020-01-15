import java.util.*;
import java.math.*;
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        BigInteger n1 = sc.nextBigInteger();
        BigInteger n2 = n1.multiply(new BigInteger("2"));
        String s1 = n1.toString();
        String s2 = n2.toString();
        Map<Character, Integer> m = new HashMap<>();
        for(int i = 0; i < s1.length(); i++){
          char c = s1.charAt(i);
          if(m.containsKey(c)) m.put(c, m.get(c) + 1);
          else m.put(c, 1);
        }
        for(int i = 0; i < s2.length(); i++){
          char c = s2.charAt(i);
          if(m.containsKey(c)) m.put(c, m.get(c) - 1);
          else m.put(c, -1);
        }
        boolean f = true;
        for(char c : m.keySet()){
          if(m.get(c) != 0){
            f = false; 
            break;
          }
        }
        if(f == true){
          System.out.println("Yes");
        }
        else{
          System.out.println("No");
        }
        System.out.println(s2);
    }
}