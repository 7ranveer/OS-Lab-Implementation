#201452010
#!/bin/sh
r=$1
	g=$((r % 10))
if [[ g -ne 0 ]]; then
	echo -ne "$g"
fi
r=$((r/10))

while [ $r -ne 0 ]
do
	g=$((r % 10))
	echo -ne "$g"
	r=$((r/10))
	if [[ r -eq 0 ]];
	 then
		break
	fi
done
echo ""