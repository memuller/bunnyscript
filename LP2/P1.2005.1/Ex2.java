import br.ime.lp2.*;
import java.util.Vector;

public class Ex2 {
    public static void main(String[] args){
        Vector vect = new Vector(5); //cria o vetor, com cinco posições
        for(int i = 0; i < 5; i++){ //adiciona cinco elementos (0..4)
            vect.add(i);
        }
        
        int[] arrayInvertido = Utils.invertArray(vect); //usa o método invertArray
        // da classe criada no exercício 1. que retorna um array de inteiros
        
        for(int item : arrayInvertido){ // imprime cada item em uma linha
            System.out.println(item); // deve imprimir 4 3 2 1 0 , cada um em uma linha
        }
    }
}