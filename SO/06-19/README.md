# Como Executar o Projeto

## Requisitos para Execução Manual

- **Linux** (recomendado Ubuntu 22.04 ou superior)
- `gcc` (compilador C)
- `make`
- `pkg-config`
- `libssl-dev`
- `cargo` e `rustc` (Rust)
- `go` (Go 1.21 ou superior)

Instale as dependências no Ubuntu:
```sh
sudo apt update
sudo apt install build-essential gcc g++ make cmake curl wget git pkg-config libssl-dev cargo golang
```

Para compilar e executar:
```sh
make clean && make
./server -p 8080
```

---

## Requisitos para Execução via Docker

- **Docker** (https://docs.docker.com/get-docker/)

Para buildar e rodar o projeto:
```sh
docker build -t linux-server-modules .
docker run -p 8080:8080 linux-server-modules
```

---

Acesse o sistema em: [http://localhost:8080](http://localhost:8080) 