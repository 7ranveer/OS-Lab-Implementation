#201452010
#!/bin/sh
echo "Enter the total numbers to be sorted"
read n
for ((i=0;i<n;i++));
do 
	read a[i]
done
for ((i=0;i<n;i++));
do
	for ((j=0;j<n;j++));
	do
		if [ ${a[i]} -gt ${a[j]} ];
			then
			b=${a[i]}
			a[i]=${a[j]}
			a[j]=$b
		fi
	done
done
echo "sorted numbers are"
for ((i=n-1;i>=0;i--));
do
	echo -n "${a[i]} "
done