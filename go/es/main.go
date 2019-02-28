package main

import (
	"context"
	"fmt"
	"log"
	"reflect"

	elastic "gopkg.in/olivere/elastic.v2"
)

// Person v
type Person struct {
	Name  string `json:"name"`
	Age   int    `json:"age"`
	Class string `json:"class"`
}

func main() {

	client, err := elastic.NewClient(elastic.SetSniff(false), elastic.SetURL("http://localhost:9200"))
	if err != nil {
		log.Fatalln(err)
	}

	t := Person{
		Name:  "Joh",
		Age:   10,
		Class: "232",
	}

	func() {
		res, err := client.Index().Index("searchdb").Type("aladdin").Id("1").BodyJson(t).Do()
		if err != nil {
			log.Fatalln(err)
		}
		log.Println(res)
	}()

	func() {
		q := elastic.NewQueryStringQuery("Joh")
		res, err := client.Search("searchdb").Type("aladdin").Query(q).DoC(context.Background())
		printPerson(res, err)
	}()

	func() {
		q := elastic.NewBoolQuery()
		q.Must(elastic.NewRangeQuery("age").Gt(9))
		res, err := client.Search("searchdb").Type("aladdin").Query(q).DoC(context.Background())
		printPerson(res, err)
	}()
}

func printPerson(res *elastic.SearchResult, err error) {
	if err != nil {
		log.Fatalln(err)
	}

	var t Person
	for _, item := range res.Each(reflect.TypeOf(t)) {
		v := item.(Person)
		fmt.Printf("%#v\n", v)
	}
}
