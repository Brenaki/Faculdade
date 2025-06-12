# ==========
# SEUS DADOS
# ==========

# Método fread/fwrite
fread_fwrite <- c(427.63,463.20,481.01,727.04,517.85,499.93,484.76,370.96,397.02,499.65,391.03,356.79,375.19,384.64,378.24,515.18,349.96,349.48,350.13,350.17,354.72,354.77,350.35,353.01,354.62,352.83,351.10,351.07,350.18,349.93)

# Método read/write
read_write <- c(469.54,469.06,493.14,461.35,499.83,508.22,384.51,407.59,439.32,630.51,366.06,371.90,389.02,382.08,438.25,396.26,353.70,356.25,356.34,367.38,356.19,357.15,359.27,359.18,358.19,357.63,357.85,358.15,355.68,354.07)

# Converter para vetores (já são vetores em R)
x1 <- fread_fwrite
x2 <- read_write

cat("TESTES DE HIPÓTESES\n")
cat(paste(rep("=", 60), collapse=""), "\n")
cat("Dados carregados:\n")

n1 <- length(x1)
n2 <- length(x2)
av1 <- mean(x1)
av2 <- mean(x2)
var1 <- var(x1)
var2 <- var(x2)

cat(sprintf("fread/fwrite: %d valores, média = %.3f, variância = %.3f\n", n1, av1, var1))
cat(sprintf("read/write: %d valores, média = %.3f, variância = %.3f\n", n2, av2, var2))

# ========================================
# FUNÇÕES PARA TESTES DE HIPÓTESES
# ========================================

teste_media_uma_amostra <- function(dados, mu0, alpha = 0.05, teste = 'bilateral') {
  # Teste t para média de uma amostra
  # H0: μ = μ0 vs H1: μ ≠ μ0 (bilateral) ou μ > μ0 ou μ < μ0
  
  n <- length(dados)
  media <- mean(dados)
  s <- sd(dados)
  
  # Estatística t
  t_calc <- (media - mu0) / (s / sqrt(n))
  
  # Valor crítico e p-valor
  if (teste == 'bilateral') {
    t_crit <- qt(1 - alpha/2, df = n-1)
    p_valor <- 2 * (1 - pt(abs(t_calc), df = n-1))
    regiao_rejeicao <- sprintf("|t| > %.3f", t_crit)
  } else if (teste == 'direita') {
    t_crit <- qt(1 - alpha, df = n-1)
    p_valor <- 1 - pt(t_calc, df = n-1)
    regiao_rejeicao <- sprintf("t > %.3f", t_crit)
  } else { # esquerda
    t_crit <- qt(alpha, df = n-1)
    p_valor <- pt(t_calc, df = n-1)
    regiao_rejeicao <- sprintf("t < %.3f", t_crit)
  }
  
  decisao <- ifelse(p_valor < alpha, "Rejeitar H0", "Não rejeitar H0")
  
  return(list(
    estatistica = t_calc,
    valor_critico = t_crit,
    p_valor = p_valor,
    decisao = decisao,
    regiao_rejeicao = regiao_rejeicao,
    media_amostral = media,
    gl = n-1
  ))
}

teste_variancia_uma_amostra <- function(dados, sigma2_0, alpha = 0.05, teste = 'bilateral') {
  # Teste qui-quadrado para variância de uma amostra
  # H0: σ² = σ²₀ vs H1: σ² ≠ σ²₀
  
  n <- length(dados)
  s2 <- var(dados)
  
  # Estatística qui-quadrado
  chi2_calc <- (n - 1) * s2 / sigma2_0
  
  # Valores críticos e p-valor
  if (teste == 'bilateral') {
    chi2_inf <- qchisq(alpha/2, df = n-1)
    chi2_sup <- qchisq(1 - alpha/2, df = n-1)
    p_valor <- 2 * min(pchisq(chi2_calc, df = n-1), 
                      1 - pchisq(chi2_calc, df = n-1))
    regiao_rejeicao <- sprintf("χ² < %.3f ou χ² > %.3f", chi2_inf, chi2_sup)
    decisao <- ifelse(chi2_calc < chi2_inf | chi2_calc > chi2_sup, 
                     "Rejeitar H0", "Não rejeitar H0")
  } else if (teste == 'direita') {
    chi2_crit <- qchisq(1 - alpha, df = n-1)
    p_valor <- 1 - pchisq(chi2_calc, df = n-1)
    regiao_rejeicao <- sprintf("χ² > %.3f", chi2_crit)
    decisao <- ifelse(chi2_calc > chi2_crit, "Rejeitar H0", "Não rejeitar H0")
  } else { # esquerda
    chi2_crit <- qchisq(alpha, df = n-1)
    p_valor <- pchisq(chi2_calc, df = n-1)
    regiao_rejeicao <- sprintf("χ² < %.3f", chi2_crit)
    decisao <- ifelse(chi2_calc < chi2_crit, "Rejeitar H0", "Não rejeitar H0")
  }
  
  return(list(
    estatistica = chi2_calc,
    p_valor = p_valor,
    decisao = decisao,
    regiao_rejeicao = regiao_rejeicao,
    variancia_amostral = s2,
    gl = n-1
  ))
}

teste_comparacao_medias <- function(grupo1, grupo2, alpha = 0.05, teste = 'bilateral') {
  # Teste t de Welch para comparação de médias (variâncias diferentes)
  # H0: μ₁ = μ₂ vs H1: μ₁ ≠ μ₂
  
  n1 <- length(grupo1)
  n2 <- length(grupo2)
  m1 <- mean(grupo1)
  m2 <- mean(grupo2)
  s1 <- sd(grupo1)
  s2 <- sd(grupo2)
  
  # Erro padrão da diferença
  se_diff <- sqrt(s1^2/n1 + s2^2/n2)
  
  # Graus de liberdade de Welch
  df_welch <- (s1^2/n1 + s2^2/n2)^2 / ((s1^2/n1)^2/(n1-1) + (s2^2/n2)^2/(n2-1))
  
  # Estatística t
  t_calc <- (m1 - m2) / se_diff
  
  # Valor crítico e p-valor
  if (teste == 'bilateral') {
    t_crit <- qt(1 - alpha/2, df = df_welch)
    p_valor <- 2 * (1 - pt(abs(t_calc), df = df_welch))
    regiao_rejeicao <- sprintf("|t| > %.3f", t_crit)
  } else if (teste == 'direita') {
    t_crit <- qt(1 - alpha, df = df_welch)
    p_valor <- 1 - pt(t_calc, df = df_welch)
    regiao_rejeicao <- sprintf("t > %.3f", t_crit)
  } else { # esquerda
    t_crit <- qt(alpha, df = df_welch)
    p_valor <- pt(t_calc, df = df_welch)
    regiao_rejeicao <- sprintf("t < %.3f", t_crit)
  }
  
  decisao <- ifelse(p_valor < alpha, "Rejeitar H0", "Não rejeitar H0")
  
  return(list(
    estatistica = t_calc,
    valor_critico = t_crit,
    p_valor = p_valor,
    decisao = decisao,
    regiao_rejeicao = regiao_rejeicao,
    diferenca = m1 - m2,
    gl = df_welch
  ))
}

teste_comparacao_variancias <- function(grupo1, grupo2, alpha = 0.05) {
  # Teste F para comparação de variâncias
  # H0: σ₁² = σ₂² vs H1: σ₁² ≠ σ₂²
  
  s1_2 <- var(grupo1)
  s2_2 <- var(grupo2)
  n1 <- length(grupo1)
  n2 <- length(grupo2)
  
  # Estatística F (maior variância no numerador)
  if (s1_2 >= s2_2) {
    f_calc <- s1_2 / s2_2
    df1 <- n1 - 1
    df2 <- n2 - 1
  } else {
    f_calc <- s2_2 / s1_2
    df1 <- n2 - 1
    df2 <- n1 - 1
  }
  
  # Valor crítico e p-valor (teste bilateral)
  f_crit <- qf(1 - alpha/2, df1, df2)
  p_valor <- 2 * (1 - pf(f_calc, df1, df2))
  
  decisao <- ifelse(f_calc > f_crit, "Rejeitar H0", "Não rejeitar H0")
  
  return(list(
    estatistica = f_calc,
    valor_critico = f_crit,
    p_valor = p_valor,
    decisao = decisao,
    regiao_rejeicao = sprintf("F > %.3f", f_crit),
    gl1 = df1,
    gl2 = df2
  ))
}

# ========================================
# TESTES PARA CADA VARIÁVEL
# ========================================

cat("\n", paste(rep("=", 60), collapse=""), "\n")
cat("1. TESTES PARA fread/fwrite\n")
cat(paste(rep("=", 60), collapse=""), "\n")

# Teste 1.1: Média
cat(sprintf("\n1.1 Teste para a média (H0: μ = %.3f)\n", av1))
cat(paste(rep("-", 40), collapse=""), "\n")
resultado <- teste_media_uma_amostra(x1, mu0 = av1, teste = 'bilateral')
cat(sprintf("H0: μ = %.3f  vs  H1: μ ≠ %.3f\n", av1, av1))
cat(sprintf("Estatística t: %.3f\n", resultado$estatistica))
cat(sprintf("Valor crítico: ±%.3f\n", resultado$valor_critico))
cat(sprintf("P-valor: %.4f\n", resultado$p_valor))
cat(sprintf("Região de rejeição: %s\n", resultado$regiao_rejeicao))
cat(sprintf("Decisão: %s\n", resultado$decisao))
cat(sprintf("Média amostral: %.3f\n", resultado$media_amostral))

# Teste 1.2: Variância
cat(sprintf("\n1.2 Teste para a variância (H0: σ² = %.3f)\n", var1))
cat(paste(rep("-", 40), collapse=""), "\n")
resultado <- teste_variancia_uma_amostra(x1, sigma2_0 = var1, teste = 'bilateral')
cat(sprintf("H0: σ² = %.3f  vs  H1: σ² ≠ %.3f\n", var1, var1))
cat(sprintf("Estatística χ²: %.3f\n", resultado$estatistica))
cat(sprintf("P-valor: %.4f\n", resultado$p_valor))
cat(sprintf("Região de rejeição: %s\n", resultado$regiao_rejeicao))
cat(sprintf("Decisão: %s\n", resultado$decisao))
cat(sprintf("Variância amostral: %.3f\n", resultado$variancia_amostral))

cat("\n", paste(rep("=", 60), collapse=""), "\n")
cat("2. TESTES PARA read/write\n")
cat(paste(rep("=", 60), collapse=""), "\n")

# Teste 2.1: Média
cat(sprintf("\n2.1 Teste para a média (H0: μ = %.3f)\n", av2))
cat(paste(rep("-", 40), collapse=""), "\n")
resultado <- teste_media_uma_amostra(x2, mu0 = av2, teste = 'bilateral')
cat(sprintf("H0: μ = %.3f  vs  H1: μ ≠ %.3f\n", av2, av2))
cat(sprintf("Estatística t: %.3f\n", resultado$estatistica))
cat(sprintf("Valor crítico: ±%.3f\n", resultado$valor_critico))
cat(sprintf("P-valor: %.4f\n", resultado$p_valor))
cat(sprintf("Região de rejeição: %s\n", resultado$regiao_rejeicao))
cat(sprintf("Decisão: %s\n", resultado$decisao))
cat(sprintf("Média amostral: %.3f\n", resultado$media_amostral))

# Teste 2.2: Variância
cat(sprintf("\n2.2 Teste para a variância (H0: σ² = %.3f)\n", var2))
cat(paste(rep("-", 40), collapse=""), "\n")
resultado <- teste_variancia_uma_amostra(x2, sigma2_0 = var2, teste = 'bilateral')
cat(sprintf("H0: σ² = %.3f  vs  H1: σ² ≠ %.3f\n", var2, var2))
cat(sprintf("Estatística χ²: %.3f\n", resultado$estatistica))
cat(sprintf("P-valor: %.4f\n", resultado$p_valor))
cat(sprintf("Região de rejeição: %s\n", resultado$regiao_rejeicao))
cat(sprintf("Decisão: %s\n", resultado$decisao))
cat(sprintf("Variância amostral: %.3f\n", resultado$variancia_amostral))

# ========================================
# TESTES DE COMPARAÇÃO
# ========================================

cat("\n", paste(rep("=", 60), collapse=""), "\n")
cat("3. COMPARAÇÃO ENTRE AS DUAS VARIÁVEIS\n")
cat(paste(rep("=", 60), collapse=""), "\n")

# Teste 3.1: Igualdade das variâncias
cat("\n3.1 Teste de igualdade das variâncias\n")
cat(paste(rep("-", 40), collapse=""), "\n")
resultado <- teste_comparacao_variancias(x1, x2)
cat("H0: σ₁² = σ₂²  vs  H1: σ₁² ≠ σ₂²\n")
cat(sprintf("Estatística F: %.3f\n", resultado$estatistica))
cat(sprintf("Valor crítico: %.3f\n", resultado$valor_critico))
cat(sprintf("P-valor: %.4f\n", resultado$p_valor))
cat(sprintf("Região de rejeição: %s\n", resultado$regiao_rejeicao))
cat(sprintf("Decisão: %s\n", resultado$decisao))
cat(sprintf("GL: (%d, %d)\n", resultado$gl1, resultado$gl2))

# Teste 3.2: Igualdade das médias
cat("\n3.2 Teste de igualdade das médias (Welch)\n")
cat(paste(rep("-", 40), collapse=""), "\n")
resultado <- teste_comparacao_medias(x1, x2, teste = 'bilateral')
cat("H0: μ₁ = μ₂  vs  H1: μ₁ ≠ μ₂\n")
cat(sprintf("Estatística t: %.3f\n", resultado$estatistica))
cat(sprintf("Valor crítico: ±%.3f\n", resultado$valor_critico))
cat(sprintf("P-valor: %.4f\n", resultado$p_valor))
cat(sprintf("Região de rejeição: %s\n", resultado$regiao_rejeicao))
cat(sprintf("Decisão: %s\n", resultado$decisao))
cat(sprintf("Diferença das médias: %.3f\n", resultado$diferenca))
cat(sprintf("GL (Welch): %.1f\n", resultado$gl))

# Teste 3.3: fread/fwrite é mais rápido? (teste unilateral)
cat("\n3.3 Teste: fread/fwrite é mais rápido?\n")
cat(paste(rep("-", 40), collapse=""), "\n")
resultado <- teste_comparacao_medias(x1, x2, teste = 'esquerda')  # μ₁ < μ₂
cat("H0: μ₁ ≥ μ₂  vs  H1: μ₁ < μ₂ (fread/fwrite mais rápido)\n")
cat(sprintf("Estatística t: %.3f\n", resultado$estatistica))
cat(sprintf("Valor crítico: %.3f\n", resultado$valor_critico))
cat(sprintf("P-valor: %.4f\n", resultado$p_valor))
cat(sprintf("Região de rejeição: %s\n", resultado$regiao_rejeicao))
cat(sprintf("Decisão: %s\n", resultado$decisao))

# ========================================
# RESUMO DOS RESULTADOS
# ========================================

cat("\n", paste(rep("=", 70), collapse=""), "\n")
cat("RESUMO DOS TESTES DE HIPÓTESES\n")
cat(paste(rep("=", 70), collapse=""), "\n")

# Recalcular alguns testes para o resumo
t1_media <- teste_media_uma_amostra(x1, mu0 = av1)
t2_media <- teste_media_uma_amostra(x2, mu0 = av2)
t1_var <- teste_variancia_uma_amostra(x1, sigma2_0 = var1)
t2_var <- teste_variancia_uma_amostra(x2, sigma2_0 = var2)
t_comp_var <- teste_comparacao_variancias(x1, x2)
t_comp_media <- teste_comparacao_medias(x1, x2)

cat(sprintf("%-35s %-12s %-10s %-20s\n", "Teste", "Estatística", "P-valor", "Decisão"))
cat(paste(rep("-", 70), collapse=""), "\n")
cat(sprintf("%-35s %-12.3f %-10.4f %-20s\n", 
           sprintf("fread/fwrite: μ = %.3f", av1), 
           t1_media$estatistica, t1_media$p_valor, t1_media$decisao))
cat(sprintf("%-35s %-12.3f %-10.4f %-20s\n", 
           sprintf("read/write: μ = %.3f", av2), 
           t2_media$estatistica, t2_media$p_valor, t2_media$decisao))
cat(sprintf("%-35s %-12.3f %-10.4f %-20s\n", 
           sprintf("fread/fwrite: σ² = %.3f", var1), 
           t1_var$estatistica, t1_var$p_valor, t1_var$decisao))
cat(sprintf("%-35s %-12.3f %-10.4f %-20s\n", 
           sprintf("read/write: σ² = %.3f", var2), 
           t2_var$estatistica, t2_var$p_valor, t2_var$decisao))
cat(sprintf("%-35s %-12.3f %-10.4f %-20s\n", 
           "Igualdade das variâncias", 
           t_comp_var$estatistica, t_comp_var$p_valor, t_comp_var$decisao))
cat(sprintf("%-35s %-12.3f %-10.4f %-20s\n", 
           "Igualdade das médias", 
           t_comp_media$estatistica, t_comp_media$p_valor, t_comp_media$decisao))

cat("\n", paste(rep("=", 70), collapse=""), "\n")
cat("INTERPRETAÇÃO GERAL:\n")
cat(paste(rep("=", 70), collapse=""), "\n")
cat("• Testes para médias individuais: verificam se cada método tem\n")
cat(sprintf("  tempo médio igual a um valor específico (%.3f)\n", av1))
cat("• Testes para variâncias individuais: verificam a variabilidade\n")
cat("  de cada método\n")
cat("• Teste de igualdade das variâncias: verifica se os dois métodos\n")
cat("  têm a mesma variabilidade\n")
cat("• Teste de igualdade das médias: verifica se os dois métodos\n")
cat("  têm o mesmo tempo médio\n")