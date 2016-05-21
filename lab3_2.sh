#201452010
#!/bin/sh
large=$1
small=$1
sum=0
r=0
for i in $*

do
	sum="`expr $sum + $i`"
	if [ $large -lt $i ]
		then
		large=$i
	fi
	if [ $small -gt $i ]
		then
		small=$i
	fi
	r="`expr $r + 1`"
done	
echo "Highest:$large"
echo "Lowest:$small"
echo "Average:$((sum/r))"