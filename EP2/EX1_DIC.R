library(readr)
EX1_R_DIC <- read_delim("EX1_R_DIC.csv", 
                        delim = "\t", escape_double = FALSE, 
                        locale = locale(decimal_mark = ","), 
                        trim_ws = TRUE)
View(EX1_R_DIC)

library(ExpDes.pt)

dic(EX1_R_DIC$`TIPO REDE`,EX1_R_DIC$TEMPO, mcomp = "ski")
