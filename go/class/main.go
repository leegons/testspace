package main

import "fmt"

type ITalker interface {
	Talk(string)
}

type Person struct {
	name string
	age  int
}

func (p *Person) Talk(msg string) {
	fmt.Printf("%s say: %s\n", p.name, msg)
}
func (p *Person) String() string {
	return fmt.Sprintf("Person{name:%s, age:%d}", p.name, p.age)
}

type Dog struct{}

func (d *Dog) Talk(string) {
	fmt.Println("wangwangwang")
}
func (d *Dog) String() string {
	return "{NoNameDog}"
}

func NewTalker(name string) ITalker {
	switch name {
	case "person":
		return &Person{name: "Joh", age: 18}
	case "dog":
		return &Dog{}
	default:
		return nil
	}
}

func Test(t ITalker) {
	switch t.(type) {
	case *Person:
		fmt.Println("person", t.(*Person))
	case *Dog:
		fmt.Println("dog", t.(*Dog))
	}

}

func main() {
	var talker ITalker

	talker = NewTalker("person")
	talker.Talk("hello")
	Test(talker)

	talker = NewTalker("dog")
	talker.Talk("hello")
	Test(talker)
}
