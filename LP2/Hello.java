public class Hello {
    public static void main(String[] args){
        
        Knight roan = new Knight("roan", "rok", 2);
        Knight arthuria = new Knight("arthuria", "honor", 20);
        Knight ofNi = new Knight("ofNi", "Ni!", 4);
        
        //System.out.println (roan.nome + " " + arthuria.nome + " " + ofNi.nome);
        roan.says("alguma coisa arbitrária");
        
        Person agnes = new Person("agnes", "so melhora");
        
        System.out.println("o lvl do roan é " + roan.level);
        agnes.says("precisa de ar condicionado e água quente");
    }
}

class Person {
    String nome;
    String catchphrase = "honor";
    
    public void says(String arg)
    {
        System.out.println(arg);
    }
    
    public Person(String nome, String catchphrase){
        this.nome = nome;
        if (catchphrase != ""){
            this.catchphrase = catchphrase;
        }
    }

}

class Knight extends Person implements Human {
    String arma = "sword";
    String escudo = "shield";
    int level = 1;
    
    public void catchy(){
        System.out.println(catchphrase);
    }
    
    public void says(String arg)
    {
        super.says(arg+"!");
    }    
    
    public Knight(String nome, String catchphrase, int level){
        super(nome, catchphrase);
        this.level = level;
    }
    
}

// o que é um objeto?
// classe dele
// classes mãe dele
// classes mãe das classes mãe
// interfaces destas classes


// no ato de criação de um Knight, você deve especificar o nível dele.




// crie um método says para a classe pessoa que se comporte como o método says da Knight atualmente.
// porém, se o método says() de Knight for usado, ele deve dizer coisas sempre terminando em "!".



// Polimorfismo
/*
    toda vez que um objeto ser "mais de uma coisa", ele está exibindo polimorfismo.

*/


// faça com que seja possível especificar o nome do Knight no ato da sua criação através de um método construtor.


// faça com que todo objeto Knight tenha uma propriedade 'catchphrase' (uma String).
// terão também um método catchy() que dirá esta catchphrase.

// faça com que no ato da criação de um objeto Knight você possa especificar também a sua propriedade catchphrase.


// faça com que se for passada no ato da criação uma catchphrase vazia, 
// ela seja setada como "HONOR".

// crie os atributos arma, lvl(inteiro) e escudo de um knight. todos estes devem ter valores padrão.

// crie uma classe chamada Person com os atributos genéricos de uma pessoa que atualmente fazem parte da classe Knight.
// (os atributos que pareçam específicos de um Knight)



// if(something == true){
//     //do stuff
// } else if(something == 'dshadksad'){
//     // do other stuff
// } else {
    
// }

// while(false){
//     //bloco de código
// }

// String items[10];

// for(String item : items){
    
// }


