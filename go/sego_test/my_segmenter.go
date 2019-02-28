package main

import (
	"fmt"

	"github.com/huichen/sego"
)

type MySegmenter sego.Segmenter

func NewSegmenter(dictname string) MySegmenter {
	var seg sego.Segmenter

	seg.LoadDictionary(dictname)

	return MySegmenter(seg)
}

func (seg MySegmenter) Parse(text string) string {
	t := []byte(text)
	segmenter := sego.Segmenter(seg)

	segments := segmenter.Segment(t)
	return sego.SegmentsToString(segments, true)
}

func (seg MySegmenter) ParseAndPrint(text string) {
	fmt.Println("origin text: ", text)

	res := seg.Parse(text)
	fmt.Println("parse result: ", res)
}
