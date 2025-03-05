package main

import "fmt"

func main() {
  n := 26473
  // Lower case & Upper case hexadecimal
  fmt.Printf("%x\n", n)
  fmt.Printf("%X\n", n)
  fmt.Printf("%o\n", n) // Octal
  fmt.Printf("%O\n", n) // Octal with prefix
  fmt.Println("%b\n", n) // Binary

  n1 := 0x92F356 // Hexadecimal number
  fmt.Println(n1)
  fmt.Printf("Decimal: %d\n", n1)

  // Octal
  n2 := 02454
  fmt.Println(n2)

  // Creating a slice of bytes
  // Slices in Go are similar to std::vector<T> in C++
  // In Go, byte is an alias of uint8
  b := make([]byte, 0) //  Empty slice
  b = append(b, 255)
  b = append(b, 10)
  fmt.Println(b)

  // Strings are immutable in Go and implicitly encoded in UTF-8
  raw_literal := `Carriage returns are
  ignored. Back quotes (ticks) are forbidden characters.`
  interpreted_litreal := "Forbidden characters are new lines\nand double quotes."

  fmt.Println(raw_literal)
  fmt.Println(interpreted_litreal)

  test := "Hello, go!"
  // When we iterate over a string, each v below is of type rune, rune is equivalent to int32
  // and is only used to differentiate bewteen character values and integer values.

  // Rune represents the unicode value
  for _, v := range test {
    fmt.Printf("Unicode pt: %U - char: '%c'\n", v, v)
  }

  // We can also create runes
  var myRune rune = 'X'
  fmt.Printf("Unicode point of &#39;%c&#39;: %U\n", myRune, myRune)
}
