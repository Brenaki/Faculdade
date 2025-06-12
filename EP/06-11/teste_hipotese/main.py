import numpy as np
from scipy import stats
import matplotlib.pyplot as plt

# ==========
# SEUS DADOS
# ==========

## Método fread/fwrite
fread_fwrite = [427.63,463.20,481.01,727.04,517.85,499.93,484.76,370.96,397.02,499.65,391.03,356.79,375.19,384.64,378.24,515.18,349.96,349.48,350.13,350.17,354.72,354.77,350.35,353.01,354.62,352.83,351.10,351.07,350.18,349.93]

## Método read/write
read_write = [469.54,469.06,493.14,461.35,499.83,508.22,384.51,407.59,439.32,630.51,366.06,371.90,389.02,382.08,438.25,396.26,353.70,356.25,356.34,367.38,356.19,357.15,359.27,359.18,358.19,357.63,357.85,358.15,355.68,354.07]

# Converter para arrays numpy
x1 = np.array(fread_fwrite)
x2 = np.array(read_write)

print("TESTES DE HIPÓTESES")
print("="*60)
print(f"Dados carregados:")

n1 = len(x1)
n2 = len(x2)
av1 = np.mean(x1)
av2 = np.mean(x2)
var1 = np.var(x1, ddof=1)
var2 = np.var(x2, ddof=1)

print(f"fread/fwrite: {n1} valores, média = {av1:.3f}, variância = {var1:.3f}")
print(f"read/write: {n2} valores, média = {av2:.3f}, variância = {var2:.3f}")

# ========================================
# FUNÇÕES PARA TESTES DE HIPÓTESES
# ========================================

def teste_media_uma_amostra(dados, mu0, alpha=0.05, teste='bilateral'):
    """
    Teste t para média de uma amostra
    H0: μ = μ0 vs H1: μ ≠ μ0 (bilateral) ou μ > μ0 ou μ < μ0
    """
    n = len(dados)
    media = np.mean(dados)
    s = np.std(dados, ddof=1)
    
    # Estatística t
    t_calc = (media - mu0) / (s / np.sqrt(n))
    
    # Valor crítico e p-valor
    if teste == 'bilateral':
        t_crit = stats.t.ppf(1 - alpha/2, df=n-1)
        p_valor = 2 * (1 - stats.t.cdf(abs(t_calc), df=n-1))
        regiao_rejeicao = f"|t| > {t_crit:.3f}"
    elif teste == 'direita':
        t_crit = stats.t.ppf(1 - alpha, df=n-1)
        p_valor = 1 - stats.t.cdf(t_calc, df=n-1)
        regiao_rejeicao = f"t > {t_crit:.3f}"
    else:  # esquerda
        t_crit = stats.t.ppf(alpha, df=n-1)
        p_valor = stats.t.cdf(t_calc, df=n-1)
        regiao_rejeicao = f"t < {t_crit:.3f}"
    
    decisao = "Rejeitar H0" if p_valor < alpha else "Não rejeitar H0"
    
    return {
        'estatistica': t_calc,
        'valor_critico': t_crit,
        'p_valor': p_valor,
        'decisao': decisao,
        'regiao_rejeicao': regiao_rejeicao,
        'media_amostral': media,
        'gl': n-1
    }

def teste_variancia_uma_amostra(dados, sigma2_0, alpha=0.05, teste='bilateral'):
    """
    Teste qui-quadrado para variância de uma amostra
    H0: σ² = σ²₀ vs H1: σ² ≠ σ²₀
    """
    n = len(dados)
    s2 = np.var(dados, ddof=1)
    
    # Estatística qui-quadrado
    chi2_calc = (n - 1) * s2 / sigma2_0
    
    # Valores críticos e p-valor
    if teste == 'bilateral':
        chi2_inf = stats.chi2.ppf(alpha/2, df=n-1)
        chi2_sup = stats.chi2.ppf(1 - alpha/2, df=n-1)
        p_valor = 2 * min(stats.chi2.cdf(chi2_calc, df=n-1), 
                         1 - stats.chi2.cdf(chi2_calc, df=n-1))
        regiao_rejeicao = f"χ² < {chi2_inf:.3f} ou χ² > {chi2_sup:.3f}"
        decisao = "Rejeitar H0" if chi2_calc < chi2_inf or chi2_calc > chi2_sup else "Não rejeitar H0"
    elif teste == 'direita':
        chi2_crit = stats.chi2.ppf(1 - alpha, df=n-1)
        p_valor = 1 - stats.chi2.cdf(chi2_calc, df=n-1)
        regiao_rejeicao = f"χ² > {chi2_crit:.3f}"
        decisao = "Rejeitar H0" if chi2_calc > chi2_crit else "Não rejeitar H0"
    else:  # esquerda
        chi2_crit = stats.chi2.ppf(alpha, df=n-1)
        p_valor = stats.chi2.cdf(chi2_calc, df=n-1)
        regiao_rejeicao = f"χ² < {chi2_crit:.3f}"
        decisao = "Rejeitar H0" if chi2_calc < chi2_crit else "Não rejeitar H0"
    
    return {
        'estatistica': chi2_calc,
        'p_valor': p_valor,
        'decisao': decisao,
        'regiao_rejeicao': regiao_rejeicao,
        'variancia_amostral': s2,
        'gl': n-1
    }

def teste_comparacao_medias(grupo1, grupo2, alpha=0.05, teste='bilateral'):
    """
    Teste t de Welch para comparação de médias (variâncias diferentes)
    H0: μ₁ = μ₂ vs H1: μ₁ ≠ μ₂
    """
    n1, n2 = len(grupo1), len(grupo2)
    m1, m2 = np.mean(grupo1), np.mean(grupo2)
    s1, s2 = np.std(grupo1, ddof=1), np.std(grupo2, ddof=1)
    
    # Erro padrão da diferença
    se_diff = np.sqrt(s1**2/n1 + s2**2/n2)
    
    # Graus de liberdade de Welch
    df_welch = (s1**2/n1 + s2**2/n2)**2 / ((s1**2/n1)**2/(n1-1) + (s2**2/n2)**2/(n2-1))
    
    # Estatística t
    t_calc = (m1 - m2) / se_diff
    
    # Valor crítico e p-valor
    if teste == 'bilateral':
        t_crit = stats.t.ppf(1 - alpha/2, df=df_welch)
        p_valor = 2 * (1 - stats.t.cdf(abs(t_calc), df=df_welch))
        regiao_rejeicao = f"|t| > {t_crit:.3f}"
    elif teste == 'direita':
        t_crit = stats.t.ppf(1 - alpha, df=df_welch)
        p_valor = 1 - stats.t.cdf(t_calc, df=df_welch)
        regiao_rejeicao = f"t > {t_crit:.3f}"
    else:  # esquerda
        t_crit = stats.t.ppf(alpha, df=df_welch)
        p_valor = stats.t.cdf(t_calc, df=df_welch)
        regiao_rejeicao = f"t < {t_crit:.3f}"
    
    decisao = "Rejeitar H0" if p_valor < alpha else "Não rejeitar H0"
    
    return {
        'estatistica': t_calc,
        'valor_critico': t_crit,
        'p_valor': p_valor,
        'decisao': decisao,
        'regiao_rejeicao': regiao_rejeicao,
        'diferenca': m1 - m2,
        'gl': df_welch
    }

def teste_comparacao_variancias(grupo1, grupo2, alpha=0.05):
    """
    Teste F para comparação de variâncias
    H0: σ₁² = σ₂² vs H1: σ₁² ≠ σ₂²
    """
    s1_2 = np.var(grupo1, ddof=1)
    s2_2 = np.var(grupo2, ddof=1)
    n1, n2 = len(grupo1), len(grupo2)
    
    # Estatística F (maior variância no numerador)
    if s1_2 >= s2_2:
        f_calc = s1_2 / s2_2
        df1, df2 = n1-1, n2-1
    else:
        f_calc = s2_2 / s1_2
        df1, df2 = n2-1, n1-1
    
    # Valor crítico e p-valor (teste bilateral)
    f_crit = stats.f.ppf(1 - alpha/2, df1, df2)
    p_valor = 2 * (1 - stats.f.cdf(f_calc, df1, df2))
    
    decisao = "Rejeitar H0" if f_calc > f_crit else "Não rejeitar H0"
    
    return {
        'estatistica': f_calc,
        'valor_critico': f_crit,
        'p_valor': p_valor,
        'decisao': decisao,
        'regiao_rejeicao': f"F > {f_crit:.3f}",
        'gl1': df1,
        'gl2': df2
    }

# ========================================
# TESTES PARA CADA VARIÁVEL
# ========================================

print("\n" + "="*60)
print("1. TESTES PARA fread/fwrite")
print("="*60)

# Teste 1.1: Média
print(f"\n1.1 Teste para a média (H0: μ = {av1:.3f})")
print("-" * 40)
resultado = teste_media_uma_amostra(x1, mu0=av1, teste='bilateral')
print(f"H0: μ = {av1:.3f}  vs  H1: μ ≠ {av1:.3f}")
print(f"Estatística t: {resultado['estatistica']:.3f}")
print(f"Valor crítico: ±{resultado['valor_critico']:.3f}")
print(f"P-valor: {resultado['p_valor']:.4f}")
print(f"Região de rejeição: {resultado['regiao_rejeicao']}")
print(f"Decisão: {resultado['decisao']}")
print(f"Média amostral: {resultado['media_amostral']:.3f}")

# Teste 1.2: Variância
print(f"\n1.2 Teste para a variância (H0: σ² = {var1:.3f})")
print("-" * 40)
resultado = teste_variancia_uma_amostra(x1, sigma2_0=var1, teste='bilateral')
print(f"H0: σ² = {var1:.3f}  vs  H1: σ² ≠ {var1:.3f}")
print(f"Estatística χ²: {resultado['estatistica']:.3f}")
print(f"P-valor: {resultado['p_valor']:.4f}")
print(f"Região de rejeição: {resultado['regiao_rejeicao']}")
print(f"Decisão: {resultado['decisao']}")
print(f"Variância amostral: {resultado['variancia_amostral']:.3f}")

print("\n" + "="*60)
print("2. TESTES PARA read/write")
print("="*60)

# Teste 2.1: Média
print(f"\n2.1 Teste para a média (H0: μ = {av2:.3f})")
print("-" * 40)
resultado = teste_media_uma_amostra(x2, mu0=av2, teste='bilateral')
print(f"H0: μ = {av2:.3f}  vs  H1: μ ≠ {av2:.3f}")
print(f"Estatística t: {resultado['estatistica']:.3f}")
print(f"Valor crítico: ±{resultado['valor_critico']:.3f}")
print(f"P-valor: {resultado['p_valor']:.4f}")
print(f"Região de rejeição: {resultado['regiao_rejeicao']}")
print(f"Decisão: {resultado['decisao']}")
print(f"Média amostral: {resultado['media_amostral']:.3f}")

# Teste 2.2: Variância
print(f"\n2.2 Teste para a variância (H0: σ² = {var2:.3f})")
print("-" * 40)
resultado = teste_variancia_uma_amostra(x2, sigma2_0=var2, teste='bilateral')
print(f"H0: σ² = {var2:.3f}  vs  H1: σ² ≠ {var2:.3f}")
print(f"Estatística χ²: {resultado['estatistica']:.3f}")
print(f"P-valor: {resultado['p_valor']:.4f}")
print(f"Região de rejeição: {resultado['regiao_rejeicao']}")
print(f"Decisão: {resultado['decisao']}")
print(f"Variância amostral: {resultado['variancia_amostral']:.3f}")

# ========================================
# TESTES DE COMPARAÇÃO
# ========================================

print("\n" + "="*60)
print("3. COMPARAÇÃO ENTRE AS DUAS VARIÁVEIS")
print("="*60)

# Teste 3.1: Igualdade das variâncias
print("\n3.1 Teste de igualdade das variâncias")
print("-" * 40)
resultado = teste_comparacao_variancias(x1, x2)
print(f"H0: σ₁² = σ₂²  vs  H1: σ₁² ≠ σ₂²")
print(f"Estatística F: {resultado['estatistica']:.3f}")
print(f"Valor crítico: {resultado['valor_critico']:.3f}")
print(f"P-valor: {resultado['p_valor']:.4f}")
print(f"Região de rejeição: {resultado['regiao_rejeicao']}")
print(f"Decisão: {resultado['decisao']}")
print(f"GL: ({resultado['gl1']}, {resultado['gl2']})")

# Teste 3.2: Igualdade das médias
print("\n3.2 Teste de igualdade das médias (Welch)")
print("-" * 40)
resultado = teste_comparacao_medias(x1, x2, teste='bilateral')
print(f"H0: μ₁ = μ₂  vs  H1: μ₁ ≠ μ₂")
print(f"Estatística t: {resultado['estatistica']:.3f}")
print(f"Valor crítico: ±{resultado['valor_critico']:.3f}")
print(f"P-valor: {resultado['p_valor']:.4f}")
print(f"Região de rejeição: {resultado['regiao_rejeicao']}")
print(f"Decisão: {resultado['decisao']}")
print(f"Diferença das médias: {resultado['diferenca']:.3f}")
print(f"GL (Welch): {resultado['gl']:.1f}")

# Teste 3.3: fread/fwrite é mais rápido? (teste unilateral)
print("\n3.3 Teste: fread/fwrite é mais rápido?")
print("-" * 40)
resultado = teste_comparacao_medias(x1, x2, teste='esquerda')  # μ₁ < μ₂
print(f"H0: μ₁ ≥ μ₂  vs  H1: μ₁ < μ₂ (fread/fwrite mais rápido)")
print(f"Estatística t: {resultado['estatistica']:.3f}")
print(f"Valor crítico: {resultado['valor_critico']:.3f}")
print(f"P-valor: {resultado['p_valor']:.4f}")
print(f"Região de rejeição: {resultado['regiao_rejeicao']}")
print(f"Decisão: {resultado['decisao']}")

# ========================================
# RESUMO DOS RESULTADOS
# ========================================

print("\n" + "="*70)
print("RESUMO DOS TESTES DE HIPÓTESES")
print("="*70)

# Recalcular alguns testes para o resumo
t1_media = teste_media_uma_amostra(x1, mu0=av1)
t2_media = teste_media_uma_amostra(x2, mu0=av2)
t1_var = teste_variancia_uma_amostra(x1, sigma2_0=var1)
t2_var = teste_variancia_uma_amostra(x2, sigma2_0=var2)
t_comp_var = teste_comparacao_variancias(x1, x2)
t_comp_media = teste_comparacao_medias(x1, x2)

print(f"{'Teste':<35} {'Estatística':<12} {'P-valor':<10} {'Decisão':<20}")
print("-" * 70)
print(f"{f'fread/fwrite: μ = {av1:.3f}':<35} {t1_media['estatistica']:<12.3f} {t1_media['p_valor']:<10.4f} {t1_media['decisao']:<20}")
print(f"{f'read/write: μ = {av2:.3f}':<35} {t2_media['estatistica']:<12.3f} {t2_media['p_valor']:<10.4f} {t2_media['decisao']:<20}")
print(f"{f'fread/fwrite: σ² = {var1:.3f}':<35} {t1_var['estatistica']:<12.3f} {t1_var['p_valor']:<10.4f} {t1_var['decisao']:<20}")
print(f"{f'read/write: σ² = {var2:.3f}':<35} {t2_var['estatistica']:<12.3f} {t2_var['p_valor']:<10.4f} {t2_var['decisao']:<20}")
print(f"{'Igualdade das variâncias':<35} {t_comp_var['estatistica']:<12.3f} {t_comp_var['p_valor']:<10.4f} {t_comp_var['decisao']:<20}")
print(f"{'Igualdade das médias':<35} {t_comp_media['estatistica']:<12.3f} {t_comp_media['p_valor']:<10.4f} {t_comp_media['decisao']:<20}")

print("\n" + "="*70)
print("INTERPRETAÇÃO GERAL:")
print("="*70)
print("• Testes para médias individuais: verificam se cada método tem")
print(f"  tempo médio igual a um valor específico ({av1:.3f})")
print("• Testes para variâncias individuais: verificam a variabilidade")
print("  de cada método")
print("• Teste de igualdade das variâncias: verifica se os dois métodos")
print("  têm a mesma variabilidade")
print("• Teste de igualdade das médias: verifica se os dois métodos")
print("  têm o mesmo tempo médio")