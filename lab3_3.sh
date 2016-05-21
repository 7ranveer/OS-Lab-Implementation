#201452010
#!/bin/sh
r=$1
g=$3
case $2 in
	"+") 
		echo "$((r+g))"
		;;
	"-")
		echo "$((r-g))"
		;;
	"/")
		echo "$((r/g))"
		;;
	"x")
		echo "$((r * g))"
		;;
esac