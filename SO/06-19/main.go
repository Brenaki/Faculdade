package main

/*
#cgo CFLAGS: -I.
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
*/
import "C"
import (
	"os"
)

//export module_generate
func module_generate(fd C.int) {
	// Converter o file descriptor C para Go
	goFd := int(fd)

	// Criar um arquivo a partir do file descriptor
	file := os.NewFile(uintptr(goFd), "socket")
	if file == nil {
		return
	}
	defer file.Close()

	// HTML sobre Go programming language
	htmlContent := `<!DOCTYPE html>
<html lang="pt-BR">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Go Programming Language</title>
    <style>
        body {
            font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
            margin: 0;
            padding: 20px;
            background: linear-gradient(135deg, #00ADD8 0%, #5DC9E2 100%);
            min-height: 100vh;
            display: flex;
            flex-direction: column;
            align-items: center;
        }
        
        .container {
            max-width: 900px;
            width: 100%;
            background: white;
            border-radius: 15px;
            box-shadow: 0 20px 40px rgba(0,0,0,0.1);
            overflow: hidden;
        }
        
        .header {
            background: linear-gradient(45deg, #00ADD8, #5DC9E2);
            color: white;
            padding: 30px;
            text-align: center;
        }
        
        .header h1 {
            margin: 0;
            font-size: 2.5em;
            font-weight: 300;
        }
        
        .header p {
            margin: 10px 0 0 0;
            font-size: 1.2em;
            opacity: 0.9;
        }
        
        .content {
            padding: 30px;
        }
        
        .video-container {
            position: relative;
            width: 100%;
            height: 0;
            padding-bottom: 56.25%;
            margin-bottom: 20px;
        }
        
        .video-container iframe {
            position: absolute;
            top: 0;
            left: 0;
            width: 100%;
            height: 100%;
            border: none;
            border-radius: 10px;
            box-shadow: 0 10px 30px rgba(0,0,0,0.2);
        }
        
        .description {
            background: #f8f9fa;
            padding: 20px;
            border-radius: 10px;
            margin-top: 20px;
        }
        
        .description h2 {
            color: #333;
            margin-top: 0;
        }
        
        .description p {
            color: #666;
            line-height: 1.6;
        }
        
        .go-logo {
            width: 80px;
            height: 80px;
            margin: 0 auto 20px;
            display: block;
            background: #00ADD8;
            border-radius: 50%;
            position: relative;
        }
        
        .go-logo::before {
            content: "Go";
            position: absolute;
            top: 50%;
            left: 50%;
            transform: translate(-50%, -50%);
            color: white;
            font-weight: bold;
            font-size: 24px;
        }
        
        .features {
            display: grid;
            grid-template-columns: repeat(auto-fit, minmax(250px, 1fr));
            gap: 20px;
            margin-top: 30px;
        }
        
        .feature {
            background: #fff;
            padding: 20px;
            border-radius: 10px;
            border-left: 4px solid #00ADD8;
            box-shadow: 0 5px 15px rgba(0,0,0,0.1);
        }
        
        .feature h3 {
            color: #333;
            margin-top: 0;
        }
        
        .feature p {
            color: #666;
            margin-bottom: 0;
        }
        
        .code-example {
            background: #2d3748;
            color: #e2e8f0;
            padding: 20px;
            border-radius: 10px;
            font-family: 'Courier New', monospace;
            margin: 20px 0;
            overflow-x: auto;
            white-space: pre;
            line-height: 1.4;
        }
    </style>
</head>
<body>
    <div class="container">
        <div class="header">
            <div class="go-logo"></div>
            <h1>Go Programming Language</h1>
            <p>Uma linguagem de programação moderna, simples e eficiente</p>
        </div>
        
        <div class="content">
            <div class="description">
                <h2>Por que Go?</h2>
                <p>
                    Go é uma linguagem de programação de código aberto desenvolvida pelo Google. 
                    Ela combina a simplicidade de linguagens dinâmicas com a eficiência e segurança 
                    de linguagens compiladas. Go é especialmente conhecida por sua excelente 
                    performance em aplicações concorrentes e distribuídas.
                </p>
            </div>
            
            <div class="code-example">package main

import "fmt"

func main() {
    fmt.Println("Hello, Go!")
    
    // Goroutines para concorrência
    go func() {
        fmt.Println("Executando em paralelo!")
    }()
    
    // Channels para comunicação
    ch := make(chan string)
    go func() {
        ch <- "Mensagem do channel"
    }()
    
    msg := <-ch
    fmt.Println(msg)
}</div>
            
            <div class="video-container">
                <iframe 
                    src="https://www.youtube.com/embed/YS4e4q9oBaU" 
                    title="Go Programming Language Tutorial"
                    allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" 
                    allowfullscreen>
                </iframe>
            </div>
            
            <div class="features">
                <div class="feature">
                    <h3>🚀 Simplicidade</h3>
                    <p>Sintaxe limpa e fácil de aprender, sem herança complexa</p>
                </div>
                <div class="feature">
                    <h3>⚡ Concorrência</h3>
                    <p>Goroutines e channels para programação concorrente eficiente</p>
                </div>
                <div class="feature">
                    <h3>🔧 Ferramentas</h3>
                    <p>go fmt, go test, go mod e ecossistema rico</p>
                </div>
                <div class="feature">
                    <h3>🌐 Networking</h3>
                    <p>Excelente para aplicações web e microserviços</p>
                </div>
                <div class="feature">
                    <h3>📦 Garbage Collection</h3>
                    <p>Gerenciamento automático de memória eficiente</p>
                </div>
                <div class="feature">
                    <h3>🔒 Segurança</h3>
                    <p>Tipagem estática e verificações em tempo de compilação</p>
                </div>
            </div>
        </div>
    </div>
</body>
</html>`

	// Escrever o HTML no file descriptor
	file.WriteString(htmlContent)

	// Flush para garantir que todos os dados sejam enviados
	file.Sync()
}

func main() {
	// Esta função é necessária para compilar como biblioteca compartilhada
	// mas não será chamada quando usado como módulo
}
