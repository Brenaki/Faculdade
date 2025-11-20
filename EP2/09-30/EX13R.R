library(readxl)
EX13R <- read_excel("D:/EP2/09-30/Lista 2 - U4 - Experimentos Fatoriais.xlsx", 
                                                sheet = "EX13R")
View(EX13R)

a=ExpDes.pt::fat2.dbc(EX13R$SO, EX13R$RAM, EX13R$Bloco, EX13R$Tempo, 
                    quali = c(T,F), fac.names = c("SO", "RAM"))

# LINUX
## Modelos Linear e Quadratico

x=c(4,8,16)
m=a$medias.dentro12[1,]

plot(x,m,xlab = "Mémoria RAM (GBs)", ylab = "TEMPO (ms)",
     main = "LINUX - Mémoria X Tempo", pch = 19)
### linear
curve(13.0375-0.2263*x, add=T)
text(13,12,"Y = 13.03 - 022x \nR² = 0.9383")

### Curva Quadratica
curve(14.6-0.6281*x+0.0195*x^2,add=T,col=2)
text(12.7,11.5,"Y = 14.6 - 0.62x + 0.019x² \nR² = 1", col=2)

# Windows
## Modelos Linear e Quadratico

x1=c(4,8,16)
m2=a$medias.dentro12[2,]

plot(x1,m2,xlab = "Mémoria RAM (GBs)", ylab = "TEMPO (ms)",
     main = "WINDOWS - Mémoria X Tempo", pch = 19)
### linear
curve(14.9-0.2339*x, add=T)
text(13,14,"Y = 14.9 - 023x \nR² = 0.971304")

### Curva Quadratica
curve(15.9833-0.5125*x+0.0135*x^2,add=T,col=2)
text(12.5,13.5,"Y = 15.98 - 0.51x + 0.013x² \nR² = 1", col=2)
