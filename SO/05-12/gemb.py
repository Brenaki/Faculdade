# Mensagem a ser repetida
message = "Molotto e Victor são legais! "
message_bytes = message.encode('utf-8')

# Tamanho desejado: 1GB = 1073741824 bytes
target_size = 6144 * 1024 * 1024  # 1GB em bytes

# Calcula quantas vezes a mensagem precisa ser repetida
repeats = target_size // len(message_bytes)

# Cria o arquivo binário
with open('mensagem_1gb.bin', 'wb') as f:
    # Escreve a mensagem repetidamente até atingir aproximadamente 1GB
    for _ in range(repeats):
        f.write(message_bytes)

# Verifica o tamanho do arquivo criado
import os
file_size = os.path.getsize('mensagem_1gb.bin')
print(f"Arquivo criado com sucesso!")
print(f"Tamanho do arquivo: {file_size / (6144*1024*1024):.2f} GB")
