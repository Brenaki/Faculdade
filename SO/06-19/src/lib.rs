use std::ffi::c_int;
use std::io::Write;
use std::os::unix::io::FromRawFd;

#[no_mangle]
pub extern "C" fn module_generate(fd: c_int) {
    // Criar um arquivo a partir do file descriptor
    let mut file = unsafe { std::fs::File::from_raw_fd(fd) };
    
    // HTML com um vídeo sobre Rust
    let html_content = r##"<!DOCTYPE html>
<html lang="pt-BR">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Vídeo sobre Rust</title>
    <style>
        body {
            font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
            margin: 0;
            padding: 20px;
            background: linear-gradient(135deg, #667eea 0%, #764ba2 100%);
            min-height: 100vh;
            display: flex;
            flex-direction: column;
            align-items: center;
        }
        
        .container {
            max-width: 800px;
            width: 100%;
            background: white;
            border-radius: 15px;
            box-shadow: 0 20px 40px rgba(0,0,0,0.1);
            overflow: hidden;
        }
        
        .header {
            background: linear-gradient(45deg, #ff6b6b, #ee5a24);
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
        
        .rust-logo {
            width: 60px;
            height: 60px;
            margin: 0 auto 20px;
            display: block;
        }
        
        .features {
            display: grid;
            grid-template-columns: repeat(auto-fit, minmax(200px, 1fr));
            gap: 20px;
            margin-top: 30px;
        }
        
        .feature {
            background: #fff;
            padding: 20px;
            border-radius: 10px;
            border-left: 4px solid #ff6b6b;
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
    </style>
</head>
<body>
    <div class="container">
        <div class="header">
            <svg class="rust-logo" viewBox="0 0 100 100" xmlns="http://www.w3.org/2000/svg">
                <circle cx="50" cy="50" r="45" fill="#000"/>
                <path d="M30 35 L70 35 L70 65 L30 65 Z" fill="#DEA584"/>
                <path d="M35 40 L65 40 L65 60 L35 60 Z" fill="#000"/>
                <path d="M40 45 L60 45 L60 55 L40 55 Z" fill="#DEA584"/>
            </svg>
            <h1>Rust Programming Language</h1>
            <p>Uma linguagem de programação moderna, segura e eficiente</p>
        </div>
        
        <div class="content">
            <div class="video-container ">
                <iframe 
                    src="https://www.youtube.com/embed/5C_HPTJg5ek" 
                    title="Rust Programming Language Tutorial"
                    allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" 
                    allowfullscreen>
                </iframe>
            </div>
            
            <div class="description">
                <h2>Por que Rust?</h2>
                <p>
                    Rust é uma linguagem de programação de sistemas que oferece segurança de memória 
                    sem garbage collection, concorrência sem data races, e abstrações sem custo de runtime. 
                    É uma linguagem moderna que combina a performance de C/C++ com a segurança de linguagens 
                    de alto nível.
                </p>
            </div>
            
            <div class="features">
                <div class="feature">
                    <h3>🚀 Performance</h3>
                    <p>Performance comparável a C/C++ com zero-cost abstractions</p>
                </div>
                <div class="feature">
                    <h3>🛡️ Segurança</h3>
                    <p>Segurança de memória garantida em tempo de compilação</p>
                </div>
                <div class="feature">
                    <h3>⚡ Concorrência</h3>
                    <p>Concorrência segura sem data races</p>
                </div>
                <div class="feature">
                    <h3>🔧 Ferramentas</h3>
                    <p>Cargo, rustc e ecossistema rico de bibliotecas</p>
                </div>
            </div>
        </div>
    </div>
</body>
</html>"##;
    
    // Escrever o HTML no file descriptor
    if let Err(e) = file.write_all(html_content.as_bytes()) {
        eprintln!("Erro ao escrever HTML: {}", e);
    }
    
    // Flush para garantir que todos os dados sejam enviados
    if let Err(e) = file.flush() {
        eprintln!("Erro ao fazer flush: {}", e);
    }
} 