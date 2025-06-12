import numpy as np
from scipy import stats
import matplotlib.pyplot as plt

# =====
# Dados
# =====

## Método fread/fwrite
fread_fwrite = [427.63,463.20,481.01,727.04,517.85,499.93,484.76,370.96,397.02,499.65,391.03,356.79,375.19,384.64,378.24,515.18,349.96,349.48,350.13,350.17,354.72,354.77,350.35,353.01,354.62,352.83,351.10,351.07,350.18,349.93]

## Método read/write
read_write = [469.54,469.06,493.14,461.35,499.83,508.22,384.51,407.59,439.32,630.51,366.06,371.90,389.02,382.08,438.25,396.26,353.70,356.25,356.34,367.38,356.19,357.15,359.27,359.18,358.19,357.63,357.85,358.15,355.68,354.07]

### Converter para array numpy
x1 = np.array(fread_fwrite)
x2 = np.array(read_write)

# ====================================
# Funções para intervalos de confiança
# ====================================

def ic_media(dados, confianca=0.95):
    """Intervalo de confiança para a média"""
    n = len(dados)
    media = np.mean(dados)
    erro_padrao = stats.sem(dados)
    t_critico = stats.t.ppf((1 + confianca) / 2, df=n-1)
    margem_erro = t_critico * erro_padrao
    return media, (media - margem_erro, media + margem_erro), margem_erro

def ic_variancia(dados, confianca=0.95):
    """Intervalo de confiança para variância"""
    n = len(dados)
    variancia = np.var(dados, ddof=1)
    chi2_inf = stats.chi2.ppf((1 - confianca) / 2, df=n-1)
    chi2_sup = stats.chi2.ppf((1 + confianca) / 2, df=n-1)
    ic_inf = (n-1) * variancia / chi2_sup
    ic_sup = (n-1) * variancia / chi2_inf
    return variancia, (ic_inf, ic_sup)

def ic_diferenca_medias(grupo1, grupo2, confianca=0.95):
    """Intervalo de confiança para diferença das médias (Welch)"""
    n1, n2 = len(grupo1), len(grupo2)
    m1, m2 = np.mean(grupo1), np.mean(grupo2)
    s1, s2 = np.std(grupo1, ddof=1), np.std(grupo2, ddof=1)

    # Erro padrão da diferença
    se_diff = np.sqrt(s1**2/n1 + s2**2/n2)

    # Graus de liberdade de Welch
    df_welch = (s1**2/n1 + s2**2/n2)**2 / ((s1**2/n1)**2/(n1-1) + (s2**2/n2)**2/(n2-1))

    # Diferença e intervalo  
    diff = m1 - m2  
    t_critico = stats.t.ppf((1 + confianca) / 2, df=df_welch)  
    margem_erro = t_critico * se_diff  
      
    return diff, (diff - margem_erro, diff + margem_erro), df_welch, se_diff

# ===============================
# Calcular Intervalo de Confiança
# ===============================

print("\n" + "="*60)  
print("INTERVALOS DE CONFIANÇA (95%)")  
print("="*60)  
  
# Para fread/fwrite  
print("\n1. MÉTODO: fread/fwrite")  
print("-" * 30)  
media1, ic_media1, me1 = ic_media(x1)  
var1, ic_var1 = ic_variancia(x1)  
  
print(f"Tamanho da amostra: {len(x1)}")  
print(f"Média: {media1:.3f}")  
print(f"IC 95% para média: ({ic_media1[0]:.3f}, {ic_media1[1]:.3f})")  
print(f"Margem de erro: ±{me1:.3f}")  
print(f"Variância: {var1:.3f}")  
print(f"IC 95% para variância: ({ic_var1[0]:.3f}, {ic_var1[1]:.3f})")  
print(f"Desvio padrão: {np.sqrt(var1):.3f}")  
  
# Para read/write  
print("\n2. MÉTODO: read/write")  
print("-" * 30)  
media2, ic_media2, me2 = ic_media(x2)  
var2, ic_var2 = ic_variancia(x2)  
  
print(f"Tamanho da amostra: {len(x2)}")  
print(f"Média: {media2:.3f}")  
print(f"IC 95% para média: ({ic_media2[0]:.3f}, {ic_media2[1]:.3f})")  
print(f"Margem de erro: ±{me2:.3f}")  
print(f"Variância: {var2:.3f}")  
print(f"IC 95% para variância: ({ic_var2[0]:.3f}, {ic_var2[1]:.3f})")  
print(f"Desvio padrão: {np.sqrt(var2):.3f}")  
  
# Comparação entre métodos  
print("\n3. COMPARAÇÃO ENTRE MÉTODOS")  
print("-" * 40)  
diff, ic_diff, df_welch, se_diff = ic_diferenca_medias(x1, x2)  
  
print(f"Diferença das médias (fread/fwrite - read/write): {diff:.3f}")  
print(f"Erro padrão da diferença: {se_diff:.3f}")  
print(f"Graus de liberdade (Welch): {df_welch:.1f}")  
print(f"IC 95% para diferença: ({ic_diff[0]:.3f}, {ic_diff[1]:.3f})")  
  
# Teste estatístico  
t_stat, p_value = stats.ttest_ind(x1, x2, equal_var=False)  
print(f"Teste t de Welch: t = {t_stat:.3f}, p-valor = {p_value:.4f}")  
  
# Interpretação  
print(f"\nINTERPRETAÇÃO:")  
if ic_diff[0] <= 0 <= ic_diff[1]:  
    print("• O intervalo inclui zero → NÃO há diferença significativa")  
    print("  entre os métodos fread/fwrite e read/write.")  
else:  
    print("• O intervalo NÃO inclui zero → HÁ diferença significativa")  
    print("  entre os métodos.")


# ======
# Reusmo
# ======

print("\n" + "="*70)  
print("RESUMO DOS RESULTADOS")  
print("="*70)  
print(f"{'Parâmetro':<25} {'fread/fwrite':<20} {'read/write':<20}")  
print("-" * 70)  
print(f"{'Média':<25} {media1:.3f} ± {me1:.3f} {'':<8} {media2:.3f} ± {me2:.3f}")  
print(f"{'IC Média':<25} ({ic_media1[0]:.1f}, {ic_media1[1]:.1f}) {'':<8} ({ic_media2[0]:.1f}, {ic_media2[1]:.1f})")  
print(f"{'Variância':<25} {var1:.1f} {'':<15} {var2:.1f}")  
print(f"{'IC Variância':<25} ({ic_var1[0]:.1f}, {ic_var1[1]:.1f}) {'':<4} ({ic_var2[0]:.1f}, {ic_var2[1]:.1f})")  
print("-" * 70)  
print(f"{'Diferença das médias:':<25} {diff:.3f}")  
print(f"{'IC Diferença:':<25} ({ic_diff[0]:.1f}, {ic_diff[1]:.1f})")  
print(f"{'Conclusão:':<25} {'Sem diferença significativa' if p_value > 0.05 else 'Diferença significativa'}")
