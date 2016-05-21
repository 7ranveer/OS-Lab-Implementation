#201452010
#!/bin/sh
r=$1
fact=1
for ((i=1;i<=r;i++));
do
	fact=$((fact * i))
done
echo "$fact"