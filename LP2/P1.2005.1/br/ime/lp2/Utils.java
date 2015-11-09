package br.ime.lp2;
import java.util.Vector;
public class Utils {
    public static int [] invertArray(int [] arg){
        int len = arg.length; //o tamanho do array. vamos usar bastante
        int[] inverted = new int[len]; //um array que será o passado como argumento, só que invertido
        for (int i = 0; i < len; i++ ){ //para cada elemento do array argumento...
            inverted[i] = arg[len-1-i]; //colocamos no array invertido o elemento contador-
        }//good. dúvidas sobre a sintaxe do vetor?
        return inverted; // sim. wtf "<Integer>" sendo usado. tem que escrever assim pra ser um vector de ints?
    }// sim...ou algo pior que isso. o ponto do vector é que ele pode armazenar coisas de tipos diferentes,
    // diferente do array que armazena só as coisas de um tipo só.
    // mas o java faz isso colocando cada elemento do vector dentro de um objeto. o que quebra o meu
    // for ali embaixo - dá que eu preciso de um inteiro mas passei um object.
    // então caso vá usar o Vector somente para armazenar coisas de um tipo, precisa colocar
    // Vector<classedotipo> na declaração, ou vai ter problemas depois.
    // ou é isso, ou precisa sempre ficar convertendo o tipo das coisas quando ler do vetor
    // o que é francamente bem mais chato.
    // mas duvido que o professor vá pegar este erro sem o copilador tho
    
    public static int[] invertArray(Vector<Integer> arg){
        int[] array = new int[arg.size()];
        int i = 0;
        for(int item : arg){
            array[i] = item;
            i++;
        }
        
        return invertArray(array);
    }
}