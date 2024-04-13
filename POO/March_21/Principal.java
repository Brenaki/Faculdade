public class Principal {
  public static void main(String[] args) {
    Data d[];
    Pessoa p[];
    Funcionario f[];
    Chefe c[];
    Aluno a[];

    d = new Data[3];

    d[0] = new Data(13, 6);
    d[1] = new Data(24, 8, 1998);
    d[2] = new Data(18, 9, 2005);

    // Datas
    System.out.println("\n**Datas**");
    for (int i = 0; i < 3; i++) {
      System.out.println(d[i]);
    }

    p = new Pessoa[2];

    p[0] = new Pessoa("João", "123456789", d[0]);
    p[1] = new Pessoa("Maria", d[1]);

    // Pessoas
    System.out.println("\n**Pessoas**");
    for (int i = 0; i < 2; i++) {
      System.out.println(p[i]);
    }

    a = new Aluno[2];

    a[0] = new Aluno("Pedro", "987654321", d[0], "123456");
    a[1] = new Aluno("Julia", d[1], "654321");

    // Alunos
    System.out.println("\n**Alunos**");
    for (int i = 0; i < 2; i++) {
      System.out.println(a[i]);
    }

    f = new Funcionario[2];

    f[0] = new Funcionario("José", "987654321", d[2], "123456", 1000.0);
    f[1] = new Funcionario("Ana", d[0], "654321", 2000.0);

    // Funcionarios
    System.out.println("\n**Funcionarios**");
    for (int i = 0; i < 2; i++) {
      System.out.println(f[i]);
    }

    c = new Chefe[2];

    c[0] = new Chefe("Carlos", "123456789", d[1], "123456", 3000.0, "Gerente");
    c[1] = new Chefe("Marta", d[2], "654321", 4000.0, "Diretor");

    // Chefes
    System.out.println("\n**Chefes**\n");
    for (int i = 0; i < 2; i++) {
      System.out.println(c[i]);
    }
  }
}