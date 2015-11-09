/* 1) Modele um funcionário. Ele deve ter o nome do funcionário, o departamento onde trabalha, seu salário
(double), a data de entrada no banco (String) e seu RG (String).
Você deve criar alguns métodos de acordo com sua necessidade. Além deles, crie um método
recebeAumento que aumenta o salario do funcionário de acordo com o parâmetro passado como argumento.
Crie também um método calculaGanhoAnual, que não recebe parâmetro algum, devolvendo
o valor do salário multiplicado por 12..
A ideia aqui é apenas modelar, isto é, só identifique que informações são importantes e o que um funcionário
faz. Desenhe no papel tudo o que um Funcionario tem e tudo que ele faz. 

Transforme o modelo acima em uma classe Java. Teste-a, usando uma outra classe que tenha o main. Você
deve criar a classe do funcionário com o nome Funcionario, mas pode nomear como quiser a classe de
testes, contudo, ela deve possuir o método main.*/




class Pg60{
    public static void main(String[] args){
        Funcionario Saber = new Funcionario();
        
        Saber.nome = "Seibaa";
        Saber.depart = "Seihai Senso";
        Saber.sal = 1337;
        Saber.dataEntr = "28/10/2015";
        Saber.rg = "12.345.6789";
        
        Saber.mostra();
        
        //posso usar os atributos/métodos de classe normalmente fora da classe,
        // usando o nome da classe. 
        // Funcionario.qtdTotalAumentos Funcionario.umMetodoQualquer(); etc
    }
}

class Funcionario{
    public String nome;
    public String depart;
    public double sal;
    public String dataEntr;
    public String rg;
    
    public double recebeAumento(double aumento){
        return sal+aumento;
    }
    
    public double calculaGanhoAnual(){
        return sal*12;    
    }
    
    public void mostra(){
        System.out.println("Nome: " + this.nome);
        System.out.println("Departamento: " + this.depart);
        System.out.println("Salário: " + this.sal);
        System.out.println("Data de entrada na empresa: " + this.dataEntr);
        System.out.println("RG: " + this.rg);
    }
}