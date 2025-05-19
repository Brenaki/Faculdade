# Retorna um quantil da normal
# Exemplo: Percentil 5, Média 50, Variância 5

# DISTRIBUIÇÃO NORMAL
qnorm(0.05, 50, 2) # qnorm() corresponde ao inv.norm() no LibreOffice Calc

pnorm(46.71029, 50, 2) # pnorm() corresponde ao dist.norm() no LibreOffice Calc

# DISTRIBUIÇÃO T
# Exemplo: Percentil 5, Grau de liberdade 9
qt(0.05, 9) # qt() corresponde ao inv.t() no LibreOffice Calc

pt(1.833113, 9)

# DISTRIBUIÇÃO QUI-QUADRADO
# Exemplo: Percentil 95, Grau de liberdade 15
qchisq(0.95, 15) # qchisq() corresponde a inv.quiqua() no LibreOffice Calc

pchisq(24.99579, 15) # pchisq() corresponde a dist.quiqua() no LibreOffice Calc
