package main

import "fmt"

const (
	russian = "Russian"
	french  = "French"

	englishHelloPrefix = "Hello, "
	russianHelloPrefix = "Привет, "
	frenchHelloPrefix  = "Bonjour, "
)

// Hello returns a greeting.
func Hello(name, language string) string {
	if name == "" {
		name = "World"
	}

	return greetingPrefix(language) + name
}

func greetingPrefix(language string) (prefix string) {
	switch language {
	case russian:
		prefix = russianHelloPrefix
	case french:
		prefix = frenchHelloPrefix
	default:
		prefix = englishHelloPrefix
	}
	return prefix
}

func main() {
	fmt.Println(Hello("world", ""))
}
