library(readr)
# Chamando arquivo csv no R
arquivo <- read_delim("D:/EP2/09-09/Exercícios U3 - Regressão - Tratamentos Numéricos.csv", 
                                                            delim = "\t", escape_double = FALSE, 
                                                            locale = locale(decimal_mark = ","), 
                                                            trim_ws = TRUE)
View(arquivo)

analise_variancia = ExpDes.pt::dbc(arquivo$Comprimento, arquivo$Bloco, arquivo$Velocidade, 
               quali = F, mcomp = "tukey")

# Modelo Linear

m = analise_variancia$medias

plot(m$trat,m$resp, 
     pch=19, 
     col=2, 
     main = "Comprimento X Velociadade",
     xlab = "Comprimento (m)", 
     ylab = "Velocidade (KB/s)",
     xlim = c(5,45), ylim = c(4,6))

modelo_linear = analise_variancia$reg$`Coeficientes reta`

curve(modelo_linear[1,1]+modelo_linear[2,1]*x,
      add = T, 
      col=4, 
      lwd=2)

text(18,5.5,"Y = 3.96 + 0.03336x")
text(18,5.3,"R² = 89.29%")     

# Modelo Quadratico

plot(m$trat,m$resp, 
     pch=19, 
     col=2, 
     main = "Comprimento X Velociadade",
     xlab = "Comprimento (m)", 
     ylab = "Velocidade (KB/s)",
     xlim = c(5,45), ylim = c(4,6)
     )

q=analise_variancia$reg$`Coeficientes parabola`

curve(q[1,1]+q[2,1]*x+q[3,1]*x^2, 
      add = T, 
      col=4, 
      lwd=2
)

text(20,5.5,"Y = 4.58 - 0.0281x + 0.0012x^2")
text(20,5.3,"R² = 99,0058%")


# Modelo Cubico

plot(m$trat,m$resp, 
     pch=19, 
     col=2, 
     main = "Comprimento X Velociadade",
     xlab = "Comprimento (m)", 
     ylab = "Velocidade (KB/s)",
     xlim = c(5,45), ylim = c(4,6)
)

c=analise_variancia$reg$`Coeficientes cubica`

curve(c[1,1]+c[2,1]*x+c[3,1]*x^2+c[4,1]*x^3, 
      add = T, 
      col=4, 
      lwd=2
)

text(25,4.2,
     "Y = 3.9640 + 0.0698x - 0.0032x^2 + 0.0001x^3",
     cex=1)
text(25,4.1,"R² = 100%", cex=1)

