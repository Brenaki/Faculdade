# Exemplo 1 Unidade 6
n <- 10
s2 <- 4
Qinf <- qchisq(0.05, n - 1) # percentil 5
Qsup <- qchisq(0.95, n - 1) # percentil 95

li1 <- ((n - 1) * s2) / Qsup
ls1 <- ((n - 1) * s2) / Qinf

# IC = [2.1277 ; 10.8267]
# intervalo tem 90% de confiança

# exemplo 2 Unidade 6
p1 <- c(801.0, 809.5, 806.2, 814.4, 799.0, 800.6, 800.2, 799.1, 812.0)
p2 <- c(810.8, 806.5, 798.6, 801.5, 808.0, 794.3, 806.4, 799.0, 805.2, 803.5)

v1 <- var(p1)
v2 <- var(p2)

n1 <- length(p1)
n2 <- length(p2)

fi2 <- qf(0.05, n1 - 1, n2 - 1)
fs2 <- qf(0.05, n1 - 1, n2 - 1, lower.tail = F)

li2 <- v1 / (v2 * fs2)
ls2 <- v1 / (v2 * fi2)
# IC = [0.44159 ; 4.83209]
# com 90% de confiança o intervalo abrange o valor verdadeiro

# emxemplo 5 Unidade 6
# IC para uma média usando a normal
n <- 100
m <- 40
sig <- 10
z <- qnorm(0.005, lower.tail = F) # Z(alfa/2)
erro <- z * (sig / sqrt(n))
li3 <- m - erro
ls3 <- m + erro
# IC = [37.42417 ; 42.57582] com 99% de confiança


# EXEMPLO 7 UNIDADE 6
a <- c(36.4, 35.7, 37.2, 36.5, 34.9, 35.2, 36.3, 35.8, 36.6, 36.9)
alfa <- 0.05
n7 <- length(a)
m <- mean(a)
s <- sd(a)
erro <- t(s / sqrt(n7))
Li7 <- m - erro
Ls7 <- m + erro

### UTILIZANDO AS FUNÇÕES DO R###
# Usando os dados de exemplo 7 - intervalo de confiança para uma proporção
library(TeachingDemos)
sigma.test(a) # para intervalo de confianca sempre usar o defaut:"two.sided"
# [0.2557462 ;  1.8015920]
# Entao com 95% de confianca esse intervalo abrange o verdadeiro valor da variabilidade da dureza do aço

# usando dados de exemplo 5 - intervalo de confiança para uma proporção
library(BSDA)
# z.test() precisa de um conjunto de dados
zsum.test(m, sig, n, conf.level = 0.99) # precisa dos parametros

# usando os dados do exemplo 7
t.test(a)

# Exemplo 13 UNIDADE 6 - intervalo de confiança com duas proporções
# para homens
nh <- 1250
xh <- 670
# para mulheres
nm <- 1410
xm <- 770
# proporções
ph <- xh / nh
pm <- xm / nm

ph - pm
alfa <- 0.01
z <- qnorm(alfa / 2, lower.tail = F)
erro <- z * sqrt((ph * (1 - ph) / nh) + (pm * (1 - pm) / nm))

Li13 <- (ph - pm) - erro
Ls13 <- (ph - pm) + erro
# IC: [-0.0599 ; 0.0397]
# esse intervalo abrange o verdadeiro valor entre as proporções
# comando pronto para o exemplo 12
alfa <- 0.05
n <- 2000
x <- 952
prop.test(x, n)
# comando pronto para o exemplo 13
prop.test(c(xh, xm), c(nh, nm), conf.level = 0.99, correct = F)

### Intervalo de confiança para duas médias###
