package main

import (
	"fmt"

	"github.com/sergi/go-diff/diffmatchpatch"
)

const (
	text1 = `common_feature_value {	
		values {	
		  key: "127_a"	
		  value {	
			f_value: 884875	
		  }	
		}	
		values {	
		  key: "130_a"	
		  value {	
			f_value: 4	
		  }	
		}`
	text2 = `common_feature_value {
		values {
		  key: "127_a"
		  value {
			f_value: 884875.0
		  }
		}
		values {
		  key: "130_a"
		  value {
			f_value: 4.0
		  }
		}`
)

func main() {
	dmp := diffmatchpatch.New()

	diffs := dmp.DiffMain(text1, text2, true)

	fmt.Println(dmp.DiffPrettyText(diffs))
}
