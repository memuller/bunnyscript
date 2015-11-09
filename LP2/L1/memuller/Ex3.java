import java.util.*;
import java.io.*;


public class Ex3 {
    
    public static void main(String[] args){
        MinhaListaOrdenavel lista = new MinhaListaOrdenavel();
        String line = ""; String option = "";
        
        lista.add(new Produto(1,    "pastel carne",         4,      50, 2,  0 ));
        lista.add(new Produto(2,    "pastel queijo",        3.50,   50, 5,  20));
        lista.add(new Produto(3,    "coca-cola",            3,      50, 12, 0));
        lista.add(new Produto(4,    "kibe",                 2.50,   50, 9,  0));
        lista.add(new Produto(5,    "cochinha",             10,     50, 70, 0));
        lista.add(new Produto(6,    "guarana",              4,      50, 2,  0));
        lista.add(new Produto(7,    "empada",               7,      50, 2,  0));
        lista.add(new Produto(8,    "pão",                  4,      50, 2,  0));
        lista.add(new Produto(9,    "chocolate",            1.50,   50, 2,  0));
        lista.add(new Produto(10,   "biscoito",             11,     50, 2,  0));
        
        
        
        do{
            printLine("1. Imprimir lista");
            printLine("2. Sair");
            line = readLine();
            
            if(line.equals("1")){
                printLine("1. Alfabética Nome Asc");
                printLine("2. Alfabética Nome Desc");
                printLine("3. Preço Efetivo Asc");
                printLine("4. Preço Efetivo Desc");
                printLine("5. Número de Vendas Desc");
                option = readLine();
                
                lista.ordena(Integer.parseInt(option));
                for(Produto item : lista.lista){
                    printLine(item);
                }
            }
            
        } while(!line.equals("2"));
    }
    
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
}

class Produto {
    private int codigo;
    private String nome;
    private double preco;
    private int estoque;
    private int vendidos;
    private double promocao;
    
    // pedido para que propriedades sejam privadas, mas precisamos
    // delas no Comparator; então teremos que fazer acessores públicos. 
    public String getNome(){ return this.nome; }
    public int getVendidos(){ return this.vendidos; }
    
    public Produto(int codigo, String nome, double preco, int estoque, int vendidos, double promocao){
        this.codigo = codigo;
        this.nome = nome;
        this.preco = preco;
        this.estoque = estoque;
        this.vendidos = vendidos;
        this.promocao = promocao;
    }
    
    public double precoReal(){
        if(this.promocao > 0){
            return this.preco - (this.promocao*this.preco)/100;
        } else {
            return this.preco;
        }
    }
    
    public String toString(){
        return "Codigo: "+this.codigo+" Nome: "+this.nome+" Preço: "+this.preco+" Estoque: "+this.estoque+" Vendidos: "+this.vendidos+" Promocao: "+this.promocao+" Preco Efetivo: "+this.precoReal();
    }
}

class MinhaListaOrdenavel {
    ArrayList<Produto> lista = new ArrayList();
    public static final int ALFA_ASC    = 1;
    public static final int ALFA_DESC   = 2;
    public static final int PRECO_ASC   = 3;
    public static final int PRECO_DESC  = 4;
    public static final int VENDAS_DESC = 5;
    
    public void add(Produto arg){
        lista.add(arg);
    }
    
    public Produto get(int i){
        return lista.get(i);
    }
    
    public ArrayList ordena(int criterio){
        switch(criterio){
            
            case ALFA_ASC:
                Collections.sort(lista, nomeAsc);
                break;
            case ALFA_DESC:
                Collections.sort(lista, nomeAsc);
                Collections.reverse(lista);
                break;
            case PRECO_ASC:
                Collections.sort(lista, precoAsc);
                break;
            case PRECO_DESC:
                Collections.sort(lista, precoAsc);
                Collections.reverse(lista);
                break;
            case VENDAS_DESC:
                Collections.sort(lista, vendasAsc);
                Collections.reverse(lista);
                break;
        }
        return lista;
    }
    
    
    public Comparator precoAsc = new Comparator(){
        public int compare(Object p1, Object p2){
            return (int) Math.round( 
                ((Produto) p1).precoReal() - ((Produto) p2).precoReal() 
            );
        }
    };
    
    public Comparator nomeAsc = new Comparator(){
        public int compare(Object p1, Object p2){
            return ((Produto) p1).getNome().compareTo(((Produto) p2).getNome());
        }
    };
    
    public Comparator vendasAsc = new Comparator(){
        public int compare(Object p1, Object p2){
            return (int) Math.round( 
                ((Produto) p1).getVendidos() - ((Produto) p2).getVendidos() 
            );
        }
    };
    
}