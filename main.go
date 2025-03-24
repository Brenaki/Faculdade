package main

import "fmt";

func main(){
  max := 20
  for i:= 0; i<max; i++{
    go fmt.Println("1:", i)
    go fmt.Println("2:", i)
    go fmt.Println("3:", i)
  }
}
