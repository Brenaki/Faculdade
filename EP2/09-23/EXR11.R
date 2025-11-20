library(readxl)
EXR11 <- read_excel("D:/EP2/09-23/Exercícios U4 - Experimentos Fatoriais.xlsx", 
                                                   sheet = "EX11R")
View(EXR11)

# Exemplo  com 3 fatores
ExpDes.pt::fat3.dbc(EXR11$nitrogenio, EXR11$fosforo, EXR11$potassio, EXR11$bloco, EXR11$producao, fac.names = c("N", "P", "K"))
