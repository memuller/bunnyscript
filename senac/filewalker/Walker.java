/*== Descrição
[...] quando ocorreu a restauração a data de criação ou
modificação das pastas e arquivos ficou definida como 08/12/2013 ou 09/12/2013.

Peço que realizem o levantamento de estruturas de
pastas/arquivos  na pasta H:\NPME\Projetos que estão sem modificação desde
estas datas citadas acima, caracterizando-as como projetos em que não ocorreram
modificações por mais de um ano e meio. 

Sugiro criar uma tabela contendo: endereço raiz da pasta,
data modificação, tamanho 
/*

/* podemos tentar visualizar deste jeito acho:
para cada pasta de projeto
    percorrer todos os arquivos e arquivos dentro de subpastas
        captar a data de alteração destes
    se a data de alteração do arquivo ou pasta mais recente for anterior a 12/2013
    imprimir o nome/caminho do projeto e a data
*/

/*
docs.oracle.com/javase/7/docs/api/java/io/File.html
*/


/*== Exercícios */

class Walker {
    
    // you may want to use this instead of System.out.shit
    // just print(stuff)
    public static void print(Object... args){
        for(Object stuff: args){
            System.out.println(stuff);
        }
    }
    
    public static void main(String[] args){
        
        //testa exercício 1
        // String path = "/home/ubuntu/worspace/";
        // StringOuFile arquivos[] = nomedometodo();
        // for (StringOuFile arquivo : arquivos ){
        //     print(arquivo);
        // } 
    }
    
    public ItensPasta(String caminho){
        return File[String caminho].listFiles();
    }


/* (1) escreva um método que, dado um caminho de pasta como string, retorne um array 
com os items presentes nesta pasta.
*/
// (key method here is File.listFiles()) or File.list()


/* (2) escreva uma função que, dada uma pasta (como File), retorne um array
com todos os itens presentes nesta pasta, inclusive dentro de subpastas deste.
este método deve ser recursivo.
*/
// (File.isDirectory())

/* (3) escreva um método que, dada uma data em formato dd/mm/yyyy como parâmetro,
retorne esta data convertidade para formato Unix (segundos desde a Época) 
*/


/* (4) escreva uma função que, dado um arquivo e uma data no formato dd/mm/yyyy
passados como parâmetro, retorne verdadeiro caso o arquivo seja mais velho
que a data passada; e falso do contrário.
*/


/* (5) escreva uma função que, dado um caminho de pasta como string, retorne o
arquivo mais recente presente dentro desta pasta e subspastas.
*/

}