// este programa é um exemplo; ele não deve ser compilado.
public class Book {

	public String title;
	public String author;

	public int totalPages;
	public int currentPage;

	public Book(String title, String author, int pages){
		this.title = title;
		this.author = author;
		this.totalPages = pages;
		this.currentPage = 1;
	}

	public void goToPage(int page){
		this.currentPage = page;
	}
	
	public void nextPage(){
		this.goToPage(this.current_page+1);
	}
}

/*	uma classe representando livros, com métodos e propriedades
	bem intuitivas sobre como um livro se comporta - páginas totais,
	página atual, um método para ir até uma página específica, outro para
	ir para a página seguinte. etc

	estes métodos e propriedades são de *instância*, pois eles são comportamentos
	do objeto livro; de cada livro que irá existir tendo esta classe como modelo.
	ou seja, eles são coisas disponíveis após criar um objeto desta classe - instanciar.

	por exemplo:
*/
	mybook = new Book("Dark Places", "Gillian", 350);
	// como eu criei um método com o mesmo nome da classe ali, ele é usado automaticamente
	// quando eu crio um objeto usando new. isso me permite já colocar alguns atributos
	// no objeto.
	
	System.out.println(mybook.title); // como esperado, isso vai imprimir o título deste Book.
	mybook.nextPage(); // isso vai evocar o método nextPage deste objeto Book.
	System.out.println(mybook.currentPage); // ...que fará o livro ir para a página seguinte,
	// que agora deve ser a segunda.

	another_book = new Book("The Jewelry God: The Jewelry Team", "JR Tolkien", 9999);
	// isso cria um outro objeto livro. fazê-lo sempre pode ser descrito como 'instanciar' um objeto da classe.

	System.out.println(another_book.currentPage);
	// como esperado, este livro ainda está na página 1.
	// todas as propriedades e métodos de cada objeto livro dizem respeito somente a ele mesmo;
	// sendo completamente independentes entre si.

/*
	é assim que todo método e variável funciona em java por padrão; para não ser desta forma
	você os declara como static. 

	ao declarar algo como static, você quer dizer que ele diz respeito sobre a CLASSE COMO UM TODO,
	não cada objeto individualmente.
	ou seja, são métodos e propriedades 'de classe', em oposição aos que são 'de instância', 'do objeto'.
	como estes métodos e propriedades são 'da classe', eles são acessados diretamente nela; 
	criar ou não criar objetos não tem nada a ver com eles.

	lembre-se de onde tem usado static até agora - no método principal de cada programa.
	isso é pois o java evoca este método da seguinte forma, certo?
*/
	NomeDoArquivo.main(argumentos);
	// ...sendo NomeDoArquivo o nome do arquivo (...) e também da classe.
	// se ele está chamando o método assim, diretamente na classe, é por ele ser estático.
	// sem o static na declaração do método (public static void main(String[] args) etc)
	// o método seria de instância, ou seja, não poderia ser usado diretamente na classe,
	// sendo necessário criar uma instância dela antes. o java teria que fazer assim:
	NomeDoArquivo programa = new NomeDoArquivo();
	programa.main(argumentos);

/*	como isso do static é útil? bom, lá você coloca coisas que dizem respeito a Livros no geral,
	não a cada objeto livro especificamente; coisas que são compartilhadas entre eles, utilidades gerais,
	etc. vou dar um exemplo prático aqui, refazendo esta classe Book de forma que:
	-- ela mantenha um registro de todos os livros que eu tenho,
	-- ela mantenha um registro da quantidade total de páginas que eu li até agora, em livros quaisquer.
	-- tenha um registro de todos os títulos de livros que eu possuo.
*/

public class Book {

	public String title;
	public String author;

	public int totalPages;
	public int currentPage;

	// estou criando aqui algumas variáveis estáticas. elas ficarão acessíveis na classe,
	// (Book.numBooks), com seus valores independentes do que esteja acontecendo em cada
	// objeto Book.
	public static int allReadPages = 0;
	public static int numBooks = 0;
	public static String[] bookTitles; //vou usar isso para armazenar os títulos de livros.

	public Book(String title, String author, int pages){
		this.title = title;
		this.author = author;
		this.totalPages = pages;
		this.currentPage = 1;

		// aqui a diferença: agora toda vez que eu crio um novo livro,
		// incremento o contador total de livros da classe Book.
		Book.allPages += 1;
		// adiciona também o título deste livro no array que tem a lista de todos eles.
		Book.bookTitles.append(this.title);
	}

	public void goToPage(int page){
		this.currentPage = page;
	}
	
	public void nextPage(){
		this.goToPage(this.current_page+1);
		// sempre que eu ir para a próxima página, incremento o contador correspondente
		// na classe.
		Book.allReadPages += 1;
	}

	// vou criar um método de classe que me permita checar se eu tenho ou não um livro.
	// ele vai receber o título do livro que estou procurando como parâmetro,
	// e retornar TRUE/FALSE se eu o possuir ou não.
	static boolean findBook(String title){
		// na prática eu percorro o array de livros procurando por um com o mesmo título.
		// se encontrar, eu retorno true imediatamente.
		// se eu percorrer todos os livros e não encontrar um com o mesmo título,
		// o for acaba e eu retorno false no final.
		for(String bookTitle: Books.bookTitles){
			if(bookTitle == title){
				return true;
			}
		}
		return false;
	}
}

/*
	agora isso é fabuloso:
*/
	mybook = new Book("Dark Places", "Gillian", 350);
	another_book = new Book("The Jewelry God: The Jewelry Team", "JR Tolkien", 9999);
	books_are_the_word = new Book("Brief History of Time", "Leonard Mlodinow", 300);

	System.out.println(Book.numBooks); //isso corretamente me dirá que eu tenho três livros.
	// como a variável é da classe, ela está lá independende do que eu faça com os objetos.

	// o método find da classe (que usa uma variáveis de classe, um array com todos os nomes de livros)
	// nos permite agora comemorar o fato de eu não ter fifty shades of gray:
	if(Book.find("Fifty Shades of Gray") == false){
		System.out.println("que bom né");  
	}

	mybook.nextPage();
	another_book.nextPage();
	mybook.nextPage();

	// posso ler meus livros no ritmo merda que eu preferir, e a classe manterá registro do total de páginas lidas.
	System.out.println(Book.allReadPages);

/* 
	enfim, somente através da combinação de métodos e propriedades de objeto e de classe você consegue
	montar programas úteis, que adequadamente simulem a realidade:
	... com os métodos e propriedades de objeto/instância se referindo ao comportamento de um objeto individual
	específico daquela classe;
	... e com os métodos e propriedades de classe/estáticos se referindo à coisas gerais que são sobre aquela classe,
	mas não sobre objetos específicos. 

	dá para imaginar facilmente uma classe como esta dentro de um programa de gerenciamento de biblioteca,
	e é realmente assim que funciona.
*/