library(readxl)
EXR7 <- read_excel("D:/EP2/09-23/Exercícios U4 - Experimentos Fatoriais.xlsx", 
                                                   sheet = "EX7R")
View(EXR7)

# Exemplo com 2 fatores

ExpDes.pt::fat2.dic(EXR7$recipiente, EXR7$especie, EXR7$altura, fac.names = c("Recip", "Esp"))
