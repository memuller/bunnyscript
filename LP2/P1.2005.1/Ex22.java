import br.ime.lp2.*;
import java.util.Vector;

class Ex22{
    public static void main(String[] args){
        Vector vetor = new Vector(5);
        int[] vet = new int[5];
        int i =0;
        
        vetor.addElement(1);
        vetor.addElement(2);
        vetor.addElement(3);
        vetor.addElement(4);
        vetor.addElement(5);
    
        vet = Ex1.invertArray(vetor);
        
        for (i=0; i<5; i++){
            System.out.print(vet[i] + " ");    
        }
        
    }
}