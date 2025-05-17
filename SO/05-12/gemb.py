message = "Molotto e Victor são legais! "
message_bytes = message.encode('utf-8')
target_size = 2 * 1024 * 1024 * 1024  

repeats = target_size // len(message_bytes)

with open('mensagem_2GB.bin', 'wb') as f:
    for _ in range(repeats):
        f.write(message_bytes)

import os
file_size = os.path.getsize('mensagem_2GB.bin')
print(f"Arquivo criado com sucesso!")
print(f"Tamanho do arquivo: {file_size / (1024*1024*1024):.2f} GB")
