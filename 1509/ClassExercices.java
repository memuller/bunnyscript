/*
    - as atividades são incrementais. altere as classes/main conforme progride
    - vá devagar
    - teste com mais frequência. don't trust yourself
    - escreva o código que vai usar para testar na main antes, daí vá para a classe
      e programe para fazer o que escreveu na main funcionar
      
    
    (1) 
    crie uma classe Album representando um álbum musical, com os seguintes atributos:
        título, artista, ano, número de faixas, número de discos, gênero, comentários
    a classe deve possuir um método construtor que permita já definir título e artista 
    no ato da instanciação do objeto.
    
    (2)
    crie um método de instância 'tagline' que imprima a 'tagline' do Álbum em questão,
    composta de seu título, artista e ano no seguinte formato:
        artista - titulo (ano)
    
    (3)
    crie um método de classe 'build' que, recebendo uma string como parâmetro, 
    retorne uma instância do objeto álbum preenchida com os atributos contidos nesta string,
    estando estes atributos na ordem descrita no (1), separados por vírgula.
    
    eg. 
        Album.build("Ceremonials, Florence + The Machine, 2011, 20, 2, Indie, hmmmkay");
    ...deve retornar um Album com os atributos descritos nesta string.
    
    (4)
    crie um método de classe 'loadFromFile' que, recebendo um nome de álbum como parâmetro, retorna um
    objeto Album com os atributos carregados de um arquivo .csv com o título passado.
    
    por exemplo,
        Albums.load("Ceremonials")
    ...deve retornar um Album cujos atributos estão contidos no arquivo Ceremonials.csv
    
    use a classe BufferedReader; especificamente o método readLine()
    http://www.tutorialspoint.com/java/io/bufferedreader_readline.htm
    
    use o método build() anteriormente criado.
*/

public class ClassExercices {
    public static void main(String[] args){ //tests exercice 2
        Album ceremonials = new Album("Ceremonials", "Florence + The Machine");
        ceremonials.Tagline();
        // deve imprimir "Florence + The Machine - Ceremonials (2011)"
    }

    // prints shit
    public static void print(Object... args){
        for(Object stuff: args){
            System.out.println(stuff);
        }
    }
}

class Album {
    public String titulo, artista, genero, comment;
    public int ano=2015, numf, numdisc;
    
    public Album(String titulo, String artista) {
        this.titulo = titulo;
        this.artista = artista;
    }
    
    public void Tagline()
    {
        System.out.print(Album.artista);
        System.out.print(" - ");
        System.out.print(Album.titulo);
        System.out.print(" (");
        System.out.print(Album.ano);
        System.out.print(")");
    }
}