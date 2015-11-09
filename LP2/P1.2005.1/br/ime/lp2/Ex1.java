package br.ime.lp2;
import java.util.Vector;

public class Ex1{
    public static int[] invertArray(int[] a){
        int k = a.length;
        int i = 0;
        int[] b = new int[k];
        
        for (i=0; i<k; i++){
            b[i]=a[k];
            k--;
        }
        
        return b;
    }
    
    public static int[] invertArray(Vector<Integer> b){
        int k = b.size();
        int i=0;
        int[] c = new int[k];
        
        for(i=0; i<k; i++){
            c[i]=b.elementAt(k);
            k--;
        }
        
        return c;
    }
}