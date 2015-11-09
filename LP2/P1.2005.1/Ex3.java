import java.io.FileOutputStream;
class PInteger extends Integer { //uma classe-filha de integer. isso que o "especializar" dele significa,
// pelo que entendi.
    public void salva(String filename){
        FileOutputStream out = new FileOutputStream(filename); //criando um stream de saída...
        filename.write(super.intValue()); //escrevendo nele o valor do inteiro.
        // objetos da classe Integer tem este método intValue() que retorna o valor deles próprios.
        // e super, em uma classe-filha, representa a classe pai (superclass).
        // eu poderia chamar intValue() somente ao invés de super.intValue(), pois quando
        // o método não é encotnrado na classe filha ele vai usar o do pai anyway
        // mas ele pediu especificamente para usar o valor inteiro DO PAI. então okay, por via das dúvidas
        filename.close(); //fecha o stream
    }
}