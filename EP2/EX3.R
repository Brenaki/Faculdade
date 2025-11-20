## EXEMPLO 3 ####
## IMPORTANDO OS DADOS ####
library(readr)
EX3_R <- read_delim("C:/Users/deinfo/Downloads/EX3-R.csv", 
                    delim = "\t", escape_double = FALSE, 
                    locale = locale(decimal_mark = ","), 
                    trim_ws = TRUE)
View(EX3_R)

## OUTRA FORMA DE IMPORTAR
setwd("C:/Users/deinfo/Downloads")

dados=read.table("EX3-R.csv",header = T,dec = ",")


## CARREGANDO A BIBLIOTECA
library(ExpDes.pt)

dbc(EX3_R$comprimento,EX3_R$bloco,EX3_R$velocidade)
