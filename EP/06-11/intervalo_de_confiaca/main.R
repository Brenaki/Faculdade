# =====
# Dados
# =====

# Método fread/fwrite
fread_fwrite <- c(427.63, 463.20, 481.01, 727.04, 517.85, 499.93, 484.76, 370.96, 397.02, 499.65,
                  391.03, 356.79, 375.19, 384.64, 378.24, 515.18, 349.96, 349.48, 350.13, 350.17,
                  354.72, 354.77, 350.35, 353.01, 354.62, 352.83, 351.10, 351.07, 350.18, 349.93)

# Método read/write
read_write <- c(469.54, 469.06, 493.14, 461.35, 499.83, 508.22, 384.51, 407.59, 439.32, 630.51,
                366.06, 371.90, 389.02, 382.08, 438.25, 396.26, 353.70, 356.25, 356.34, 367.38,
                356.19, 357.15, 359.27, 359.18, 358.19, 357.63, 357.85, 358.15, 355.68, 354.07)

# ====================================
# Funções para intervalos de confiança
# ====================================

ic_media <- function(dados, confianca = 0.95) {
  # Intervalo de confiança para a média
  n <- length(dados)
  media <- mean(dados)
  erro_padrao <- sd(dados) / sqrt(n)
  t_critico <- qt((1 + confianca) / 2, df = n - 1)
  margem_erro <- t_critico * erro_padrao
  ic <- c(media - margem_erro, media + margem_erro)
  return(list(media = media, ic = ic, margem_erro = margem_erro))
}

ic_variancia <- function(dados, confianca = 0.95) {
  # Intervalo de confiança para variância
  n <- length(dados)
  variancia <- var(dados)
  chi2_inf <- qchisq((1 - confianca) / 2, df = n - 1)
  chi2_sup <- qchisq((1 + confianca) / 2, df = n - 1)
  ic_inf <- (n - 1) * variancia / chi2_sup
  ic_sup <- (n - 1) * variancia / chi2_inf
  ic <- c(ic_inf, ic_sup)
  return(list(variancia = variancia, ic = ic))
}

ic_diferenca_medias <- function(grupo1, grupo2, confianca = 0.95) {
  # Intervalo de confiança para diferença das médias (Welch)
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
  
  # Diferença e intervalo
  diff <- m1 - m2
  t_critico <- qt((1 + confianca) / 2, df = df_welch)
  margem_erro <- t_critico * se_diff
  ic <- c(diff - margem_erro, diff + margem_erro)
  
  return(list(diff = diff, ic = ic, df_welch = df_welch, se_diff = se_diff))
}

# ===============================
# Calcular Intervalo de Confiança
# ===============================

cat("\n", rep("=", 60), "\n")
cat("INTERVALOS DE CONFIANÇA (95%)\n")
cat(rep("=", 60), "\n")

# Para fread/fwrite
cat("\n1. MÉTODO: fread/fwrite\n")
cat(rep("-", 30), "\n")
resultado1 <- ic_media(fread_fwrite)
var_resultado1 <- ic_variancia(fread_fwrite)

cat("Tamanho da amostra:", length(fread_fwrite), "\n")
cat("Média:", sprintf("%.3f", resultado1$media), "\n")
cat("IC 95% para média: (", sprintf("%.3f", resultado1$ic[1]), ", ", sprintf("%.3f", resultado1$ic[2]), ")\n")
cat("Margem de erro: ±", sprintf("%.3f", resultado1$margem_erro), "\n")
cat("Variância:", sprintf("%.3f", var_resultado1$variancia), "\n")
cat("IC 95% para variância: (", sprintf("%.3f", var_resultado1$ic[1]), ", ", sprintf("%.3f", var_resultado1$ic[2]), ")\n")
cat("Desvio padrão:", sprintf("%.3f", sqrt(var_resultado1$variancia)), "\n")

# Para read/write
cat("\n2. MÉTODO: read/write\n")
cat(rep("-", 30), "\n")
resultado2 <- ic_media(read_write)
var_resultado2 <- ic_variancia(read_write)

cat("Tamanho da amostra:", length(read_write), "\n")
cat("Média:", sprintf("%.3f", resultado2$media), "\n")
cat("IC 95% para média: (", sprintf("%.3f", resultado2$ic[1]), ", ", sprintf("%.3f", resultado2$ic[2]), ")\n")
cat("Margem de erro: ±", sprintf("%.3f", resultado2$margem_erro), "\n")
cat("Variância:", sprintf("%.3f", var_resultado2$variancia), "\n")
cat("IC 95% para variância: (", sprintf("%.3f", var_resultado2$ic[1]), ", ", sprintf("%.3f", var_resultado2$ic[2]), ")\n")
cat("Desvio padrão:", sprintf("%.3f", sqrt(var_resultado2$variancia)), "\n")

# Comparação entre métodos
cat("\n3. COMPARAÇÃO ENTRE MÉTODOS\n")
cat(rep("-", 40), "\n")
comparacao <- ic_diferenca_medias(fread_fwrite, read_write)

cat("Diferença das médias (fread/fwrite - read/write):", sprintf("%.3f", comparacao$diff), "\n")
cat("Erro padrão da diferença:", sprintf("%.3f", comparacao$se_diff), "\n")
cat("Graus de liberdade (Welch):", sprintf("%.1f", comparacao$df_welch), "\n")
cat("IC 95% para diferença: (", sprintf("%.3f", comparacao$ic[1]), ", ", sprintf("%.3f", comparacao$ic[2]), ")\n")

# Teste estatístico
teste_t <- t.test(fread_fwrite, read_write, var.equal = FALSE)
cat("Teste t de Welch: t =", sprintf("%.3f", teste_t$statistic), ", p-valor =", sprintf("%.4f", teste_t$p.value), "\n")

# Interpretação
cat("\nINTERPRETAÇÃO:\n")
if (comparacao$ic[1] <= 0 && 0 <= comparacao$ic[2]) {
  cat("• O intervalo inclui zero → NÃO há diferença significativa\n")
  cat("  entre os métodos fread/fwrite e read/write.\n")
} else {
  cat("• O intervalo NÃO inclui zero → HÁ diferença significativa\n")
  cat("  entre os métodos.\n")
}

# ======
# Resumo
# ======

cat("\n", rep("=", 70), "\n")
cat("RESUMO DOS RESULTADOS\n")
cat(rep("=", 70), "\n")
cat(sprintf("%-25s %-20s %-20s\n", "Parâmetro", "fread/fwrite", "read/write"))
cat(rep("-", 70), "\n")
cat(sprintf("%-25s %.3f ± %.3f %8s %.3f ± %.3f\n", "Média", 
            resultado1$media, resultado1$margem_erro, "", 
            resultado2$media, resultado2$margem_erro))
cat(sprintf("%-25s (%.1f, %.1f) %8s (%.1f, %.1f)\n", "IC Média", 
            resultado1$ic[1], resultado1$ic[2], "", 
            resultado2$ic[1], resultado2$ic[2]))
cat(sprintf("%-25s %.1f %15s %.1f\n", "Variância", 
            var_resultado1$variancia, "", var_resultado2$variancia))
cat(sprintf("%-25s (%.1f, %.1f) %4s (%.1f, %.1f)\n", "IC Variância", 
            var_resultado1$ic[1], var_resultado1$ic[2], "", 
            var_resultado2$ic[1], var_resultado2$ic[2]))
cat(rep("-", 70), "\n")
cat(sprintf("%-25s %.3f\n", "Diferença das médias:", comparacao$diff))
cat(sprintf("%-25s (%.1f, %.1f)\n", "IC Diferença:", comparacao$ic[1], comparacao$ic[2]))
conclusao <- ifelse(teste_t$p.value > 0.05, "Sem diferença significativa", "Diferença significativa")
cat(sprintf("%-25s %s\n", "Conclusão:", conclusao))