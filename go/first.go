/*
 * @Descripttion: 
 * @version: 
 * @Author: ahtoh
 * @Date: 2022-03-09 20:23:23
 * @LastEditors: ahtoh
 * @LastEditTime: 2022-03-09 20:25:18
 */

 package main
 import (
	 "fmt"
	 "os"
 )

 func main() {
	 var s, sep string
	 for i:=1; i< len(os.Args);i++{
		 s += sep + os.Args[i]
		 sep  = "  "
	 }
	 fmt.Println(s)
 }