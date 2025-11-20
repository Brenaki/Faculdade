library(readr)
EX2_R_DIC <- read_delim("EX2_R_DIC.csv", 
                        delim = "\t", escape_double = FALSE, 
                        locale = locale(decimal_mark = ","), 
                        trim_ws = TRUE)
View(EX2_R_DIC)

library(ExpDes.pt)

dic(EX2_R_DIC$Especie,EX2_R_DIC$Absorcao, mcomp = "sk")
