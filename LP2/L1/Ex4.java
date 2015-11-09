/*
a) criar uma classe de exceção é criar uma que herde de Exception.

b) um campo para armazenar o número. okay.
lembra de construtor, right? veja nos anteriores.
getters e setters são métodos cuja função é acessar e alterar o valor de um atributo do objeto. por exemplo, este método é um setter da propriedade num:
public void setNum(Integer arg){
    this.num = arg;
}
enquanto o getter retornaria esta propriedade.

getters e setters são úteis quando você sempre quer fazer algum trabalho adicional quando acessa ou altera um atributo. por exemplo, você nunca pode alterar o status de um Book (status informa se o livro está emprestado ou disponível) sem também informar quem emprestou/devolveu e a data. então usa um método para isso, tendo estas coisas como parâmetro, ao invés de simplesmente dizer que livro.status = "emprestado"; ou coisa assim.

os métodos das operações aritméticas parecem okay.

método toString é um método com este nome que retorna uma string.
este método é usado pelo java quando ele precisa converter um objeto da classe para uma string - por exemplo quando ele é parâmetro de um print. 

 c) well, a classe Primo herdará da classe Numero, então.
 e terá alguns comportamentos diferentes nos seus métodos.

d) ele quer que você crie o algortimo principal do programa em outra classe, que não seja Numero, Primo ou a classe principal do programa. crie outra, então.

ela vai ter dois construtores, um que recebe parâmetro e outro que não. lembra como métodos podem ter o mesmo nome? mesma coisa com construtores. então pode criar dois construtores.

coisa chata aí no loop e menu, mas parece okay. vá devagar - faça a coisa funcionar com o cara escolhendo uma coisa no menu somente, daí coloque dentro do loop para ele escolher N coisas até optar por sair.



*/  


class Ex4{
    public static void main(String[] args){ 
        
    }
    
}
                                                                    
class NaoPrimoEx extends Exception {
    
}

class Primo{
    public int valor;
    
    public Primo(int valor){
        this.valor = valor;
    }
    
    // int soma(int num){
    //     return num+valor;
    // }
    
    // int sub(int num)
    // {
    //     return num-valor;
    // }
    
    // int mult(int num){
    //     return num*valor;
    // }
    
    // int div (int num){
    //     return num/valor;
    // }
    
    String toString(){
        return String.parseString(valor);
    }
    
    public void setValor(int val){
        this.valor = val;
    }
    
    public int getValor(){
        return valor;
    }
    
}


