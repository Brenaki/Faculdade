import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
import numpy as np
import glob
import os
from datetime import datetime

# Configuração do estilo dos gráficos
plt.style.use('default')  # Usando estilo padrão do matplotlib
sns.set_theme()  # Usando tema padrão do seaborn

# Encontra todos os arquivos CSV na pasta atual
arquivos_csv = glob.glob('*.csv')

if not arquivos_csv:
    print("Nenhum arquivo CSV encontrado na pasta atual!")
    exit(1)

# Lista para armazenar todos os DataFrames
dfs = []

# Processa cada arquivo CSV
for arquivo in arquivos_csv:
    print(f"Processando arquivo: {arquivo}")
    try:
        df = pd.read_csv(arquivo)
        # Adiciona uma coluna com o nome do arquivo
        df['Arquivo'] = os.path.splitext(arquivo)[0]
        dfs.append(df)
    except Exception as e:
        print(f"Erro ao processar arquivo {arquivo}: {str(e)}")
        continue

if not dfs:
    print("Nenhum arquivo CSV válido foi encontrado!")
    exit(1)

# Combina todos os DataFrames
df = pd.concat(dfs, ignore_index=True)

# Converte o tamanho do buffer para KB para melhor visualização
df['TamanhoBuffer_KB'] = df['TamanhoBuffer'] / 1024

# Cria uma pasta para os resultados com timestamp
timestamp = datetime.now().strftime("%Y%m%d_%H%M%S")
pasta_resultados = f"analise_resultados_{timestamp}"
os.makedirs(pasta_resultados, exist_ok=True)

# Configuração da figura
plt.rcParams['figure.figsize'] = [15, 10]
plt.rcParams['figure.dpi'] = 100
plt.rcParams['savefig.dpi'] = 300

# Cria uma figura com múltiplos subplots
fig, axs = plt.subplots(2, 2, figsize=(15, 10))

# 1. Gráfico de Barras: Tempo por Método e Tamanho de Buffer
sns.barplot(data=df, x='TamanhoBuffer_KB', y='TempoGasto', hue='Metodo', ax=axs[0,0])
axs[0,0].set_title('Tempo de Cópia por Método e Tamanho de Buffer')
axs[0,0].set_xlabel('Tamanho do Buffer (KB)')
axs[0,0].set_ylabel('Tempo (segundos)')
axs[0,0].tick_params(axis='x', rotation=45)
axs[0,0].legend(title='Método', bbox_to_anchor=(1.05, 1), loc='upper left')

# 2. Gráfico de Linha: Taxa de Transferência
# Calcula a taxa de transferência em MB/s
df['TaxaTransferencia'] = (df['BytesCopiados'] / (1024 * 1024)) / df['TempoGasto']
sns.lineplot(data=df, x='TamanhoBuffer_KB', y='TaxaTransferencia', hue='Metodo', marker='o', ax=axs[0,1])
axs[0,1].set_title('Taxa de Transferência por Método e Tamanho de Buffer')
axs[0,1].set_xlabel('Tamanho do Buffer (KB)')
axs[0,1].set_ylabel('Taxa de Transferência (MB/s)')
axs[0,1].legend(title='Método', bbox_to_anchor=(1.05, 1), loc='upper left')

# 3. Gráfico de Dispersão: Tempo vs Tamanho do Buffer
sns.scatterplot(data=df, x='TamanhoBuffer_KB', y='TempoGasto', hue='Metodo', style='Metodo', ax=axs[1,0])
axs[1,0].set_title('Relação entre Tempo e Tamanho do Buffer')
axs[1,0].set_xlabel('Tamanho do Buffer (KB)')
axs[1,0].set_ylabel('Tempo (segundos)')
axs[1,0].legend(title='Método', bbox_to_anchor=(1.05, 1), loc='upper left')

# 4. Gráfico de Barras Empilhadas: Comparação de Métodos
pivot_df = df.pivot_table(
    values='TempoGasto',
    index='TamanhoBuffer_KB',
    columns='Metodo',
    aggfunc='mean'
)
pivot_df.plot(kind='bar', ax=axs[1,1])
axs[1,1].set_title('Comparação de Métodos por Tamanho de Buffer')
axs[1,1].set_xlabel('Tamanho do Buffer (KB)')
axs[1,1].set_ylabel('Tempo (segundos)')
axs[1,1].legend(title='Método', bbox_to_anchor=(1.05, 1), loc='upper left')
axs[1,1].tick_params(axis='x', rotation=45)

# Ajusta o layout para acomodar as legendas
plt.tight_layout()

# Salva o gráfico
caminho_grafico = os.path.join(pasta_resultados, 'analise_desempenho.png')
plt.savefig(caminho_grafico, dpi=300, bbox_inches='tight')

# Gera um relatório em texto
caminho_relatorio = os.path.join(pasta_resultados, 'relatorio_desempenho.txt')
with open(caminho_relatorio, 'w', encoding='utf-8') as f:
    f.write("Relatório de Desempenho - Cópia de Arquivos\n")
    f.write("=" * 50 + "\n\n")
    
    # Lista os arquivos processados
    f.write("Arquivos Processados:\n")
    f.write("-" * 20 + "\n")
    for arquivo in arquivos_csv:
        f.write(f"- {arquivo}\n")
    f.write("\n")
    
    # Análise por arquivo
    f.write("1. Análise por Arquivo\n")
    f.write("-" * 20 + "\n")
    for arquivo in df['Arquivo'].unique():
        arquivo_df = df[df['Arquivo'] == arquivo]
        f.write(f"\nArquivo: {arquivo}\n")
        f.write(f"Total de testes: {len(arquivo_df)}\n")
        f.write(f"Tamanho médio dos arquivos: {arquivo_df['BytesCopiados'].mean() / (1024*1024):.2f} MB\n")
        f.write(f"Tempo médio total: {arquivo_df['TempoGasto'].mean():.4f} segundos\n")
        f.write(f"Taxa de transferência média: {arquivo_df['TaxaTransferencia'].mean():.2f} MB/s\n")
    
    # Análise por método
    f.write("\n\n2. Análise por Método\n")
    f.write("-" * 20 + "\n")
    for metodo in df['Metodo'].unique():
        metodo_df = df[df['Metodo'] == metodo]
        f.write(f"\nMétodo: {metodo}\n")
        f.write(f"Tempo médio: {metodo_df['TempoGasto'].mean():.4f} segundos\n")
        f.write(f"Taxa de transferência média: {metodo_df['TaxaTransferencia'].mean():.2f} MB/s\n")
        f.write(f"Melhor tamanho de buffer: {metodo_df.loc[metodo_df['TempoGasto'].idxmin(), 'TamanhoBuffer_KB']:.2f} KB\n")
        f.write(f"Desvio padrão do tempo: {metodo_df['TempoGasto'].std():.4f} segundos\n")
    
    # Análise por tamanho de buffer
    f.write("\n\n3. Análise por Tamanho de Buffer\n")
    f.write("-" * 20 + "\n")
    for buffer in sorted(df['TamanhoBuffer_KB'].unique()):
        buffer_df = df[df['TamanhoBuffer_KB'] == buffer]
        f.write(f"\nTamanho de Buffer: {buffer:.2f} KB\n")
        for metodo in buffer_df['Metodo'].unique():
            metodo_data = buffer_df[buffer_df['Metodo'] == metodo]
            f.write(f"  {metodo}:\n")
            f.write(f"    Tempo médio: {metodo_data['TempoGasto'].mean():.4f} segundos\n")
            f.write(f"    Taxa média: {metodo_data['TaxaTransferencia'].mean():.2f} MB/s\n")
            f.write(f"    Desvio padrão: {metodo_data['TempoGasto'].std():.4f} segundos\n")
    
    # Conclusões
    f.write("\n\n4. Conclusões\n")
    f.write("-" * 20 + "\n")
    melhor_metodo = df.groupby('Metodo')['TempoGasto'].mean().idxmin()
    melhor_buffer = df.groupby('TamanhoBuffer_KB')['TempoGasto'].mean().idxmin()
    f.write(f"\nMelhor método geral: {melhor_metodo}\n")
    f.write(f"Melhor tamanho de buffer geral: {melhor_buffer:.2f} KB\n")
    f.write(f"Taxa de transferência máxima: {df['TaxaTransferencia'].max():.2f} MB/s\n")
    f.write(f"Taxa de transferência média geral: {df['TaxaTransferencia'].mean():.2f} MB/s\n")
    f.write(f"Tempo médio geral: {df['TempoGasto'].mean():.4f} segundos\n")

print(f"\nAnálise concluída! Arquivos gerados na pasta '{pasta_resultados}':")
print(f"1. analise_desempenho.png - Gráficos comparativos")
print(f"2. relatorio_desempenho.txt - Relatório detalhado")
print(f"\nArquivos CSV processados: {len(arquivos_csv)}")
for arquivo in arquivos_csv:
    print(f"- {arquivo}") 