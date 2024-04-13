# Composição

- Composição é usada quando se inclui classes preexistentes como atributos de uma nova classe. Por exemplo,imagine que existe uma classe chamada Porta, que possua como atributo apenas uma *string* que contenha a cor da porta e dois métodos para abrir e fechar.

[Classe Porta](.Porta.java)

- Se criamos uma classe chamada Casa, nós podemos usar objetos da classe Porta como atributos, pois uma **casa tem portas**. O uso do verbo **ter** tem de fazer sentido quando relacionamos as duas classes, pois uma composição implica uma relação de pertinência entre duas classes.

- Ou seja, para sabermos se existe uma relação de composição na qual a classe A vai ser incluída como atributo da classe B, a frase **B tem A** deve fazer sentido.

[Classe Casa](./Casa.java)

- A classe Casa recebe como parâmetros de seu construtor dois objetos da classe Porta, pois está definido nela que a casa possui duas portas, uma da frente e outra no fundo.

- Os métodos responsáveis por abrir e fechar a porta fazem parte da classe Porta, então é necessário criar métodos na classe Casa que sejam responsáveis por executar os métodos da classe Porta.

- Na classe Principal, duas portas são criadas e passadas como parâmetro para o construtor da casa sendo construída.

- É importante ressaltar que objetos, quando usados como parâmetros de métodos e construtores, são passados por referência. Se forem criadas duas casas e forem passadas as mesmas portas como parâmetos dos construtores, as duas casas compartilharão as mesmas portas, o que estaria errad. Portanto, se forem criadas duas casas, devem ser criados quatro objetos da classe Porta.

[Classe Principal](./Principal.java)
