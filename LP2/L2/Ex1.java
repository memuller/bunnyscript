/* Requisitos:
As classes dos itens I, II, III e IV devem pertencer a um pacote chamado lp2gXX.biblioteca (onde XX é o número do usuário).

I) Crie uma classe Pessoa com os campos nome e dataNasc (da classe GregorianCalendar(int year, int month, int dayOfMonth)), que devem ser inicializados pelo construtor.

II) Crie uma classe Usuário, que estende Pessoa, e possua um campo String endereço e um campo do tipo int códigoUsuário. O construtor da classe Usuário deve inicializar todos os seus campos.
A classe Usuário também deve ter um campo Histórico da classe Vector. Este campo deve armazenar objetos da classe Empréstimo.
A classe Empréstimo deve conter a data do empréstimo, data de devolução e o código do Livro solicitado para empréstimo.
A classe Usuário deve ter um método adLivroHist(), que recebe a data de locação, data de devolução e o código do Livro emprestado, cria um objeto Empréstimo com estas informações e adiciona o mesmo no Histórico.

III) Crie uma classe Livro, com campos para:
 Código do Livro (String)
 Título do Livro
 Categoria (que pode ser Aventura, Ficção, Romance, etc.)
 Quantidade (inteiro)
 Emprestados (inteiro)
... e os seguintes construtores:
 Um construtor que inicializa todos os seus campos
 Um construtor que recebe como parâmetro um objeto String e inicializa o campo do Título do Livro.
Também deve ter os seguintes métodos:
 empresta, que não recebe parâmetros e acerta o campo Emprestados. Caso todas as cópias estejam emprestadas, deve levantar a exceção confirmada CopiaNaoDisponivelEx;
 devolve, que não recebe parâmetros e acerta o campo Emprestados. Caso nenhuma cópia tenha sido emprestada, deve levantar a exceção NenhumaCopiaEmprestadaEx.
A classe Livro também deve ter um campo Histórico da classe Vector. Este campo deve armazenar objetos da classe EmprestadoPara.
A classe EmprestadoPara deve conter a data do empréstimo, data de devolução e o código do usuário que pegou o livro emprestado.
A classe Livro deve ter um método adUsuarioHist(), que recebe a data de locação, data de devolução e o código do Usuário que pediu o livro emprestado, cria um objeto EmprestadoPara com estas informações e adiciona o mesmo no Histórico.

IV) Implemente a classe Biblioteca com:
 um campo para o cadastro de usuários contendo um objeto da classe java.util.Hashtable
 um campo para o cadastro de livros contendo um objeto da classe java.util.Hashtable.
A classe Biblioteca classe deve possuir dois construtores:
 um que inicialize os campos
 um construtor que carregue o cadastro de usuários e o cadastro de livros salvos em dois arquivos distintos.
Biblioteca deve possuir os seguintes métodos:
 cadastraUsuário: de retorno void, que recebe como parâmetro um objeto da classe Usuário e o armazena no objeto Hashtable correspondente. O código do usuário deve ser utilizado como chave;
 cadastraLivro: de retorno void, recebe como parâmetro um objeto da classe Livro e o armazena no objeto Hashtable correspondente; O código do Livro deve ser usado como chave;
 salvaArquivo: de retorno void, recebe como parâmetros um objeto da classe Hashtable (que pode ser o cadastro de usuários ou o acervo de livros) e um objeto da classe String contendo o nome do arquivo onde o outro parâmetro será salvo;
 lêArquivo: de retorno void, recebe como parâmetros um objeto da classe String contendo o nome do arquivos a ser lido (como o construtor, mas que pode ser chamado a qualquer hora, e lê somente o acervo de livros ou o cadastro de usuários);
 emprestaLivro: recebe como parâmetros a referência a um objeto Usuário a referencia a um objeto da classe Livro. (as referências já devem ter sido validadas – obtidas através dos métodos getLivro e getUsuário – veja observação abaixo). Chama o método empresta no objeto Livro e atualiza o histórico no objeto Usuário chamando adLivroHist. A data do empréstimo é obtida consultando o relógio/calendário do sistema no momento da operação.
 devolveLivro: o mesmo definido para o método anterior, só que chama o método devolve no objeto Livro. Aqui, no entanto, se você implementou a personalização direito, pode ser verificado se o usuário está devolvendo o livro com atraso e avisar de uma multa.
 String imprimeLivros(): Devolve uma string com a lista de livros cadastrados, ordenados pelo título.
 String imprimeUsuários():Devolve uma string com a lista de usuários cadastrados, ordenados pelo nome.

 Livro getLivro (String cód): Recebe o código do livro e obtém o objeto Livro da Hashtable correspondente. Se o livro não estiver cadastrado, deve gerar a exceção LivroNaoCadastradoEx;
 Usuário getUsuário (int cód): Recebe o código do usuário e obtém o objeto Usuário da Hashtable correspondente. Se o usuário não existir na Hashtable, deve gerar a exceção UsuárioNaoCadastradoEx;
Obs.: Além dos métodos listados, verifique se as classes Pessoa, Usuário, Livro e Biblioteca, devem ter, para cada campo, um método get<NomeDoCampo>() que retorna o conteúdo do campo.
Obs: Para todas estas classes, exceto Biblioteca, sobrescrever o método toString() para mostrar todas as informações sobre o objeto [no caso de Usuário e Livro, deve exibir inclusive o histórico].
As classes dos itens I, II, III e IV devem pertencer a um pacote chamado lp2gXX.biblioteca (onde XX é o número do usuário).

V) Desenvolver o programa principal, que deve ter os seguintes módulos:
 Manutenção, que cria, abre e salva os arquivos (dois) que contém, cada um, uma HasTable (livros e usuários);
 Cadastro, que cadastra usuários e livros. Deve exibir um menu com opções para: cadastrar usuários, cadastrar livros e salvar em arquivo. A opção de salvamento em arquivo deve exibir um sub-menu para que o usuário escolha se deseja salvar o cadastro de usuários ou o cadastro de livros.
 Empréstimo: que executa a locação de um livro para um usuário. Um menu com as opções de exibir o cadastro de livros ou fazer um empréstimo deve ser exibido. Ao fazer um empréstimo, devem ser obtidos os objetos Livro e Usuário. As exceções (livro não existe, usuário não cadastrado, cópia não disponível, etc.) devem ser tratadas. Quando um empréstimo for bem sucedido os dados devem ser escritos na tela, o registro do livro mantido (e salvo na Hashtable – dependendo de como for programado) e o histórico do usuário atualizado.
Obs: no programa principal, o programador deve customizar a política da biblioteca (por isso as classes de suporte estão em um pacote e o programa principal não está). Por exemplo, pode restringir o número máximo de livros que um usuário pode emprestar de uma só vez e o número de dias que um usuário pode ficar com o livro sem pagar multa.
 Relatório, que permite listar o acervo de livros, o cadastro de usuários ou detalhes de um usuário ou livro específico (com seu histórico).

VI) Desenvolver dois scripts (um para Windows e outro para Linux) para inicializar o programa. Os scripts podem (devem) usar argumentos e/ou variáveis de ambiente para
carregar a JVM e classes adequadamente (isso deve tornar os pacotes “independentes de localização).
Exercício 2: Applet – Tabela de produtos
Você vai adaptar a 3ª questão da Lista 1, da lista de produtos com ordenação.
Faça um painel para entrar com produtos, usando campos e botões.
Coloque os produtos em uma tabela gráfica (pode usar o exemplo SwitgSet2), permitindo a ordenação por qualquer cambo (como feito para o Ex 3 da Lista 1)
Faça a previsão de mensagens de erro (em janelas pop-up ou campos de texto).
Utilize componentes adicionais ou recursos que você junge necessários.
O applet deve ser acessado pela Internet, através da URL: 152.92.236.11/~<seu login>
Para isso você vai precisar criar um diretório public_html, dentro do seu diretório home e, lá dentro, um arquivo index.html com as permissões e o conteúdo adequado, além das classes em Java. */

class Pessoa{
    public Pessoa(String nome){
        this.nome = nome;
        // this.dataNasc =
    }
}