import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Vector;


public class Ex5 {
    public static void main(String[] args){
        int number_people = 0;
        String gender_people = "";
        Vector people = new Vector(); Vector person;
        
        String line;
        
        
        printLine("== Quantas pessoas?");
        do {
            line = readLine();
            if(isNumeric(line)){
                number_people = Integer.parseInt(line);
            } else {
                printLine("Inteiro maior que zero, por favor.");
            }
        } while(number_people == 0);

        printLine("== Qual gênero? (M/F)");
        do {
            line = readLine();
            if(isAmong(line, new String[]{"M", "F"})){
                gender_people = line;
            } else {
                printLine("Gênero binário na forma de uma única letra (M/F) por favor.");
            }
        } while(gender_people.equals(""));
        
        for (int i = 0; i < number_people; i++ ){
            printLine("==Dados da pessoa "+(i+1));
            person = readPerson();
            if(gender_people == "M"){
                people.add(
                  new Homem(
                      (String) person.elementAt(0), 
                      (String) person.elementAt(1), 
                      (Double) person.elementAt(2), 
                      (Double) person.elementAt(3))  
                );
            } else {
                people.add(
                  new Mulher(
                      (String) person.elementAt(0), 
                      (String) person.elementAt(1), 
                      (Double) person.elementAt(2), 
                      (Double) person.elementAt(3))  
                );
            }
        }
        
        printLine("==== IMCS ====");
        for(int i = 0; i < number_people; i++){
            printLine((PessoaIMC) people.elementAt(i));
            printLine("----------------------");
        }
            

    }
    
    
    public static void printLine(Object arg){
        System.out.println(arg);
    }
    
    public static Vector readPerson(){
        Vector person_info = new Vector();
        String line;
        String nome = ""; String data_nasc = "";
        double altura = 0; double peso = 0;
        
        printLine("=Nome da pessoa:");
        nome = readLine();
        printLine("=Data de nascimento:");
        data_nasc = readLine();
        
        printLine("=Altura:");
        do {
            line = readLine();
            if(isNumeric(line)){
                altura = Double.parseDouble(line);
            } else {
                printLine("Altura numérica em metros, por favor.");
            }
        } while(altura == 0);
        
        printLine("=Peso:");
        do {
            line = readLine();
            if(isNumeric(line)){
                peso = Double.parseDouble(line);
            } else {
                printLine("Peso numérico em kg, por favor.");
            }
        } while(peso == 0);
        
        person_info.add(nome);
        person_info.add(data_nasc);
        person_info.add(altura);
        person_info.add(peso);
        
        return person_info;
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
    
    public static boolean isAmong(String arg, String[] valid_args){
        boolean valid = false;
        for (String item : valid_args){
            printLine(item);
            if(item.equals(arg)){
                valid = true;
                break;
            }
        }
        return valid;
    }
    
    public static boolean isNumeric(String arg){
        boolean valid = true;
        try{
            Double.parseDouble(arg);
        } catch(NumberFormatException e){
            valid = false;
        }
        return valid;
    }
}

class Pessoa {
    protected String nome;
    protected String dataNascimento;
    
    public Pessoa(String nome, String data){
        this.nome = nome;
        this.dataNascimento = data;
    }
    
    public String toString(){
        return "Nome: "+this.nome+"\nData de Nascimento: "+this.dataNascimento;
    }
}

abstract class PessoaIMC extends Pessoa {
    protected double peso;
    protected double altura;
    
    public PessoaIMC(String nome, String data, double peso, double altura){
        super(nome, data);
        this.peso = peso;
        this.altura = altura;
    }
    
    public double getPeso(){
        return this.peso;
    }
    public double getAltura(){
        return this.altura;
    }
    
    public static double calculaIMC(double peso, double altura){
        return peso/(altura*altura) ;
    }
    
    abstract String resultIMC();
    
    public String toString(){
        String texto;
        texto = super.toString();
        texto += "\nPeso: "+this.peso+"\nAltura: "+this.altura;
        return texto;
    }
}

class Homem extends PessoaIMC {
    static double limiteInferior = 20.7;
    static double limiteSuperior = 26.4;
    
    public String resultIMC(){
        double imc = calculaIMC(this.peso, this.altura);
        String texto = "\nIMC: "+imc+" ";
        if(imc < limiteInferior){
            texto += "(abaixo do peso ideal)";
        } else if(limiteInferior < imc && imc < limiteSuperior){
            texto += "(dentro do peso ideal)";
        } else {
            texto += "(acima do peso ideal)";
        }
        
        return texto;
    }
    
    public Homem(String nome, String data, double peso, double altura){
        super(nome, data, peso, altura);
    }
    
    public String toString(){
        String texto;
        texto = super.toString();
        texto += this.resultIMC();
        
        return texto;
    }
}

class Mulher extends PessoaIMC {
    static double limiteInferior = 19;
    static double limiteSuperior = 25.8;
    
    public String resultIMC(){
        double imc = calculaIMC(this.peso, this.altura);
        String texto = "\nIMC: "+imc+" ";
        if(imc < limiteInferior){
            texto += "(abaixo do peso ideal)";
        } else if(limiteInferior < imc && imc < limiteSuperior){
            texto += "(dentro do peso ideal)";
        } else {
            texto += "(acima do peso ideal)";
        }
        
        return texto;
    }
    
    public Mulher(String nome, String data, double peso, double altura){
        super(nome, data, peso, altura);
    }
    
    public String toString(){
        String texto;
        texto = super.toString();
        texto += this.resultIMC();
        
        return texto;
    }
}