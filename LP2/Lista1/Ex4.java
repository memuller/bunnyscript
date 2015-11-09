import java.util.*;
import java.io.*;

class Ex4{
    public static void main(String[] args){
        Programa programa = new Programa();
        programa.entradaDados();
        programa.alteraDados();
        programa.saidaDados();
    }
    
}
                                                                    
class NaoPrimoEx extends RuntimeException {}

class Numero{
    public int valor;
    
    public Numero(int valor){
        this.valor = valor;
    }
    
    public int soma(int num){
        return num+valor;
    }
    
    public int sub(int num)
    {
        return num-valor;
    }
    
    public int mult(int num){
        return num*valor;
    }
    
    public int div (int num){
        return num/valor;
    }
    
    public String toString(){
        return String.valueOf(valor);
    }
    
    public void setValor(int val){
        this.valor = val;
    }
    
    public int getValor(){
        return valor;
    }
    
}

class Primo extends Numero {
    
    static boolean isPrime(int arg){
        if(arg == 1) 
            return true; 
        if(arg < 0) 
            arg = arg * -1;
        for(int i = 2; 2*i < arg; i++){
            if(arg % i == 0)
                return false;
        }
        return true;
    }
    
    private boolean isPrimo(){
        return Primo.isPrime(this.valor);
    }
    
    public Primo(int valor){
        super(valor);
        if(!isPrimo())
            throw new NaoPrimoEx();
    }
    
    public int soma(int num){
        int result = super.soma(num);
        if(!Primo.isPrime(result))
            throw new NaoPrimoEx();
        return result;
    }
    
    public int sub(int num){
        int result = super.sub(num);
        if(!Primo.isPrime(result))
            throw new NaoPrimoEx();
        return result;
    }
    
    public int div(int num){
        int result = super.div(num);
        if(!Primo.isPrime(result))
            throw new NaoPrimoEx();
        return result;
    }
    
    public int mult(int num){
        int result = super.mult(num);
        if(!Primo.isPrime(result))
            throw new NaoPrimoEx();
        return result;
    }
    
    public String toString(){ 
        return String.valueOf(valor); 
        
    }
}

class Programa {
    public List items = new ArrayList();
    
    public static void printLine(Object arg){
        System.out.println(arg);
    }
    
    public static String readLine(){
        BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
        String line = "";
        try {
            line = stdin.readLine();
        } catch(IOException e){
            e.printStackTrace();
            System.exit(1);
        }
        return line;
    }
    
    public Programa(){}
    
    public Programa(List arg){
        items = arg;
    }
    
    public void entradaDados(){
        String line = ""; boolean isPrime; int value; 
        do {
            printLine("Primo ou normal? (P/N ou Enter para sair)");
            line = readLine();
            if(line.equals(""))
                break;
            
            isPrime = line.equals("P");
            printLine("Digite o número:");
            line = readLine();
            if(line.equals(""))
                break;
            value = Integer.parseInt(line);
            if(isPrime){
                 items.add(new Primo(value));   
            } else {
                items.add(new Numero(value));
            }
        } while(true);
    }
    
    public void alteraDados(){
        String line = ""; String operation = ""; 
        int i1; int i2; 
        Numero t1; Numero t2;
        int result;
        do {
            printLine("Escolha a operação:");
            printLine("1. Soma");
            printLine("2. Subtração");
            printLine("3. Multiplicação");
            printLine("4. Divisão");
            printLine("5. Sair");
            operation = readLine();
            if(operation.equals("") || operation.equals("5"))
                break;
            
            printLine("Escolha o primeiro termo: (0-"+(items.size()-1)+")");
            i1 = Integer.parseInt(readLine());
            
            printLine("Escolha o segundo termo: (0-"+(items.size()-1)+")");
            i2 = Integer.parseInt(readLine());
            
            t1 = (Numero) items.get(i1);
            t2 = (Numero) items.get(i2);
            
            switch(operation){
                case "2":
                    result = t1.sub(t2.getValor());
                    break;
                case "3":
                    result = t1.mult(t2.getValor());
                    break;
                case "4":
                    result = t1.div(t2.getValor());
                    break;
                default:
                    result = t1.soma(t2.getValor());
                    break;
            }
            
            if(Primo.isPrime(result)){
                items.set(i1, new Primo(result));
            } else {
                items.set(i1, new Numero(result));
            }
            
            
        } while(true);
    }
    
    public void saidaDados(){
        printLine("Resultados:");
        for(Object item : items){
            printLine( ((Numero) item ) );
        }
    }
}